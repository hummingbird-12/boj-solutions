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

vector < vector < pair < int, int > > > graph;
vector < int > dist;

void dijkstra(const int start) {
    priority_queue <
        pair < int, int >,
        vector < pair < int, int > >,
        greater < pair < int, int > >
    > pq;

    pq.emplace(0, start);

    while (!pq.empty()) {
        const int distance = pq.top().first;
        const int cur = pq.top().second;

        if (distance < dist[cur]) {
            dist[cur] = distance;

            for (const auto& edge : graph[cur]) {
                const int& next = edge.first;
                const int& cost = edge.second;

                if (distance + cost < dist[next]) {
                    pq.emplace(distance + cost, next);
                }
            }
        }

        pq.pop();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int vertices, edges, start;
    cin >> vertices >> edges >> start;

    graph.resize(vertices + 1);
    dist.resize(vertices + 1, INT_MAX);

    int u, v, w;
    while (edges--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    dijkstra(start);

    for (int i = 1; i <= vertices; i++) {
        cout << (dist[i] != INT_MAX ? to_string(dist[i]) : "INF") << '\n';
    }

    return 0;
}
