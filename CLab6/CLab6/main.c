#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

struct Person {
    char* name;
    int age;
};

#define countof(x) (sizeof(x) / sizeof((x)[0]))

struct Person* GenArray(int numPeople) {
    struct Person* peopleArray = (struct Person*)malloc(numPeople * sizeof(struct Person));

    if (peopleArray == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    return peopleArray;
}

void FillArray(struct Person* person) {
    person->name = (char*)malloc(50 * sizeof(char));
    if (person->name == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    printf("Enter name: ");
    scanf_s("%49s", person->name, 50);  // Updated to prevent buffer overflow
    printf("Enter age: ");
    scanf_s("%d", &person->age);
}

void PrintArray(const struct Person* person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

struct Person* A_Names(const struct Person* firstArr, int firstSize, int* secondSize) {
    int count = 0;

    for (int i = 0; i < firstSize; ++i) {
        if (firstArr[i].name[0] == 'A' || firstArr[i].name[0] == 'a') {
            count++;
        }
    }

    *secondSize = count;
    struct Person* secondArr = GenArray(count);

    int secondIndex = 0;
    for (int i = 0; i < firstSize; ++i) {
        if (firstArr[i].name[0] == 'A' || firstArr[i].name[0] == 'a') {
            secondArr[secondIndex++] = firstArr[i];
        }
    }

    return secondArr;
}

void FillStrings(char*** stringArray, int size) {
    *stringArray = (char**)malloc(size * sizeof(char*));

    if (*stringArray == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        (*stringArray)[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));

        if ((*stringArray)[i] == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }

        printf("Enter string %d: ", i + 1);
        scanf_s("%s", (*stringArray)[i], MAX_STRING_LENGTH);
    }
}

void PrintStrings(char** stringArray, int size) {
    printf("String Array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%s\n", stringArray[i]);
    }
}

void DeleteStrings(char*** stringArray, int* size) {
    int count = 0;

    // Count the number of odd strings
    for (int i = 0; i < *size; ++i) {
        if (i % 2 != 0) {
            free((*stringArray)[i]);
        }
        else {
            (*stringArray)[count++] = (*stringArray)[i];
        }
    }

    // Resize the array to the new count of odd strings
    *stringArray = realloc(*stringArray, count * sizeof(char*));

    if (*stringArray == NULL && count != 0) {
        fprintf(stderr, "Memory reallocation error\n");
        exit(1);
    }

    *size = count;
}

int main() {
    int numPeople;
    printf("Enter the number of people: ");
    scanf_s("%i", &numPeople);

    struct Person* peopleArray = GenArray(numPeople);

    for (int i = 0; i < numPeople; ++i) {
        FillArray(&peopleArray[i]);
    }

    int secondSize;
    struct Person* secondArr = A_Names(peopleArray, numPeople, &secondSize);

    printf("People whose names begin with A: \n");
    for (int i = 0; i < secondSize; ++i) {
        PrintArray(&secondArr[i]);
    }

    // Free memory for Person array
    for (int i = 0; i < numPeople; ++i) {
        free(peopleArray[i].name);
    }
    free(peopleArray);

    // Free memory for A_Names result array
    for (int i = 0; i < secondSize; ++i) {
        free(secondArr[i].name);
    }
    free(secondArr);

    // Additional steps
    int numStrings;
    printf("Enter the number of strings: ");
    scanf_s("%d", &numStrings);

    char** stringArray;

    // Step 5: Form the dynamic string array and perform input
    FillStrings(&stringArray, numStrings);

    // Step 6: Print the formed array
    PrintStrings(stringArray, numStrings);

    // Step 7: Delete even strings from the array
    DeleteStrings(&stringArray, &numStrings);

    // Step 8: Print the resulting array
    PrintStrings(stringArray, numStrings);

    // Step 9: Free allocated memory for string array
    for (int i = 0; i < numStrings; ++i) {
        free(stringArray[i]);
    }
    free(stringArray);

    return 0;
}
