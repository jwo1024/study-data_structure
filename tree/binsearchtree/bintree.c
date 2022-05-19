#include	"bintree.h"

#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *newTree;

    newTree = calloc(1, sizeof(BinTree));
    newTree->pRootNode = calloc(1, sizeof(BinTreeNode));
    *(newTree->pRootNode) = rootNode;
    return(newTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if(pBinTree && pBinTree->pRootNode)
        return (pBinTree->pRootNode);
    return (NULL);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if (pParentNode->pLeftChild != NULL)
        return (NULL);
    pParentNode->pLeftChild = calloc(1, sizeof(BinTreeNode));
    *(pParentNode->pLeftChild) = element;
    return (pParentNode->pLeftChild);
}
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if (pParentNode->pRightChild != NULL)
        return (NULL);
    pParentNode->pRightChild = calloc(1, sizeof(BinTreeNode));
    *(pParentNode->pRightChild) = element;
    return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode && pNode->pLeftChild)
        return (pNode->pLeftChild);
    return (NULL);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if (pNode && pNode->pRightChild)
        return (pNode->pRightChild);
    return (NULL);
}


void deleteBinTree(BinTree** pBinTree)
{
    BinTreeNode *rootNode;
    if (!pBinTree || !(*pBinTree) || !((*pBinTree)->pRootNode))
        return ;
    rootNode = (*pBinTree)->pRootNode;
    deleteAllNode(rootNode);
    free(*pBinTree);
    *pBinTree = NULL;
}

void  deleteAllNode(BinTreeNode *root)
{
    if (root == NULL)
        return;
    deleteAllNode(root->pLeftChild);
    deleteAllNode(root->pRightChild);
    free(root);
}

void deleteBinTreeNode(BinTreeNode** pNode)
{
    free(*pNode);
    *pNode = NULL;
}

void preOrderTraversalBinTree(BinTreeNode *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preOrderTraversalBinTree(root->pLeftChild);
    preOrderTraversalBinTree(root->pRightChild);
}

void inOrderTraversalBinTree(BinTreeNode *root)
{
    if (root == NULL)
        return ;
    inOrderTraversalBinTree(root->pLeftChild);
    printf("%c ", root->data);
    inOrderTraversalBinTree(root->pRightChild);
}

void postOrderTraversalBinTree(BinTreeNode *root)
{
    if (root == NULL)
        return ;
    postOrderTraversalBinTree(root->pLeftChild);
    postOrderTraversalBinTree(root->pRightChild);
    printf("%c ", root->data);
}
