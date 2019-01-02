#include <stdio.h>
#include<stdbool.h>

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	struct Node* Next;
}ListNode,*pListNode;



/*���ܣ�  ����������ͷ�ڵ��β���뷨��*/
/*����ֵ��pListNode:ָ�򴴽������ָ��*/
pListNode CreateList(int n);


/*���ܣ�  ��������*/
/*����ֵ��0��������Ϊ�գ�1��������ɹ�*/
bool TraverseList(pListNode List);


/*���ܣ�  ����������Ϊdata�Ľڵ�*/
/*����ֵ��0�������ʧ�ܣ�1�������ɹ�*/
bool AddNode(pListNode List, ElementType data);


/*���ܣ�  ��ͷ�ڵ�֮���position���ڵ㴦����������Ϊdata�Ľڵ�*/
/*����ֵ��0�������ʧ�ܣ�1�������ɹ�*/
bool InsertNode(pListNode List, int position, ElementType data);


/*���ܣ�  Ѱ��������������Ϊdata�Ľڵ�λ��*/
/*����ֵ��Ϊ��������data��ȵĵ�һ���ڵ��λ�ã�ͷ�ڵ�Ϊ��0���ڵ㣩*/
int FindNode(ElementType data, pListNode List);


/*���ܣ�  ɾ��������������Ϊdata�Ľڵ�*/
/*����ֵ��0����ɾ��ʧ�ܣ�1����ɾ���ɹ�*/
bool DeleteNode(pListNode List, ElementType data);


/*���ܣ�  ɾ����������*/
/*����ֵ��0����ɾ��ʧ�ܣ�1����ɾ���ɹ�*/
bool DeleteList(pListNode List);

