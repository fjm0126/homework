#pragma once
#include<time.h>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
void insertSort(int arr[], int size);//插入排序
int binarySearch(int arr[], int left, int right, int target);//二分搜索
void insertSort2(int arr[], int size);//插入排序优化
void bubblesort1(int arr[], int size);//冒泡排序及优化1
void quicksort(int arr[], int start, int end);//快速排序
void merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd);//合并
void mergeSort(int arr[], int tmp[], int start, int end);//归并排序
void countSort(int arr[], int n, int range);//计数排序
int getDigit(int num, int digit);// 获取数字的指定位数上的数字
void randomArray(int arr[], int size);//获取随机数数组
void countingSortForDigit(int arr[], int n, int digit);
void radixCountingSort(int arr[], int n);//基数计数排序
void colorSort();//颜色排序
void SavedataTofile(char* filename ,int size);//保存数据到文件
void ReaddataInfile(char* filename, int* data);//读取文件到数组
int SearchK(int data[], int k);//找到第k小的数
void swap(int* a, int* b);//交换两个数据
void bubblesort2(int arr[], int size);//冒泡排序优化2
void bubblesort3(int arr[], int size);//冒泡排序优化3
int partition(int arr[], int low, int high);//找到位置