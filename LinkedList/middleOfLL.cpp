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

void printLL(Node *head)
{
     while (head != NULL)
     {
          cout << " " << head->data;
          head = head->next;
     }
}
// TC=O(2n)
// SC=O(n)
Node *middleNodeBrute(Node *head)
{
     int length = 0;
     Node *temp = head;
     while (temp != NULL)
     {
          temp = temp->next;
          length++;
     }

     for (int i = 0; i < (length / 2); i++)
     {
          head = head->next;
     }

     return head;
}

// TC=O(n/2)
// SC=O(1)
Node *middleNode(Node *head)  //[TortoiseHare Method]
{

     Node *slow = head;
     Node *fast = head;

     while (fast != NULL && fast->next != NULL)
     {
          slow = slow->next;
          fast = fast->next->next;
     }

     return slow;
}

int main()
{

     vector<int> arr = {6, 5, 3, 7, 4};

     Node *head = convertArr2LL(arr);
     head = middleNode(head);
     printLL(head);
     return 0;
}