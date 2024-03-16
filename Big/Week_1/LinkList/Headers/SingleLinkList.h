#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkedList;
LNode* createNode(int data);//创建新结点
void createLinkList(LNode* head,int n);//创建一个的链表
void appendNode(LNode* head, int data);//在链表尾部加入节点
void insertNode(LNode* head, int data, int num);//将某个数据插入到某个位置
void printLinkList(LNode* head);//打印链表数据
void deleteNode(LNode* head, int num);//删除某一结点
void destroyLinkList(LNode* head);//销毁链表
void searchData(LNode* head, int data);//查找某一数据
void exchangeNode(LNode* head);//奇偶交换
void reversalList(LNode* head);//反转链表
void findMiddle(LNode* head);//找到中点