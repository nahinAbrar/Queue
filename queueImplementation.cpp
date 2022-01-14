//Queue, Linked List Implementation
// ID - 190204065
// 22/08/2021

#include <iostream>
using namespace std;

struct queue{
    int data;
    struct queue* next;
}*first=NULL, *last = NULL;


void enqueue(int data) {
    struct queue *newQueue;
    newQueue = new queue();
    newQueue->data = data;
    newQueue->next = NULL;

    if (first == NULL)
        first = last = newQueue;
    else {
        last->next = newQueue;
        last = newQueue;
    }

    cout << "Enqueue Done." << endl;
}

void dequeue(){
    if(first == NULL)
        cout << "Queue Is Empty";
    else
    {
        struct queue* temp = first;
        cout << "Deleted Element is: " << temp->data << endl;
        first = first->next;
        free(temp);
    }

    if(first != NULL)
        cout << "Dequeue Done." << endl;


}

bool isEmpty(){
    if(first == NULL)
        return true;
    else
        return false;
}

int size(){
    int size = 0;
    if(first == NULL)
        cout << "Queue Is Empty";
    else
    {
        struct queue* temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
            size++;
        }
        size++;
    }

    return size;

}

void showQueue(){
    if(first == NULL)
        cout << "Queue Is Empty";
    else
    {
        struct queue* temp = first;
        while(temp->next != NULL)
        {
            cout << temp->data << "-->" ;
            temp = temp->next;
        }
        cout << temp->data << "-->NULL" << endl ;

    }


}

void Menu() {
    cout << "------Menu------" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check Size" << endl;
    cout << "4. Check if Empty" << endl;
    cout << "5. View Queue" << endl;
    cout << "6. Exit" << endl;
}

int main()
{
    while(true)
    {

        Menu();
        int inp;
        cin >> inp;
        switch (inp) {
            case 1:
                int val;
                cout << "Enter Data to Enqueue: " << endl;
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Size of the Queue: " << size() << endl;
                break;
            case 4:
                cout << "Queue Empty or not (1/0): " << isEmpty() << endl;
                break;
            case 5:
                showQueue();
                break;
            case 6:
                exit(1);
            default:
                cout << "Wrong Choice";

        }
    }
}