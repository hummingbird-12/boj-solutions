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

int n, m;

void backtracking(vector < int >& selected, const int cur = 0) {
    if (selected.size() == m) {
        for (const int& i : selected) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur + 1; i <= n; i++) {
        selected.push_back(i);
        backtracking(selected, i);
        selected.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vector < int > v;
    backtracking(v);

    return 0;
}
