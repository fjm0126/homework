#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode,*DuLinkedList;
DuLinkedList createList();//创建空双向链表
void LastAppend(DuLNode* head,int data);//从尾部添加数据
void printDuList(DuLinkedList head);//打印链表
void headAppend(DuLNode* head, int data);//从头部添加数据
void destoryDuList(DuLinkedList head);//销毁链表
void searchData(DuLinkedList head,int data);//查找数据
void DeleteNode(DuLinkedList head,int data);//删除某一结点