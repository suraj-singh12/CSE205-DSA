#include <iostream>
#include <string>
using namespace std;

struct node{
    string name;
    int rollNo;
    node* link;
};
node* head = NULL;

void traverse(){
    node *ptr = head;
    while(ptr != NULL){     // we can't do while(ptr->link != NULL) because then the last node data will not be printed, because it will have NULL in its link
        cout << ptr->name << " ";
        ptr = ptr->link;    // now ptr points to next node (in the last node, when it is done, loop breaks; but see we printed the last node data already)
    }
    cout << '\n';
}

void search(int r){
    node *ptr = head;
    while(ptr != NULL){
        if(ptr->rollNo == r){
            cout << ptr->name << " is roll No " << r << '\n';
            break;
        }
        ptr = ptr->link;
    }
    if(ptr == NULL){
        cout << "Roll number " << r << " NOT found.\n";
    }
}
int main()
{
    // creating 5 nodes
    // static implementation
    node *n1 = new node;
    node *n2 = new node;
    node *n3 = new node;
    node *n4 = new node;
    node *n5 = new node;

    // inserting data and linking nodes
    n1->name = "Fury";     n1->rollNo = 21;    n1->link = n2;
    n2->name = "Charlie";     n2->rollNo = 22;    n2->link = n3;
    n3->name = "Michael";   n3->rollNo = 23;    n3->link = n4;
    n4->name = "Delta";      n4->rollNo = 24;    n4->link = n5;
    n5->name = "John";      n5->rollNo = 25;    n5->link = NULL;
    head = n1;      // head points to first node

    cout << "All Students in list:\n";
    traverse();
    cout << '\n';

    int roll;
    cout << "Enter the roll number to be searched: ";
    cin >> roll;
    search(roll);

    head = n1 = n2 = n3 = n4 = n5 = NULL;
    delete n1;  delete n2;  delete n3;  delete n4;  delete n5;
    return 0;
}