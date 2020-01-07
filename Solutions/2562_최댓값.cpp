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

constexpr int N = 9;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n = N, num;
    vector < int > numbers;
    numbers.reserve(N);

    while (n--) {
        cin >> num;
        numbers.push_back(num);
    }
    const auto maxIt = max_element(numbers.begin(), numbers.end());
    cout << *maxIt << '\n';
    cout << maxIt - numbers.begin() + 1 << '\n';

    return 0;
}
