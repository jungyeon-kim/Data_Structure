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
//		printf("포화상태입니다.");
//	rear = (rear + 1) % MAX_QUEUE_SIZE;
//	data[rear] = val;
//}
//Element dequeue()
//{
//	if (is_empty())
//		printf("공백상태입니다.");
//	front = (front + 1) % MAX_QUEUE_SIZE;
//	return data[front];
//}
//Element peek()
//{
//	if (is_empty())
//		printf("공백상태입니다.");
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

// front: 꺼내야될 원소의 앞, 첫번째 원소의 앞
// rear: 삽입된 마지막 원소
// 선형큐: 시작이 -1, 원형큐: 시작이 0
