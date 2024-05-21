//
// Created by [] on []
//

#include "headers/User.h"

void User::Register(){
    DataFrame registered(CONFIG.registered_users_table);

    Case x;
    x.header = registered.Header();
    x["ID"] = id;
    x["Name"] = name;
    x["Email"] = email;
    x["Password"] = password;
    x["Type"] = "user";

    registered.INSERT(x);

    registered.save();
}
