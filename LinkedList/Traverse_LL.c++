#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
     int data;
     Node *next;

     Node(int data1)
     {
          data = data1;
          next = nullptr;
     }
};

Node *convert(vector<int> &arr)
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

int lengthLL(Node *head)
{
     int cnt=0;
     Node *temp = head;
     while (temp)
     {
          temp = temp->next;
          cnt++;
     }
     return cnt;
}

int main()
{
     vector<int> arr = {8, 4, 3, 6, 8};
     Node *head = convert(arr);
     Node *temp = head;
     while (temp)
     {
          cout << temp->data << " : ";
          temp = temp->next;
     }

     cout<<"\nsize of Linked List is: "<<lengthLL(head);

     return 0;
}