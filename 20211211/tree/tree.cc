#include "tree.h"

int mod_tree::TreeDepth(TreeNode *pRoot)
{
	if (!pRoot) {
		return 0;
	}

	return 1 + (TreeDepth(pRoot->right) > TreeDepth(pRoot->left) ? TreeDepth(pRoot->right) : TreeDepth(pRoot->left));
}

/*之字形顺序打印*/
vector<vector<int> > mod_tree::Rrint(TreeNode *pRoot)
{
	stack<TreeNode *> sta1;
	stack<TreeNode *> sta2;
	vector<vector<int> > vvec;

	if (!pRoot) {
		return vvec;
	}

	sta1.push(pRoot);
	while (!sta1.empty() || !sta2.empty()) {
		vector<int> vec;
		if (!sta1.empty()) {
			while (!sta1.empty()) {
				TreeNode *node = sta1.top();
				sta1.pop();
				if (node->left) {
					sta2.push(node->left);
				}
				if (node->right) {
					sta2.push(node->right);
				}
				vec.push_back(node->val);
			}
		}
		else {
			while (!sta2.empty()) {
				TreeNode *node = sta2.top();
				sta2.pop();
				if (node->right) {
					sta1.push(node->right);
				}
				if (node->left) {
					sta1.push(node->left);
				}
				vec.push_back(node->val);
			}
		}
		vvec.push_back(vec);
	}
	return vvec;
}

int mod_tree::__GetNodes(TreeNode *pRoot)
{
	if (!pRoot) {
		return 0;
	}
	return 1 + __GetNodes(pRoot->left) + __GetNodes(pRoot->right);
}
int mod_tree::KthNode(TreeNode *pRoot, int k)
{
	if (!pRoot) {
		return -1;
	}

	int left_count = __GetNodes(pRoot->left);
	int right_count = __GetNodes(pRoot->right);
	if (left_count + right_count + 1 < k) {
		return -1;
	}
	else if (left_count + 1 == k) {
		return pRoot->val;
	}
	else if (left_count +1 < k) {
		return KthNode(pRoot->right, k - left_count - 1);
	}
	else {
		return KthNode(pRoot->left, k);
	}
}

TreeNode *mod_tree::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.size() != vin.size() || pre.size() == 0) {
		return NULL;
	}

	vector<int> prev_left, prev_right, vin_left, vin_right;

	TreeNode *root = new TreeNode(pre[0]);
	int index;
	int ix = 0;

	for (ix = 0; ix < vin.size(); ix++) {
		if (vin[ix] == pre[0]) {
			index = ix;
			break;
		}
	}

	for (ix = 0; ix < index; ix++) {
		/*left*/
		prev_left.push_back(pre[ix + 1]);
		vin_left.push_back(vin[ix]);
	}
	for (ix = index+1; ix < vin.size(); ix++) {
		/*right*/
		prev_right.push_back(pre[ix]);
		vin_right.push_back(vin[ix]);
	}

	root->right = reConstructBinaryTree(prev_right, vin_right);
	root->left = reConstructBinaryTree(prev_left, vin_left);


	return root;
}

bool mod_tree::__IsSame(TreeNode *pRoot1, TreeNode *pRoot2)
{
	bool left = true, right = true;
	if (!pRoot1 || pRoot1->val != pRoot2->val) {
		return false;
	}
	if (pRoot2->left) {
		left = __IsSame(pRoot1->left, pRoot2->left);
	}
	if (pRoot2->right) {
		right = __IsSame(pRoot1->right, pRoot2->right);
	}

	return left && right;
}

bool mod_tree::HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
	if (!pRoot2 || !pRoot1) {
		return false;
	}

	if (__IsSame(pRoot1, pRoot2)) {
		return true;
	}

	if (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2)) {
		return true;
	}
	else {
		return false;
	}
}

