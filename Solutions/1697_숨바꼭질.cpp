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

#define BACKWARDS_ONE -1
#define FORWARDS_ONE 1
#define TELEPORT 2
#define OTHER 0

constexpr int MAX = 100001;

bool visited[MAX];

pair < int, pair < int, int > > getNextPosition(const pair < int, pair < int, int > > current, const int moveToDo) {
    int nextPosition;
    const int currentPosition = current.first;
    const int nextSecond = current.second.first + 1;

    switch (moveToDo) {
    case BACKWARDS_ONE:
        nextPosition = currentPosition - 1;
        break;
    case FORWARDS_ONE:
        nextPosition = currentPosition + 1;
        break;
    default:
        nextPosition = currentPosition * 2;
        break;
    }

    return make_pair(nextPosition, make_pair(nextSecond, moveToDo));
}

int bfs(const int start, const int destination) {
    pair < int, pair < int, int > > current; // < CURRENT_POSITION < CURRENT_TIME, PREVIOUS_MOVE > >
    queue < pair < int, pair < int, int > > > position;

    current = make_pair(start, make_pair(0, OTHER));
    position.push(current);
    while (true) {
        current = position.front();
        position.pop();

        const int currentPosition = current.first;
        const int prevMove = current.second.second;

        if (currentPosition == destination) {
            break;
        }
        if (currentPosition >= MAX || currentPosition < 0 || visited[currentPosition]) {
            continue;
        }
        visited[currentPosition] = true;

        const auto forwards = getNextPosition(current, FORWARDS_ONE);
        const auto backwards = getNextPosition(current, BACKWARDS_ONE);
        const auto teleport = getNextPosition(current, TELEPORT);

        switch (prevMove) {
        case BACKWARDS_ONE:
            position.push(backwards);
            position.push(teleport);
            break;
        case FORWARDS_ONE:
            position.push(forwards);
            position.push(teleport);
            break;
        default:
            position.push(backwards);
            position.push(forwards);
            position.push(teleport);
            break;
        }
    }
    return current.second.first;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k, ans;

    cin >> n >> k;

    if (k < n) {
        ans = n - k;
    }
    else if (k == n) {
        ans = 0;
    }
    else {
        ans = bfs(n, k);
    }
    cout << ans << '\n';

    return 0;
}
