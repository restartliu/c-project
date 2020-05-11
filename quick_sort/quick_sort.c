#include "quick_sort.h"

void quick_sort(int *number, int left, int right)
{
    if (left>=right) return;

    int smaller_index = 0;

    for (int i = smaller_index = left+1; i < right; i++)
        if(number[left]>number[i])
            smaller_index==i?smaller_index++:swap(&number[i], &number[smaller_index++]);
    
    left<(smaller_index-1)?swap(&number[left], &number[smaller_index-1]):0;

    quick_sort(number, left, smaller_index-1);
    quick_sort(number, smaller_index, right);
}

/*void quick_sort(int *a, int left, int right)
{

    if (left >= right)
        return;

    int pivot = a[left];
    int i = left;
    int j = right;

    //如果左右指针碰头就代表这一轮迭代结束
    while (i != j)
    {
        //先从右边开始,找小于pivot点的数字
        //因此，循环的条件是如果大于pivot就继续查找
        //小于pivot就停止
        while (a[j] >= pivot && i < j)
        {
            j--;
        }
        //后从左边开始，找大于pivot的数字
        //因此，循环的条件是如果是小于pivot就继续查找
        //大于pivot就停止
        while (a[i] <= pivot && i < j)
        {
            i++;
        }

        if (i < j)
        {
            //交换两个数字
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }

    //基准归位
    a[left] = a[i];
    a[i] = pivot;

    quick_sort(a, left, i - 1);

    quick_sort(a, i + 1, right);
}*/

void swap(int *first, int *second)
{
    int p = *first;
    *first = *second;
    *second = p;
}

void print_number(int *number, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\n");
}