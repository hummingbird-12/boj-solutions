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

#define MAX 12

short mem[MAX];

void backtracking(int num, short sum) {
    if (sum >= num) {
        if (sum == num) {
            mem[num]++;
        }
        return;
    }

    for (short i = 1; i <= 3; i++) {
        backtracking(num, sum + i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        if (mem[n] == 0) {
            backtracking(n, 0);
        }
        printf("%d\n", mem[n]);
    }
    
    return 0;
}
