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

vector < int > incoming_count;
vector < vector < int > > graph;
vector < pair < int, int > > edges;
unordered_map < int, int > mapper;

inline int get_index(int u) {
    if (mapper.find(u) != mapper.end()) {
        return mapper[u];
    }
    return (mapper[u] = mapper.size());
}

bool check_tree_bfs(int start, int n) {
    queue < int > q;
    vector < bool > visited(n);

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        for (int next : graph[q.front()]) {
            if (visited[next]) {
                return false;
            }
            q.push(next);
            visited[next] = true;
        }
        q.pop();
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int u, v, tc = 1;

    while (true) {
        cin >> u >> v;
        if (u < 0 && v < 0) {
            break;
        }

        if (u == 0 && v == 0) {
            cout << "Case " << tc++ << " is a tree.\n";
            continue;
        }

        do {
            edges.emplace_back(get_index(u), get_index(v));
            cin >> u >> v;
        } while (u != 0 || v != 0);

        int n = mapper.size();
        incoming_count.resize(n);
        graph.resize(n);
        for (auto e : edges) {
            graph[e.first].push_back(e.second);
            incoming_count[e.second]++;
        }

        bool check = true;
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (incoming_count[i] == 0) {
                if (root != -1) {
                    check = false;
                    break;
                }
                root = i;
            }
            else if (incoming_count[i] > 1) {
                check = false;
                break;
            }
        }
        if (root == -1) {
            check = false;
        }

        cout << "Case " << tc++ << " is " <<
            (check && check_tree_bfs(root, n) ? "" : "not ")
            << "a tree.\n";

        graph.clear();
        mapper.clear();
        edges.clear();
        incoming_count.clear();
    }
    return 0;
}
