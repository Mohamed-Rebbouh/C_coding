#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Structure for a linked list node
struct Node {
    char key[50];
    int value;
    struct Node* next;
};

// Structure for the hash table
struct HashTable {
    struct Node* array[SIZE];
};

// Function to create a new node
struct Node* createNode(char* key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < SIZE; ++i) {
        hashTable->array[i] = NULL;
    }
    return hashTable;
}

// Function to compute hash value
int hash(char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        hash = (hash + key[i]) % SIZE;
    }
    return hash;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* hashTable, char* key, int value) {
    int index = hash(key);
    struct Node* newNode = createNode(key, value);
    if (hashTable->array[index] == NULL) {
        hashTable->array[index] = newNode;
    } else {
        struct Node* temp = hashTable->array[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a key in the hash table
int search(struct HashTable* hashTable, char* key) {
    int index = hash(key);
    struct Node* temp = hashTable->array[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

int main() {
    struct HashTable* hashTable = createHashTable();

    // Insert some key-value pairs
    insert(hashTable, "j", 25);
    insert(hashTable, "e", 30);
    insert(hashTable, "a", 20);
    insert(hashTable, "b", 35);

    // Search for a key
    printf("Value for key 'j': %d\n", search(hashTable, "j"));
    printf("Value for key 'a': %d\n", search(hashTable, "a"));
    printf("Value for key 'A': %d\n", search(hashTable, "A"));

    return 0;
}
