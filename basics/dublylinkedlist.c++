// aditya kumar
// 21bcs9520

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;


void insert_beginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    cout << "\nNode has been inserted at the beginning";
}


void insert_end(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "\nNode has been inserted at the end";
}

void delete_beginning() {
    if (head == nullptr) {
        cout << "\nList is empty!";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    cout << "\nNode has been deleted from the beginning";
}

void delete_end() {
    if (head == nullptr) {
        cout << "\nList is empty!";
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    cout << "\nNode has been deleted from the end";
}


void display() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "Nothing to print";
    } else {
        cout << "\nPrinting values: [ ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]";
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete from the beginning\n";
        cout << "4. Delete from the end\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert_beginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insert_end(value);
                break;

            case 3:
                delete_beginning();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                cout << "\nInvalid choice!";
        }
    }

    return 0;
}
