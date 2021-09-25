// implementation of STACK using arrays

#include <iostream>
using namespace std;

int size = 10;
int STACK[10];      // let STACK has a total size of 10
int top = -1;

void push(int data){
    // check if stack is full
    if(top == size-1){
        cout << "Overflow!!";
        return;
    }
    // insert the element in stack
    ++top;
    STACK[top] = data;
}
int pop(){
    // check if stack is empty
    if(top == -1){
        cout << "Underflow i.e. ";
        return -1;
    }
    // pop the element from stack
    int item = STACK[top];
    top--;
    return item;
}

int main()
{
    int choice; 
    do{
        cout << "\n\n1. Push()\n";
        cout << "2. Pop()\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1: int d;
                    cout << "Enter data to be pushed: ";
                    cin >> d;
                    push(d);
                    break;
            case 2:
                    cout << pop();
                    break;
            default:
                    break;
        }
    }while(choice != 0);
    return 0;
}