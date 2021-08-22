/*
 * SingleLink
 * 1.创建结点
 * 2.初始化
 *  2.1 建立头结点
 *  2.2 初始化头结点
 * 3.插入操作
 *  3.1 头插法
 *  3.2 尾插法
 * 4.遍历
 *  4.1 顺序遍历
 * 5.删除
 */

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0


typedef struct LNode {
    int data;               // 数据
    struct LNode *next;     // 下一个结点
}LNode;


LNode* InitList(){
    LNode* L = (LNode*)malloc(sizeof(LNode));       // 创立头结点，创立结点，需要空间
    L ->data = 0;                                   // 用头结点记录当前链表中有多少元素
    L ->next = NULL;
    return L; // 最后要返回的
}

void SingleLinkHeadInsert(LNode *L,int data)//传入头指针和数据
{
    // 给data找个空建立一个结点
    LNode *node;
    node = (LNode *)malloc(sizeof(LNode));
    node ->data = data;
    node ->next = L->next;
    L ->next = node;
    L ->data++;
}

// 传入头指针
void PrintList(LNode *L){
    printf(" come in");
    LNode *node; // 建立一个结点
    node = L->next;
    while(node){
        printf("%d\n",node ->data);
        node = node ->next;
    }
}

void SingleTailInsert(LNode *L,int data)
{
    LNode *node = L;
    for (int i = 0;i<L->data;i++){
        // printf("%d"
        node = node->next;
    }

    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->data = data;
    n->next = NULL;
    node->next = n;
    L->data ++;
}

void TailInsert(LNode *L,int data){
	LNode* node = (LNode *)malloc(sizeof(LNode));
	node ->data = data;
	node ->next = NULL;
	LNode* Lnode = L;
	for (int i = 0;i <L->data;i++){
		Lnode = Lnode ->next;
	}
	Lnode->next= node;
	L->data++;
}
// void SingleLinkDelect()


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



int main(){
    LNode* L = InitList();
    SingleLinkHeadInsert(L,1);
    SingleLinkHeadInsert(L,2);
    SingleLinkHeadInsert(L,3);
    SingleLinkHeadInsert(L,4);
    SingleLinkHeadInsert(L,5);
    SingleLinkHeadInsert(L,6);
    SingleLinkHeadInsert(L,7);
    int c = DeleteElem(L,7);
    PrintList(L);
    LNode *h = (LNode*)malloc(sizeof(LNode));
    *h = GetElemReturn(L,4);
    if (c)
        printf("删除成功");
    return 0;

}
