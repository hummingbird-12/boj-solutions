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

long long countZeroSums(const vector < int > arrays[], const vector < int >& abSums) {
    long long count = 0;
    int i, j, cdSum;

    for (i = 0; i < arrays[2].size(); i++) {
        for (j = 0; j < arrays[3].size(); j++) {
            cdSum = (arrays[2][i] + arrays[3][j]) * -1;
            count += upper_bound(abSums.begin(), abSums.end(), cdSum)
                - lower_bound(abSums.begin(), abSums.end(), cdSum);
        }
    }
    return count;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector < int > arrays[4];
    vector < int > abSums;
    int n, e, i, j;

    cin >> n;
    for (i = 0; i < 4; i++) {
        arrays[i].resize(n);
    }
    abSums.reserve(n * n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            cin >> e;
            arrays[j][i] = e;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            abSums.push_back(arrays[0][i] + arrays[1][j]);
        }
    }
    sort(abSums.begin(), abSums.end());

    cout << countZeroSums(arrays, abSums) << '\n';

    return 0;
}
