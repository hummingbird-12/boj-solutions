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

vector < string > words;
bool used[26];
bool letters[26];

bool readable(const string word) {
    for (char c : word) {
        if (!letters[c - 'a']) {
            return false;
        }
    }
    return true;
}

int dfs(char cur, int count, const int k) {
    if (count >= k) {
        int readable_words = 0;
        for (string w : words) {
            if (readable(w)) {
                readable_words++;
            }
        }
        return readable_words;
    }

    int mx = 0;
    for (char c = cur + 1; c <= 'z'; c++) {
        if (!used[c - 'a'] && !letters[c - 'a']) {
            letters[c - 'a'] = true;
            mx = max(mx, dfs(c, count + 1, k));
            letters[c - 'a'] = false;
        }
    }

    return mx;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    used['a' - 'a'] = letters['a' - 'a'] = true;
    used['n' - 'a'] = letters['n' - 'a'] = true;
    used['t' - 'a'] = letters['t' - 'a'] = true;
    used['i' - 'a'] = letters['i' - 'a'] = true;
    used['c' - 'a'] = letters['c' - 'a'] = true;

    int mx = 0;
    if (k == 5) {
        for (string w : words) {
            if (readable(w)) {
                mx++;
            }
        }
    }
    else if (k >= 6) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (used[c - 'a']) {
                continue;
            }
            letters[c - 'a'] = true;
            mx = max(mx, dfs(c, 6, k));
            letters[c - 'a'] = false;

            used[c - 'a'] = true;
        }
    }
    cout << mx << '\n';

    return 0;
}
