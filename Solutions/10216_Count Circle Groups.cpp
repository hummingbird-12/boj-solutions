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

vector < pair < pair < int, int >, int > > camps;
int parent[3000];
bool cnt[3000];

int _find(int u) {
    if (parent[u] == -1) {
        return u;
    }
    return (parent[u] = _find(parent[u]));
}

void _union(int u, int v) {
    int vpar = _find(v);
    if (_find(u) != vpar) {
        parent[vpar] = u;
    }
}

inline int dist_sq(pair < int, int > x, pair < int, int > y) {
    int first = y.first - x.first;
    int second = y.second - x.second;
    return first * first + second * second;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, x, y, r, r_sum;
        fill(parent, parent + 3000, -1);

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            camps.emplace_back(make_pair(x, y), r);
            for (int j = 0; j < i; j++) {
                r_sum = r + camps[j].second;
                if (dist_sq(camps[i].first, camps[j].first) <= r_sum * r_sum) {
                    _union(i, j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            x = _find(i);
            if (!cnt[x]) {
                ans++;
                cnt[x] = true;
            }
        }

        cout << ans << '\n';

        camps.clear();
        fill(cnt, cnt + 3000, false);
    }
    return 0;
}
