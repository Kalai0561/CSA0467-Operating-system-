#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, seek_time = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    int max_range = 199;
    int min_range = 0;
    int direction = 1; // 1 for up, 0 for down
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            for (j = i; j < n; j++) {
                if (requests[j] > max_range) {
                    continue;
                }
                seek_time += abs(head - requests[j]);
                head = requests[j];
            }
            direction = 0;
            i = -1;
        } else if (requests[i] < head) {
            for (j = i; j >= 0; j--) {
                if (requests[j] < min_range) {
                    continue;
                }
                seek_time += abs(head - requests[j]);
                head = requests[j];
            }
            direction = 1;
            i = -1;
        }
    }
    printf("Total seek time: %d\n", seek_time);

    return 0;
}

