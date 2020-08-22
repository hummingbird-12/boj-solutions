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

/*
 * make_mod1[i][j]:
 * Stores the multiplier such that given `N` and `OFFSET`,
 * (N * make_mod1[N % 10][OFFSET % 10] + OFFSET) % 10 == 1
 */
short make_mod1[10][10];

void preprocess() {
    vector < short > target = { 1, 3, 7, 9 };

    for (const short& t : target) {
        for (int off = 0; off <= 9; off++) {
            for (int i = 1; i <= 9; i++) {
                if ((t * i + off) % 10 == 1) {
                    make_mod1[t][off] = i;
                    break;
                }
            }
        }
    }
}

bool all_one(const int n) {
    for (const char& c : to_string(n)) {
        if (c != '1') {
            return false;
        }
    }
    return true;
}

bool all_one(const string& s) {
    for (const char& c : s) {
        if (c != '1') {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    preprocess();

    string s;
    while (cin >> s) {
        // Input already consists of only 1's
        if (all_one(s)) {
            cout << s.size() << '\n';
        }
        else {
            const int n = atoi(s.c_str());
            int offset = 0;
            int digits = 0;

            // Repeat multiplication while mantaining 1's digit as 1
            while (!all_one(offset)) {
                digits++;

                const int product = n * make_mod1[n % 10][offset % 10] + offset;
                offset = product / 10;
            }

            cout << digits + to_string(offset).size() << '\n';
        }
    }

    return 0;
}
