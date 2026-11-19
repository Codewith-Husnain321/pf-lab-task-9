#include <stdio.h>
#include <string.h>

#define FILENAME "attendance.txt"

void addRecords() {
    FILE *fp = fopen(FILENAME, "a");
    if (!fp) {
        printf("Error opening %s for appending.\n", FILENAME);
        return;
    }

    int count;
    printf("How many student records do you want to add? ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int roll;
        char name[50], status[15];

        printf("Enter Roll Number, Name, Status (Present/Absent): ");
        scanf("%d %49s %14s", &roll, name, status);
        fprintf(fp, "%d %s %s\n", roll, name, status);
    }

    fclose(fp);
    printf("Records saved to %s.\n", FILENAME);
}

void displayRecords() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No attendance records found (%s does not exist).\n", FILENAME);
        return;
    }

    int roll;
    char name[50], status[15];
    printf("\n--- Attendance Records ---\n");
    while (fscanf(fp, "%d %49s %14s", &roll, name, status) == 3) {
        printf("Roll: %d | Name: %s | Status: %s\n", roll, name, status);
    }

    fclose(fp);
}

void deleteFile() {
    if (remove(FILENAME) == 0) {
        printf("%s deleted successfully.\n", FILENAME);
    } else {
        printf("Unable to delete %s (file may not exist).\n", FILENAME);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Attendance Records\n2. Display All Records\n3. Delete Attendance File\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecords(); break;
            case 2: displayRecords(); break;
            case 3: deleteFile(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}