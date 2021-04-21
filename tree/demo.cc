/***************************************************************************************
 *   Copyright (C), 2006-2021, Legendsec Technology Co., Ltd.
 *
 *    Filename: demo.cc
 * Description:
 *     Version: 1.0
 *     Created: ChaiYD   04/12/2021 10:51:28 PM
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              ChaiYD   04/12/2021                  build this moudle
 ***************************************************************************************/

#include <iostream>
#include "demo.h"

TreeNode *solution::__do_buildTree(vector<int> &preorder, int pbegin, int pend,
						 vector<int> &inorder, int ibegin, int iend)
{
	if (pbegin >= pend) {
		return NULL;
	}
	TreeNode *cur = new TreeNode(preorder[pbegin]);

	int ix = 0;
	for (ix = ibegin; ix < iend; ix++) {
		if (inorder[ix] == preorder[pbegin]) {
			break;
		}
	}

	cur->left = __do_buildTree(preorder, pbegin + 1, pbegin + 1 + ix - ibegin, inorder, ibegin, ix - 1);
	cur->right = __do_buildTree(preorder, pbegin + 1 + ix - ibegin, pend, inorder, ix + 1, iend);

	return cur;
}

TreeNode *solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
	if (preorder.size() != inorder.size()) {
		return NULL;
	}
	TreeNode *root = __do_buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());

	return root;
}

int solution::maxDepth(TreeNode *root)
{
	if (!root) {
		return 0;
	}

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

vector<vector<int>> solution::zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int>> ret;

	stack<TreeNode *> sta1;
	stack<TreeNode *> sta2;

	if (!root) {
		return ret;
	}
	sta1.push(root);

	while (!sta1.empty() || !sta2.empty()) {
		vector<int> tmp;
		if (!sta1.empty()) {
			while (!sta1.empty()) {
				tmp.push_back(sta1.top()->val);
				if (sta1.top()->left) {
					sta2.push(sta1.top()->left);
				}
				if (sta1.top()->right) {
					sta2.push(sta1.top()->right);
				}
				sta1.pop();
			}
			ret.push_back(tmp);
		}
		else if (!sta2.empty()) {
			while (!sta2.empty()) {
				tmp.push_back(sta2.top()->val);
				if (sta2.top()->right) {
					sta1.push(sta2.top()->right);
				}
				if (sta2.top()->left) {
					sta1.push(sta2.top()->left);
				}
				sta2.pop();
			}
			ret.push_back(tmp);
		}
	}

	return ret;
}

vector<vector<int>> solution::levelOrder(TreeNode *root)
{
	vector<vector<int>> ret;
	queue<TreeNode *> que1;
	queue<TreeNode *> que2;
	if (!root) {
		return ret;
	}
	que1.push(root);
	while (!que1.empty() || !que2.empty()) {
		vector<int> tmp;
		if (!que1.empty()) {
			while (!que1.empty()) {
				tmp.push_back(que1.front()->val);
				if (que1.front()->left) {
					que2.push(que1.front()->left);
				}
				if (que1.front()->right) {
					que2.push(que1.front()->right);
				}
				que1.pop();
			}
			ret.push_back(tmp);
		}
		else if (!que2.empty()) {
			while (!que2.empty()) {
				tmp.push_back(que2.front()->val);
				if (que2.front()->left) {
					que1.push(que2.front()->left);
				}
				if (que2.front()->right) {
					que1.push(que2.front()->right);
				}
				que2.pop();
			}
			ret.push_back(tmp);
		}

	}
	return ret;
}

void solution::_inorderTraversal(TreeNode *root, vector<int> &vec)
{
	if (!root) {
		return;
	}

	_inorderTraversal(root->left, vec);
	vec.push_back(root->val);
	_inorderTraversal(root->right, vec);

	return;
}

vector<int> solution::inorderTraversal(TreeNode *root)
{
	vector<int> vec;
	_inorderTraversal(root, vec);
	return vec;
}
void solution::print(vector<int> &vec)
{
	cout << "vec: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

vector<TreeNode *> solution::_generateTree(int start, int end)
{
	vector<TreeNode *> vec;

	if (start > end) {
		vec.push_back(NULL);
	}

	for (int ix = start; ix <= end; ix++) {
		vector<TreeNode *> left = _generateTree(start, ix - 1);
		vector<TreeNode *> right = _generateTree(ix + 1, end);
		for (auto lx : left) {
			for (auto rx : right) {
				TreeNode *root = new TreeNode(ix);
				root->left = lx;
				root->right = rx;
				vec.push_back(root);
			} //rx end
		} //lx end
	} // end

	return vec;
}

vector<TreeNode *> solution::generateTree(int n)
{
	return _generateTree(1, n);
}

int solution::numTrees(int n)
{
	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	vector<int> vec(n + 1);

	vec[0] = 1;
	vec[1] = 1;
	vec[2] = 2;

	for (int ix = 3; ix <= n; ix++) {
		for (int left = 0; left < ix; left++) {
			vec[ix] += vec[left] * vec[ix - left - 1];
		}
	}

	return vec[n];
}

void solution::print_tree(TreeNode *root)
{
	if (!root) {
		cout << "NULL ";
		return;
	}
	/* 先序遍历 */
	cout << root->val << " ";
	if (root->left == NULL && root->right == NULL) {
		return;
	}
	print_tree(root->left);
	print_tree(root->right);
	return;
}
void solution::delete_tree(TreeNode *root)
{
	return;
}
