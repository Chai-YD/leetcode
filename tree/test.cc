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

int main(int argc, char *argv[])
{
	demo_inorder_traversal();
	demo_geterate_tree();
	return 0;
}
