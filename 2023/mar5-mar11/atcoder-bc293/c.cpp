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
	int h, w; cin >> h >> w;
	vector<vector<int>> grid(h, vector<int>(w));
	for (int i = 0; i < h; i++) 
		for (int j = 0; j < w; j++)
			cin >> grid[i][j];
	
	//check all paths
	//1 is down, 0 is right
	int ans = 0;
	for (int mask = 0; mask < (1 << (h + w) - 2); mask++) {
		//check if this is a valid path
		int ones = 0;

		for (int i = 0; i < h + w; i++) {
			if (mask & (1 << i)) ones++;
		}

		if (ones != h - 1) continue;

		bool isDistinctPath = true;
		int x = 0, y = 0;
		set<int> numbers{ grid[y][x] };
		for (int i = 0; i < h + w - 2; i++) {
			if (mask & (1 << i)) y++;
			else x++;

			if (numbers.find(grid[y][x]) != numbers.end()) { isDistinctPath = false; break; }
			
			numbers.insert(grid[y][x]);
		}

		if (isDistinctPath) ans++;
	}

	cout << ans;
}
