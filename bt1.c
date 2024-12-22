#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int numElements, addValue, addIndex;

    printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So phan tu khong hop le.\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    currentLength = numElements;

    printf("Nhap gia tri muon them: ");
    scanf("%d", &addValue);

    printf("Nhap vi tri muon them (0-%d): ", MAX_SIZE - 1);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex >= MAX_SIZE) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }
	if (addIndex >= currentLength) {
        arr[addIndex] = addValue;
        currentLength = addIndex + 1;
    } else {
        for (int i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[addIndex] = addValue;
        currentLength++;
    }

    printf("Mang sau khi them:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

