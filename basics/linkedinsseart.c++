// aditya kumar
// 21bcs9520

#include <iostream>
using namespace std;
int main()
{
    int ch = 0;
    struct node
    {
        int data = 0;
        struct node *next;
    };
    struct node *head = NULL;

    while (ch != 4)
    {
        cout << "\n choose 1 for inseart at begining \n 2 for in the end \n 3 for display\n 4 for exit\n ";
        cin >> ch;
        if (ch == 1)
        {
            struct node *ptr;
            int item;
            ptr = (struct node *)malloc(sizeof(struct node));

            if (ptr == NULL)
            {
                cout << "\nOVERFLOW";
            }
            else
            {
                cout << "\nEnter the value\n";
                cin >> item;
                ptr->data = item;
                ptr->next = head;
                head = ptr;
                cout << "\nNode has been inserted";
            }
        }

        else if (ch == 2)
        {
            struct node *ptr, *temp;
            int item;
            ptr = (struct node *)malloc(sizeof(struct node));

            if (ptr == NULL)
            {
                cout << "\nOVERFLOW";
            }
            else
            {
                cout << "\nEnter the value\n";
                cin >> item;
                ptr->data = item;
                if (head == NULL)
                {
                    ptr->next = NULL;
                    head = ptr;
                    cout << "\nNode has been  inserted";
                }
                else
                {
                    temp = head;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = ptr;
                    ptr->next = NULL;
                    cout << "\nNode inserted";
                }
            }
        }

        else
        {
            struct node *ptr;
            ptr = head;
            if (ptr == NULL)
            {
                cout << "Nothing to print";
            }
            else
            {
                cout << "\nprinting values . . . . .\n";
                cout << "[ ";
                while (ptr != NULL)
                {
                    cout << "  " << ptr->data<<" ";
                    ptr = ptr->next;
                }
                cout << " ]";
            }
        }
    }
    return 0;
}