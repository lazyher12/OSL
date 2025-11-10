#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, head, min, diff, seekTime = 0, count = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n], completed[n];
    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        completed[i] = 0;  // initially none are served
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\n--- SSTF Disk Scheduling ---\n");
    printf("Seek Sequence: %d", head);

    while (count < n) {
        min = 10000;
        int index = -1;

        // Find the request closest to current head
        for (i = 0; i < n; i++) {
            if (!completed[i]) {
                diff = abs(head - requests[i]);
                if (diff < min) {
                    min = diff;
                    index = i;
                }
            }
        }

        // Move head to that request
        seekTime += min;
        head = requests[index];
        completed[index] = 1;
        count++;

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d", seekTime);
    printf("\nAverage Seek Time: %.2f\n", (float)seekTime / n);

    return 0;
}
