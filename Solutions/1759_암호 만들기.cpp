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

vector < char > ch;
int l, c;

inline bool isVocal(char c) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

void backtracking(string& password, int cur, int vocals, int consonants) {
    if (password.size() == l) {
        if (vocals >= 1 && consonants >= 2) {
            cout << password << '\n';
        }
        return;
    }

    for (int i = cur + 1; i < c; i++) {
        password.push_back(ch[i]);
        (isVocal(ch[i]) ? vocals : consonants)++;
        backtracking(password, i, vocals, consonants);
        (isVocal(ch[i]) ? vocals : consonants)--;
        password.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> l >> c;

    ch.resize(c);
    for (int i = 0; i < c; i++) {
        cin >> ch[i];
    }
    sort(ch.begin(), ch.end());

    string password;
    backtracking(password, -1, 0, 0);

    return 0;
}
