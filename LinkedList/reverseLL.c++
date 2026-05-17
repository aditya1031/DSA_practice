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
Node *reverseLLBrute(Node *head) // Using STACK
{
     Node *temp = head;
     stack<int> st;
     while (temp != NULL)
     {
          st.push(temp->data);
          temp = temp->next;
     }
     temp = head;
     while (temp != NULL)
     {
          temp->data = st.top();
          st.pop();
          temp = temp->next;
     }
     return head;
}

// TC=O(n)
// SC=O(1)
Node *reverseLLOptimal(Node *head) //
{
     Node *temp = head;

     Node *front = head;
     Node *prev = NULL;

     while (temp != NULL)
     {
          front = temp->next;
          temp->next = prev;
          prev = temp;
          temp = front;
     }
     return prev;
}

// TC=O(n)
// SC=O(n)
Node *reverseLLRecursion(Node *head)
{
    
     if (head == NULL || head->next == NULL)
     {
          return head;
     }
     Node *newHead = reverseLLRecursion(head->next);

     Node *front = head->next;
     front->next = head;
     head->next = NULL;

     return newHead;
}

int main()
{

     vector<int> arr = {6, 5, 3, 7, 4};

     Node *head = convertArr2LL(arr);
     printLL(head);
     cout << endl;
     head = reverseLLRecursion(head);
     printLL(head);
     return 0;
}