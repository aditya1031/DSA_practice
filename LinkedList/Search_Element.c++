// git - aditya1031

#include <bits/stdc++.h>
using namespace std;

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

Node *convertArr2LL(vector<int> &arr)
{
     Node *head = new Node(arr[0]);
     Node *mover = head;
     for (int i = 1; i < arr.size(); i++)
     {
          Node *temp = new Node(arr[i]);
          mover->next = temp;
          mover = temp;
     }
     return head;
}

int checkIfPresent(Node *head, int val)
{
     Node *temp = head;
     while (temp)
     {
          if (temp->data == val)
          {
               return 1;
          }
          temp = temp->next;
     }
     return 0;
}

int main()
{

     vector<int> arr = {6, 5, 3, 7, 4};

     Node *head = convertArr2LL(arr);
     int ans = checkIfPresent(head, 15);
     if (ans)
     {
          cout << "YES";
     }
     else
     {
          cout << "NO";
     }
     return 0;
}