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
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *pl, TreeNode *pr): val(x), left(pl), right(pr) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(NULL) {}
	ListNode(int x): val(x), next(NULL) {}
	ListNode(int x, ListNode *pl): val(x), next(pl) {}
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

	/*二叉树的层序遍历
	 * 描述：给一个二叉树，返回其按 层序遍历 得到的结点（即逐层，从左到右）
	 * */
	vector<vector<int>> levelOrder(TreeNode *root);

	/* 二叉树的锯齿形层序遍历
	 * 描述：给定一个二叉树，返回其结点的锯齿形层序遍历（从左到右，再从右到左） */
	vector<vector<int>> zigzagLevelOrder(TreeNode *root);

	/* 二叉树的最大深度
	 * 描述：给定一个二叉树，找出其最大深度；二叉树的深度为根节点到最远叶子节点的最路径上的节点数 */
	int maxDepth(TreeNode *root);

	/* 从前序 与 中序遍历序列构造二叉树
	 * 描述：根据一棵树的前序遍历与中序遍历构造二叉树
	 * 注意： 假设树中没有重复的元素*/
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
	TreeNode *__do_buildTree(vector<int> &preorder, int pbegin, int pend,
							 vector<int> &inorder, int ibegin, int iend);

	/* 从中序与后序遍历序列构造二叉树
	 * 描述：根据一棵树的中序遍历和后序遍历构建二叉树
	 * 注意：假设树中没有重复的元素 */
	TreeNode *buildTree_ex(vector<int> &inorder, vector<int> &postorder);
	TreeNode *__do_buildTree_ex(vector<int> &inorder, int ibegin, int iend,
								vector<int> &postorder, int pbegin, int pend);

	/* 二叉树的层序遍历
	 * 描述：给定一个二叉树，返回其结点自底向上的层序比哪里。(即按从叶子结点所在层到根结点所在层，逐层从左到右遍历)
	 **/
	vector<vector<int>> levelOrderBottom(TreeNode* root);

	/* 将有序数组转换为二叉搜索树
	 * 描述：给一个整数数组nums，其中的元素已经按升序排列，将其转换为一颗高度平和二叉搜索树
	 * 注：高度平衡，二叉树是一颗满足[每个结点的左右两个子树的高度差的绝对值不超过1]的二叉树 */
	TreeNode* sortedArrayToBST(vector<int>& nums);
	TreeNode* __do_sortedArrayToBST(vector<int>& nums, int begin, int end);

	/* 有序链表转换二叉搜索树
	 * 描述：给定一个单链表， 其中的元素按升序排序，将其转换为高度平衡的二叉搜索树
	 * 注：一个高度平衡二叉树是一个二叉树每个结点的左右两个子树的高度差的绝对值不超过1 */
	TreeNode* sortedListToBST(ListNode* head);
	
	/* 描述： 打印vector */
	void print(vector<int> &vec);
	void print_tree(TreeNode *root);
	void delete_tree(TreeNode *root);
};
