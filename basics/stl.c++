#include <bits/stdc++.h>
using namespace std;

void demonstratePair()
{
    /*
        === PAIR ===
        - A pair stores two values of any type (can be different).
        - Syntax: pair<T1, T2> p;
        - Commonly used for key-value storage, coordinates, tree nodes, etc.
    */

    cout << "\n=== PAIR DEMO ===" << endl;

    // Basic pair initialization
    pair<int, int> p = {3, 4}; // pair of two integers
    cout << "p.first: " << p.first << ", p.second: " << p.second << endl;

    // Nested pair: a pair inside a pair
    pair<int, pair<int, int>> p1 = {1, {3, 5}};
    // Accessing nested values
    cout << "Nested pair: " << p1.first << ", " << p1.second.first << ", " << p1.second.second << endl;

    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 4}, {3, 3}};
    cout << "arr[2].second: " << arr[2].second << endl; // Accessing elements like a 2D structure
}

void demonstrateVector()
{
    /*
        === VECTOR ===
        - Dynamic array that grows automatically.
        - Syntax: vector<T> v;
        - Fast random access, slow insertion/deletion in middle.
        - Common Operations:
            push_back(), emplace_back(), insert(), erase(), size(), clear(), empty(), swap(), at(), []
    */

    cout << "\n=== VECTOR DEMO ===" << endl;

    // Constructor: vector of size 5 with all values = 100
    vector<int> v(5, 100); // {100, 100, 100, 100, 100}

    // Copy constructor
    vector<int> v1(5, 34); // {34, 34, 34, 34, 34}
    vector<int> v2(v1);    // Copies v1 into v2

    // Accessing elements
    cout << "v[3]: " << v[3] << endl;       // direct access
    cout << "v.at(0): " << v.at(0) << endl; // bounds-checked access

    // Iteration: Using iterator
    cout << "Iterator traversal:\n";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    // Iteration: Using auto
    cout << "\nAuto iterator:\n";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    // Iteration: Using range-based loop
    cout << "\nRange-based for:\n";
    for (auto val : v)
        cout << val << " ";
    cout << endl;

    // Modifying contents
    v.erase(v.begin() + 1);                // removes 2nd element
    v.erase(v.begin() + 2, v.begin() + 4); // removes elements from index 2 to 3 (exclusive of 4)

    // Insert operations
    vector<int> v3(2, 100);           // {100, 100}
    v3.insert(v3.begin(), 300);       // insert 300 at beginning: {300, 100, 100}
    v3.insert(v3.begin() + 1, 2, 34); // insert two 34s at index 1: {300, 34, 34, 100, 100}

    vector<int> temp(2, 54);                         // temp: {54, 54}
    v3.insert(v3.begin(), temp.begin(), temp.end()); // insert all elements of temp at start

    // Utility functions
    cout << "Size of v3: " << v3.size() << endl; // get size
    v3.pop_back();                               // remove last element
    v1.swap(v2);                                 // swap contents of v1 and v2
    v.clear();                                   // clear all elements from v
    cout << "Is v empty? " << v.empty() << endl; // check if vector is empty (returns bool)
}

void demonstrateList()
{
    /*
        === LIST ===
        - Doubly linked list, fast insertion/deletion from anywhere.
        - Syntax: list<T> ls;
        - No random access like vector (no operator[])
        - Common Operations:
            push_back(), push_front(), emplace_back(), emplace_front(), insert(), erase(), clear(), size(), swap()
    */

    cout << "\n=== LIST DEMO ===" << endl;

    list<int> ls;

    ls.push_back(2);      // add at end: {2}
    ls.emplace_back(54);  // add at end (more efficient): {2, 54}
    ls.push_front(33);    // add at beginning: {33, 2, 54}
    ls.emplace_front(77); // add at beginning: {77, 33, 2, 54}

    cout << "List contents: ";
    for (auto val : ls)
        cout << val << " ";
    cout << endl;
}

void demonstrateDeque()
{
    /*
        === DEQUE ===
        - Double-ended queue: fast insertion/deletion at both front and back.
        - Syntax: deque<T> dq;
        - Supports random access and vector-like operations.
        - Common Operations:
            push_back(), push_front(), pop_back(), pop_front(), at(), [], insert(), erase(), clear(), size(), empty()
    */

    cout << "\n=== DEQUE DEMO ===" << endl;

    deque<int> dq;

    dq.push_back(1);    // {1}
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4);   // {4, 1, 2}

    dq.pop_back();  // removes 2 -> {4, 1}
    dq.pop_front(); // removes 4 -> {1}

    cout << "Deque contents: ";
    for (auto val : dq)
        cout << val << " ";
    cout << endl;
}

