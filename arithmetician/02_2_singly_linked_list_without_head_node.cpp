/***
 * @Description: 无头节点单链表
 * @Author: Black_R
 * @Date: 2021-02-05 15:58:13
 * @LastEditors: Black_R
 * @LastEditTime: 2021-02-05 15:58:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/****************************************************************
----------------------------基本操作-----------------------------
****************************************************************/
// 初始化 无头节点链表
bool InitList(LinkList &list)
{
    //第一个结点为空则代表链表中还没有添加数据
    list = NULL;
    return true;
}

//获取单链表长度
int Length(LinkList list)
{
    int length = 0;

    return length;
}

// 按位查找 返回第i个结点
LNode *GetElem(LinkList &list, int i)
{
    LNode *p;

    return p;
}

// 按值查找 返回第一个值为e的元素
LNode *LocateElem(LinkList &list, int e)
{
    LNode *p = list;

    return p;
}

// 前插：在指定的结点P前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
    return true;
}

// 后插：在指定的结点P后插入元素e
bool InsertNextNode(LNode *p, int e)
{
    return true;
}

// 在第i个位置插入一个元素e 含头节点
bool ListInsertHasHeadNode(LinkList &list, int i, int e)
{
    return true;
}

// 删除指定结点P
bool DeleteNode(LNode *p)
{
    return true;
}

// 删除第i个结点
bool ListDelete(LinkList &list, int i, int &e)
{
    return true;
}
