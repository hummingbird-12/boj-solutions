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

class SegmentTree {
    vector < long long > tree;
    int leaf_start;

    /*
     * Fills the tree starting from leaves, then upwards
     */
    void fill_tree(const vector < int >& numbers) {
        int i = leaf_start;
        for (const int& n : numbers) {
            tree[i++] = n;
        }

        for (int i = leaf_start - 1; i >= 1; i--) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    /*
     * Segment sum query
     */
    long long query(
        const int qleft, const int qright,
        const int tstart, const int tend, const int current = 1) {
        // Encompassed within query range
        if (qleft <= tstart && tend <= qright) {
            return tree[current];
        }

        // Out of query range
        if (qright < tstart || tend < qleft) {
            return 0;
        }

        const int mid = (tstart + tend) / 2;
        return
            query(qleft, qright, tstart, mid, current * 2) +
            query(qleft, qright, mid + 1, tend, current * 2 + 1);
    }

public:
    SegmentTree(const vector < int >& numbers) {
        const int n = numbers.size();
        tree.resize(n * 4, 0);

        leaf_start = 1;
        while (leaf_start < n) {
            leaf_start *= 2;
        }

        fill_tree(numbers);
    }

    void update(const int index, const int n) {
        int i = leaf_start + index - 1;
        tree[i] = n;

        // Propagate update upwards
        i /= 2;
        while (i >= 1) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
            i /= 2;
        }
    }

    long long ask(const int x, const int y) {
        return (x <= y ? query(x, y, 1, leaf_start) : query(y, x, 1, leaf_start));
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector < int > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegmentTree* tree = new SegmentTree(v);

    int x, y, a, b;
    while (q--) {
        cin >> x >> y;
        cout << tree->ask(x, y) << '\n';
        cin >> a >> b;
        tree->update(a, b);
    }

    return 0;
}
