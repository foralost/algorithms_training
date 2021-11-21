/*
 * btree.h
 *
 *  Created on: 17 sie 2021
 *      Author: foralost
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <stdint.h>
#include <string.h>

#define TREE_NODE_POINTERS 	4
#define TREE_NODE_KEYS		TREE_NODE_POINTERS-1
#define TREE_INVALID_KEY	-1

struct tree_node {
	uint32_t			keys[TREE_NODE_KEYS] = { -1 };
	struct 	tree_node* 	ptrs[TREE_NODE_POINTERS] = {};
	struct  tree_node*  root = NULL;
};


void btree_set_empty_node(struct tree_node* start)
{
	memset(start->keys, TREE_INVALID_KEY, TREE_NODE_KEYS * sizeof(*start->keys));
	memset(start->ptrs, 0, sizeof(start->ptrs[0]) * TREE_NODE_POINTERS);
}


char btree_is_node_full(struct tree_node* node){
	for(uint8_t i = 0 ; i < TREE_NODE_KEYS; i++)
		if(node->keys[i] == TREE_INVALID_KEY)
			return 0;

	return 1;
}
struct tree_node* btree_move_down(struct tree_node* node, const uint32_t val)
{
	for(uint8_t i = 0; i < TREE_NODE_KEYS; i++)
		if( node->keys[i] < val && node->ptrs[i] )
			return node->ptrs[i];
		else if(node->keys[i] > val && node->ptrs[i+1])
			return node->ptrs[i+1];

	return 0;

}
struct tree_node* btree_append_key(struct tree_node* node, const uint32_t val){

	struct tree_node* next_node = node, *curr_node = node;

	// Find a leaf node
	while(!next_node)
	{
		curr_node = next_node;
		next_node = btree_move_down(curr_node, val);
	}

	for(uint8_t i = 0 ; i < TREE_NODE_KEYS - 1; i++){
		if(val <= node->keys[i + 1] && node->keys[i] == TREE_INVALID_KEY ){
			node->keys[i] = val;
			return node;
		}
	}

	struct tree_node* new_node = malloc(sizeof(struct tree_node));
	btree_set_empty_node(new_node);
	uint8_t break_index = TREE_NODE_KEYS << 1;

	if( TREE_NODE_KEYS & 1 ){
		break_index++;
	}

	new_node->keys[0] = val;

	// There is no space left... time for splitting





}





#endif /* BTREE_H_ */
