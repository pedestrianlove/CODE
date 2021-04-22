#include <iostream>

using namespace std;

void draw (int n) {
	for (int i = 0; i < n; i++)
		cout << "*";
	cout << endl;
}

int main ()
{
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++)
			draw (i);
	}
}