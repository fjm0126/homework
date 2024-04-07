#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Treenode,*Tree;
//栈
typedef struct Stack {
	int top;
	struct Treenode* array[100];
}stack;
//队列
typedef struct QueueNode {
	struct TreeNode* data;
	struct QueueNode* next;
}Queue;
 typedef struct Queue {
	struct QueueNode* front;
	struct QueueNode* rear;
}queue;
 //堆
 typedef struct {
	 int* rcd;//空间基址
	 int n;//堆长度
	 int size;//堆容量
	 int tag;//tag=0为小顶堆，tag=1为大顶堆
	 int (*prior)(int, int);
 }Heap;
Treenode* createNode(int data);//创建节点
void insertNode(Treenode** root, int data);//插入数据
int deleteNode(Treenode** root, int data);//删除数据
void createSortTree(Treenode* root);//创建二叉排序树
Treenode* searchData(Treenode* root, int data);//查找数据
void preorderTraversal(Treenode* root);//先序遍历（递归）
void middleTraversal(Treenode* root);//中序遍历（递归）
void lastTraversal(Treenode* root);//后序遍历（递归）
Tree findMin(Tree node);//找到右子树中的最小值
stack* createStack();//初始化栈
int isEmpty(stack* Stack);//判空
void push(stack* Stack, Tree T);//入栈
Tree pop(stack* Stack);//出栈
void preorderTraversal2(Treenode* root);//非递归先序遍历
void middleTraversal2(Treenode* root);//非递归中序遍历
void lastTraversal2(Treenode* root);//非递归后序遍历
Queue* cerateQueuenode(Tree data);//创建队列结点
queue* initQueue();//初始化队列
void enqueue(queue* Q, Tree data);///入队操作
Tree dequeue(queue* Q);//出队操作
void levelTraversal(Tree root);//层序遍历
int minHeap(int a, int b);//最小堆比较
int maxHeap(int a, int b);//最大堆比较
Heap* initHeap(int size, int tag, int (*prior)(int, int));//初始化堆
void swap(int* a, int* b);//交换堆中的两个元素
void adjust(Heap* heap, int k);//调整k位置
void buildHeap(Heap* heap, int* data, int n);//建堆
void printHeap(Heap* heap);//打印堆
