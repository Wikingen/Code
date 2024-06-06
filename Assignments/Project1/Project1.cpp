#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

string getLayer1MessageDecryption(string encrypted_message, int method_choice, string key1, string key2);
string getLayer1MessageEncryption(string message, int method_choice, string key1, string key2);
char shiftChar(char letter, int shift_value);
string getKey(string keyphrase);
string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase);
string shiftString(string sentence, int shift_value);
int getDoubleKeyShiftValue(string key1, string key2);
string getLayer2MessageDecryption(string encrypted_message, string key_phrase);
string getLayer2MessageEncryption(string message, string key_phrase);
string getChainDecryption(string encrypted_message, int method_choice, string key1, string key2, string key_phrase);
void printMenu();

int main()
{
    string str_menu_choice;
    string str_enc_menu_choice;
    string str_method1_technique;
    int method1_technique;
    int menu_choice = -1;     // main menu choice
    int enc_menu_choice = -1; // encryptioon methos menu choice
    string message;
    string encrypted_message;
    int method_choice = -1;
    string key1;
    string key2;
    string key_phrase;
    string decrypted_message;
    bool key1_is_given = false;
    bool key2_is_given = false;
    bool keyphrase_is_given = false;
    bool encryption_method_is_given = false;
    bool valid_keyphrase = false;

    do
    {
        printMenu();
        getline(cin, str_menu_choice);

        while (!(str_menu_choice == "1" || str_menu_choice == "2" || str_menu_choice == "3" || str_menu_choice == "4" || str_menu_choice == "5" || str_menu_choice == "6" || str_menu_choice == "7"))
        {
            cout << "Invalid input" << endl;
            printMenu();
            getline(cin, str_menu_choice);
        } // after this the choice must be a valid choice

        menu_choice = stoi(str_menu_choice); // make an  int so we can use switch case

        switch (menu_choice)
        {
        case 1:

            cout << "Enter First key: " << endl;
            getline(cin, key1);

            while ((int)key1.length() < 1) // make sure key is valid
            {
                cout << "Invalid key" << endl;
                cout << "Enter First key: " << endl;
                getline(cin, key1);
            }

            key1_is_given = true;
            cout << "Successfully set first encryption key to " << key1 << endl;

            break;

        case 2:

            cout << "Enter Second key: " << endl;
            getline(cin, key2);

            while ((int)key2.length() < 1) // make sure key is valid
            {
                cout << "Invalid key" << endl;
                cout << "Enter Second key: " << endl;
                getline(cin, key2);
            }

            key2_is_given = true;
            cout << "Successfully set second encryption key to " << key2 << endl;

            break;

        case 3:

            valid_keyphrase = true;

            cout << "Enter keyphrase: " << endl;
            getline(cin, key_phrase);

            
            for(int i = 0; i < (int)key_phrase.length(); i++)
            {
                if(!(isalpha(key_phrase[i]) || key_phrase[i] == ' '))
                {
                    valid_keyphrase = false;

                }
            }            

            while ((int)key_phrase.length() < 1 || !valid_keyphrase)
            {
                cout << "Invalid keyphrase" << endl;
                cout << "Enter keyphrase: " << endl;
                getline(cin, key_phrase);
                valid_keyphrase = true;   //set up before validation test
                for (int i = 0; i < (int)key_phrase.length(); i++)
                {
                    if (!(isalpha(key_phrase[i]) || key_phrase[i] == ' '))
                    {
                        valid_keyphrase = false;
                    }
                }
            }

            keyphrase_is_given = true;
            cout << "Successfully set encryption keyphrase to " << key_phrase << endl;

            break;

        case 4:
            cout << "Please input 1-3 to decide encryption technique. \n1. Layer 1 Message Encryption \n2. Layer 2 Message Encryption \n3. Chain Encryption " << endl;
            getline(cin, str_enc_menu_choice);

            while (!(str_enc_menu_choice == "1" || str_enc_menu_choice == "2" || str_enc_menu_choice == "3"))
            {
                cout << "Invalid encryption choice" << endl;
                getline(cin, str_enc_menu_choice);
                cout << "Please input 1-3 to decide encryption technique. \n1. Layer 1 Message Encryption \n2. Layer 2 Message Encryption \n3. Chain Encryption " << endl;
            } // after this the choice must be a valid choice

            enc_menu_choice = stoi(str_enc_menu_choice);

            switch (enc_menu_choice) // OBS this is an inner switch inside of switch
            {
            case 1: // Layer 1 encryption chosen

                method_choice = 1;
                encryption_method_is_given = true;
                cout << "Successfully set encryption type to " << method_choice << endl;

                cout << "Please input 1-2 to decide Layer-1 encryption technique.\n1. Shift by 13 \n2. Shift by mixed keys \n";

                getline(cin, str_method1_technique);

                while (!(str_method1_technique == "1" || str_method1_technique == "2"))
                {
                    cout << "Invalid encryption choice" << endl;
                    cout << "Please input 1-2 to decide Layer-1 encryption technique.\n1. Shift by 13 \n2. Shift by mixed keys \n";
                    getline(cin, str_method1_technique);
                } // after this the choice must be a valid choice

                method1_technique = stoi(str_method1_technique);
                

                break;

            case 2:
                method_choice = 2;
                encryption_method_is_given = true;
                cout << "Successfully set encryption type to " << method_choice << endl;

                break;

            case 3:

                method_choice = 3;
                encryption_method_is_given = true;
                cout << "Successfully set encryption type to " << method_choice << endl;
                cout << "Please input 1-2 to decide Layer-1 encryption technique.\n1. Shift by 13 \n2. Shift by mixed keys \n";

                getline(cin, str_method1_technique);

                while (!(str_method1_technique == "1" || str_method1_technique == "2"))
                {
                    cout << "Invalid encryption choice" << endl;
                    cout << "Please input 1-2 to decide Layer-1 encryption technique.\n1. Shift by 13 \n2. Shift by mixed keys \n";
                    getline(cin, str_method1_technique);

                } // after this the choice must be a valid choice

                method1_technique = stoi(str_method1_technique);
                

                break;

            default:
                cout << "Something went horribly wrong and we ended up in default switch" << endl;

                break;
            }

            break;

        case 5:

            if (key1_is_given && key2_is_given && keyphrase_is_given && encryption_method_is_given)
            {
                cout << "Enter your message to encrypt: " << endl;
                getline(cin, message);

                if (method_choice == 1)
                {
                    encrypted_message = getLayer1MessageEncryption(message, method1_technique, key1, key2);
                    cout << encrypted_message << endl;
                }
                else if (method_choice == 2)
                {
                    encrypted_message = getLayer2MessageEncryption(message, key_phrase);
                    cout << encrypted_message << endl;
                }
                else if (method_choice == 3)
                {
                    encrypted_message = getChainEncryption(message, method1_technique, key1, key2, key_phrase);
                    
                    cout << encrypted_message << endl;
                }
                else
                {
                    cout << "Something went very wrong her bro" << endl;
                }
            }
            else
            {
                cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
            }

            break;

        case 6: 
            if (key1_is_given && key2_is_given && keyphrase_is_given && encryption_method_is_given)
            {
                cout << "Enter your message to decrypt: " << endl;
                getline(cin, encrypted_message);

                if (method_choice == 1)
                {
                    message = getLayer1MessageDecryption(encrypted_message, method1_technique, key1, key2);
                    cout << message << endl;
                }
                else if (method_choice == 2)
                {
                    message = getLayer2MessageDecryption(encrypted_message, key_phrase);
                    cout << message << endl;
                }
                else if (method_choice == 3)
                {
                    message = getChainDecryption(encrypted_message, method1_technique, key1, key2, key_phrase);
                    cout << message << endl;
                }
                else
                {
                    cout << "Something went very wrong her bro" << endl;
                }
            }
            else
            {
                cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
            }

            break;

        case 7:
            cout << "Goodbye." << endl;
            break;

        default: // It should not be able to get here.
            cout << "Something went very wrong and our menu choice was not 1,2,3,4,5,6,7! gulp!" << endl;
            break;
        }

    } while (menu_choice != 7); // if choice was 7 we should have printed end message and can now break loop

    return 0;
}

