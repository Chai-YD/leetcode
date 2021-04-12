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

	vector<int> vec(n+1);

	vec[0] = 1;
	vec[1] = 1;
	vec[2] = 2;

	for (int ix = 3; ix <= n; ix++) {
		for (int left = 0; left < ix; left++){
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
