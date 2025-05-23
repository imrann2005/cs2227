#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insertLinearProbing(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % TABLE_SIZE] != -1 && i < TABLE_SIZE)
        i++;

    if (i < TABLE_SIZE)
        hashTable[(index + i) % TABLE_SIZE] = key;
    else
        printf("Hash table is full\n");
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("%d ", hashTable[i]);
    printf("\n");
}

int main() {
    init();
    insertLinearProbing(23);
    insertLinearProbing(43);
    insertLinearProbing(13);
    insertLinearProbing(27);
    display();
    return 0;
}
