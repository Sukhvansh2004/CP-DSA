
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* findNode(TreeNode* root, TreeNode* &parent, int key){
        if(root){
            if(root->val == key) return root;
            else if(key < root->val) {
                parent = root;
                return findNode(root->left, parent, key);
            }
            else {
                parent = root;
                return findNode(root->right, parent, key);
            }
        }
        return nullptr;
    }
    TreeNode* findMin(TreeNode* root) {
        if(root->left) return findMin(root->left);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* node = findNode(root, parent, key);

        if (!node) return root;

        TreeNode* replace = nullptr;

        if (node->left && node->right) {
            replace = findMin(node->right);
            root = deleteNode(root, replace->val);
        }
        else if (node->left) {
            replace = node->left;
        }
        else if (node->right) {
            replace = node->right;
        }
        
        if(parent) {
            if(parent->val > node->val) {
                parent->left = replace;
            }
            else {
                parent->right = replace;
            }
        }
        else {
            root = replace;
        }

        if(replace) {
            replace->left = node->left;
            replace->right = node->right;
        }
        
        return root;
    }
};