#include <iostream>
#include "../include/Date.h"
using namespace std;


int main() {
    Date d(23, 3, 2024);
    cout<<d.toString("DD-MM-YYYY", "/");


    return 0;
}
