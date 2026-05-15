#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
     Node *prev;
     int data;
     Node *next;

public:
     Node(Node *prev1, int data1, Node *next1)
     {
          prev = prev1;
          data = data1;
          next = next1;
     }
     Node(int data1)
     {
          prev = nullptr;
          data = data1;
          next = nullptr;
     }
};

Node *convertDLL(vector<int> arr)
{
     Node *head = new Node(arr[0]);
     Node *prev = head;
     for (int i = 1; i < arr.size(); i++)
     {
          Node *temp = new Node(prev, arr[i], nullptr);
          prev->next = temp;
          prev = temp;
     }
     return head;
}

void printDLL(Node *head)
{

     while (head != NULL)
     {
          cout << "  " << head->data;
          head = head->next;
     }
     cout << endl;
}



// tc=O(2n)
// sc=O(n)
Node *reverseDLLBrute(Node *head)
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


//TC=O(n)
//SC=O(1)
Node *reverseDLLOptimal(Node *head)
{
     if (head == NULL || head->next == NULL)
     {
          return head;
     }
     Node *prev = NULL;
     Node *curr = head;
     while (curr != NULL)
     {
          prev = curr->prev;
          curr->prev = curr->next;
          curr->next = prev;
          curr = curr->prev;
     }
     head = prev->prev;
     return head;
}

int main()
{

     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

     Node *head1 = convertDLL(arr);
     printDLL(head1);

     head1 = reverseDLLBrute(head1);
     printDLL(head1);

     head1 = reverseDLLOptimal(head1);
     printDLL(head1);

     return 0;
}