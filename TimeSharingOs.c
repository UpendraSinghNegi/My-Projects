#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} cpu;
struct node *l = NULL, *r = NULL;

cpu *insert(cpu *start)
{
    int p;
    cpu *ptr = (cpu *)malloc(sizeof(cpu));
    if (ptr == NULL)
        printf("Too Much Processes!\n");

        printf("Enter Burst Time of Next Process: \n");
        scanf("%d", &p);
        ptr->data = p;
        if (start == NULL)
        {            
            r = ptr;            
        }
        ptr->next = start;
        start = ptr;
        l = start;
        r->next = l;    
    return start;
}

void scheduler(cpu *start)
{
    cpu *ptr = start;
    cpu *preptr;
    int ts, rt;
    printf("Enter the time Quant or Slot:\n");
    scanf("%d", &ts);
    do
    {
        while (ptr->next != start)
        {
            rt = ptr->data - ts;
            ptr->data = rt;
            printf("%d ", ptr->data);
            ptr = ptr->next;
            if (ptr->next->data == 0)
            {
                cpu *f = ptr;
                ptr = ptr->next;
                if (ptr->data == 0 && ptr->next->data == 0)
                {
                    while (ptr->next->data == 0)
                    {
                        preptr = ptr;
                        ptr = ptr->next;
                        free(preptr);
                    }
                    f->next = ptr;
                }
                else // (ptr->data == 0)
                {
                    preptr = f;
                    while (preptr->next->data == 0)
                    {
                        preptr = ptr;
                        ptr = ptr->next;
                    }
                    free(preptr);
                    f->next = ptr;
                }
            }
            if (ptr->next == start)
            {
                printf("%d ", ptr->data - ts);
                printf("\n");
                if (start->data == 0)
                {
                    cpu *temp = start;
                    while (start->data == 0)
                        start = start->next;
                    free(temp);
                    // ptr = ptr->next;
                    if (start == ptr)
                    {
                        while (ptr->data != 0)
                        {
                            rt = ptr->data - ts;
                            ptr->data = rt;
                            printf("%d ", ptr->data);
                        }
                        free(start);        
                        exit(0);
                    }
                }
                else // (start->data != 0)
                {
                    ptr = start;
                }
            }
        }        
    } while (start->data != 0);
    // return start;
}
   
int main()
{
    cpu *start = NULL;
    int c;

    do
    {
        printf("Enter the Choice: \n1 for Inserting processes: \n2 for Scheduling processes: \n0 to Exit!\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            scheduler(start);
            break;
        default:
            printf("Enter valid Entry next time!\n");
        }
    } while (c != 0);

    return 0;
}