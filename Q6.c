#include <stdio.h>

struct Salary {
    float basicPay;
    float bonus;
    float deduction;
};

struct Employee {
    int id;
    char name[50];
    struct Salary salary;
};

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

float calculateNetSalary(struct Employee e) {
    return e.salary.basicPay + e.salary.bonus - e.salary.deduction;
}

void displayEmployee(struct Employee e) {
    printf("\nEmployee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Basic Pay: %.2f\n", e.salary.basicPay);
    printf("Bonus: %.2f\n", e.salary.bonus);
    printf("Deduction: %.2f\n", e.salary.deduction);
    printf("Net Salary: %.2f\n", calculateNetSalary(e));
}

void addEmployee(struct Employee emp[], int *count) {
    char temp[100];

    printf("Enter Employee ID: ");
    scanf("%d", &emp[*count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", temp);
    copyString(emp[*count].name, temp);

    printf("Enter Basic Pay: ");
    scanf("%f", &emp[*count].salary.basicPay);

    printf("Enter Bonus: ");
    scanf("%f", &emp[*count].salary.bonus);

    printf("Enter Deduction: ");
    scanf("%f", &emp[*count].salary.deduction);

    (*count)++;
    printf("Employee Added Successfully!\n");
}

int main() {
    struct Employee emp[100];
    int count = 0;
    int i, choice;

    while (1) {
        printf("\n--- Payroll System Menu ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addEmployee(emp, &count);
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("No employees to display.\n");
            } else {
                for ( i = 0; i < count; i++) {
                    displayEmployee(emp[i]);
                }
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

