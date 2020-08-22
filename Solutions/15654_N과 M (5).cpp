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

class TrieNode {
public:
    int n;
    vector < TrieNode* > children;

    TrieNode(const int n) {
        this->n = n;
    }

    TrieNode* get_child(const int num) {
        const auto child = find_if(children.begin(), children.end(),
            [num](const TrieNode* node) -> bool { return node->n == num; });
        return (child != children.end() ? *child : nullptr);
    }

    void print_children(vector < int >& buffer) {
        if (children.empty()) {
            for (const int& i : buffer) {
                cout << i << ' ';
            }
            cout << '\n';
            return;
        }

        sort(children.begin(), children.end(),
            [](const TrieNode* left, const TrieNode* right) ->
            bool { return left->n < right->n; });

        for (const auto& c : children) {
            buffer.push_back(c->n);
            c->print_children(buffer);
            buffer.pop_back();
        }
    }
};

TrieNode* root;
vector < int > nums;
int n, m;

void add_trie(const vector < int >& v) {
    TrieNode* cur = root;

    for (const int& i : v) {
        TrieNode* child = cur->get_child(i);
        if (child == nullptr) {
            child = new TrieNode(i);
            cur->children.push_back(child);
        }

        cur = child;
    }
}

void backtracking(vector < bool >& used, vector < int >& selected) {
    if (selected.size() == m) {
        add_trie(selected);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            selected.push_back(nums[i]);
            used[i] = true;

            backtracking(used, selected);

            selected.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    root = new TrieNode(0);

    cin >> n >> m;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector < int > v;
    vector < bool > used(n);
    backtracking(used, v);

    root->print_children(v);

    return 0;
}
