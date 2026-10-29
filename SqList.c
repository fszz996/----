#include <stdio.h>
#include <stdlib.h>
#define OK      1
#define ERROR   0
#define TRUE    1
#define FALSE    0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE    100
typedef int ElemType;  //声明ElemType的类型
typedef int Status;  //声明函数类型名

typedef struct SqList { 
        ElemType *elem;  //顺序表数据存储空间基址 
        int length;
}SqList;// LIST为用户定义的线性表类型

Status InitList(SqList *L){
    L ->elem = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));//强制类型转换为elemtype型

    if(L->elem == NULL){
        printf("内存申请失败");
        return 0;
    }

    L->length = MAXSIZE;
    return OK;
}

Status ClearList(SqList *L){
    L->length = 0;
    return OK;
}

int ListLength(SqList L){
    return L.length;
}

Status GetElem(SqList L,int i,ElemType *e){
    if (i>=1 && i<=L.length){
        *e = L.elem[i-1];
        return OK;
    }

    return ERROR;
}

int LocateList(SqList L , ElemType e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.elem[i] == e){
            return i+1;
            break;
        }
    }
    return 0;
}

Status ListInsert(SqList *L,int i,ElemType e){
    if(i<1||i>L->length+1||L->length+1>MAXSIZE){
        return ERROR;
    }

    int j;
    for(j=L->length;j>=i;j--){
        L->elem[j] = L->elem[j-1];//从最后开始,依次后移,notice最后的下标是j-1
    }

    L->elem[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e){
    if(i<1||i>L->length){
        return ERROR;
    }

    *e = L->elem[i-1]; 

    int j;
    for(j=i-1;j<L->length-1;j++){
        L->elem[j] = L->elem[j+1];
    }
    L->length--;
    return OK;
}

Status ListTraverse(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        printf("%d\n",L.elem[i]);
    }
    return OK;
}

//3

Status Union(SqList *La,SqList Lb){
    int i,j,found;
    for(i=0;i<Lb.length;i++){
        found = 0;

        for(j=0;j<La->length;j++){
            if(Lb.elem[i] == La->elem[j]){
                found++;
                break;
            }
        }

        if(found == 0){
            Status result = ListInsert(La, La->length + 1, Lb.elem[i]);
            if(result == ERROR)
                return ERROR;
        }
    }
    return OK;
}


Status Intersection(SqList *La, SqList Lb){
    int i, j, found;
    ElemType deleted;
    i = 1;
    while(i <= La->length){
        found = 0;
        for(j = 0; j < Lb.length; j++){
            if(La->elem[i - 1] == Lb.elem[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){//在b里面没找到当前的a[i-1],也就是非交部分
            Status result = ListDelete(La, i, &deleted);

            if(result == ERROR){
                return ERROR;
            }
        }else{//只有没删除的情况下才执行i++,避免删除后下标会前移从而跳过下一个element
            i++;
        }
    }
    return OK;
}

