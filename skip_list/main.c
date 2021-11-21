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

struct insert_history {
	struct item *inserted;
	struct insert_history *next;
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

struct item* append_node(struct item *to_append, int val) {
	struct item *temp = to_append->next;
	to_append->next = create_node(val, NULL, to_append->assigned);

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

struct item* search_to_insert(struct item *node, int val,
		struct insert_history **hist) {

	struct item *curr = node; // Start at top-left node

	for (;;) {
		while (curr->next && val >= curr->next->val) {
			printf("Going next: %d -> %d, LVL: %d \n", curr->val,
					curr->next->val, curr->assigned->height);
			curr = curr->next;
		}

		if (curr->bottom) {
			printf("Going down: LVL %d -> %d\n", curr->assigned->height,
					curr->bottom->assigned->height);

			//FIXME: Fix goddamn names
			struct insert_history *new_item = malloc(
					sizeof(struct insert_history));
			new_item->inserted = curr;
			new_item->next = NULL;

			if (hist) {
				if (!(*hist))
					*hist = new_item;
				else {
					struct insert_history *temp = (*hist);
					*hist = new_item;
					new_item->next = temp;
				}
			}

			curr = curr->bottom;
		} else {

			return curr;
		}
	}

	// DEADC0DE
	return NULL;
}

struct item* search_key(struct skip_list *list, int val) {
	struct item *curr = list->top_tower->items; // Start at top-left node

	for (;;) {
		while (curr->next && val >= curr->next->val)
			curr = curr->next;

		if (curr->val == val)
			return curr;

		if (curr->bottom)
			curr = curr->bottom;
		else
			return NULL;
	}

	return NULL;
}

void print_list(struct skip_list *curr_list) {
	struct tower *curr_tower = curr_list->top_tower;
	struct item *curr_item;

	while (1) {
		curr_item = curr_tower->items->next;
		printf("Tower number %d \n ", curr_tower->height);
		while (curr_item) {
			printf(" %d ", curr_item->val);
			curr_item = curr_item->next;
		}
		printf("\n");

		if (curr_tower->items->bottom)
			curr_tower = curr_tower->items->bottom->assigned;
		else
			break;
	}

}

struct item* insert_node(struct skip_list *list, int val) {
	printf("Inserting element: %d\n", val);
	struct insert_history *hist = NULL, *prev_hist;
	struct item *found = search_to_insert(list->top_tower->items, val, &hist);
	// Found should be at level 0!

	struct item *added = append_node(found, val);

	struct item *curr_item = added;
	struct tower *curr_tower = added->assigned;

	struct item *prev_item = added;
	while (head_or_tail()) {
		if (!curr_tower->prev) {
			// We are going to create a new tower, there is only one start node
			list->top_tower = create_tower(curr_tower->height + 1, curr_tower);
			curr_tower->prev = list->top_tower;

			// Append new one to it
			curr_item = append_node(list->top_tower->items, val);
			list->top_tower->items->next->bottom = prev_item;

		} else {
			// We are at existing higher tower
			// Recover the last node from which we went down
			// Append a new node to it
			curr_item = append_node(hist->inserted, val);
			curr_item->bottom = prev_item;

			prev_hist = hist;
			hist = hist->next;
			free(prev_hist);
		}

		prev_item = curr_item;
		curr_tower = curr_item->assigned;
	}

	// Remove leftovers if we are not going to
	// add another node to the higher level

	while (hist) {
		prev_hist = hist;
		hist = hist->next;
		free(prev_hist);
	}

	printf("\n");
	print_list(list);
	printf("\n");
	return found;
}

void delete_tower(struct tower *to_del) {
	struct item *curr_item = to_del->items;
	struct item *next_item = curr_item;

	do {

		curr_item = next_item;
		next_item = curr_item->next;

		curr_item->next = NULL;
		curr_item->bottom = NULL;
		curr_item->assigned = NULL;

		free(curr_item);
	} while (next_item);

	to_del->prev = NULL;
	to_del->items = NULL;
	free(to_del);
}

void delete_node(struct item *to_del_after) {
	struct item *temp = to_del_after->next->next;

	to_del_after->next->next = NULL;
	to_del_after->next->bottom = NULL;

	free(to_del_after->next);

	if (temp)
		to_del_after->next = temp;
	else
		to_del_after->next = NULL;
}


//TODO: Make deletion of a node, not value (allow duplicates).
void delete_node_from_list_p(struct items* item,  struct item* to_del) {}


void delete_node_from_list(struct skip_list *skip, int val) {
	struct item *curr = skip->top_tower->items;
	struct item *curr_bottom = NULL;

	for (;;) {

		while (curr->next && curr->next->val < val)
			curr = curr->next;

		if (curr->next && curr->next->val == val) {
			delete_node(curr);
			// Removing empty tower
			if (curr == curr->assigned->items && !curr->next) {
				curr_bottom = curr->bottom;
				delete_tower(curr->assigned);

				skip->top_tower = curr_bottom->assigned;
				curr_bottom->assigned->prev = NULL;

				if (curr_bottom) {
					curr = curr_bottom;
					continue;
				} else {
					return;
				}
			}

		}

		if (curr->bottom)
			curr = curr->bottom;
		else
			return;
	}

}
int main(void) {
	srand(0);		// RANDOMIZATION
	struct skip_list *skip = create_skip_list();

	for (int i = 0; i < 60; i++)
		insert_node(skip, rand() % 1024);

	delete_node_from_list(skip, 153);
	print_list(skip);

	struct item *found_k = search_key(skip, 923);

	if (found_k)
		printf("Found! %d Level %d", found_k->val, found_k->assigned->height);

	return 0;
}
