#include<stack>
#include<queue>

using namespace std;


// Definition for a binary tree node.
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
    void preorderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        if ( root->val >= g_low && root->val <= g_high) {
            sum += root->val;
        }
        // 不在范围内提前结束遍历
        if (root->val < g_low) { 
            preorderTraversal(root->right);
        } else if (root->val > g_high) {
            preorderTraversal(root->left);
        } else {
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        g_high = high;
        g_low = low;
        if (!root) {
            return sum;
        }
        preorderTraversal(root);
        return sum;
    }
private:
    int g_high;
    int g_low;
    int sum;
};

//  二叉搜索树的范围和
// 迭代解法：递归前序遍历+二叉搜索树左子树小于右子树特性和搜索范围，提前结束递归；
int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    if (!root) {
        return sum;
    }
    stack<TreeNode*> stc; // 使用stack先入后出的特性，控制左右子树访问顺序
    stc.push(root);
    TreeNode* tmpNode;
    while (!stc.empty()) {
        tmpNode = stc.top();
        stc.pop();
        if (tmpNode->val >= low && tmpNode->val <= high) {
            sum += tmpNode->val;
            if (tmpNode->right) { // 右子树先入栈，后访问
                stc.push(tmpNode->right);
            }
            if (tmpNode->left) { // 左子树后入栈，先访问
                stc.push(tmpNode->left);
            }
        } else if (tmpNode->val < low && tmpNode->right) { // 不在搜索范围内提前结束迭代
            stc.push(tmpNode->right);
        } else if (tmpNode->left) {  //if (tmpNode->val > high) {
            stc.push(tmpNode->left);
        }
    }
    return sum;
}
