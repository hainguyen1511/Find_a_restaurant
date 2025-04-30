#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include "Restaurant.h"
using namespace std;


Restaurant setRestaurant(Restaurant& aRest, char newName[], char newFood[], double newRating)
{
	strcpy(aRest.restaurantName, newName);
	strcpy(aRest.foodType, newFood);
	aRest.rating = newRating;
	return aRest;
}

void PrintValues(Restaurant& aRest)
{
	cout << aRest.restaurantName << ";" << aRest.foodType << ";" << fixed << showpoint << setprecision(1) << aRest.rating << endl;
	return;
}