#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node *List;

/* ----------------------------------------------------------------- */

int listLengthIter(List l) {
    int len = 0;
    for (Node *curr = l; curr != NULL; curr = curr->next) {
        len++;
    }

    return len;
}

int listLengthRec(List l) {
    if (l == NULL) {
        return 0;
    }

    return 1 + listLengthRec(l->next);
}

/* ----------------------------------------------------------------- */

int listCountOddsIter(List l) {
    int odds = 0;
    for (Node *curr = l; curr != NULL; curr = curr->next) {
        if (curr->data % 2 != 0) {
            odds++;
        }
    }

    return odds;
}

int listCountOddsRec(List l) {
    if (l == NULL) {
        return 0;
    }

    if (l->data % 2 != 0) {
        return 1 + listCountOddsRec(l->next);
    } else {
        return listCountOddsRec(l->next);
    }

    // (condition) ? (if true) : (if false);
    // return ((l->data % 2 != 0) ? 1 : 0) + listCountOddsRec(l->next);

/* ----------------------------------------------------------------- */

bool listIsSortedIter(List l) {

}

bool listIsSortedRec(List l) {
    if (l == NULL || l->next == NULL) {
        // 0 or 1 elements are sorted
        return true;
    }

    if (l->data > l->next->data) {
        // Out of order
        return false;
    }

    return listIsSortedRec(l->next);
}

/* ----------------------------------------------------------------- */

List listDelete(List l, int value) {
    if (l == NULL) {
        return NULL;
    }

    if (l->data == value) {
        // Delete this one
        Node *restOfList = l->next;
        free(l);
        return restOfList;
    }

    l->next = listDelete(l->next, value);
    return l;
}
