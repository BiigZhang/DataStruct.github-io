# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// 循环单链表，就是尾指针指向头指针
// Create SCNode 创建循环链表结点
typedef struct SCNode{
	int data;
	struct SCNode* next;
}SCNode;

// initLink 初始化
SCNode* InitLink(SCNode *L){
	SCNode *L = (SCNode*)malloc(sizeof(SCNode));
	L ->data = 0;
	L ->next = L;
}

// 判空
bool IsEmpty(SCNode *L){
	if (L ->next == L)
		return true;
	return false;
}

// 插入

// 头插
void SCHeadInsert(SCNode *L,int data){
	SCNode *node = (SCNode*)malloc(sizeof(SCNode));
	node ->data = data;
	node ->next = L->next;
	L->next = node;
	L->data++;
}

// 尾插
void SCTailInsert(SCNode *L,int data){
	SCNode *node = (SCNode*)malloc(sizeof(SCNode));
	node ->data = data;
	node ->next = L;
	SCNode *n = L;
	for (int i = 0;i<L->data;i++){
		n = n->next;
	}
	n ->next = node;
	L->data ++;
}
// 输出
void PrintLink(SCNode *L){
	SCNode *node = L->next;
	while (node){
		printf("node : %d",node->data);
		node = node ->next;
	}
}
// 查找
bool FindElem(SCNode *L,int data){
	SCNode *node = L->data;
	while(node){
		if (node ->data == data)
			return true;
		node = node ->next;
	}
	return false;
}

// 删除
int DeleteElem(LNode *L,int data){
	LNode *PreNode = L;
	LNode *node = PreNode->next;
	while (node){
		if(node ->data ==data){
			PreNode->next = node->next;
			free(node);
			L->data--;
			return True;
		}
		PreNode = node;
		node = node->next;
	}
    return False;
}

// 找到某个元素,并返回其指针
LNode GetElemReturn(LNode *L,int elem){
	LNode *node;
	node = L->next;
	while(node){
		if (node ->data == elem)
			return *node;
		node = node ->next;
	}
	return *node;
}
