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
	string s; cin >> s;
	char temp;
	for (int i = 1; i < s.size(); i += 2) {
		temp = s[i];
		s[i] = s[i - 1];
		s[i - 1] = temp;
	}
	cout << s << endl;
}
