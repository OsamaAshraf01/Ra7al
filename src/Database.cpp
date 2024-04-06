//
// Created by OSAMA ASHRAF on 3/25/2024.
//

#include "../include/Database.h"
#include "../include/publicFunctions.h"

// Constructors
Database::Database(string databasePath): path(databasePath), fout(path, ios::app), fin(path) {}

// Methods
void Database::insert(vector<string> values) {
    fout << '\n' << join(values, ",");
}

void Database::close(){this->fout.close();}