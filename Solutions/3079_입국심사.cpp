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
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool testFeasibility(const vector < int >& controlTime, const long long testDuration, int people) {
    for (auto time : controlTime) {
        people -= testDuration / time;
        if (people <= 0) {
            return true;
        }
    }
    return false;
}

long long binarySearch(long long left, long long right, const vector < int >& controlTime, const int people) {
    long long mid, lastValid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (testFeasibility(controlTime, mid, people)) {
            lastValid = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return lastValid;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, t;
    vector < int > controlTime;

    cin >> n >> m;
    controlTime.reserve(n);

    while (n--) {
        cin >> t;
        controlTime.push_back(t);
    }
    sort(controlTime.rbegin(), controlTime.rend());

    cout << binarySearch(0, controlTime.front() * (long long) m, controlTime, m) << '\n';

    return 0;
}
