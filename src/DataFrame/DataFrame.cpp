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
        temp.header = header;
        for(int i=0 ; i<header.size() ; i++){
            temp.dict[ get<string>(header[i]) ] = values[i];
        }

        rows.push_back(temp);
    }
}

DataFrame::DataFrame(List& header): header(header){}

// Methods

void DataFrame::print(){
    cout<<join(header, "\t")<<'\n';
    for(Case& c : rows)
        c.print();
}

DataFrame DataFrame::select(vector<string> conditionColumns, vector<Any> conditionValues){
    DataFrame temp(header);  bool isMatched;
    for(int i=0 ; i<rows.size() ; i++){
        Case x = rows[i];
        isMatched = true;
        for(int j=0 ; j<conditionColumns.size() ; j++){
            if(x[ conditionColumns[j] ] != conditionValues[j])
                isMatched = false;
        }

        if(isMatched)
            temp.insert(x);
    }

    return temp;
}


void DataFrame::insert(Case& x){
    rows.push_back(x);
}


List DataFrame::Header(){return header;}


// Operators
Case& DataFrame::operator[](int index){
    return rows[index];
}