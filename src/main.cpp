#include <iostream>
#include "../include/Time.h"
using namespace std;

int main() {
    Time t(5, 0, 0, "AM");
    cout<<t.toString()<<'\n';
    t.addHours(7);
    t.addMinutes(30);
    t.addSeconds(40);
    cout << t.toString("hh:mm") <<'\n';

    return 0;
}
