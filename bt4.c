#include <stdio.h>
#define MAX_SIZE 100

int nhapMang(int arr[]) {
    int numElements;
    printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So phan tu khong hop le.\n");
        return 0;
    }

    printf("Nhap %d phan tu:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    return numElements;
}

int hienThiMang(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong.\n");
        return 0;
    }

    printf("Mang hien tai:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1;
}

int themPhanTu(int arr[], int currentLength) {
    if (currentLength >= MAX_SIZE) {
        printf("Mang da day, khong the them.\n");
        return currentLength;
    }

    int addValue, addIndex;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &addValue);
    printf("Nhap vi tri muon them (0-%d): ", currentLength);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > currentLength) {
        printf("Vi tri khong hop le.\n");
        return currentLength;
    }

    for (int i = currentLength; i > addIndex; i--) {
        arr[i] = arr[i - 1];
    }
    arr[addIndex] = addValue;

    return currentLength + 1;
}

int suaPhanTu(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong, khong co gi de sua.\n");
        return 0;
    }

    int index, newValue;
    printf("Nhap vi tri can sua (0-%d): ", currentLength - 1);
    scanf("%d", &index);

    if (index < 0 || index >= currentLength) {
        printf("Vi tri khong hop le.\n");
        return 0;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[index] = newValue;
    return 1; // Thành công
}

int xoaPhanTu(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong, khong co gi de xoa.\n");
        return currentLength;
    }

    int deleteIndex;
    printf("Nhap vi tri can xoa (0-%d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vi tri khong hop le.\n");
        return currentLength;
    }

    for (int i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return currentLength - 1;
}

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                currentLength = nhapMang(arr);
                break;
            case 2:
                hienThiMang(arr, currentLength);
                break;
            case 3:
                currentLength = themPhanTu(arr, currentLength);
                break;
            case 4:
                if (!suaPhanTu(arr, currentLength)) {
                    printf("Khong sua duoc phan tu.\n");
                }
                break;
            case 5:
                currentLength = xoaPhanTu(arr, currentLength);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

