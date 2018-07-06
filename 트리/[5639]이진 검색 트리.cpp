#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

class Node {
public:
	Node* left = NULL;
	Node* right = NULL;
	int id = 0;
};

class Tree {
public:
	Node* root = NULL;

	void insert(int input) {
		Node* node = new Node;
		node->id = input;

		if (root == NULL) {
			root = node;
			return;
		}

		Node* curr = root;
		while (1) {

			if (input < curr->id) {
				if (curr->left == NULL) {
					curr->left = node;
					return;
				}
				else
					curr = curr->left;
			}
			else {
				if (curr->right == NULL) {
					curr->right = node;
					return;
				}
				else
					curr = curr->right;
			}
		}
	}

	void postOrder(Node* node) {
		if (node == NULL)
			return;

		postOrder(node->left);
		postOrder(node->right);

		printf("%d\n", node->id);
	}

};

int main() {
	Tree tree;
	int input;
	while (scanf("%d", &input) != EOF)
		tree.insert(input);
	tree.postOrder(tree.root);
}