void demonstrateStack()
{
    /*
        === STACK ===
        - Stack is a LIFO (Last In First Out) data structure.
        - Syntax: stack<T> s;
        - Elements are inserted and removed only from the **top**.
        - Use Cases:
            - Function call stack
            - Undo operations
            - Expression evaluation
        - Common Operations:
            push(), emplace(), pop(), top(), size(), empty(), swap()
    */

    cout << "\n=== STACK DEMO ===" << endl;

    stack<int> st; // Declare an empty stack of integers

    // Insert elements into stack (top of stack)
    st.push(1);    // stack: {1}
    st.push(2);    // stack: {1, 2}
    st.push(3);    // stack: {1, 2, 3}
    st.push(4);    // stack: {1, 2, 3, 4}
    st.emplace(5); // stack: {1, 2, 3, 4, 5} — faster than push()

    // Access the top element (most recently added)
    cout << "Top of stack: " << st.top() << endl; // Output: 5

    st.pop(); // Removes top element (5), stack becomes: {1, 2, 3, 4}

    cout << "New top after pop: " << st.top() << endl; // Output: 4

    // Get the size of the stack
    cout << "Stack size: " << st.size() << endl; // Output: 4

    // Check if the stack is empty
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    // Swap two stacks
    stack<int> st1, st2;
    st1.push(10);
    st1.push(20);
    st2.push(100);
    st2.push(200);

    cout << "Before swap - Top of st1: " << st1.top() << ", Top of st2: " << st2.top() << endl;

    st1.swap(st2); // Swap contents of st1 and st2

    cout << "After swap - Top of st1: " << st1.top() << ", Top of st2: " << st2.top() << endl;
}

void demonstrateQueue()
{
    /*
        === QUEUE ===
        - A queue is a FIFO (First-In-First-Out) data structure.
        - Elements are inserted at the **back** and removed from the **front**.
        - Syntax: queue<T> q;
        - Use Cases:
            - Job scheduling
            - Request processing
            - Level-order traversal in trees
        - Common Operations:
            push(), emplace(), front(), back(), pop(), size(), empty()
    */

    cout << "\n=== QUEUE DEMO ===" << endl;

    queue<int> q; // Create an empty queue of integers

    // Insert elements at the back of the queue
    q.push(1);    // Queue: {1}
    q.push(2);    // Queue: {1, 2}
    q.push(3);    // Queue: {1, 2, 3}
    q.emplace(4); // Queue: {1, 2, 3, 4} — emplace is slightly faster than push

    // Modify the last (back) element
    q.back() += 5; // back = 4 + 5 = 9 => Queue becomes: {1, 2, 3, 9}

    // Access the last (back) element
    cout << "Back of queue: " << q.back() << endl; // Output: 9

    // Access the first (front) element
    cout << "Front of queue before pop: " << q.front() << endl; // Output: 1

    // Remove the front element
    q.pop(); // Removes 1 → Queue becomes: {2, 3, 9}

    // Access the new front
    cout << "Front of queue aft er pop: " << q.front() << endl; // Output: 2
}

void demonstratePriorityQueue()
{
    /*
        === PRIORITY QUEUE ===
        - A container adapter that provides constant time lookup of the largest (or smallest) element.
        - By default, it's a **Max-Heap**: largest element at top.
        - Syntax: priority_queue<T>
        - Use Cases:
            - Task scheduling by priority
            - Dijkstra's shortest path
            - Real-time leaderboards

        Common Operations:
        - push(x): adds element
        - emplace(x): efficient insertion
        - top(): returns top element
        - pop(): removes top element
        - size(), empty(), swap()
    */

    cout << "\n=== PRIORITY QUEUE DEMO ===" << endl;

    // ---------- MAX-HEAP (default) ----------
    priority_queue<int> pq;

    pq.push(5);    // {5}
    pq.push(3);    // {5, 3}
    pq.push(2);    // {5, 3, 2}
    pq.emplace(1); // {5, 3, 2, 1} (1 is inserted but doesn't go to top)

    cout << "Top of max-heap: " << pq.top() << endl; // Output: 5

    pq.pop(); // removes 5 → top becomes 3

    cout << "New top of max-heap after pop: " << pq.top() << endl; // Output: 3

    // ---------- MIN-HEAP (custom comparator) ----------
    /*
        To make a min-heap:
        Syntax: priority_queue<type, vector<type>, greater<type>>
    */
    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_min.push(5);
    pq_min.push(3);
    pq_min.push(2);
    pq_min.emplace(1); // Min-heap now has 1 at top

    cout << "Top of min-heap: " << pq_min.top() << endl; // Output: 1

    pq_min.pop(); // removes 1 → top becomes 2

    cout << "New top of min-heap after pop: " << pq_min.top() << endl; // Output: 2
}

