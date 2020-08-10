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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, t;
    vector < int > v;

    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> m;
    while (m--) {
        cin >> t;

        int left = 0, right = n - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (t < v[mid]) {
                right = mid - 1;
            }
            else if (t > v[mid]) {
                left = mid + 1;
            }
            else {
                cout << 1 << '\n';
                break;
            }
        }

        if (left > right) {
            cout << 0 << '\n';
        }
    }

    return 0;
}
