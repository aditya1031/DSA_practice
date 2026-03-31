#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
Two strings are isomorphic if characters in s can be replaced to get t.
Each character must map to exactly one character (one-to-one mapping).
So we use two hash maps:
1. s -> t mapping
2. t -> s mapping
This ensures bijection (no two characters map to same character).
*/

/*
APPROACH:
1. If lengths are not equal → return false.
2. Create two hash maps:
      mapST → mapping from s to t
      mapTS → mapping from t to s
3. Traverse both strings together.
4. Check:
      If mapping already exists and does not match → return false.
5. Store mapping in both maps.
6. If loop finishes → return true.
*/

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
(At most 256 characters in map)
*/

bool isIsomorphic(string s, string t)
{
    int n = s.size();

    // Step 1: Length check
    if (n != t.size())
    {
        return false;
    }

    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    // Step 2: Traverse both strings
    for (int i = 0; i < n; i++)
    {
        char c1 = s[i];
        char c2 = t[i];

        // Step 3: Check s -> t mapping
        if (mapST.count(c1) && mapST[c1] != c2)
        {
            return false;
        }

        // Step 4: Check t -> s mapping
        if (mapTS.count(c2) && mapTS[c2] != c1)
        {
            return false;
        }

        // Step 5: Store mapping
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }

    return true;
}

int main()
{
    cout << isIsomorphic("egg", "add");  // true
    return 0;
}