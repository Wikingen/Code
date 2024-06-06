#include <vector>
#include <iostream>
using namespace std;

vector<string> unsubscribe(vector<string> subscriptions, string newsletter)
{
   vector<string> new_vector;

    for(int i = 0; i< (int)subscriptions.size(); i++)
    {
        if (subscriptions[i] == newsletter)
        {
            continue;
        }
        new_vector.push_back(subscriptions[i]);
    }
    return new_vector;
}

vector<string> subscribe(vector<string> subscriptions, string newsletter)
{
    int repeat = false;
    for (int i = 0; i < (int)subscriptions.size(); i++)
    {
        if (subscriptions[i] == newsletter)
        {
            repeat = true;
        }
    }

    if (!repeat)
    {
        subscriptions.push_back(newsletter);
    }

    return subscriptions;
}
void printVector(vector<string> vector)
{
    if((int)vector.size() == 0)
    {
        cout << "You are not subscribed to any newsletters."<<endl;
        return;
    }
    cout << "Current subscriptions:"<<endl;
    for(int i= 0; i< (int)vector.size(); i++)
    {
        cout << vector[i] << endl;
    }
}
void printMenu()
{
    cout << "1. Subscribe to a newsletter"<<endl;
    cout << "2. Unsubscribe from a newsletter"<<endl;
    cout << "3. Display current subscriptions"<<endl;
    cout << "4. Exit"<<endl;
    cout << "Enter your choice:" <<endl;
}

int main()
{
    vector<string> subscriptions;
    string choice;
    int num_choice =0;
    while (choice !="4")
    {
        printMenu();
        getline(cin,choice);
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
        {
            cout << "Invalid choice! Enter a valid choice." << endl;
            printMenu();
            getline(cin,choice);
        }
        num_choice = stoi(choice);
        string newspaper_name;
        
        switch (num_choice)
        {
        case 1:
            cout << "Enter the name of the newsletter to subscribe to:"<<endl;
            getline(cin,newspaper_name);
            subscriptions = subscribe(subscriptions,newspaper_name);
            break;
        case 2:
            cout << "Enter the name of the newsletter to unsubscribe from:"<<endl;
            getline(cin,newspaper_name);
            subscriptions = unsubscribe(subscriptions,newspaper_name);
            break;
        case 3:
            printVector(subscriptions);
            break;
        default:
            break;
        }
        
        


    }
    
    cout << "Exit"<<endl;
}