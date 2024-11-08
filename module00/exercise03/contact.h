//
// Created by CTW03389 on 08/11/2024.
//

#ifndef SEA_ME_WARM_UP_CONTACT_H
#define SEA_ME_WARM_UP_CONTACT_H

#include <iostream>

// -- interface --
class Contact {
    std::string c_name {};
    std::string c_phone_number {};
    std::string c_nickname {};
    bool bookmarked {false};
public:
    Contact(const std::string& name, const std::string& phone_number, const std::string& nickname);
    Contact(const Contact&); // copy constructor
    ~Contact(); // destructor
    Contact& operator = (const Contact&); // copy/assignment operator
    void print() const;
    void bookmark();
    std::string phone_number() {
        return c_phone_number;
    }
};


#endif //SEA_ME_WARM_UP_CONTACT_H
