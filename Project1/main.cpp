// author @Mabon Manoj Ninan M13883690

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

// This function is a special function that I deveopled to ensure that users do not input a decimal number which may cause the program to go into an infinite loop
int input() {
	double inp;
	cin >> inp;
	while (cin.fail() || (inp - floor(inp)))
	{
		cout << "Error. Elements has to be integer. Try again: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> inp;
	}
	int inp1 = (int)inp;
	return inp1;
}

// Input function for the fraction
void InputFractions(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4)
{
	cout << "First Fraction:\n";
	cout << "Enter the numerator (Only Whole Number):\n";
	Num = input();
	while (Num < 0) {
		cout << "Error!\n Enter a Whole number\n";
		Num = input();
	}
	cout << "Enter the denominator (Only possitive integer):\n";
	Denom = input();
	while (Denom <= 0) {
		cout << "Error!\nEnter a positive number integer\n";
		Denom = input();
	}


	cout << "Second Fraction:\n";
	cout << "Enter the numerator (Only Whole Number):\n";
	Num2 = input();
	while (Num2 < 0) {
		cout << "Error!\n Enter a Whole number\n";
		Num2 = input();
	}
	cout << "Enter the denominator (Only possitive integer):\n";
	Denom2 = input();
	while (Denom2 <= 0) {
		cout << "Error!\nEnter a positive number integer\n";
		Denom2 = input();
	}


	cout << "Third Fraction:\n";
	cout << "Enter the numerator (Only Whole Number):\n";
	Num3 = input();
	while (Num3 < 0) {
		cout << "Error!\nEnter a positive number integer\n";
		Num3 = input();
	}
	cout << "Enter the denominator (Only possitive integer):\n";
	Denom3 = input();
	while (Denom3 <= 0) {
		cout << "Error!\nEnter a positive number integer\n";
		Denom3 = input();
	}

	cout << "Fourth Fraction:\n";
	cout << "Enter the numerator (Only Whole Number):\n";
	Num4 = input();
	while (Num4 < 0) {
		cout << "Error!\nEnter a positive number integer\n";
		Num4 = input();
	}
	cout << "Enter the denominator (Only possitive integer):\n";
	Denom4 = input();
	while (Denom4 <= 0) {
		cout << "Error! Enter a positive number";
		Denom4 = input();
	}


}\


/* This function is called after InputFractions(). This function will
   reduce the two fractions.
   Pre: Two Fractions
   Post: Two reduced fractions */
	void reduce(int& Num, int& Denom)

{
	int a, b, j = 0;
	a = Denom;
	b = Num;

	for (int i = a * b; i > 1; i--)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			a /= i;
			b /= i;
		}
	}
	cout << Num << "/" << Denom << " is reduced to " << b << "/" << a << endl;

	Denom = a;
	Num = b;
}

//This function converts improper fractions to mixed fractions
void reduce2(int& Num, int& Denom)

{
	int whole_num = 0;
	whole_num = Num / Denom;
	int dividend = 0;
	dividend = Num % Denom;
	cout << Num << "/" << Denom << " is reduced  to " << whole_num << " and " << dividend << "/" << Denom << endl;

}


/* This function is called after Reduce. This function adds the two
   fractions Reduce() reduced
   Pre: Two Fractions
   Post: One reduced fraction  */
int addfractions(int Num, int Denom, int Num2, int Denom2, int& a, int& b, int& c, int& x, int& y)

{

	cout << "The sum of " << Num << "/" << Denom << " and " << Num2 << "/" << Denom2 << " is ";
	if (Denom != Denom2)
	{

		y = Denom * Denom2;
		a = Denom2 * Num;
		b = Denom * Num2;
		c = a + b;
	}
	else
	{
		c = Num + Num2;
		y = Denom;
	}
	cout << c << "/" << y << endl;

	reduce(c, y);
	reduce2(c, y);

	return c, y;
}

//This function checks if the first fraction is greater or not
bool IsGreater(int& Num, int& Denom, int& Num2, int& Denom2)
{
	int h, j = 0;
	h = Num * Denom2;
	j = Num2 * Denom;
	if (h > j) {
		return true;
	}
	else {
		return false;
	}
}

