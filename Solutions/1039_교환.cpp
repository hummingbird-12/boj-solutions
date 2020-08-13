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

vector < short > digits;
int n, k;

inline void swap(int index1, int index2) {
    short temp = digits[index1];
    digits[index1] = digits[index2];
    digits[index2] = temp;
}

inline int to_int() {
    int num = 0;
    for (int i : digits) {
        num = num * 10 + i;
    }
    return num;
}

int backtracking(int index, int cnt) {
    if (cnt == k) {
        return to_int();
    }

    if (index == digits.size() - 1) {
        swap(n - 2, n - 1);
        int mx = backtracking(index - 1, cnt + 1);
        swap(n - 2, n - 1);
        return mx;
    }

    int mx = backtracking(index + 1, cnt);
    for (int i = 0; i < digits.size(); i++) {
        if (i == index) {
            continue;
        }
        if ((index == 0 && digits[i] == 0) || (i == 0 && digits[index] == 0)) {
            continue;
        }
        swap(index, i);
        mx = max(mx, backtracking(index + 1, cnt + 1));
        swap(index, i);
    }

    return mx;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string inp;
    cin >> inp;
    for (char c : inp) {
        digits.push_back(c - '0');
    }
    cin >> k;
    n = digits.size();

    if (n == 1 || (n == 2 && digits[1] == 0)) {
        cout << -1 << '\n';
        return 0;
    }

    cout << backtracking(0, 0) << '\n';

    return 0;
}
