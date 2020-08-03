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

vector < string > rows;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    rows.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> rows[i];
    }

    string order;
    cin >> order;

    int l, r;
    long long cnt = 0;
    l = r = m - 1;

    auto it = order.rbegin();
    string& cur = rows[*it - 'A'];
    while (l - 1 >= 0 && cur[l - 1] == 'R') {
        l--;
    }
    cnt += r - l + 1;
    for (it++; it != order.rend(); it++) {
        string& cur = rows[*it - 'A'];
        while (r >= 0 && cur[r] == 'R') {
            r--;
        }

        if (r < l) {
            break;
        }

        while (l - 1 >= 0 && cur[l - 1] == 'R') {
            l--;
        }

        cnt += r - l + 1;
    }
    cout << cnt << '\n';

    return 0;
}
