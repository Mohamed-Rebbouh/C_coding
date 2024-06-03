#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

struct DynamicArray {
    int *array;
    int size;
    int capacity;
};

// Function to create a new dynamic array
struct DynamicArray* createDynamicArray() {
    struct DynamicArray* dynamicArray = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
    dynamicArray->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    dynamicArray->size = 0;
    dynamicArray->capacity = INITIAL_CAPACITY;
    return dynamicArray;
}

// Function to resize the dynamic array
void resize(struct DynamicArray* dynamicArray) {
    dynamicArray->capacity *= 2;
    dynamicArray->array = (int*)realloc(dynamicArray->array, dynamicArray->capacity * sizeof(int));
}

// Function to insert an element at the end of the dynamic array
void insert(struct DynamicArray* dynamicArray, int element) {
    if (dynamicArray->size == dynamicArray->capacity) {
        resize(dynamicArray);
    }
    dynamicArray->array[dynamicArray->size++] = element;
}

// Function to delete an element at a given index from the dynamic array
void delete(struct DynamicArray* dynamicArray, int index) {
    if (index < 0 || index >= dynamicArray->size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < dynamicArray->size - 1; ++i) {
        dynamicArray->array[i] = dynamicArray->array[i + 1];
    }
    dynamicArray->size--;
}

// Function to search for an element in the dynamic array
int search(struct DynamicArray* dynamicArray, int element) {
    for (int i = 0; i < dynamicArray->size; ++i) {
        if (dynamicArray->array[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to print the elements of the dynamic array
void printDynamicArray(struct DynamicArray* dynamicArray) {
    printf("Dynamic Array: ");
    for (int i = 0; i < dynamicArray->size; ++i) {
        printf("%d ", dynamicArray->array[i]);
    }
    printf("\n");
}

int main() {
    struct DynamicArray* dynamicArray = createDynamicArray();

    // Insert elements into the dynamic array
    insert(dynamicArray, 10);
    insert(dynamicArray, 20);
    insert(dynamicArray, 30);
    insert(dynamicArray, 40);
    insert(dynamicArray, 50);

    // Print the dynamic array
    printDynamicArray(dynamicArray);

    // Delete an element at index 2
    delete(dynamicArray, 2);

    // Print the dynamic array after deletion
    printDynamicArray(dynamicArray);

    // Search for an element
    int element = 40;
    int index = search(dynamicArray, element);
    if (index != -1) {
        printf("%d found at index %d\n", element, index);
    } else {
        printf("%d not found in the dynamic array\n", element);
    }

    // Free the memory allocated for the dynamic array
    free(dynamicArray->array);
    free(dynamicArray);

    return 0;
}
