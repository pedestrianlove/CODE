#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sales {
	public:
	int id;
	int data[5];
	int sum;
	Sales () {
		cin >> id;
		sum = 0;
		for (int i = 0;i < 5; i++) {
			cin >> data[i];
			sum += data[i];
		}
	}
};

// cmp
bool cmp (Sales &A, Sales &B) {
	return A.sum > B.sum;
}


int main ()
{
	// variables
	int n = 3;
	vector<Sales> sales_list;

	// input
	for (int i = 0;i < n; i++) {
		sales_list.push_back (Sales ());
	}

	// output total per sales (a, b, c)
	for (auto i = sales_list.begin (); i != sales_list.end (); ++i) {
		cout << (i -> sum);
		if (i == (sales_list.end ()-1))	cout << endl;
		else				cout << " ";
	}

	// output total per product / find max
	int max = 0, max_idx;
	for (int i = 0;i  < 5; i++) {
		int sum = 0;
		//get price
		for (auto j = sales_list.begin (); j != sales_list.end (); ++j) {
			sum += (j -> data[i]);
		}

		// record max
		if (max < sum) {
			max = sum;
			max_idx = i;
		}

		// output price
		cout << sum;
		if (i == 4)	cout << endl;
		else		cout << " ";
	}

	// output best selling sales
	sort (sales_list.begin (), sales_list.end (), cmp);
	cout << sales_list[0].id << endl;


	// output best selling product
	cout << (char)('A' + max_idx) << endl;





}
