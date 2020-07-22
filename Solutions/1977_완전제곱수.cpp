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

    int m, n, rt;
    int mn = INT_MAX, sum = 0;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        rt = sqrt(i);
        if (rt * rt == i) {
            sum += i;
            mn = min(mn, i);
        }
    }

    if (sum == 0) {
        cout << "-1\n";
        return 0;
    }

    cout << sum << '\n';
    cout << mn << '\n';

    return 0;
}
