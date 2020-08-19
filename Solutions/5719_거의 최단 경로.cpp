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
vector < vector < int > > shortest_paths; // Saves parent for each node within shortest path

int dijkstra(const int n, const int start, const int dest) {
    priority_queue <
        pair < int, int >,
        vector < pair < int, int > >,
        greater < pair < int, int > >
    > pq;
    vector < int > distance(n, INT_MAX);

    pq.emplace(0, start);
    distance[start] = 0;

    while (!pq.empty()) {
        const int cur = pq.top().second;

        for (const auto& edge : graph[cur]) {
            const int& next = edge.first;
            const int& cost = edge.second;

            // Edge was removed
            if (cost == -1) {
                continue;
            }

            // Edge is possibly part of a shortest path
            if (distance[cur] == distance[next] - cost) {
                shortest_paths[next].push_back(cur);
            }

            // Update shortest distance and path
            if (distance[cur] < distance[next] - cost) {
                distance[next] = distance[cur] + cost;
                pq.emplace(distance[cur] + cost, next);

                shortest_paths[next].clear();
                shortest_paths[next].push_back(cur);
            }
        }

        pq.pop();
    }

    return (distance[dest] == INT_MAX ? -1 : distance[dest]);
}

/*
 * Go backwards starting from destination, marking edges in the shortest path as removed
 */
void remove_shortest_paths(const int destination) {
    queue < int > q;

    q.push(destination);

    while (!q.empty()) {
        const int& cur = q.front();

        for (const int& par : shortest_paths[cur]) {
            auto& edge = *find_if(graph[par].begin(), graph[par].end(),
                [cur](const pair < int, int >& e) -> bool { return e.first == cur; });
            edge.second = -1; // Mark edge as removed

            q.push(par);
        }

        q.pop();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, start, destination, u, v, p;

    cin >> n >> m;
    while (n != 0 || m != 0) {
        graph.resize(n);
        shortest_paths.resize(n);

        cin >> start >> destination;
        while (m--) {
            cin >> u >> v >> p;
            graph[u].emplace_back(v, p);
        }

        dijkstra(n, start, destination);
        remove_shortest_paths(destination);
        cout << dijkstra(n, start, destination) << '\n';

        graph.clear();
        shortest_paths.clear();

        cin >> n >> m;
    }

    return 0;
}
