/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> ans(n+1);
        ans[0].push_back(NULL);
        for(int numberOfNodes=1;numberOfNodes<=n;numberOfNodes++){
            for(int i=1;i<=numberOfNodes;i++){
                int j=numberOfNodes-i;
                for(auto left:ans[i-1]){
                    for(auto right:ans[j]){
                        TreeNode* root=new TreeNode(i,left,clone(right,i));
                        ans[numberOfNodes].push_back(root);
                    }
                }
            }
        }
        return ans[n];
    }
private:
    TreeNode* clone(TreeNode* node,int offset){
        if(!node) return NULL;
        TreeNode* clonedNode = new TreeNode(node->val+offset);
        clonedNode->left=clone(node->left,offset);
        clonedNode->right=clone(node->right,offset);
        return clonedNode;
    }
};