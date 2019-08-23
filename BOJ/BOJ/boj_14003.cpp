#include<iostream>
#include<climits>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int v):val(v),left(0),right(0){}
	Node() {}
};

int N;
Node nodePool[1000001];
int nodeIdx;
int m, sz;
Node *root;

Node* getNode(int v) {
	nodePool[nodeIdx].val = v;
	nodePool[nodeIdx].left = NULL;
	nodePool[nodeIdx].right = NULL;
	return &nodePool[nodeIdx++];
}

void _insert(Node* n, int v) {

	if (n->val > v) {
		if (n->left == NULL) {
			n->left = getNode(v);
			sz++;
			return;
		}
		else
			_insert(n->left, v);
	}
	else if (n->val < v) {
		if (n->right == NULL) {
			n->right = getNode(v);
			sz++;
			return;
		}
		else
			_insert(n->right, v);
	}
}

void _update(Node *n, int v) {

	if (n->val < v) {
		if (n->right == NULL) {
			n->val = v;
			m = v;
		}
		else
			_update(n->right, v);
	}
	else if (n->val > v) {
		if (n->left == NULL)
			n->val = v;
		else
			_update(n->left, v);
	}
	else {
		m = v;
	}
}

void inorder(Node *n) {
	if (n == NULL) return;
	inorder(n->left);
	printf("%d ", n->val);
	inorder(n->right);
}

int main() {
	//freopen("input.txt","r",stdin);
	int num;
	scanf("%d", &N);
	scanf("%d", &num);
	root = getNode(num);

	sz = 1;
	m = num;
	for (int i = 1; i < N; i++) {
		scanf("%d", &num);

		if (m < num) {
			m = num;
			_insert(root, num);
		}
		else {
			_update(root, num);
		}
	}
	printf("%d\n",sz);
	inorder(root);
	return 0;
}