#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student sv;

    // Gan gia tri
    strcpy(sv.name, "Nguyen Van A");
    sv.age = 20;
    strcpy(sv.phoneNumber, "0123456789");
    // In gia tri 
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("So dien thoai: %s\n", sv.phoneNumber);

    return 0;
}
 
