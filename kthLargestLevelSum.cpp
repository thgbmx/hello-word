#include<vector>
#include<queue>
#include<algorithm>

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
    // 二叉树中的第 K 大层和
    // 层序遍历求和，递减排序
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        vector<long long> ans;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            int n = qe.size();
            long long sum = 0;
            TreeNode* node;
            for (int i = 0; i < n; i++) {
                node = qe.front();
                qe.pop();
                sum += node->val;
                
                if (node->left) {
                    qe.push(node->left);
                }
                if (node->right) {
                    qe.push(node->right);
                }
            }
            ans.push_back(sum);
        }
        if (k > ans.size()) {
            return -1;
        }
        // 第 K 大, 使用快速选择
        sort(ans.begin(), ans.end(), greater<long long>()); // 注意数据类型
        return ans[k-1];

        // sort(ans.begin(), ans.end());
        // return ans[levelnum-k];
    }
};