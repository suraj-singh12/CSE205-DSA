#include<iostream>

using namespace std;

	int* arr;
    int size, n;





void print()
{
	cout<<"\n\n\t* * * ARRAY * * *\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<< "\t";
	}
}

    
void bubble_sort()
{
	bool flag = true;
	
	for(int i=0; flag && i<n-1; i++)
	{
		flag = false;
		for(int j=0; j<n-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{    
			    flag = true;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= temp;
			}
		}
		print();
	}
}

int search(int item)
{
	int pos = -1;
	for(int i=0; i<n; i++)
	{
		if(item == arr[i])
		{
			pos = i; break;
		}
	}
	return pos;
}


void insert(int item, int index)
{
	for(int i=n-1; i >= index; i--)
	{
		arr[i+1] = arr[i];
	}
	arr[index] = item;
	n = n+1;
}

void delete_at_index(int index)
{
	for(int i=index; i<n-1; i++)
	   arr[i] = arr[i+1];
	   
	n = n-1;
}

void delete_ITEM(int item)
{
    int index = search(item);

    if(index != -1)
	    delete_at_index(index);	
    else cout<<"\nITEM "<<item <<" is NOT PRESENT in this Array";
}

void insert_before_largest(int item)
{
	//Insert the item before the largest element of the array
}


int main()
{	
	cout<<"\nEnter the size of the Array:\t";
	cin>> size;
	
	arr = new int[size];
	
	cout<<"\nEnter the Number of Elements to be stored in Array:\t";
	cin>> n;
	
	cout<<"\nPlease Enter the elements of the Array\n";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
    }
bubble_sort();

	//insert(20, 1);
	//delete_at_index(2);
	
//	delete_ITEM(20);
  //  print();
	
	return 0;
}

