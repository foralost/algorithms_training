/*
 * fsm_asm.c
 *
 *  Created on: 18 sie 2021
 *      Author: foralost
 */

#include<stddef.h>
#include <stdlib.h>

enum STATES {
	S_START,
	S_SECTION,
	S_SECTION_NAME,
	S_LABEL,
	S_OPCODE,
	S_ARGUMENT,
	S_END,
	S_FAIL
};

struct token_result {
	char *val;
	enum STATES TYPE;
	struct token_result *next;
};

char __fsm_is_letter(char to_test) {
	return (('A' <= to_test) && (to_test <= 'z'));
}

char __fsm_is_char(char to_test) {
	return (('0' <= to_test) && (to_test <= 'z'));
}

char __fsm_is_ws(char to_test) {
	return (to_test == ' ' || to_test == '\t' || to_test == '\n');
}

struct token_result* append_new_token(enum STATES to_set, char *buff,
		size_t *start, size_t *end) {

	struct token_result *toRet = malloc(sizeof(struct token_result));
	toRet->val = malloc(*end - *start);
	toRet->TYPE = to_set;
	size_t offset = 0;
	for (size_t i = *start; i < *end; i++){
		if(!__fsm_is_ws(buff[i])){
			toRet->val[offset++] = buff[i];
		}
	}

	return toRet;

}



struct token_result* fsm_parse_assembly(char *input, size_t size) {
	enum STATES current_state;
	size_t offset, last_offset;

	offset = 0;
	last_offset = 0;

	current_state = S_START;

	struct token_result *curr_token = malloc(sizeof(struct token_result));
	struct token_result *start = curr_token;

	while (offset < size) {
		char c = input[offset];

		switch (current_state) {

		case S_START:
			if (c == '.') {
				current_state = S_SECTION;
				last_offset = offset;
			} else if (__fsm_is_char(c)) {
				current_state = S_OPCODE;
				last_offset = offset;
			} else if (__fsm_is_ws(c)) {
				break;
			} else if (!c) {
				current_state = S_END;
			} else {
				current_state = S_FAIL;
			}
			break;
		case S_SECTION:
			if (__fsm_is_ws(c)) {
				curr_token->next = append_new_token(current_state, input,
						&last_offset, &offset);
				curr_token = curr_token->next;

				current_state = S_SECTION_NAME;
				last_offset = offset;
			} else if (!c) {
				current_state = S_END;
			} else if(!__fsm_is_char(c)){
				current_state = S_FAIL;
			}
			break;
		case S_SECTION_NAME:
			if (__fsm_is_ws(c)) {
				curr_token->next = append_new_token(current_state, input,
						&last_offset, &offset);
				curr_token = curr_token->next;

				current_state = S_START;
			} else if (!c) {
				current_state = S_END;
			} else if(!__fsm_is_char(c) && c != '.') {
				current_state = S_FAIL;
			}
			break;
		case S_OPCODE:
			if (c == ':') {
				current_state = S_START;
				offset++;

				curr_token->next = append_new_token(S_LABEL, input,
						&last_offset, &offset);
				curr_token = curr_token->next;

			} else if (__fsm_is_ws(c)) {
				curr_token->next = append_new_token(current_state, input,
						&last_offset, &offset);
				curr_token = curr_token->next;

				current_state = S_ARGUMENT;
				last_offset = offset;
			} else if (!c) {
				current_state = S_END;
			} else if(!__fsm_is_char(c)){
				current_state = S_FAIL;
			}
			break;

		case S_ARGUMENT:
		if (c == ',') {
				curr_token->next = append_new_token(current_state, input,
						&last_offset, &offset);
				curr_token = curr_token->next;
				last_offset = offset + 1;

			} else if (c == '\n') {
				curr_token->next = append_new_token(current_state, input,
						&last_offset, &offset);

				curr_token = curr_token->next;
				current_state = S_START;

			} else if (!c) {
				current_state = S_END;
			} else if(!__fsm_is_char(c)) {
				current_state = S_FAIL;
			}
			break;
		default:
			printf("Fail State! Error at: %.16s", input + offset - 1);
			return NULL;

		}

		offset++;

	}
	return start;
}

