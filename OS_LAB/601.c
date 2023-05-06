#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int values[10] = {7, 8, 3, 9, 1, 3, 2, 0, 7, 7};

struct thread_args
{
    int *start;
    int *end;
};

void *sort(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *start = args->start;
    int *end = args->end;
    for (int *i = start; i < end; i++)
    {
        for (int *j = i + 1; j < end; j++)
        {
            if (*i > *j)
            {
                int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    pthread_exit(NULL);
}
void *merge_sort(void *arg)
{
    int *start1 = values;
    int *end1 = values + 5;
    int *start2 = end1;
    int *end2 = values + 10;
    int *result = (int *)malloc(sizeof(int) * 10);
    int *p = result;
    while (start1 < end1 && start2 < end2)
    {
        if (*start1 < *start2)
        {
            *p++ = *start1++;
        }
        else
        {
            *p++ = *start2++;
        }
    }
    while (start1 < end1)
    {
        *p++ = *start1++;
    }
    while (start2 < end2)
    {
        *p++ = *start2++;
    }
    for (int i = 0; i < 10; i++)
    {
        values[i] = result[i];
    }
    free(result);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    struct thread_args args1 = {values, values + 5};
    struct thread_args args2 = {values + 5, values + 10};
    pthread_create(&thread1, NULL, sort, &args1);
    pthread_create(&thread2, NULL, sort, &args2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_create(&thread3, NULL, merge_sort, NULL);
    pthread_join(thread3, NULL);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", values[i]);
    }
    return 0;
}