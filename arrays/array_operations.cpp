#include <iostream>
using namespace std;

void print(int *A, int n){
    cout << "===========================================\n";
    cout << "The elements in the array are: \n";
    for (int i = 0; i < n ; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "===========================================\n";
}

void insert(int *A, int &n, int size, int index, int elem){         // n(no of elements) is taken by reference, as it will be updated
    if (n == size){
        cout << "Error!!, array is already full!!\n";
        return ;
    }
    
    for(int i = n - 1; i >= index; i--){
        A[i+1] = A[i];
    }
    A[index] = elem;
    n += 1;
}

void deleteFromIndex(int *A, int &n, int index){
    if(index >= n || index < 0){
        cout << "Error!!, index is out of range.\n";
        return ;
    }
    
    for(int i = index; i < n - 1; i++){
        A[i] = A[i+1];
    }
    n = n - 1;
}

int search(int *A, int n, int elem){
    for (int i = 0; i < n; ++i){
        if(A[i] == elem)
            return i;
    }
    return -1;
}

void deleteElem(int *A, int &n, int elem){
    int index = search(A, n, elem);
    if(index != -1){
        deleteFromIndex(A, n, index);
        cout << "Element successfully deleted.\n";
    }
    else 
        cout << "Element not found!!\n";
}

// optimised ; best time complexity: O(n)   worst time complexity: O(n^2)
void bubbleSort(int *A, int n){
    bool flag = false;              // for optimisation purpose

    cout << "========Sorting=============\n";
    for(int i = 0; i < n-1; i++){
        
        flag = false;
        cout << "\nPass " << i+1 << ": ";

        for(int j = 0; j < n-1-i; j++){
            if(A[j] > A[j+1]){
                flag = true;
                // swap
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
        if (flag == false){     // if no swapping is done, that means elements are already sorted, so break   
            break;
        }
        
        for (int k = 0; k < n; ++k){
            cout << A[k] << " ";
        }
        cout << "\n";
    }
    cout << "\n================================\n";
}

void insertBeforeLargest(int *A, int &n, int size, int elem){
    int largest = INT32_MIN;
    int index = -1;
    for(int i=0;i<n;++i){
        if(A[i] > largest){
            largest = A[i];
            index = i;
        }
    }
    insert(A, n, size, index, elem);
}

void insertionSort(int *A, int n)      // will sort in ascending order
{
    for (int j = 1; j < n; j++)
    {
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && key < A[i])     // very important condition
        {
            A[i+1] = A[i];      // shifting
            i = i-1;
        }
        A[i+1] = key;
        print(A, n);
    }
    
}

void selectionSort(int *A, int n)
{
    for(int i = 0; i < n - 1; ++i)      // for wall (it goes from [0->n-1)  )
    {
        int min = i;            // ith element as min
        for(int j = i+1; j < n; ++j)        // find if any other element in [i+1 to n) is smaller than A[min]
        {
            if(A[j] < A[min])       // if found set min = that element
                min = j;
        }
        if (min!=i)                 // if there was an element in [i+1,n) area, then min will be not i, if so then swap otherwise do not swap
        {
            int tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
        }
        print(A,n);     // print the each ith pass
    }
}

int main()
{
    int *arr, size;
    cout << "Enter the size of the array (>0): ";
    cin >> size;
    while(size <= 0){
        cout << "Error!!, Enter a valid value for size (>0): ";
        cin >> size;
    }

    arr = new int[size];        // creating array on heap

    int n;
    cout << "Enter the number of elements in the array (<=size): ";
    cin >> n;
    while(n>size){
        cout << "Error!!, number of elements can't be more than the size of the array.\n";
        cout << "Enter the number of elements in the array (<=size): ";
    }

    cout << "Enter " << n << " space-seperated integers: \n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // print(arr,n);
    // insert(arr, n, size, 1, 50);
    // print(arr,n);
    // deleteFromIndex(arr, n, 1);
    // print(arr,n);
    // deleteElem(arr, n, 5);
    // print(arr,n);

    // bubbleSort(arr, n);
    // print(arr, n);
    
    // insertBeforeLargest(arr, n, size,45);
    // insertionSort(arr,n);
    selectionSort(arr,n);
    print(arr,n);
    return 0;
}
// 3 5 8 7 9