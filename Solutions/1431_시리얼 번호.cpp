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

inline int digitSum(const string s) {
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

bool compareSN(const string left, const string right) {
    if (left.length() != right.length()) {
        return left.length() < right.length();
    }
    const int leftSum = digitSum(left);
    const int rightSum = digitSum(right);
    if (leftSum != rightSum) {
        return leftSum < rightSum;
    }
    return left < right;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    vector < string > serials;
    int n;

    cin >> n;
    serials.reserve(n);

    while (n--) {
        cin >> s;
        serials.push_back(s);
    }

    sort(serials.begin(), serials.end(), compareSN);
    for (auto sn : serials) {
        cout << sn << '\n';
    }

    return 0;
}
