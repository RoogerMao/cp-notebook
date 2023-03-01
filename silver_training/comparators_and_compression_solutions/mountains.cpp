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
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    map<int, int> peaks;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        if (y - x > peaks[x + y] || peaks[x + y] == 0) peaks[x + y] = y - x;
    }
    //point to second element from end in array
    int max_diff = INT32_MIN;
    int visiblePeaks = 0;
    for (auto it = peaks.rbegin(); it != peaks.rend(); it++) {
        auto pair = (*it);
        if (pair.second > max_diff) {
            max_diff = pair.second; 
            visiblePeaks++;
        }
        pair.second = max_diff;
    }

    cout << visiblePeaks;
}