void printMenu(){
    cout << "Please input 1-7 followed by enter to navigate the menu:\n1. Set Encryption Key 1\n2. Set Encryption Key 2 \n3. Set Key Phrase \n4. Select Encryption Method \n5. Encrypt Message \n6. Decrypt Message \n7. Exit Program \n";
}

string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase)
{
    if (message == "" || !(method_choice == 1 || method_choice == 2) || key_phrase == "")
    {
        return message;
    }
    else if (method_choice == 2)
    {
        if (key1 == "" || key2 == "")
        {
            return message;
        }
    }

    string key = getKey(key_phrase); // Check before if second encryption will take place
    const int key_length = key.length();
    if (key_phrase == "" || (int)key.length() == 0) // if there is no key phrase just return that messege instantly
    {
        return message;
    }

    bool valid_key = true; // check if we have valid key
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            valid_key = false;
        }
    }

    if (!valid_key)
    {
        return message;
    }

    string resultant = getLayer1MessageEncryption(message, method_choice, key1, key2);


    string double_encrypted_message = getLayer2MessageEncryption(resultant, key_phrase);

    return double_encrypted_message;
}

string getChainDecryption(string encrypted_message, int method_choice, string key1, string key2, string key_phrase)
{

    if (encrypted_message == "" || !(method_choice == 1 || method_choice == 2) || key_phrase == "")
    {
        return encrypted_message;
    }
    else if (method_choice == 2)
    {
        if (key1 == "" || key2 == "")
        {
            return encrypted_message;
        }
    }

    string key = getKey(key_phrase); // Check before if second encryption will take place
    const int key_length = key.length();
    if (key_phrase == "" || key_length == 0) // if there is no key phrase just return that messege instantly
    {
        return encrypted_message;
    }

    bool valid_key = true; // check if we have valid key
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            valid_key = false;
        }
    }

    if (!valid_key)
    {
        return encrypted_message;
    }

    string resultant = getLayer1MessageDecryption(encrypted_message, method_choice, key1, key2);

    string decrypted_message = getLayer2MessageDecryption(resultant, key_phrase);

    return decrypted_message;
}

