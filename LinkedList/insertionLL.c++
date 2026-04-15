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
          cout << temp->data << " : ";
          temp = temp->next;
     }
}

Node *insertHead(Node *head, int val)
{
     Node *temp = new Node(val, head);
     return temp;
}

Node *insertLast(Node *head, int val)
{
     if (head == NULL)
     {
          return new Node(val);
     }
     Node *temp = head;
     while (temp->next != NULL)
     {
          temp = temp->next;
     }
     Node *newNode = new Node(val);
     temp->next = newNode;
     return head;
}

Node *insertKthPos(Node *head, int val, int k)
{
     if (head == NULL)
     {
          if (k == 1)
          {
               Node *temp = new Node(val);
               return temp;
          }
          else
               return head;
     }
     if (k == 1)
     {
          // Node *temp = new Node(val);
          // temp->next = head;
          // return temp;

          return new Node(val, head);
     }
     Node *temp = head;
     int cnt = 0;
     while (temp != NULL)
     {
          cnt++;
          if (cnt == (k - 1))
          {
               Node *newNode = new Node(val, temp->next);
               // newNode->next = temp->next;
               temp->next = newNode;
               break;
          }
          temp = temp->next;
     }
     return head;
}

Node *insertBeforeValue(Node *head, int el, int val)
{
     if (head == NULL)
     {
          return NULL;
     }
     if (head->data == val)
     {
          return new Node(el, head);
     }
     Node *temp = head;

     while (temp->next != NULL)
     {
          if (temp->next->data == val)
          {
               Node *newNode = new Node(el, temp->next);
               // newNode->next = temp->next;
               temp->next = newNode;
               break;
          }
          temp = temp->next;
     }
     return head;
}

int main()
{
     vector<int> arr = {1, 2, 3, 4, 5, 6};

     Node *head1 = convertArr2LL(arr);
     traverseLL(head1);

     int val = 22;
     cout << endl;
     head1 = insertHead(head1, val);
     traverseLL(head1);

     val = 55;
     cout << endl;
     head1 = insertLast(head1, val);
     traverseLL(head1);

     val = 888;
     cout << endl;
     head1 = insertKthPos(head1, val, 5);
     traverseLL(head1);

     val = 2;
     cout << endl;
     head1 = insertBeforeValue(head1, 1001, val);
     traverseLL(head1);

     return 0;
}