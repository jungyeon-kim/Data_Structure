#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 100
#define STR_LENGTH 80
typedef struct TreeNode {
	int weight;
	struct TreeNode *left_child;
	struct TreeNode *right_child;
} TreeNode;
typedef struct {
	TreeNode *ptree;
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// �ʱ�ȭ �Լ�
init(HeapType *h)
{
	h->heap_size = 0;
}
// ���� �Լ�
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ���� Ʈ�� ���� �Լ�
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "�޸� ����\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}
// ���� Ʈ�� ���� �Լ�
void destroy_tree(TreeNode *root)
{
	if (root == NULL) return;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	free(root);
}

void print_huffman(char *str, TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	if (root->left_child) {
		strcat_s(str, STR_LENGTH, "1");
		print_huffman(str, root->left_child);
	}
	if (root->right_child) {
		strcat_s(str, STR_LENGTH, "0");
		print_huffman(str, root->right_child);
	}
	if (root->left_child || root->right_child) {
		if (strlen(str)>0)
			str[strlen(str) - 1] = '\0';   // �ǵ��ƿ� ����� ��°� �����
	}
	if (root->left_child == NULL && root->right_child == NULL) {
		printf("%s ", str);
		str[strlen(str) - 1] = '\0';   // ����� �ܸ������ ��°� �����
	}
}

// ������ �ڵ� ���� �Լ�
void huffman_tree(int freq[], int n)
{
	int i;
	TreeNode *node, *x;
	HeapType heap;
	element e, e1, e2;
	char str[STR_LENGTH] = { "\0" };

	init(&heap);
	for (i = 0; i<n; i++) {
		node = make_tree(NULL, NULL);
		e.key = node->weight = freq[i]; //������ Ű������ �󵵼��� ����
		e.ptree = node; //���� ���� ����� �ּҰ��� ������ ptree �ʵ忡 ����
		insert_min_heap(&heap, e);  // �� �ʵ带 ���� ���Ҹ� ���� ����
	}
	for (i = 1; i<n; i++) {
		e1 = delete_min_heap(&heap);		// �ּҰ��� ������ �ΰ��� ��带 ����
		e2 = delete_min_heap(&heap);
		x = make_tree(e1.ptree, e2.ptree); // �ΰ��� ��带 ���ļ� ���ο� ��带 ����
		e.key = x->weight = e1.key + e2.key;// �� ����� Ű������ �� �󵵼� ���� ����
		e.ptree = x;   // �� ����� �ּҸ� ptree �ʵ忡 ����
		insert_min_heap(&heap, e); // �ѹ������� ������ �����Ҵ� �پ��� Ʈ���� Ŀ��
	}                              // �������� �� ���� �Ѱ��� ���� Ʈ���� �ϳ��� ��
	e = delete_min_heap(&heap); // ���� Ʈ��
	print_huffman(str, e.ptree);
	destroy_tree(e.ptree);
}
// ���Լ� 
void main()
{
	int freq[] = { 15, 12, 8, 6, 4 };
	huffman_tree(freq, 5);
}
