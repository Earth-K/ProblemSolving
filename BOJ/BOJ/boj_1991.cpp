#include<iostream>
using namespace std;
/*
	2019. 07. 23.
	백준 1991. 트리 순회
*/

struct Node {
	char alp;
	Node *left, *right;
	Node(char alp):alp(alp),left(0),right(0){}
	Node(){}
};

int N;

class _tree {
public:

	Node *p[26], *root;

	_tree(char ch) { 
		root = new Node(ch); 
		p[0] = root; 
	}
	_tree() {}

	void insert(char target, char ch, int type) {
		if (ch == '.') return;

		Node *newNode = new Node(ch);
		Node *t = p[target - 'A'];

		if(type == 0)	
			t->left = newNode;
		else  
			t->right = newNode;

		p[ch - 'A'] = newNode;
	}
};

void preoder(Node *t) {
	if (t == 0) return;
	printf("%c", t->alp);
	preoder(t->left);
	preoder(t->right);
}
void inoder(Node *t) {
	if (t == 0) return;
	inoder(t->left);
	printf("%c", t->alp);
	inoder(t->right);
}
void postoder(Node *t) {
	if (t == 0) return;
	postoder(t->left);
	postoder(t->right);
	printf("%c", t->alp);
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);
	_tree *tree = new _tree('A');

	for (int i = 0; i < N; i++) {
		char ch[4];
		cin >> ch[0] >> ch[1] >> ch[2];

		tree->insert(ch[0], ch[1], 0);
		tree->insert(ch[0], ch[2], 1);
	}

	preoder(tree->root);
	printf("\n");
	inoder(tree->root);
	printf("\n");
	postoder(tree->root);

	return 0;
}