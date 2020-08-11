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

priority_queue < int, vector < int >, greater < int > > pq;
priority_queue < int, vector < int >, greater < int > > to_eliminate;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;

    vector < int > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = -l + 1, right = 0;

    pq.push(INT_MAX);
    for (; right < n; right++, left++) {
        pq.push(v[right]);

        cout << pq.top() << ' ';
        if (left >= 0) {
            to_eliminate.push(v[left]);
            while (!to_eliminate.empty() && to_eliminate.top() == pq.top()) {
                pq.pop();
                to_eliminate.pop();
            }
        }
    }
    cout << '\n';

    return 0;
}
