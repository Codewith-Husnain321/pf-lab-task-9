#include <stdio.h>

#define FILENAME "employees.dat"

struct Employee {
    int id;
    char name[50];
    float salary;
};

void storeEmployees() {
    int count;
    do {
        printf("Enter number of employees to store (at least 5): ");
        scanf("%d", &count);
    } while (count < 5);

    FILE *fp = fopen(FILENAME, "wb");
    if (!fp) {
        printf("Error creating %s.\n", FILENAME);
        return;
    }

    for (int i = 0; i < count; i++) {
        struct Employee emp;
        printf("Employee %d - Enter ID, Name, Monthly Salary: ", i + 1);
        scanf("%d %49s %f", &emp.id, emp.name, &emp.salary);
        fwrite(&emp, sizeof(struct Employee), 1, fp);
    }

    fclose(fp);
    printf("Stored %d employee records in %s.\n", count, FILENAME);
}

void displayAndTotalSalary() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("Error opening %s.\n", FILENAME);
        return;
    }

    struct Employee emp;
    float totalSalary = 0.0f;

    printf("\n--- Employee Records ---\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("ID: %d | Name: %s | Monthly Salary: %.2f\n", emp.id, emp.name, emp.salary);
        totalSalary += emp.salary;
    }

    printf("Total Monthly Salary Paid: %.2f\n", totalSalary);
    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("Error opening %s.\n", FILENAME);
        return;
    }

    int targetId, found = 0;
    struct Employee emp;

    printf("Enter Employee ID to search: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.id == targetId) {
            printf("Employee Found -> ID: %d | Name: %s | Monthly Salary: %.2f\n",
                   emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }

    fclose(fp);
}

void deleteBinaryFile() {
    if (remove(FILENAME) == 0) {
        printf("%s deleted successfully.\n", FILENAME);
    } else {
        printf("Unable to delete %s.\n", FILENAME);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Store Employees (min 5)\n2. Display All & Total Salary\n3. Search by ID\n4. Delete Binary File\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: storeEmployees(); break;
            case 2: displayAndTotalSalary(); break;
            case 3: searchEmployee(); break;
            case 4: deleteBinaryFile(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}