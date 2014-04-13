//Rusty Shivers
#include <iostream>
#include <string>

// testing commit

template <typename Any>
void Show(Any a[],int n);

template <typename Any>
Any Maximum(Any a[], int n);

template <typename Any>
Any Minimum(Any a[], int n);

template <typename Any>
void find(Any a[], int n, Any element);

template <typename Any>
void Swap(Any &a, Any &b);

template <typename Any>
void Sort(Any a[], int n);

const int Size = 15;
using namespace std;


int main()
{

	int array1[Size] = {44,5,2,90,45,99,12,7,4,9,0,15,23,89,32};
	
	double array2[Size] = {7.5,2.4,45.3,9.7,82.3,1.2,14.8,2.3,44.1,20.9,5.8,12.2,34.2,16.8,1.5};
	
	char array3[Size] = {'e','p','r','a','s','z','l','c','b','k','w','v','x','t','d'};
	
	string array4[Size] = {"dog","cat","bear","eagle","ant","bird","monkey","elephant","lion","gecko", "dolphin","horse","cow","donkey",};
 	
}

// Prints the contents of the array of size n
template <typename Any>
void Show(Any a[],int n)
{
	for(int i=0;i<=n;i++)
		cout << a[i] << " ";
	cout << endl;
}
//Returns the maximum element of the array of size n
//Does not assume that the elements of the array are sorted
template <typename Any>
Any Maximum(Any a[], int n)
{
	Any max = a[0];
	for(int i = 0 ; i< n ;i++)
		if (a[i] >  max)
		  max = a[i];
	return max;
}
//Returns the minimum element of the array of size n
//Does not assume that the elements of the array are sorted
template <typename Any>
Any Minimum(Any a[], int n)
{
	Any min = a[0];
	for(int i = 0 ; i < n ;i++)
		if (a[i] <  min)
		  min = a[i];
	return min;
}
//Prints whether element is in the array of size n or not
template <typename Any>
void find(Any a[], int n, Any element)
{
	Any find = a[0];
	for(int i = 0 ; i < n ; i++)
		if (a[i] == find)
			find = a[i];
	return find;
}
//Swaps the contents of a and b
//Uses pass by reference
template <typename Any>
void Swap(Any &a, Any &b);

//Sorts the array of size n using the selection sory algorithm explained in class
//MUST use function Swap
//DO NOT use pointers to sort
template <typename Any>
void Sort(Any a[], int n);

