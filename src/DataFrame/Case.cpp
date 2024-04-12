//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#include "../../include/DataFrame/Case.h"
#include <sstream>

void Case::print(List header){
    List temp;

    for(auto e : header)
        temp.append(dict[get<string>(e)]);

    cout<<join(temp, "\t\t")<<'\n';

}
