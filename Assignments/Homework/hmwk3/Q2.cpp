#include <iostream>
using namespace std;

int main()
{
    int style = -1;
    int artist = -1;
    int painting = -1;

    cout << "Select the Style: (1) Impressionism (2) Surrealism" << endl;
    cin >> style;

    if (!(style == 1 || style == 2))
    {
        cout << "Please enter a valid input";
        return 0;
    }
    else if (style == 1)
    {
        cout << "Select the Artist: (1) Claude Monet (2) Edgar Degas (3) Pierre-Auguste Renoir" << endl;
        cin >> artist;

        if (!(artist == 1 || artist == 2 || artist == 3))
        {
            cout << "Please enter a valid input";
            return 0;
        }
        else if (artist == 1)
        {
            cout << "Select the Artwork: (1) Water Lilies (2) Impression, Sunrise" << endl;
            cin >> painting;
            if (!(painting == 1 || painting == 2))
            {
                cout << "Please enter a valid input";
                return 0;
            }
            else if (painting == 1)
            {
                cout << "You have reserved the artwork: Water Lilies";
            }
            else
            {
                cout << "You have reserved the artwork: Impression, Sunrise";
            }
        }
        else if (artist == 2)
        {
            cout << "Select the Artwork: (1) The Dance Class (2) L'Absinthe" << endl;
            cin >> painting;
            if (!(painting == 1 || painting == 2))
            {
                cout << "Please enter a valid input";
                return 0;
            }
            else if (painting == 1)
            {
                cout << "You have reserved the artwork: The Dance Class";
            }
            else
            {
                cout << "You have reserved the artwork: L'Absinthe";
            }
        }
        else if (artist == 3)
        {
            cout << "Select the Artwork: (1) Luncheon of the Boating Party (2) Bal du moulin de la Galette" << endl;
            cin >> painting;
            if (!(painting == 1 || painting == 2))
            {
                cout << "Please enter a valid input";
                return 0;
            }
            else if (painting == 1)
            {
                cout << "You have reserved the artwork: Luncheon of the Boating Party";
            }
            else
            {
                cout << "You have reserved the artwork: Bal du moulin de la Galette";
            }
        }
    }
    else
    {
        cout << "Select the Artist: (1) Salvador Dali (2) Rena Magritte (3) Frida Kahlo" << endl;
        cin >> artist;

        if (!(artist == 1 || artist == 2 || artist == 3))
        {
            cout << "Please enter a valid input";
            return 0;
        }
        else if (artist == 1)
        {
            cout << "Select the Artwork: (1) The Persistence of Memory (2) The Elephant" << endl;
            cin >> painting;
            if (!(painting == 1 || painting == 2))
            {
                cout << "Please enter a valid input";
                return 0;
            }
            else if (painting == 1)
            {
                cout << "You have reserved the artwork: The Persistence of Memory";
            }
            else
            {
                cout << "You have reserved the artwork: The Elephant";
            }
        }
        else if (artist == 2)
        {
            cout << "Select the Artwork: (1) The Son of Man (2) The Treachery of Images" << endl;
            cin >> painting;
            if (!(painting == 1 || painting == 2))
            {
                cout << "Please enter a valid input";
                return 0;
            }
            else if (painting == 1)
            {
                cout << "You have reserved the artwork: The Son of Man";
            }
            else
            {
                cout << "You have reserved the artwork: The Treachery of Images";
            }
        }
        else if (artist == 3)
        {
            cout << "Select the Artwork: (1) The Two Fridas (2) Self-Portrait with Thorn Necklace" << endl;
            cin >> painting;
            if (!(painting == 1 || painting == 2))
            {
                cout << "Please enter a valid input";
                return 0;
            }
            else if (painting == 1)
            {
                cout << "You have reserved the artwork: The Two Fridas";
            }
            else
            {
                cout << "You have reserved the artwork: Self-Portrait with Thorn Necklace";
            }
        }
    }
}
