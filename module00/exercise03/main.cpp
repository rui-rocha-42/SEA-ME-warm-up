#include <iostream>
#include <map>
#include <sstream>
#include "phonebook.h"

using namespace std;

Phonebook contacts {
    Contact{"Rui", "123", "RR"},
    Contact{"Pedro", "345", "Petrus"}
};

int parse_int(const string& str) {
    try {
        return stoi(str);
    }
    catch(...) {
        return -1;
    }
}

void add_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("n");
    if(it == options.end()){
        cout << "Name is required\n";
        return;
    }
    string name = it->second;

    it = options.find("p");
    if(it == options.end()){
        cout << "Phone number is required\n";
        return;
    }
    string phone_number = it->second;

    it = options.find("k");
    if(it == options.end()){
        cout << "Nickname is required\n";
        return;
    }
    string nickname = it->second;

    cout << "Adding user " << name << " " << phone_number << " " << nickname << endl;
    contacts.add_contact(Contact {name, phone_number, nickname});
}

void remove_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("i");
    bool removed;
    if(it == options.end()){
        it = options.find("p");
        if(it == options.end()){
            cout << "No inputted id\n";
            return;
        }
        // Retrieve id of phone number (if not exists return)
        string phone = it->second;
        removed = contacts.remove_contact(phone);
    }
    else {
        int index = parse_int(it->second);
        cout << "Removing contact with index " << index << endl;
        removed = contacts.remove_contact(index);
    }
    if(removed) cout << "Successfully removed\n";
    else cout << "Error removing\n";
}

void search_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("i");
    if(it == options.end()){
        cout << "Listing all contacts\n";
        contacts.print();
        return;
    }
    int index = parse_int(it->second);

    cout << "Searching contact with index " << index << endl;
    if (auto contact = contacts.contact(index); contact.has_value()) {
        contact.value().print();
    }
}

void bookmark_contact(const std::map<std::string, std::string>& options) {
    auto it = options.find("i");
    if(it == options.end()){
        cout << "Listing bookmarked contacts\n";
        return;
    }
    int index = parse_int(it->second);

    if(index < 0 || index > contacts.size() - 1) {
        cout << "Index out of bounds\n";
        return;
    }
    cout << "Bookmarking contact with index " << index << endl;
    if (auto contact = contacts.contact(index); contact.has_value()) {
        contact.value().bookmark();
    }
}

string prompt(const string& p) {
    std::string r {};
    cout << p << ">";
    getline(std::cin, r, '\n');

    return r;
}

bool jump(const string& select) {
    size_t whitespace = select.find(' ');
    string command {select};
    std::map<std::string, std::string> options;

    // Checking if there's whitespace to check for options
    if(whitespace != std::string::npos) {
        command = select.substr(0, whitespace);

        string options_str {select.substr(whitespace + 1, select.size())};
        std::istringstream iss(options_str);
        std::string token;

        std::string current_key;

        while (iss >> token) {
            if (token[0] == '-') {
                current_key = token.substr(1);
            } else {
                options[current_key] = token;
            }
        }
    }

    using jumpfunc = void(*)(const std::map<std::string, std::string>&);

    const std::map<string, jumpfunc> jumpmap {
            { "ADD", ::add_contact },
            { "SEARCH",::search_contact },
            { "REMOVE", ::remove_contact },
            { "BOOKMARK", ::bookmark_contact },
    };

    const auto it = jumpmap.find(command);
    if (it != jumpmap.end()) it->second(options);
    else {
        cout << "Invalid command\n";
        return false;
    }

    return true;
}

int main()
{
    cout << "PHONEBOOK\n";

    string pstr {
            "Commands: \nADD -n name -p phonenumber -k nickname\n"
            "SEARCH [-i <index>]\n"
            "REMOVE -i <index>/-p <phonenumber>\n"
            "BOOKMARK [-i <index>]\n"
            "EXIT\n"
    };

    for (auto key = prompt(pstr); key != "EXIT"; key = prompt(pstr)) {
        if (key.size() > 1) jump(key);
    }
    cout << "Bye!\n";

    return 0;
}
