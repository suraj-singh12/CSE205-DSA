#include <iostream>
using namespace std;

struct node{
    int data;
    node *link;
};
node *start = NULL;

void print(){
    cout << "\nContents are: ";
    if(start != NULL){
        cout << "Contents are: ";
        node *ptr = start;
        
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
    } 
    else
        cout << "List empty!!";
    cout << "\n";
}
void insertAtBeginning(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;
    
    if(start == NULL){
        nd->link = NULL;
        start = nd;
    } 
    else{
        nd->link = start;
        start = nd;    
    }
}

void insertAtEnd(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;
    
    if(start == NULL){
        nd->link = NULL;
        start = nd;
    }
    else{
        node *ptr = start; 
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        nd->link = NULL;
        ptr->link = nd;
    }
}

void insertInSorted(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;

    if(start == NULL){
        nd->link = NULL;
        start = nd;
    } else if(nd->data < start->data){
        nd->link = start;
        start = nd;
    } else{
        node *prev = start;
        node *ptr = start->link;
        while(ptr != NULL && ptr->data < nd->data){
            prev = ptr;
            ptr = ptr->link;
        }
        nd->link = ptr;
        prev->link = nd;
    }
}
void deleteFromList(int d){
    if(start == NULL){
        cout << "Underflow!!";
    } else if(start->data == d){
            start = NULL;
    } else{
        node *prev = start;
        node *ptr = start->link;
        while(ptr != NULL && ptr->data != d){
            prev = ptr;
            ptr = ptr->link;
        }
        if(ptr == NULL){
            cout << "Element to be deleted is not in the list.";
        } else{
            prev->link = ptr->link;
            ptr->link = NULL;     //optional, but a good practise
        }
    }
}

// searches for the given element in the list, if found prints true; else prints false
void searchInList(int d){
    node *ptr = start;
    while(ptr != NULL){
        if(ptr->data == d){
            cout << "True\n";
            return;
        }
        ptr = ptr->link;    // move ahead to next link
    }
    cout << "False\n";
}

int main()
{
    int choice;
    do{
        cout << "1. Create a linked list\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Insert in sorted list\n";
        cout << "5. Delete element at a position\n";
        cout << "6. Search in the list\n";
        cout << "9. Print the linked list contents\n";
        cout << "Enter your choice: ";
        switch(choice){
            case 1:
                    int nodes;
                    cout << "How many nodes to insert: ";
                    cin >> nodes;
                    for(int i = 0; i < nodes; ++i){
                        insertAtBeginning();
                    }
                    break;
            case 2:
                    insertAtBeginning();
                    break;
            case 3: 
                    insertAtEnd();
                    break;
            case 4:
                    insertInSorted();
                    break;
            case 5:
                    int d;
                    cout << "Enter the element to be deleted: ";
                    cin >> d;
                    deleteFromList(d);
                    break;
            case 6:
                    int elem;
                    cout << "Enter the element to be searched for: ";
                    cin >> elem;
                    searchInList(elem);
                    break;
            case 9:
                    print();
                    break;
            default: cout << "Implementation pending\n";
        }
    }while(choice != 0);
    return 0;
}