#include <stdlib.h>
#include <stdio.h>

#include "List.h"

struct Node {
    int value;
    List next;
};

static List createListNode(int value);
static List listGetLargest(List l);
static List listRemoveNode(List l, List node);

// Create a linked list from an array of values, maintaining the same order as
// in the array.
List ListFromArray(int values[], int size) {
    List l = NULL;
    List tail = NULL;
    for (int i = 0; i < size; i++) {
        List node = createListNode(values[i]);
        if (l == NULL) {
            l = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return l;
}

// Print out all values in a list.
// E.g. A list containing numbers 1, 2 and 3 will print:
// 1 -> 2 -> 3 -> X
void ListPrint(List l) {
    if (l == NULL) {
        printf("X\n");
    } else {
        printf("%d -> ", l->value);
        ListPrint(l->next);
    }
}

// Free all memory associated with a list.
void ListFree(List l) {
    if (l != NULL) {
        ListFree(l->next);
        free(l);
    }
}

// Sort the values in a list using the selection sort algorithm.
//
// The nodes from the original list are re-ordered into the sorted list which is
// returned, therefore the original list cannot be used after calling this
// function.
List ListSelectionSort(List l) {
    List sorted = NULL;
    List unsorted = l;

    while (unsorted != NULL) {
        // Find the largest unsorted element
        List largest = listGetLargest(unsorted);

        // Remove from the original list
        unsorted = listRemoveNode(unsorted, largest);

        // Insert into the sorted list
        largest->next = sorted;
        sorted = largest;
    }

    return sorted;
}

static List listGetLargest(List l) {
    List largest = l;
    for (List curr = l; curr != NULL; curr = curr->next) {
        if (curr->value > largest->value) {
            largest = curr;
        }
    }

    return largest;
}

static List listRemoveNode(List l, List node) {
    if (l == node) {
        return l->next;
    } else {
        l->next = listRemoveNode(l->next, node);
        return l;
    }
}

// Create a list node with a given value.
static List createListNode(int value) {
    List l = malloc(sizeof(struct Node));
    if (l == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    l->value = value;

    return l;
}

