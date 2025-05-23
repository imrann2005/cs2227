#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);  // 7 is a prime < TABLE_SIZE
}

void insertDoubleHashing(int key) {
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;

    while (hashTable[(index + i * step) % TABLE_SIZE] != -1 && i < TABLE_SIZE)
        i++;

    if (i < TABLE_SIZE)
        hashTable[(index + i * step) % TABLE_SIZE] = key;
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
    insertDoubleHashing(23);
    insertDoubleHashing(43);
    insertDoubleHashing(13);
    insertDoubleHashing(27);
    display();
    return 0;
}
