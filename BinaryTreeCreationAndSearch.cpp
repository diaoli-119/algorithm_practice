
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(nullptr),right(nullptr){}
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode *right):val(x), left(left), right(right){}
};

void CreateBinarySearchTree(TreeNode * leaf, int key)
{
	if (key < leaf->val)
	{
		if (!leaf->left)
			leaf->left = new TreeNode(key);
		else
			CreateBinarySearchTree(leaf->left, key);
	}
	else if (key >= leaf->val)
	{
		if (!leaf->right)
			leaf->right = new TreeNode(key);
		else
			CreateBinarySearchTree(leaf->right, key);
	}
}

void CreateBinaryTreeWithBFS(TreeNode *node, int val)
{
	if (!node) return;
	std::queue<TreeNode*> q;
	q.push(node);

	TreeNode* n;
	int qLen;
	if (!q.empty())
	{
		qLen = q.size();
		for (int i = 0; i < qLen; i++)
		{
			n = q.front();
			q.pop();
			if (!n->left)
			{
				n->left = new TreeNode(val);
				q.push(n->left);
				return;
			}
			else
				q.push(n->left);

			if (!n->right)
			{
				n->right = new TreeNode(val);
				q.push(n->right);
				return;
			}
			else
				q.push(n->right);
			qLen = q.size();
		}
	}
}

int deepestLeavesSum(TreeNode* root) 
{
	std::queue<TreeNode*> q;
	q.push(root);
	int sum;
	TreeNode* popNode;
	while (!q.empty())
	{
		sum = 0;
		for (int i = 0; i < q.size(); i++)
		{
			popNode = q.front();
			q.pop();
			sum += popNode->val;
			if (popNode->left) q.push(popNode->left);
			if (popNode->right) q.push(popNode->right);
		}
	}
	return sum;
}

TreeNode* callCreateBinaryTree()
{
	int depth = 0;
	cout << "input depth of BT:";
	cin >> depth;
	cout << "input int values for the root:";
	int i;
	cin >> i;
	TreeNode* root = new TreeNode();
	root->val = i;

	cout << "input int values for BT, end with '#': ";
	while (true)
	{
		cin >> i;
		if ( i == -1)break;
		CreateBinaryTreeWithBFS(root, i);
	}
	return root;
}