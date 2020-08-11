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

constexpr int MAX = 500000;
int place[MAX]; // Rank of each person based on index
int temp[MAX]; // Used for merge sort
int skills[MAX]; // List of skill values
unordered_map < int, int > index_mapper; // Maps original index

/*
 * Uses merge sort to, for each number, count smaller numbers that appears before.
 */
void merge(int left, int mid, int right) {
    int l_index = left, r_index = mid + 1;
    int cursor = left;

    while (l_index <= mid && r_index <= right) {
        // Sort ascending
        if (skills[l_index] <= skills[r_index]) {
            temp[cursor++] = skills[l_index++];
        }
        else {
            /*
             * Decrease `place` based on how many people with lower skill value
             * was on the "left" block.
             */
            place[index_mapper[skills[r_index]]] -= l_index - left;
            temp[cursor++] = skills[r_index++];
        }
    }

    while (l_index <= mid) {
        temp[cursor++] = skills[l_index++];
    }

    while (r_index <= right) {
        /*
         * Decrease `place` based on how many people with lower skill value
         * was on the "left" block.
         */
        place[index_mapper[skills[r_index]]] -= l_index - left;
        temp[cursor++] = skills[r_index++];
    }

    for (int i = left; i <= right; i++) {
        skills[i] = temp[i];
    }
}

void split(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        split(left, mid);
        split(mid + 1, right);

        merge(left, mid, right);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    index_mapper.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
        index_mapper[skills[i]] = i;
        place[i] = i + 1; // Initialize place based on index
    }

    split(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << place[i] << '\n';
    }

    return 0;
}