void demonstrateSet()
{
    /*
        === SET ===
        - A container that stores **unique**, **sorted** elements in ascending order (by default).
        - Implemented as balanced BST (Red-Black Tree).
        - Syntax: set<T> s;
        - All operations like insert, erase, find take O(log n) time.

        Use Cases:
        - Removing duplicates
        - Fast existence checking
        - Maintaining sorted collection

        Key Functions:
        - insert(), emplace(), erase(), find(), count(), lower_bound(), upper_bound(), begin(), end()
    */

    cout << "\n=== SET DEMO ===" << endl;

    set<int> st;

    // Inserting elements
    st.insert(1);  // {1}
    st.emplace(2); // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(5);  // {1, 2, 4, 5}
    st.emplace(1); // Duplicate, ignored → {1, 2, 4, 5}
    st.emplace(3); // {1, 2, 3, 4, 5} ← now sorted

    // Displaying elements
    cout << "Set contents: ";
    for (auto val : st)
        cout << val << " ";
    cout << endl;

    // Finding an element
    auto it = st.find(3); // returns iterator to 3
    if (it != st.end())
        cout << "Found 3 in set.\n";

    auto itNotFound = st.find(6); // returns st.end()
    if (itNotFound == st.end())
        cout << "6 not found in set.\n";

    // Erasing an element by value
    st.erase(5); // removes 5 if exists

    // Count - returns 1 if present, 0 otherwise
    int cnt = st.count(1); // 1 (true)
    cout << "Is 1 in set? " << (cnt ? "Yes" : "No") << endl;

    // Erasing using iterator
    auto it3 = st.find(3);
    if (it3 != st.end())
        st.erase(it3); // removes 3

    // Erasing a range [it1, it2)
    auto it1 = st.find(2); // iterator to 2
    auto it2 = st.find(4); // iterator to 4 (exclusive)
    if (it1 != st.end() && it2 != st.end())
        st.erase(it1, it2); // removes 2 and 3 if they exist (we already removed 3 earlier)

    // lower_bound(): returns iterator to first element ≥ value
    auto itLB = st.lower_bound(2);
    if (itLB != st.end())
        cout << "Lower bound of 2: " << *itLB << endl;
    else
        cout << "Lower bound of 2 not found.\n";

    // upper_bound(): returns iterator to first element > value
    auto itUB = st.upper_bound(3);
    if (itUB != st.end())
        cout << "Upper bound of 3: " << *itUB << endl;
    else
        cout << "Upper bound of 3 not found.\n";

    // Final set contents
    cout << "Final set contents: ";
    for (auto val : st)
        cout << val << " ";
    cout << endl;
}

void demonstrateMultiset()
{
    /*
       === MULTISET ===
        - Similar to `set`, but allows **duplicate** elements.
        - Automatically maintains **sorted order**.
        - Implemented using Red-Black Tree (Balanced BST).
        - Syntax: multiset<T> ms;

        Use Cases:
        - Storing sorted duplicates (e.g., marks, frequencies)
        - Fast counting and searching with duplicates

        Key Functions:
        - insert(), emplace(), count(), find(), erase(), equal_range(), lower_bound(), upper_bound()
    */

    cout << "\n=== MULTISET DEMO ===" << endl;

    multiset<int> ms;

    // Insert elements (with duplicates)
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(1); // ms = {1, 1, 1, 1, 2, 3}

    cout << "Original multiset: ";
    for (int val : ms)
        cout << val << " ";
    cout << endl;

    // 1. Erase all occurrences of 1
    ms.erase(1); // ms = {2, 3}

    cout << "After erasing all 1s: ";
    for (int val : ms)
        cout << val << " ";
    cout << endl;

    // Re-insert duplicates for further demo
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // ms = {1, 1, 1, 2, 3}

    // 2. Count how many 1s are in the multiset
    int cnt = ms.count(1);
    cout << "Number of 1s: " << cnt << endl;

    // 3. Erase only one 1 (first occurrence)
    auto it = ms.find(1);
    if (it != ms.end())
        ms.erase(it); // ms = {1, 1, 2, 3}

    cout << "After erasing one 1: ";
    for (int val : ms)
        cout << val << " ";
    cout << endl;

    // 4. Erase a range of 1s (example: erase 2 more 1s)
    auto start = ms.find(1);
    auto end = start;
    int toErase = 2;

    while (toErase-- && end != ms.end() && *end == 1)
    {
        ++end;
    }

    ms.erase(start, end); // ms = {2, 3}

    cout << "After erasing two more 1s: ";
    for (int val : ms)
        cout << val << " ";
    cout << endl;
}

