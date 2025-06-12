#include <stdio.h>
#include <string.h>

// cau truc sinh vien
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

// ham xoa sinh vien theo id
void xoaSinhVienTheoID(int id, struct Student students[], int *currentLength) {
    int found = 0;

    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            // dich cac phan tu sau ve truoc
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--; // giam so luong sinh vien
            printf("Da xoa sinh vien co id = %d\n", id);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co id = %d\n", id);
    }
}

int main() {
    struct Student students[50] = {
        {1, "Nguyen Van A", 20, "0901234567"},
        {2, "Le Thi B", 21, "0912345678"},
        {3, "Tran Van C", 22, "0923456789"},
        {4, "Pham Thi D", 23, "0934567890"},
        {5, "Hoang Van E", 24, "0945678901"}
    };

    int currentLength = 5;
    int idCanXoa;

    printf("Nhap id sinh vien can xoa: ");
    scanf("%d", &idCanXoa);

    // goi ham xoa
    xoaSinhVienTheoID(idCanXoa, students, &currentLength);

    // in danh sach sinh vien sau khi xoa
    printf("\nDanh sach sinh vien hien tai:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }

    return 0;
}

