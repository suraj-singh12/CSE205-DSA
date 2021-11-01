#include <iostream>
using namespace std;

void toh(int disks, int beg, int aux, int end)
{
    if(disks == 1)
    {
        cout << beg << " => " << end << '\n';
        return;
    }
    toh(disks-1,beg,end,aux);
    cout << beg << " => " << end << '\n';
    toh(disks-1,aux,beg,end);
}

int main()
{
    int beg=1, aux=2, end=3;
    cout << "Enter the number of disks: ";
    int n;
    cin >> n;

    toh(n,beg, aux, end);
}