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
    vector < int > tree;
    int leaf_start;

public:
    SegmentTree(int n) {
        tree.resize(n * 4, 0);

        // Calculate the index where leaves start
        leaf_start = 1;
        while (leaf_start < n) {
            leaf_start *= 2;
        }
    }

    /*
     * Change count of candy of taste `i` by `n`
     */
    void update(int i, int n) {
        int index = leaf_start + i - 1;
        tree[index] += n;

        // Propagate change until root
        index /= 2;
        while (index >= 1) {
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
            index /= 2;
        }
    }

    /*
     * Get taste number of n-th candy
     */
    int query(int n, int index = 1) {
        // If query reached a leaf node
        if (index >= leaf_start) {
            return index - leaf_start + 1;
        }

        // If n-th candy is within left sub-tree
        if (n <= tree[index * 2]) {
            return query(n, index * 2);
        }
        // If n-th candy is within right sub-tree
        else {
            return query(n - tree[index * 2], index * 2 + 1);
        }
    }

    int get_nth_candy(const int n) {
        return query(n);
    }
};

SegmentTree* tree = new SegmentTree(1'000'000);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a, b, c;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            c = tree->get_nth_candy(b);
            cout << c << '\n';
            tree->update(c, -1);
        }
        else {
            cin >> b >> c;
            tree->update(b, c);
        }
    }

    return 0;
}
