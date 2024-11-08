//
// Created by CTW03389 on 08/11/2024.
//

#ifndef SEA_ME_WARM_UP_PHONEBOOK_H
#define SEA_ME_WARM_UP_PHONEBOOK_H

#include "contact.h"
#include <vector>
#include <optional>

class Phonebook  {
    std::vector<Contact> contacts {};
public:
    Phonebook() { std::cout << "default phonebook ctor\n" ; }   // default ctor
    Phonebook(std::initializer_list<Contact> il);    // il ctor
    Phonebook(const Phonebook& rhs);           // copy ctor
    Phonebook(Phonebook&& rhs) noexcept;       // move ctor
    ~Phonebook();
    void print() const;
    void add_contact(const Contact& contact);
    bool remove_contact(int index);
    bool remove_contact(const std::string& phone_number);
    std::optional<Contact> contact(int index);
    [[nodiscard]] unsigned long long size() const;
};


#endif //SEA_ME_WARM_UP_PHONEBOOK_H
