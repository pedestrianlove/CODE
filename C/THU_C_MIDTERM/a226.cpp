#include <iostream>
#include <algorithm>

using namespace std;




int main ()
{
	int n, all_pass, all_failed, max_failed, min_pass;
	int* data;
	
	while (cin >> n) {
		all_pass = 1, all_failed = 1;
		max_failed = -1, min_pass = 101;
		// input
		data = new int[n];
		for (int i = 0;i < n; i++) cin >> data[i];

		// sort
		sort (data, data + n);

		// output grade
		for (int i = 0;i < n; i++) {
			if (data[i] >= 60) {
				if (data[i] < min_pass) min_pass = data[i];
				all_failed = 0;
			}else {
				if (data[i] > max_failed) max_failed = data[i];
				all_pass = 0;
			}


			cout << data[i];
			if (i == (n-1)) cout << endl;
			else		cout << ' ';
		}

		// output min/max
		if (max_failed != -1) {
			cout << max_failed << endl;
		}
		else {
			cout << "best case" << endl;
		}

		if (min_pass != 101) {
			cout << min_pass << endl;
		}
		else {
			cout << "worst case" << endl;
		}


	}
	
}