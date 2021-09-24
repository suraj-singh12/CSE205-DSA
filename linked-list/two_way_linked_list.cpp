// two-way linked list
#include <iostream>
using namespace std;

struct node{
    node *forward;
    int data;
    node *backward;
};
node *start = NULL;
node *End = NULL;

void print(){
    cout << "\nContents are: ";
    if(start == NULL && End == NULL){
        cout << "List is empty!!\n";
    } else{
        node *ptr = start;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->forward;
        }
    }
    cout << "\n";
}

void insertAtBeginning(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;

    if(start == NULL && End == NULL){          // if there is no node in the list 
        // nd is the first node then
        nd->forward = NULL;     // nothing beyond
        nd->backward = NULL;    // nothing back
        start = nd;             // first node is nd
        End = nd;               // last node is also nd
    } 
    else{     // if there are nodes present in the list
        // make nd the first node
        nd->forward = start;        // nd->forward point to first node
        nd->backward = NULL;        // since nd will become first node, and there's nothing in backside of a first node
        start->backward = nd;       // first_element's->backward point to nd
        start = nd;                 // start point to nd (so nd is now first node)
        // now read that nd->backward = NULL; again (understood now!!)
    }
}

void insertAtEnd(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;

    if(start == NULL && End == NULL){      // if there is no node in the list
        // nd is the first node then
        nd->forward = NULL;     // nothing beyond
        nd->backward = NULL;    // nothing back
        start = nd;             // first node is nd which is the last node itself 
        End = nd;              // last node is also nd
    }
    else{     // if there are nodes present in the list
        // insert nd at the end
        nd->forward = NULL;     // because nd will be last node
        nd->backward = End;     // pointing to present last node of the list 
        End->forward = nd;      // present last node pointing to nd (which now becomes the last node)
        End = nd;               // now nd becomes last node 
    }
}

void insertInSorted(){
    node *nd = new node;
    cout << "Enter data: ";
    cin >> nd->data;

    if(start == NULL && End == NULL){      // if there is no node in the list
        // nd is the first node then
        nd->forward = NULL;     // nothing beyond
        nd->backward = NULL;    // nothing back
        start = nd;             // first node is nd which is the last node itself 
        End = nd;              // last node is also nd
    }
    else if(nd->data < start->data){        // if the data is smaller than first node's data 
        // insert before first node
        nd->forward = start;        // first node will go ahead of nd 
        nd->backward = NULL;        // nothing backside of nd (as it will be first node soon)
        start->backward = nd;       // first node will point back to nd
        start = nd;                 // now nd becomes first node 
    }
    else{               // start checking form next node
        node *ptr = start->forward;
        // traverse in forward direction until we find the right place to insert our new node (nd)
        while(ptr != NULL && ptr->data < nd->data){
            ptr = ptr->forward;
        }

        // if we did not cross the last node, that means we have found a valid place between the nodes to insert our nd node
        if(ptr != NULL){
            node *prev = ptr->backward;     // previous node address saved in *prev ptr

            nd->forward = ptr;          // nd's forward is ptr
            nd->backward = ptr->backward;   // nd's backward is what is in ptr's backward
            ptr->backward = nd;         // now ptr's is nd (ptr updated)
            prev->forward = nd;         // originally prev_node's forward updated to nd
        }
        else{  // it means we have reached beyond last node, that means we did not find a valid place in entire list to insert nd node
            // so insert at end of the list
            nd->forward = NULL;         // nothing is beyond nd 
            nd->backward = End;         // nd's backward pointing to present last node
            End->forward = nd;          // present last node's forward points to nd
            End = nd;                   // as nd is the last node
        }
    }
}

void deleteFromList(int d){
    if(start == NULL && End == NULL){
        cout << "Underflow!!\n";
    }
    else if(start->data == d){        // if only one node present in list
        if(start == End){       // if only one node is there (then we will also need to update End to NULL)
            start = NULL;
            End = NULL;
        }else{          // if more than one node is there in list, then only need to update start
            start = start->forward;
        }
    } 
    else{
        node *ptr = start->forward; 
        while(ptr != NULL && ptr->data != d){
            ptr = ptr->forward;
        }
        
        if(ptr == NULL){        // if gone beyond end
            cout << d << " is not found in the list\n";
        }
        else if(ptr == End){        // if data matches with last node's data
            // drop the last node then
            node *prev = ptr->backward;     // previous node address stored in *prev
            prev->forward = NULL;       // remove last node
            End = prev;                 // now last node is this
        }
        else{
            // drop the ptr node 
            node *prev = ptr->backward;     // previous node's address stored in *prev
            node *ahead = ptr->forward;     // address of the node in front of ptr node is stored in *ahead 
            
            prev->forward = ptr->forward;       // point to node ahead of ptr
            ahead->backward = ptr->backward;    // point to node behind of ptr
            // ptr node is dropped !!
        }
    }
}

void searchInList(int d){
    node *ptr = start;
    while(ptr != NULL){
        if(ptr->data == d){
            cout << "True\n";
            return;
        }
        ptr = ptr->forward;     // move ahead to next node
    }
    cout << "False\n";
}

int main()
{
    int choice;
    do{
        cout << "\n\n1. Create a new doubly linked list\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at the end\n";
        cout << "4. Insert in sorted\n";
        cout << "5. Delete from list\n";
        cout << "6. Search in the list\n";
        cout << "9. Print the linked list\n";
        cout << "0. Exit\n";
        cout << "Enter your resoponse: ";
        cin >> choice;   
        switch(choice){
            case 1:
                    int nodes;
                    cout << "Enter the number of nodes: ";
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
                    cout << "Enter the data to be searched for: ";
                    cin >> d;
                    deleteFromList(d);
                    break;
            case 6:
                    int s;
                    cout << "Enter the data to be searched for: ";
                    cin >> s;
                    searchInList(s);
                    break;
            case 9: 
                    print();
                    break;
            default: 
                    break;
        }
    }while(choice != 0);
    return 0;
}