TreeNode *mod_tree::Mirror(TreeNode *pRoot)
{
	if (!pRoot) {
		return NULL;
	}
	pRoot->right = Mirror(pRoot->left);
	pRoot->left = Mirror(pRoot->right);

	return pRoot;
}
vector<int> mod_tree::PrintFromTopToBottom(TreeNode *root)
{
	vector<int> vec;
	queue<TreeNode *> que; 

	if (!root) {
		return vec;
	}

	que.push(root);
	while (!que.empty()) {
		TreeNode *cur = que.front();
		que.pop();
		vec.push_back(cur->val);
		if (cur->left) {
			que.push(cur->left);
		}
		if (cur->right) {
			que.push(cur->right);
		}
	}
	return vec;
}
bool mod_tree::__check(vector<int> vec, int left, int right)
{
	if (left >= right) {
		return true;
	}

	int root = vec[right];
	int ix = 0;
	for (ix = left; ix < right; ix++) {
		if (root < vec[ix]) {
			break;
		}
	}
	for (int jx = ix; jx < right; jx++) {
		if (root > vec[jx]) {
			return false;
		}
	}
	return __check(vec, left, ix - 1) && __check(vec, ix, right - 1);
}
bool mod_tree::VerifySquenceOfBSF(vector<int> sequence)
{
	if (sequence.empty()) {
		return false;
	}
	int len = sequence.size();
	return __check(sequence, 0, len - 1);
}
bool mod_tree::hasPathSum(TreeNode *root, int sum)
{
	if (!root) {
		return false;
	}
	
	if (!root->left && !root->right && sum - root->val == 0) {
		return true;	
	}
	bool left = true, right = true;
	left  = hasPathSum(root->left, sum - root->val);
	right  = hasPathSum(root->right, sum - root->val);

	return left || right; 
}
void mod_tree::__FindPath(TreeNode *root, int target)
{
	if (!root) {
		return;
	}

	cur_vec.push_back(root->val);
	target -= root->val;
	if (!root->left && !root->right && target == 0) {
		ans.push_back(cur_vec);
	}

	__FindPath(root->left, target);
	__FindPath(root->right, target);

	cur_vec.pop_back();
}
vector<vector<int> > mod_tree::FindPath(TreeNode *root, int expectNumber)
{
	__FindPath(root, target);

	return ans;
}
void mod_tree::__Convert(TreeNode *pRootOfTree)
{
	if (!pRootOfTree) {
		return;
	}
	Convert(pRootOfTree->left);

	if (!prev) {
		head = pRootOfTree;
	}
	else {
		pRootOfTree->left = prev;
		prev->right = pRootOfTree;
	}
	prev = pRootOfTree;

	Convert(pRootOfTree->right);
}
TreeNode *mod_tree::Convert(TreeNode *pRootOfTree)
{
	__Convert(pRootOfTree);

	return head;
}
int mod_tree::__DepthOfTree(TreeNode *pRoot)
{
	if (!pRoot) {
		return 0;
	}
	int left = __DepthOfTree(pRoot->left);
	if (left == -1) {
		return -1;
	}
	int right = __DepthOfTree(pRoot->right);
	if (right == -1) {
		return -1;
	}

	int sub = left > right ? left - right : right - left;
	if (sub > 1) {
		return -1;
	}
	return left > right ? left + 1 : right + 1;
}
bool mod_tree::IsBalanced_Solution(TreeNode *pRoot)
{
	return __DepthOfTree(pRoot) != -1;
}
TreeLinkNode *GetNext(TreeLinkNode * pNode)
{
	if (!pNode) {
		return pNode;
	}

	if (pNode->right) {
		pNode = pNode->right;
		while (pNode->left) {
			pNode = pNode->left;
		}
		return pNode;
	}

	while (pNode->next) {
		TreeLinkNode *root = pNode->next;
		if (root->left == pNode) {
			return root;
		}
		pNode = pNode->next;
	}

	return NULL;
}

void mod_tree::__Print(vector<TreeNode *> &vec, int left, int right)
{
	vector<int> tmp;
	if (right - left < 0) {
		return;
	}
	for (int ix = left; ix < right; ix++) {
		TreeNode *cur = vec[ix];
		if (cur->left) {
			vec.push_back(cur->left);
		}
		if (cur->right) {
			vec.push_back(cur->right);
		}
		tmp.push_back(cur->val);
	}
	ans.push_back(tmp);
	__Print(vec, right, vec.size());
}
vector<vector<int> > mod_tree::Print(TreeNode *pRoot)
{
	vector<TreeNode *> vec;
	if (!pRoot) {
		return ans;
	}
	vec.push_back(pRoot);
	__Print(vec, 0, vec.size());

	return ans;
}
char *mod_tree::serialize(TreeNode *root)
{
	string str;
	queue<TreeNode *> qu;

	qu.push(root);
	while (!qu.empty()) {
		TreeNode *node = qu.front();
		qu.pop();
		if (node == NULL) {
			str.push_back('#');
			str.push_back(',');
			continue;
		}

		str += to_string(node->val);
		str.push_back(',');

		qu.push(node->left);
		qu.push(node->right);
	}

	char *ret_val = new char(s.length() + 1);
	strcpy(ret_val, str.c_str());

	return ret_val;
}

