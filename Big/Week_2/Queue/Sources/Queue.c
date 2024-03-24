#include<Queue.h>
int flag = 0;
LinkQueue* queue;
int main()
{
	SetConsoleOutputCP(65001);
	queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	printf("-------------------\n");
	printf("链式存储的泛型队列\n");
	printf("-------------------\n");
	while (1)
	{
		printf("1、初始化队列\n");
		printf("2、元素入队\n");
		printf("3、元素出队\n");
		printf("4、清空队列\n");
		printf("5、销毁队列\n");
		printf("6、查看队头\n");
		printf("7、队列长度\n");
		printf("8、队列判空\n");
		printf("9、打印队列\n");
		printf("请选择你的操作：\n");
		int choice;
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			system("cls");
			if (flag == 1)
			{
				printf("已经初始化，请勿重新操作！\n");
			}
			else {
				initQueue(queue);
			}
			break;
		case 2:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				printf("1、整型\n");
				printf("2、字符型\n");
				printf("3、字符串型(请勿尝试）\n");
				printf("4、浮点型\n");
				printf("请输入要入队的元素类型：");
				int choice;
				scanf_s("%d", &choice);
				getchar();
				switch (choice)
				{
				case 1:
					EnQueue(queue, (void*)readnumber());
					break;
				case 2:
					EnQueue(queue, (void*)readChar());
					break;
				case 3:
					EnQueue(queue, (void*)readString());
					break;
				case 4:
					EnQueue(queue, (void*)readFloat());
					break;
				default:
					printf("无效操作，请重新输入！\n");
				}
			}
			break;
		case 3:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				DeQueue(queue);
			}
			break;
		case 4:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				cleanQueue(queue);
			}
			break;
		case 5:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				destoryQueue(queue);
			}
			break;
		case 6:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				checkhead(queue);
			}
			break;
		case 7:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				checklength(queue);
			}
			break;
		case 8:
			system("cls");
			if (flag == 0)
			{
				printf("请先初始化队列！\n");
			}
			else {
				isEmpty(queue);
			}
			break;
		case 9:
			system("cls");
			printQueue(queue);
			break;
		default:
			printf("无效操作，请重新输入！\n");
		}
	}
}
void initQueue(LinkQueue* queue)
{
	queue->head=NULL;
	queue->tail=NULL;
	queue->length = 0;
	flag = 1;
	printf("初始化成功！\n");
}
void EnQueue(LinkQueue* queue, void* data)
{
	QNode* Node = (QNode*)malloc(sizeof(QNode));
	Node->data = data;
	Node->next = NULL;
	if (queue->tail == NULL)
	{
		queue->head = queue->tail = Node;
		queue->length++;
	}
	else
	{
		queue->tail->next = Node;
		queue->tail = Node;
		queue->length++;
		printf("入队成功！\n");
	}
}
void printQueue(LinkQueue* queue)
{
	if (queue->head == NULL)
	{
		printf("队列现在为空！\n");
		return;
	}
	else
	{
		QNode* p = queue->head;
		printf("队列现在的元素为：");
		while (p != NULL)
		{
			if(('a'<=p->data&&p->data<='z')|| ('A' <= p->data && p->data <= 'Z'))
			{
				printf("%c ",p->data);
			}
			else {
				printf("%d ", p->data);
			}
			p = p->next;
		}
	}
	printf("\n");
}
long long readnumber(){
	long long data;
	printf("请输入一个整数数据: ");
	scanf_s("%ld", &data);
	return data;
}
char readChar(){
	char data;
	printf("请输入一个字符: ");
	scanf_s(" %c", &data); 
	return data;
}
char* readString(){
	char string[100];
	printf("请输入字符串: ");
	scanf_s("%s", string);
	return string;
}
void* readFloat() {
	float value;
	printf("请输入一个浮点型的数据: ");
	scanf_s("%f", &value);
	return (void*)&value;
}
void DeQueue(LinkQueue* queue)
{
	if (queue->head == NULL)
	{
		printf("队列为空！\n");
		return;
	}
	QNode* p = queue->head;
	queue->head = p->next;
	free(p);
	queue->length--;
	printf("出队成功！\n");
	printQueue(queue);
}
void checkhead(LinkQueue* queue)
{
	if (queue->head == NULL)
	{
		printf("队列为空！\n");
		return;
	}
	else
	{
		printf("队头的元素为：%d", queue->head->data);
		printf("\n");
	}
}
void checklength(LinkQueue* queue)
{
	printf("队列长度为:%d\n", queue->length);
}
void isEmpty(LinkQueue* queue)
{
	if (queue->head == NULL)
	{
		printf("现在队列为空！\n");
	}
	else
	{
		printf("现在队列不为空！\n");
	}
}
void cleanQueue(LinkQueue* queue)
{
	if (queue->head == NULL)
	{
		printf("现在队列为空！\n");
	}
	else {
		while (queue->head != NULL) {
			QNode* temp = queue->head;
			queue->head = temp->next;
			free(temp); 
		}
		queue->tail = NULL;
		queue->length = 0;
		printf("清空成功！\n");
	}
}
void destoryQueue(LinkQueue* queue)
{
		while (queue->head != NULL) {
			QNode* temp = queue->head;
			queue->head = temp->next;
			free(temp);
		}
		flag = 0;
		printf("销毁成功！\n");
}