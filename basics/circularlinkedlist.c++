// aditya kumar
// 21bcs9520

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insert_beginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    cout << "\nNode has been inserted at the beginning";
}

// Insert at the end
void insert_end(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
    cout << "\nNode has been inserted at the end";
}

// Delete from the beginning
void delete_beginning() {
    if (head == nullptr) {
        cout << "\nList is empty!";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }
    cout << "\nNode has been deleted from the beginning";
}

// Delete from the end
void delete_end() {
    if (head == nullptr) {
        cout << "\nList is empty!";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
    cout << "\nNode has been deleted from the end";
}

// Display the list
void display() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "Nothing to print";
    } else {
        cout << "\nPrinting values: [ ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
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
