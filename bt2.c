#include <stdio.h>
#define SIZE 10

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index, newValue, i;

    printf("Mang hien tai:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap vi tri can sua (0-%d): ", SIZE - 1);
    scanf("%d", &index);

    if (index < 0 || index >= SIZE) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[index] = newValue;

    printf("Mang sau khi sua:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

