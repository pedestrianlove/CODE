#include <iostream>

using namespace std;

int corres (char X) {
	if ((X - 'A') / 3 <= 4)
		return ((X - 'A')/3) + 2;
	else {
		if ((X >= 'P') && (X <= 'S'))
			return 7;
		else if ((X >= 'T') && (X <= 'V'))
			return 8;
		else if ((X >= 'W') && (X <= 'Z'))
			return 9;
		else
			return -1;
	}
}


int main ()
{
	int counter, len, hyphen_counter;;
	string s;
	while (cin >> s) {
		counter = 0, hyphen_counter = 0;
		len = s.length ();
		for (int i = 0;i < len; i++) {
			if ((s[i] >= 'A') && (s[i] <= 'Z')) {
				counter ++;
				cout << corres (s[i]);
			}
			else if (s[i] == '-'){
				hyphen_counter ++;
				cout << s[i];
			}
			else
				cout << s[i];
		}
		// output number of alphabets
		cout << " " << counter << " ";

		// output number of hyphens
		cout << hyphen_counter << endl;
	}
	
}