// Power funtion
int power(int x, int n)
{
	if (n == 0) {
		return 1;
	}
	else {
		return pow(x, n);
	}
}

//Helps for power of fraction
void FracPow(int Num, int Denom, int p)

{

	int n = 0;
	int d = 0;
	d = power(Denom, p);
	n = power(Num, p);
	cout << Num << '/' << Denom << " raised to power of " << p << " gives " << n << "/" << d << endl;
	reduce(n, d);
	reduce2(n, d);

}


//Main Function 
int main()
{
	char an;
	do
	{
		int whole_num = 0;
		int a, b, c, x, y = 0;
		int Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4, Num5, Denom5, Num6, Denom6, Num7, Denom7, Num8, Denom8;

		InputFractions(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4);

		reduce(Num, Denom);
		reduce(Num2, Denom2);
		reduce(Num3, Denom3);
		reduce(Num4, Denom4);
		cout << endl;
		cout << endl;

		reduce2(Num, Denom);
		reduce2(Num2, Denom2);
		reduce2(Num3, Denom3);
		reduce2(Num4, Denom4);
		cout << endl;
		cout << endl;

		Num5, Denom5 = addfractions(Num, Denom, Num2, Denom2, a, b, c, x, y);
		Num5, Denom6 = addfractions(Num, Denom, Num3, Denom3, a, b, c, x, y);
		Num5, Denom7 = addfractions(Num2, Denom2, Num3, Denom3, a, b, c, x, y);
		Num5, Denom8 = addfractions(Num2, Denom2, Num4, Denom4, a, b, c, x, y);
		cout << endl;
		cout << endl;


		if (IsGreater(Num, Denom, Num2, Denom2) == true)
		{
			cout << Num << "/" << Denom << " is greater than " << Num2 << "/" << Denom2 << endl;
		}
		else {
			cout << Num << "/" << Denom << " is not greater than " << Num2 << "/" << Denom2 << endl;
		}

		if (IsGreater(Num2, Denom2, Num3, Denom3) == true)
		{
			cout << Num2 << "/" << Denom2 << " is greater than " << Num3 << "/" << Denom3 << endl;
		}
		else {
			cout << Num2 << "/" << Denom2 << " is not greater than " << Num3 << "/" << Denom3 << endl;
		}

		if (IsGreater(Num2, Denom2, Num4, Denom4) == true)
		{
			cout << Num2 << "/" << Denom2 << " is greater than " << Num4 << "/" << Denom4 << endl;
		}
		else {
			cout << Num2 << "/" << Denom2 << " is not greater than " << Num4 << "/" << Denom4 << endl;
		}
		if (IsGreater(Num3, Denom3, Num4, Denom4) == true)
		{
			cout << Num3 << "/" << Denom3 << " is greater than " << Num4 << "/" << Denom4 << endl;
		}
		else {
			cout << Num3 << "/" << Denom3 << " is not greater than " << Num4 << "/" << Denom4 << endl;
		}



		int p1, p2, p3, p4;
		cout << "Enter power for fraction 1: ";
		cin >> p1;
		cout << "Enter power for fraction 2: ";
		cin >> p2;
		cout << "Enter power for fraction 3: ";
		cin >> p3;
		cout << "Enter power for fraction 4: ";
		cin >> p4;

		FracPow(Num, Denom, p1);
		FracPow(Num2, Denom2, p2);
		FracPow(Num3, Denom3, p3);
		FracPow(Num4, Denom4, p4);

		cout << "Would you like to re-run this porgram? (y/n) ";
		cin >> an;
	} while ((an == 'y') || (an == 'Y'));

	return(0);
}

/*	  Cerificate:
//... This Code was Developed By Mabon Manoj Ninan
..... University of Cincinnati
......Machine Learning Reseacher: Lab Of Computer Vision- MNourzi
......Cource: Data Structures
..... Instructor: Nitin Nitin
..... 05/23/2022
*/