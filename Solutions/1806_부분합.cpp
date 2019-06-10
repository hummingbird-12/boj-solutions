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

vector < int > seq;

int minLen = INT_MAX;
int leftBound, rightBound;
int curSum;

inline int curLen() {
    return rightBound - leftBound + 1;
}

inline void advanceLeft() {
    curSum -= seq[leftBound++];
}

inline void advanceRight() {
    if (rightBound >= seq.size() - 1) {
        return;
    }
    curSum += seq[++rightBound];
}

void twoPointer(int s) {
    leftBound = rightBound = 0;
    curSum = seq[0];

    while (leftBound <= rightBound) {
        if (curSum >= s) {
            minLen = min(minLen, curLen());
            if (minLen == 1) {
                return;
            }
            advanceLeft();
        }
        else {
            advanceRight();
            if (curLen() >= minLen) {
                advanceLeft();
            }
        }
        if (rightBound == seq.size() - 1 && curSum < s) {
            break;
        }
    }
}

int main() {
    int n, s, num;

    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        seq.push_back(num);
    }

    twoPointer(s);
    if (minLen == INT_MAX) {
        minLen = 0;
    }
    printf("%d\n", minLen);
    return 0;
}
