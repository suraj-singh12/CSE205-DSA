#include <iostream>
using namespace std;

int partition(int *A, int p, int r)
{
    int pivot = A[r];
    int i = p-1;
    for(int j = p; j <= r; ++j){
        if(A[j] <= pivot)
        {
            // increment i and swap
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    return i;
}

void quick_sort(int *A, int p, int r)
{
    if(p < r)
    {
        int q = partition(A, p, r);
        quick_sort(A, 0, q-1);
        quick_sort(A, q+1, r);
    }
}
int main()
{
    int A[] = {5,2,9,4,6,4};
    int n = sizeof(A) / sizeof(int);
    quick_sort(A, 0, n);
    for(auto x: A){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}