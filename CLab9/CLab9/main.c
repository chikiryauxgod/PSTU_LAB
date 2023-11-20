#include <stdio.h>

struct Owner {
    char name[100];
    char carNumber[20];
    char phoneNumber[20];
    char techNumber[20];
};

void Input(FILE* file, int n) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    while ((getchar()) != '\n');

    for (int i = 0; i < n; i++) {
        struct Owner owner;

        printf("\nВведите имя в формате 'Фамилия Имя Отчество': ");
        fgets(owner.name, sizeof(owner.name), stdin);
        owner.name[strcspn(owner.name, "\n")] = '\0';

        printf("Введите номер автомобиля: ");
        fgets(owner.carNumber, sizeof(owner.carNumber), stdin);
        owner.carNumber[strcspn(owner.carNumber, "\n")] = '\0';

        printf("Введите номер телефона владельца: ");
        fgets(owner.phoneNumber, sizeof(owner.phoneNumber), stdin);
        owner.phoneNumber[strcspn(owner.phoneNumber, "\n")] = '\0';

        printf("Введите номер техпаспорта автомобиля: ");
        fgets(owner.techNumber, sizeof(owner.techNumber), stdin);
        owner.techNumber[strcspn(owner.techNumber, "\n")] = '\0';

        fprintf(file, "%s\n%s\n%s\n%s\n", owner.name, owner.carNumber, owner.phoneNumber, owner.techNumber);
    }
}

void Delete(FILE* file, int elementDel) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* tempFile;
    if (fopen_s(&tempFile, "temp.txt", "w+") != 0) {
        printf("Не удалось открыть временный файл.\n");
        return;
    }

    struct Owner owner;
    int nowElement = 0;

    fseek(file, 0, SEEK_SET);

    while (fgets(owner.name, sizeof(owner.name), file) != NULL) {
        fgets(owner.carNumber, sizeof(owner.carNumber), file);
        fgets(owner.phoneNumber, sizeof(owner.phoneNumber), file);
        fgets(owner.techNumber, sizeof(owner.techNumber), file);

        nowElement++;

        if (nowElement != elementDel) {
            fprintf(tempFile, "%s%s%s%s", owner.name, owner.carNumber, owner.phoneNumber, owner.techNumber);
        }
    }

    fclose(tempFile);
    fclose(file);

    remove("programm.txt");

    if (rename("temp.txt", "programm.txt") != 0) {
        printf("Не удалось переименовать временный файл.\n");
        return;
    }
}


void AddElements(FILE* file, int n, int k) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while ((getchar()) != '\n');

    fseek(file, (k - 1) * sizeof(struct Owner), SEEK_SET);

    for (int i = 0; i < n; i++) {
        struct Owner owner;

        printf("\nВведите имя в формате 'Фамилия Имя Отчество': ");
        fgets(owner.name, sizeof(owner.name), stdin);
        owner.name[strcspn(owner.name, "\n")] = '\0';

        printf("Введите номер автомобиля: ");
        fgets(owner.carNumber, sizeof(owner.carNumber), stdin);
        owner.carNumber[strcspn(owner.carNumber, "\n")] = '\0';

        printf("Введите номер телефона владельца: ");
        fgets(owner.phoneNumber, sizeof(owner.phoneNumber), stdin);
        owner.phoneNumber[strcspn(owner.phoneNumber, "\n")] = '\0';

        printf("Введите номер техпаспорта автомобиля: ");
        fgets(owner.techNumber, sizeof(owner.techNumber), stdin);
        owner.techNumber[strcspn(owner.techNumber, "\n")] = '\0';

        fseek(file, 0, SEEK_END);  
        if (i > 0) {
            fprintf(file, "\n");  
        }
        fprintf(file, "%s\n%s\n%s\n%s", owner.name, owner.carNumber, owner.phoneNumber, owner.techNumber);

        if (i < n - 1) {
            fprintf(file, "\n");  
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* file = fopen("programm.txt", "r+");

    if (file != NULL) {
        int choice;
        printf("Выберите операцию:\n1. Добавить элементы\n2. Удалить элемент\n3. Ввести новые элементы\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            int n, k;
            printf("Введите количество элементов для добавления: ");
            scanf_s("%d", &n);
            printf("Введите номер K, с которого начать добавление: ");
            scanf_s("%d", &k);

            AddElements(file, n, k);

            printf("Элементы успешно добавлены.\n");
            break;
        }
        case 2: {
            int elementDel;
            printf("Введите номер элемента для удаления: ");
            scanf_s("%d", &elementDel);

            Delete(file, elementDel);

            printf("Элемент успешно удален.\n");
            break;
        }
        case 3: {
            int n;
            printf("Введите количество элементов для ввода: ");
            scanf_s("%d", &n);

            Input(file, n);

            printf("Элементы успешно введены.\n");
            break;
        }
        default:
            printf("Неверный выбор операции.\n");
        }
        fclose(file);
    }
    else {
        printf("Не удалось открыть файл.\n");
        return 1;
    }
    return 0;
}
