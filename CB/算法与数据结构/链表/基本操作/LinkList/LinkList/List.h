#include <stdio.h>
#include<stdbool.h>

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	struct Node* Next;
}ListNode,*pListNode;



/*功能：  创建链表（带头节点的尾插入法）*/
/*返回值：pListNode:指向创建链表的指针*/
pListNode CreateList(int n);


/*功能：  遍历链表*/
/*返回值：0代表链表为空；1代表遍历成功*/
bool TraverseList(pListNode List);


/*功能：  增加数据域为data的节点*/
/*返回值：0代表插入失败；1代表插入成功*/
bool AddNode(pListNode List, ElementType data);


/*功能：  在头节点之后第position个节点处插入数据域为data的节点*/
/*返回值：0代表插入失败；1代表插入成功*/
bool InsertNode(pListNode List, int position, ElementType data);


/*功能：  寻找链表中数据域为data的节点位置*/
/*返回值：为数据域与data相等的第一个节点的位置（头节点为第0个节点）*/
int FindNode(ElementType data, pListNode List);


/*功能：  删除链表中数据域为data的节点*/
/*返回值：0代表删除失败；1代表删除成功*/
bool DeleteNode(pListNode List, ElementType data);


/*功能：  删除整个链表*/
/*返回值：0代表删除失败；1代表删除成功*/
bool DeleteList(pListNode List);

