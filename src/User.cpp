//
// Created by [] on []
//

#include "headers/User.h"

void User::Register(){
    DataFrame registered(CONFIG.registered_path);

    Case x;
    x.header = registered.Header();
    x["Name"] = name;
    x["Email"] = email;
    x["Password"] = password;
    x["Type"] = "user";

    registered.INSERT(x);

    registered.save();
}
