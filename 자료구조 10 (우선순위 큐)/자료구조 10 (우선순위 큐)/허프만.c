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

// 초기화 함수
init(HeapType *h)
{
	h->heap_size = 0;
}
// 삽입 함수
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "메모리 에러\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}
// 이진 트리 제거 함수
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
			str[strlen(str) - 1] = '\0';   // 되돌아온 노드의 출력값 지우기
	}
	if (root->left_child == NULL && root->right_child == NULL) {
		printf("%s ", str);
		str[strlen(str) - 1] = '\0';   // 출력한 단말노드의 출력값 지우기
	}
}

// 허프만 코드 생성 함수
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
		e.key = node->weight = freq[i]; //원소의 키값으로 빈도수를 저장
		e.ptree = node; //새로 생긴 노드의 주소값을 원소의 ptree 필드에 저장
		insert_min_heap(&heap, e);  // 두 필드를 가진 원소를 힙에 삽입
	}
	for (i = 1; i<n; i++) {
		e1 = delete_min_heap(&heap);		// 최소값을 가지는 두개의 노드를 삭제
		e2 = delete_min_heap(&heap);
		x = make_tree(e1.ptree, e2.ptree); // 두개의 노드를 합쳐서 새로운 노드를 만듦
		e.key = x->weight = e1.key + e2.key;// 새 노드의 키값으로 두 빈도수 합을 저장
		e.ptree = x;   // 새 노드의 주소를 ptree 필드에 저장
		insert_min_heap(&heap, e); // 한번수행할 때마다 힙원소는 줄어들고 트리는 커짐
	}                              // 마지막에 힙 노드는 한개만 남고 트리도 하나만 됨
	e = delete_min_heap(&heap); // 최종 트리
	print_huffman(str, e.ptree);
	destroy_tree(e.ptree);
}
// 주함수 
void main()
{
	int freq[] = { 15, 12, 8, 6, 4 };
	huffman_tree(freq, 5);
}
