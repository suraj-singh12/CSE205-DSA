#include <iostream>
using namespace std;

struct node{
    char data;
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
    } else if(start->link == NULL){
        save = NULL;
        ptr = start;

        if(ptr->data < NEW->data){
            NEW->link = NULL;
            ptr->link = NEW;
        } else{
            NEW->link = start;
            start = NEW;
        }
    } else{
        save = start;
        ptr = start->link;

        while(ptr != NULL && ptr->data < NEW->data){
            save = ptr;
            ptr = ptr->link;
        }
        NEW->link = save->link;
        save->link = NEW;
    }
}

// INCOMPLETE
void deleteItem(char c){
    node *locp, *loc;
    node *ptr = start;
    if(ptr == NULL){                // if the list is empty
        locp = NULL;
        loc = NULL;
        cout << "Underflow !!";
    } else if(ptr->link == NULL){       // if only 1 node in list
        locp = NULL;
        loc = start;
        if(loc->data == c){
            start = loc = NULL;
        }
    } else{                         // if list has nodes > 1
        locp = start;
        loc = start->link;
        
        if(locp->data == c){        // if first node matches, then just update start pointer and that's it
            start = start->link;
        } 
        else{           // check from node 2
            
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
            case 4:
                    insertSorted();
                    break;
            case 5:
                    char c;
                    cout << "Enter element to be deleted: ";
                    cin >> c;
                    deleteItem(c);
                    break;
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