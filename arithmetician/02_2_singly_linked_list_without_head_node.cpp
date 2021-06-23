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
