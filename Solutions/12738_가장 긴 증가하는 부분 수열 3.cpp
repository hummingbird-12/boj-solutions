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

vector < int > buffer;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, num;
    cin >> n;

    cin >> num;
    buffer.push_back(num);

    int ans = 1;
    while (n--) {
        cin >> num;

        const int low_index = lower_bound(buffer.begin(), buffer.end(), num) - buffer.begin();

        if (low_index == buffer.size()) {
            buffer.push_back(num);
        }
        else {
            buffer[low_index] = num;
        }

        ans = max(ans, low_index + 1);
    }

    cout << ans << '\n';

    return 0;
}
