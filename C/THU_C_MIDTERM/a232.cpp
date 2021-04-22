#include <iostream>

using namespace std;

void draw (int n, char x) {
	for (int i = 0; i < n; i++) {
		cout << x;
	}
}


int main ()
{
	int m, n;
	while (cin >> m >> n) {
		for (int i=  0; i < m; i++) {
			if (i == 0 || i == (m-1))	draw (n, '*');
			else {
				draw (1, '*');
				draw (n - 2, ' ');
				draw (1, '*');
			}
			cout << endl;
		}
	}
}