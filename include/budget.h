#include <iostream>
#include <string>
using namespace std;

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
    Budget()
    {
        totalBudget = 0;
        flightBudget = 0;
        hotelBudget = 0;
        foodBudget = 0;
        entertainmentBudget = 0;
        shoppingBudget = 0;
    }

    // Constructor with parameters
    Budget(double totalBudgetInput, double flightBudgetInput, double hotelBudgetInput, double foodBudgetInput, double entertainmentBudgetInput, double shoppingBudgetInput)
    {
        totalBudget = totalBudgetInput;
        flightBudget = flightBudgetInput;
        hotelBudget = hotelBudgetInput;
        foodBudget = foodBudgetInput;
        entertainmentBudget = entertainmentBudgetInput;
        shoppingBudget = shoppingBudgetInput;
    }

    // Setters
    void setTotalBudget(double newTotalBudget)
    {
        totalBudget = newTotalBudget;
    }

    void setFlightBudget(double newFlightBudget)
    {
        flightBudget = newFlightBudget;
    }

    void setHotelBudget(double newHotelBudget)
    {
        hotelBudget = newHotelBudget;
    }

    void setFoodBudget(double newFoodBudget)
    {
        foodBudget = newFoodBudget;
    }

    void setEntertainmentBudget(double newEntertainmentBudget)
    {
        entertainmentBudget = newEntertainmentBudget;
    }

    void setShoppingBudget(double newShoppingBudget)
    {
        shoppingBudget = newShoppingBudget;
    }

    // Getters
    double getTotalBudget() const
    {
        return totalBudget;
    }

    double getFlightBudget() const
    {
        return flightBudget;
    }

    double getHotelBudget() const
    {
        return hotelBudget;
    }

    double getFoodBudget() const
    {
        return foodBudget;
    }

    double getEntertainmentBudget() const
    {
        return entertainmentBudget;
    }

    double getShoppingBudget() const
    {
        return shoppingBudget;
    }

    // Display budget
    void displayBudget()
    {
        cout << "Total budget: " << totalBudget << endl;
        cout << "Flight budget: " << flightBudget << endl;
        cout << "Hotel budget: " << hotelBudget << endl;
        cout << "Food budget: " << foodBudget << endl;
        cout << "Entertainment budget: " << entertainmentBudget << endl;
        cout << "Shopping budget: " << shoppingBudget << endl;
    }
};
