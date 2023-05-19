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

int AddQueue(QueuePtr& pQueue, Item nItem)
{	// queue�� nItem�� �߰��ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nItem;
		if (pQueue) {
			pNew->link = pQueue->link;
			pQueue->link = pNew;
		}
		else
			pQueue = pNew->link = pNew;
		pQueue = pNew;
	}
	return pNew != NULL;
}

int DeleteQueue(QueuePtr& pQueue, Item& nItem)
{	//queue���� �����Ͽ� nItem�� �����ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	NodePtr pDel = NULL;
	if (pQueue) {
		pDel = pQueue->link;
		nItem = pDel->nData;
		if (pQueue == pDel)
			pQueue = NULL;
		else
			pQueue->link = pDel->link;
		delete pDel;
	}
	return pDel != NULL;
}

void PrintQueue(QueuePtr pQueue)
{
	NodePtr pNode, pFirst = pQueue ? pQueue->link : NULL;
	if (pNode = pFirst)
		do {
			printf("----");
			pNode = pNode->link;
		} while (pNode != pFirst);
	printf("--\n");
	if (pNode = pFirst)
		do {
			printf("%4d", pNode->nData);
			pNode = pNode->link;
		} while (pNode != pFirst);
	printf("\n");
	if (pNode = pFirst)
		do {
			printf("----");
			pNode = pNode->link;
		} while (pNode != pFirst);
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
