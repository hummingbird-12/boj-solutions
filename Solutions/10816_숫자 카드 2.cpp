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
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define MIN_NUMBER -10000000
#define MAX_NUMBER 10000000

inline int cardToIndexMapper(const int card) {
    return card - MIN_NUMBER;
}

vector < char* > numberCount(MAX_NUMBER - MIN_NUMBER + 1, NULL);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, card, index;
    int currentCount;

    cin >> n;
    while (n--) {
        cin >> card;

        index = cardToIndexMapper(card);
        if (numberCount[index] == NULL) {
            numberCount[index] = (char*)malloc(7 * sizeof(char));
            sprintf(numberCount[index], "0");
        }
        currentCount = atoi(numberCount[index]);
        sprintf(numberCount[index], "%d", currentCount + 1);
    }

    cin >> m;
    while (m--) {
        cin >> card;

        index = cardToIndexMapper(card);
        if (numberCount[index] == NULL) {
            cout << 0 << ' ';
        }
        else {
            cout << numberCount[index] << ' ';
        }
    }
    return 0;
}
