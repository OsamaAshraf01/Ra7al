//
// Created by OSAMA ASHRAF on 3/25/2024.
//

#include <utility>

#include "../../include/DataFrame/DataFrame.h"
#include "../../public/functions.h"

// Constructors
DataFrame::DataFrame(string DataFramePath): path (std::move(DataFramePath)), fout(path, ios::app), fin(path){
    string h;
    getline(fin, h);
    header = split(h, ',');

    string line;
    while(getline(fin, line)){
        List values = split(line, ',');
        Case temp;
        for(int i=0 ; i<header.size() ; i++){
            temp.dict[ get<string>(header[i]) ] = values[i];
        }

        rows.push_back(temp);
    }
}

// Methods


void DataFrame::print() {
    cout<<join(header, "\t")<<'\n';
    for(Case c : rows)
        c.print(header);
}

