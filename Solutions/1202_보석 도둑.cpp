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

priority_queue < int > pq; // Max-heap of < VALUE, WEIGHT >
vector < int > bags;
vector < pair < int, int > > jews;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k, m, v;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jews.emplace_back(m, v);
    }

    bags.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }

    sort(jews.begin(), jews.end());
    sort(bags.begin(), bags.end());

    long long price = 0;
    auto it = jews.begin();
    for (int b : bags) {
        // Push all jewelries that fit in the bag into max-heap
        while (it != jews.end() && (*it).first <= b) {
            pq.push((*it).second);
            it++;
        }

        if (pq.empty()) {
            continue;
        }

        // Choose the jewelry with highest value
        price += pq.top();
        pq.pop();
    }

    cout << price << '\n';

    return 0;
}
