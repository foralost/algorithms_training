/*
 * main.c
 *
 *	Simple skip list implementation.
 *
 *  Created on: 18 lis 2021
 *      Author: foralost
 */
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct item {
	int val;

	struct tower *assigned;

	struct item *bottom;
	struct item *next;
};

struct tower {
	uint8_t height;

	struct tower *prev;
	struct item *items;
};

struct skip_list {
	struct tower *top_tower;
};

uint8_t head_or_tail() {
	return rand() % 2;
}

struct item* create_node(int val, struct item *bottom, struct tower *assigned) {

	struct item *toRet = malloc(sizeof(struct item));
	toRet->val = val;
	toRet->bottom = bottom;
	toRet->assigned = assigned;
	toRet->next = NULL;
	return toRet;
}

struct item* append_node(struct item *to_append, int val, struct item *bottom) {
	struct item *temp = to_append->next;
	to_append->next = create_node(val, bottom, to_append->assigned);

	if (temp)
		to_append->next->next = temp;
	return to_append->next;
}

struct tower* create_tower(uint8_t height, struct tower *bottom) {

	struct tower *toRet = malloc(sizeof(struct tower));
	toRet->height = height;
	toRet->prev = NULL;
	toRet->items = calloc(sizeof(struct item), 1);

	if (bottom)
		toRet->items->bottom = bottom->items;

	toRet->items->assigned = toRet;

	return toRet;
}

struct skip_list* create_skip_list() {
	struct skip_list *toRet = malloc(sizeof(struct skip_list));
	toRet->top_tower = create_tower(0, NULL);
	return toRet;
}

//TODO: History of insertion in parameter
//	to remove searching inside one tower
struct item* search_to_insert(struct item *node, int val) {

	struct item *curr = node; // Start at top-left node

	for (;;) {
		while (curr->next && val >= curr->next->val){
			printf("Going next: %d -> %d, LVL: %d \n", curr->val, curr->next->val, curr->assigned->height);
			curr = curr->next;
		}

		if (curr->bottom){
			printf("Going down: LVL %d -> %d\n", curr->assigned->height, curr->bottom->assigned->height);
			curr = curr->bottom;
		}
		else{
			return curr;
		}
	}

	// DEADC0DE
	return NULL;
}

struct item* search_key(struct skip_list* list, int val){
	struct item *curr = list->top_tower->items; // Start at top-left node

	for (;;) {
		while (curr->next && val >= curr->next->val)
			curr = curr->next;

		if(curr->val == val)
			return curr;

		if (curr->bottom)
			curr = curr->bottom;
		else
			return NULL;
	}

	return NULL;
}

//TODO: Remove
struct item* search_to_insert_in_tower(struct item *node, int val) {

	struct item *curr = node; // Start at top-left node

	for (;;) {
		if (curr->next && val >= curr->next->val)
			curr = curr->next;
		else
			return curr;
	}

	// DEADC0DE
	return NULL;
}

void print_list(struct skip_list* curr_list){
	struct tower *curr_tower = curr_list->top_tower;
		struct item *curr_item;

		while ( 1 ) {
			curr_item = curr_tower->items->next;
			printf("Tower number %d \n ", curr_tower->height);
			while (curr_item) {
				printf(" %d ", curr_item->val);
				curr_item = curr_item->next;
			}
			printf("\n");

			if(curr_tower->items->bottom)
				curr_tower = curr_tower->items->bottom->assigned;
			else
				break;
		}

}

struct item* insert_node(struct skip_list *list, int val) {
	printf("Inserting element: %d\n", val);
	struct item *found = search_to_insert(list->top_tower->items, val); // it should be at level 0
	struct item *added = append_node(found, val, NULL);

	struct item *added_prev = added;
	struct tower *curr_tower = added->assigned;

	while (head_or_tail()) {
		if (!curr_tower->prev) {
			list->top_tower = create_tower(curr_tower->height + 1, curr_tower);
			curr_tower->prev = list->top_tower;
		}
		// TODO: Use history from searching from insert, to append proper nodes
		struct item *added_higher = append_node(
				search_to_insert_in_tower(curr_tower->prev->items, val), val,
				added_prev);

		added_prev = added_higher;
		curr_tower = added_higher->assigned;
	}
	printf("\n");
	print_list(list);
	printf("\n");
	return added_prev;
}



int main(void) {
	srand( 0 );		// RANDOMIZATION
	struct skip_list *skip = create_skip_list();
	for(int i = 0 ; i < 1000; i++)
	insert_node(skip, rand() % 4096);

	// Print list

	struct item* found_k = search_key(skip, 103);

	if(found_k)
		printf("Found! %d Level %d", found_k->val, found_k->assigned->height);

	return 0;
}
