#include <iostream>
#include "../include/Location.h"
using namespace std;

int main() {
    Location l;   double lat, lon;
    do{
        cout<<"Enter Latitude: ";
        cin>>lat;
    } while(!l.setLatitude(lat) && (cout << "Invalid Value! "));
    do{
        cout<<"Enter Longitude: ";
        cin>>lon;
    } while(!l.setLongitude(lon) && (cout << "Invalid Value! "));

    cout<<l.toString();
    return 0;
}
