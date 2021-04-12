/***************************************************************************************
 *   Copyright (C), 2006-2021, Legendsec Technology Co., Ltd.
 *
 *    Filename: demo.h
 * Description:
 *     Version: 1.0
 *     Created: ChaiYD   04/12/2021 10:51:37 PM
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              ChaiYD   04/12/2021                  build this moudle
 ***************************************************************************************/
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *pl, TreeNode *pr): val(x), left(pl), right(pr) {}
};

class solution
{
public:
	/* 二叉树的中序遍历
	 * 描述： 给定一个二叉树的根结点，返回它的中序 遍历
	 * */
	vector<int> inorderTraversal(TreeNode *root);
	void _inorderTraversal(TreeNode *root, vector<int> &vec);

	/* 不同的二叉搜索树
	 * 描述：给定一个整数n，生成所有由1...n为节点所组成的二叉搜索树
	 * */
	vector<TreeNode *> _generateTree(int start, int end);
	vector<TreeNode *> generateTree(int n);

	/* 不同的二叉搜索树
	 * 描述：给定一个整数n， 求以1...n为节点组成的二叉搜索树有多少种*/
	int numTrees(int n);

	/* 描述： 打印vector */
	void print(vector<int> &vec);
	void print_tree(TreeNode *root);
	void delete_tree(TreeNode *root);
};
