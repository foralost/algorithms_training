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
	struct 	tree_node* 	nodes[TREE_NODE_POINTERS] = {};
	struct  tree_node*  root = NULL;
};


void btree_set_empty_node(struct tree_node* start)
{
	memset(start->keys, TREE_INVALID_KEY, TREE_NODE_KEYS * sizeof(*start->keys));
	memset(start->nodes, 0, sizeof(start->nodes[0]) * TREE_NODE_POINTERS);
}


void btree_append_key(struct tree_node* node, const uint32_t val){

	for(uint8_t i = 0 ; i < TREE_NODE_KEYS - 1; i++){
		if(val <= node->keys[i + 1] && node->keys[i] == TREE_INVALID_KEY ){
			node->keys[i] = val;
		}
	}

	// There is no space left... time for splitting





}





#endif /* BTREE_H_ */
