#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct Person {
    char* name;
    int age;
};

#define countof(x) (sizeof(x) / sizeof((x)[0]))

struct Person* GenArray(int numPeople) {
    struct Person* peopleArray = (struct Person*)malloc(numPeople * sizeof(struct Person));

    if (peopleArray == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }

    return peopleArray;
}

void FillArray(struct Person* person) {
    person->name = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    if (person->name == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Введите имя: ");
    scanf("%s", person->name);
    printf("Введите возраст: ");
    scanf("%d", &person->age);
}

void PrintArray(const struct Person* person) {
    printf("Имя: %s, Возраст: %d\n", person->name, person->age);
}

struct Person* A_Names(const struct Person* firstArr, int firstSize, int* secondSize) {
    int count = 0;

    for (int i = 0; i < firstSize; ++i) {
        if (firstArr[i].name[0] == 'A' || firstArr[i].name[0] == 'a') {
            count++;
        }
    }

    if (count == 0) {
        printf("Требуемые элементы не найдены.\n");
        *secondSize = 0;
        return NULL;
    }

    *secondSize = count;
    struct Person* secondArr = GenArray(count);

    int secondIndex = 0;
    for (int i = 0; i < firstSize; ++i) {
        if (firstArr[i].name[0] == 'A' || firstArr[i].name[0] == 'a') {
            secondArr[secondIndex].name = (char*)malloc(strlen(firstArr[i].name) + 1);
            if (secondArr[secondIndex].name == NULL) {
                fprintf(stderr, "Ошибка выделения памяти\n");
                exit(1);
            }

            strcpy(secondArr[secondIndex].name, firstArr[i].name);
            secondArr[secondIndex].age = firstArr[i].age;
            secondIndex++;
        }
    }

    return secondArr;
}

void FillStrings(char*** stringArray, int size) {
    *stringArray = (char**)malloc(size * sizeof(char*));

    if (*stringArray == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }

    // Очистить буфер ввода
    while (getchar() != '\n');

    for (int i = 0; i < size; ++i) {
        (*stringArray)[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));

        if ((*stringArray)[i] == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            exit(1);
        }

        printf("Введите строку %d: ", i + 1);
        fgets((*stringArray)[i], MAX_STRING_LENGTH, stdin);

        // Удалить символ новой строки, если он был считан
        size_t length = strlen((*stringArray)[i]);
        if (length > 0 && (*stringArray)[i][length - 1] == '\n') {
            (*stringArray)[i][length - 1] = '\0';
        }
    }
}

void PrintStrings(char** stringArray, int size) {
    printf("Массив строк:\n");
    for (int i = 0; i < size; ++i) {
        printf("%s\n", stringArray[i]);
    }
}

void DeleteEvenStrings(char*** stringArray, int* size) {
    if (*size == 0) {
        printf("Массив строк пуст.\n");
        return;
    }

    int count = 0;

    for (int i = 0; i < *size; ++i) {
        if (i % 2 != 0) {
            free((*stringArray)[i]);
        } else {
            (*stringArray)[count++] = (*stringArray)[i];
        }
    }

    *stringArray = realloc(*stringArray, count * sizeof(char*));

    if (*stringArray == NULL && count != 0) {
        fprintf(stderr, "Ошибка перераспределения памяти\n");
        exit(1);
    }

    *size = count;
}

int main() {
    int numPeople;
    printf("Введите количество людей: ");
    scanf("%i", &numPeople);

    struct Person* peopleArray = GenArray(numPeople);

    for (int i = 0; i < numPeople; ++i) {
        FillArray(&peopleArray[i]);
    }

    int secondSize;
    struct Person* secondArr = A_Names(peopleArray, numPeople, &secondSize);

    if (secondArr != NULL) {
        printf("Люди, имена которых начинаются с A: \n");
        for (int i = 0; i < secondSize; ++i) {
            PrintArray(&secondArr[i]);
        }

        // Освободить память для второго массива структур Person
        for (int i = 0; i < secondSize; ++i) {
            free(secondArr[i].name);
        }
        free(secondArr);
    }

    for (int i = 0; i < numPeople; ++i) {
        free(peopleArray[i].name);
    }
    free(peopleArray);

    int numStrings;
    printf("Введите количество строк: ");
    scanf("%d", &numStrings);
    char** stringArray;
    FillStrings(&stringArray, numStrings);
    PrintStrings(stringArray, numStrings);
    DeleteEvenStrings(&stringArray, &numStrings);
    PrintStrings(stringArray, numStrings);
    
    for (int i = 0; i < numStrings; ++i) {
        free(stringArray[i]);
    }
    free(stringArray);

    return 0;
}
