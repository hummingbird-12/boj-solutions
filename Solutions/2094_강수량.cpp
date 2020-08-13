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

class Node {
public:

    pair < int, int > range;
    pair < int, int > max_value;

    Node() {
        range = make_pair(0, 0);
        max_value = make_pair(0, 0);
    }

    Node(const int left, const int right,
        const int year, const int value) {
        range = make_pair(left, right);
        max_value = make_pair(year, value);
    }
};

class SegmentTree {
    vector < Node > tree;
    unordered_map < int, int > year_to_index;
    int leaf_start;

    void fill_tree(const vector < pair < int, int > >& v) {
        int i = leaf_start;
        for (auto p : v) {
            year_to_index[p.first] = i;
            tree[i].range = make_pair(p.first, p.first);
            tree[i].max_value = make_pair(p.first, p.second);
            i++;
        }

        int last_year = v.back().first;
        for (; i < leaf_start + leaf_start; i++) {
            tree[i].range = make_pair(last_year, last_year++);
            tree[i].max_value = make_pair(0, 0);
        }

        for (int i = leaf_start - 1; i >= 1; i--) {
            const Node& left = tree[i * 2];
            const Node& right = tree[i * 2 + 1];
            tree[i].range = make_pair(left.range.first, right.range.second);
            tree[i].max_value = (
                left.max_value.second >= right.max_value.second ?
                make_pair(left.max_value.first, left.max_value.second) :
                make_pair(right.max_value.first, right.max_value.second)
                );
        }
    }

    pair < int, int > query(const int qstart, const int qend, const int index) {
        const Node& current = tree[index];
        if (qstart <= current.range.first && current.range.second <= qend) {
            return current.max_value;
        }
        if (current.range.second < qstart || qend < current.range.first) {
            return make_pair(0, -1);
        }

        const auto left = query(qstart, qend, index * 2);
        const auto right = query(qstart, qend, index * 2 + 1);

        return (left.second >= right.second ? left : right);
    }

public:
    SegmentTree(const vector < pair < int, int > >& v) {
        const int n = v.size();
        tree.resize(n * 4, Node());

        leaf_start = 1;
        while (leaf_start < n) {
            leaf_start *= 2;
        }

        fill_tree(v);
    }

    void ask(const int y, const int x) {
        bool is_true = true;
        int y_rain = -1;
        int x_rain = -1;

        //
        // 1. Y년도, X년도, 그리고 그 사이의 모든 년도들의 강수량에 대한 정보가 알려져 있다.
        //

        // 1.1. Y년도 확인
        const auto y_index = year_to_index.find(y);
        if (y_index == year_to_index.end()) {
            is_true = false;
        }
        else {
            y_rain = tree[(*y_index).second].max_value.second;
        }

        // 1.2. X년도 확인
        const auto x_index = year_to_index.find(x);
        if (x_index == year_to_index.end()) {
            is_true = false;
        }
        else {
            x_rain = tree[(*x_index).second].max_value.second;
        }

        // 1.3. 사이 년도 확인
        if (is_true && x - y != (*x_index).second - (*y_index).second) {
            is_true = false;
        }

        //
        // 2. X년도의 강수량은 Y년도의 강수량 이하이다.
        //

        if (x_rain >= 0 && y_rain > 0 && x_rain > y_rain) {
            cout << "false\n";
            return;
        }

        //
        // 3. Y < Z < X를 만족하는 모든 Z들에 대해서, Z년도의 강수량은 X년도보다 적다.
        //

        // 강수량의 최소값은 1 이기 때문에 `y_rain`이 1이면 x > y + 1 일때 불가능
        if (y_rain == 1 && x - y > 1) {
            cout << "false\n";
            return;
        }

        const auto zx_max = query(y + 1, x, 1);
        if ((x_rain > 0 && zx_max.first != x) ||
            (y_rain > 1 && zx_max.second >= y_rain)) {
            cout << "false\n";
            return;
        }

        cout << (is_true ? "true" : "maybe") << '\n';
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector < pair < int, int > > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    SegmentTree* tree = new SegmentTree(v);

    int y, x;
    cin >> n;
    while (n--) {
        cin >> y >> x;
        tree->ask(y, x);
    }

    return 0;
}
