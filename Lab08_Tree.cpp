#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 200
typedef int ElemType;
//��������
//�������ڵ�
typedef struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightSibling;
} Node, *Tree;

//���򴴽���
int CreateForest(Tree *T)
{
    ElemType ch;
    ElemType temp;
    scanf("%d", &ch);
    temp = getchar();
    if (ch == -1)
        *T = NULL;
    else
    {
        *T = (Tree)malloc(sizeof(Node));
        if (!(*T))
            exit(-1);
        (*T)->data = ch;
        printf("����%d������:", ch);
        CreateForest(&(*T)->leftChild);
        printf("����%d���ֵ�:", ch);
        CreateForest(&(*T)->rightSibling);
    }
    return 1;
}
//�ȸ�����ɭ��
void TraverseForest(Tree T)
{
    if (T == NULL)
        return;
    printf("%d ", T->data);
    TraverseForest(T->leftChild);
    TraverseForest(T->rightSibling);
}
//�������ɭ��
void PostOrderForest(Tree T)
{
    if (T == NULL)
        return;
    //������������
    PostOrderForest(T->leftChild);
    PostOrderForest(T->rightSibling);
    printf("%d ", T->data);
}

// �����ú����ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽ��ĸ���
// �ݹ��˼·:����޺�����ý���ΪҶ�ӽ��
int CountLeaves(Tree root)
{
    if (!root) // �����Ϊ���򷵻�0
    {
        return 0;
    }
    else
    {
        //������������
        if (root->leftChild == NULL)
            return 1 + CountLeaves(root->leftChild) + CountLeaves(root->rightSibling);
        else
            return CountLeaves(root->leftChild) + CountLeaves(root->rightSibling);
    }
}

int height(Tree root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        //������������
        if (root->leftChild != NULL)
        {
            return height(root->leftChild) >= height(root->rightSibling)
                       ? height(root->leftChild) + 1
                       : height(root->rightSibling) + 1;
        }
        else
            return height(root->leftChild) >= height(root->rightSibling)
                       ? height(root->leftChild)
                       : height(root->rightSibling);
    }
}

//������
int main(void)
{
    Tree T;

    int deepth, num = 0;
    printf("�������һ������ֵ,-1��ʾû�ж�Ӧ����:\n");
    CreateForest(&T);
    printf("�������ɭ��:\n");
    TraverseForest(T);
    printf("\n");
    printf("�������ɭ��:\n");
    PostOrderForest(T);
    printf("\n");

    num = CountLeaves(T);
    printf("ɭ�ֵ�Ҷ�ӽ�����Ϊ:%d", num);
    printf("\n");

    deepth = height(T);
    printf("ɭ�ֵĸ߶�Ϊ:%d", deepth);
    printf("\n");

    return 0;
}