#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		: val(x)
		, left(NULL)
		, right(NULL)
	{
	}
};

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){
	}
};

class mod_tree
{
private:
	int __GetNodes(TreeNode *pRoot);
	bool __IsSame(TreeNode *pRoot1, TreeNode *pRoot2);
	bool __check(vector<int> vec, int left, int right);
	void __FindPath(TreeNode *root, int expectNumber);
	void __Convert(TreeNode *pRootOfTree);
	int __DepthOfTree(TreeNode *pRoot);
	void __Print(vector<TreeNode *> &vec, int left, int right);
	void __FindPath_ex(TreeNode *root, int sum);
	void __inorder(TreeNode *root, int sum);
	int __lowestCommonAncestor(TreeNode *root, int o2);
	bool __FindNode(TreeNode *root, int val);
public:
	int TreeDepth(TreeNode *pRoot);
	vector<vector<int>> Rrint(TreeNode *pRoot);
	int KthNode(TreeNode *pRoot, int k);
	TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin);
	bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2);
	TreeNode *Mirror(TreeNode *pRoot);
	vector<int> PrintFromTopToBottom(TreeNode *root);
	bool VerifySquenceOfBSF(vector<int> sequence);
	bool hasPathSum(TreeNode *root, int sum);
	vector<vector<int> > FindPath(TreeNode *root, int expectNumber);
	TreeNode *Convert(TreeNode *pRootOfTree);
	bool IsBalanced_Solution(TreeNode *pRoot);
	TreeLinkNode *GetNext(TreeLinkNode * pNode);
	vector<vector<int> > Print(TreeNode *pRoot);
	char *serialize(TreeNode *root);
	TreeNode *deserialize(char *str);
	int FindPath(TreeNode *root, int sum);
	int lowestCommonAncestor(TreeNode *root, int o1, int o2);
	int lowestCommonAncestor_sort(TreeNode *root, int p, int q);
private:
	vector<vector<int> > ans;
	vector<int> cur_vec;
	int total = 0;
	int ret_val = -1;
	std::string ret_str;
	int find = 0;
	TreeNode * prev = NULL;
	TreeNode * head = NULL;
};
