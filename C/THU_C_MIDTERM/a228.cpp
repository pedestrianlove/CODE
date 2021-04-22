#include <iostream>

using namespace std;

int main ()
{
	// var
	int n, paid, real;
	int change[9] = {2000, 1000, 500, 200, 100, 50, 10, 5, 1};

	while (cin >> n) {
		for (int i= 0; i < n; i++) {
			// input
			cin >> paid >> real;	paid -= real;

			// process && output
			for (int j= 0 ; j < 9; j++) {
				if (paid >= change[j]) {
					cout << (paid / change[j]);
					paid = paid % change[j];
				}
				else {
					cout << 0;
				}
				if (j != 8) cout << " ";
			}
			cout << endl;


		}
	}
}