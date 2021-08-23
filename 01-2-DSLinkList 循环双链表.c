#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 创立结点
typedef struct DCNode{
	int data;
	struct DCNode *next;
	struct DCNode *pre;
}DCNode;

// 初始化
DCNode* InitList(){
	DCNode *L = (DCNode*)malloc(sizeof(DCNode));
	L ->data = 0;
	L ->next = L;
	L ->pre = L;
	return L;
}

// 判空
bool IsEmpty(DCNode *L){
	if (L->next == L)
		return true;
	return false;
}

// 插入

// 头插
void DCHeadInsert(DCNode *L,int data){
	DCNode *node = (DCNode *)malloc(sizeof(DCNode));

	node ->data = data;
	node ->next = L->next;
	L ->next ->pre = node;
	node ->pre = L;
	L ->next = node;
	L ->data ++;

}
// 尾插
void DCTailInsert(DCNode *L,int data){
	DCNode *node = (DCNode *)malloc(sizeof(DCNode));
	node ->data = data;
	node ->next = L;
	DCNode *n = L;
	for (int i=0;i<L->data;i++)
		n = n->next;
	node ->pre = n;
	n ->next = node;
	L ->data ++;
}

// 删除
bool DCDelete(DCNode *L, int data){
	DCNode *node = L->next;
	while (node!=L){
		if (node->data == data){
			node ->pre ->next = node ->next;
			node ->next ->pre = node ->pre;
			free(node);
			L->data --;
			return true;
		}
		node = node ->next;
	}
	return false;
}

// 查找
DCNode *FindAndReturn(DCNode *L,int data){
	DCNode *node = L->next;
	while (node!=L){
		if (node->data == data){
			return node;
		}
		node = node ->next;
	}
	return NULL;
}

// 输出
void PrintList(DCNode *L){
	DCNode *node = L->next;
	while (node!=L){
		printf("%d\n",node ->data);
		node = node ->next;
	}
}

int main(){
    DCNode *L = InitList();
    DCHeadInsert(L,12313);
    DCHeadInsert(L,12312);
    DCHeadInsert(L,12311);
    DCDelete(L,12313);
    DCTailInsert(L,111);
    DCTailInsert(L,222);
    if(!FindAndReturn(L,222122))
        PrintList(L);
    if (!IsEmpty(L))
        printf("not Empty\n");
}
