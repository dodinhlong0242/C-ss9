#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void nhapMang(int arr[], int *currentLength) {
    printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", currentLength);
    if (*currentLength > MAX_SIZE || *currentLength < 0) {
        printf("So phan tu khong hop le.\n");
        *currentLength = 0;
        return;
    }
    printf("Nhap gia tri cac phan tu:\n");
    for (int i = 0; i < *currentLength; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int arr[], int currentLength) {
    printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void hienThiVaTongChan(int arr[], int currentLength) {
    int tong = 0;
    printf("Cac phan tu chan:\n");
    for (int i = 0; i < currentLength; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cac so chan: %d\n", tong);
}

void timMaxMin(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong.\n");
        return;
    }
    int max = arr[0], min = arr[0];
    for (int i = 1; i < currentLength; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);
}

void hienThiVaTongNguyenTo(int arr[], int currentLength) {
    int tong = 0;
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < currentLength; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cac so nguyen to: %d\n", tong);
}

void thongKeSoX(int arr[], int currentLength) {
    int x, dem = 0;
    printf("Nhap mot so de thong ke: ");
    scanf("%d", &x);
    for (int i = 0; i < currentLength; i++) {
        if (arr[i] == x) {
            dem++;
        }
    }
    printf("So lan xuat hien cua %d: %d\n", x, dem);
}

void themPhanTu(int arr[], int *currentLength) {
    if (*currentLength >= MAX_SIZE) {
        printf("Mang da day, khong the them.\n");
        return;
    }
    int addValue, addIndex;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &addValue);
    printf("Nhap vi tri muon them (0-%d): ", *currentLength);
    scanf("%d", &addIndex);
    if (addIndex < 0 || addIndex > *currentLength) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *currentLength; i > addIndex; i--) {
        arr[i] = arr[i - 1];
    }
    arr[addIndex] = addValue;
    (*currentLength)++;
}

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &currentLength);
                break;
            case 2:
                hienThiMang(arr, currentLength);
                break;
            case 3:
                hienThiVaTongChan(arr, currentLength);
                break;
            case 4:
                timMaxMin(arr, currentLength);
                break;
            case 5:
                hienThiVaTongNguyenTo(arr, currentLength);
                break;
            case 6:
                thongKeSoX(arr, currentLength);
                break;
            case 7:
                themPhanTu(arr, &currentLength);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}


