//aditya kumar
//21bcs9520

#include <iostream>

struct Node {
    int data;
    Node* next;
};
bool isCircular (Node* head){
    if(head== nullptr)
    return false;

Node* slow=head;
Node* fast=head;
while (fast!= nullptr && fast !=nullptr){
slow=slow->next;
fast->next->next;
if (slow==fast)
{
 return true;   /* code */
}
return false;
}

int main(){
    Node* head = new Node {1,nullptr};
    head->nextnew Noode{2,nullptr};
    head -> nest->next =new Node{3,nullptr};
}

