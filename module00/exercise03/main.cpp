#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// print a pair
template <typename T1, typename T2>
void print_pair(pair<T1,T2> & p) {
    cout << p.first << ": " << p.second << endl;
}

// print the elements of the map
template<typename T>
void print_map(T & m) {
    if(m.empty()) return;
    for(auto x : m) print_pair(x);
    cout << endl;
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

    // Checking if there's whitespace
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

    cout << "COMMAND: " << command << endl;
    print_map(options);
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
