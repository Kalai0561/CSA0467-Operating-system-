#include <stdio.h>

struct record {
    char empname[20];
    int id;
    float salary;
};

typedef struct record person;

int main() {
    person employee;
    int i, n;
    FILE *fp;
	char file[1000];
    printf("How many records: ");
    scanf("%d", &n);
    printf("Enter the file name with path : ");
    scanf("%s",&file);

    fp = fopen(file, "w");

    for (i = 0; i < n; i++) {
        printf("Enter the employee information %d (EmpName, id, Salary): ", i + 1);
        scanf("%s%d%f", employee.empname, &employee.id, &employee.salary);
        fprintf(fp, "%s %d %.2f\n", employee.empname, employee.id, employee.salary);
    }

    fclose(fp);

    printf("Data written to file successfully.\n");

    return 0;
}