void demonstrateUSet()
{
    /*
        === UNORDERED_SET ===
        - Stores only UNIQUE values.
        - Does NOT maintain any order (random).
        - Uses HASH TABLE internally.
        - Fast operations: insert, erase, find → average O(1) time.
        - Duplicates are ignored automatically.

        🚫 Note: Functions like lower_bound() and upper_bound() DO NOT work
        because unordered_set is NOT sorted.
    */

    cout << "\n=== UNORDERED SET DEMO ===" << endl;

    unordered_set<int> st;

    // Insert elements (unordered and unique)
    st.insert(10);
    st.insert(20);
    st.insert(10); // Duplicate, ignored
    st.insert(30);
    st.insert(40);

    // Display all elements (order is random)
    cout << "Contents of unordered_set: ";
    for (int val : st)
    {
        cout << val << " ";
    }
    cout << endl;

    // Find an element
    if (st.find(20) != st.end())
    {
        cout << "20 is present in the set.\n";
    }
    else
    {
        cout << "20 is not in the set.\n";
    }

    // Erase an element
    st.erase(30);
    cout << "After erasing 30: ";
    for (int val : st)
    {
        cout << val << " ";
    }
    cout << endl;

    // Size of the set
    cout << "Size of unordered_set: " << st.size() << endl;

    // Check if set is empty
    cout << "Is set empty? " << (st.empty() ? "Yes" : "No") << endl;

    /*
        🚫 Why lower_bound() and upper_bound() DON'T work:
        - These functions are available only in containers that keep elements in order (like set, map, multiset).
        - unordered_set is NOT sorted. It's stored in random hash buckets.
        - So there's no concept of "next greater" or "next equal or greater" element.

        Example (INVALID):
        // st.lower_bound(25);  ❌ Compile error
        // st.upper_bound(25);  ❌ Compile error
    */
}

void demonstrateMap()
{
    /*
        === MAP ===
        - Stores key-value pairs in sorted order by key.
        - Keys are unique.
        - Uses Red-Black Tree (balanced BST).
        - Time complexity: O(log N) for insert, erase, find, etc.
    */

    cout << "\n=== MAP DEMO ===" << endl;

    map<int, int> mpp;

    // Insert using assignment
    mpp[1] = 2; // {1 → 2}
    mpp[2] = 4; // {2 → 4}

    // Insert using emplace
    mpp.emplace(3, 5); // {3 → 5}

    // Insert using insert()
    mpp.insert({4, 6}); // {4 → 6}

    // Access elements
    cout << "mpp[1] = " << mpp[1] << endl;
    cout << "mpp[5] = " << mpp[5] << endl; // Will insert 5 → 0 if not present

    // Iterate through map
    cout << "All key-value pairs:\n";
    int it;
    for (auto it : mpp)
    {
        cout << "Key: " << it.first << " | Value: " << it.second << endl;
    }

    // Find key 3
    auto it = mpp.find(3); // returns iterator to pair {3, 5}
    if (it != mpp.end())
    {
        cout << "Found key 3 with value = " << it->second << endl;
    }

    // Lower and upper bound
    auto lb = mpp.lower_bound(2); // key ≥ 2
    auto ub = mpp.upper_bound(3); // key > 3

    cout << "Lower bound of 2 = Key: " << lb->first << ", Value: " << lb->second << endl;
    cout << "Upper bound of 3 = Key: " << ub->first << ", Value: " << ub->second << endl;

    // Example: map with pair as key
    map<pair<int, int>, int> pairMap;
    pairMap[{2, 3}] = 10;
    cout << "Value at key {2,3} = " << pairMap[{2, 3}] << endl;

    // Example: map with pair as value
    map<int, pair<int, int>> valueMap;
    valueMap[1] = {5, 6};
    cout << "Value at key 1 = {" << valueMap[1].first << ", " << valueMap[1].second << "}" << endl;
}

