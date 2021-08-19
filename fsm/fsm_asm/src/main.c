/*
 * main.c
 *
 *  Created on: 18 sie 2021
 *      Author: foralost
 */

#include <stdio.h>
#include "include/fsm_asm.c"
#include <string.h>

int main(int argc, char** argv)
{
	char buff[] = ".section .text\nstart: mov eax,ebx\nmov ecx,edx\nsyscall\n";

	struct token_result* res  = fsm_parse_assembly(buff, strlen(buff));

	while(res)
	{
		switch ( res->TYPE ){
		case S_LABEL:
			printf("LABEL ");
			break;

		case S_OPCODE:
			printf("OPCODE ");
			break;

		case S_ARGUMENT:
			printf("ARGUMENT ");
			break;

		case S_SECTION:
			printf("SECTION ");
			break;

		case S_SECTION_NAME:
			printf("SECTION NAME ");
			break;

		default:
			goto continue_l;
		}
		printf("%.12s\n", res->val);


		continue_l:
			res = res->next;
	}
	return 0;
}
