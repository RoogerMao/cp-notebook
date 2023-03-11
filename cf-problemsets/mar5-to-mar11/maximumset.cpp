#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		int max_size = log2(r / l) + 1, max_num = 0;
		//find sets of max size w/ no values of d = 3
		max_num += r / pow(2, max_size - 1) - l + 1;

		//find sets of max size w/ one value of d = 3
		if (max_size > 1) max_num += (max_size - 1) * max(0, (r / (int)pow(2, max_size - 2) / 3 - l + 1));

		cout << max_size << " " << max_num << endl;
	}
}
