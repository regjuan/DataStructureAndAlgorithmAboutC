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
