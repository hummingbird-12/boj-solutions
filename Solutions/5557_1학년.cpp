#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

long long calculateSums(const vector < short >& numbers) {
    constexpr short MAX_SUM = 20;
    constexpr short MIN_SUM = 0;
    /// dp[i][j]: the number of cases in which the cumulative sum till
    /// number at index `i` is `j`.
    vector < vector < long long > > dp;
    dp.resize(numbers.size() - 1);

    dp[0] = vector < long long >(MAX_SUM - MIN_SUM + 1, 0);
    dp[0][numbers[0]] = 1;

    for (int i = 1; i < dp.size(); i++) {
        dp[i] = vector < long long >(MAX_SUM - MIN_SUM + 1, 0);
        for (int j = MIN_SUM; j <= MAX_SUM; j++) {
            if (j - numbers[i] >= MIN_SUM) {
                dp[i][j] += dp[i - 1][j - numbers[i]];
            }
            if (j + numbers[i] <= MAX_SUM) {
                dp[i][j] += dp[i - 1][j + numbers[i]];
            }
        }
    }

    return dp.back()[numbers.back()];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, num;
    vector < short > numbers;

    cin >> n;
    numbers.reserve(n);

    while (n--) {
        cin >> num;
        numbers.push_back(num);
    }
    cout << calculateSums(numbers) << '\n';

    return 0;
}
