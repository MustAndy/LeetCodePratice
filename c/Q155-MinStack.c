
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int val;
    struct StackNode *next;
} StackNode;

typedef struct MinStack
{
    int size;
    StackNode *top;
    StackNode *min;

} MinStack;

/** initialize your data structure here. */
MinStack *minStackCreate(int maxSize)
{
    MinStack *new_stack = (MinStack *)calloc(1, sizeof(MinStack));
    new_stack->min = NULL;
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

void minStackPush(MinStack *obj, int x)
{
    StackNode *new_node = (StackNode *)calloc(1, sizeof(StackNode));
    new_node->val = x;
    new_node->next = obj->top;
    obj->top = new_node;
    obj->size += 1;

    StackNode *min_node = (StackNode *)calloc(1, sizeof(StackNode));
    min_node->val = x;
    min_node->next = obj->min;
    if (obj->min)
    {
        if (obj->min->val >= x)
        {
            obj->min = min_node;
        }
    }
    else
        obj->min = min_node;
}

void minStackPop(MinStack *obj)
{
    StackNode *t, *m;
    t = obj->top;
    m = obj->min;
    if (m->val == t->val)
    {
        obj->min = obj->min->next;
        free(m);
    }
    obj->top = obj->top->next;
    obj->size--;
    free(t);
}

int minStackTop(MinStack *obj)
{
    return obj->top->val;
}

int minStackGetMin(MinStack *obj)
{
    //if (obj->min)
    return obj->min->val;
    // else
    //     return 0;
}

void minStackFree(MinStack *obj)
{
    while (obj->size != 0)
    {
        minStackPop(obj);
    }
    while (obj->min != NULL)
    {
        StackNode *m = obj->min;
        obj->min = obj->min->next;
        free(m);
    }
}
int main()
{
    struct MinStack *obj = minStackCreate(10);
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    int param_4 = minStackGetMin(obj);

    minStackPop(obj);
    int param_3 = minStackTop(obj);
    int param_2 = minStackGetMin(obj);

    minStackFree(obj);
    return 0;
}