TreeNode *mod_tree::deserialize(char *str)
{
	if (!str) {
		return NULL:
	}

	string s(str);
	if (s[0] == '#') {
		return NULL;
	}

	queue<TreeNode *>qu;
	TreeNode *ret = new TreeNode(atoi(s.c_str()));
	s = s.substr(s.find_first_of(',') + 1);
	qu.push(ret);

	while (!qu.empty() && !s.empty()) {
		TreeNode *node = qu.front();
		qu.pop();
		if (s[0] == '#') {
			node->left = NULL;
			s = s.substr(2);
		}
		else {
			node->left = new TreeNode(atoi(s.c_str()));
			qu.push(node->left);
			s = s.substr(s.find_first_of(',') + 1);
		}
		if (s[0] == '#') {
			node->right = NULL;
			s = s.substr(2);
		}
		else {
			node->right = new TreeNode(atoi(s.c_str()));
			qu.push(node->right);
			s = s.substr(s.find_first_of(',') + 1);
		}
	}

	return ret;
}

void mod_tree::__FindPath_ex(TreeNode *root, int sum)
{
	if (sum == 0) {
		total++;
	}
	if (root->left) {
		__FindPath_ex(root->left, sum - root->val);
	}
	if (root->right) {
		__FindPath_ex(root->right, sum - root->val);
	}
}
void mod_tree::__inorder(TreeNode *root, int sum)
{
	if (!root) {
		return;
	}
	__FindPath_ex(root, sum);
	if (root->left) {
		__inorder(root->left, sum);
	}
	if (root->right) {
		__inorder(root->right, sum);
	}
}
int mod_tree::FindPath(TreeNode *root, int sum)
{
	if (!root) {
		return 0;
	}
	__inorder(root, sum);

	return total;
}
bool mod_tree::__FindNode(TreeNode *root, int val)
{
	if (!root) {
		return false;
	}
	if (root->val == val) {
		return true;
	}

	bool left = false, right = false;

	return __FindNode(root->left, val) || __FindNode(root->right, val);
}
void mod_tree::__lowestCommonAncestor(TreeNode *root, int o1, int o2)
{
	if (!root) {
		return;
	}
	if (find == 0 && root->val != o1) {
		if (find == 0 &&root->left) {
			__lowestCommonAncestor(root->left, o1, o2);
			if (find == 2) {
				if (root->val == o2) {
					ret_val = root->val;
					find = 3;
				}
				if (find == 2 && root->right && __FindNode(root->right, o2)) {
					find = 3;
					ret_val = root->val;
				}
			}
		}
		if (find == 0 && root->right) {
			__lowestCommonAncestor(root->right, o1, o2);
			if (find == 2) {
				if (root->val == o2) {
					ret_val = root->val;
					find = 3;
				}
				if (find == 2 && root->left && __FindNode(root->left, o2)) {
					find = 3;
					ret_val = root->val;
				}
			}
		}
	}
	else if (root->val == o1) {
		find = 1;
	}
	if (find == 1 && root->left) {
		if (__FindNode(root->left, o2)) {
			find = 3;
			ret_val = root->val;
		}
	}
	if (find == 1 && root->right) {
		if (__FindNode(root->right, o2)) {
			find = 3;
			ret_val = root->val;
		}
	}
	if (find == 1) {
		find = 2;
	}
	return;
}
int mod_tree::lowestCommonAncestor(TreeNode *root, int o1, int o2)
{
	__lowestCommonAncestor(root, o1, o2);
	return ret_val;
}
int mod_tree::lowestCommonAncestor_sort(TreeNode *root, int p, int q)
{
	if (!root) {
		return -1;
	}

	if (p > q) {
		int tmp = q;
		q = p;
		p = tmp;
	}

	if (root->val == p && root->val == q) {
		return root->val;
	}
	else if (root->val > q) {
		if (root->left) {
			return lowestCommonAncestor_sort(root->left, p, q);
		}
		else {
			return -1;
		}
	}
	else if (root->val < p) {
		if (root->right) {
			return lowestCommonAncestor_sort(root->right, p, q);
		}
		else {
			return -1;
		}
	}
	else {
		return root->val;
	}
}
