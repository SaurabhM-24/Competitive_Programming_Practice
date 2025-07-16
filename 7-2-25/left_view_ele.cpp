#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> levelorderTraversal(TreeNode* root) {

        vector<int> ans;

        if(root==nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;

        while(!q.empty()) {

            int len = q.size();
        
            for(int i=0; i<len; i++) {
                curr = q.front();
                q.pop();

                if(i==0)
                    ans.push_back(curr->val);
                
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return ans;
    }
};
