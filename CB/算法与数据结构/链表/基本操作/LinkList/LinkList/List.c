#include "List.h"
#include <malloc.h>


/*：注两个指针之间的赋值是地址的赋值，即将一个指针指向的地址赋给另一个指针。*/
pListNode CreateList(int n)
{
	pListNode pHead = (pListNode)malloc(sizeof(ListNode));
	pListNode pRear = pHead;
	ElementType pNewData;
	pRear->Next = NULL;
	for (int i = 0; i < n; i++)
	{
		pListNode pNewNode = (pListNode)malloc(sizeof(ListNode));
		printf("请输入第%d个节点的数据：", i+1);
		scanf_s("%d", &pNewData);

		pNewNode->Data = pNewData;
		pRear->Next = pNewNode;
		pNewNode->Next = NULL;
		pRear = pNewNode; 
	}
	//pRear->Next = NULL;
	return pHead;
}


/*pListNode CreateList(int n)
{
	pListNode pHead = (pListNode)malloc(sizeof(ListNode));
	pHead->Next = NULL;
	for (int i = 0; i < n; i++)
	{
		pListNode pNewNode = (pListNode)malloc(sizeof(ListNode));
		printf("请输入第%d个节点的数据：", i + 1);
		scanf_s("%d", &(pNewNode->Data));
		pNewNode->Next = pHead->Next;
		pHead->Next = pNewNode;
	}
	return pHead;
}*/


bool TraverseList(pListNode List)
{
	int i = 1;
	if (List == NULL && List->Next == NULL)
	{
		printf("空链表！\n");
		return 0;
	}
	pListNode pNewNode = List->Next;
	while (pNewNode != NULL)
	{
		printf("第%d个节点的数据是：%d\n", i,pNewNode->Data);
		i++;
		pNewNode = pNewNode->Next;
	}
	return 1;
}


bool AddNode(pListNode List, ElementType data)
{
	pListNode pNewNode = List;
	if (pNewNode == NULL)
	{
		printf("空链表！\n");
		return 0;
	}
	pListNode pTempNode = (pListNode)malloc(sizeof(ListNode));
	while (pNewNode->Next != NULL)
	{
		pNewNode = pNewNode->Next;
	}
	pTempNode->Data = data;
	pTempNode->Next = NULL;
	pNewNode->Next = pTempNode;
	return 1;
}


bool InsertNode(pListNode List, int position, ElementType data)
{
	if (List == NULL)
	{
		printf("空链表！\n");
		return 0;
	}
	int i = 0;
	pListNode pTempNode = (pListNode)malloc(sizeof(ListNode));
	pListNode pNewNode = List->Next;
	if (position < 0)
	{
		printf("链表中无法找到该位置！\n");
		return 0;
	}
	/*此处第i个节点指的是不包含头节点，即头节点+i个节点的位置*/
	while (pNewNode != NULL && i < position - 1)
	{
		pNewNode = pNewNode->Next;
		i++;
	}
	pTempNode->Data = data;
	pTempNode->Next = pNewNode->Next;
	pNewNode->Next = pTempNode;
	return 1;
}


int FindNode(ElementType data, pListNode List)
{
	if (List == NULL || List->Next ==NULL)
	{
		printf("空链表！\n");
		return 0;
	}
	pListNode pNewNode = List->Next;
	int position = 1;
	while (pNewNode->Next != NULL && pNewNode->Data != data)
	{
		pNewNode = pNewNode->Next;
		position++;
	}
	if (pNewNode->Next == NULL)
	{
		printf("该链表中无此数！\n");
		return 0;
	}
	printf("寻找的数在第%d个位置\n", position);
	return position;
}


bool DeleteNode(pListNode List, ElementType data)
{
	
    pListNode pNewNode = List;
	if (pNewNode == NULL || pNewNode->Next == NULL)
	{
		printf("空链表！\n");
		return 0;
	}
	while (pNewNode->Next->Next != NULL && pNewNode->Next->Data != data)
	{
		pNewNode = pNewNode->Next;
	}
	if (pNewNode->Next->Next == NULL)
	{
		printf("链表中无此数！\n");
		return 0;
	}
	pNewNode->Next = pNewNode->Next->Next;
	return 1;
}


bool DeleteList(pListNode List)
{
	pListNode pNewNode = List->Next;
	List->Next = NULL;
	pListNode pTempNode;
	//pListNode pTempNode = (pListNode)malloc(sizeof(ListNode));
	/*注：此处需要用一个临时变量来存储pNewNode指向的内存空间的值，因为一旦pNewNode指针一旦被释放，就成为了野指针。随时可能被其他内存占用*/
	while (pNewNode != NULL)
	{
		pTempNode = pNewNode->Next;
    /*free的是pNewNode指向的那块内存区域，但是pNewNode指针仍然存在，并且仍指向原来的堆地址，但是该地址很可能被分配给其他程序*/
		free(pNewNode);
		pNewNode = pTempNode;
	}
}


int main()
{
	pListNode pList = CreateList(10);
	int position = 0;
	InsertNode(pList, 3, 20);
	TraverseList(pList);
	position = FindNode(30, pList);
	//printf("寻找的数在第%d个位置\n", position);
	DeleteNode(pList, 20);
	AddNode(pList, 60);
	TraverseList(pList);
	DeleteList(pList);
	TraverseList(pList);
	AddNode(pList, 60);
	TraverseList(pList);
}