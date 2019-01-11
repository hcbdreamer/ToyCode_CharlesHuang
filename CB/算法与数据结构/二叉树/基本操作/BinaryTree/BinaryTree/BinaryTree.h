#include<stdbool.h>
/*typedef struct Node* BinaryTree;
typedef int ElementType;
struct Node
{
	ElementType data;
	BinaryTree leftchild;
	BinaryTree rightchild;
};*/

typedef int ElementType;
typedef struct Tree
{
	ElementType data;
	struct Tree* leftchild;
	struct Tree* rightchild;

}BinaryTree,*pBinaryTree;
typedef pBinaryTree TreePosition;


//bool CreateBinaryTree(pBinaryTree* pBT);
/*���ܣ�����������
  ����ֵ����ָ��
  ע��nΪ��־λ�������жϵ�ǰ��λ����������������������ʼֵ�����Ϊ0*/
pBinaryTree CreateBinaryTree(int n);


/*���ܣ�ǰ�����*/
bool PreOrderTraversal(pBinaryTree pBT);


/*�������*/
bool InOrderTraversal(pBinaryTree pBT);


/*��������*/
bool PostOrderTraversal(pBinaryTree pBT);


/*���ܣ������ڵ��в���һ����ֵ
    ע�������ҹ�������*/
pBinaryTree InsertTree(pBinaryTree pBT, ElementType data);


/*���ܣ�����data�����е�λ��
  ����ֵ��ֵ�������ڵ��λ��ָ��
  ע�������������������ʣ�1.�ǿ����������м�ֵ��������ڵ�ļ�ֵ
                          2.�ǿ����������м�ֵС������ڵ�ļ�ֵ
						  3.�����������Ƕ���������*/
TreePosition Find(pBinaryTree pBT, ElementType data);


/*���ܣ��ҵ�������Сֵ��λ��
����ֵ��������Сֵ��λ��ָ��*/
TreePosition FindMin(pBinaryTree pBT);


/*���ܣ��ҵ�������Сֵ��λ��
����ֵ��������Сֵ��λ��ָ��*/
TreePosition FindMax(pBinaryTree pBT);


/*���ܣ�ɾ��dataֵ���ڵĽ��
    ע�������������1.�ýڵ�������������ֱ��ɾ������
	                2.�ýڵ�ֻ��һ�������������丸�ڵ�ָ��ָ����������
					3.�ýڵ����������������ֲ��ԣ�1.�ҵ���������Сֵ������ֵ�����ý�㣬֮��ɾ�����ڴ˽ڵ���������Сֵ���Ǹ����
                                                  2.�ҵ����������ֵ������ֵ�����ý�㣬֮��ɾ�����ڴ˽ڵ����������ֵ���Ǹ����*/
pBinaryTree DeleteTreeNode(pBinaryTree pBT, ElementType data);
