#include <iostream>

class TreeNode
{
public:
	TreeNode(const std::string &s = std::string(""), int c = 0, TreeNode *l = nullptr, TreeNode *r = nullptr) :
		value(s), count(c), left(l), right(r) { }
	TreeNode(const TreeNode &orig);
	TreeNode &operator=(const TreeNode &rhs);
	~TreeNode();
	void set_left(TreeNode *l) { left = l; }
	void set_right(TreeNode *r) { right = r; }
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode::TreeNode(const TreeNode &orig)
{
	TreeNode *temp_left = nullptr;
	TreeNode *temp_right = nullptr;

	if (orig.left != nullptr)
	{
		temp_left = new TreeNode(*orig.left);
	}
	if (orig.right != nullptr)
	{
		temp_right = new TreeNode(*orig.right);
	}
	left = temp_left;
	right = temp_right;
	count = orig.count;
	value = orig.value;
}

TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
	TreeNode *temp_left = nullptr;
	TreeNode *temp_right = nullptr;

	if (rhs.left != nullptr)
	{
		temp_left = new TreeNode(*rhs.left);
	}
	if (rhs.right != nullptr)
	{
		temp_right = new TreeNode(*rhs.right);
	}
	delete left;
	delete right;
	left = temp_left;
	right = temp_right;
	count = rhs.count;
	value = rhs.value;
}

TreeNode::~TreeNode()
{
	delete left;
	delete right;
}


class BinStrTree
{
public:
	BinStrTree(const std::string &s = std::string("")) : root(new TreeNode(s)) { }
	BinStrTree(const BinStrTree &orig);
	BinStrTree &operator=(const BinStrTree &rhs);
	~BinStrTree();
	TreeNode *get_root() { return root; }
private:
	TreeNode *root;
};

BinStrTree::BinStrTree(const BinStrTree &orig) : root(new TreeNode(*orig.root))
{

}

BinStrTree & BinStrTree::operator=(const BinStrTree &rhs)
{
	if (this != &rhs)
	{
		TreeNode *temp = new TreeNode(*rhs.root);
		delete root;
		root = temp;
	}
	return *this;
}

BinStrTree::~BinStrTree()
{
	delete root;
}



int main()
{
	BinStrTree t("root");
	t.get_root()->set_left(new TreeNode("left"));
	t.get_root()->set_right(new TreeNode("right"));



	return 0;
}
