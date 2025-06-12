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

// ham hien thi danh sach sinh vien
void hienThiDanhSach(struct Student students[], int length) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < length; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
}

// ham them sinh vien
void themSinhVien(struct Student students[], int *length, int *nextId) {
    if (*length >= 50) {
        printf("Danh sach day!\n");
        return;
    }

    printf("Nhap ten: ");
    getchar(); // xoa bo dem
    fgets(students[*length].name, sizeof(students[*length].name), stdin);
    students[*length].name[strcspn(students[*length].name, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &students[*length].age);

    printf("Nhap so dien thoai: ");
    scanf("%s", students[*length].phoneNumber);

    students[*length].id = (*nextId)++;
    (*length)++;

    printf("Them thanh cong!\n");
}

// ham sua thong tin sinh vien theo id
void suaSinhVien(struct Student students[], int length) {
    int id, found = 0;
    printf("Nhap id sinh vien can sua: ");
    scanf("%d", &id);

    for (int i = 0; i < length; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Nhap ten moi: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);

            printf("Sua thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien!\n");
    }
}

// ham xoa sinh vien theo id
void xoaSinhVien(struct Student students[], int *length) {
    int id, found = 0;
    printf("Nhap id sinh vien can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *length; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *length - 1; j++) {
                students[j] = students[j + 1];
            }
            (*length)--;
            printf("Da xoa sinh vien co id %d\n", id);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien!\n");
    }
}

// ham tim kiem sinh vien theo ten
void timKiemSinhVien(struct Student students[], int length) {
    char keyword[50];
    int found = 0;
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < length; i++) {
        if (strstr(students[i].name, keyword) != NULL) {
            printf("\nID: %d\n", students[i].id);
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("So dien thoai: %s\n", students[i].phoneNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien!\n");
    }
}

// ham sap xep sinh vien theo ten
void sapXepTheoTen(struct Student students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                swap(&students[i], &students[j]);
            }
        }
    }

    printf("Sap xep thanh cong!\n");
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
    int nextId = 6;
    int choice;

    do {
        printf("\n================ MENU ================\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hienThiDanhSach(students, currentLength);
                break;
            case 2:
                themSinhVien(students, &currentLength, &nextId);
                break;
            case 3:
                suaSinhVien(students, currentLength);
                break;
            case 4:
                xoaSinhVien(students, &currentLength);
                break;
            case 5:
                timKiemSinhVien(students, currentLength);
                break;
            case 6:
                sapXepTheoTen(students, currentLength);
                break;
            case 7:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

    } while (choice != 7);

    return 0;
}

