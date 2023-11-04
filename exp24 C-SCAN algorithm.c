#include<stdio.h>
#include<stdlib.h>

int main()
{
    int queue[20], head, q_size, i, j, seek = 0, max, diff, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float avg_seek_time;
    printf("Enter the size of Queue: ");
    scanf("%d", &q_size);
    printf("Enter the Queue: ");
    for(i = 1; i <= q_size; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    queue[0] = head;
    for(i = 0; i <= q_size; i++)
    {
        for(j = i + 1; j <= q_size; j++)
        {
            if(queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    max = queue[q_size];
    for(i = 0; i <= q_size; i++)
    {
        if(queue[i] == head)
        {
            j = i;
            break;
        }
    }
    for(i = j; i >= 1; i--)
    {
        queue1[temp1] = queue[i];
        temp1++;
    }
    queue1[temp1] = 0;
    for(i = j + 1; i <= q_size; i++)
    {
        queue2[temp2] = queue[i];
        temp2++;
    }
    queue2[temp2] = max;
    for(i = 0; i <= temp1 - 1; i++)
    {
        seek += abs(queue1[i] - queue1[i - 1]);
    }
    seek += abs(queue1[temp1 - 1] - 0);
    for(i = 0; i <= temp2; i++)
    {
        seek += abs(queue2[i] - queue1[temp1 - 1]);
        temp1++;
    }
    avg_seek_time = seek / (float)q_size;
    printf("\nTotal Seek Time: %d\n", seek);
    printf("Average Seek Time: %f\n", avg_seek_time);
    return 0;
}

