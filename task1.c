#include <stdio.h>
#include <stdlib.h>

struct ListNode;

struct ListNode {
    struct ListNode* next;
    int value;
};

int getSize(struct ListNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getSize(root->next);
}

int* findMax(struct ListNode *root) {
    if(root == NULL) {
        return NULL;
    }
    int* nxt = findMax(root->next);
    if(nxt != NULL) {
        if(*nxt > root->value) {
            return nxt;
        } else return &root->value;
    }
    return &root->value;
}

void deleteElement_h(int value, struct ListNode *cur, struct ListNode* last) {
    if(cur == NULL) {
        return;
    }
    if(cur->value == value) {
        if(last != NULL) {
            last->next = cur->next;
        }
        deleteElement_h(value, cur->next, last);
    } else {
        deleteElement_h(value, cur->next, cur);
    }
}

struct ListNode* deleteElement(int value, struct ListNode *root) {
    if(root == NULL) {
        return NULL;
    }
    struct ListNode *cur = root;
    while(cur->value == value) {
        cur = cur->next;
        if(cur == NULL) {
            return NULL;
        }
    }
    deleteElement_h(value, cur, NULL);
    return cur;
}

struct ListNode* addElement(int value, struct ListNode* root) {
    if(root == NULL) {
        struct ListNode* l = calloc(sizeof (struct ListNode), 1);
        l->value = value;
        return l;
    } else {
        struct ListNode *cur = root;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        struct ListNode* l = calloc(sizeof (struct ListNode), 1);
        cur->next = l;
        l->value = value;
        return root;
    }
}

void outlist(struct ListNode *root) {
    if(root == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", root->value);
    outlist(root->next);
}

struct ListNode* makeUnique(struct ListNode* root) {
    if(root == NULL) {
        return NULL;
    }
    struct ListNode *cur = deleteElement(root->value, root->next);
    root->next = cur;
    makeUnique(root->next);
    return root;
}

int main() {
    struct ListNode *root = NULL;

    root = addElement(1, root);
    root = addElement(1, root);
    root = addElement(2, root);
    root = addElement(2, root);
    root = addElement(3, root);
    root = addElement(3, root);
    root = addElement(3, root);
    outlist(root);

    root = makeUnique(root);
    root = deleteElement(1, root);
    outlist(root);
}
