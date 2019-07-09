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

vector < vector < short > > dp;

int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2;

    cin >> s1 >> s2;

    dp.resize(s1.size() + 1, vector < short > (s2.size() + 1, 0));
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[i].size(); j++) {
            // match
            if (s1[i - 1] == s2[j - 1]) {
                /*
                    +1 from c1 and c2 excluded
                */
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // no match
            else {
                /*
                    max between:
                    1. LCS with c1 included and before c2
                    2. LCS with c1 excluded and until c2
                */
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp.back().back() << endl;

    return 0;
}
