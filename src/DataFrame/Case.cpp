//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#include "headers/DataFrame/Case.h"
#include <sstream>

Case::Case(){}


void Case::print(bool with_header){
    List temp;
    if(with_header)
        cout<<join(header, "\t")<<'\n';
    for(auto e : header)
        temp.append(dict[get<string>(e)]);

    cout<<join(temp, "\t")<<'\n';

}

string Case::toString(){
    ostringstream oss;
    for(auto col : header){
        oss << dict[get<string>(col)] << ',';
    }
    return strip(oss.str(), ","); // remove any redundant commas before returning
}
