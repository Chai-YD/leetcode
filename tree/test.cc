/***************************************************************************************
 *   Copyright (C), 2006-2021, Legendsec Technology Co., Ltd.
 *
 *    Filename: test.cc
 * Description:
 *     Version: 1.0
 *     Created: ChaiYD   04/12/2021 11:11:13 PM
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              ChaiYD   04/12/2021                  build this moudle
 ***************************************************************************************/

#include <iostream>
#include "demo.h"

void demo_inorder_traversal()
{
	TreeNode *pnode_4 = new TreeNode(4);
	TreeNode *pnode_5 = new TreeNode(5);
	TreeNode *pnode_6 = new TreeNode(6);
	TreeNode *pnode_7 = new TreeNode(7);
	TreeNode *pnode_2 = new TreeNode(2, pnode_4, pnode_5);
	TreeNode *pnode_3 = new TreeNode(3, pnode_6, pnode_7);
	TreeNode *pnode_1 = new TreeNode(1, pnode_2, pnode_3);

	solution sol;
	vector< int> vec = sol.inorderTraversal(pnode_1);
	sol.print(vec);

	delete pnode_1;
	delete pnode_2;
	delete pnode_3;
	delete pnode_4;
	delete pnode_5;
	delete pnode_6;
	delete pnode_7;
}

void demo_geterate_tree()
{
	solution sol;
	int n = 3;
	vector<TreeNode *> vec = sol.generateTree(n);
	//cout << "size : "<< vec.size() << " " <<sol.numTrees(n) <<endl;
	if (vec.size() == sol.numTrees(n)) {
		cout << "demo_geterate_tree ==> [ok]" << endl;
	}
	else {
		cout << "demo_geterate_tree ==> [fail]" << endl;
	}

	//资源释放 TODO
	for (vector<TreeNode *>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it != NULL) {
			sol.print_tree(*it);
			cout << endl;
		}
	} //end for
}

void demo_levelOrder()
{
	TreeNode *pnode_4 = new TreeNode(15);
	TreeNode *pnode_5 = new TreeNode(7);
	TreeNode *pnode_6 = new TreeNode(9);
	TreeNode *pnode_7 = new TreeNode(20, pnode_4, pnode_5);
	TreeNode *pnode_3 = new TreeNode(3, pnode_6, pnode_7);

	solution sol;
	vector< vector<int>> vec = sol.levelOrder(pnode_3);
	for (int ix = 0; ix < vec.size(); ix++) {
		for (int jx = 0; jx < vec[ix].size(); jx++) {
			cout << vec[ix][jx] << " ";
		}
		cout << endl;
	}

	delete pnode_3;
	delete pnode_4;
	delete pnode_5;
	delete pnode_6;
	delete pnode_7;
}

void demo_zigzagLevelOrder()
{
	TreeNode *pnode_4 = new TreeNode(15);
	TreeNode *pnode_5 = new TreeNode(7);
	TreeNode *pnode_6 = new TreeNode(9);
	TreeNode *pnode_7 = new TreeNode(20, pnode_4, pnode_5);
	TreeNode *pnode_3 = new TreeNode(3, pnode_6, pnode_7);

	solution sol;
	vector< vector<int>> vec = sol.zigzagLevelOrder(pnode_3);
	for (int ix = 0; ix < vec.size(); ix++) {
		for (int jx = 0; jx < vec[ix].size(); jx++) {
			cout << vec[ix][jx] << " ";
		}
		cout << endl;
	}

	delete pnode_3;
	delete pnode_4;
	delete pnode_5;
	delete pnode_6;
	delete pnode_7;
}

