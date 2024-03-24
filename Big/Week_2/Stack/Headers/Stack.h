#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>
typedef struct StackNode
{
	long long data;
	struct StackNode* next;
}StackNode,*LinkStackptr;
typedef struct LinkStack
{
	LinkStackptr top; //栈顶指针
	int count; //栈中元素个数
}LinkStack;
void initLinkStack(LinkStack* stack);//初始化链栈
void isEmpty(LinkStack* stack);//判断是否为空
void push(LinkStack* stack, long long data);//入栈
long long pop(LinkStack* stack);//出栈
long long getdata(LinkStack* stack);//获取栈顶元素
void clear(LinkStack* stack);//清空链栈
int num(stack);//获取元素个数
void destroy(LinkStack* stack);//销毁链栈
void printstack(LinkStack* stack); //打印链栈