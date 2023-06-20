#include <iostream>
using namespace std;

int kfcCombo = 10;

struct Node {
	int data;
	Node* next;
};

void push(Node** head_ref)
{
	Node* new_node = new Node();
	int data;
	while(true){
    	cout << "Input number of KFCCombo(positive number): "; cin>>data;
	    if(data > 0)break;
	}
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteNode(Node** head_ref, int position)
{
    if(position == -1){
        cout<<"Need more supplays"<<endl;
        return ;
    }

    if (*head_ref == NULL)
	    return;

    Node* temp = *head_ref;

    if (position == 0) {
        kfcCombo -= temp->data;
	    *head_ref = temp->next;

	    free(temp);
	    return;
	}

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;
    kfcCombo -= temp->data;
    Node* next = temp->next->next;

    free(temp->next); 

    temp->next = next;
    
}

int posFind(Node* node){
    int i=0;
    int pos=0;
    int data = 99999999;
    while (node != NULL) {
		if(node->data <= kfcCombo) {
		    pos = i;
		    data = node->data;
		}
		node = node->next;
		i++;
	}
	if(data>kfcCombo)return -1;
	return pos;
}

void printList(Node* node)
{
    cout << "Orders: ";
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

void addSupplays(int $kfcCombo){
    int newkfcCombo; 
    while(true){
        cout << "How much food & drink comming(positive number, please): ";
        cin >> newkfcCombo;
        cout << endl;
        if(newkfcCombo > 0){
            break;
        }
        
    }
    kfcCombo += newkfcCombo;
    return;
}

void DisplaySuplays(){
    cout << "KFCCombo: " << kfcCombo << "; " << endl;
    return;
}

// Driver code
int main()
{
    cout<<"1) Insert human to queue tp choose what to do"<<endl;
    cout<<"2) Delete human from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Add supplues"<<endl;
    cout<<"5) Display foods and drinks"<<endl;
    cout<<"6) Exit"<<endl;
	Node* head = NULL;
    int ch;
    do {
        cout<<"Enter your choice : ";
        cin>>ch;
        switch (ch) {
            case 1: push(&head);;
            break;
            case 2: deleteNode(&head,posFind(head));
            break;
            case 3: printList(head);
            break;
            case 4: addSupplays(kfcCombo);
            break;
            case 5: DisplaySuplays();
            break;
            case 6: cout<<"Exit"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
    } while(ch!=6);
	return 0;
}
