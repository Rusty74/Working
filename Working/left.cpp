 // left.cpp -- string function with a default argument
#include <iostream>
using namespace std;
const int ArSize = 80;

char * left(const char * str, int n = 1);

int main()
{
	char sample[ArSize];
	int count = 0;
	int strl = size_t(sample);
while (count < strl)
	{
		cout << "Enter a string:\n";
		cin.get(sample,ArSize);
		cout << count;
		char *ps = left(sample, count);
		cout << ps << endl;
		delete [] ps;                  // free old string

		ps = left(sample);
		cout << ps << endl;
		delete [] ps;                 // free new string
		count++;
	}
    return 0;
}

// This function returns a pointer to a new string // consisting of the first n characters in the str string.
char * left(const char * str, int n)
{
	if (n < 0)
		n = 0;
    char * p = new char[n+1];
    int i;

    for (i = 0; i < n && str[i]; i++)
    	p[i] = str[i];                               // copy characters
    while (i <= n)
    	p[i++] = '\0';                           // set rest of string to '\0‘
    return p;
}
