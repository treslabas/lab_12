#include<stdio.h>
#include<stdlib.h>
#include "ctype.h"

struct AEROFLOT {
    char destination_name[255];
    int flight_number;
    char plane_type[255];
};

struct AEROFLOT *read_plane() {
    struct AEROFLOT *el = calloc(sizeof(struct AEROFLOT), 1);
    printf("Please, write destination name: ");
    scanf("%s", el->destination_name);
    printf("Please, write flight number: ");
    scanf("%d", &(el->flight_number));
    printf("Please, write plane type: ");
    scanf("%s", el->plane_type);
    return el;
}

static void print_struct(struct AEROFLOT *el) {
    printf("| DIST.NAME: %s, FLIGHT NUMBER: %d, PLANE TYPE: %s |\n",
           el->destination_name, (el->flight_number), el->plane_type);
}

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct item {
    struct AEROFLOT *item22;

    struct item *next;
} Item;

void Enqueue(void);

void Dequeue(void);

void Display(void);

Item *head = NULL, *tail = NULL;/* Указатели на начало(голову) и конец(хвост) очереди*/

int main() {
    int done = FALSE;
    char c;
    while (!done) {
        Display();
        printf("\nA)add, D)Delete, Q)Quit ");
        scanf("%s", &c);
        getchar();
        switch (toupper(c)) {
            case 'A':
                Enqueue();
                break;
            case 'D':
                Dequeue();
                break;
            case 'Q':
                done = TRUE;
                break;
        }
    }
    return 0;
}

/* Удалить элемент из очереди*/
void Dequeue(void) {
    Item *p = head; /* p указывает на голову очереди*/
    if (head != NULL) { /* если очередь не пуста... */
        head = head->next; /* head указывает на следующий эл. */
        if (head == NULL) /* если очередь содержит1 элемент*/
            tail = NULL; /* tail равен нулю*/
        free(p); /* удалить элемент*/
    }
}

/* Отобразить содержимое очереди*/
void Display(void) {
    Item *p = head;
    if (p == NULL)
        printf("Queue is empty");
    else
        printf("Queue: ");
    while (p != NULL) {
        print_struct(p->item22);
        p = p->next;
    }
}

/* Поставить элемент в очередь*/
void Enqueue(void) {
    Item *p;
    p = (Item *) malloc(sizeof(Item)); /* создать элемент*/
    p->item22 = read_plane(); /* присвоитьdata случайное число*/
    p->next = NULL; /* установить признак конца очереди*/
    if (head == NULL) /* если очередь пуста... */
        head = p; /* head указывает на созданный элемент*/
    else tail->next = p; /* поставить новый эл. в конец очереди*/
    tail = p; /* tail указывает на конец очереди*/
}
