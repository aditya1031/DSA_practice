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

void traverseLL(Node *head)
{
     Node *temp = head;
     while (temp)
     {
          cout << temp->data;
          temp = temp->next;
     }
}

Node *deleteKth(Node *head, int k)
{
     if (head == NULL)
          return head;

     if (k == 1)
     {
          Node *temp = head;
          head = head->next;
          delete temp;
          return head;
     }
     int cnt = 0;
     Node *prev = NULL;
     Node *temp = head;
     while (temp != NULL)
     {
          cnt++;
          if (cnt == k)
          {
               prev->next = prev->next->next;
               delete temp;
               break;
          }
          prev = temp;
          temp = temp->next;
     }

     return head;
}

int main()
{
     vector<int> arr = {6, 5, 3, 7, 4};

     Node *head1 = convertArr2LL(arr);
     traverseLL(head1);
     int k = 2;
     cout << " \nafter Kth delete: \n";
     head1=deleteKth(head1,k);
     traverseLL(head1);

     return 0;
}