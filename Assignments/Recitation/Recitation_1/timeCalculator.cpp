#include <iostream>
using namespace std; 


int seconds, minutes, hours, days; //Declare the variables that store the data 

int main() 
{
    

    cout << "Give me a number of seconds: "; //Tells user to give input in terminal

    cin >> seconds; //Recieve input of seconds and store in seconds

    days = seconds/86400; //Gives us the number of times we can fit a day into the amount of seconds
    seconds =  seconds % 86400; // Saves the remainding seconds after the time of days have been subtracted

    hours = seconds/3600;  //Gives us the number of times we can fit an hour into the amount of seconds
    seconds =  seconds % 3600;  // Saves the remainding seconds after the time of hours have been subtracted

    minutes = seconds/60;   //Gives us the number of times we can fit a minute into the amount of seconds
    seconds =  seconds % 60;  // Saves the remainding seconds after the time of minutes have been subtracted

    cout << "That makes " << days << " days " << hours << " hours " << minutes << " minutes and " << seconds << " seconds."; //Print out result





}

