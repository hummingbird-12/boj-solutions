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

vector < int > arr_a;
vector < int > arr_b;
vector < int > sums_a;
vector < int > sums_b;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n, m;
    cin >> t;

    cin >> n;
    arr_a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr_a[i];
        int s = 0;
        for (int j = i; j >= 0; j--) {
            s += arr_a[j];
            sums_a.push_back(s);
        }
    }
    sort(sums_a.rbegin(), sums_a.rend());

    cin >> m;
    arr_b.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> arr_b[i];
        int s = 0;
        for (int j = i; j >= 0; j--) {
            s += arr_b[j];
            sums_b.push_back(s);
        }
    }
    sort(sums_b.begin(), sums_b.end());

    long long cnt = 0;
    for (int sa : sums_a) {
        auto up = upper_bound(sums_b.begin(), sums_b.end(), t - sa);
        auto lw = lower_bound(sums_b.begin(), sums_b.end(), t - sa);
        if (lw == sums_b.end()) {
            break;
        }
        cnt += up - lw;
    }
    cout << cnt << '\n';

    return 0;
}
