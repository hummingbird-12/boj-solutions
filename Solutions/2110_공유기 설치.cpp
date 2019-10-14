#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector < int > house;

bool placedAll(int d, int c) {
    int prev = house.front();
    c--;

    for (int i : house) {
        if (i >= prev + d) {
            c--;
            prev = i;
        }
        if (!c) {
            break;
        }
    }

    return c ? false : true;
}

int binarySearch(int l, int r, int c) {
    int mid;
    int maxDist = -1;

    while (l <= r) {
        mid = (l + r) / 2;

        if (placedAll(mid, c)) {    // was able to place all routers
            l = mid + 1;
            maxDist = max(maxDist, mid);
        }
        else {                      // was unable to place all routers
            r = mid - 1;
        }
    }

    return maxDist;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, c, h;
    int opt;

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> h;
        house.push_back(h);
    }
    sort(house.begin(), house.end());
    opt = (house.back() - house.front()) / (c - 1);

    cout << binarySearch(1, opt, c) << '\n';

    return 0;
}
