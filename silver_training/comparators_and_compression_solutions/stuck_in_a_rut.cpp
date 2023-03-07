/* 
DOES NOT WORK, NEED TO REVISE
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#pragma warning(suppress : 4496)
typedef long long ll;
using namespace std;

void setIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdin);
}

struct cow {
	int x, y; 
	int cows_stopped;
	bool operator==(const cow& c) {
		return cows_stopped == c.cows_stopped && c.x == x && c.y == y;
	}
};

struct collision {
	int i_north, i_east;
	int t;
	bool operator<(const collision &c) { return t < c.t; }
};

int main() {
	//read information
	int n; cin >> n;
	vector<cow> north_cows, east_cows;
	vector<collision> collisions;
	vector<pair<bool, int>> order;
	char direction;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> direction >> x >> y;
		cow c = { x, y, 0 };
		if (direction == 'N') {
			north_cows.push_back(c);
			order.push_back({ true, north_cows.size() - 1 });
		}
		else {
			east_cows.push_back(c); 
			order.push_back({ false, east_cows.size() - 1 });
		}
	}

	//find all collisions
	int t;
	for (int i = 0; i < north_cows.size(); i++) {
		for (int j = 0; j < east_cows.size(); j++) {
			cow north_cow = north_cows[i], east_cow = east_cows[j];
			if (north_cow.x < east_cow.x || east_cow.y < north_cow.y) continue;
			if (north_cow.x - east_cow.x == east_cow.y - north_cow.y) continue;
			t = max(north_cow.x - east_cow.x, east_cow.y - north_cow.y);
			collisions.push_back({i, j, t});
		}
	}
	sort(collisions.begin(), collisions.end());

	//process collisions
	set<int> north_cows_stopped, east_cows_stopped;
	for (collision c : collisions) {
		if (north_cows_stopped.find(c.i_north) != north_cows_stopped.end()) continue;
		if (east_cows_stopped.find(c.i_east) != east_cows_stopped.end()) continue;
		bool east_cow_stopped = false;
		cow* stopping_cow, * stopped_cow;
		if (north_cows[c.i_north].x - east_cows[c.i_east].x == c.t) {
			stopped_cow = &east_cows[c.i_east];
			stopping_cow = &north_cows[c.i_north];
			east_cow_stopped = true;
		}
		else {
			stopped_cow = &north_cows[c.i_north];
			stopping_cow = &east_cows[c.i_east];
		}

		stopping_cow->cows_stopped += 1 + stopped_cow->cows_stopped;
		if (east_cow_stopped) east_cows_stopped.insert(find(east_cows.begin(), east_cows.end(), (*stopped_cow)) - east_cows.begin());
		else north_cows_stopped.insert(find(north_cows.begin(), north_cows.end(), (*stopped_cow)) - north_cows.begin());
	}

	for (auto pair : order) {
		if (pair.first) cout << north_cows[pair.second].cows_stopped << endl;
		else cout << east_cows[pair.second].cows_stopped << endl;
	}
}
