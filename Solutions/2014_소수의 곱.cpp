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
vector < int > v;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> k >> n;

    v.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        pq.push(v[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int top = pq.top();

        // Add into priority queue the product of `top` with each of the given primes
        for (int j : v) {
            if (j > INT_MAX / top) {
                continue;
            }
            int m = j * top;
            pq.push(m);
        }

        // Remove any duplicate
        while (pq.top() == top) {
            pq.pop();
        }
    }

    cout << pq.top() << '\n';

    return 0;
}
