#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct BinTrNode {
	TElement	 data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;
TNode*	root;

void init_tree() { root = NULL; }
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; }

TNode* create_tree(TElement val, TNode* l, TNode* r)
{
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

//================================================================
void preorder(TNode *n)
{
	if (n != NULL) {
		printf("[%c] ", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}
void inorder(TNode *n)
{
	if (n != NULL) {
		inorder(n->left);
		printf("[%c] ", n->data);
		inorder(n->right);
	}
}
void postorder(TNode *n)
{
	if (n != NULL) {
		postorder(n->left);
		postorder(n->right);
		printf("[%c] ", n->data);
	}
}

//================================================================
#define MAX_QUEUE_SIZE	100
typedef TNode* Element;

// ���α׷� 4.1�� 6~37�� �߰�
Element data[MAX_QUEUE_SIZE];	// ����� �迭
int	front;			// ����
int	rear;			// �Ĵ�

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
// ť�� �ֿ� ����: ����
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
	if (is_full())
		error("  ť ��ȭ ����");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
Element dequeue()
{
	if (is_empty())
		error("  ť ���� ����");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek()
{
	if (is_empty())
		error("  ť ���� ����");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void levelorder(TNode *root)
{
	TNode* n;

	if (root == NULL) return;
	init_queue();
	enqueue(root);
	while (!is_empty()) {
		n = dequeue();
		if (n != NULL) {
			printf("[%c] ", n->data);
			//print_elem(n);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int count_node(TNode *n)
{
	if (n == NULL) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n)
{
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n)
{
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
}

int is_level(TNode *node1, TNode *node2, int lev)
{

	if (node1 == NULL)
		return 0;
	if (node1 == node2)
		return lev;
	if (node1->left == NULL && node1->right == NULL)
		return 0;
	
	int letf = is_level(node1->left, node2, lev + 1);
	int right = is_level(node1->right, node2, lev + 1);

	if (!letf)
		return right;
	else
		return letf;
}

int level(TNode* node)
{
	return is_level(root, node, 1);
}

int is_balanced(TNode *n)
{
	int hLeft, hRight;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);

	if (abs(hLeft - hRight) < 2)
		printf(" ���� ���� �ִ�.\n");
	else
		printf(" ���� �������� �ʴ�.\n");
}

int path_length(TNode* root)
{
	TNode* n;
	if (root == NULL) return;
	init_queue();
	enqueue(root);
	int sum = 0;
	while (!is_empty())
	{
		n = dequeue();
		sum += level(n) - 1;
		if (n != NULL)
		{
			if (n->left)
				enqueue(n->left);
			if (n->right)
				enqueue(n->right);
		}
	}
	return sum;
}

void main()
{
	TNode *b, *c, *d, *e, *f, *g, *h, *i;

	init_tree();
	i = create_tree('I', NULL, NULL);
	h = create_tree('H', NULL, NULL);
	d = create_tree('D', h, i);
	e = create_tree('E', NULL, NULL);
	b = create_tree('B', d, e);
	//f = create_tree('F', NULL, NULL);
	c = create_tree('C', NULL, NULL);
	root = create_tree('A', b, c);

	// Ʈ�� �׽�Ʈ ���α׷� �߰� 
	printf("\nLevel-Order : ");	levelorder(root);
	printf("\n");

	printf(" ����� ���� = %d\n", count_node(root));
	printf(" �ܸ��� ���� = %d\n", count_leaf(root));
	printf(" Ʈ���� ���� = %d\n", calc_height(root));
	is_balanced(root);
	printf(" ����� ���� �� = %d\n", path_length(root));
}

