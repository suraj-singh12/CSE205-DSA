#include <iostream>
using namespace std;

struct node{
    int data;
    node *link;
};
node *start = NULL;

void print(){
    node *ptr = start;
    while(ptr != NULL){     // we can't do while(ptr->link != NULL) because then the last node data will not be printed, because it will have NULL in its link
        cout << ptr->data << " ";
        ptr = ptr->link;    // now ptr points to next node (in the last node, when it is done, loop breaks; but see we printed the last node data already)
    }
    cout << '\n';
}

void insertAtBeginning(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;

    if(start == NULL){
        nd->link = NULL;
        start = nd;
    } else{
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
    } else{
        node *ptr = start;
        while(ptr->link != NULL)        // when i am in last node, i check does this node's link == NULL; it says yes and loop exits
            ptr = ptr->link;
        
        nd->link = NULL;
        // now I am sure that I am at the last node (because of the logic used in while loop), and now I can do ptr->link = nd 
        ptr->link = nd;
    }
}

void insertSorted(){
    node *NEW = new node;
    cout << "Enter the data: ";
    cin >> NEW->data;
    
    node *save, *ptr;
    if(start == NULL){
        // save = NULL;
        // ptr = NULL;
        NEW->link = NULL;
        start = NEW;
    } else if(NEW->data < start->data){
        // save = NULL;
        // ptr = start;
        NEW->link = start;
        start = NEW;
    } else{
        save = start;
        ptr = start->link;
        // here using two pointer approach to keep a track of previous node's address
        while(ptr != NULL && ptr->data < NEW->data){
            save = ptr;
            ptr = ptr->link;
        }

        NEW->link = ptr;        // NEW node points to ptr (node ahead of it)
        save->link = NEW;       // previous of ptr (save),points to NEW node; 
        // now this new node is between save and ptr (i.e. insertion done)
    }
}


void deleteItem(int c){
    node *locp, *loc;
    node *ptr = start;
    if(ptr == NULL){                // if the list is empty
        locp = NULL;
        loc = NULL;
        cout << "Underflow !!";
    } else if(start->data == c){       // if first node itself matches the data 
        // locp = NULL;
        // loc = start;
        start = start->link;
    } else{                         // if list has nodes > 1
        locp = start;
        loc = start->link;
        
        // check from node 2
        while(loc != NULL && loc->data != c){
            locp = loc;
            loc = loc->link;
        }

        // now check if we did not reach end of list, that means element matched a node's data
        // so delete that node
        if(loc != NULL){
            locp->link = loc->link;
            loc->link = NULL;   // optional but good
        } 
        else        // if loc is NULL, that means, we did not find a node having the element asked to delete
            cout << c << " does not exist in the list !";
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
        cout << "\n\n1. Create a linked list\n";
        cout << "2. Insert in the beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Insert in Sorted List\n";
        cout << "5. Delete from list\n";
        cout << "6. Search an element\n";
        cout << "9. Print the linked list contents\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                    int nodes; 
                    cout << "Enter the number of nodes: ";
                    cin >> nodes;
                    for (int i = 0; i < nodes; i++)
                        insertAtBeginning();
                    break;
            case 2:
                    insertAtBeginning();
                    break;
            case 3:
                    insertAtEnd();
                    break;
            case 4: // assuming list is sorted in ascending order
                    insertSorted();
                    break;
            case 5:
                    int c;
                    cout << "Enter element to be deleted: ";
                    cin >> c;
                    deleteItem(c);
                    break;
            case 6:
                    int elem;
                    cout << "Enter the element to be searched for: ";
                    cin >> elem;
                    searchInList(elem);
            case 9:
                    cout << "Contents are: ";
                    print();
                    break;
            default:
                    break;
                    
        }
    }while(choice != 0);
    return 0;
}