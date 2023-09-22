#include <TADTree.h>

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
}

treeNode *createNode(int value)
{
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    if (newNode == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(-1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

treeNode *copyTree(treeNode *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    treeNode *newTree = createNode(tree->value);
    newTree->left = copyTree(tree->left);
    newTree->right = copyTree(tree->right);
    return newTree;
}

treeNode *invertTree(treeNode *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    treeNode *invertedTree = createNode(tree->value);
    invertedTree->left = invertTree(tree->right);
    invertedTree->right = invertTree(tree->left);
    return invertedTree;
}

int maxValue(treeNode *tree)
{
    if (tree == NULL)
    {
        return -1;
    }
    int Max = tree->value;
    int leftMax = maxValue(tree->left);
    int rightMax = maxValue(tree->right);
    if (leftMax > Max)
    {
        Max = leftMax;
    }
    if (rightMax > Max)
    {
        Max = rightMax;
    }
    return Max;
}

int minValue(treeNode *tree)
{
    if (tree == NULL)
    {
        return -1;
    }
    int Min = tree->value;
    int leftMin = minValue(tree->left);
    int rightMin = minValue(tree->right);
    if (leftMin < Min)
    {
        Min = leftMin;
    }
    if (rightMin < Min)
    {
        Min = rightMin;
    }
    return Min;
}

void printTree(treeNode *tree, int tab)
{
    for (int x = 0; x < tab; x++)
    {
        printf("-");
    }
    if (tree == NULL)
    {
        printf("null");
        return;
    }
    printf("%d\n", tree->value);
    printTree(tree->left, tab + 2);
    printf("\n");
    printTree(tree->right, tab + 2);
}

bool equalTrees(treeNode *treeA, treeNode *treeB)
{
    if (treeA == NULL && treeB == NULL)
    {
        return true;
    }
    if (treeA == NULL || treeB == NULL)
    {
        return false;
    }
    if (treeA->value != treeB->value)
    {
        return false;
    }
    bool leftEqual = equalTrees(treeA->left, treeB->left);
    bool rightEqual = equalTrees(treeA->right, treeB->right);
    return leftEqual && rightEqual;
}

treeNode *insertNodeBST(treeNode *tree, int value)
{
    if (tree == NULL)
    {
        treeNode *newNode = createNode(value);
        return newNode;
    }
    if (tree->value > value)
    {
        tree->left = insertNodeBST(tree->left, value);
    }
    else if (tree->value < value)
    {
        tree->right = insertNodeBST(tree->right, value);
    }
    else
    {
        printf("ERRO! Valor repetido.\n");
    }
    return tree;
}

int treeHeight(treeNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int leftHeight = treeHeight(tree->left);
    int rightHeight = treeHeight(tree->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int balanceFactor(treeNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return treeHeight(tree->left) - treeHeight(tree->right);
}

int treeElements(treeNode *tree)
{
}

treeNode *rotateLeft(treeNode *tree)
{
    treeNode *newNode = tree->right;
    tree->right = newNode->left;
    newNode->left = tree;
    return newNode;
}

treeNode *rotateRight(treeNode *tree)
{
    treeNode *newNode = tree->left;
    tree->left = newNode->right;
    newNode->right = tree;
    return newNode;
}

treeNode *insertNodeAVL(treeNode *tree, int value) // Incompleto
{
    if (tree == NULL)
    {
        treeNode *newNode = createNode(value);
    }
    if (tree->value > value)
    {
        tree->left = insertNodeAVL(tree->left, value);
    }
    if (tree->value < value)
    {
        tree->right = insertNodeAVL(tree->right, value);
    }
    else
    {
        printf("ERRO! Valor repetido.\n");
        return tree;
    }
    int bf = balanceFactor(tree);
    if (bf > 1)
    {
        value < tree->left->value;
        return rotateRight(tree);
    }
    else
    {
        tree->left = rotateLeft(tree->left);
        return rotateRight(tree);
    }
    if // teste ssaasa dfkaskldfa
}