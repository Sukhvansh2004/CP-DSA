#include <bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    vector<TrieNode*> children;
    char c;
    bool is_end_of_word;
    TrieNode() : children(26, nullptr), is_end_of_word(false) {};
    TrieNode(char x) : c(x), children(26, nullptr), is_end_of_word(false) {};

    void insert(string w) {
        if (w.length() == 0) {
            is_end_of_word = true;
            return;
        } 
        if (children[w[0] - 'a'] == nullptr) {
            children[w[0] - 'a'] = new TrieNode(w[0]);
        }
        children[w[0] - 'a']->insert(w.substr(1, w.length()));
    }
};
class Solution {
public:
    vector<char> result;
    void findLongestWord(vector<char>& str, TrieNode*& node) {
        if (!node)
            return;

        if (node->is_end_of_word) {
            str.push_back(node->c);
            if (str.size() >= result.size()) {
                result = str;
            }
        }
        for (int i = 25; i >= 0; i--) {
            findLongestWord(str, node->children[i]);
        }

        str.pop_back();
    }
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode;
        for(string word: words){
            root->insert(word);
        }
        vector<char> temp;
        findLongestWord(temp, root);
        string res = "";
        for (char c : result) {
            res += c;
        }
        return res;
    }
};