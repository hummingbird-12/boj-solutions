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

    int n;
    vector < int > v;
    vector < int > dp;

    cin >> n;
    v.resize(n);
    dp.resize(n, INT_MAX);

    cin >> v[0];
    dp[0] = 0;
    for (int j = 1; j < dp.size() && j <= v[0]; j++) {
        dp[j] = min(dp[j], dp[0] + 1);
    }

    for (int i = 1; i < n; i++) {
        cin >> v[i];
        if (dp[i] == INT_MAX) {
            continue;
        }
        for (int j = 1; i + j < dp.size() && j <= v[i]; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    cout << (dp.back() == INT_MAX ? -1 : dp.back()) << '\n';

    return 0;
}
