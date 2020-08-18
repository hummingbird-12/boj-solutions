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

priority_queue <
    pair < int, pair < int, int > >,
    vector < pair < int, pair < int, int > > >,
    greater < pair < int, pair < int, int > > >
> pq;
vector < int > parent;

int _find(const int x) {
    if (parent[x] == -1) {
        return x;
    }
    return (parent[x] = _find(parent[x]));
}

void _union(const int x, const int y) {
    const int x_parent = _find(x);
    const int y_parent = _find(y);

    if (x_parent != y_parent) {
        parent[y_parent] = x_parent;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, u, v, cost;
    cin >> n >> m;

    parent.resize(n + 1, -1);

    while (m--) {
        cin >> u >> v >> cost;
        pq.emplace(cost, make_pair(u, v));
    }

    int sum = 0;
    while (!pq.empty()) {
        const auto& cur_cost = pq.top().first;
        const auto& cur_u = pq.top().second.first;
        const auto& cur_v = pq.top().second.second;

        if (_find(cur_u) != _find(cur_v)) {
            _union(cur_u, cur_v);
            sum += cur_cost;
        }

        pq.pop();
    }

    cout << sum << '\n';

    return 0;
}
