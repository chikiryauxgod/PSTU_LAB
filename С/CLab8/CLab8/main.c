#include <stdio.h>
#include <stdlib.h>

struct node {
int value;
struct node* previous;
};

void push_back(struct node** last, int data) {
struct node* tmp = (struct node*)malloc(sizeof(struct node));
tmp->value = data;
tmp->previous = (*last);
(*last) = tmp;
}

void for_each(struct node** last, void(*function)(int*))
{
struct node* tmp = *last;
while (tmp) {
function(&tmp->value);
tmp = tmp->previous;
}
}

void erase_list(struct node** last)
{
struct node* tmp = *last;
while (tmp) {
tmp = tmp->previous;
free(*last);
*last = tmp;
}
}
void setman (int* element){
printf("Введите значение элемента: ");
scanf("%i", element);
}

void show(int* element){
printf("%03d ", *element);
}

int main() {
struct node* head = 0;
push_back(&head, 11);
push_back(&head, 12);
for_each(&head, show);
printf("\n");
for_each(&head, setman);
push_back(&head, 13);
for_each(&head, show);
printf("\n");
printf("head: %LX\n", head);
erase_list(&head);
printf("head: %LX\n", head);

}
