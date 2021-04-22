#include <iostream>
#include <cmath>

using namespace std;
int LEN;
int str_to_int (char* s, int len) {
	int sum = 0, mult = 1;
	for (int i = len-1; i >= 0; i--) {
		sum += (s[i] - '0') * mult;
		mult *= 10;
	}
	return sum;
}

bool isPrime (int n) {
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt (n); i+= 2) {
		if (n % i == 0) return false;
	}
	return true;
}



// interface
int Compute (char* str, int pt, int n) {

	//
	if (n >= 1) {
		Compute (str, pt+1, n-1);
	

		// ignore
		char tmp = str[0];
		str[0] = '0';
		Compute (str, pt+1,  n-1);
	}
	else {

	}
}

int main ()
{
	int n;
	string s; char* num;
	while (cin  >> s) {
		LEN = s.length ();
		num = new char[LEN];

	}
}