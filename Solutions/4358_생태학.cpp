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
    char c;
    int count;
    vector < TrieNode* > children;

    TrieNode(char c) {
        this->c = c;
        count = 0;
    }

    /*
     * Finds the child `TrieNode` that contains the given character
     * and returns its pointer. If not present, returns `NULL`.
     */
    TrieNode* get_child(const char c) {
        for (auto it = children.begin(); it != children.end(); it++) {
            if ((*it)->c == c) {
                return *it;
            }
        }
        return NULL;
    }

    /*
     * Inserts a child `TrieNode` with given character.
     */
    TrieNode* insert_child(const char c) {
        TrieNode* new_child = new TrieNode(c);
        children.push_back(new_child);
        return new_child;
    }
};

/*
 * Utility function used for sorting `TrieNode` instances.
 */
bool compare_children(TrieNode* const& left, TrieNode* const& right) {
    return left->c < right->c;
}

/*
 * Print answer while searching the trie tree in DFS fashion.
 */
void dfs(TrieNode* cur, string& path, const int n) {
    sort(cur->children.begin(), cur->children.end(), compare_children);
    for (auto child : cur->children) {
        path.push_back(child->c);
        if (child->count > 0) {
            printf("%s %.4f\n", path.c_str(), child->count * 100.0f / n);
        }
        dfs(child, path, n);
        path.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    TrieNode* root = new TrieNode('\0');

    int n = 0;
    string tree;
    TrieNode* cur, * next;
    while (getline(cin, tree)) {
        // Insert into trie tree
        cur = root;
        for (char c : tree) {
            next = cur->get_child(c);
            if (next == NULL) {
                next = cur->insert_child(c);
            }
            cur = next;
        }
        // Increase counter at the end of string
        cur->count++;
        n++;
    }

    tree = "";
    dfs(root, tree, n);

    return 0;
}
