//**************************************************************************
//Author: Hai Nguyen
//Assignment: Assignment 08 Structs
//Date: 21 Jan 2021
//Description: Read from a given text file into an array, print arrays
//and search array.
//Input: file restaurant.txt
//Output: aRest.restaurantName, aRest.foodType, aRest.rating
//Sources: using Restaurant.h and Restaurant.cpp from ZyLab 10.6.
//**************************************************************************
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Restaurant.h"
using namespace std;

//global constants
const int CAP = 100;
//function prototypes
void displayMenu();
char readOption();
char readOption();
void readata(Restaurant aRest[CAP], ifstream& inFile, int& count);
void printdata(Restaurant aRest[CAP], int count);
void srchByName(Restaurant aRest[CAP], int count);
//main
int main(){
    Restaurant aRest[CAP];
    char option;
    int count = 0;
    string fileName;
    cout << "Welcome to my Restaurant Database:\n";
    cout << "Pick from one of the following options:\n\n";
    ifstream inFile;
    fileName = "Restaurant.txt";
    inFile.open(fileName);
    if (!inFile) {
        cout << "Could not open file Restaurant.txt" << endl;
        exit(0);
    }
    else if (inFile) {
        readata(aRest, inFile, count);
        do
        {
            displayMenu();
            option = tolower(readOption());//convert user option to lower case
            switch (option)
            {
            case 'p':
                printdata(aRest, count);
                break;
            case 's':
                srchByName(aRest,count);
                break;
            case 'q':
                cout << "Thank you for visiting my Database!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
            }
        } while (option != 'q');
    }
    return 0;
}

//displayMenu
//outputs the menu to the user
//takes no parameters
//returns nothing
void displayMenu()
{
    cout << "\n\n";
    cout << "(p) Print the restaurant list" << endl;
    cout << "(s) Search the restaurant list by name" << endl;
    cout << "(q) Quit" << endl;
    cout << "\n\n";
}

//returns user's choice
char readOption(){
    char option;
    cin >> option;
    return option;
}
//read all data in the file
//also share every thing it read from file to other functions
//also count the number of rows in the file
void readata(Restaurant aRest[CAP], ifstream& inFile, int& count)
{
    char newName[CAP];
    char newFood[CAP];
    double newRating = 0;
    while (!inFile.eof())
    {
    inFile >> newName>> newFood >> newRating;
    aRest[count] = setRestaurant(aRest[count], newName, newFood, newRating);
    count++;
    }
}
//this function will only print data until reaching the count it got from readata.
void printdata(Restaurant aRest[CAP], int count){
    int i;

    for (i = 0 ; i < count; i++){
    PrintValues(aRest[i]);
    }
}
//this function will search the first collum it receive from readata function
void srchByName(Restaurant aRest[CAP], int count){
    string srchRest;
    int i;
    int result = 0;
    cout << "Please enter a name to search for: ";
    cin >> srchRest;
    for ( i = 0; i < count; i++)
    {
      if (string(aRest[i].restaurantName).find(srchRest) != string::npos)
      {
      PrintValues(aRest[i]);
      result++;
      }
    }
    if (result == 0)
    {
    cout << "No entries found!" << endl;
    }
}