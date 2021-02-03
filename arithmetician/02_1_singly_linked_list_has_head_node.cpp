/***
 * @Description: 单链表实验
 * @Author: Black_R
 * @Date: 2021-02-03 15:02:17
 * @LastEditors: Black_R
 * @LastEditTime: 2021-02-03 15:02:18
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 声明单链表
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/****************************************************************
----------------------------基本操作-----------------------------
****************************************************************/

// 初始化 含头节点链表
bool InitListHasHeadNode(LinkList &list)
{
    //分配一个头结点
    list = (LNode *)malloc(sizeof(LNode));
    if (list == NULL)
    {
        return false;
    }
    //头结点当前没有子结点，同样通过判断子节点有无判断链表是否为空
    list->next = NULL;
    return true;
}

//获取单链表长度
int Length(LinkList list)
{
    int length = 0;
    LNode *p = list;
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

// 按位查找 返回第i个结点
LNode *GetElem(LinkList &list, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p;
    p = list;
    int loop = 0;

    while (loop < i && p != NULL)
    {
        p = p->next;
        loop++;
    }
    return p;
}

// 按值查找 返回第一个值为e的元素
LNode *LocateElem(LinkList &list, int e)
{
    LNode *p = list;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 前插：在指定的结点P前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    //内存已满 分配失败
    if (tmp == NULL)
    {
        return false;
    }
    tmp->data = p->data;
    p->data = e;
    tmp->next = p->next;
    p->next = tmp;
    return true;
}

// 后插：在指定的结点P后插入元素e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    //内存已满 分配失败
    if (tmp == NULL)
    {
        return false;
    }

    tmp->data = e;
    tmp->next = p->next;
    p->next = tmp;
    return true;
}

// 在第i个位置插入一个元素e 含头节点
bool ListInsertHasHeadNode(LinkList &list, int i, int e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(list, i - 1);

    return InsertNextNode(p, e);
}

// 删除指定结点P
bool DeleteNode(LNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    return true;
}

// 删除第i个结点
bool ListDelete(LinkList &list, int i, int &e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = GetElem(list, i - 1);

    //p为空 链表已结束。或p(i-1)的下位为空，则不存在要删除的i
    if (p == NULL || p->next == NULL)
    {
        return false;
    }

    return DeleteNode(p);
}

//头插法
//尾插法
int main()
{
    LinkList list;
    InitListHasHeadNode(list);

    //位插 期望 100-200-300-500;
    ListInsertHasHeadNode(list, 1, 300);
    ListInsertHasHeadNode(list, 1, 100);
    ListInsertHasHeadNode(list, 2, 200);
    ListInsertHasHeadNode(list, 4, 500);

    //测试 前插
    LNode *p = list;
    int i = 1;
    while (i < 5)
    {
        p = p->next;
        i++;
    }
    InsertPriorNode(p, 400);

    int a = 1;
    ListDelete(list, 4, a);
    a = 1;
}
