#include <stdio.h>
#include <stdlib.h>

int receiver(int winsize);
int simulate(int winsize);

int main() {
    int winsize = 8, totalFrames = 10, remainingFrames = totalFrames;

    printf("Number of frames = %d\n", totalFrames);

    while (remainingFrames > 0) {
        int sentFrames = simulate(winsize);
        printf("Sending frames: ");
        
        for (int i = 0; i < sentFrames; i++) {
            printf("%d ", totalFrames - remainingFrames + i + 1);
        }
        printf("\n");

        int ackFrames = receiver(sentFrames);
        printf("Acknowledgment received for frames: ");
        
        for (int i = 0; i < ackFrames; i++) {
            printf("%d ", i + 1);
        }
        printf("\n");

        remainingFrames -= ackFrames;
    }

    printf("End of sliding window protocol\n");
    return 0;
}

int receiver(int winsize) {
    return rand() % winsize;
}

int simulate(int winsize) {
    return rand() % winsize + 1;
}
