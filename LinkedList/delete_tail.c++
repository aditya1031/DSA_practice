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

Node *deleteTail(Node *head)
{
     if (head == NULL || head->next == NULL)
          return NULL;

     Node *temp = head;
     while (temp->next->next != NULL)
     {
          temp = temp->next;
     }
     free(temp->next);//delete temp->next;
     temp->next = NULL;
     return head;
}

int main()
{
     vector<int> arr = {6, 5, 3, 7, 4};

     Node *head1 = convertArr2LL(arr);
     traverseLL(head1);
     cout << " \nafter tail delete: \n";
     Node *head2 = deleteTail(head1);
     traverseLL(head2);
     cout << " \nafter tail delete: \n";
     Node *head3 = deleteTail(head2);
     traverseLL(head2);

     return 0;
}