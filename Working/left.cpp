// leftover.cpp -- overloading the left() function
#include <iostream>

const int ArSize=80;
long left(long num, int ct);
char * left(const char * str, int n = 1);

int main()
{
	using namespace std;

    char str[ArSize];
    cout<<"Enter a string:\n";
    cin.getline(str, ArSize);

    long num;
    cout<<"Enter an integer:\n";
	cin>>num;
    
	int i;
	char * temp;

	for (i = 1; i < 10; i++)
	{
		cout << left(num, i) << endl;
		temp = left(str,i);
		cout << temp << endl;
		delete [] temp; // point to temporary storage
		}
	return 0;
}

// This function returns the first ct digits of the number num.

long left(long num, int ct)
{
	int digits = 1;
	long n = num;

	if (ct == 0 || num == 0) return 0; // return 0 if no digits

	while (n /= 10)
		digits++;

	if (digits > ct)
	{
		ct = digits - ct;

		while (ct--)
			num /= 10;

		return num; // return left ct digits
	}
	else return num; // if ct >= number of digits return the whole number
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.

char * left(const char * str, int n)
{
	if (n < 0)
		n = 0;

	char * p = new char[n+1];

	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i]; // copy characters

	while (i <= n) p[i++] = '\0'; // set rest of string to '\0'
 return p;
}

