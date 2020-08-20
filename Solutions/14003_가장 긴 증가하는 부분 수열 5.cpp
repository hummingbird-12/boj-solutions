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

vector < pair < int, int > > buffer;
vector < int > previous;
vector < int > numbers;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    previous.resize(n, -1);
    numbers.resize(n);

    cin >> numbers[0];
    buffer.emplace_back(numbers[0], 0);

    pair < int, int > ans(1, 0);
    for (int i = 1; i < n; i++) {
        cin >> numbers[i];

        const int low_index =
            lower_bound(buffer.begin(), buffer.end(), make_pair(numbers[i], 0)) - buffer.begin();

        if (low_index == buffer.size()) {
            buffer.emplace_back(numbers[i], i);
        }
        else {
            buffer[low_index] = make_pair(numbers[i], i);
        }

        // Save index of previous number in LIS
        if (low_index > 0) {
            previous[i] = buffer[low_index - 1].second;
        }

        if (low_index + 1 > ans.first) {
            ans = make_pair(low_index + 1, i);
        }
    }

    cout << ans.first << '\n';

    stack < int > s;
    int i = ans.second;
    while (i != -1) {
        s.push(numbers[i]);
        i = previous[i];
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    return 0;
}
