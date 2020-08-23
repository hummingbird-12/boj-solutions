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

vector < int > v;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector < int >::iterator left = v.begin();
    vector < int >::iterator right = v.end() - 1;
    int mn = INT_MAX;
    pair < int, int> ans;

    while (left < right) {
        const int sum = abs(*left + *right);
        if (sum < mn) {
            mn = sum;
            ans = make_pair(*left, *right);
        }

        if (abs(*(left + 1) + *right) < abs(*left + *(right - 1))) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
