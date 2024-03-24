#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct QNode {
	void* data;
	struct QNode* next;
}QNode,*Queueptr;
typedef struct {
	Queueptr head;
	Queueptr tail;
	size_t length;
}LinkQueue;
void initQueue(LinkQueue* queue);//初始化队列
void printQueue(LinkQueue* queue);//打印队列
void EnQueue(LinkQueue* queue, void* data);//元素入队
long long readnumber();//读取整型
char readChar();//读取字符
char* readString();//读取字符串
void* readFloat();//读取浮点型
void DeQueue(LinkQueue* queue);//出队
void checkhead(LinkQueue* queue);//头数据
void checklength(LinkQueue* queue);//长度
void isEmpty(LinkQueue* queue);//判空
void cleanQueue(LinkQueue* queue);//清空队列
void destoryQueue(LinkQueue* queue);//销毁队列
