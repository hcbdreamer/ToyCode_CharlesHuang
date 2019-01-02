#include "List.h"
#include <malloc.h>


/*��ע����ָ��֮��ĸ�ֵ�ǵ�ַ�ĸ�ֵ������һ��ָ��ָ��ĵ�ַ������һ��ָ�롣*/
pListNode CreateList(int n)
{
	pListNode pHead = (pListNode)malloc(sizeof(ListNode));
	pListNode pRear = pHead;
	ElementType pNewData;
	pRear->Next = NULL;
	for (int i = 0; i < n; i++)
	{
		pListNode pNewNode = (pListNode)malloc(sizeof(ListNode));
		printf("�������%d���ڵ�����ݣ�", i+1);
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
		printf("�������%d���ڵ�����ݣ�", i + 1);
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
		printf("������\n");
		return 0;
	}
	pListNode pNewNode = List->Next;
	while (pNewNode != NULL)
	{
		printf("��%d���ڵ�������ǣ�%d\n", i,pNewNode->Data);
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
		printf("������\n");
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
		printf("������\n");
		return 0;
	}
	int i = 0;
	pListNode pTempNode = (pListNode)malloc(sizeof(ListNode));
	pListNode pNewNode = List->Next;
	if (position < 0)
	{
		printf("�������޷��ҵ���λ�ã�\n");
		return 0;
	}
	/*�˴���i���ڵ�ָ���ǲ�����ͷ�ڵ㣬��ͷ�ڵ�+i���ڵ��λ��*/
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
		printf("������\n");
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
		printf("���������޴�����\n");
		return 0;
	}
	printf("Ѱ�ҵ����ڵ�%d��λ��\n", position);
	return position;
}


bool DeleteNode(pListNode List, ElementType data)
{
	
    pListNode pNewNode = List;
	if (pNewNode == NULL || pNewNode->Next == NULL)
	{
		printf("������\n");
		return 0;
	}
	while (pNewNode->Next->Next != NULL && pNewNode->Next->Data != data)
	{
		pNewNode = pNewNode->Next;
	}
	if (pNewNode->Next->Next == NULL)
	{
		printf("�������޴�����\n");
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
	/*ע���˴���Ҫ��һ����ʱ�������洢pNewNodeָ����ڴ�ռ��ֵ����Ϊһ��pNewNodeָ��һ�����ͷţ��ͳ�Ϊ��Ұָ�롣��ʱ���ܱ������ڴ�ռ��*/
	while (pNewNode != NULL)
	{
		pTempNode = pNewNode->Next;
    /*free����pNewNodeָ����ǿ��ڴ����򣬵���pNewNodeָ����Ȼ���ڣ�������ָ��ԭ���Ķѵ�ַ�����Ǹõ�ַ�ܿ��ܱ��������������*/
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
	//printf("Ѱ�ҵ����ڵ�%d��λ��\n", position);
	DeleteNode(pList, 20);
	AddNode(pList, 60);
	TraverseList(pList);
	DeleteList(pList);
	TraverseList(pList);
	AddNode(pList, 60);
	TraverseList(pList);
}