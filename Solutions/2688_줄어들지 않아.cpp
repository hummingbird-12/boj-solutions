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

long long dp[65][10];

void preprocess() {
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 1; i < 64; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                dp[i + 1][k] += dp[i][j];
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    preprocess();

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        long long ans = 0;
        cin >> n;

        for (int i = 0; i <= 9; i++) {
            ans += dp[n][i];
        }

        cout << ans << '\n';
    }
    return 0;
}
