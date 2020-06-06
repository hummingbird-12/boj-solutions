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

    int days;
    cin >> days;

    vector < short > duration(days + 1);
    vector < short > reward(days + 1);

    for (int i = 1; i <= days; i++) {
        cin >> duration[i] >> reward[i];
    }

    vector < short > dp(days + 2);
    for (int i = 1; i <= days; i++) {
        // Able to complete
        if (i + duration[i] - 1 <= days) {
            dp[i + duration[i]] = max((int)dp[i + duration[i]], dp[i] + reward[i]);
        }
        // Skip
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << dp[days + 1] << '\n';

    return 0;
}
