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
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    short n, m;
    vector < short > a;

    cin >> n;
    a.reserve(n);
    vector < short > dp(n, (short) 1);

    while (n--) {
        cin >> m;
        a.push_back(m);
    }

    for (auto it = a.rbegin(), itDP = dp.rbegin(); it != a.rend(); it++, itDP++) {
        for (auto it2 = a.rbegin(), it2DP = dp.rbegin(); it2 != it; it2++, it2DP++) {
            if (*it2 < *it) {
                *itDP = max(*itDP, (short) (*it2DP + 1));
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
