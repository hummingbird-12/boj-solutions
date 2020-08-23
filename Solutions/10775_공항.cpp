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
    const int par_x = _find(x);
    const int par_y = _find(y);

    if (par_x != par_y) {
        parent[par_y] = par_x;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int g, planes;
    cin >> g >> planes;

    parent.resize(g + 1, -1);

    int cnt = 0;
    while (planes--) {
        cin >> g;

        const int assign_to = _find(g);
        if (assign_to == 0) {
            break;
        }

        _union(assign_to - 1, assign_to);
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
