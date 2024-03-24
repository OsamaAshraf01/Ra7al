#pragma once
#include <string>

class Budget
{
private:
    double totalBudget;
    double flightBudget;
    double hotelBudget;
    double foodBudget;
    double entertainmentBudget;
    double shoppingBudget;

public:
    // Default constructor
    Budget();

    // Constructor with parameters
    Budget(double totalBudgetInput, double flightBudgetInput, double hotelBudgetInput, double foodBudgetInput, double entertainmentBudgetInput, double shoppingBudgetInput);

    // Setters
    void setTotalBudget(double newTotalBudget);
    void setFlightBudget(double newFlightBudget);
    void setHotelBudget(double newHotelBudget);
    void setFoodBudget(double newFoodBudget);
    void setEntertainmentBudget(double newEntertainmentBudget);
    void setShoppingBudget(double newShoppingBudget);

    // Getters
    double getTotalBudget() const;
    double getFlightBudget() const;
    double getHotelBudget() const;
    double getFoodBudget() const;
    double getEntertainmentBudget() const;
    double getShoppingBudget() const;

    // Display budget
    void displayBudget();
};