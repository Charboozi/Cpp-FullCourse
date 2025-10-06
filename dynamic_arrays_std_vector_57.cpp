#include <iostream>
#include <vector> 
#include <algorithm> // for std::sort, std::find, etc.

// std::vector is a dynamic array in C++ that automatically manages its size and memory.
// Unlike raw arrays, vectors can grow or shrink as needed (using push_back, resize, etc.).
// They provide bounds-safe access with .at(), support iteration like arrays, 
// and free you from manually allocating or deleting memory.
// Example: std::vector<int> numbers; numbers.push_back(10);

struct Vertex{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& v){
    stream << "Vertex(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
} 

int main(){

    // problem: we are stuck with a fixed size array
    //Vertex* vertices[5] = new Vertex[5]; 
    //vertices[4];

    // solution: use vector
    std::vector<Vertex> vertices;
    // why we should use Vertex objects instead of pointers to Vertex objects
    // 1. better cache locality (faster access to data). Objects are stored contiguously in memory. Pointers can point to scattered memory locations.

    vertices.push_back({1.0f, 2.0f, 3.0f});// add a Vertex to the end of the vector(array)
    vertices.push_back({4.0f, 5.0f, 6.0f});

    for(int i = 0; i < vertices.size(); i++){
        std::cout << vertices[i] << '\n';
    }
    // vertices.size() returns the number of elements in the vector
    
    for(Vertex& v : vertices){// use reference to avoid copying the object
        std::cout << v << "\n";
    }

    vertices.clear(); // remove all elements from the vector

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // decleration & initialization
    std::vector<int> v1; // empty vector
    std::vector<int> v2(5); // 5 elements, all 0
    std::vector<int> v3(5, 10); // 5 elements, all 10
    std::vector<int> v4 = {1, 2, 3, 4, 5}; // initializer list
    std::vector<int> v5(v4); // copy constructor
    std::vector<int> v6(std::move(v4)); // move constructor (v4 is now empty)

    // adding elements
    v1.push_back(10); // add elements to end
    v1.push_back(20);
    v1.emplace_back(30); // like push_back but constructs in place (faster)

    v1.insert(v1.begin(), 5); // insert 5 at start
    v1.insert(v1.begin() + 2, 15); // insert at index 2
    v1.insert(v1.end(), {40, 50, 60}); // insert multiple

    // accessing elements
    std::cout << v1[0] << "\n"; // direct access (no bound check)
    std::cout << v1.at(2) << "\n"; // safe access (throw std::out_of_range)
    std::cout << v1.front() << "\n"; // first element
    std::cout << v1.back() << "\n"; // last element

    // iteration

    // range-based for loop
    for (int x : v1) 
        std::cout << x << " ";
    std::cout << "\n";

    // using iterator
    for(auto it = v1.begin(); it != v1.end(); ++it) // use ++it for std::vector<int>::iterator, its faster
        std::cout << *it << " ";
    std::cout << "\n";    

    // reverse iterator
    for(auto it = v1.rbegin(); it != v1.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // removing elements
    v1.pop_back(); // remove last element
    v1.erase(v1.begin() + 1); // remove element at index 1
    v1.erase(v1.begin(), v1.begin() + 2); // remove a range 0 to 2
    v1.clear(); // remove all elements

    // size and capacity
    std::vector<int> v = {1, 2, 3};
    std::cout << "Size: " << v.size() << "\n"; // number of elements
    std::cout << "Capacity: " << v.capacity() << "\n"; // allocated memory size

    v.push_back(4); // if capacity is not enough, vector reallocates (slow operation)
    v.reserve(100); // pre-allocate memory for 100 elements to avoid reallocations
    v.shrink_to_fit(); // reduce capacity to match size (optional)
    
    // copying & moving
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = a; // copy assignment (deep copy)
    std::vector<int> c = std::move(a); // move assignment (a is now empty)

    // sorting & searching
    std::vector<int> nums = {4, 1, 3, 2};
    std::sort(nums.begin(), nums.end()); // 1 2 3 4
    
    // find element
    auto it = std::find(nums.begin(), nums.end(), 3); // iterators: [begin] [ +1 ] [ +2 ] [ end ]
    if(it != nums.end())
        std::cout << "Found at index " << (it - nums.begin()) << "\n";

    // resizing
    nums.resize(10); // if 10 is larger than vector size, new elements are default-initialized (0)
    nums.resize(2); // if smaller, truncates

    // memory behaviour

    // vector stores elements contigously:
    int* ptr = nums.data();
    std::cout << ptr[0] << " " << ptr[1] << "\n";

    // custom types
    struct Point{
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
    };

    std::vector<Point> points;
    points.emplace_back(1, 2); // constructs in place (no copy)
    points.push_back(Point(3, 4)); // constructs temporary then copies/moves it

    //access custom objects
    for (const auto& p : points)
        std::cout << "(" << p.x << "," << p.y << ")\n";
    
    // capacity vs size demo
    std::vector<int> demo;
    for (int i = 0; i < 10; ++i)
    {
        demo.push_back(i);
        std::cout << "Size: " << demo.size() << "Capacity: " << demo.capacity();
    }
    std::cout << "\n";

    // You'll see capacity grows geometrically (like 1,2,4,8,16,...)
    // This is why push_back can sometimes cause reallocation (slow).
    // Use reserve() if you know how many elements you'll need.

    // common pitfalls

    // INVALID: erasing while iterating ( use erase with returned iterator):
    /*
    for (auto it = demo.begin(); it != demo.end(); ++it)
        if (*it % 2 == 0)
            demo.erase(it); // invalidates iterator -> crash
    */

    // corrected version
    for (auto it = demo.begin(); it != demo.end();)
        if(*it % 2 == 0)
            it = demo.erase(it);
        else
            ++it;
    
    // multidimensional vectors

    std::vector <std::vector<int>> matrix(3, std::vector<int>(3, 0)); // 3x3 zero matrix
    matrix[0][1] = 5;
    matrix[2].push_back(7); // rows can have different sizes (jagged array)

    for (const auto& row : matrix){
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }

    return 0;
}

    // -------------------------------------------------------------------------
    // 🔹 SUMMARY
    // -------------------------------------------------------------------------

    /*
        ✅ Key vector properties:
        - Stores elements contiguously in dynamic memory.
        - Fast random access (like arrays).
        - Automatically grows (capacity doubles roughly each time).
        - Slow for inserting/removing in the middle (O(n)).
        - Supports copy and move semantics.
        - Iterators, range-based loops, algorithms all supported.

        ⚙️ Common functions:
        push_back(), emplace_back(), pop_back(), insert(), erase(), clear()
        size(), capacity(), empty(), reserve(), resize(), shrink_to_fit()
        front(), back(), data(), at(), operator[]

        🧠 Best practice:
        - Use reserve() if you know how many elements you'll insert.
        - Avoid holding raw pointers or iterators across push_back().
        - Prefer emplace_back() for custom types.
    */