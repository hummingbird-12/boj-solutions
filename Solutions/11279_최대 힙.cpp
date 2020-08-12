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

class min_heap {
    const int ROOT = 1;
    vector < int > tree;
    int last;

    void swap_by_index(int index1, int index2) {
        int temp = tree[index1];
        tree[index1] = tree[index2];
        tree[index2] = temp;
    }

public:
    min_heap(int n) {
        tree.resize(n + 1);
        last = 0;
    }

    void insert(int n) {
        tree[++last] = n;

        int index = last;
        // Repeatedly swap with smaller parent
        while (index > ROOT && tree[index / 2] < tree[index]) {
            swap_by_index(index, index / 2);
            index /= 2;
        }
    }

    int pop() {
        if (last == 0) {
            return 0;
        }

        int ret = tree[ROOT];
        tree[ROOT] = tree[last--];

        int index = ROOT;
        // Repeatedly swap with bigger child
        while (index * 2 <= last) {
            int l = tree[index * 2];
            int r = (index * 2 + 1 <= last ? tree[index * 2 + 1] : -1);

            // Swap with left child
            if (l > r && l > tree[index]) {
                swap_by_index(index, index * 2);
                index *= 2;
            }
            // Swap with right child
            else if (r > tree[index]) {
                swap_by_index(index, index * 2 + 1);
                index = index * 2 + 1;
            }
            else {
                break;
            }
        }

        return ret;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    min_heap mh = min_heap(n);

    int inp;
    while (n--) {
        cin >> inp;
        if (inp == 0) {
            cout << mh.pop() << '\n';
        }
        else {
            mh.insert(inp);
        }
    }

    return 0;
}
