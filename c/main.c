#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "main.h"

int main()
{
    int a[11];
    int len = 0;
    int cmd;

    do
    {
        initData(a);
        len = sizeof(a) / sizeof(a[0]);

        int *p = NULL;

        printf("options: 1.[bubble sort] 2.[selection sort] 3.[quick sort] 4.[insert sort] 5.[shell sort]\n");
        scanf("%d", &cmd);
        *p = cmd;

        check(p);
        switch (cmd)
        {

        case 1:
            //冒泡排序
            printf("starting bubble sort...\n");
            sort_bubble(a, len);
            break;
        case 2:
            //选择排序
            printf("starting selection sort...\n");
            sort_selection(a, len);
            break;
        case 3:
            //快速排序
             printf("starting quick sort...\n");
            sort_quick(a, 0, len - 1);
            break;
        case 4:
            //插入排序
             printf("starting insert sort...\n");
            sort_insert(a, len);
            break;
        case 5:
            //Shell排序
            printf("starting shell sort...\n");
            sort_shell(a, len);
            break;
        default:
            printf("executed none.");
            break;
        }
        printf("after sort, data:\n");
        printData(a, len);
    } while (1);

    system("pause");
    return 0;
}


 int max(int x,int y) 
 { int z;
   if(x>y) 
   z = x;
   else 
   z = y;
 return(z); 
 
 }

void check(int * result){

    printf("%d\n", !(*result));
}

void initData(int *a)
{
    int b[] = {17, 6, 19, 45, 1, 2, 23, 5, 4, 11, 3};
    int len = sizeof(b) / sizeof(b[0]);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        a[i] = b[i];
    }
    printf("initial data:\n");
    printData(a, len);
}

void printData(int *a, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void sort_bubble(int *a, int num)
{

    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printData(a, num);
    }
}

void sort_selection(int *a, int num)
{

    int i,j = 0;
    int temp = 0;
    int min;

    for (i = 0; i < num - 1; i++)
    {
        min = i;
        for (j = i + 1; j < num; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printData(a, num);
    }
}

void sort_quick(int *a, int start, int end)
{
    int i = start;
    int j = end;
    int temp = 0;
    int base = a[i];

    if (start < end)
    {
        while (i != j)
        {
            while (i < j && a[j] >= base)
                j--;

            while (i < j && a[i] <= base)
                i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            printData(a, end + 1);
        }

        a[start] = a[i];
        a[i] = base;
        printf("search done:");
        printData(a, end + 1);
        sort_quick(a, start, i - 1);
        sort_quick(a, i + 1, end);
    }
}

void sort_insert(int *a, int num)
{
    int i, j = 0;
    int temp;

    for (i = 1; i < num; i++)
    {
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            for (j = i; j >= 0; j--)
            {
                if (j > 0 && a[j - 1] > temp)
                {
                    a[j] = a[j - 1];
                }
                else
                {
                    a[j] = temp;
                    break;
                }
            }
        }
        printf("search done:");
        printData(a,num);
    }
}

void sort_shell(int *a, int num){

    int i,j = 0;
    int temp = 0;
    int scale = round(num);
    while(scale > 0){

        for(i=scale;i<num;i++){
            temp = a[i];
            j = i;
            while ( j >= scale && a[j-scale] > temp ){
                a[j] = a[j-scale];
                j = j - scale;
            }
            a[j] = temp;
        }
        scale = round(scale/2);
        printf("search done:");
        printData(a,num);
    }
}