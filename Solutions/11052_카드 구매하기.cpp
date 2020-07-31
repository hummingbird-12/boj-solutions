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

int dp[1001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, c, i, j;
    cin >> n;

    cin >> c;
    for (i = 1; i <= n; i++) {
        dp[i] = c * i;
    }

    for (i = 2; i <= n; i++) {
        cin >> c;
        for (j = i; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - i] + c);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
