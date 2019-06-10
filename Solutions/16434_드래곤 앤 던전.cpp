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

long long hInitAttack;
vector < pair < int, pair < int, int > > > dungeon;

bool fightDungeon(long long maxHealth) {
    long long curAttack = hInitAttack;
    long long curHealth = maxHealth;

    for (auto it : dungeon) {
        switch (it.first) {
        case 1:
            if (curHealth <= it.second.first * ((long long)ceilf((float)it.second.second / curAttack) - 1)) {
                return false;
            }
            curHealth -= it.second.first * ((long long)ceilf((float)it.second.second / curAttack) - 1);
            break;
        case 2:
            curAttack += it.second.first;
            curHealth = min(maxHealth, curHealth + it.second.second);
            break;
        }
    }
    return true;
}

long long binarySearch(long long low, long long high) {
    long long mid;
    bool result, testLow;

    while (low <= high) {
        mid = (low + high) / 2;
        result = fightDungeon(mid);

        if (result) {
            testLow = fightDungeon(mid - 1);
            if (!testLow) {
                return mid;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            low = mid + 1;
        }
    }
}

int main() {
    int n;
    int t, a, h;
    long long upperBound = 0;

    scanf("%d%d", &n, &hInitAttack);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &t, &a, &h);
        dungeon.push_back(make_pair(t, make_pair(a, h)));
        if (t == 1) {
            upperBound += (long long) a * ceilf((float)h / hInitAttack);
        }
    }
    printf("%lld\n", binarySearch(1, upperBound));
    return 0;
}
