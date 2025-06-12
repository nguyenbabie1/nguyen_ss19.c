#include <stdio.h>
#include <string.h>

// cau truc sinh vien gom id tu dong name age va phoneNumber
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student students[50];
    int i;

    printf("Nhap thong tin cho 5 sinh vien\n");

    for (i = 0; i < 5; i++) {
        students[i].id = i + 1; // gan id tu dong bat dau tu 1

        printf("\nSinh vien thu %d\n", i + 1);

        printf("Nhap ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);
        getchar(); // xoa ky tu xuong dong con lai

        printf("Nhap so dien thoai: ");
        fgets(students[i].phoneNumber, sizeof(students[i].phoneNumber), stdin);
    }

    printf("\nDanh sach sinh vien da nhap\n");

    for (i = 0; i < 5; i++) {
        printf("\nSinh vien thu %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s", students[i].phoneNumber);
    }

    return 0;
}
ds
 
