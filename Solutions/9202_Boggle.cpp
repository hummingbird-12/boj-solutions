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

const short dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const short dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

class TrieNode {
    char c;
    TrieNode* children[26];
    bool is_end;
    bool is_hit;

public:
    TrieNode(char c) {
        this->c = c;
        is_end = false;
        is_hit = false;
        fill(children, children + 26, nullptr);
    }

    bool get_is_end() {
        return is_end;
    }

    bool get_is_hit() {
        return is_hit;
    }

    void mark_as_end() {
        is_end = true;
    }

    void mark_as_hit() {
        is_hit = true;
    }

    void clear_hits() {
        is_hit = false;
        for (auto c : children) {
            if (c != nullptr) {
                c->clear_hits();
            }
        }
    }

    TrieNode* get_child(const char c) {
        return children[c - 'A'];
    }

    TrieNode* insert_child(const char c) {
        TrieNode* new_child = new TrieNode(c);
        children[c - 'A'] = new_child;
        return new_child;
    }
};

TrieNode* root;
vector < string > board(4);
bool used[4][4];
string longest;
int score;
int cnt;

void add_trie(const string& word) {
    TrieNode* cur = root;
    TrieNode* next;
    for (char c : word) {
        if ((next = cur->get_child(c)) == NULL) {
            next = cur->insert_child(c);
        }
        cur = next;
    }
    cur->mark_as_end();
}

bool has_word(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if ((cur = cur->get_child(c)) == NULL) {
            return false;
        }
    }
    return cur->get_is_end();
}

void dfs(int r, int c, TrieNode* cur, string& word) {
    if (cur->get_is_end() && !cur->get_is_hit()) {
        cnt++;

        if (word.size() > longest.size() ||
            (word.size() == longest.size() && word < longest)) {
            longest = word;
        }

        switch (word.size()) {
        case 3:
        case 4:
            score += 1;
            break;
        case 5:
            score += 2;
            break;
        case 6:
            score += 3;
            break;
        case 7:
            score += 5;
            break;
        case 8:
            score += 11;
            break;
        default:
            break;
        }
        cur->mark_as_hit();
    }

    TrieNode* next;
    for (int i = 0; i < 8; i++) {
        int row = r + dx[i];
        int col = c + dy[i];

        if (0 <= row && row < 4 && 0 <= col && col < 4) {
            if ((next = cur->get_child(board[row][col])) && !used[row][col]) {
                used[row][col] = true;
                word.push_back(board[row][col]);

                dfs(row, col, next, word);

                word.pop_back();
                used[row][col] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    root = new TrieNode('\0');

    int words;
    cin >> words;

    string word;
    for (int i = 0; i < words; i++) {
        cin >> word;
        add_trie(word);
    }

    TrieNode* start;
    int boggles;
    cin >> boggles;
    for (int i = 0; i < boggles; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> board[j];
        }

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if ((start = root->get_child(board[j][k]))) {
                    word.clear();
                    word.push_back(board[j][k]);
                    used[j][k] = true;
                    dfs(j, k, start, word);
                    used[j][k] = false;
                }
            }
        }

        cout << score << ' ' << longest << ' ' << cnt << '\n';

        cnt = score = 0;
        longest.clear();
        root->clear_hits();
    }

    return 0;
}
