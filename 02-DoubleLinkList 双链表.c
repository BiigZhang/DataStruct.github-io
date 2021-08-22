#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DoubleLinkList 双链表
// Create DNode   创立结点
typedef struct DNode{
	int data;
	struct DNode *pre;
	struct DNode *next;
}DNode;
// InitList        初始化
DNode* InitList(){
	DNode *L = (DNode*)malloc(sizeof(DNode));
	L ->data = 0;
	L ->pre = NULL;
	L ->next = NULL;
	return L;
}

// 判空 要使用bool类型就要导入<stdbool.h>
bool IsEmpty(DNode *L){
	if (L->next == NULL)
		return true;
	return false;
}

// 插入
// 在某个位置后插入
bool FindIndexInsert(DNode *L,int n,int data){
	if (n> L->data) return false;
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node ->data = data;
	DNode *Dnode = L;
	for (int i = 0;i<n;i++){
		Dnode = Dnode ->next;
	}
	node ->next = Dnode ->next;
	node ->pre = Dnode;
	Dnode ->next ->pre = node;
	Dnode ->next = node;
	L->data++;
	return true;
}

// 按查找元素插入
//elem为双链表中的某个元素,也可能不存在，data为将要插入的元素
bool FindElemInsert(DNode *L,int elem,int data){
	DNode *eNode = L->next;
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node ->data = data;
	while (eNode){
		if(eNode ->data == elem){
			node ->pre = eNode;
			node ->next = eNode->next;
			eNode ->next ->pre = node;
			eNode ->next = node;
			return true;
		}
		eNode = eNode ->next;
	}
	return false;

}

// 头插
void HeadInsert(DNode *L,int data){
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node ->data = data;
	node ->next = L->next;
	node ->pre = L;
	if (L->next == NULL){
        L ->next =node;
        L ->data ++;
    }
	else{
        L ->next ->pre = node;
        L ->next = node;
        L ->data ++;
    }
}

// 尾插
void TailInsert(DNode *L,int data){
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node ->next = NULL;
	node ->data = data;
	DNode *n = L;
	for (int i = 0;i<L->data;i++){
		n = n->next;
	}
	node ->pre = n;
	n ->next = node;
	L ->data++;
}
// 删除
bool DelectElem(DNode *L,int data){
	DNode *node =L->next;
	while (node){
		if(node ->data == data){
			node ->pre ->next = node ->next;
			node ->next ->pre =node ->pre;
			free(node);
			L ->data--;
			return true;
		}
		node = node ->next;
	}
	return false;
}

// 查找
bool FindElem(DNode *L,int elem){
	if (IsEmpty(L)) return false;
	DNode *node = L->next;
	while(node){
		if (node->data == elem)
			return true;
        node = node->next;
	}
    return false;
}


// 输出
void PrintList(DNode *L){
	DNode *node = L;
	node = L->next;
	while(node){
		printf("node = %d\n",node->data);
		node = node ->next;
	}
}

