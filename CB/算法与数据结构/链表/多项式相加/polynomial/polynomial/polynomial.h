#include<stdbool.h>
typedef int ElementType;
typedef struct PolyNode
{
	ElementType Coefficient;
	ElementType Exponent;
	struct PolyNode* Next;
}Polynomial, *pPolynomial;


/*���ܣ�  ��������ʽ����*/
/*����ֵ�������õĶ���ʽ����ָ��*/
pPolynomial CreatePolynomial();


/*���ܣ�  ��ӡ�����ÿһ��*/
/*����ֵ��0�����ӡʧ�ܣ�1�����ӡ�ɹ�*/
bool PrintfResult(pPolynomial polynomialList);


/*���ܣ�  �������β�����½ڵ�*/
/*����ֵ��0�������ʧ�ܣ�1�������ɹ�*/
bool InsertNode(pPolynomial polynomialList, ElementType Coefficient, ElementType Exponent);


/*���ܣ�  ����������ʽ�����Ӧ���*/
/*����ֵ��ִ����ӷ�����������*/
pPolynomial AddPolynomial(pPolynomial Polynomial1, pPolynomial Polynomial2);
