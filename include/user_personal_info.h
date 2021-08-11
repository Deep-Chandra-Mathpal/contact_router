#ifndef USER_PERSONAL_INFO_H
#define USER_PERSONAL_INFO_H

#include<bits/stdc++.h>

class user_personal_info
{
    private:
        std::string name;
        std::string address;
        std::string contact;
    public:
        user_personal_info(std::string,std::string,std::string);
        std::string get_name();
        std::string get_address();
        std::string get_contact();            
};

#endif