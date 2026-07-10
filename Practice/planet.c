// Name: planet.c
// Purpose: To check whether the given command line args are planets or not.
// Author: Ayush Raj

#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[]) {
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    for (int i = 1; i < argc; i++) {
        int j;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (strcmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d.\n", argv[i], j);
            }
        }
        if (j == NUM_PLANETS) {
            printf("%s is not a planet.\n", argv[i]);
        }
    }

    return 0;
}
