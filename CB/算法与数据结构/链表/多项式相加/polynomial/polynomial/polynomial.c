#include"polynomial.h"
#include<stdio.h>
#include<malloc.h>

pPolynomial CreatePolynomial()
{
	int n;
	printf("请输入多项式项数：");
	scanf_s("%d", &n);
	pPolynomial pHead = (pPolynomial)malloc(sizeof(Polynomial));
	pPolynomial pRear = pHead;
	ElementType pData1, pData2;
	pRear->Next = NULL;
	for (int i = 0; i < n; i++)
	{
		pPolynomial pTempNode = (pPolynomial)malloc(sizeof(Polynomial));
		printf("请输入多项式第%d项系数，指数：", i + 1);
		scanf_s("%d%d", &pData1, &pData2);
		pTempNode->Coefficient = pData1;
		pTempNode->Exponent = pData2;
		pTempNode->Next = NULL;
		pRear->Next = pTempNode;
		pRear = pTempNode;
	}
	return pHead;
}

bool PrintfResult(pPolynomial PolynomialList)
{
	pPolynomial pTempNode = PolynomialList;
	if (pTempNode == NULL || pTempNode->Next == NULL)
	{
		printf("空链表！\n");
		return false;
	}
	while (pTempNode->Next != NULL)
	{
		printf("%d %d\n", pTempNode->Next->Coefficient, pTempNode->Next->Exponent);
		pTempNode = pTempNode->Next;
	}
	return true;
}

bool InsertNode(pPolynomial polynomialList, ElementType Coefficient, ElementType Exponent)
{
	pPolynomial pTempNode = polynomialList;
	pPolynomial pNewNode = (pPolynomial)malloc(sizeof(Polynomial));
	if (pTempNode == NULL)
	{
		printf("空链表！\n");
		return false;
	}
	while (pTempNode->Next != NULL)
	{
		pTempNode = pTempNode->Next;
	}
	pNewNode->Coefficient = Coefficient;
	pNewNode->Exponent = Exponent;
	pNewNode->Next = NULL;
	pTempNode->Next = pNewNode;
	return true;
}

pPolynomial AddPolynomial(pPolynomial Polynomial1, pPolynomial Polynomial2)
{
	if (Polynomial1 == NULL || Polynomial2 == NULL || Polynomial1->Next == NULL || Polynomial2->Next == NULL)
	{
		printf("空链表！\n");
	}
	pPolynomial pTempNode1 = Polynomial1->Next;
	pPolynomial pTempNode2 = Polynomial2->Next;
	pPolynomial pTempNode3 = (pPolynomial)malloc(sizeof(Polynomial));
	pTempNode3->Next = NULL;
	while (pTempNode1 != NULL && pTempNode2 != NULL)
	{
		if (pTempNode1->Exponent < pTempNode2->Exponent)
		{
			InsertNode(pTempNode3, pTempNode1->Coefficient, pTempNode1->Exponent);
		    pTempNode1                    = pTempNode1->Next;
		}
		else if (pTempNode1->Exponent == pTempNode2->Exponent)
		{
			if (pTempNode1->Coefficient + pTempNode2->Coefficient != 0)
			{
				InsertNode(pTempNode3, pTempNode1->Coefficient + pTempNode2->Coefficient, pTempNode1->Exponent);
			}
			    pTempNode1 = pTempNode1->Next;
				pTempNode2 = pTempNode2->Next;
		}
		else
		{
			InsertNode(pTempNode3, pTempNode2->Coefficient, pTempNode2->Exponent);
			pTempNode2 = pTempNode2->Next;
		}
	}
	if (pTempNode1 == NULL)
	{
		pPolynomial pTempNode4 = pTempNode3;
		while (pTempNode4->Next != NULL)
		{
			pTempNode4 = pTempNode4->Next;
		}
		pTempNode4->Next = pTempNode2;
	}
	if (pTempNode2 == NULL)
	{
		pPolynomial pTempNode4 = pTempNode3;
		while (pTempNode4->Next != NULL)
		{
			pTempNode4 = pTempNode4->Next;
		}
		pTempNode4->Next = pTempNode1;
	}
	return pTempNode3;
}
int main()
{
	pPolynomial PolynomialList1 = (pPolynomial)malloc(sizeof(Polynomial));
    pPolynomial PolynomialList2 = (pPolynomial)malloc(sizeof(Polynomial));
	pPolynomial PolynomialList3 = (pPolynomial)malloc(sizeof(Polynomial));
	PolynomialList1 = CreatePolynomial();
	PolynomialList2 = CreatePolynomial();
	PrintfResult(PolynomialList1);
    PrintfResult(PolynomialList2);
	PolynomialList3 = AddPolynomial(PolynomialList1, PolynomialList2);
	PrintfResult(PolynomialList3);
}