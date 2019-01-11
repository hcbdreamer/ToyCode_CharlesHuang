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
/*功能：创建二叉树
  返回值：树指针
  注：n为标志位，用于判断当前数位于左子树还是右子树，初始值最好设为0*/
pBinaryTree CreateBinaryTree(int n);


/*功能：前序遍历*/
bool PreOrderTraversal(pBinaryTree pBT);


/*中序遍历*/
bool InOrderTraversal(pBinaryTree pBT);


/*后续遍历*/
bool PostOrderTraversal(pBinaryTree pBT);


/*功能：往树节点中插入一个新值
    注：跟查找过程类似*/
pBinaryTree InsertTree(pBinaryTree pBT, ElementType data);


/*功能：查找data在数中的位置
  返回值：值所在树节点的位置指针
  注：查找树满足如下性质：1.非空右子树所有键值大于其根节点的键值
                          2.非空左子树所有键值小于其根节点的键值
						  3.左右子树都是二叉搜索树*/
TreePosition Find(pBinaryTree pBT, ElementType data);


/*功能：找到树中最小值的位置
返回值：返回最小值的位置指针*/
TreePosition FindMin(pBinaryTree pBT);


/*功能：找到树中最小值的位置
返回值：返回最小值的位置指针*/
TreePosition FindMax(pBinaryTree pBT);


/*功能：删除data值所在的结点
    注：分三种情况：1.该节点无左右子树，直接删除即可
	                2.该节点只有一个子树，调节其父节点指针指向子树即可
					3.该节点有左右子树，两种策略：1.找到右子树最小值，将其值赋给该结点，之后删除现在此节点右子树最小值的那个结点
                                                  2.找到左子树最大值，将其值赋给该结点，之后删除现在此节点左子树最大值的那个结点*/
pBinaryTree DeleteTreeNode(pBinaryTree pBT, ElementType data);
