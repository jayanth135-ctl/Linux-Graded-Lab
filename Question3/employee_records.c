#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    int fd;
    struct Employee emp;

    fd = open("employee.dat", O_RDWR | O_CREAT, 0644);

    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    struct Employee e1 = {101, "Alice", 50000};
    struct Employee e2 = {102, "Bob", 60000};

    write(fd, &e1, sizeof(e1));
    write(fd, &e2, sizeof(e2));

    lseek(fd, sizeof(struct Employee), SEEK_SET);

    emp.id = 102;
    strcpy(emp.name, "Bob");
    emp.salary = 65000;

    write(fd, &emp, sizeof(emp));

    lseek(fd, 0, SEEK_SET);

    printf("Employee Records:\n");

    while (read(fd, &emp, sizeof(emp)) > 0) {
        printf("ID: %d Name: %s Salary: %.2f\n",
               emp.id, emp.name, emp.salary);
    }

    close(fd);

    return 0;
}
