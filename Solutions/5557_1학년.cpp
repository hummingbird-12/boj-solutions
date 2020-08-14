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

constexpr int MIN = 0;
constexpr int MAX = 20;

long long dp[99][21];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int d;
    cin >> d;
    dp[0][d] = 1;
    for (int i = 1; i < n - 1; i++) {
        cin >> d;
        for (int j = MIN; j <= MAX; j++) {
            // Able to substract current number
            if (j - d >= MIN) {
                dp[i][j] += dp[i - 1][j - d];
            }
            // Able to add current number
            if (j + d <= MAX) {
                dp[i][j] += dp[i - 1][j + d];
            }
        }
    }

    cin >> d;
    cout << dp[n - 2][d] << '\n';

    return 0;
}
