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

vector < string > cards;
vector < bool > used;
set < int > numbers;
int n, k;

void backtracking(string& num, int cnt = 0) {
    if (cnt == k) {
        numbers.insert(stoi(num));
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            num += cards[i];

            backtracking(num, cnt + 1);

            for (int j = 0; j < cards[i].size(); j++) {
                num.pop_back();
            }
            used[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> k;

    cards.resize(n);
    used.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    string num;
    backtracking(num);

    cout << numbers.size() << '\n';

    return 0;
}
