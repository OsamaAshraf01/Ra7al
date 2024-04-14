//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#include "../../include/DataFrame/Case.h"
#include <sstream>

void Case::print(bool with_header){
    List temp;
    if(with_header)
        cout<<join(header, "\t")<<'\n';
    for(auto e : header)
        temp.append(dict[get<string>(e)]);

    cout<<join(temp, "\t")<<'\n';

}
