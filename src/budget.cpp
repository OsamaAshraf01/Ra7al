#include "../include/budget.hpp"
#include <iostream>

// Default constructor
Budget::Budget()
{
    totalBudget = 0;
    flightBudget = 0;
    hotelBudget = 0;
    foodBudget = 0;
    entertainmentBudget = 0;
    shoppingBudget = 0;
}

// Constructor with parameters
Budget::Budget(double totalBudgetInput, double flightBudgetInput, double hotelBudgetInput, double foodBudgetInput, double entertainmentBudgetInput, double shoppingBudgetInput)
{
    totalBudget = totalBudgetInput;
    flightBudget = flightBudgetInput;
    hotelBudget = hotelBudgetInput;
    foodBudget = foodBudgetInput;
    entertainmentBudget = entertainmentBudgetInput;
    shoppingBudget = shoppingBudgetInput;
}

// Setters
void Budget::setTotalBudget(double newTotalBudget)
{
    totalBudget = newTotalBudget;
}

void Budget::setFlightBudget(double newFlightBudget)
{
    flightBudget = newFlightBudget;
}

void Budget::setHotelBudget(double newHotelBudget)
{
    hotelBudget = newHotelBudget;
}

void Budget::setFoodBudget(double newFoodBudget)
{
    foodBudget = newFoodBudget;
}

void Budget::setEntertainmentBudget(double newEntertainmentBudget)
{
    entertainmentBudget = newEntertainmentBudget;
}

void Budget::setShoppingBudget(double newShoppingBudget)
{
    shoppingBudget = newShoppingBudget;
}

// Getters
double Budget::getTotalBudget() const
{
    return totalBudget;
}

double Budget::getFlightBudget() const
{
    return flightBudget;
}

double Budget::getHotelBudget() const
{
    return hotelBudget;
}

double Budget::getFoodBudget() const
{
    return foodBudget;
}

double Budget::getEntertainmentBudget() const
{
    return entertainmentBudget;
}

double Budget::getShoppingBudget() const
{
    return shoppingBudget;
}

// Display budget
void Budget::displayBudget()
{
    std::cout << "Total budget: " << totalBudget << std::endl;
    std::cout << "Flight budget: " << flightBudget << std::endl;
    std::cout << "Hotel budget: " << hotelBudget << std::endl;
    std::cout << "Food budget: " << foodBudget << std::endl;
    std::cout << "Entertainment budget: " << entertainmentBudget << std::endl;
    std::cout << "Shopping budget: " << shoppingBudget << std::endl;
}