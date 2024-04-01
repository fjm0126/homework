#define _CRT_SECURE_NO_WARNINGS 1
#include<Sort.h>
int main()
{
	SetConsoleOutputCP(65001);
	srand(time(NULL));
	double time = 0;
	int test[1000];
	int size_levels[] = { 10000, 50000, 200000 };
	int num_levels = sizeof(size_levels) / sizeof(size_levels[0]);
	while (1) {
		printf("----------------\n");
		printf("排序算法的实现\n");
		printf("----------------\n");
		printf("1、插入排序\n");
		printf("2、插入排序优化(二分查找优化）\n");
		printf("3、快速排序（递归版）\n");
		printf("4、计数排序\n");
		printf("5、基数计数排序\n");
		printf("6、颜色排序\n");
		printf("7、无序序列找到第k小的数\n");
		printf("8、冒泡排序优化1\n");
		printf("9、冒泡排序优化2\n");
		printf("10、冒泡排序优化3\n");
		printf("请输入你要选择的排序算法：");
		int choice;
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("插入排序的各个层次时间：\n");
			for (int i = 0; i < num_levels; i++)
			{
				int size = size_levels[i];
				int* data = (int*)malloc(size * sizeof(int));
				randomArray(data, size);
				clock_t start = clock();
				insertSort(data, size);
				clock_t diff = clock() - start;
				printf("(%d)数据量的时间为：%d ms\n",size,diff);
			}
			for (int i = 0; i < 1000; i++)
			{
				int* data2 = (int*)malloc(100* sizeof(int));
				randomArray(data2, 100);
				clock_t starttime = clock();
				insertSort(data2, 100);
				clock_t endtime = clock();
				time += (endtime - starttime);
			}
			printf("插入排序大量小数据下(100个数据*1000次)的排序用时：%fms\n",time);
			time = 0;
			SavedataTofile("test_data.txt", 1000);
			printf("从文件读取1000个数据排序\n");
			ReaddataInfile("test_data.txt", test);
			insertSort(test, 1000);
			printf("排序后的数据为：");
			for (int i = 0; i < 1000; i++)
			{
				printf("%d ", test[i]);
			}
			printf("\n");
			break;
		case 2:
			printf("插入排序优化（二分查找优化）的各个层次时间：\n");
			for (int i = 0; i < num_levels; i++)
			{
				int size = size_levels[i];
				int* data = (int*)malloc(size * sizeof(int));
				randomArray(data, size);
				clock_t start = clock();
				insertSort2(data, size);
				clock_t diff = clock() - start;
				printf("(%d)数据量的时间为：%d ms\n", size, diff);
			}
			for (int i = 0; i < 1000; i++)
			{
				int* data2 = (int*)malloc(100 * sizeof(int));
				randomArray(data2, 100);
				clock_t starttime = clock();
				insertSort2(data2, 100);
				clock_t endtime = clock();
				time += (endtime - starttime);
			}
			printf("插入排序优化（二分查找优化）大量小数据下(100个数据*1000次)的排序用时：%fms\n", time);
			time = 0;
			SavedataTofile("test_data.txt", 1000);
			printf("从文件读取1000个数据排序\n");
			ReaddataInfile("test_data.txt", test);
			insertSort2(test, 1000);
			printf("排序后的数据为：");
			for (int i = 0; i < 1000; i++)
			{
				printf("%d ", test[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("快速排序（递归版）的各个层次时间：\n");
			for (int i = 0; i < num_levels; i++)
			{
				int size = size_levels[i];
				int* data = (int*)malloc(size * sizeof(int));
				randomArray(data, size);
				clock_t start = clock();
				quicksort(data,0,size-1);
				clock_t diff = clock() - start;
				printf("(%d)数据量的时间为：%d ms\n", size, diff);
			}
			for (int i = 0; i < 1000; i++)
			{
				int* data2 = (int*)malloc(100 * sizeof(int));
				randomArray(data2, 100);
				clock_t starttime = clock();
				quicksort(data2, 0, 99);
				clock_t endtime = clock();
				time += (endtime - starttime);
			}
			printf("快速排序大量小数据下(100个数据*1000次)的排序用时：%fms\n", time);
			time = 0;
			SavedataTofile("test_data.txt", 1000);
			printf("从文件读取1000个数据排序\n");
			ReaddataInfile("test_data.txt", test);
			quicksort(test,0,999);
			printf("排序后的数据为：");
			for (int i = 0; i < 1000; i++)
			{
				printf("%d ", test[i]);
			}
			printf("\n");
			break;
		case 4:
			printf("计数排序的各个层次时间：\n");
			for (int i = 0; i < num_levels; i++)
			{
				int range = 1000;
				int size = size_levels[i];
				int* data = (int*)malloc(size * sizeof(int));
				randomArray(data, size);
				clock_t start = clock();
				countSort(data, size,range);
				clock_t diff = clock() - start;
				printf("(%d)数据量的时间为：%d ms\n", size, diff);
			}
			for (int i = 0; i < 1000; i++)
			{
				int* data2 = (int*)malloc(100 * sizeof(int));
				randomArray(data2, 100);
				clock_t starttime = clock();
				countSort(data2, 100, 1000);
				clock_t endtime = clock();
				time += (endtime - starttime);
			}
			printf("计数排序大量小数据下(100个数据*1000次)的排序用时：%fms\n", time);
			time = 0;
			SavedataTofile("test_data.txt", 1000);
			printf("从文件读取1000个数据排序\n");
			ReaddataInfile("test_data.txt", test);
			countSort(test, 1000,1000);
			printf("排序后的数据为：");
			for (int i = 0; i < 1000; i++)
			{
				printf("%d ", test[i]);
			}
			printf("\n");
			break;
		case 5:
			printf("基数计数排序的各个层次时间：\n");
			for (int i = 0; i < num_levels; i++)
			{
				int size = size_levels[i];
				int* data = (int*)malloc(size * sizeof(int));
				randomArray(data, size);
				clock_t start = clock();
				radixCountingSort(data, size);
				clock_t diff = clock() - start;
				printf("(%d)数据量的时间为：%d ms\n", size, diff);
			}
			for (int i = 0; i < 1000; i++)
			{
				int* data2 = (int*)malloc(100 * sizeof(int));
				randomArray(data2, 100);
				clock_t starttime = clock();
				radixCountingSort(data2,100);
				clock_t endtime = clock();
				time += (endtime - starttime);
			}
			printf("基数计数排序大量小数据下(100个数据*1000次)的排序用时：%fms\n", time);
			time = 0;
			SavedataTofile("test_data.txt", 1000);
			printf("从文件读取1000个数据排序\n");
			ReaddataInfile("test_data.txt", test);
			radixCountingSort(test, 1000);
			printf("排序后的数据为：");
			for (int i = 0; i < 1000; i++)
			{
				printf("%d ", test[i]);
			}
			printf("\n");
			break;
		case 6:
			colorSort();
			break;
		case 7:
		{int k;
		while (1) {
			printf("请输入k的值：");
			scanf("%d", &k);
			if (k > 30 || k <= 0)
			{
				printf("范围有误，请输入1到30！\n");
			}
			else {
				break;
			}
		}
		int* data3;
		data3 = (int*)malloc(30 * sizeof(int));
		randomArray(data3, 30);
		printf("生成的无序数组为：\n");
		for (int i = 0; i < 30; i++)
		{
			printf("%d ", data3[i]);
		}
		printf("\n");
		int result = SearchK(data3, k, 29, 0);
		printf("结果为：%d\n", result);
		break;
		}
		case 8:
		{int* data4;
		printf("测试数据为100000个\n");
		data4 = (int*)malloc(100000 * sizeof(int));
		randomArray(data4, 100000);
		clock_t start = clock();
		bubblesort1(data4, 100000);
		clock_t end = clock();
		printf("用时为：%dms\n", end - start);
		break;
		}
		case 9:
		{int* data5;
		printf("测试数据为100000个\n");
		data5 = (int*)malloc(100000 * sizeof(int));
		randomArray(data5, 100000);
		clock_t start1 = clock();
		bubblesort2(data5, 100000);
		clock_t end1 = clock();
		printf("用时为：%dms\n", end1 - start1);
		break;
		}
		case 10:
		{int* data6;
		printf("测试数据为100000个\n");
		data6 = (int*)malloc(100000 * sizeof(int));
		randomArray(data6, 100000);
		clock_t start2 = clock();
		bubblesort3(data6, 100000);
		clock_t end2 = clock();
		printf("用时为：%dms\n", end2 - start2);
		break;
		}
		default:
			printf("无效操作，请重新输入！\n");

		}
	}
}
void bubblesort1(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
void bubblesort2(int arr[], int size)
{
	int index = size - 1;
	int lastindex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < index; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				lastindex = j;
			}
		}
		if (flag)
		{
			break;
		}
		index = lastindex;
	}
}
void bubblesort3(int arr[], int size)
{
	int index = size - 1;
	int max_index = 0;
	int min_index = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < index; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				max_index = j;
			}
		}
		if (flag)
		{
			break;
		}
		index = max_index;
		for (int j = index; j > min_index; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
				flag = 0;
			}
		}
		min_index++;
		if (flag)
		{
			break;
		}
	}
}
void insertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i], j = i;
		while (j > 0 && arr[j - 1] > temp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}
