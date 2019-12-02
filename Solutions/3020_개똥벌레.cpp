#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

constexpr int BOTTOM = 0;
constexpr int TOP = 1;

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector < int > count[2]; // count obstacles in top and bottom per height
    vector < int > obstacles;
    int n, h, obs;
    int bottom, top;
    int current = BOTTOM; // 0 is bottom, 1 is top

    cin >> n >> h;
    obstacles.resize(h + 1, INT_MAX);
    count[0].resize(h + 1);
    count[1].resize(h + 1);

    for (int i = 0; i < n; i++) {
        cin >> obs;
        count[current][obs]++;
        current = 1 - current;
    }

    bottom = n / 2;
    top = 0;
    for (int i = 1; i <= h; i++) {
        obstacles[i] = bottom + top;
        bottom -= count[BOTTOM][i];
        top += count[TOP][h - i];
    }

    const int minimum = *min_element(obstacles.begin(), obstacles.end());
    int minCount = 0;
    for (auto i : obstacles) {
        if (i == minimum) {
            minCount++;
        }
    }
    cout << minimum << ' ' << minCount << '\n';

    return 0;
}
