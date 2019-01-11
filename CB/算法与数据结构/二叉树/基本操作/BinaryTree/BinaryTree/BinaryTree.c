#include"BinaryTree.h"
#include<stdio.h>
#include<malloc.h>


/*bool CreateBinaryTree(pBinaryTree* pBT)
{
	ElementType data;
	printf("请输入该节点数据：");
	scanf_s("%s", &data);
	if (data == '#')
	{
		*pBT = NULL;
		return false;
	}
	else
	{
		/*此处需要为每个形参分配内存，因为递归传进去的leftchild,rightchild从第一个节点之后就为空，因此需要用二级指针*/
		/**pBT = (pBinaryTree)malloc(sizeof(BinaryTree));
		(*pBT)->data = data;
	    CreateBinaryTree(&((*pBT)->leftchild));//传入指针的指针指向的地址
	    CreateBinaryTree(&((*pBT)->rightchild));
	    return true;
	}
}*/
/*构造一个平衡树：18 14 12 0 0 15 0 0 24 20 0 0 25 0 0*/
pBinaryTree CreateBinaryTree(int n)
{
	ElementType data;
	pBinaryTree pTempBT = (pBinaryTree)malloc(sizeof(BinaryTree));
	printf("请输入该%d节点数据：",n);
	scanf_s("%d", &data);
	if (data == 0)
	{
		return NULL;
	}
	else
	{
		pTempBT->data = data;
		pTempBT->leftchild = CreateBinaryTree(n-1);
		pTempBT->rightchild = CreateBinaryTree(n+1);
		return pTempBT;
	}
}


bool PreOrderTraversal(pBinaryTree pBT)
{
	if (pBT)
	{
		printf("%d\n", pBT->data);
		PreOrderTraversal(pBT->leftchild);
		PreOrderTraversal(pBT->rightchild);
return true;
	}
	else
	{
		return false;
	}
}


bool InOrderTraversal(pBinaryTree pBT)
{
	if (pBT)
	{
		InOrderTraversal(pBT->leftchild);
		printf("%d\n", pBT->data);
		InOrderTraversal(pBT->rightchild);
		return true;
	}
	else
	{
		return false;
	}
}


bool PostOrderTraversal(pBinaryTree pBT)
{
	if (pBT)
	{
		PostOrderTraversal(pBT->leftchild);
		PostOrderTraversal(pBT->rightchild);
		printf("%d\n", pBT->data);
		return true;
	}
	else
	{
		return false;
	}
}


TreePosition Find(pBinaryTree pBT, ElementType data)
{
	if (pBT)
	{
		if (data > pBT->data)
		{
			return Find(pBT->rightchild, data);
		}
		else if (data < pBT->data)
		{
			return Find(pBT->leftchild, data);
		}
		else
		{
			return pBT;
		}
	}
	else
	{
		printf("二叉树中没有这个数！\n");
		return NULL;
	}
}


TreePosition FindMin(pBinaryTree pBT)
{
	/*非递归方法*/
	pBinaryTree pTempTree = pBT;
	while (pTempTree)
	{
		if (!pTempTree->leftchild)
		{
			return pTempTree;
		}
		else
		{
			pTempTree = pTempTree->leftchild;
		}
	}
	return pTempTree;
	/*递归方法*/
	/*if (pBT)
	{
	if (pBT->leftchild)
	{
	return FindMin(pBT->leftchild);
	}
	else
	return pBT;
	}
	else
	return NULL;*/
}


TreePosition FindMax(pBinaryTree pBT)
{
	if (pBT)
	{
		if (pBT->rightchild)
		{
			return FindMax(pBT->rightchild);
		}
		else
			return pBT;
	}
	else
		return NULL;
}


pBinaryTree InsertTree(pBinaryTree pBT, ElementType data)
{
	if (pBT)
	{
		if (data < pBT->data)
		{
			/*将插入的节点传出来，要么用返回值，要么用二级指针*/
			pBT->leftchild = InsertTree(pBT->leftchild, data);
			return pBT;
		}
		else if (data > pBT->data)
		{
			pBT->rightchild = InsertTree(pBT->rightchild, data);
			return pBT;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		pBT = (pBinaryTree)malloc(sizeof(BinaryTree));
		pBT->data = data;
		pBT->leftchild = pBT->rightchild = NULL;
		return pBT;
	}
}


pBinaryTree DeleteTreeNode(pBinaryTree pBT, ElementType data)
{
	if (pBT)
	{
		/*首先找到data值树节点*/
		if (data < pBT->data)
		{
			pBT->leftchild = DeleteTreeNode(pBT->leftchild, data);
			return pBT;
		}
		else if (data > pBT->data)
		{
			pBT->rightchild = DeleteTreeNode(pBT->rightchild, data);
			return pBT;
		}
		else
		{
			/*找到该节点后分两种情况：1.该结点左右两结点均非空，此时将其右子树的最小值赋给该结点（也可选取左子树的最大值），之后将右子树中该结点删去；
			                          2.该结点有一个子树，或者无子树。无子树直接删除，如果有子树，则将该子树赋给该结点即可；
			 */
			if (pBT->leftchild && pBT->rightchild)
			{
				TreePosition ptempBT = (TreePosition)malloc(sizeof(BinaryTree));
				ptempBT = FindMin(pBT->rightchild);//找右子树最小值或左子树最大值
				pBT->data = ptempBT->data;
				pBT->rightchild = DeleteTreeNode(pBT->rightchild, pBT->data);
				free(ptempBT);
				return pBT;
			}
			else
			{
				if (pBT->leftchild)
				{
					pBT = pBT->leftchild;
				}
				else if (pBT->rightchild)
				{
					pBT = pBT->rightchild;
				}
				return pBT;
			}
		}
	}
	else
	{
		printf("该树中无此数！\n");
		return pBT;
	}
}


int main()
{
	pBinaryTree pBT = (pBinaryTree)malloc(sizeof(BinaryTree));
	TreePosition pTemp = (TreePosition)malloc(sizeof(BinaryTree));
	TreePosition pMax = (TreePosition)malloc(sizeof(BinaryTree));
	TreePosition pMin = (TreePosition)malloc(sizeof(BinaryTree));
	pBT = CreateBinaryTree(0);
	InsertTree(pBT, 12);
	DeleteTreeNode(pBT, 14);
	PreOrderTraversal(pBT);
	InOrderTraversal(pBT);
	PostOrderTraversal(pBT);
	pTemp = Find(pBT, 20);
	if (pTemp)
	{
		printf("您要找的数是%d\n", pTemp->data);
	}
	pMax = FindMax(pBT);
	if (pMax)
	{
		printf("最大数是%d\n", pMax->data);
	}
	pMin = FindMin(pBT);
	if (pMin)
	{
		printf("最小数是%d\n", pMin->data);
	}
}