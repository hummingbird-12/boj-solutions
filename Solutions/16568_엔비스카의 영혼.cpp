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

constexpr int MAX = 1000001;
constexpr int CUT_SKILLS = 2;

int dp[MAX];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int inLine, cuts[CUT_SKILLS];
    cin >> inLine >> cuts[0] >> cuts[1];

    int i, j;
    for (i = 1; i <= inLine; i++) {
        dp[i] = i;
        for (j = 0; j < CUT_SKILLS; j++) {
            if (i > cuts[j]) {
                dp[i] = min(dp[i], dp[i - cuts[j] - 1] + 1);
            }
        }
    }
    cout << dp[inLine] << '\n';

    return 0;
}
