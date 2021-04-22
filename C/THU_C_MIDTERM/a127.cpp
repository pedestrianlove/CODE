#include <iostream>

using namespace std;

int main ()
{
	int a, b;
	while (cin >> a >> b) {
		if ((a != 0) && (b != 0)) {
			cout << a+b << " " << a/b << endl;
		}
	}
}