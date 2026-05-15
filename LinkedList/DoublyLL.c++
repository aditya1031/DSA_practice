#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node *back;

     Node(int data1, Node *next1, Node *back1)
     {
          data = data1;
          next = next1;
          back = back1;
     }

     Node(int data1)
     {
          data = data1;
          next = nullptr;
          back = nullptr;
     }
};

Node *convertArr2DLL(vector<int> &arr)
{
     Node *head = new Node(arr[0]);
     Node *prev = head;
     for (int i = 1; i < arr.size(); i++)
     {
          Node *temp = new Node(arr[i], nullptr, prev);
          prev->next = temp;
          prev = temp;
     }
     return head;
}

void printDLL(Node *head)
{
     while (head != NULL)
     {
          cout << head->data << " ";
          head = head->next;
     }
     cout << endl;
}

Node *deleteHead(Node *head)
{
     if (head == NULL || head->next == NULL)
     {
          return NULL;
     }
     Node *prev = head;
     head = head->next;
     head->back = nullptr;
     prev->next = nullptr;
     delete prev;

     return head;
}

Node *deleteTail(Node *head)
{
     if (head == NULL || head->next == NULL)
     {
          return NULL;
     }
     Node *tail = head;
     while (tail->next != NULL)
     {
          tail = tail->next;
     }
     Node *newTail = tail->back;
     newTail->next = nullptr;
     tail->back = nullptr;
     delete tail;

     return head;
}

Node *deleteKth(Node *head, int k)
{
     Node *temp = head;
     int cnt = 0;
     while (temp != NULL)
     {
          cnt++;
          if (cnt == k)
          {
               break;
          }
          temp = temp->next;
     }
     Node *prev = temp->back;
     Node *front = temp->next;

     if (prev == NULL && front == NULL)
     {
          delete temp;
          return NULL;
     }
     else if (prev == NULL)
     {
          return deleteHead(head);
     }
     else if (front == NULL)
     {
          return deleteTail(head);
     }
     else
     {
          prev->next = front;
          front->back = prev;

          temp->next = nullptr;
          temp->back = nullptr;
          delete temp;
     }
     return head;
}

void deleteNode(Node *temp)
{
     Node *prev = temp->back;
     Node *front = temp->next;
     if (front == NULL)
     {
          prev->next = nullptr;
          temp->back = nullptr;
          delete temp;
     }
     else
     {
          prev->next = front;
          front->back = prev;
          temp->next = nullptr;
          temp->back = nullptr;
          delete temp;
     }
}

Node *insertNodeBeforeHead(Node *head, int val)
{
     Node *newHead = new Node(val, head, nullptr);
     head->back = newHead;
     return newHead;
}

Node *insertNodeBeforeTail(Node *head, int val)
{
     if (head->next = NULL)
     {
          return insertNodeBeforeHead(head, val);
     }

     Node *tail;
     while (tail->next != NULL)
     {
          tail = tail->next;
     }
     Node *prev = tail->back;
     Node *newNode = new Node(val, tail, prev);

     prev->next = newNode;
     tail->back = newNode;
     return head;
}

Node *insertNodeBeforeKth(Node *head, int val, int k)
{
     int cnt = 0;
     Node *temp = head;
     while (temp != NULL)
     {
          cnt++;
          if (cnt == k)
          {
               break;
          }
          temp = temp->next;
     }

     Node *prev = temp->back;
     Node *newNode = new Node(val, temp, prev);

     prev->next = newNode;
     temp->back = newNode;
     return head;
}

void insertNodeBeforeNode(Node *node, int val)
{
     Node *prev = node->back;
     Node *newNode = new Node(val, node, prev);
     prev->next = newNode;
     node->back = newNode;
}

int main()
{
     vector<int> arr = {1, 2, 3, 4, 5, 6};

     Node *head1 = convertArr2DLL(arr);
     printDLL(head1);

     // head1 = deleteHead(head1);
     // printDLL(head1);

     // head1 = deleteTail(head1);
     // printDLL(head1);

     // head1 = deleteKth(head1, 2);
     // printDLL(head1);

     // deleteNode(head1->next);
     // printDLL(head1);

     // head1 = insertNodeBeforeHead(head1, 100);
     // printDLL(head1);

     // head1 = insertNodeBeforeTail(head1, 100);
     // printDLL(head1);

     head1 = insertNodeBeforeKth(head1, 100, 4);
     printDLL(head1);

     insertNodeBeforeNode(head1->next->next, 100);
     printDLL(head1);

     return 0;
}