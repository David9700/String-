
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "String.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "String sample project" << endl;
	cout << "---------------------" << endl << endl;

	String a("This"), b("is"), c("a"), d("test");
	String e = a + " " + b + " " + c + " " + d;

	cout << "String parts:" << endl;
	cout << '\t' << a << endl;
	cout << '\t' << b << endl;
	cout << '\t' << c << endl;
	cout << '\t' << d << endl << endl;

	cout << "Concatenated with spaces:" << endl;
	cout << '\t' << e << endl << endl;

	String f, g;

	cout << "Please input a string (empty to break): ";
	cin >> f;
	cout << "Please input other string (empty to break): ";
	cin >> g;

	cout << endl;

	cout << "1st string (" << f << ") is " << f.Length() << " chars long." << endl;
	cout << "2nd string (" << g << ") is " << g.Length() << " chars long." << endl;

	cout << endl;
	f[2] = 'a';
	cout << "1st string's second character is:" << f[2] << endl;
	cout << "1st string in lowercase is: " << f.Lower() << endl;
	cout << "1st string in uppercase is: " << f.Upper() << endl << endl;

	cout << "2nd string in lowercase is: " << g.Lower() << endl;
	cout << "2nd string in uppercase is: " << g.Upper() << endl;
	cout << "2 belongs to 1: " << (f && g) << endl << endl;

	cout << "1 < 2\t=> " << (f < g ? "true" : "false") << endl;
	cout << "1 <= 2\t=> " << (f <= g ? "true" : "false") << endl;
	cout << "1 > 2\t=> " << (f > g ? "true" : "false") << endl;
	cout << "1 >= 2\t=> " << (f >= g ? "true" : "false") << endl;
	cout << "1 == 2\t=> " << (f == g ? "true" : "false") << endl;
	cout << "1 != 2\t=> " << (f != g ? "true" : "false") << endl << endl;

	if (f == g)
		cout << "Strings are equal." << endl;
	else
		cout << "Strings are not equal." << endl;

	cout << endl;

	cout << "1+2\t=> " << f + g << endl;
	cout << "2+1\t=> " << g + f << endl;

	cout << endl;


	system("pause");//for visual studio 2017

	return 0;
}
