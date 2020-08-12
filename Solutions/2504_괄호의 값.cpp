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

stack < string > s;

inline int to_int(const string& str) {
    int num = 0;
    for (char c : str) {
        num = num * 10 + c - '0';
    }
    return num;
}

inline void incorrect() {
    cout << 0 << '\n';
    exit(0);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string inp;
    cin >> inp;

    for (char c : inp) {
        string str;
        switch (c) {
        case '(':
        case '[':
            str.push_back(c);
            s.push(str);
            break;
        case ')':
        case ']':
            if (s.empty()) {
                incorrect();
            }

            // Multiply stacked score
            int mult = 1;
            if (isdigit(s.top()[0])) {
                mult = to_int(s.top());
                s.pop();

                // No opening parenthesis/bracket
                if (s.empty()) {
                    incorrect();
                }
            }

            // Incorrect match of opening parenthesis/bracket
            if (s.top()[0] == (c == ')' ? '[' : '(')) {
                incorrect();
            }

            // Pop out opening parenthesis/bracket
            s.pop();

            // Add stacked score
            int sum = 0;
            while (!s.empty() && isdigit(s.top()[0])) {
                sum += to_int(s.top());
                s.pop();
            }

            // Stack calculated score
            s.push(to_string((c == ')' ? 2 : 3) * mult + sum));
            break;
        }
    }

    // Only the final score should be present in the stack
    if (!isdigit(s.top()[0]) || s.size() != 1) {
        incorrect();
    }

    cout << s.top() << '\n';

    return 0;
}
