#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

struct BSTNode {
	int data;
	BSTNode *left;
	BSTNode *right;
};

class BST {
public:
	BSTNode* getNewNode(int data) {
		BSTNode *newNode = new BSTNode();
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	BSTNode* insert(BSTNode* root, int data) {
		//empty tree
		if (root == NULL) {
			root = getNewNode(data);
		}
		//data is less than root vale
		else if (data <= root->data) {
			root->left = insert(root->left, data);
		}
		//data is greater than the root value
		else {
			root->right = insert(root->right, data);
		}
		return root;
	}

	int findMin(BSTNode *root) {
		//empty tree
		if (root == NULL) {
			cout << "Error: Tree is empty!";
			return -1;
		}

		while (root->left != NULL) {
			root = root->left;
		}
		return root->data;
	}

	BSTNode* findMinNode(BSTNode *root) {
		//empty tree
		if (root == NULL) {
			cout << "Error: Tree is empty!";
			return root;
		}

		while (root->left != NULL) {
			root = root->left;
		}
		return root;
	}


	int findMinRecursive(BSTNode *root) {
		//empty tree
		if (root == NULL) {
			cout << "Error: Tree is empty!";
			return -1;
		}

		else if (root->left == NULL) {
			return root->data;
		}
		return findMinRecursive(root->left);
	}

	int findMax(BSTNode *root) {
		//empty tree
		if (root == NULL) {
			cout << "Error: Tree is empty!";
			return -1;
		}

		while (root->right != NULL) {
			root = root->right;
		}
		return root->data;
	}

	int findMaxRecursive(BSTNode *root) {
		//empty tree
		if (root == NULL) {
			cout << "Error: Tree is empty!";
			return -1;
		}

		else if (root->right == NULL) {
			return root->data;
		}
		return findMaxRecursive(root->right);
	}

	int findHeight(BSTNode *root) {
		if (root == NULL)
		{
			return 0;
		}
		return 1+max(findHeight(root->left), findHeight(root->right));
	}

	bool search(BSTNode *root, int data) {
		if (root == NULL) return false;
		else if (root->data == data) return true;
		else if (data <= root->data) return search(root->left, data);
		else return search(root->right, data);
	}

	BSTNode* findNode(BSTNode *root, int data) {
		if (root == NULL) return root;
		else if (root->data == data) return root;
		else if (data <= root->data) return findNode(root->left, data);
		else return findNode(root->right, data);
	}


	BSTNode* deleteNode(BSTNode *root, int data) {
		if (root == NULL) {
			return root;
		}
		//searching in left subtree
		else if (data < root->data) {
			root->left = deleteNode(root->left, data);
		}
		//searching in right subtree
		else if (data > root->data) {
			root->right = deleteNode(root->right, data);
		}
		//found the node to delete
		else {
			//case 1: No child
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
			}
			//case 2: One child
			else if (root->left == NULL) {
				BSTNode* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL) {
				BSTNode *temp = root;
				root = root->left;
				delete temp;
			}
			//case3: two children
			else {
				BSTNode *temp = findMinNode(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}

	void levelOrder(BSTNode *root) {
		//empty tree
		if (root == NULL) {
			return;
		}

		queue<BSTNode*> Q;
		Q.push(root);
		//while there are elements to process
		while (!Q.empty()) {
			BSTNode *current = Q.front();
			cout << current->data << " ";
			if (current->left != NULL) {
				Q.push(current->left);
			}
			if (current->right != NULL) {
				Q.push(current->right);
			}
			Q.pop(); //removing the visited node from front
		}
		cout << endl;
	}

	void preOrder(BSTNode *root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

	void inOrder(BSTNode *root) {
		if (root == NULL) {
			return;
		}
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

	void postOrder(BSTNode *root) {
		if (root == NULL) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}

	bool isBinarySearchTreeUtil(BSTNode *root, int minValue, int maxValue) {
		if (root == NULL) {
			return true;
		}

		if (root->data > minValue
			&& root->data < maxValue
			&& isBinarySearchTreeUtil(root->left, minValue, root->data)
			&& isBinarySearchTreeUtil(root->right, root->data, maxValue)) {
			return true;
		}
		else 
			return false;
		}

	bool isBinarySearchTree(BSTNode *root) {
		int minValue = numeric_limits<int>::min();
		int maxValue = numeric_limits<int>::max();
		bool result = isBinarySearchTreeUtil(root, minValue, maxValue);
		return result;
	}

	BSTNode* getSuccessor(BSTNode *root, BSTNode *current) {
		if (current == NULL) {
			return NULL;
		}
		//case 1: Node has a right subtree
		if (current->right != NULL) {
			return findMinNode(current->right); // O(h)
		}
		//case 2: No right subtree
		BSTNode *successor = NULL;
		BSTNode *ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor; //so far this is the deepest node for which the current node is in left
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}

};

int main() {
	BSTNode* root = NULL; //creating an empty tree
	BST obj;

	root = obj.insert(root, 12);
	root = obj.insert(root, 15);
	root = obj.insert(root, 5);
	root = obj.insert(root, 3);
	root = obj.insert(root, 7);
	root = obj.insert(root, 1);
	root = obj.insert(root, 9);
	root = obj.insert(root, 13);
	root = obj.insert(root, 17);
	
	//finding min
	int min_value = obj.findMin(root);
	cout << "Minimum value: " << min_value << endl;

	//finding max
	int max_value = obj.findMax(root);
	cout << "Maximum value: " << max_value << endl;

	//finding min and max recursively
	min_value = obj.findMinRecursive(root);
	cout << "Minimum value(Recursive): " << min_value << endl;
	min_value = obj.findMaxRecursive(root);
	cout << "Minimum value(Recursive): " << max_value << endl;

	//height
	cout << "Height: " << obj.findHeight(root) << endl;

	//level order traversal
	cout << "Level Order Traversal : "; 
	obj.levelOrder(root);

	//preoder, inorder and postorder;
	cout << "PreOrder Traversal : ";
	obj.preOrder(root);
	cout << endl;
	cout << "InOrder Traversal : ";
	obj.inOrder(root);
	cout << endl;
	cout << "PostOrder Traversal : ";
	obj.postOrder(root);
	cout << endl;

	//isBST
	bool isBST = obj.isBinarySearchTree(root);
	cout << "Is it a Binary Search Tree? :" << isBST << endl;
	
	//delete
	root = obj.deleteNode(root, 12);
	cout << "Root after deleting old root(12) :" << root->data << endl;

	//Searching a number based on user input
	int num;
	cout << "Enter the number: ";
	cin >> num;
	if (obj.search(root, num)) {
		cout << "Number found!";
	}
	else {
		cout << "Number not found";
	}

	return 0;
}