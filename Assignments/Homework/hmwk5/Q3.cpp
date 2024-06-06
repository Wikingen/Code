#include <iostream>
using namespace std;

int patternSearch(string sequence, string fragment)
{
    const int sequence_length = sequence.length();
    const int fragment_length = fragment.length();
    int instances = 0;

    for (int i = 0; i < sequence_length; i++)
    {
        if (!(sequence[i] == 'A' || sequence[i] == 'C' || sequence[i] == 'G' || sequence[i] == 'T'))
        {
            return -1;
        }
    }

    for (int i = 0; i < fragment_length; i++)
    {
        if (!(fragment[i] == 'A' || fragment[i] == 'C' || fragment[i] == 'G' || fragment[i] == 'T'))
        {
            return -1;
        }
    }

    for (int i = 0; i < sequence_length; i++)
    {
        bool fragment_found = true;
        if (sequence[i] == fragment[0])
        {

            for (int j = i; j < (i + fragment_length); j++)
            {
                if (sequence[j] != fragment[j - i])
                {
                    fragment_found = false;
                }
            }
            if (fragment_found)
            {
                instances += 1;
            }
            fragment_found = false;
        }
    }
    return instances;
}

int main()
{
    string sequence;
    string fragment;
    cout << "Enter the DNA Sequence:" << endl;
    getline(cin, sequence);
    cout << "Enter the DNA fragment to be searched:" << endl;
    getline(cin, fragment);

    int occurrences = patternSearch(sequence, fragment);

    if (occurrences == -1)
    {
        cout << "This is not a valid DNA sequence." << endl;
    }
    else
    {
        cout << "Number of occurrences: " << occurrences << endl;
    }




    return 0;
}
