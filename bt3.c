#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int numElements, deleteIndex, i;

    printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So phan tu khong hop le.\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", numElements);
    for (i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    currentLength = numElements;

    printf("Nhap vi tri can xoa (0-%d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }

    for (i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    currentLength--;

    printf("Mang sau khi xoa:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
