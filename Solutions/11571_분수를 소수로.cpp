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

inline int getGCD(int a, int b) {
    int temp;

    if (b > a) {
        temp = b;
        b = a;
        a = temp;
    }

    while (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc, integer, q, gcd;
    int repetitionStart;
    int numerator, denominator; // 분자, 분모
    string decimal;
    string repetition;
    vector < int > firstAppearance(10240);

    cin >> tc;
    while (tc--) {
        cin >> numerator >> denominator;

        if (numerator == 0) {
            cout << "0.(0)" << '\n';
            continue;
        }

        // initialize for new test case
        decimal = "";
        repetition = "0";
        fill(firstAppearance.begin(), firstAppearance.end(), -1);

        // simplify to a irreducible fraction
        gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // calculate the integer part
        integer = numerator / denominator;
        numerator %= denominator;

        while (numerator % denominator != 0) {
            // expand numerator
            numerator *= 10;

            // check if remainder already appeared
            if (firstAppearance[numerator] != -1) {
                repetitionStart = firstAppearance[numerator];
                repetition = decimal.substr(repetitionStart);
                decimal = decimal.substr(0, repetitionStart);
                break;
            }

            // map current index for current numerator
            firstAppearance[numerator] = decimal.length();

            // numerator still needs expansion
            if (numerator < denominator) {
                decimal += to_string(0);
                continue;
            }

            // calculate current decimal
            q = numerator / denominator;
            decimal += to_string(q);

            // prepare remainder for next cycle
            numerator %= denominator;
        }

        cout << integer << '.' << decimal << '(' << repetition << ')' << '\n';
    }
    return 0;
}
