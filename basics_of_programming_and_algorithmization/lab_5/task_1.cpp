#include <iostream>

using namespace std;

struct node {
    int data;
    int data1;
    struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

struct queue{
    int kfccombo;
    int cola;
};

void Insert() {
    int val;
    int val1;
    cout<<"Insert count of humburgers and Cola Dobriy : "<<endl;
    cin>>val;
    cin>>val1;
    if (rear == NULL) {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = val;
        rear->data1 = val1;
        front = rear;
    } else {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = val;
        temp->data1 = val1;
        temp->next = NULL;
        rear = temp;
    }
}
void Delete() {
    temp = front;
    if (front == NULL) {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    if (temp->next != NULL) {
        temp = temp->next;
        cout<<"Element deleted from queue is : "<<front->data << " " << front->data1<<endl;
        free(front);
        front = temp;
    } else {
        cout<<"Element deleted from queue is : "<<front->data << " " << front->data1 <<endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}
void Display() {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements are: " << endl;
    while (temp != NULL) {
        int x = temp->data;
        if(x!=0) cout << temp->data << " Haburgers" << " ";
        if(x!=0) cout << temp->data1 << " Cola Dobriy";
        cout << endl;
        temp = temp->next;
    }
    cout<<endl;
}
int main() {
    int 
    int ch;
    cout<<"1) Insert human to queue tp choose what to do"<<endl;
    cout<<"2) Delete human from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Exit"<<endl;
    do {
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch (ch) {
            case 1: Insert();
            break;
            case 2: Delete();
            break;
            case 3: Display();
            break;
            case 4: cout<<"Exit"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
    } while(ch!=4);
    return 0;
}
