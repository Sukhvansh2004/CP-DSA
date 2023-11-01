#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isTerminal;
    int frequency;

    TrieNode() {
        isTerminal = false;
        frequency = 0;
    }
};

void insertWord(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node->frequency++;
        node = node->children[ch];
        
    }
    node->isTerminal = true;
    node->frequency++;
}

TrieNode* Search(TrieNode* root, string word){
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            return nullptr;
        }
        node = node->children[ch];
        
    }
    return node;
}

struct Comparator {
  bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
    return a.second < b.second;
  }
};

void findSuggestions(TrieNode* node, string currentWord, vector<string>& suggestions) {
    // if(node == nullptr){
    //     return;
    // }
    if (node->children.size() == 0){
        suggestions.push_back(currentWord);
    }
    else{
        vector<pair<char, int>> arr;
        for(auto it: node->children){
            pair<char, int> val;
            val.first = it.first;
            val.second = node->children[it.first]->frequency;
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end(),Comparator());
        for(int i=0; i<arr.size(); i++){
            findSuggestions(node->children[arr[i].first], currentWord + arr[i].first, suggestions);
        }
        if(node->isTerminal){
            suggestions.push_back(currentWord);
        }
    }
}

int main() {
    int n;
    cin >> n;

    TrieNode* root = new TrieNode();

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        insertWord(root, word);
    }

    string query;
    cin >> query;

    vector<string> Suggestion;
    TrieNode* node = Search(root, query);
    if(node == nullptr){
        return 0;
    }
    findSuggestions(node, query, Suggestion);
    for(int i=Suggestion.size()-1;i>=0;i--){
        cout<<Suggestion[i]<<endl;
    }

    return 0;
}