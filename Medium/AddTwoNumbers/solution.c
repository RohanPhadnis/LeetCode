/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int current_place = 0;
    int next_place = 0;
    int num;

    struct ListNode* output = NULL;
    struct ListNode* prev;
    struct ListNode* current;

    while (l1 != NULL || l2 != NULL || next_place != 0) {

        num = next_place;
        if (l1 != NULL) {
            num += l1 -> val;
        }
        if (l2 != NULL) {
            num += l2 -> val;
        }

        current_place = num % 10;
        next_place = num / 10;

        current = malloc(sizeof(struct ListNode));
        current -> val = current_place;
        current -> next = NULL;
        if (output == NULL) {
            output = current;
            prev = output;
        } else {
            prev -> next = current;
            prev = prev -> next;
        }
        current = current -> next;
        if (l1 != NULL) {
            l1 = l1 -> next;
        }
        if (l2 != NULL) {
            l2 = l2 -> next;
        }
    }

    return output;
}
