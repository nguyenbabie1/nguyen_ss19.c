#include <stdio.h>
#include <string.h>

// cau truc sinh vien
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

// ham hoan doi 2 sinh vien
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// ham sap xep sinh vien theo ten
void sapXepTheoTen(struct Student students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            // so sanh ten
            if (strcmp(students[i].name, students[j].name) > 0) {
                swap(&students[i], &students[j]);
            }
        }
    }
}

int main() {
    struct Student students[5] = {
        {1, "Tran Van C", 22, "0901111111"},
        {2, "Nguyen Van A", 20, "0912222222"},
        {3, "Pham Thi D", 21, "0923333333"},
        {4, "Le Thi B", 23, "0934444444"},
        {5, "Hoang Van E", 24, "0945555555"}
    };

    int currentLength = 5;

    // goi ham sap xep
    sapXepTheoTen(students, currentLength);

    // in danh sach sau khi sap xep
    printf("Danh sach sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }

    return 0;
}

