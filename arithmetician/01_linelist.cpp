#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/****************************************************************
-------------------------线性表-静态生成-------------------------
****************************************************************/
#define kMaxSize 10

//静态顺序表
typedef struct{
    //{element_type} data[list_size]
    int data[kMaxSize];
    int length;
}StaticSqlist;

//初始化静态分配方式生成的顺序表
void StaticInitLinelist(StaticSqlist &list){
    for(int i=0; i<kMaxSize; i++){
        list.data[i] = 0;      //赋初值 屏蔽内存地址不为空的影响
        list.length = 0;       //线性表中有效数据数
    }
}

//TESTUNIT 静态生成的单元测试
int TestUnit_StaticSqlist(){
    StaticSqlist list;
    StaticInitLinelist(list);

    //输入校验
    for(int loop = 0; loop < 10; loop++){
        printf("%d ", list.data[loop]);
    }

    return 0;
}


/****************************************************************
-------------------------线性表-动态生成-------------------------
****************************************************************/
#define InitSize 10

//动态分配顺序表
typedef struct{
    //{element_type} *data 指向线性表头部
    int *data;
    //{element_type} data[list_size]
    int MaxSize;
    int length;
}DynamicSqlist;

//初始化动态分配方式生成的顺序表
void DynamicInitLinelist(DynamicSqlist &list){
    list.data = (int *)malloc(sizeof(int) * InitSize);
    list.MaxSize = InitSize;
    list.length = 0;
}

//更改动态分配的顺序表的表长
void DynamicChangeListLength(DynamicSqlist &list,int len){
    int *tmp = list.data;

    //开辟新长度的空间
    list.data = (int *)malloc(sizeof(int) * (len+list.MaxSize));

    //将原数据写入新空间
    for(int  i = 0; i < list.length; i++){
        list.data[i] = tmp[i];
    }
    list.MaxSize = len+list.MaxSize;
    free(tmp);
}

//TESTUNIT 动态生成的单元测试：生成/更改长度
int TestUnit_DynamicSqlist(){
    DynamicSqlist list;
    //初始化
    DynamicInitLinelist(list);


    //随机生成list数据
    //更新随机种子
    srand((unsigned int )time(NULL) );
    int seed_length = 5 + (rand() % 5);
    for (int i = 0; i < seed_length; i++)
    {
        list.data[i] = rand()%50;
        list.length++;
    }

    //输入校验
    for(int loop = 0; loop < list.MaxSize; loop++){
        printf("%d ", list.data[loop]);
    }
    printf("\n");

    //更改顺序表长度
    DynamicChangeListLength(list, 5);

    //输出更改长度后的表
    for(int loop = 0; loop < list.MaxSize; loop++){
        printf("%d ", list.data[loop]);
    }

    printf("\n");

}


/***************************************************************/
int main(){
    TestUnit_DynamicSqlist();
}
