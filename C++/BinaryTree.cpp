#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class BinaryTree
{
public:
    void Insert(PPNODE first, int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->lchild = NULL;
        newn->rchild = NULL;

        if (*first == NULL)
        {
            *first = newn;
            return;
        }
        else
        {
            temp = *first;

            while (1)
            {
                if (no == temp->data)
                {
                    cout << "Duplicate element: Unable to insert node" << endl;
                    free(newn);
                    break;
                }
                else if (no > temp->data) // rchild
                {
                    if (temp->rchild == NULL)
                    {
                        temp->rchild = newn;
                        break;
                    }
                    temp = temp->rchild;
                }
                else if (no < temp->data) // lchild
                {
                    if (temp->lchild == NULL)
                    {
                        temp->lchild = newn;
                        break;
                    }

                    temp = temp->lchild;
                }
            }
        }
    }

    void Inorder(PNODE first)
    {
        if (first != NULL)
        {

            Inorder(first->lchild);
            printf("%d\t", first->data);
            Inorder(first->rchild);
        }
    }

    void Preorder(PNODE first)
    {
        if (first != NULL)
        {
            printf("%d\t", first->data);
            Preorder(first->lchild);
            Preorder(first->rchild);
        }
    }

    void Postorder(PNODE first)
    {
        if (first != NULL)
        {
            Postorder(first->lchild);
            Postorder(first->rchild);
            printf("%d\t", first->data);
        }
    }
};

int main()
{
    PNODE head = NULL;

    BinaryTree bobj;

    bobj.Insert(&head, 11);
    bobj.Insert(&head, 9);
    bobj.Insert(&head, 17);

    printf("\nPreorder data is: \n");
    bobj.Preorder(head);

    printf("\nInorder data is: \n");
    bobj.Inorder(head);

    printf("\nPostorder data is: \n");
    bobj.Postorder(head);

    return 0;
}
