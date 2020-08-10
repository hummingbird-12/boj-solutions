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

list < pair < pair < int, int >, int > > candidates; // < < REC_CNT, TIME >, NUM >

bool num_compare(
    const pair < pair < int, int >, int >& left,
    const pair < pair < int, int >, int >& right) {
    return left.second < right.second;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, rec, c;
    cin >> n;
    cin >> rec;

    for (int i = 0; i < rec; i++) {
        cin >> c;

        auto it = candidates.begin();
        for (; it != candidates.end(); it++) {
            if ((*it).second == c) {
                break;
            }
        }

        // Already a candidate, increase REC_CNT
        if (it != candidates.end()) {
            (*it).first.first++;
        }
        // New candidate, replace the lowest oldest previous candidate
        else if (candidates.size() == n) {
            candidates.sort();
            candidates.pop_front();
            candidates.emplace_back(make_pair(1, i), c);
        }
        // New candidate
        else {
            candidates.emplace_back(make_pair(1, i), c);
        }
    }

    candidates.sort(num_compare);
    for (auto& cand : candidates) {
        cout << cand.second << ' ';
    }
    cout << '\n';

    return 0;
}
