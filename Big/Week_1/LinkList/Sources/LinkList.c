#include<SingleLinkList.h>
int main()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	while (1)
	{
		printf("单链表ADT\n");
		printf("------------------\n");
		printf("1、生成链表\n");
		printf("2、插入数据\n");
		printf("3、删除结点\n");
		printf("4、销毁链表\n");
		printf("5、查找数据\n");
		printf("6、打印链表\n");
		printf("7、奇偶调换(未实现，有问题)\n");
		printf("8、反转链表（非递归）\n");
		printf("9、中间结点\n");
		int choice;
		printf("请输入要选择的操作：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("请输入要生成链表结点的个数：");
			int n;
			scanf_s("%d", &n);
			createLinkList(head,n);
			break;
		case 2:
			printf("请输入要插入的数据：");
			int data;
			scanf_s("%d", &data);
			printf("请输入要插入的编号：");
			int num;
			scanf_s("%d", &num);
			insertNode(head, data, num);
			break;

		case 3:
			printf("请输入要删除结点的编号：");
			int num1;
			scanf_s("%d", &num1);
			deleteNode(head, num1);
			break;
		case 4:
			destroyLinkList(head);
			head = (LNode*)malloc(sizeof(LNode));//重新生成头节点，便于后续操作
			head->next = NULL;
			break;
		case 5:
			printf("请输入要查找的数据：");
			int data1;
			scanf_s("%d", &data1);
			searchData(head, data1);
			break;
		case 6:
			printLinkList(head);
			break;
		case 7:
			exchangeNode(head);
			break;
		case 8:
			reversalList(head);
			break;
		case 9:
			findMiddle(head);
			break;
		default:
			printf("无效操作，请重新输入！\n");
		}
	}
}
LNode* createNode(int data) {
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	newNode->data = data;
	return newNode;
}
void appendNode(LNode* head,int data)
{
	LNode* newNode = createNode(data);
	LNode* p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = newNode;
	newNode->next = NULL;
}
void createLinkList(LNode* head,int n)
{
	int data;
	for (int i = 0; i < n; i++)
	{
		int data;
		printf("请输入第%d个结点的数据：", i + 1);
		scanf_s("%d", &data);
		appendNode(head, data);
	}
	printf("生成链表成功\n");
}
void printLinkList(LNode* head)
{
	if (head->next== NULL)
	{
		printf("链表为空！\n");
		return;
	}
	LNode* p = head->next;
	while (p!= NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void insertNode(LNode* head, int data, int num)
{
	LNode* p;
	p = head->next;
	for (int i = 1; i <num-1; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			printf("插入位置超出范围！");
			return;
		}
	}
	LNode* newNode = createNode(data);
	newNode->next = p->next;
	p->next = newNode;
	printf("数据插入成功\n");
	printLinkList(head);
}
void deleteNode(LNode* head, int num)
{
	LNode* p;
	p = head->next;
	for (int i = 1; i < num - 1; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			printf("删除位置超出范围！\n");
			return;
		}
	}
	LNode* m = p->next;
	p->next = p->next->next;
	free(m);
	printf("结点删除成功!\n");
	printLinkList(head);
}
void destroyLinkList(LNode* head)
{
	LNode* p = head;
	while (p != NULL)
	{
		LNode* m = p;
		p = p->next;
		free(m);
	}
	printf("链表销毁成功！\n");
}
void searchData(LNode* head, int data1)
{
	LNode* p=head->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == data1)
		{
			printf("存在此数据，位于第%d个结点\n", i);
			return;
		}
		p = p->next;
		i++;
	}
	printf("没有此数据！\n");
}
void exchangeNode(LNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	LNode* p = head;
	LNode* k = p->next;
	LNode* m = k->next;
	LNode* a = m->next;
	 while(p->next->next!=NULL)
	{
		m->next = NULL;
		p->next = m;
		m->next = k;
		p = p->next->next;
		k = a->next;
		m = k->next;
		a = a->next->next;
	}
}
void reversalList(LNode* head)
{
	LNode* p = head->next;
	head->next = NULL;
	LNode* m = p->next;
	head->next = p;
	p->next = NULL;
	while (m != NULL)
	{
		p = m;
		m=m->next;
		p->next = head->next;
		head->next = p;
	}
	printf("链表反转成功！\n");
	printLinkList(head);
}
void findMiddle(LNode* head)
{
	LNode* fast = head;
	LNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("中间节点的值为:%d\n", slow->data);
}