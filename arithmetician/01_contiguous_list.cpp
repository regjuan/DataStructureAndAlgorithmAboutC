#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 静态顺序表
#define kMaxSize 10
typedef struct
{
    //{element_type} data[list_size]
    int data[kMaxSize];
    int length;
} StaticSqlist;

// 动态分配顺序表
#define InitSize 10
typedef struct
{
    //{element_type} *data 指向线性表头部
    int *data;
    //{element_type} data[list_size]
    int MaxSize;
    int length;
} DynamicSqlist;

/****************************************************************
----------------------------工具方法-----------------------------
****************************************************************/
// 输出顺序表
void LoopOutput(int list[], int loop_amount)
{
    for (int loop = 0; loop < loop_amount; loop++)
    {
        printf("%d ", list[loop]);
    }
}

// 随机生成动态声明的list的数据
void RandomlyDynamicSqlist(DynamicSqlist &list, int count)
{
    //更新随机种子
    srand((unsigned int)time(NULL));
    for (int i = 0; i < count; i++)
    {
        if (i > list.MaxSize)
        {
            break;
        }
        list.data[i] = rand() % 50;
        list.length++;
    }
}

/****************************************************************
-------------------------顺序表-静态生成-------------------------
****************************************************************/
// 初始化静态分配方式生成的顺序表
void StaticInitLinelist(StaticSqlist &list)
{
    for (int i = 0; i < kMaxSize; i++)
    {
        list.data[i] = 0; //赋初值 屏蔽内存地址不为空的影响
        list.length = 0;  //线性表中有效数据数
    }
}

/****************************************************************
-------------------------顺序表-动态生成-------------------------
****************************************************************/
// 初始化动态分配方式生成的顺序表
void DynamicInitLinelist(DynamicSqlist &list)
{
    list.data = (int *)malloc(sizeof(int) * InitSize);
    list.MaxSize = InitSize;
    list.length = 0;
}

void DynamicInitLinelist(DynamicSqlist &list, int list_length)
{
    list.data = (int *)malloc(sizeof(int) * list_length);
    list.MaxSize = list_length;
    list.length = 0;
}

// 更改动态分配的顺序表的表长
void DynamicChangeListLength(DynamicSqlist &list, int len)
{
    int *tmp = list.data;

    //开辟新长度的空间
    list.data = (int *)malloc(sizeof(int) * (len + list.MaxSize));

    //将原数据写入新空间
    for (int i = 0; i < list.length; i++)
    {
        list.data[i] = tmp[i];
    }
    list.MaxSize = len + list.MaxSize;
    free(tmp);
}

/****************************************************************
-------------------------顺序表-基本操作-------------------------
****************************************************************/

// 查找第一个等于e的元素，返回位序 不存在则返回-1
int LocateElem(DynamicSqlist list, int e)
{
    for (int i = 0; i < list.length; i++)
    {
        if (list.data[i] == e)
        {
            return i;
        }
    }
    return -1;
}

// 返回第e个位置的元素
int GetElem(DynamicSqlist list, int i)
{
    //i 在范围内判断
    return list.data[i - 1];
}

// 在list的第i位插入e
bool ListInsert(DynamicSqlist &list, int i, int e)
{
    //无法插入情况：1非法位置,2.超出长度 中间有空白数据;3.线性表已满
    if (i < 1 || i > list.length || list.length >= list.MaxSize)
    {
        return false;
    }
    for (int j = list.length; j >= i; j--)
    {
        list.data[j] = list.data[j - 1];
    }
    list.data[i - 1] = e;
    list.length++;
    return true;
}

int ListInsert(DynamicSqlist &list, int i, int e, char type[])
{
    //无法插入情况：1非法位置,2.超出长度 中间有空白数据;3.线性表已满
    if (i < 1)
    {
        return 1;
    }
    if (i - 1 > list.length)
    {
        return 2;
    }
    if (list.length >= list.MaxSize)
    {
        return 3;
    }

    for (int j = list.length; j >= i; j--)
    {
        list.data[j] = list.data[j - 1];
    }
    list.data[i - 1] = e;
    list.length++;
    return 100;
}

// 在list中删除第i个元素 成功后返回该元素
bool ListDelete(DynamicSqlist &list, int i, int &e)
{
    if (i<1; i> list.length)
    {
        return false;
    }
    e = list.data[i - 1];
    for (; i < list.length; i++)
    {
        list.data[i - 1] = list.data[i];
    }
    list.length--;
    return true;
}

/****************************************************************
-------------------------顺序表-测试单元-------------------------
****************************************************************/
// TESTUNIT 静态生成的单元测试
void TestUnit_StaticSqlist()
{
    StaticSqlist list;
    StaticInitLinelist(list);

    //输入校验
    LoopOutput(list.data, kMaxSize);
}

// TESTUNIT 动态生成的单元测试：生成/更改长度
void TestUnit_DynamicSqlist()
{
    DynamicSqlist list;
    //初始化
    DynamicInitLinelist(list);

    //生成数据
    RandomlyDynamicSqlist(list, 5);

    //输出更改长度后的表
    LoopOutput(list.data, list.MaxSize);
    printf("\n");

    //更改顺序表长度
    DynamicChangeListLength(list, 5);

    //输出更改长度后的表
    //tips:会有脏数据，为展现重写入故输出所有值
    LoopOutput(list.data, list.MaxSize);
    printf("\n");
}

/***************************************************************/
int main()
{
    DynamicSqlist list;
    //创建一个长度为10的顺序表
    DynamicInitLinelist(list, 10);

    //输出所有脏数据
    LoopOutput(list.data, 10);

    printf("\n");
    printf("-------------");
    printf("\n");

    //常规输出
    LoopOutput(list.data, list.length);

    printf("\n");
    printf("-------------");
    printf("\n");

    //写入数据
    RandomlyDynamicSqlist(list, 10);

    //输出
    LoopOutput(list.data, list.length);

    printf("\n");
    printf("-------------");
    printf("\n");

    //获取第五个元素 即位序4
    int five = GetElem(list, 5);
    printf("%d", five);

    printf("\n");
    printf("-------------");
    printf("\n");

    //测试定位
    list.data[4] = 8;
    int where_eight = LocateElem(list, 8);

    LoopOutput(list.data, list.length);
    printf("\n");
    printf("%d", where_eight);

    printf("\n");
    printf("-------------");
    printf("\n");

    //测试插入
    //1.异常：非法位置
    int sign = ListInsert(list, -1, 999, "int");
    LoopOutput(list.data, list.length);
    printf("\n");
    printf("1:%d\n", sign);

    //2.异常：跳跃
    sign = ListInsert(list, 10, 999, "int");
    LoopOutput(list.data, list.length);
    printf("\n");
    printf("2:%d\n", sign);

    //3.正常
    sign = ListInsert(list, 1, 999, "int");
    LoopOutput(list.data, list.length);
    printf("\n");
    printf("3.1:%d\n", sign);

    sign = ListInsert(list, 10, 1010, "int");
    LoopOutput(list.data, list.length);
    printf("\n");
    printf("3.2:%d\n", sign);

    //5.异常：内存已满
    sign = ListInsert(list, 2, 1010, "int");
    LoopOutput(list.data, list.length);
    printf("\n");
    printf("4:%d\n", sign);

    //删除测试
    ListDelete(list, 1, sign);
    printf("删除了:%d\n", sign);
    LoopOutput(list.data, list.length);
    printf("\n");

    ListDelete(list, 5, sign);
    printf("删除了:%d\n", sign);
    LoopOutput(list.data, list.length);
    printf("\n");
}
