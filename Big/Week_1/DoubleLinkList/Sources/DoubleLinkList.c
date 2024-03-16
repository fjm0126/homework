#include<DoubleLinkList.h>
int main()
{
	DuLNode* head=NULL;
	while (1)
	{
		printf("双向链表ADT\n");
		printf("-----------------\n");
		printf("1、创建空双向链表(请最先进行操作）\n");
		printf("2、从尾部插入数据\n");
		printf("3、从头部插入数据\n");
		printf("4、销毁链表\n");
		printf("5、打印链表\n");
		printf("6、查找数据\n");
		printf("7、删除结点\n");
		int choice;
		printf("请输入要选择的操作：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			head = createList();
			break;
		case 2:
			printf("请输入要添加的数据：");
			int data;
			scanf_s("%d", &data);
			LastAppend(head, data);
			break;
		case 3:
			printf("请输入要添加的数据：");
			int data1;
			scanf_s("%d", &data1);
			headAppend(head, data1);
			break;
		case 4:
			destoryDuList(head);
			break;
		case 5:
			printDuList(head);
			break;
		case 6:
			printf("请输入要查找的数据：");
			int data2;
			scanf_s("%d", &data2);
			searchData(head, data2);
			break;
		case 7:
			printf("请选择要删除的数据：");
			int data3;
			scanf_s("%d", &data3);
			DeleteNode(head, data3);
			break;
		}

	}
}
DuLinkedList createList()
{
	DuLinkedList head = (DuLinkedList)malloc(sizeof(DuLNode));
	if (head != NULL) {
		head->prior = NULL;
		head->next = NULL;
	}
	printf("创建成功\n");
	return head;
}
void LastAppend(DuLNode* head,int data)
{
	DuLinkedList Node = (DuLinkedList)malloc(sizeof(DuLNode));
	Node->data = data;
	Node->next = NULL;
	DuLinkedList p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = Node;
	Node->prior = p;
	printf("数据添加成功！\n");
	printDuList(head);
}
void printDuList(DuLinkedList head)
{
	if (head==NULL||head->next == NULL)
	{
		printf("链表为空\n");
		return;
	}
	DuLinkedList p = head->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
void headAppend(DuLNode* head, int data)
{
	DuLinkedList Node = (DuLinkedList)malloc(sizeof(DuLNode));
	Node->data = data;
	if (head->next != NULL) {
		head->next->prior = Node;
		Node->next = head->next;
		Node->prior = head;
		head->next = Node;
	}
	else {

		head->next = Node;
		Node->prior = head;
		Node->next = NULL;
	}
	printf("数据插入成功！\n");
	printDuList(head);
}
void destoryDuList(DuLinkedList head)
{
	DuLinkedList p= head;
	while (p!= NULL) {
		DuLinkedList m=p;
		p= p->next;
		free(m);
	}
	printf("销毁成功！\n");
}
void searchData(DuLinkedList head, int data)
{
	DuLinkedList p = head->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == data)
		{
			printf("此数据在链表第%d个结点\n", i);
		}
		p = p->next;
		i++;
	}
}
void DeleteNode(DuLinkedList head,int data)
{
	if (head->next == NULL)
	{
		return;
	}
	DuLinkedList p = head->next;
	if (head->next->next == NULL)
	{
		free(p);
		head->next = NULL;
		printf("删除成功！\n");
		printDuList(head);
		return;
	}
	if (p->data == data)
	{
		DuLinkedList m = p->next;
		head->next = m;
		m->prior = head;
		free(p);
		printf("删除成功！\n");
		printDuList(head);
		return;
	}
	while (p != NULL)
	{
		if (p->next->data == data && p->next->next == NULL)
		{
			DuLinkedList m = p->next;
			free(m);
			p->next = NULL;
			printf("删除成功！\n");
			printDuList(head);
			return;
		}
		if (p->next->data == data)
		{
			DuLinkedList m = p->next;
			p->next = p->next->next;
			p->next->prior = p;
			free(m);
			printf("删除成功！\n");
			printDuList(head);
		}
		p = p->next;
	}
}