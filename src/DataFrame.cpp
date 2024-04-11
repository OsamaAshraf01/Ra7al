//
// Created by OSAMA ASHRAF on 3/25/2024.
//

#include <utility>

#include "../include/DataFrame.h"
#include "../include/publicFunctions.h"

// Constructors
Database::Database(string databasePath): path(std::move(databasePath)), fout(path, ios::app), fin(path) {}

// Methods
void Database::insert(vector<string> values) {
    fout << '\n' << join(values, ",");
}


void Database::close(){this->fout.close();}