#include<stdio.h>

void first_fit(int block_size[], int m, int process_size[], int n) {
    int allocation[n], i, j;
    for (i = 0; i < n; i++)
        allocation[i] = -1;
        
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (block_size[j] >= process_size[i]) {
                allocation[i] = j;
                block_size[j] -= process_size[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, process_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int block_size[] = {100, 500, 200, 300, 600};
    int process_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(process_size)/sizeof(process_size[0]);

    first_fit(block_size, m, process_size, n);

    return 0 ;
}

