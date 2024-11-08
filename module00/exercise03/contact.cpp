//
// Created by CTW03389 on 08/11/2024.
//

#include "contact.h"

Contact::Contact(const std::string& name, const std::string& phone_number, const std::string& nickname)
        : c_name(name), c_phone_number(phone_number), c_nickname(nickname){}

Contact::Contact(const Contact& c) {
    c_name = c.c_name;
    c_nickname = c.c_nickname;
    c_phone_number = c.c_phone_number;
}

Contact::~Contact() {
    std::cout << "destructor\n";
}

// Operator overloading = just so the object doesn't copy itself
Contact& Contact::operator = (const Contact& o) {
    std::cout << "contact assignment operator\n";
    if(this != &o) {
        c_name = o.c_name;
        c_nickname = o.c_nickname;
        c_phone_number = o.c_phone_number;
    }
    return *this;
}

void Contact::print () const {
    std::cout << "Contact " << c_name << "(" << c_nickname << ") w phone " << c_phone_number << " " << (bookmarked ? "x": "o") << std::endl;
}

void Contact::bookmark() {
    bookmarked = !bookmarked;
}
