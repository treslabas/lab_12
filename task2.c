#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"

 struct AEROFLOT {
    char destination_name[255];
    int flight_number;
    char plane_type[255];
};

static void read_plane(struct AEROFLOT *el) {
    printf("Please, write destination name: ");
    scanf("%s", el->destination_name);
    printf("Please, write flight number: ");
    scanf("%d", &(el->flight_number));
    printf("Please, write plane type: ");
    scanf("%s", el->plane_type);
}

static void print_struct(struct AEROFLOT *el) {
    printf("| DIST.NAME: %s, FLIGHT NUMBER: %d, PLANE TYPE: %s |\n",
           el->destination_name, (el->flight_number), el->plane_type);
}

struct ListNode;

struct ListNode {
    struct ListNode* next;
    struct AEROFLOT* el;
};

int getSize(struct ListNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getSize(root->next);
}

void deleteElement_h(char *str, struct ListNode *cur, struct ListNode* last) {
    if(cur == NULL) {
        return;
    }
    if(strcmp(str, cur->el->destination_name) == 0) {
        if(last != NULL) {
            last->next = cur->next;
        }
        deleteElement_h(str, cur->next, last);
    } else {
        deleteElement_h(str, cur->next, cur);
    }
}

struct ListNode* deleteElement(char *str, struct ListNode *root) {
    if(root == NULL) {
        return NULL;
    }
    struct ListNode *cur = root;
    while(strcmp(str, cur->el->destination_name) == 0) {
        cur = cur->next;
        if(cur == NULL) {
            return NULL;
        }
    }
    deleteElement_h(str, cur, NULL);
    return cur;
}

struct ListNode* addElement(struct AEROFLOT *el, struct ListNode* root) {
    if(root == NULL) {
        struct ListNode* l = calloc(sizeof (struct ListNode), 1);
        l->el = el;
        return l;
    } else {
        struct ListNode *cur = root;
        assert(cur != NULL);
        while(cur->next != NULL) {
            if(strcmp(cur->next->el->destination_name, el->destination_name) >= 0) {
                break;
            }
            cur = cur->next;
            assert(cur != NULL);
        }
        struct ListNode* l = calloc(sizeof (struct ListNode), 1);
        struct ListNode *prev = cur->next;
        cur->next = l;
        l->el = el;
        l->next = prev;
        return root;
    }
}

void outlist(struct ListNode *root) {
    if(root == NULL) {
        printf("\n");
        return;
    }
    print_struct(root->el);
    outlist(root->next);
}

struct AEROFLOT* makesruct(char* d, int n, char *p) {
    struct AEROFLOT *ptr = calloc(sizeof(struct AEROFLOT), 1);
    strcpy(ptr->destination_name, d);
    ptr->flight_number = n;
    strcpy(ptr->plane_type, p);
    return ptr;
}

int main() {
    struct ListNode *root = NULL;
    root = addElement(makesruct("LA", 02, "bgf"), root);
    root = addElement(makesruct("LA3", 02, "bgf"), root);
    root = addElement(makesruct("LA", 02, "bgf"), root);
    root = addElement(makesruct("LA2", 02, "bgf"), root);
    outlist(root);
//    root = deleteElement("LA", root);
//    outlist(root);
}

