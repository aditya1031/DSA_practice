#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
We need to sort characters based on frequency (highest first).
So:
1. Count frequency using hashmap.
2. Store (char, frequency) in vector.
3. Sort vector by frequency in descending order.
4. Build result string by repeating characters freq times.

Algorithm:
1. Create unordered_map to count frequency.
2. Traverse string and store frequency.
3. Copy map data into vector<pair<char,int>>.
4. Sort vector using lambda comparator (descending frequency).
5. Build result string using string(freq, char).
6. Return result string.

Time Complexity (TC):
- Counting frequency: O(n)
- Sorting: O(k log k)  (k = unique characters)
- Building string: O(n)
Total TC = O(n log n)

Space Complexity (SC):
- Hashmap: O(k)
- Vector: O(k)
- Result string: O(n)
Total SC = O(n)
*/

string frequencySort(string s)
{
     int n = s.size();

     // Step 1: Count frequency
     unordered_map<char, int> freq;
     for (char ch : s)
     {
          freq[ch]++;
     }

     // Step 2: Store into vector for sorting
     vector<pair<char, int>> sortedFreq(freq.begin(), freq.end());

     // Step 3: Sort by frequency (descending)
     sort(sortedFreq.begin(), sortedFreq.end(),
          [](pair<char, int> a, pair<char, int> b)
          {
               return a.second > b.second;
          });

     // Step 4: Build result string
     string ans = "";
     for (auto ch : sortedFreq)
     {
          ans += string(ch.second, ch.first);
     }

     return ans;
}

/*Intuition

Instead of:
    - Storing characters in vector of pairs
    - Sorting the vector
We directly sort the string based on frequency using a custom comparator.

So we:
    - Count frequency of each character.
    - Sort the string using comparator based on frequency.
    - If two characters have same frequency → sort lexicographically.

Algorithm
    - Create frequency array of size 128 (ASCII).
    - Count frequency of each character.
    - Sort the string using custom comparator:
    - Higher frequency first.
    - If frequency same → sort by character.
    - Return sorted string.

     Time: O(n log n)
     Space: O(1)   
     
    */
string frequencySort(string s)
{
     int n = s.size();

     // Step 1: Frequency array (ASCII characters)
     vector<int> freq(128, 0);
     for (auto c : s)
     {
          freq[c]++;
     }
     // Step 2: Custom comparator for sorting
     auto cmp = [&](char a, char b)
     {
          // If same frequency → sort lexicographically
          if (freq[a] == freq[b])
               return a > b;
          // Otherwise higher frequency first
          return freq[a] > freq[b];
     };
     // Step 3: Sort the string
     sort(s.begin(), s.end(), cmp);

     return s;
}

int main()
{
     string s = "tree";
     cout << frequencySort(s);
     return 0;
}