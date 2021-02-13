/***
 * @Description: 用途双链表实验
 * @Author: Black_R
 * @Date: 2021-02-09 16:06:59
 * @LastEditors: Black_R
 * @LastEditTime: 2021-02-09 16:07:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode, *DLinklist;

//初始化
bool InitDLinklist(DLinklist &list)
{
    list = (DNode *)malloc(sizeof(DNode));
    if (list != NULL)
    {
        return false;
    }
    list->next = NULL;
    list->prior = NULL;
    return true;
}

// 判断链表为空
bool IsEmpty(DLinklist list)
{
    if (list->next == NULL)
    {
        return true;
    }
    return false;
}

// 找到链表中第i个元素
DNode *GetElem(DLinklist &list, int i)
{
    if (i < 0)
    {
        return NULL;
    }

    DNode *tmp = list;
    int sign = 1;
    while (sign < i && tmp != NULL)
    {
        tmp = tmp->next;
        sign++;
    }
    return tmp;
}

// 找到链表中第一个等于e的元素
DNode *LocateElem(DLinklist &list, int e)
{
    DNode *node = list;
    while (node->data != e && node != NULL)
    {
        node = node->next;
    }

    return node;
}

//在结点p后插入元素为e的结点
bool InsertNextNode(DNode *node, int e)
{
    // 创建结点
    DNode *tmp = (DNode *)malloc(sizeof(DNode));
    tmp->data = e;

    // 建立链接
    tmp->next = node->next;
    if (node->next != NULL)
    {
        node->next->prior = tmp;
    }
    tmp->prior = node;
    node->next = tmp;

    return true;
}

//删除指定结点
bool DeleteNode(DNode *node)
{
    if (node == NULL)
    {
        return false;
    }
    node->prior->next = node->next;
    if (node->next != NULL)
    {
        node->next->prior = node->prior;
    }
    free(node);

    return true;
}

// 销毁双链表
void DestoryList(DLinklist &list)
{
    while (list->next != NULL)
    {
        DeleteNode(list->next);
    }
    //释放头节点空间
    free(list);
    //置空头指针
    list = NULL;
}

// TESTUNIT 双链表的测试单元
void testDlinkList()
{
    DLinklist list;
    InitDLinklist(list);
}
