#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4326 4996 6001 6031)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr, *QueuePtr;

void main()
{
	int  AddQueue(QueuePtr& pQueue, Item nItem);
	int  DeleteQueue(QueuePtr& pQueue, Item& nItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	QueuePtr pQueue = NULL;
	while (1) {
		int value;
		printf("-2:Exit -1:Delete, *:Add ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		else if (value == -1) {
			if (DeleteQueue(pQueue, value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (AddQueue(pQueue, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintQueue(pQueue);
	}
}

NodePtr FindLast(NodePtr pList)
{
	if (pList)
		while (pList->link)
			pList = pList->link;
	return pList;
}
int AddQueue(QueuePtr& pQueue, Item nItem)
{	// queue에 nItem을 추가하고 성공하면 true 아니면 false를 반환한다.
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nItem;
		NodePtr pLast = FindLast(pQueue);
		pLast ? pLast->link = pNew : pQueue = pNew;
		pNew->link = NULL;
	}
	return pNew != NULL;
}

int DeleteQueue(QueuePtr& pQueue, Item& nItem)
{	//queue에서 삭제하여 nItem에 저장하고 성공하면 true 아니면 false를 반환한다.
	NodePtr pDel = pQueue;
	if (pDel) {
		nItem = pDel->nData;
		pQueue = pDel->link;
		delete pDel;
	}
	return pDel != NULL;
}

void PrintQueue(QueuePtr pQueue)
{
	NodePtr pNode = pQueue;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n");
	pNode = pQueue;
	while (pNode) {
		printf("%4d", pNode->nData);
		pNode = pNode->link;
	}
	printf("\n");
	pNode = pQueue;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
