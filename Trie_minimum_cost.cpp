#include <bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int is_end_of_word;

    TrieNode() : is_end_of_word(-1) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(const std::string& word, vector<int> &costs, int index) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        if(node->is_end_of_word == -1 || costs[index] < costs[node->is_end_of_word]){
            node->is_end_of_word = index;
        }
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->is_end_of_word;
    }
    void generate(TrieNode*& node, vector<int>& res) {
        if (node->is_end_of_word != -1)
            res.push_back(node->is_end_of_word);
        for (auto child : node->children) {
            generate(child.second, res);
        }
    }

    vector<int> starts_with(char& ch) {
        TrieNode* node = root;
        vector<int> res;
        // for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return res;
        }
        node = node->children[ch];
        // }
        generate(node, res);
        return res;
    }

    ~Trie() { clear(root); }

private:
    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }
};

class Solution {
public:
    vector<string> words;
    vector<int> costs;

    int solve(vector<int>& dp, Trie& tree, int curr, string& target) {
        if (curr == target.length())
            return 0;

        if (dp[curr] != -1)
            return dp[curr];

        int mini = INT_MAX;
        vector<int> indices = tree.starts_with(target[curr]);
        for (int i : indices) {
            if (words[i] == target.substr(curr, words[i].length()) &&
                solve(dp, tree, curr + words[i].length(), target) != INT_MAX) {
                    mini = min(mini, costs[i] + solve(dp, tree, curr + words[i].length(), target));
            }
        }
        return dp[curr] = mini;
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector<int> dp(target.length(), -1);
        Trie tree;
        for (int i = 0; i < words.size(); i++) {
            tree.insert(words[i], costs, i);
        }
        this->words = words;
        this->costs = costs;
        int tmp = solve(dp, tree, 0, target);
        if (tmp == INT_MAX)
            return -1;
        return tmp;
    }
};