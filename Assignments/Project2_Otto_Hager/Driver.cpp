#include "Entity.hpp"
#include "Game.hpp"
#include "Map.hpp"
#include "Items.hpp"
#include "utils.hpp"

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

#include <ctype.h>

using namespace std;

// The point of this file is to demonstrate what you could make to help test different parts of your code
// without necessarily having all parts implemented.

// Ideally you test and work on the individual parts and add them in piece-by-piece, until you have the whole thing to place into its own driver file.

int main()
{
    string filename;

    // initialize
    Game m_game;
    
    //print game intro
    printIntro();

    // Load Items
    filename = "items.txt";
    m_game.loadItems(filename);
    cout << "Items Loaded" << endl;

    // Load in txt files
    filename = "characters.txt";
    m_game.loadEnteties(filename, true);

    filename = "enemies.txt";
    m_game.loadEnteties(filename, false);
    cout << "Entities Loaded" << endl;

    filename = "riddles.txt";
    m_game.loadRiddles(filename);

    /* initialize random seed: */
    srand(time(NULL));

    Map m_map = Map();
    // initialize tiles
    m_map.initializeMap();
    cout << "Map initialized" << endl;
    // initiate positions to 0
    m_map.setPlayerPos(0, 0);
    m_map.setPlayerPos(1, 0);

    // get player 1
    m_game.playerPick(0);
    cout << "Player 1 has chosen " << m_game.getPlayer(0).getName() << "!" << endl;
    // get player 2
    m_game.playerPick(1);
    cout << "Player 2 has chosen " << m_game.getPlayer(1).getName() << "!" << endl;

    // Lets players shop before game starts
    cout << "Before setting sail, both players get to visit the item shop. " << endl;
    m_game.itemShop(0);
    m_game.itemShop(1);

    cout << "Here is our map:" << endl;
    m_map.printMap();


    // Randomizes which player starts
    int current_player = rand() % 2;
    cout << "After a coin flip it is set that " << m_game.getPlayer(current_player).getName() << " starts the game" << endl;

    int player_quit = -1; // Keeps track on who quitted

    bool skip_next_turn[2] = {false, false}; // flag variable for each player that determines if next turn is skipped
    // Turn loop
    //  while noone has reached Ithaca or DIED
    while (m_map.getPlayerPos(0) < 50 && m_map.getPlayerPos(1) < 50 && m_game.getPlayerHP(0) > 0 && m_game.getPlayerHP(1) > 0)
    {
        int option = -1;
        bool turn_taken = false;

        if (skip_next_turn[current_player])
        {
            skip_next_turn[current_player] = false;    // reset flag
            current_player = (current_player + 1) % 2; // swotch current player
            continue;                                  // skip this turn
        }

        cout << "Now it's " << m_game.getPlayer(current_player).getName() << "'s turn" << endl; // Whose turn it is

        // option loop
        // While player hasnt used his turn
        while (!turn_taken)
        {
            option = m_game.mainMenu();

            // If move is chosen
            if (option == 1)
            {
                if (m_game.getPlayer(current_player).getStamina() > 2) // if enough stamina
                {
                    int dice_roll = diceRoll(); // get random nummer 1-6
                    // cout << "DEBUG Rolled a " << dice_roll << endl;
                    m_map.movePlayer(current_player, dice_roll); // Move and Update player postion, returns how many steps where moved
                    // cout << "DEBUG PLayer is now postioned at " << m_map.getPlayerPos(current_player) << endl;
                    string color = m_map.getTileColor(current_player, m_map.getPlayerPos(current_player)); // Get name of tile color

                    m_map.printMap();

                    if (m_map.getPlayerPos(0) == m_map.getPlayerPos(1))
                    {

                        m_game.epicCombat();
                    }
                    else if (m_map.getTileColor(current_player, m_map.getPlayerPos(current_player)) == "blue")
                    {
                        int prob = m_game.getPlayer(current_player).getCalamity();
                        if (prob == 0)
                        {
                            prob = 1;
                        }
                        if (rand() % 100 < prob) // Calamity chance of calamity (Usually 30%)
                        {
                            int calamity_num = rand() % 100;

                            if (calamity_num <= 45) // Stormy Seas
                            {
                                cout << "You have sailed into stormy seas. " << endl;
                                cout << "With each passing moment, the storm grows fiercer, \ntesting your courage and resolve as you struggle to keep your ship afloat amidst the wrath of Poseidon" << endl;

                                // Moves player back a random amount of steps depending on Map look and map position
                                if (m_map.getPlayerPos(current_player) < 3)
                                {
                                    cout << "Stormy Seas will not affect you since you are in the bugginning" << endl;
                                }
                                else if (rand() % 2 == 0 && m_map.getMapPos(current_player, m_map.getPlayerPos(current_player) - 1) != GREEN)
                                {
                                    cout << m_game.getPlayer(current_player).getName() << " was moved back 1 tile." << endl;
                                    m_map.setPlayerPos(current_player, m_map.getPlayerPos(current_player) - 1);
                                }
                                else if (m_map.getMapPos(current_player, m_map.getPlayerPos(current_player) - 3) != GREEN)
                                {
                                    cout << m_game.getPlayer(current_player).getName() << " was moved back 3 tiles." << endl;
                                    m_map.setPlayerPos(current_player, m_map.getPlayerPos(current_player) - 3);
                                }
                                else if (m_map.getMapPos(current_player, m_map.getPlayerPos(current_player) - 2) != GREEN)
                                {
                                    cout << m_game.getPlayer(current_player).getName() << " was moved back 2 tiles." << endl;
                                    m_map.setPlayerPos(current_player, m_map.getPlayerPos(current_player) - 2);
                                    m_map.printMap();
                                }
                            }
                            else if (calamity_num <= 80) // Plague Outbreak
                            {
                                cout << "The spread of the plague seems unstoppable, defying your best efforts to contain it and leaving you to confront the harsh reality of your own mortality." << endl;
                                m_game.setPlayerCondition(current_player, 'P');
                            }
                            else // Poisonous Rats
                            {
                                cout << "Much to your dismay, it seems you are not the only one on your ship. You have gotten deseased." << endl;
                                m_game.setPlayerCondition(current_player, 'D');
                            }
                        }
                        else
                        {
                            cout << "You've landed on a blue tile. You can stay calm for now..." << endl;
                        }
                    }
                    else if (m_map.getTileColor(current_player, m_map.getPlayerPos(current_player)) == "green")
                    {

                        m_game.islandCombat(current_player);
                    }
                    else if (m_map.getTileColor(current_player, m_map.getPlayerPos(current_player)) == "red")
                    {
                        if (rand() % 2 == 0)
                        {

                            int num = rand() % 2;
                            if (num == 0)
                            {
                                cout << "As the Siren's Song echoes through the air, you sense its magical pull, \nan otherworldly force that toys with the hearts of those who dare to listen. \nYou stop in your tracks. You cannot move on your next turn only." << endl;
                                skip_next_turn[current_player] = true;
                            }
                            else if (num == 1)
                            {
                                cout << "As you stand in the brilliance of Helios' Beacon, you feel the warmth of the sun god's favor shining upon you. \nYou feel luckier. Reduce calamity chances by 5%, permanently" << endl;
                                m_game.setPlayerCalamity(current_player, m_game.getPlayerCalamity(current_player) - 5); // decrement calamity by 5
                            }
                            else if (num == 2)
                            {
                                cout << "In the embrace of the Nymph's Spring, you feel the embrace of nature itself. \nYour stamina is replenished" << endl;
                                m_game.setPlayerStamina(current_player, 120); // sets it to a high value that might be close to what the actual highest value is
                            }
                        }
                        else
                        {
                            cout << "You've ran into a hidden chest, but there is a holy spirit locking it. If you can solve the sprits riddle you can open the chest." << endl;
                            m_game.hiddenChest(current_player);
                            

                        }
                    }

                    turn_taken = true;
                }
                else
                {
                    cout << "You need at least 3 stamina to move" << endl;
                    cout << "Your stamina is " << m_game.getPlayer(current_player).getStamina() << endl;
                }
            }
            else if (option == 2)
            {
                m_game.swapWeapon(current_player);
                turn_taken = false;
            }
            else if (option == 3)
            {
                m_game.dropWeapon(current_player);
                turn_taken = false;
            }
            else if (option == 4)
            {
                bool used_potion = m_game.usePotionMenu(current_player);
                if (used_potion)
                {
                    turn_taken = true;
                }
                else
                {
                    turn_taken = false;
                }
            }
            else if (option == 5)
            {
                cout << "-------------------" << endl;
                m_game.getPlayer(current_player).printStats();
                cout << "-------------------" << endl;
            }
            else if (option == 6)
            {
                player_quit = current_player;
                turn_taken = true;
                break;
            }
        }

        if (option == 6) // if player quit
        {
            break;
        }

        // Check player conditions
        if (m_game.getPlayerCondition(current_player) == 'P')
        {
            m_game.setPlayerHP(current_player, m_game.getPlayerHP(current_player) - 5); // get rid of 5 hp
        }
        if (m_game.getPlayerCondition(current_player) == 'D')
        {
            m_game.setPlayerCondition(current_player, m_game.getPlayerCondition(current_player) - 5); // get rid of 5 stamina
        }

        // Switch current player
        current_player = (current_player + 1) % 2;
    }

    // Game over, check who has won
    if (m_map.getPlayerPos(0) > 49)
    {
        cout << m_game.getPlayer(0).getName() << " has reached Ithaca! He has won the game!!!!" << endl;
        m_game.setPlayerWon(0, true);
    }
    else if (m_map.getPlayerPos(1) > 49)
    {
        cout << m_game.getPlayer(1).getName() << " has reached Ithaca! He has won the game!!!!" << endl;
        m_game.setPlayerWon(1, true);
    }
    else if (m_game.getPlayerHP(0) <= 0)
    {
        cout << m_game.getPlayer(0).getName() << " has died." << endl;
        cout << m_game.getPlayer(1).getName() << " has won the game!" << endl;
        m_game.setPlayerWon(1, true);
    }
    else if (m_game.getPlayerHP(1) <= 0)
    {
        cout << m_game.getPlayer(1).getName() << " has died." << endl;
        cout << m_game.getPlayer(0).getName() << " has won the game!" << endl;
        m_game.setPlayerWon(0, true);
    }
    else
    {
        cout << m_game.getPlayer(player_quit).getName() << " quit the game. " << endl;
        if (player_quit == 1)
        {
            player_quit = 0;
        }
        else
        {
            player_quit = 1;
        }
        cout << m_game.getPlayer(player_quit).getName() << " has won the game! " << endl;
        m_game.setPlayerWon(player_quit, true);
    }

    string out_file_name = "results.txt";
    bool successfull_print = m_game.saveResults(out_file_name);
    if (successfull_print)
    {
        cout << "Game saved in \"" << out_file_name << "\"" << endl;
    }
    else
    {
        cout << "Failed to save game in \"" << out_file_name << "\"" << endl;
    }

    printOutro();

    return 0;
}