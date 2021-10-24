// array implementation of binary tree

// NOTE : The formulae used in program are modified ones. NOT to be used in exams.

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    int maxHeightOfTree, sizeOfArrayReqd;
    if(n > 2)
    {
        maxHeightOfTree = (n-1) +1;     // +1 keeping in mind the right skew matrix
        sizeOfArrayReqd = pow(2,maxHeightOfTree) - 1;       // here that right skew matrix +1 comes in play, i.e. in determining sizeOfArray
        
        // array index starts from 0, but algorithm starts from 1, so need to add one more location in array at end
        // eg. node = 4 (right skew tree), so maxHeightOfTree = 3, 
        sizeOfArrayReqd += 1; 
    }
    else{
        maxHeightOfTree = n + 1;
        sizeOfArrayReqd = n + 1;
    }
    char A[sizeOfArrayReqd] = {'\0'};

    cout << "Enter the nodes(0 to exit; '-' if a node has no child): \n";
    int i=1;
    cin >> A[i];            // read root node
    int nodeCount = 1;

    if(n > 1)
    {
        do{
            int indChild1 = 2 * i;
            int indChild2 = 2 * i + 1;

            char parentOfChild = A[int(indChild1/2)];   // parent of above children
            if(parentOfChild != '-')       // if parent is not null, only then it will have children, else not possible
            {
                if(nodeCount < n){
                    cin >> A[indChild1];
                    if(A[indChild1] == '0'){
                        A[indChild1] = '\0';
                        break;
                    }
                    if(A[indChild1] != '-')
                        nodeCount++;
                }
                
                if(nodeCount < n){
                    cin >> A[indChild2];
                    if(A[indChild2] == '0'){
                        A[indChild2] = '\0';
                        break;
                    }
                    if(A[indChild2] != '-')
                        nodeCount++;
                }
            }
            else
            {
                A[indChild1] = '-';
                cout << "-\n";
                // nodeCount++;

                A[indChild2] = '-';
                cout << "-\n";
                // nodeCount++;
            }
            i++;
        }while( (((2*i) + 1) < sizeOfArrayReqd) && (nodeCount < n)); 
        // ((2*i) + 1) <= sizeOfArrayReqd : this ensures 'no OutOfBound access'
        // nodeCount < n  : this ensures loop runs only as much nodes are there
    }
    
    for(int i = 1; i < sizeOfArrayReqd; ++i){
        cout << A[i] << " ";
    }
    cout << endl;
}