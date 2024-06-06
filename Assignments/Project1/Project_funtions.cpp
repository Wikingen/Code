 /*

bool isInteger(string input)
{
    if (input[0] == '-')
    {
        input.erase(0, 1);
    }

    int size = input.size();

    for (int i = 0; i < size; i++)
    {
        if (isdigit(input[i]) == false)
        {
            return false;
        }
    }
    return true;
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
                if (key1[i] == key2[j])
                {
                    matching_chars += 1;
                }
            }
        }
    }

    matching_chars %= 26;

    return matching_chars;
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

*/