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

vector < int > tree;

long long calcWood(int cut) {
    long long wood = 0;

    for (int t : tree) {
        if (t > cut) {
            wood += t - cut;
        }
    }
    return wood;
}

int binarySearch(int l, int r, int m) {
    int mid, cut = 0;
    long long wood, minWood = LLONG_MAX;

    while (l <= r) {
        mid = (l + r) / 2;
        wood = calcWood(mid);

        if (wood > m) {          // cut more than needed
            l = mid + 1;         // increase cut height
            if (wood < minWood) {
                minWood = wood;
                cut = mid;
            }
        }
        else if (wood < m) {     // cut less than needed
            r = mid - 1;         // decrease cut height
        }
        else {                  // cut exactly what's needed
            return mid;
        }
    }
    return cut;

}

int main() {
    int n, m, t;
    int mn = INT_MAX, mx = INT_MIN;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        tree.push_back(t);

        mx = max(mx, t);
        mn = min(mn, t);
    }

    printf("%d\n", binarySearch(0, mx, m));
    return 0;
}
