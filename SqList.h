#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

// 状态码
#define OK      1
#define ERROR   0
#define TRUE    1
#define FALSE   0
#define INFEASIBLE -1
#define OVERFLOW -2

// 顺序表最大容量
#define MAXSIZE 100

// 类型定义
typedef int ElemType;
typedef int Status;

// 顺序表结构体
typedef struct SqList {
    ElemType *elem;
    int length;
} SqList;


// 函数声明

// 初始化顺序表
Status InitList(SqList *L);

// 清空顺序表
Status ClearList(SqList *L);

// 获取顺序表长度
int ListLength(SqList L);

// 获取第 i 个元素
Status GetElem(SqList L, int i, ElemType *e);

// 查找元素，返回其位置，未找到返回 0
int LocateList(SqList L, ElemType e);

// 在第 i 个位置插入元素 e
Status ListInsert(SqList *L, int i, ElemType e);

// 删除第 i 个元素，并通过 e 返回被删除的值
Status ListDelete(SqList *L, int i, ElemType *e);

// 遍历并输出顺序表
Status ListTraverse(SqList L);


#endif

