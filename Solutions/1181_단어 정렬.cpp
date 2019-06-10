#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

set < string > inp;
vector < string > strs;

bool sortStrings(string left, string right) {
    if (left.length() == right.length()) {
        return left < right;
    }
    return left.length() < right.length();
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string str;

        cin >> str;
        if (inp.find(str) == inp.end()) {
            strs.push_back(str);
        }
        inp.insert(str);
    }

    sort(strs.begin(), strs.end(), sortStrings);

    for (auto it : strs) {
        cout << it << endl;
    }
    return 0;
}
