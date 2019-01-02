#include<stdbool.h>
typedef int ElementType;
typedef struct PolyNode
{
	ElementType Coefficient;
	ElementType Exponent;
	struct PolyNode* Next;
}Polynomial, *pPolynomial;


/*功能：  创建多项式链表*/
/*返回值：创建好的多项式链表指针*/
pPolynomial CreatePolynomial();


/*功能：  打印链表的每一项*/
/*返回值：0代表打印失败；1代表打印成功*/
bool PrintfResult(pPolynomial polynomialList);


/*功能：  在链表表尾插入新节点*/
/*返回值：0代表插入失败；1代表插入成功*/
bool InsertNode(pPolynomial polynomialList, ElementType Coefficient, ElementType Exponent);


/*功能：  将两个多项式链表对应相加*/
/*返回值：执行完加法运算后的链表*/
pPolynomial AddPolynomial(pPolynomial Polynomial1, pPolynomial Polynomial2);