void demo_maxDepth()
{
	TreeNode *pnode_4 = new TreeNode(15);
	TreeNode *pnode_5 = new TreeNode(7);
	TreeNode *pnode_6 = new TreeNode(9);
	TreeNode *pnode_7 = new TreeNode(20, pnode_4, pnode_5);
	TreeNode *pnode_3 = new TreeNode(3, pnode_6, pnode_7);

	solution sol;
	int depth = sol.maxDepth(pnode_3);
	if (depth == 3) {
		cout << "maxDepth [ok]" << endl;
	}
	else {
		cout << "maxDepth [err]" << endl;
	}

	delete pnode_3;
	delete pnode_4;
	delete pnode_5;
	delete pnode_6;
	delete pnode_7;
}

void demo_buildTree()
{
	solution sol;
	vector<int> preorder;
	vector<int> inorder;
	preorder.push_back(3);
	preorder.push_back(9);
	preorder.push_back(20);
	preorder.push_back(15);
	preorder.push_back(7);
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	TreeNode *root = sol.buildTree(preorder, inorder);
	sol.print_tree(root);
}

void demo_buildTree_ex()
{
	solution sol;
	vector<int> postorder;
	vector<int> inorder;
	postorder.push_back(9);
	postorder.push_back(15);
	postorder.push_back(7);
	postorder.push_back(20);
	postorder.push_back(3);
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	TreeNode *root = sol.buildTree(inorder, postorder);
	sol.print_tree(root);
}

void demo_levelOrderBottom()
{
	TreeNode *pnode_4 = new TreeNode(15);
	TreeNode *pnode_5 = new TreeNode(7);
	TreeNode *pnode_6 = new TreeNode(9);
	TreeNode *pnode_7 = new TreeNode(20, pnode_4, pnode_5);
	TreeNode *pnode_3 = new TreeNode(3, pnode_6, pnode_7);

	solution sol;
	vector< vector<int>> vec = sol.levelOrderBottom(pnode_3);
	for (int ix = 0; ix < vec.size(); ix++) {
		for (int jx = 0; jx < vec[ix].size(); jx++) {
			cout << vec[ix][jx] << " ";
		}
		cout << endl;
	}

	delete pnode_3;
	delete pnode_4;
	delete pnode_5;
	delete pnode_6;
	delete pnode_7;
}

void demo_sortedArrayToBST()
{
	vector<int> vec;
	vec.push_back(-10);
	vec.push_back(-3);
	vec.push_back(0);
	vec.push_back(5);
	vec.push_back(9);
	solution sol;
	TreeNode *root = sol.sortedArrayToBST(vec);
	sol.print_tree(root);

}

void demo_sortedListToBST()
{
	ListNode *Plist1 = new ListNode(9);
	ListNode *Plist2 = new ListNode(5, Plist1);
	ListNode *Plist3 = new ListNode(0, Plist2);
	ListNode *Plist4 = new ListNode(-3, Plist3);
	ListNode *Plist5 = new ListNode(-10, Plist4);

	solution sol;
	TreeNode *root = sol.sortedListToBST(Plist5);
	sol.print_tree(root);

}

void demo_isBalanced()
{
	TreeNode *pnode_4 = new TreeNode(15);
	TreeNode *pnode_5 = new TreeNode(7);
	TreeNode *pnode_6 = new TreeNode(9);
	TreeNode *pnode_7 = new TreeNode(20, pnode_4, pnode_5);
	TreeNode *pnode_3 = new TreeNode(3, pnode_6, pnode_7);

	solution sol;
	bool flag = sol.isBalanced(pnode_3);

	if (flag) {
		cout << "demo_isBalanced [ok]" << endl;
	}
	else {
		cout << "demo_isBalanced [err]" << endl;
	}
}

int main(int argc, char *argv[])
{
	//demo_inorder_traversal();
	//demo_geterate_tree();
	//demo_levelOrder();
	//demo_zigzagLevelOrder();
	//demo_maxDepth();
	//demo_buildTree();
	//demo_buildTree_ex();
	//demo_levelOrderBottom();
	//demo_sortedArrayToBST();
	//demo_sortedListToBST();
	demo_isBalanced();
	return 0;
}
