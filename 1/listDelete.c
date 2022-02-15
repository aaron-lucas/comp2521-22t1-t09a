#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listDelete(struct list *l, int value);

int main(int argc, char *argv[]) {

    return EXIT_SUCCESS;
}

// listDelete(1 -> 2 -> 3 -> X, 1) = 2 -> 3 -> X
// listDelete(1 -> 2 -> 3 -> X, 2) = 1 -> 3 -> X
// listDelete(1 -> 2 -> 3 -> X, 3) = 1 -> 2 -> X
void listDelete(struct list *l, int value) {
    if (l->head == NULL) {
        // Empty list
        return;
    }

    if (head->value == value) {
        // First in list
        struct node *toDelete = l->head;
        l->head = toDelete->next;
        free(toDelete);
    } else {
        // Middle or end
        for (struct node *curr = l->head; curr != NULL; curr = curr->next) {
            if (curr->next->value == value) {
                // found node
                struct node *toDelete = curr;



}
