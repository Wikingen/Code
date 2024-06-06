#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"
#include "Game.hpp"
using namespace std;

// returns an int 1-6 incluseive
int diceRoll()
{
    int rand_num = rand() % 6 + 1;
    return rand_num;
}

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void printIntro()
{
    string intro = "In a world of ancient myths and legends,\n"
                   "two brave souls embark on an odyssey\n"
                   "through the treacherous Aegean Sea.\n\n"
                   "Inspired by Homer's epic tale,\n"
                   "they must navigate perilous islands,\n"
                   "encounter formidable foes,\n"
                   "and uncover hidden treasures.\n\n"
                   "With courage and wit as their allies,\n"
                   "they strive to reach the fabled shores of Ithaca,\n"
                   "where glory and triumph await.\n\n"
                   "Prepare for an adventure like no other,\n"
                   "where the fate of heroes is forged\n"
                   "in the crucible of the gods.\n\n"
                   "May the winds of fortune guide your journey,\n"
                   "and may the echoes of legend resound\n"
                   "with the tales of your exploits.\n\n"
                   "The Odyssey awaits...";

    int lineHeight = 2; // Adjust this value to control the speed of the text scrolling
    int delay = 50;     // Delay in milliseconds between each line

    for (int i = 0; i < (int)intro.length(); i++)
    {
        if (intro[i] == '\n')
        {
            this_thread::sleep_for(chrono::milliseconds(delay));
            for (int j = 0; j < lineHeight; j++)
            {
                cout << "\n";
            }
        }
        else
        {
            cout << intro[i];
            this_thread::sleep_for(chrono::milliseconds(delay / 5)); // Slower speed for individual characters
        }
    }

    cout << "\n\nPress Enter to continue...\n";
    string input;
    getline(cin, input);
    return;
}

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void printOutro()
{
    string outro = "The epic journey has come to an end,\n"
                        "and the echoes of your exploits\n"
                        "will resonate through the ages.\n\n"
                        "You have braved the treacherous seas,\n"
                        "conquered formidable foes,\n"
                        "and emerged victorious in the crucible of the gods.\n\n"
                        "May the tales of your odyssey inspire\n"
                        "generations to come,\n"
                        "igniting the flames of courage and resilience.\n\n"
                        "Thank you for playing!\n\n"
                        "Credits:\n"
                        "Teacher: Christoffer Godley\n"
                        "All TAs in CSCI 1300\n"
                        "Creator: Otto Wiking Häger\n\n"
                        "Until our paths cross again,\n"
                        "may the winds of fortune guide your way.\n\n"
                        "Farewell, brave adventurers!";

    int lineHeight = 2; // Adjust this value to control the speed of the text scrolling
    int delay = 50;     // Delay in milliseconds between each line

    for (int i = 0; i < (int)outro.length(); i++)
    {
        if (outro[i] == '\n')
        {
            this_thread::sleep_for(chrono::milliseconds(delay));
            for (int j = 0; j < lineHeight; j++)
            {
                cout << "\n";
            }
        }
        else
        {
            cout << outro[i];
            this_thread::sleep_for(chrono::milliseconds(delay / 5)); // Slower speed for individual characters
        }
    }
    cout << "\n";
}