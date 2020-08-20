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

constexpr int MAX = 100'001;

int dp[MAX];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, num;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }

    int s, e;
    while (m--) {
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << '\n';
    }

    return 0;
}