string getLayer1MessageDecryption(string encrypted_message, int method_choice, string key1, string key2)
{
    string message;
    if (method_choice == 1)
    {
        message = shiftString(encrypted_message, -13);
    }
    else if (method_choice == 2)
    {
        int shift_distance = getDoubleKeyShiftValue(key1, key2);
        message = shiftString(encrypted_message, -1 * shift_distance);
    }
    else
    {
        message = encrypted_message;
    }
    return message;
}

string getLayer1MessageEncryption(string message, int method_choice, string key1, string key2)
{
    string shifted_message;
    if (method_choice == 1)
    {
        shifted_message = shiftString(message, 13);
    }
    else if (method_choice == 2)
    {
        int shift_distance = getDoubleKeyShiftValue(key1, key2);
        shifted_message = shiftString(message, shift_distance);
    }
    else
    {
        shifted_message = message;
    }
    return shifted_message;
}

string getLayer2MessageEncryption(string message, string key_phrase)
{

    string key = getKey(key_phrase);
    const int key_length = key.length();
    if (key_phrase == "" || key_length == 0) // if there is no key phrase just return that messege instantly
    {
        return message;
    }

    bool valid_key = true; // check if we have valid key
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            valid_key = false;
        }
    }

    if (!valid_key)
    {
        return message;
    }

    string encrypted_message;
    char incrypted_letter;
    int shift_value = 0;
    const int message_length = message.length();

    int j = 0; // index variable for key

    for (int i = 0; i < message_length; i++) // iterate through message
    {
        if (isalpha(message[i])) // if char in message is letter
        {
            shift_value = (int)key[j] - 65; // gives us alphabetical index for uppercase characters.
            j = (j + 1) % key_length;       // adds 1 to our key index, and modules it to make sure it doesnt go out of index.
            incrypted_letter = shiftChar(message[i], shift_value);
            encrypted_message += incrypted_letter;
        }
        else // if char in message is not letter
        {
            encrypted_message += message[i]; // addds non letter to encrypted message
        }
    }

    return encrypted_message;
}

