#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NAME_LEN 21
#define COMMAND 20
#define INITIAL_CAPACITY 2

struct Record {
    int id;
    char name[NAME_LEN];
    int age;
};

struct Record *add_record(struct Record *database, int *record_count, int *max_capacity);
int add_record2(struct Record **db_tracker, size_t *record_count, size_t *max_capacity);
void view_records(struct Record *database, size_t record_count);

int main(void) {
    size_t record_count = 0;
    size_t max_capacity = INITIAL_CAPACITY;

    struct Record *database = malloc(max_capacity * sizeof(struct Record));
    if (database == NULL) {
        printf("Fatal Error: Initial memory allocation failed!\n");
        return 1;
    }

    char command[COMMAND];

    while (true) {
        printf("Commands: ADD, VIEW, EXIT\n");
        fgets(command, sizeof(command), stdin);

        // Strip the trailing newline captured by fgets
        command[strcspn(command, "\n")] = '\0';

        if (!strcmp(command, "EXIT")) {
            break;
        }

        if (!strcmp(command, "ADD")) {
            struct Record **db_tracker = &database;
            // database = add_record(database, &record_count, &max_capacity);
            add_record2(db_tracker, &record_count, &max_capacity);
            printf("Added to the database.\n\n");
        } else if (!strcmp(command, "VIEW")) {
            if (record_count == 0) {
                printf("Database is empty.\n\n");
                continue;
            }
            view_records(database, record_count);
        } else {
            printf("Wrong command, try again.\n\n");
        }
    }

    free(database);
    return 0;
}

int add_record2(struct Record **db_tracker, size_t *record_count, size_t *max_capacity) {
    if (*record_count == *max_capacity) {
        *max_capacity *= 2;

        // Allocate to a temp pointer first to prevent memory leak if realloc fails
        struct Record *temp = realloc(*db_tracker, *max_capacity * sizeof(struct Record));
        if (temp == NULL) {
            printf("Fatal Error: Out of memory!\n");
            free(*db_tracker);
            exit(1);
        }
        *db_tracker = temp;
    }

    while (true) {
        printf("Enter id: ");
        if (scanf("%d", &(*db_tracker)[*record_count].id)) {
            char ch;
            while ((ch = getchar()) != '\n')
                ;
            break;
        } else {
            printf("Invalid input. Id must be a number.\n");
            char ch;
            while ((ch = getchar()) != '\n')
                ;
        }
    }

    // Flush stdin buffer to prevent fgets from skipping on the next read

    printf("Enter name: ");
    char *name = (*db_tracker)[*record_count].name;
    fgets(name, 21, stdin);
    name[strcspn(name, "\n")] = '\0';

    while (true) {
        printf("Enter age: ");
        if (scanf("%d", &(*db_tracker)[*record_count].age)) {

            // Success: cleanup trailing \n and move on
            char ch;
            while ((ch = getchar()) != '\n')
                ;
            break;
        } else {
            printf("Invalid input. Age must be a number.\n");

            char ch;
            while ((ch = getchar()) != '\n')
                ;
        }
    }

    (*record_count)++;

    return 0;
}

void view_records(struct Record *database, size_t record_count) {
    for (struct Record *ptr = database; ptr != database + record_count; ptr++) {
        int diff = ptr - database;
        printf("%d) Id: %d\n   Name: %s\n   Age: %d\n\n", diff + 1, ptr->id, ptr->name, ptr->age);
    }
}
