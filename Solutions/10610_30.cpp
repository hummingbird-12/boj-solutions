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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char n;
    int sum = 0;
    vector < char > num;

    while (cin >> n) {
        num.push_back(n);
        sum += n - '0';
    }

    sort(num.rbegin(), num.rend());
    if (num.back() == '0' && sum % 3 == 0) {
        for (const char& c : num) {
            cout << c;
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