string shiftString(string sentence, int shift_value)
{
    string shifted_string;
    const int sentence_length = sentence.length();
    for (int i = 0; i < sentence_length; i++)
    {
        shifted_string += shiftChar(sentence[i], shift_value);
    }

    return shifted_string;
}

string getLayer2MessageDecryption(string encrypted_message, string key_phrase)
{

    string key = getKey(key_phrase);
    const int key_length = key.length();
    if (key_phrase == "" || key_length == 0) // if there is no key phrase just return that messege instantly
    {
        return encrypted_message;
    }

    bool valid_key = true; // check if we have valid key
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            valid_key = false;
        }
    }

    if (!valid_key)
    {
        return encrypted_message;
    }

    string message;
    char letter;
    int shift_value = 0;
    const int encrypted_message_length = encrypted_message.length();

    int j = 0; // index variable for key

    for (int i = 0; i < encrypted_message_length; i++) // iterate through message
    {
        if (isalpha(encrypted_message[i])) // if char in message is letter
        {
            shift_value = (int)key[j] - 65; // gives us alphabetical index for uppercase characters.
            j = (j + 1) % key_length;       // adds 1 to our key index, and modules it to make sure it doesnt go out of index.
            letter = shiftChar(encrypted_message[i], -1 * shift_value);
            message += letter;
        }
        else // if char in message is not letter
        {
            message += encrypted_message[i]; // addds non letter to encrypted message
        }
    }

    return message;
}

char shiftChar(char letter, int shift_value)
{

    if (shift_value < 0)
    {
        shift_value = -1 * (abs(shift_value) % 26);
    }
    else if (shift_value > 26)
    {
        shift_value = shift_value % 26;
    }

    char shifted_letter;

    if (islower(letter))
    {
        if ((letter + shift_value) > 122)
        {
            shifted_letter = (letter + shift_value - 26);
        }
        else if (letter + shift_value < 97)
        {

            shifted_letter = (letter + shift_value + 26);
        }
        else
        {
            shifted_letter = letter + shift_value;
        }
    }

    else if (isupper(letter))
    {
        if (letter + shift_value > 90)
        {
            shifted_letter = (letter + shift_value - 26);
        }

        else if (letter + shift_value < 65)
        {
            shifted_letter = (letter + shift_value + 26);
        }
        else
        {
            shifted_letter = letter + shift_value;
        }
    }
    else
    {
        return letter;
    }
    return shifted_letter;
}

string getKey(string key_phrase)
{
    string real_key;
    char real_key_char;
    int phrase_length = key_phrase.length();
    int real_key_length = real_key.length();

    real_key_char = key_phrase[0];
    if (islower(real_key_char))
    {
        real_key_char -= 32; // makes it uppercase
    }
    real_key += real_key_char;

    for (int i = 0; i < phrase_length - 1; i++) // loops throug characters. Until - 1 since we dont want to take the next letter if the last letter is a space.
    {

        if (key_phrase[i] == ' ') // checks all but first if character after space is a letter, if so it saves it into phrase
        {
            real_key_char = key_phrase[i + 1];
            if (islower(real_key_char))
            {
                real_key_char -= 32; // makes it uppercase
            }

            real_key += real_key_char;
        }
    }

    for (int i = 0; i < real_key_length; i++) // loop checks if there are special character and returns a empty key if so
    {
        if (!isalpha(real_key[i]))
        {
            return "";
        }
    }

    return real_key;
}

int getDoubleKeyShiftValue(string key1, string key2)
{
    int matching_chars = 0;

    const int key_length_1 = key1.length();

    const int key_length_2 = key2.length();

    if (key_length_1 && key_length_2)
    {
        for (int i = 0; i < key_length_1; i++)
        {

            for (int j = 0; j < key_length_2; j++)
            {
                // cout << " Key1: " << key1[i] << " key2: " << key2[j] << "\t";
                if (toupper(key1[i]) == toupper(key2[j]))
                {
                    matching_chars += 1;
                    
                }
            }
        }
    }

    matching_chars %= 26;


    return matching_chars;
}