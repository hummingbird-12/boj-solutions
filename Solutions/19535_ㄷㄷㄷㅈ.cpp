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

vector < vector < int > > graph;
vector < pair < int, int > > edges;

inline long long comb3(long long n) {
    return (n * (n - 1) * (n - 2)) / 6;
}

inline long long count_g(int n) {
    long long count = 0;
    for (int i = 1; i <= n; i++) {
        count += comb3(graph[i].size());
    }
    return count;
}

inline long long count_d(int n) {
    long long count = 0;
    for (auto e : edges) {
        count += (graph[e.first].size() - 1) * (graph[e.second].size() - 1);
    }
    return count;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n;

    graph.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.emplace_back(a, b);
    }

    long long d_count = count_d(n);
    long long g_count = count_g(n);

    if (d_count == g_count * 3) {
        cout << "DUDUDUNGA\n";
    }
    else if (d_count > g_count * 3) {
        cout << "D\n";
    }
    else {
        cout << "G\n";
    }

    return 0;
}