int binarySearch(int arr[], int left, int right, int target)//二分搜索
{
	while (right >= left)
	{
		int mid = (right + left) / 2;
		if (target == arr[mid])
		{
			return mid + 1;
		}
		else if (target > arr[mid])
		{
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}
void insertSort2(int arr[], int size)//插入排序优化
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = binarySearch(arr, 0, i - 1, temp);
		for (int k = i; k > j; k--)
		{
			arr[k] = arr[k - 1];
		}
		arr[j] = temp;
	}
}
void quicksort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int left = start, right = end, target = arr[left];
	while (right > left)
	{
		while (right > left && arr[right] >= target)
		{
			right--;
		}
		arr[left] = arr[right];
		while (right > left && arr[left] <= target)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = target;
	quicksort(arr, start, left - 1);
	quicksort(arr, left + 1, end);
}
void merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd)
{
	int i = left, size = rightEnd - left + 1;
	while (left <= leftEnd && right <= rightEnd)
	{
		if (arr[left] <= arr[right])
			tmp[i++] = arr[left++];
		else
			tmp[i++] = arr[right++];
	}
	while (left <= leftEnd)
		tmp[i++] = arr[left++];
	while (right <= rightEnd)
		tmp[i++] = arr[right++];
	for (int j = 0; j < size; ++j, rightEnd--)
		arr[rightEnd] = tmp[rightEnd];
}
void mergeSort(int arr[], int tmp[], int start, int end)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	mergeSort(arr, tmp, start, mid);
	mergeSort(arr, tmp, mid + 1, end);
	merge(arr, tmp, start, mid, mid + 1, end);
}
void countSort(int arr[], int n, int range)
{
	int* count = (int*)malloc((range + 1) * sizeof(int));
	for (int i = 0; i <= range; i++)
	{
		count[i] = 0;
	}
	// 统计每个元素的出现次数
	for (int i = 0; i < n; ++i) {
		++count[arr[i]];
	}
	// 将计数数组中的值累加，得到每个元素在排序后的数组中的位置
	for (int i = 1; i <= range; ++i) {
		count[i] += count[i - 1];
	}

	// 创建一个临时数组存储排序结果
	int* output = (int*)malloc(n * sizeof(int));

	// 根据计数数组中的值，将元素放置到排序后的位置上
	for (int i = n - 1; i >= 0; --i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	// 将排序后的数组复制回原数组
	for (int i = 0; i < n; ++i) {
		arr[i] = output[i];
	}
}
// 获取数字的指定位数上的数字
int getDigit(int num, int digit) {
	return (num / digit) % 10;
}
// 计数排序函数，针对指定的位数进行排序
void countingSortForDigit(int arr[], int n, int digit) {
	 int range = 10; // 每个位数上可能的数字范围是0到9

	// 创建计数数组，并初始化为0
	int* count = (int*)malloc(range * sizeof(int));
	for (int i = 0; i < range; ++i) {
		count[i] = 0;
	}

	// 统计每个数字出现的次数
	for (int i = 0; i < n; ++i) {
		++count[getDigit(arr[i], digit)];
	}

	// 将计数数组中的值累加，得到每个数字在排序后的数组中的位置
	for (int i = 1; i < range; ++i) {
		count[i] += count[i - 1];
	}

	// 创建临时数组存储排序结果
	int* output = (int*)malloc(n * sizeof(int));

	// 根据计数数组中的值，将数字放置到排序后的位置上
	for (int i = n - 1; i >= 0; --i) {
		output[count[getDigit(arr[i], digit)] - 1] = arr[i];
		--count[getDigit(arr[i], digit)];
	}

	// 将排序后的数组复制回原数组
	for (int i = 0; i < n; ++i) {
		arr[i] = output[i];
	}

}

// 基数计数排序函数
void radixCountingSort(int arr[], int n) {
	// 找出数组中最大的数字
	int maxNum = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] > maxNum) {
			maxNum = arr[i];
		}
	}
	// 对每一位进行计数排序
	for (int digit = 1; maxNum / digit > 0; digit *= 10) {
		countingSortForDigit(arr, n, digit);
	}
}
void randomArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}
}
void colorSort()
{
	int data[10];
	printf("排序前的数组为：");
	for (int i = 0; i < 10; i++)
	{
		data[i] = rand() % 3;
		printf("%d ", data[i]);
	}
	int head = 0, tail = 9;
	for (int i = 0; i <= tail;)
	{
		if (data[i] == 0)
		{
			int temp = data[i];
			data[i] = data[head];
			data[head] = temp;
			i++;
			head++;
		}
		else if (data[i] == 2)
		{
			int temp = data[i];
			data[i] = data[tail];
			data[tail] = temp;
			tail--;
		}
		else {
			i++;
		}
	}
	printf("\n");
	printf("排序后的数组为：");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}
void SavedataTofile(char* filename, int size)
{
	FILE* file = fopen(filename, "w");
	int data;
	for (int i = 0; i < size; i++)
	{
		data = rand() % 1000;
		fprintf(file,"%d\n", data);
	}
	fclose(file);
}
void ReaddataInfile(char* filename, int* data)
{
	FILE* file = fopen(filename, "r");
	int i = 0;
	char line[20];
	while (fgets(line, sizeof(line), file) != NULL && i < 1000) {
		data[i] = atoi(line);
		i++;
	}
	fclose(file);
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // 选择最后一个元素作为pivot
	int i = low - 1; // 初始化i为low的前一个索引
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}
int SearchK(int arr[],int k,int high,int low)
{
		int pos = partition(arr, low, high);
		if (pos - low == k - 1) // 如果pivot的位置就是第k小的数
			return arr[pos];
		if (pos - low > k - 1) // 如果pivot的位置比第k小的数大，说明第k小的数在左边
			return SearchK(arr, low, pos - 1, k);
		// 否则在右边
		return SearchK(arr, pos + 1, high, k - pos + low - 1);
}
