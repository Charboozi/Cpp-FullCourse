// ======================================================================================
// std::set in C++
// --------------------------------------------------------------------------------------
// - Stores unique keys (no duplicates).
// - Keys are automatically kept in sorted order (by default, ascending).
// - Implemented as a balanced binary search tree (usually Red-Black Tree).
// - Main operations: insert, find, erase, lower_bound, upper_bound.
// - Complexity: O(log n) for insert/find/erase.
// - Useful when you need uniqueness + ordering + range queries.
//
// Alternatives:
//   * std::unordered_set → hash table, faster O(1) average but no ordering.
//   * std::multiset      → allows duplicates, still sorted.
// ======================================================================================


#include <iostream>
#include <set>


int main(){

    // create a set of ints
    std::set<int> numbers;

    // insert elements (duplicates ignored)
    numbers.insert(10);
    numbers.insert(5);
    numbers.insert(20);
    numbers.insert(10); // ignored (already exists)

    // iteration (element always sorted: 5, 10, 20)
    std::cout << "Set contents: ";
    for(int n : numbers){
        std::cout << n << " ";
    }
    std::cout << "\n";

    // Find elements
    auto it = numbers.find(10); // returns iterator if found, end if not
    if(it != numbers.end()){
        std::cout << "Found: " << *it << "\n";
    }

    // Erase elements
    numbers.erase(5); // removes the element with key = 5
    std::cout << "After erase: ";
        for(int n : numbers){
        std::cout << n << " ";
    }
    std::cout << "\n";

    // check existence
    if(numbers.count(20)){ // count = 1 if found, 0 if not
        std::cout << "20 exists in the set\n";
    }

    // lower/upper bound (powerful feature of sets!)
    std::set<int> s = {1, 3, 5, 7, 9};

    auto lb = s.lower_bound(4); // first element that is >= 4
    if(lb != s.end()){
        std::cout << "Lower bound of 4 is: " << *lb << "\n"; // prints 5
    }

    auto ub = s.upper_bound(5); // first element > 5
    if (ub != s.end())
        std::cout << "Upper bound of 5 is: " << *ub << "\n"; // prints 7

    // set of strings
    std::set<std::string> names;
    names.insert("Zoe");
    names.insert("Alice");
    names.insert("John");

    std::cout << "Names in sorted order: ";
    for(const std::string& name : names){
        std::cout << name << " ";
    }
    std::cout << '\n';

    // custom comparator (descending order) (ascending is default)
    std::set<int, std::greater<int>> descSet;
    descSet.insert(1);
    descSet.insert(2);
    descSet.insert(3);

    std::cout << "Descending order set: ";
    for(int n : descSet){
        std::cout << n << " ";
    }
    std::cout << "\n";

    // multiset (like set but allows duplicates)
    std::multiset<int> mset;
    mset.insert(5);
    mset.insert(5);
    mset.insert(10);

    std::cout << "Multiset contents: ";
    for (int n : mset) std::cout << n << " "; // prints 5 5 10
    std::cout << "\n";

    return 0;
}