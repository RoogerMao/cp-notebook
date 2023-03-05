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
	map<int, int> a, c;
	vector<int> b (n);
	for (int i = 0; i < n; i++) { int ai; cin >> ai; a[ai]++; }
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) { int ci; cin >> ci; c[ci]++; }

	ll pairs = 0;
	for (auto pair : c) {
		if (a.find(b[pair.first - 1]) != a.end()) pairs += pair.second * a[b[pair.first - 1]];
	}

	cout << pairs;
}
