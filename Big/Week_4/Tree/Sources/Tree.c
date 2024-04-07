#include<Tree.h>
int flag = 0;
int target = 0;
int main()
{
	SetConsoleOutputCP(65001);
	Treenode* root=NULL;
	while (1) {
		printf("----------------\n");
		printf("二叉排序树ADT\n");
		printf("----------------\n");
		printf("1、创建二叉排序树\n");
		printf("2、查找数据\n");
		printf("3、插入数据\n");
		printf("4、删除数据\n");
		printf("5、先序遍历(递归)\n");
		printf("6、中序遍历(递归)\n");
		printf("7、后序遍历(递归)\n");
		printf("8、先序遍历(非递归)\n");
		printf("9、中序遍历(非递归)\n");
		printf("10、后序遍历(非递归)\n");
		printf("11、层序遍历\n");
		printf("12、堆的实现\n");
		printf("请输入您的选择：");
		int choice;
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			if (flag)
			{
				printf("请勿重复创建二叉排序树!\n");
			}
			else {
				createSortTree(&root);
				flag = 1;
			}
			break;
		case 2:
			printf("请输入你要查找的数据：");
			int data;
			scanf_s("%d", &data);
			searchData(root, data);
			if (target == 0)
			{
				printf("二叉树中没有此数据\n");
			}
			break;
		case 3:
			if (flag) {
				printf("请输入要插入的数据：");
				int data3;
				scanf_s("%d", &data3);
				insertNode(&root, data3);
				printf("插入成功\n");
			}
			else {
				printf("请先创建二叉排序树\n");
			}
			break;
		case 4:
			printf("请输入要删除的数据：");
			int data4;
			scanf_s("%d", &data4);
			int a=deleteNode(&root, data4);
			if (a == 1) {
				printf("删除成功，余下的数据为：");
				preorderTraversal(root);
				printf("\n");
			}
			else {
				printf("删除的数据不存在！\n");
			}
			break;
		case 5:
			printf("数据为：");
			preorderTraversal(root);
			printf("\n");
			break;
		case 6:
			printf("数据为：");
			middleTraversal(root);
			printf("\n");
			break;
		case 7:
			printf("数据为：");
			lastTraversal(root);
			printf("\n");
			break;
		case 8:
			printf("数据为：");
			preorderTraversal2(root);
			printf("\n");
			break;
		case 9:
			printf("数据为：");
			middleTraversal2(root);
			printf("\n");
			break;
		case 10:
			printf("数据为：");
			lastTraversal2(root);
			printf("\n");
			break;
		case 11:
			printf("数据为：");
			levelTraversal(root);
			printf("\n");
			break;
		case 12:
			system("cls");
			printf("1、小顶堆\n");
			printf("2、大顶堆\n");
			printf("请选择要实现堆的种类：");
			int c;
			scanf_s("%d", &c);
			switch (c)
			{
			case 1:
				Heap * heap1 = initHeap(100, 0, minHeap);
				printf("请输入要构建堆的数据个数：");
				int num;
				scanf_s("%d", &num);
				int* data;
				data = (int*)malloc(num * sizeof(int));
				for (int i = 0; i < num; i++)
				{
					int d;
					printf("请输入-个数据：");
					scanf_s("%d", & d);;
					data[i] = d;
				}
				buildHeap(heap1, data, num);
				printHeap(heap1);
				break;
			case 2:
				Heap * heap2 = initHeap(100, 0, maxHeap);
				printf("请输入要构建堆的数据个数：");
				int num1;
				scanf_s("%d", &num1);
				int* data1;
				data1 = (int*)malloc(num1 * sizeof(int));
				for (int i = 0; i < num1; i++)
				{
					int d1;
					printf("请输入一个数据：");
					scanf_s("%d", &d1);
					data1[i] = d1;
				}
				buildHeap(heap2, data1, num1);
				printHeap(heap2);
				break;
			}
			break;
		default:
			printf("无效操作，请重新选择!\n");
		}
	}
}
Treenode* createNode(int data)
{
	Treenode* node = (Treenode*)malloc(sizeof(Treenode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void insertNode(Treenode** root, int data) {
	if (*root == NULL) {
		*root = createNode(data);
	}
	else if (data >= (*root)->data) {
		insertNode(&((*root)->right), data);
	}
	else {
		insertNode(&((*root)->left), data);
	}
}
void createSortTree(Treenode* root)
{
	int num;
	while (1) {
		printf("请输入生成二叉排序树的结点个数：");
		scanf_s("%d", &num);
		if (num > 0) {
			for (int i = 0; i < num; i++)
			{
				int data;
				printf("请输入数据：");
				scanf_s("%d", &data);
				insertNode(root, data);
			}
			break;
		}
		else {
			printf("请输入大于0的结点个数!\n");
		}
	}
	printf("创建成功!\n");
}
Treenode* searchData(Treenode* root, int data)
{
	if (root == NULL || root->data == data) {
		if (root != NULL)
		{
			printf("找到数据:%d\n", root->data);
			target = 1;
		}
		return root;
	}

	if (data < root->data) {
		return searchData(root->left, data);
	}
	else {
		return searchData(root->right, data);
	}
}
void preorderTraversal(Treenode* root) {
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data); // 先访问根节点
	preorderTraversal(root->left); // 递归遍历左子树
	preorderTraversal(root->right); // 递归遍历右子树
}
void middleTraversal(Treenode* root)
{
	if (root == NULL)
	{
		return;
	}
	preorderTraversal(root->left); // 递归遍历左子树
	printf("%d ", root->data); // 先访问根节点
	preorderTraversal(root->right); // 递归遍历右子树
}
void lastTraversal(Treenode* root)
{
	if (root == NULL)
	{
		return;
	}
	preorderTraversal(root->left); // 递归遍历左子树
	preorderTraversal(root->right); // 递归遍历右子树
	printf("%d ", root->data); // 先访问根节点
}
int deleteNode(Treenode** root, int data)
{
	if (*root == NULL)
	{
		return 0;
	}
	if (data > (*root)->data)
	{
		deleteNode(&((*root)->right), data);
	}
	else if (data < ((*root)->data)){
		deleteNode(&((*root)->left), data);
	}
	else {
		if ((*root)->left == NULL)
		{
			Treenode* temp = (*root)->right;
			free(*root);
			*root = temp;
		}
		else if ((*root)->right == NULL)
		{
			Treenode* temp = (*root)->left;
			free(*root);
			*root = temp;
		}
		else {
			Treenode* temp = findMin((*root)->right);
			(*root)->data = temp->data;
			deleteNode(&((*root)->right), temp->data);
		}
	}
	return 1;
}
Tree findMin(Tree node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}
stack* createStack()
{
	stack* Stack = (stack*)malloc(sizeof(stack));
	Stack->top = -1;
	return Stack;
}
int isEmpty(stack* Stack)
{
	return (Stack->top == -1);
}
void push(stack* Stack, Tree T)
{
	Stack->top++;
	Stack->array[Stack->top] = T;
}
Tree pop(stack* Stack)
{
	return Stack->array[Stack->top--];
}
void preorderTraversal2(Treenode* root)
{
	if (root == NULL)
	{
		return;
	}
	stack* Stack = createStack();
	push(Stack, root);
	while (!isEmpty(Stack))
	{
		Tree node = pop(Stack);
		printf("%d ", node->data);
		if (node->right != NULL)
		{
			push(Stack, node->right);
		}
		if (node->left != NULL)
		{
			push(Stack, node->left);
		}
	}
}
void middleTraversal2(Treenode* root)
{
	if (root == NULL)
	{
		return;
	}
	stack* Stack = createStack();
	Tree p = root;
	while (p != NULL || !isEmpty(Stack))
	{
		while (p != NULL)
		{
			push(Stack, p);
			p = p->left;
		}
		p = pop(Stack);
		printf("%d ", p->data);
		p = p->right;
	}
}
void lastTraversal2(Treenode* root)
{
	if (root == NULL)
	{
		return;
	}
	stack* Stack1 = createStack();
	stack* Stack2= createStack();
	push(Stack1, root);
	while (!isEmpty(Stack1))
	{
		Tree node = pop(Stack1);
		push(Stack2, node);
		if (node->left != NULL)
		{
			push(Stack1, node->left);
		}
		if (node->right != NULL)
		{
			push(Stack1, node->right);
		}
	}
	while (!isEmpty(Stack2))
	{
		printf("%d ", pop(Stack2)->data);
	}
}
Queue* cerateQueuenode(Tree data)
{
	Queue* node = (Queue*)malloc(sizeof(Queue));
	node->data = data;
	node->next = NULL;
	return node;
}
queue* initQueue()
{
	queue* Queue = (queue*)malloc(sizeof(queue));
	Queue->front = Queue->rear = NULL;
	return Queue;
}
void enqueue(queue* Q, Tree data)
{
	Queue* node = cerateQueuenode(data);
	if (Q->front == NULL)
	{
		Q->front = Q->rear = node;
	}
	else
	{
		Q->rear->next = node;
		Q->rear = node;
	}
}
Tree dequeue(queue* Q)
{
	Queue* temp = Q->front;
	Tree data = temp->data;
	Q->front = Q->front->next;
	free(temp);
	return data;
}
void levelTraversal(Tree root)
{
	if (root == NULL)
	{
		return;
	}
	queue* Q = initQueue();
	enqueue(Q, root);
	while (Q->front != NULL)
	{
		Tree node = dequeue(Q);
		printf("%d ", node->data);
		if (node->left != NULL)
		{
			enqueue(Q, node->left);
		}
		if (node->right != NULL)
		{
			enqueue(Q, node->right);
		}
	}
}
int minHeap(int a, int b)
{
	return a<=b;
}
int maxHeap(int a, int b)
{
	return a >= b;
}
Heap* initHeap(int size, int tag, int (*prior)(int, int)) {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->rcd = (int*)malloc(sizeof(int) * (size + 1));
	heap->n = 0;
	heap->size = size;
	heap->tag = tag;
	heap->prior = prior;
	return heap;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void adjust(Heap* heap, int k) {
	int i, j;
	i = k;
	j = 2 * i; // 左子节点
	while (j <= heap->n) {
		if (j < heap->n && heap->prior(heap->rcd[j + 1], heap->rcd[j]))
			j++; // 选择较小（最小堆）或较大（最大堆）的子节点
		if (!heap->prior(heap->rcd[j], heap->rcd[i]))
			break; // 如果父节点已经比子节点小（最小堆）或大（最大堆），退出
		swap(&heap->rcd[i], &heap->rcd[j]);
		i = j;
		j = 2 * i;
	}
}
void buildHeap(Heap* heap, int* data, int n) {
	for (int i = 1; i <= n; i++)
		heap->rcd[i] = data[i - 1];
	heap->n = n;
	for (int i = n / 2; i >= 1; i--)
		adjust(heap, i);
}
void printHeap(Heap* heap) {
	printf("堆的数据为：");
	for (int i = 1; i <= heap->n; i++)
		printf("%d ", heap->rcd[i]);
	printf("\n");
}

