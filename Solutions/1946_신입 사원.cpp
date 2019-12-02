#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
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

    int tc, n, sa, sb, currentBest, count;
    vector < pair < int, int > > orderByFirst;
    vector < pair < int, int > > orderBySecond;

    cin >> tc;
    while (tc--) {
        cin >> n;
        orderByFirst.reserve(n);
        orderBySecond.reserve(n);

        for (int i = 0; i < n; i++) {
            cin >> sa >> sb;
            orderByFirst.push_back(make_pair(sa, sb));
            orderBySecond.push_back(make_pair(sb, sa));
        }
        sort(orderByFirst.begin(), orderByFirst.end());
        sort(orderBySecond.begin(), orderBySecond.end());

        const pair < int, int > topFirst = orderByFirst.front();
        currentBest = INT_MAX;
        count = 1;
        for (auto it = orderBySecond.begin();
            (*it).first != topFirst.second && it != orderBySecond.end();
            it++) {
            if ((*it).second < currentBest) {
                currentBest = (*it).second;
                count++;
            }
        }
        cout << count << '\n';

        orderByFirst.clear();
        orderBySecond.clear();
    }
    return 0;
}
