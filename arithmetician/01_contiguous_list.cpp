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
