#include <stdio.h>
#include <unistd.h> // for sleep()

int main() {
    printf("Loading: [      ]");
    fflush(stdout); // Force print
    sleep(1);

    // \r moves cursor back to start. We do NOT use \n.
    // We overwrite "Loading: [      ]" with "Loading: [==    ]"
    printf("\rLoading: [==    ]");
    fflush(stdout);
    sleep(1);

    printf("\rLoading: [====  ]");
    fflush(stdout);
    sleep(1);

    printf("\rLoading: [======]\n"); // Finally use \n to finish
    return 0;
}
