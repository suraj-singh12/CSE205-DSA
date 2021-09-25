// program to implement stack using linked list
#include <iostream>
using namespace std;

struct node{
    int data;
    node *link;
};
node* top = NULL;

void push(){
    node *nd = new node;
    cout << "Enter the data to be pushed: ";
    cin >> nd->data;
    
    if(top == NULL){
        // insert the node at top
        nd->link = NULL;
        top = nd;
    }
    else{
        // inserting at the beginning (which is our top)
        nd->link = top;
        top = nd;
    }
}

int pop(){
    if(top == NULL){
        cout << "Underflow i.e. ";
        return -1;
    }
    else{
        int data = top->data;
        // dropped the topmost node (first one)
        top = top->link;
        return data;
    }
    return -1;
}

int main(){
    int choice;
    do{
        cout << "\n\n1. Push\n";
        cout << "2. Pop\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;
        
        case 2:
            cout << pop() << '\n';
            break;

        default:
            break;
        }
    }while(choice != 0);

    return 0;
}