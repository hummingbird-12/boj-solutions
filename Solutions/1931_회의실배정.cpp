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

vector < pair < int, int > > timeItvl;

bool sortTime(pair < int, int > left, pair < int, int > right) {
    if (left.second == right.second) {
        return left.first < right.first;
    }
    return left.second < right.second;
}

int main() {
    int n, a, b;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        timeItvl.push_back(make_pair(a, b));
    }
    sort(timeItvl.begin(), timeItvl.end(), sortTime);

    int cnt = 0;
    int prevEnd = -1;
    for (auto it : timeItvl) {
        if (it.first >= prevEnd) {
            prevEnd = it.second;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
