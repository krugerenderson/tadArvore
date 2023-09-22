#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode
{
    int value;
    treeNode *left;
    treeNode *right;
} treeNode;

treeNode *createNode(int value);
treeNode *copyTree(treeNode *tree);
treeNode *invertTree(treeNode *tree);
treeNode *insertNodeBST(treeNode *tree, int value);
treeNode *rotateLeft(treeNode *tree);
treeNode *rotateRight(treeNode *tree);
treeNode *insertNodeAVL(treeNode *tree, int value);
int treeHeight(treeNode *tree);
int balanceFactor(treeNode *tree);
int maxValue(treeNode *tree);
int minValue(treeNode *tree);
bool equalTrees(treeNode *treeA, treeNode *treeB);
void printTree(treeNode *tree, int tab);