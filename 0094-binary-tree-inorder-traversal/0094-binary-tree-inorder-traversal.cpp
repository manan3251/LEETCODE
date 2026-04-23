class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

private:
    void inorder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;

     
        inorder(node->left, res);  // Left
        res.push_back(node->val);   // Root
        inorder(node->right, res); // Right
    }
};