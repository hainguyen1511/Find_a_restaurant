#ifndef RESTAURANT_H
#define RESTAURANT_H

struct Restaurant
{
	char restaurantName[101];
	char foodType[101];
	double rating;
};

Restaurant setRestaurant(Restaurant& aRest, char newName[], char newFood[], double newRating);
void PrintValues(Restaurant& aRest);

#endif