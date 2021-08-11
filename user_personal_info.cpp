#include "include/user_personal_info.h"

std::string user_personal_info::get_name()
{
    return name;
}

std::string user_personal_info::get_address()
{
    return address;
}

std::string user_personal_info::get_contact()
{
    return contact;
}

user_personal_info::user_personal_info(std::string name_,std::string address_,std::string contact_)
{
    name = name_;
    address = address_;
    contact = contact_;
}
