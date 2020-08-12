#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;

    vector < int > upwards_cnt(h + 1);
    vector < int > downwards_cnt(h + 1);

    int height;
    // While receving input, count per height
    for (int i = 0; i < n / 2; i++) {
        cin >> height;
        upwards_cnt[height]++;
        cin >> height;
        downwards_cnt[height]++;
    }

    int upwards_obstacles = n / 2; // All upwards obstacles initially block height=1
    int downwards_obstacles = 0; // No downwards obstacle initially block height=1
    vector < int > obstacles(h + 1);
    int mn = INT_MAX;
    for (int i = 1; i <= h; i++) {
        mn = min(mn, (obstacles[i] = upwards_obstacles + downwards_obstacles));
        upwards_obstacles -= upwards_cnt[i]; // As height increases, upwards obstacles reduce
        downwards_obstacles += downwards_cnt[h - i]; // As height increases, downwards obstacles increase
    }

    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        if (obstacles[i] == mn) {
            cnt++;
        }
    }

    cout << mn << ' ' << cnt << '\n';

    return 0;
}
