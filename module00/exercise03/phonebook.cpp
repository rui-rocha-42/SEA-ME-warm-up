//
// Created by CTW03389 on 08/11/2024.
//

#include "phonebook.h"
#include <algorithm>

// initializer-list ctor
Phonebook::Phonebook(std::initializer_list<Contact> il) : contacts {il.begin(), il.end()} {
    std::cout << "phonebook initializer-list ctor\n";
}

// copy ctor
Phonebook::Phonebook(const Phonebook& rhs) : contacts {rhs.contacts} {
    std::cout << "phonebook copy ctor\n";
}

// move ctor
Phonebook::Phonebook(Phonebook&& rhs) noexcept
        : contacts {std::move(rhs.contacts)} {
    std::cout << "phonebook move ctor\n";
}

// dtor
Phonebook::~Phonebook() {
    std::cout << "phonebook dtor\n";
}

void Phonebook::add_contact(const Contact &contact) {
    contacts.emplace_back(contact);
}

unsigned long long Phonebook::size() const {
    return contacts.size();
}

void Phonebook::print() const {
    if(contacts.empty()) return;
    for(const Contact& i : contacts) i.print();
    std::cout << std::endl;
}

std::optional<Contact> Phonebook::contact(int index) {
    if(index < 0 || index > contacts.size() -1) {
        return {};
    }
    return contacts[index];
}

bool Phonebook::remove_contact(const std::string& phone_number) {
    auto c_it = std::find_if(contacts.begin(), contacts.end(),
                        [phone_number](Contact& c) {return c.phone_number() == phone_number;});
    if(c_it != contacts.end()) {
        int index = static_cast<int>(distance(contacts.begin(), c_it));
        return remove_contact(index);
    } else {
        return false;
    }
}

bool Phonebook::remove_contact(int index) {
    auto obj = contact(index);
    if (auto it = contact(index); it.has_value()) {
        contacts.erase(contacts.begin() + index);
        return true;
    }
    return false;
}
