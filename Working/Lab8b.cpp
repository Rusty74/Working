#include<iostream>
#include<cmath>
#include<cstring>

const int ArSize = 80;

// prototypes
long left(long num, int ct = 1);

long right(long num, int ct = 1);

char * left(const char * str, int ct = 1);

char * right(const char * str, int n = 1);

int main()	//begin main
{
	using namespace std;

	char str[ArSize];
	cout << "Enter a string:\n";
	cin.getline(str,ArSize);

	long num;
	cout << "Enter an integer:\n";
	cin >> num;
}

// This function returns the first ct digits of the number num
// You are required to modify this function from your lecture notes so that it uses only one while loop: to count the digits.
// Hint use function pow()
long left(long num, int ct = 1);

while (long num > 0)


// This function returns the last ct digits of the number num
// You are required to code this function so that it uses only one while loop: to count the digits.
// Hints: use the ideas from the previous function, function pow(), and the modulus operator
long right(long num, int ct = 1);

//This function returns a pointer to a new string consisting of the first n characters in the str string
char * left(const char * str, int ct = 1);

// This function returns a pointer to a new string consisting of the last n characters in the str string
// Hint: use function strlen()
char * right(const char * str, int n = 1);
