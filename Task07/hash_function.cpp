// Creator: Jeremi Toroj
// Date: 29.12.2023

#include "hash_function.hpp"
#include <string>

unsigned int hash_function(const std::string& key, std::size_t buckets_num) {
    unsigned int hash = 5381; 

    for (char c : key) {
        hash = ((hash << 5) + hash) + static_cast<unsigned int>(c);
    }

    return hash % buckets_num;
}
