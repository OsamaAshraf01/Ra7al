//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#include "../../include/DataFrame/Case.h"
#include <sstream>

void Case::print(){
    List temp;

    for(const auto& i : dict)
        temp.append(i.second);

    cout<<join(temp, "\t\t")<<'\n';

}
