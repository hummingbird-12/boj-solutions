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

int leftBound, rightBound;
int curSum;

inline void advanceLeft() {
    curSum -= seq[leftBound++];
}

inline void advanceRight() {
    if (rightBound >= seq.size() - 1) {
        return;
    }
    curSum += seq[++rightBound];
}

int twoPointer(int m) {
    int cnt = 0;
    leftBound = rightBound = 0;
    curSum = seq[0];

    while (leftBound <= rightBound) {
        if (curSum == m) {
            cnt++;
            advanceLeft();
            advanceRight();
        }
        else if(curSum < m){
            advanceRight();
        }
        else {
            if (leftBound == rightBound) {
                advanceRight();
            }
            advanceLeft();
        }
        if (rightBound == seq.size() - 1 && curSum < m) {
            break;
        }
    }
    return cnt;
}

int main() {
    int n, m, num;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        seq.push_back(num);
    }

    printf("%d\n", twoPointer(m));
    return 0;
}
