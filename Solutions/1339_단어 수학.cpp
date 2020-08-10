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
vector < pair < int, char > > letter_score;
int mapping[26];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char c = 'A';
    letter_score.resize(26);
    for (auto& i : letter_score) {
        i.first = 0;
        i.second = c++;
    }

    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        words.push_back(s);
        int j = 1;
        for (auto it = s.rbegin(); it != s.rend(); it++, j *= 10) {
            letter_score[(*it) - 'A'].first += j;
        }
    }
    sort(letter_score.rbegin(), letter_score.rend());

    int digit = 9;
    for (auto sc : letter_score) {
        if (sc.first == 0) {
            break;
        }
        mapping[sc.second - 'A'] = digit--;
    }

    int sum = 0;
    for (string w : words) {
        int value = 0;
        for (char c : w) {
            value = value * 10 + mapping[c - 'A'];
        }
        sum += value;
    }
    cout << sum << '\n';

    return 0;
}
