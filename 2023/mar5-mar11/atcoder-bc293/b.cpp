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
	int n; cin >> n;
	vector<int> co(n);
	vector<bool> c(n, false);
	for (int i = 0; i < n; i++) cin >> co[i];

	for (int i = 0; i < n; i++) {
		if (!c[i]) c[co[i] - 1] = true;
	}

	int nc = 0;
	for (bool b : c) if (!b) nc++;
	cout << nc << endl;
	for (int i = 0; i < n; i++) if (!c[i]) cout << i + 1 << " ";
}
