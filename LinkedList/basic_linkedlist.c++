#include <bits/stdc++.h>

using namespace std;

// struct Node // legacy
// {
// public:
//      int data;
//      Node *next;

// public:
//      Node(int data1, Node *next1)
//      {
//           data = data1;
//           next = next1;
//      }

// public:
//      Node(int data1)
//      {
//           data = data1;
//           next = nullptr;
//      }
// };

class Node
{
public:
     int data;
     Node *next;

     Node(int data1, Node *next1)
     {
          data = data1;
          next = next1;
     }

     Node(int data1)
     {
          data = data1;
          next = nullptr;
     }
};

int main()
{
     vector<int> arr = {2, 3, 5, 6};
     Node *y = new Node(arr[3]);
     cout << y->data;
     return 0;
}