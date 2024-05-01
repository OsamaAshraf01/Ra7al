//
// Created by OSAMA ASHRAF on 3/25/2024.
//
#include "headers/DataFrame/DataFrame.h"

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
        for(int i=0 ; i<(int)header.size() ; i++){
            temp.dict[ get<string>(header[i]) ] = values[i];
        }

        rows.push_back(temp);
    }
}

DataFrame::DataFrame(List& header): header(header){}

// Methods
bool DataFrame::isEmpty(){
    return rows.empty();
}

void DataFrame::print(){
    cout<<join(header, "\t")<<'\n';
    for(Case& c : rows)
        c.print(false); // To print the case without header
}

DataFrame DataFrame::SELECT(vector<string> conditionColumns, vector<Any> conditionValues, function<bool(Any, Any)> operation) {
    DataFrame temp(header);
    bool isMatched;
    for (int i = 0; i < (int)rows.size(); i++) {
        Case x = rows[i];
        isMatched = true;
        for (int j = 0; j < (int)conditionColumns.size(); j++) {
            if (!operation(x[conditionColumns[j]], conditionValues[j]))
                isMatched = false;
        }

        if (isMatched)
            temp.INSERT(x);
    }

    return temp;
}

void DataFrame::INSERT(Case& x){
    rows.push_back(x);
    // TODO: Sort after adding sort function
}

void DataFrame::UPDATE(string conditionColumn, Any conditionValue, string updateColumn, Any newValue, function<bool(Any, Any)> operation){
    for(int i=0 ; i<(int)rows.size() ; i++){
        if(operation(rows[i][conditionColumn], conditionValue))
            rows[i][updateColumn] = newValue;
    }
}

List DataFrame::Header(){return header;}

QString DataFrame::toQstring(){
    ostringstream oss;
    oss << "{";
    for(Case& x : rows){
        oss<<x.toString();
    }
    oss << "}";

    return QString::fromStdString(oss.str());
}

void DataFrame::save(){
    fstream clear_and_fout(CONFIG.registered_path);
    clear_and_fout << join(header, ",") <<'\n';

    for(auto row : rows){
        clear_and_fout << row.toString() << '\n';
    }

    clear_and_fout.close();
}

// Operators
Case& DataFrame::operator[](int index){
    return rows[index];
}
