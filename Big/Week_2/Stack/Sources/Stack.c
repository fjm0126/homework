#include<Stack.h>
bool flag = false;
int main()
{
	SetConsoleOutputCP(65001);
	LinkStack* stack;
	stack = (LinkStack*)malloc(sizeof(LinkStack));
	while (1)
	{
		printf("----------------------------\n");
		printf("链栈及四则运算计算器的实现\n");
		printf("----------------------------\n");
		printf("1、初始化链栈\n");
		printf("2、判断链栈是否为空\n");
		printf("3、元素入栈\n");
		printf("4、元素出栈\n");
		printf("5、获取栈顶元素\n");
		printf("6、清空链栈\n");
		printf("7、销毁栈\n");
		printf("8、获取链栈中元素个数\n");
		printf("9、打印链栈\n");
		printf("请输入要选择的操作：\n");
		int choice;
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			system("cls");
			if (flag)
			{
				printf("已初始化！请勿重复操作！\n");
			}
			else {
				initLinkStack(stack);
			}
			break;
		case 2:
			system("cls");
			if (flag)
			{
				isEmpty(stack);
			}
			else {
				printf("请先初始化链栈！\n");
			}
			break;
		case 3:
			system("cls");
			if (flag)
			{
				char data[100];
				int i = 0;
				while (1) {
					printf("请输入要入栈的元素：\n");
					fgets(data, sizeof(data), stdin);
					data[strcspn(data, "\n")] = 0;
					for (i = 0; data[i] != '\0'; i++)
					{
						if (data[i] < '0' || data[i]>'9')
						{
							printf("请输入纯数字！\n");
							break;
						}
					}
					if (data[i] == '\0')
					{
						break;
					}
				}
				long long data2 = atoi(data);
				push(stack, data2);
			}
			else {
				printf("请先初始化链栈！\n");
			}
			break;
		case 4:
			system("cls");
			if (flag)
			{
				pop(stack);
			}
			else
			{
				printf("请先初始化链栈！\n");
			}
			break;
		case 5:
			system("cls");
			if (flag)
			{
				getdata(stack);
			}
			else
			{
				printf("请先初始化链栈！\n");
			}
			break;
		case 6:
			system("cls");
			if (flag)
			{
				clear(stack);
			}
			else
			{
				printf("请先初始化链栈！\n");
			}
			break;
		case 7:
			system("cls");
			if (flag)
			{
				destroy(stack);
			}
			else
			{
				printf("请先初始化链栈！\n");
			}
			break;
		case 8:
			system("cls");
			if (flag)
			{
				int number = num(stack);
				printf("元素个数为：%d\n", number);
			}
			else
			{
				printf("请先初始化链栈！\n");
			}
			break;
		case 9:
			system("cls");
			if (flag)
			{
				printstack(stack);
			}
			else
			{
				printf("请先初始化链栈！\n");
			}
			break;
		default:
			system("cls");
			printf("无效操作，请重新输入！\n");
		}
	}
}

void initLinkStack(LinkStack* stack)
{
	stack->top = NULL;
	stack->count = 0;
	flag = true;
	printf("初始化成功！\n");
}
void isEmpty(LinkStack* stack)
{
	if (stack->top == NULL)
	{
		printf("链栈为空！\n");
	}
	else {
		printf("链栈不为空！\n");
	}
}
void push(LinkStack* stack, long long data)
{
	StackNode* Node = (StackNode*)malloc(sizeof(StackNode));
	Node->data = data;
	Node->next = stack->top;
	stack->top = Node;
	stack->count++;
	printf("入栈成功！\n");
}
long long pop(LinkStack* stack)
{
	if (stack->top == NULL)
	{
		printf("链栈为空！\n");
		return;
	}
	else {
		long long data = stack->top->data;
		StackNode* temp = stack->top;
		stack->top = stack->top->next;
		stack->count--;
		free(temp);
		printf("出栈成功\n");
	}
}
long long getdata(LinkStack* stack)
{
	if (stack->top == NULL)
	{
		printf("链栈为空！\n");
		return;
	}
	else
	{
		long long data = stack->top->data;
		printf("栈顶元素为：%ld\n", data);
		return data;
	}
}
void clear(LinkStack* stack)
{
	while (stack->top != NULL)
	{
		StackNode* temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	stack->count = 0;
	printf("清空成功！\n");
}
int num(LinkStack* stack)
{
	return stack->count;
}
void destroy(LinkStack* stack)
{
	while (stack->top != NULL)
	{
		StackNode* temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
	printf("销毁成功！\n");
	flag = false;
}
void printstack(LinkStack* stack)
{
	if (stack->top == NULL)
	{
		printf("链栈为空！\n");
	}
	else {
		printf("链栈元素为：");
		StackNode* temp = stack->top;
		while (temp != NULL)
		{
			printf("%ld  ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}