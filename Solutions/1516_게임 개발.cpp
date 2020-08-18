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

vector < vector < int > > parents;
vector < vector < int > > children;
vector < int > build_time;
vector < int > in_cnt;
vector < pair < int, int > > degree_sort; // For sorting per degree

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    parents.resize(n + 1);
    children.resize(n + 1);
    build_time.resize(n + 1);
    in_cnt.resize(n + 1);

    int pre;
    for (int i = 1; i <= n; i++) {
        cin >> build_time[i];
        cin >> pre;
        while (pre != -1) {
            parents[pre].push_back(i);
            children[i].push_back(pre);
            in_cnt[i]++;
            cin >> pre;
        }
    }

    queue < pair < int, int > > q;
    for (int i = 1; i <= n; i++) {
        if (in_cnt[i] == 0) {
            q.emplace(i, 0);
            degree_sort.emplace_back(0, i);
        }
    }

    while (!q.empty()) {
        const int& cur = q.front().first;
        const int& deg = q.front().second;

        for (const int& next : parents[cur]) {
            in_cnt[next]--;
            if (in_cnt[next] == 0) {
                q.emplace(next, deg + 1);
                degree_sort.emplace_back(deg + 1, next);
            }
        }
        q.pop();
    }

    // Process build_time from lowest degree
    sort(degree_sort.begin(), degree_sort.end());
    int mx;
    for (const auto& d : degree_sort) {
        const int& cur = d.second;
        mx = 0;
        for (const int& next : children[cur]) {
            mx = max(mx, build_time[next]);
        }
        build_time[cur] += mx;
    }

    for (int i = 1; i <= n; i++) {
        cout << build_time[i] << '\n';
    }

    return 0;
}
