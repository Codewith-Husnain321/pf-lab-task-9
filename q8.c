#include <stdio.h>
#include <string.h>

#define FILENAME "library.txt"

void addBook() {
    FILE *fp = fopen(FILENAME, "a");
    if (!fp) {
        printf("Error opening %s.\n", FILENAME);
        return;
    }

    int id;
    char title[60], author[60];

    printf("Enter Book ID, Title (no spaces), Author (no spaces): ");
    scanf("%d %59s %59s", &id, title, author);

    fprintf(fp, "%d %s %s\n", id, title, author);
    fclose(fp);
    printf("Book record added.\n");
}

void displayBooks() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No library file found.\n");
        return;
    }

    int id;
    char title[60], author[60];
    printf("\n--- Library Books ---\n");
    while (fscanf(fp, "%d %59s %59s", &id, title, author) == 3) {
        printf("ID: %d | Title: %s | Author: %s\n", id, title, author);
    }
    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No library file found.\n");
        return;
    }

    int targetId, id, found = 0;
    char title[60], author[60];

    printf("Enter Book ID to search: ");
    scanf("%d", &targetId);

    while (fscanf(fp, "%d %59s %59s", &id, title, author) == 3) {
        if (id == targetId) {
            printf("Book Found -> ID: %d | Title: %s | Author: %s\n", id, title, author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", targetId);
    }

    fclose(fp);
}

void deleteFile() {
    if (remove(FILENAME) == 0) {
        printf("%s deleted successfully.\n", FILENAME);
    } else {
        printf("Unable to delete %s.\n", FILENAME);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Book\n2. Display All Books\n3. Search Book by ID\n4. Delete File\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteFile(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}