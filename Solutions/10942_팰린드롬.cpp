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
#include <vector>

using namespace std;

constexpr int MAX = 2001;

bool tested[MAX][MAX];
bool palindrome[MAX][MAX];

bool isPalindrome(const vector < int >& v, const int start, const int end) {
    if (tested[start][end]) {
        return palindrome[start][end];
    }
    tested[start][end] = true;

    if (start >= end) {
        return (palindrome[start][end] = true);
    }
    if (v[start] != v[end]) {
        return false;
    }
    return (palindrome[start][end] = isPalindrome(v, start + 1, end - 1));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, p;
    int s, e;
    vector < int > v;

    cin >> n;
    v.reserve(n + 1);
    v.push_back(-1);
    for (int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << (isPalindrome(v, s, e) ? 1 : 0) << '\n';
    }

    return 0;
}
