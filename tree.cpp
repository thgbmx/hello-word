#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>

using namespace std;

/*
（1）先序遍历：先访问根节点，再访问左子树，最后访问右子树。
（2）后序遍历：先左子树，再右子树，最后根节点。
（3）中序遍历：先左子树，再根节点，最后右子树。
（4）层序遍历：每一层从左到右访问每一个节点。
*/

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
    // 递归解法
/*     void inorderTrave(TreeNode* root, vector<int> &ans) {
        if(root) {
            inorderTrave(root->left, ans);
            ans.push_back(root->val);
            inorderTrave(root->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTrave(root, result);
        return result;
    } */

    // 使用全局变量res
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return res;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }

private:
    vector<int> res;
};


// 迭代解法
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stc; // 使用stack先入后出的特性，控制左右子树访问顺序
    if (!root) {
        return res;
    }
    stc.push(root);
    TreeNode* tmpNode;
    while (!stc.empty()) {
        tmpNode = stc.top();
        stc.pop();
        res.push_back(tmpNode->val); //访问出栈节点
        if (tmpNode->right) { // 右子树先入栈，后访问
            stc.push(tmpNode->right);
        }
        if (tmpNode->left) { // 左子树后入栈，先访问
            stc.push(tmpNode->left);
        }
    }
    return res;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stc;
    TreeNode* cur = root;
    while (cur || !stc.empty()) {
        if (cur) { // 父节点先入栈，左子树访问到头，出栈并访问右子树
            stc.push(cur);
            cur = cur->left;
        } else {
            cur = stc.top();
            stc.pop();
            res.push_back(cur->val); //访问出栈节点
            cur = cur->right;
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stc;
    stack<TreeNode*> s;
    stc.push(root);
    TreeNode* tmpNode;
    while (!stc.empty()) {
        tmpNode = stc.top();
        stc.pop();
        s.push(tmpNode); // 记录stc出栈节点，s出栈顺序即为后续遍历顺序
        // res.push_back(tmpNode->val); // 不使用双栈，vertor记录出栈顺序，最后反转vertor即可；vertor也可以看成是一种栈，同理；
        // reverse(res.begin(), res.end()); 
        if (tmpNode->left) {
            stc.push(tmpNode->left); // 注意左右子树入栈顺序
        }
        if (tmpNode->right) {
            stc.push(tmpNode->right);
        }
    }
    while (!s.empty()) {
        res.push_back(s.top()->val);
        s.pop();
    }
    return res;
}

// 层序遍历
vector<vector<int>> levelorderTraversal(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> levelres;
    queue<TreeNode*> qu;
    if (!root) {
        return res;
    }
    qu.push(root);
    int levelnum = 1, nextlevelnum = 0;
    TreeNode* cur;
    while (!qu.empty()) {
        cur = qu.front();
        qu.pop();
        levelnum--;
        levelres.push_back(cur->val);
        if (cur->left) {
            qu.push(cur->left);
            nextlevelnum++;
        }
        if (cur->right) {
            qu.push(cur->right);
            nextlevelnum++;
        }
        // 记录每层节点个数
        if (levelnum == 0) {
            res.push_back(levelres);
            levelres.clear();
            levelnum = nextlevelnum;
            nextlevelnum = 0;
        }
    }
    return res;
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
        return ans;
    }
    queue<TreeNode*> que;
    que.push(root);
    vector<int> levelVal;
    while(!que.empty()) {
        int n = que.size(); // 每层节点的个数
        levelVal.clear();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = que.front();
            que.pop();
            levelVal.push_back(node->val);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        ans.push_back(levelVal);
    }
    //reverse(ans.begin(), ans.end()); // 从下到上层序遍历
    return ans;
}

// 二叉树的锯齿形层序遍历
vector<vector<int>> levelOrderZ(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
        return ans;
    }
    queue<TreeNode*> que;
    que.push(root);
    vector<int> levelVal;
    bool breverse = false;
    while(!que.empty()) {
        int n = que.size(); // 每层节点的个数
        levelVal.clear();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = que.front();
            que.pop();
            levelVal.push_back(node->val); // 也可以使用双端队列控制每层节点的访问顺序

            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        if (breverse) {
            reverse(levelVal.begin(), levelVal.end());
        }
        ans.push_back(levelVal);
        breverse = !breverse;
    }
    //reverse(ans.begin(), ans.end()); // 从下到上层序遍历
    return ans;
}
vector<vector<int>> levelOrderZ_v2(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
        return ans;
    }
    queue<TreeNode*> que;
    que.push(root);
    deque<int> levelVal;
    bool breverse = false;
    while(!que.empty()) {
        int n = que.size(); // 每层节点的个数
        levelVal.clear();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = que.front();
            que.pop();
            // 每层节点都是从左至右访问，此处使用双端队列控制每层节点的访问顺序
            if (breverse) {
                levelVal.push_front(node->val);
            } else {
                levelVal.push_back(node->val);
            }
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        ans.emplace_back(vector<int>{levelVal.begin(), levelVal.end()});
        breverse = !breverse;
    }
    return ans;
}


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution_v2 {
public:
    // N 叉树的层序遍历
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<Node*> qu;
        qu.push(root);
        vector<int> levelVal;
        int n = 0;
        while (!qu.empty()) {
            levelVal.clear();
            n = qu.size();
            for (int i = 0; i < n; i++) {
                Node* tmpNode = qu.front();
                qu.pop();
                levelVal.push_back(tmpNode->val);
                for (auto& chilerenNode:tmpNode->children) {
                    qu.push(chilerenNode);
                }
            }
            ans.push_back(levelVal);
        }
        return ans;
    }
    // N 叉树的前序遍历
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* tmpNode = st.top();
            st.pop();
            ans.emplace_back(tmpNode->val);
            for (auto it = tmpNode->children.rbegin(); it != tmpNode->children.rend(); it++) { // 子树节点逆序入栈
                st.push(*it);
            }
        }
        return ans;
    }
    // N 叉树的后序遍历
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* tmpNode = st.top();
            st.pop();
            ans.emplace_back(tmpNode->val);
            for (auto it = tmpNode->children.begin(); it != tmpNode->children.end(); it++) { // 子树节点逆序入栈
                st.push(*it);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{



    return 0;
}