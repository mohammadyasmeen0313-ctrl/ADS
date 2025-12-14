#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    int newIndex;

    while (i < SIZE) {
        newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }

    printf("Hash Table full! Cannot insert %d\n", key);
}

void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    int keys[] = {23, 43, 13, 27, 39, 14};
    int n = 6, i;

    init();
    for (i = 0; i < n; i++) {
        insert(keys[i]);
    }

    display();
    return 0;
}

