// Information Security Assignment RSA Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <numeric>
using namespace std;

double p, q, n, On, e, m;
int encrypt(int, int, int);
int gcdExtended(int a, int b, int *x, int *y);

int encrypt(int m, int e, int n) {
	//If n = 1 it executes the if statement. Since its impossible to have n = 0 since p and q have to be 0 for n to be zero
	if (n == 1)
	{
		//executes the if statement if n = 1. If n is greater than 1 continues the function
		return 0;
	}
	//Created the variable c and asigned it the value 1
	int c = 1;
	//Performs a for loop where the loop continues till i is less than e
	for (int i = 0; i < e; i++) 
	{
		//c is encryption. c is calculated by multiplying c*M mod n = 1
		c = (c*m) % n;
	}
	//Once the loop reaches c = 1 It stops and outputs C
	return c;
}

void modInverse(int a, int k)
{
	int x, y;
	int g = gcdExtended(a, k, &x, &y);
	if (g != 1)
		cout << "d doesn't exist. Since d != 1" << endl;
	else
	{
		// m is added to handle negative x 
		int res = (x % k + k) % k;
		cout << "d = " << res << endl;
	}
}

void modInverseE(int j, int h)
{
	int x, y;
	int g = gcdExtended(j, h, &x, &y);
	if (g != 1)
		cout << "e doesn't exist. Since e != 1" << endl;
	else
	{
		// m is added to handle negative x 
		int res = (x % h + h) % h;
		cout << "e = " << res << endl;
	}
}

int gcdExtended(int a, int b, int *x, int *y)
{
	// Base Case 
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call 
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int main() {
	//User inputs p. P is a prime number
	cout << "Enter p: ";
	cin >> p;

	//User inputs q. Q is a prime number
	cout << "Enter q: ";
	cin >> q;

	//n is the modulous of the private and public keys. n = p*q
	n = p * q;
	cout << "N = " << n << endl;

	//O(n) = (p-1) * (q-1) is the totient. It subtracts a number from p and q and multiplies the subtracted 
	On = (p - 1) * (q - 1);
	cout << "O(n) = " << On << endl << endl;



	//e = gcd(e,O(n)) = 1
	cout << "CALCULATING e" << endl;
	int j, h;
	//User inputs e
	cout << "Enter d: ";
	cin >> j;
	//User inputs On
	cout << "Enter On: ";
	cin >> h;
	//Calls the function modInverse to calculate d
	modInverseE(j, h);
	cout << endl;




	//d = e*d mod On = 1
	cout << "CALCULATING d" << endl;
	//Declaring the variables a,k to calculate d
	int a, k;
	//User inputs e
	cout << "Enter e: ";
	cin >> a;
	//User inputs On
	cout << "Enter On: ";
	cin >> k;
	//Calls the function modInverse to calculate d
	modInverse(a, k);
	cout << endl;

	



	//C = M^e mod N
	cout << "CALCULATING c" << endl;
	//Declare the variables m,e,n to calculate c
	int m, e, n;
	//M stands for Message and it is the base
	cout << "M = ";
	cin >> m;
	//e stands for secret key
	cout << "e = ";
	cin >> e;
	//n is the modulus and is mod n 
	cout << "N = ";
	cin	>> n;


	//Encryption also known as C is calculated by using the square and multiply algorithm.
	cout << endl << "Encryption C = " << encrypt(m, e, n) << endl;
	
	return 0;
}