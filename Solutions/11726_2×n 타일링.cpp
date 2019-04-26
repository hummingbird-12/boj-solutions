#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define MOD 10007

/*
 * dp[i][0] : fill in i-th column with 2x1 piece
 * dp[i][1] : fill in i-th column with 1x2 pieces
 */
int dp[1001][2];

int main() {
    int n, calc;

    scanf("%d", &n);

    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        calc = (dp[i - 1][0] + dp[i - 2][1]) % MOD;
        dp[i][0] = calc;
        dp[i][1] = calc;
    }

    printf("%d\n", (dp[n][0] + dp[n - 1][1]) % MOD);
    return 0;
}