void explainMultimap()
{
    /*
        === MULTIMAP ===
        - Allows duplicate keys.
        - Each key can have multiple values.
        - Stores in sorted order (like map).
        - No [] operator, use insert() only.
        - Time complexity: O(log N)
    */

    cout << "\n=== MULTIMAP DEMO ===" << endl;

    multimap<int, string> mm;
    mm.insert({1, "apple"});
    mm.insert({1, "banana"});
    mm.insert({2, "orange"});

    // Prints all key-value pairs (including duplicates)
    for (auto it : mm)
    {
        cout << "Key: " << it.first << " | Value: " << it.second << endl;
    }

    // Find all values with key = 1
    auto range = mm.equal_range(1);
    cout << "All values with key 1: ";
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second << " ";
    }
    cout << endl;
}

void explainUnorderedMap()
{
    /*
        === UNORDERED_MAP ===
        - Stores key-value pairs in random order.
        - Uses hash table internally.
        - Much faster than map for average cases.
        - Time complexity: O(1) avg, O(N) worst case
        - Keys must be hashable (no custom struct by default)
    */

    cout << "\n=== UNORDERED MAP DEMO ===" << endl;

    unordered_map<string, int> ump;
    ump["apple"] = 3;
    ump["banana"] = 5;
    ump["apple"]++; // apple: 4

    for (auto it : ump)
    {
        cout << "Fruit: " << it.first << " | Count: " << it.second << endl;
    }

    // Find key
    if (ump.find("banana") != ump.end())
    {
        cout << "Banana exists with count: " << ump["banana"] << endl;
    }

    // Note: No lower_bound or upper_bound here — no order!
}

// Comparator function to sort pairs by second value, break ties with first
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    if (a.second == b.second)
        return a.first < b.first;
    return false;
}

void explainExtra()
{
    /*
        === SORT FUNCTION & CUSTOM COMPARATORS ===

        sort(arr, arr + n): sorts array from index 0 to n-1 (ascending)
        sort(v.begin(), v.end()): sorts vector in ascending
        sort(start, end, greater<int>()): sorts in descending

        You can also use custom comparators with sort() for pairs or structs.
    */

    cout << "\n=== SORT EXAMPLES ===" << endl;

    // Sorting array
    int arr[] = {5, 1, 3, 4, 2};
    int n = 5;

    // Sort full array in ascending
    sort(arr, arr + n);
    cout << "Sorted array (asc): ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort subarray [index 2 to 3]
    sort(arr + 2, arr + 4);
    cout << "Partial sort [2–3]: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort full array in descending
    sort(arr, arr + n, greater<int>());
    cout << "Sorted array (desc): ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sorting vector
    vector<int> v = {4, 2, 5, 1, 3};
    sort(v.begin(), v.end());
    cout << "Sorted vector: ";
    for (int val : v)
        cout << val << " ";
    cout << endl;

    // Sorting array of pairs
    pair<int, int> pArr[] = {{1, 2}, {4, 3}, {4, 1}, {2, 3}};

    /*
        Custom sort:
        - Sort by second value in ascending order.
        - If second is same, sort by first in ascending.
    */
    sort(pArr, pArr + 4, comp);

    cout << "Sorted pairs (by 2nd, then 1st): ";
    for (int i = 0; i < 4; ++i)
    {
        cout << "{" << pArr[i].first << "," << pArr[i].second << "} ";
    }
    cout << endl;

    /*
           === BUILT-IN FUNCTIONS & PERMUTATIONS ===
           - __builtin_popcount(n): counts number of 1s in binary of an integer (only for int)
           - __builtin_popcountll(n): same for long long
           - sort(begin, end): sorts a string or container
           - next_permutation(): generates next lexicographical permutation
           - max_element(): returns pointer to max element in range
       */

    cout << "\n=== Built-in Functions Demo ===" << endl;

    int num = 7; // Binary: 111 → 3 set bits
    int cnt = __builtin_popcount(num);
    cout << "Number of set bits in " << num << " = " << cnt << endl;

    long long num1 = 9839775748;
    int cnt1 = __builtin_popcountll(num1);
    cout << "Number of set bits in " << num1 << " = " << cnt1 << endl;

    // Sorting and generating permutations
    string s = "1234";
    sort(s.begin(), s.end()); // First sort to get lexicographically smallest

    cout << "\nAll permutations of '1234':" << endl;
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // Max element in array
    int a[] = {5, 2, 9, 1, 7};
    int n = sizeof(a) / sizeof(a[0]);

    int maxi = *max_element(a, a + n);
    cout << "\nMaximum element in array = " << maxi << endl;
}

// ===================== MAIN FUNCTION =====================
int main()
{
    demonstratePair();
    demonstrateVector();
    demonstrateList();
    demonstrateDeque();
    demonstrateStack();
    demonstrateDeque();
    demonstratePriorityQueue();
    demonstrateMap();
    explainMultimap();
    explainUnorderedMap();

    return 0;
}
