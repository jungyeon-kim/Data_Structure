//#include<stdio.h>
//
//#define MAX_QUEUE_SIZE 10
//#define Element int
//
//Element data[MAX_QUEUE_SIZE];
//int front;
//int rear;
//
//void init_queue() { front = rear = 0; }
//int is_empty() { return front == rear; }
//int is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front % MAX_QUEUE_SIZE; }
//int size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }
//
//void enqueue(Element val)
//{
//	if (is_full())
//		printf("��ȭ�����Դϴ�.");
//	rear = (rear + 1) % MAX_QUEUE_SIZE;
//	data[rear] = val;
//}
//Element dequeue()
//{
//	if (is_empty())
//		printf("��������Դϴ�.");
//	front = (front + 1) % MAX_QUEUE_SIZE;
//	return data[front];
//}
//Element peek()
//{
//	if (is_empty())
//		printf("��������Դϴ�.");
//	return data[(front + 1) % MAX_QUEUE_SIZE];
//}
//
//int main()
//{
//	int i;
//	init_queue();
//	for (i = 1; i<10; i++)
//		enqueue(i);
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//	printf("\tdequeue() --> %d\n", dequeue());
//}

// front: �����ߵ� ������ ��, ù��° ������ ��
// rear: ���Ե� ������ ����
// ����ť: ������ -1, ����ť: ������ 0
