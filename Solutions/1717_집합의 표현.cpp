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

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1, -1);

    int op, x, y;
    while (m--) {
        cin >> op >> x >> y;
        if (op == 0) {
            _union(x, y);
        }
        else {
            cout << (_find(x) == _find(y) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
