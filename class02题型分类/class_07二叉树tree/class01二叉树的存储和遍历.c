#include <stdio.h>
#include <stdlib.h>

/*
                 A
                / \
               B   C
              / \   \
             D   E   F
                    /
                   G

*/


typedef struct Node
{
    char data;
    struct Node *Lchild;
    struct Node *Rchild;
} Node;

Node *
createNode(char data)
{
    Node *newNode = ( Node * )malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;

    return newNode;
}

void
insertNode(Node *parent, Node *Lchird, Node *Rchild)
{
    parent->Lchild = Lchird;
    parent->Rchild = Rchild;
}

// 遍历方式
void
preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preOrder(root->Lchild);
        preOrder(root->Rchild);
    }
}

void
midOrder(Node *root)
{
    if (root != NULL)
    {
        midOrder(root->Lchild);
        printf("%c ", root->data);
        midOrder(root->Rchild);
    }
}

void
lastOrder(Node *root)
{
    if (root != NULL)
    {
        lastOrder(root->Lchild);
        lastOrder(root->Rchild);
        printf("%c ", root->data);
    }
}

int
main()
{
    // 创建
    Node *A = createNode('A');
    Node *B = createNode('B');
    Node *C = createNode('C');
    Node *D = createNode('D');
    Node *E = createNode('E');
    Node *F = createNode('F');
    Node *G = createNode('G');

    // 连接
    insertNode(A, B, C);
    insertNode(B, D, E);
    insertNode(C, NULL, F);
    insertNode(F, G, NULL);


    printf("前序遍历: ");
    preOrder(A);
    printf("\n");

    printf("中序遍历: ");
    midOrder(A);
    printf("\n");

    printf("后序遍历: ");
    lastOrder(A);
    printf("\n");

    return 0;
}