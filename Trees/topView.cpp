#include<iostream>
#include<vector>
#include<map>
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

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    map<int,int>mp;
    queue<pair<TreeNode*,int>>q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end()){
            mp[line] = node->val;
        }
        
        if(node->left){
            q.push({node->left, line-1});
        }
        if(node->right){
            q.push({node->right, line+1});
        }
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }
return ans;
}
