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
 * dp[i] : number of combination until i-th column
 */
int dp[1002];

int main() {
    int n;

    scanf("%d", &n);

    dp[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    printf("%d\n", dp[n + 1]);
    return 0;
}
