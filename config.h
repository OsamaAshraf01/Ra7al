#ifndef CONFIG_H
#define CONFIG_H
#include <QString>
#include <string>
using namespace std;


struct {
    // Colors
    string main_color = "#ff6400";


    // Images Paths
    QString logo_path = "D:\\Career\\PROJECTS\\Ra7al\\icons\\logo.png";
    QString go_back_path = "D:\\Career\\PROJECTS\\Ra7al\\icons\\go_back.png";
    QString profile_pic_path = "D:\\Career\\PROJECTS\\Ra7al\\icons\\profile.jpg";

    string registered_users_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\registered_users.csv";
    string countries_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\countries.csv";
    string countries_arilines_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\countries_airlines.csv";
    string flights_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\flights.csv";
    string airports_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\airports.csv";
    string airlines_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\airlines.csv";
    string currencies_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\currencies.csv";
    string hotels_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\hotels.csv";
    string activities_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\activities.csv";
    string itineraries_table = "D:\\Career\\PROJECTS\\Ra7al\\data\\itineraries.csv";
}CONFIG;

#endif // CONFIG_H
