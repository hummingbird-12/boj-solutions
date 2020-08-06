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

constexpr int MAX = 2001;
constexpr int IMP = -1;

int dp[MAX][MAX]; // dp[i][j] : max score when `i` cards remain on the left deck and `j` cards remain on the right deck
vector < int > lcard;
vector < int > rcard;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    lcard.resize(n);
    rcard.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lcard[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> rcard[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = (
            dp[0][i - 1] != IMP && rcard[i - 1] < lcard[0] ?
            dp[0][i - 1] + rcard[i - 1] :
            IMP);
    }

    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            // Max score followed by withdrawing from both decks or withdrawing from left deck only
            dp[l][r] = max(dp[l - 1][r - 1], (r < n ? dp[l - 1][r] : IMP));
            // Update max score followed by withdrawing from right deck only, if possible
            if (l < n && rcard[r - 1] < lcard[l] && dp[l][r - 1] != IMP) {
                dp[l][r] = max(dp[l][r], dp[l][r - 1] + rcard[r - 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
        ans = max(ans, dp[i][n]);
    }

    cout << ans << '\n';

    return 0;
}
