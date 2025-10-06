#include <iostream>
#include <vector>
// std::map vs std::unordered_map
// -------------------------------
// Both store key-value pairs, like a dictionary.
//
// std::map
//   - Implemented as a balanced binary search tree (usually Red-Black Tree).
//   - Keys are always stored in sorted order.
//   - Operations (insert, find, erase) are O(log n).
//   - Iterating gives keys in sorted order.
//   - Use when you need ordering.
//
// std::unordered_map
//   - Implemented as a hash table.
//   - Keys have no defined order (pseudo-random order).
//   - Average operations (insert, find, erase) are O(1), worst case O(n).
//   - Iterating gives keys in arbitrary order.
//   - Use when you need fast lookups and don’t care about ordering.
//
// Rule of thumb:
//   - Use std::map if you need sorted keys or range-based queries.
//   - Use std::unordered_map if you want maximum speed for lookups.

#include <map>
#include <unordered_map>

struct CityRecord
{
    std::string Name;
    uint64_t Population;
    double Latitude, Longitude;
    
};

int main(){
 
    std::vector<CityRecord> cities;

    cities.emplace_back(CityRecord{"Melbourne", 5000000, 2.4, 9.4});
    cities.emplace_back(CityRecord{"Stockholm", 5000000, 2.4, 9.4});
    cities.emplace_back(CityRecord{"Berlin", 5000000, 2.4, 9.4});
    cities.emplace_back(CityRecord{"Paris", 5000000, 2.4, 9.4});
    cities.emplace_back(CityRecord{"London", 5000000, 2.4, 9.4});

    for(const CityRecord& city : cities){
        if(city.Name == "Berlin"){
            city.Population;
            break;
        }
    }
    // this is bad if we have for example 1000 cities we need to check 1000 times in the loop
    // also string comparisions are expensive

//////////////////////////////////////////////////////////////////////////////////////////////////////

    std::map<std::string, CityRecord> cityMap; //<key, type>
    //std::unordered_map<std::string, CityRecord> cityMap; //used the exact same way, is a even faster way of doing lookup
    cityMap["Melbourne"] = CityRecord { "Melbourne", 5000000, 2.4, 9.4 };
    cityMap["Stockholm"] = CityRecord { "Stockholm", 5000000, 2.4, 9.4 };
    cityMap["Berlin"] = CityRecord { "Berlin", 5000000, 2.4, 9.4 };
    cityMap["Paris"] = CityRecord { "Paris", 5000000, 2.4, 9.4 };
    cityMap["London"] = CityRecord { "London", 5000000, 2.4, 9.4 };
    // instead of indexing with ordered numbers like array [0], [1], [2] etc.
    // we index with a meaningful key ["Melbourne"]

    CityRecord& berlinData = cityMap["Berlin"]; 
    // we did the same thing here but much more easy and EFFICIENT

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAPS IN DETAIL

    //Create a map (keys auto-sorted)
    std::map<int, std::string> ordered;

    // Insert elements
    ordered[3] = "Three"; // insert with []
    ordered.insert({1, "One"}); // insert with pair
    ordered.insert({2, "Two"});

    // Iteration (keys come out in sorted order: 1, 2, 3)
    std::cout << "std::map iteration (sorted): \n";
    for(auto& kv : ordered){ // the type is (std::pair<const int, std::string>)
        std::cout << kv.first << " => " << kv.second << std::endl;
        // first = key, second = value
    }

    // Access: O(log n) (tree lookup)
    std::cout << "Key 2 value; " << ordered[2] << std::endl;

    // Find: returns iterator to element, or end() if not found
    auto it = ordered.find(3);
    if(it != ordered.end()){
        std::cout << "Found key 3 with value: " << it->second << std::endl;
    }

    // Erase by key: removes from the tree
    ordered.erase(1);
    std::cout << "After erase, size = " << ordered.size() << std::endl;

///////////////////////////////////////////////////////////////////////////////////////////////

    // create an unordered_map: key = int, value = string
    std::unordered_map<int, std::string> umap;

    // insert element
    umap[3] = "Three";     // average O(1), hash(3) decides bucket
    umap.insert({1, "One"});
    umap.insert({2, "Two"});

    // Find: O(1) average (hash + bucket search)
    auto it_ = umap.find(3);
    if (it_ != umap.end())
    std::cout << "Found key 3 with value: " << it_->second << std::endl;

    // Erase: O(1) average
    umap.erase(1);
    std::cout << "After erase, size = " << umap.size() << std::endl;

    return 0;
}