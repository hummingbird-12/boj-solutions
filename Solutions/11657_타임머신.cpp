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

constexpr long long INF = (1ll << 40);

vector < pair < pair < int, int >, int > > edges;
vector < long long > dist;

void bellman_ford(const int nodes, const int start) {
    dist[start] = 0;

    for (int i = 1; i < nodes; i++) {
        for (const auto& e : edges) {
            const int& from = e.first.first;
            const int& to = e.first.second;
            const int& cost = e.second;

            // Prevent overflow
            if (dist[from] != INF && dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
            }
        }
    }
}

bool test_neg_cycle() {
    for (const auto& e : edges) {
        const int& from = e.first.first;
        const int& to = e.first.second;
        const int& cost = e.second;

        // Prevent overflow
        if (dist[from] != INF && dist[from] + cost < dist[to]) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    edges.resize(m);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }

    bellman_ford(n, 1);

    if (test_neg_cycle()) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= n; i++) {
            cout << (dist[i] != INF ? dist[i] : -1) << '\n';
        }
    }

    return 0;
}
