#include <iostream>
#include <string>
#include <unordered_map>
 
int main()
{
    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
 
    // Helper lambda function to print key:value pairs
    auto print_key_value = [](std::string const& key, std::string const& value) {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };
 
    std::cout << "Iterate and print keys and values of unordered_map, being\n"
                 "explicit with the type of the iterator, n:\n";
    for( const std::pair<const std::string, std::string>& n : u ) {
        print_key_value(n.first, n.second);
    }
    std::cout << "\n";
 
    std::cout << "Iterate and print keys and values of unordered_map,\n"
                 "using auto:\n";
    for( const auto& n : u ) {
        print_key_value(n.first, n.second);
    }
    std::cout << "\n";
 
    std::cout << "Iterate and print keys and values using structured binding\n"
                 "(since C++17):\n";
    for( const auto& [key, value] : u ) {
        print_key_value(key, value);
    }
    std::cout << "\n";
 
    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";
 
    std::cout << "Output values by key:\n";
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n\n";
 
    // Use of operator[] with non-existent key inserts a new value
    print_key_value("new_key", u["new_key"]);
    std::cout << "Iterating over the unordered_map shows `new_key` is now one\n"
                 "of the keys in the map:\n";
    for( const std::pair<const std::string, std::string>& n : u ) {
        print_key_value(n.first, n.second);
    }
}