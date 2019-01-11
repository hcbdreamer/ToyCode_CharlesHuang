#include"BinaryTree.h"
#include<stdio.h>
#include<malloc.h>


/*bool CreateBinaryTree(pBinaryTree* pBT)
{
	ElementType data;
	printf("������ýڵ����ݣ�");
	scanf_s("%s", &data);
	if (data == '#')
	{
		*pBT = NULL;
		return false;
	}
	else
	{
		/*�˴���ҪΪÿ���βη����ڴ棬��Ϊ�ݹ鴫��ȥ��leftchild,rightchild�ӵ�һ���ڵ�֮���Ϊ�գ������Ҫ�ö���ָ��*/
		/**pBT = (pBinaryTree)malloc(sizeof(BinaryTree));
		(*pBT)->data = data;
	    CreateBinaryTree(&((*pBT)->leftchild));//����ָ���ָ��ָ��ĵ�ַ
	    CreateBinaryTree(&((*pBT)->rightchild));
	    return true;
	}
}*/
/*����һ��ƽ������18 14 12 0 0 15 0 0 24 20 0 0 25 0 0*/
pBinaryTree CreateBinaryTree(int n)
{
	ElementType data;
	pBinaryTree pTempBT = (pBinaryTree)malloc(sizeof(BinaryTree));
	printf("�������%d�ڵ����ݣ�",n);
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
		printf("��������û���������\n");
		return NULL;
	}
}


TreePosition FindMin(pBinaryTree pBT)
{
	/*�ǵݹ鷽��*/
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
	/*�ݹ鷽��*/
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
			/*������Ľڵ㴫������Ҫô�÷���ֵ��Ҫô�ö���ָ��*/
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
		/*�����ҵ�dataֵ���ڵ�*/
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
			/*�ҵ��ýڵ������������1.�ý�������������ǿգ���ʱ��������������Сֵ�����ý�㣨Ҳ��ѡȡ�����������ֵ����֮���������иý��ɾȥ��
			                          2.�ý����һ��������������������������ֱ��ɾ����������������򽫸����������ý�㼴�ɣ�
			 */
			if (pBT->leftchild && pBT->rightchild)
			{
				TreePosition ptempBT = (TreePosition)malloc(sizeof(BinaryTree));
				ptempBT = FindMin(pBT->rightchild);//����������Сֵ�����������ֵ
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
		printf("�������޴�����\n");
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
		printf("��Ҫ�ҵ�����%d\n", pTemp->data);
	}
	pMax = FindMax(pBT);
	if (pMax)
	{
		printf("�������%d\n", pMax->data);
	}
	pMin = FindMin(pBT);
	if (pMin)
	{
		printf("��С����%d\n", pMin->data);
	}
}