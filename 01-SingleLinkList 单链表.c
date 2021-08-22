//SingleLinkList 单链表
//Create LNode       创建节点
 Typedef struct LNode{
	int data;				// 存储数据
	struct LNode *next;		// 存放下一个元素的地址
 }LNode;
// InitList           初始化
LNode* InitList(){
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L ->data = 0;
	L ->next = NULL;
	return L;
}
// HeadInsert         头插法
void HeadInsert(LNode *L,int data){
	LNode* node = (LNode *)malloc(sizeof(LNode));
	node ->data = data;
	node ->next = L ->next;
	L ->next = node;
	L ->data ++; 		// 计数
}
// TailInsert         尾插法
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
// PrintList          输出全部元素
void PrintList(LNode L){
	LNode *node = L->next; // 不要输出头结点
	while(node)
		printf("%d",L->data);
		node = node ->next;
}

// DeleteElem         删除某个元素
bool DeleteElem(LNode *L,int data){
	LNode *PreNode = L->next;
	LNode *node = PreNode->next;
	while(node){
		if (node ->data == data){
			PreNode ->next = node ->next;
			free(node);
			L->data--;
			return true;
		}
		PreNode = node;
		node = node ->next;
	}
	return false;
}


