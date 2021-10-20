#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
    }
};

vector<vector<int>> LevelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level; 
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
return ans;
}