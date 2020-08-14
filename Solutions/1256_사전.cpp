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

long long dp[201][101] = { { 1 } };

long long comb(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }

    if (dp[n][r] != 0) {
        return dp[n][r];
    }

    const long long lcomb = comb(n - 1, r - 1);
    const long long rcomb = comb(n - 1, r);

    return (dp[n][r] = (lcomb > 1'000'000'000 - rcomb ? 1'000'000'001 : lcomb + rcomb));
}

void query(int a_cnt, int z_cnt, string& word, long long order) {
    if (a_cnt == 0 || z_cnt == 0) {
        while (a_cnt--) {
            word.push_back('a');
        }
        while (z_cnt--) {
            word.push_back('z');
        }
        cout << word << '\n';
        return;
    }

    const long long left = comb(a_cnt + z_cnt - 1, z_cnt);
    const long long right = (z_cnt > 0 ? comb(a_cnt + z_cnt - 1, z_cnt - 1) : 1);

    if (order <= left) {
        word.push_back('a');
        query(a_cnt - 1, z_cnt, word, order);
    }
    else {
        word.push_back('z');
        query(a_cnt, z_cnt - 1, word, order - left);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    if (comb(n + m, n) < k) {
        cout << -1 << '\n';
        return 0;
    }

    string word;
    query(n, m, word, k);

    return 0;
}
