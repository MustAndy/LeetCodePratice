#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode NODE;
void display(NODE *head)
{
    printf("\ninput number is：");
    NODE *p;
    for (p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("\n");
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{

    NODE *head, *pnew, *tail;
    int number;
    head = (NODE *)malloc(sizeof(NODE));
    if (head == NULL)
    {
        printf("fail\n");
        return NULL;
    }
    head->next = NULL;
    tail = head;
    int carry = 0;
    printf("calculating:\n");
    while (l1 != NULL || l2 != NULL || (l1 == NULL && l2 == NULL && carry == 1))
    {

        if (l1 == NULL && l2 == NULL && carry == 1)
            number = 1;
        else if (l2 == NULL)
            number = l1->val + carry;
        else if (l1 == NULL)
            number = l2->val + carry;
        else
            number = l1->val + l2->val + carry;
        printf("1\n");
        if (number >= 10)
        {
            carry = 1;
            number -= 10;
        }
        else
            carry = 0;
        printf("2\n");
        pnew = (NODE *)malloc(sizeof(NODE));
        if (pnew == NULL)
        {
            printf("fail\n");
            return NULL;
        }
        pnew->val = number;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
        printf("3\n");
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
        if (l1 == NULL && l2 == NULL && carry == 0)
            break;
        printf("4\n");
    }

    head = head->next;
    display(head);
    return head;
}

NODE *create()
{
    NODE *head, *pnew, *tail;
    int number;
    head = (NODE *)malloc(sizeof(NODE));
    if (head == NULL)
    {
        printf("fail\n");
        return NULL;
    }
    head->next = NULL;
    tail = head;
    printf("input number:");
    while (1)
    {
        scanf("%d", &number);
        if (number < 0)
            break;
        pnew = (NODE *)malloc(sizeof(NODE));
        if (pnew == NULL)
        {
            printf("fail\n");
            return NULL;
        }
        pnew->val = number;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    printf("return head;\n");
    // display(head);
    head = head->next;
    return head;
}

void allClear(NODE *head)
{
    NODE *p, *q;
    p = head;
    while (p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(head); //最后删除头节点
}

int main()
{
    NODE *l1, *l2, *l11, *l22, *result;
    l1 = create();
    l2 = create();

    result = addTwoNumbers(l1, l2);
    // result = result->next;
    // display(result);
    // allClear(l1);
    // allClear(l2);
    // allClear(result);
    return 0;
}
