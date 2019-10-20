#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
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
#include <vector>

using namespace std;

// Returns `true` if the first operand has the greatest absolute value
bool firstGreaterAbsolute(const string input1, const string input2) {
    const int length1 = input1.length();
    const int length2 = input2.length();

    if (length1 > length2) {
        return true;
    }
    else if (length1 < length2) {
        return false;
    }

    for (auto it1 = input1.begin(), it2 = input2.begin();
        it1 != input1.end() && it2 != input2.end();
        it1++, it2++) {
        const int digit1 = *it1 - '0';
        const int digit2 = *it2 - '0';
        if (digit1 > digit2) {
            return true;
        }
        else if (digit1 < digit2) {
            return false;
        }
    }
}

// Prints result string from the stack
inline void printResult(stack < char >& result, const bool isNegative) {
    while (result.top() == '0' && !result.empty()) {
        result.pop();
    }
    if (isNegative) {
        cout << '-';
    }
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool resultNegative = false, addition = true, borrow = false;
    short digit1, digit2, temp, carry;
    string input1, input2;
    stack < char > result;

    cin >> input1 >> input2;
    if (input1 == "0" && input2 == "0") {
        cout << 0 << '\n';
        return 0;
    }
    const bool positive1 = input1.front() != '-';
    const bool positive2 = input2.front() != '-';

    if (!positive1) {
        input1.erase(0, 1);
    }
    if (!positive2) {
        input2.erase(0, 1);
    }

    // prepare operands
    if (positive1 != positive2) {
        if (input1 == input2) {
            cout << 0 << '\n';
            return 0;
        }
        addition = false;
        // `input2` has greater absolute value
        if (!firstGreaterAbsolute(input1, input2)) {
            input1.swap(input2);
            // `input2` is negative
            if (!positive2) {
                resultNegative = true;
            }
        }
        // `input1` has greater absolute value
        // and `input1` is negative
        else if (!positive1) {
            resultNegative = true;
        }
    }
    else if (!positive1 && !positive2) {
        resultNegative = true;
    }

    carry = 0;
    for (auto it1 = input1.rbegin(), it2 = input2.rbegin();
        it1 != input1.rend() || it2 != input2.rend(); ) {
        digit1 = (it1 == input1.rend() ? 0 : *it1 - '0');
        digit2 = (it2 == input2.rend() ? 0 : *it2 - '0');

        if (borrow) {
            digit1--;
            borrow = false;
        }
        temp = digit1 + (addition ? 1 : -1) * digit2 + carry;
        if (temp < 0) {
            borrow = true;
            temp += 10;
        }
        carry = temp / 10;
        temp %= 10;

        result.push('0' + temp);

        if (it1 != input1.rend()) {
            it1++;
        }
        if (it2 != input2.rend()) {
            it2++;
        }
    }
    if (carry > 0) {
        result.push('0' + carry);
    }

    printResult(result, resultNegative);
    cout << '\n';

    return 0;
}
