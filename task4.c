//Создать стек для символов. Максимальный размер стека вводится с экрана.
// Создать функции для ввода и вывода элементов стека. Добавлять символы с экрана в стек.
// В случае совпадения вводимого символа с вершиной стека вытолкнуть его и распечатать стек.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char *x;
    int head;
    int size;
} Stack;

int Init(Stack *stack, int nSize);
char Pop(Stack *stack);
int Push(Stack *stack, char cElement);
void Clear(Stack *stack);
void Free(Stack *stack);

int Init(Stack *stack, int nSize) {
    stack->x = (char *) malloc(nSize);
    if (stack->x == NULL) return -1;
    stack->size = nSize;
    stack->head = 0;
    return nSize;
}

char Pop(Stack *stack) {
    if (stack->head == 0) return 0;
    return stack->x[--stack->head];
}

char Get(Stack *stack) {
    if (stack->head == 0) return 0;
    return stack->x[stack->head - 1];
}

int Push(Stack *stack, char cElement) {
    if (stack->head == stack->size)
        return -1;
    stack->x[stack->head++] = cElement;
    return 1;
}

void Clear(Stack *stack) {
    stack->head = 0;
    printf("Стек пуст");
}

void Free(Stack *stack) {
    free(stack->x);
}

int main() {
    setlocale(LC_ALL, "ru");
    Stack a, b;
    int n1, n2;
    printf("Введите размер первого стека: ");
    scanf("%d", &n1);
    Init(&a, n1);
    int exit = 0;
    while (!exit) {
        printf("1. Добавить\n"
               "2. Удалить\n"
               "3. Показать\n"
               "4. Удаление всех элементов стека\n"
               "0. Выход\n");
        int k;
        scanf("%d", &k);
        switch (k) {
            case 1:
                printf("Введите символ: \n");
                char c;
                scanf(" %c", &c);
                if (Get(&a) == c) {
                    printf("Удаляем элемент\n");
                    Pop(&a);
                    if (a.head == 0)
                        printf("Стек пуст\n");
                    for (int i = 0; i < a.head; i++)
                        printf("%c ", a.x[i]);
                    printf("\n");
                } else {
                    Push(&a, c);
                }
                break;
            case 2:
                if (a.head == 0)printf("Стек пуст\n");
                Pop(&a);
                break;
            case 3:
                if (a.head == 0)
                    printf("Стек пуст\n");
                for (int i = 0; i < a.head; i++)
                    printf("%c ", a.x[i]);
                printf("\n");
                break;
            case 4:
                Clear(&a);
                Free(&a);
                break;
            case 0:
                exit = 1;
                break;
        }
    }
    return 0;
}
