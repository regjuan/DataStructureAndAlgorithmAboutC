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
