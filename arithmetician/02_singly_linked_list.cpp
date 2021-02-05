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
typedef struct{
    int data;
    struct LNode *next;
}LNode, *LinkList;


/****************************************************************
----------------------------工具方法-----------------------------
****************************************************************/

/****************************************************************
----------------------------基本操作-----------------------------
****************************************************************/
// 初始化 无头节点链表
bool InitList(LinkList &list){
    //头指针为空则代表链表中还没有添加数据
    list = NULL;
    return true;
}


// 初始化 含头节点链表
bool InitListHasHeadNode(LinkList &list){
    //分配一个头结点
    list = (LNode *)malloc(sizeof(LNode));
    if(list == NULL){
        return false;
    }
    //头结点当前没有子结点，同样通过判断子节点有无判断链表是否为空
    list->next = NULL;
    return true;
}

// 在第i个位置插入一个元素e 含头节点
bool ListInsertHasHeadNode(LinkList &list, int i, int e){

}


int main(){

}
