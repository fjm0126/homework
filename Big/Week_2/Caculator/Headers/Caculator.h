#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>
typedef struct StackNode
{
	long long data;
	struct StackNode* next;
}StackNode, * LinkStackptr;
typedef struct LinkStack
{
	LinkStackptr top; //栈顶指针
	int count; //栈中元素个数
}LinkStack;
void initLinkStack(LinkStack* stack);//初始化
int JudgePriority(char op);//判断操作优先级
char* changeExpression(char* expression, char* expression2);//中缀表达式转化为后缀表达式
void push(LinkStack* stack, char data);//入栈
void push2(LinkStack* stack, int data);//入栈，接收整数类型的值
bool isEmpty(LinkStack* stack);//判断是否为空
char pop(LinkStack* stack);//出栈
char getdata(LinkStack* stack);//获取栈顶元素
int evaluateexpression(char* expression);//计算后缀表达式
int isOperator(char ch);//判断是否为操作符
//int isValidCharacter(char ch);//判断是否有无效字符
