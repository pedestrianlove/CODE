#include <iostream>

using namespace std;

int main ()
{
	long long n;
	long long data[5] = {1000000000000, 1000000000, 1000000, 1000, 1};
	string str_list[5] = {" TB", " GB", " MB", " KB", " B"};
	while (cin >> n) {
		// process && output
		for (int j= 0 ; j < 5; j++) {
			if (n >= data[j]) {
				cout << (n / data[j]) << str_list[j];
				n = n % data[j];
				if (n != 0) cout << " ";
			}
			
		}
		cout << endl;
	}
}