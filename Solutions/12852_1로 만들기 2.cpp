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

constexpr int MAX_N = 1'000'001;

int dp[MAX_N];
int previous[MAX_N];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = n - 1; i >= 1; i--) {
        dp[i] = INT_MAX;
        if (i * 3 <= n) {
            dp[i] = dp[i * 3] + 1;
            previous[i] = i * 3;
        }
        if (i * 2 <= n && dp[i * 2] + 1 < dp[i]) {
            dp[i] = dp[i * 2] + 1;
            previous[i] = i * 2;
        }
        if (dp[i + 1] + 1 < dp[i]) {
            dp[i] = dp[i + 1] + 1;
            previous[i] = i + 1;
        }
    }

    cout << dp[1] << '\n';

    stack < int > s;
    int i = 1;
    while (i != 0) {
        s.push(i);
        i = previous[i];
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    return 0;
}
