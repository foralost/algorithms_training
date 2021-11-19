#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char* __shift_left_big_num( unsigned char* numb, const size_t* size, const size_t* n, size_t* new_size);


int main(int argc, char** argv)
{
	unsigned char numb[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEE };
	size_t size_num = 6;

	size_t places = 1;
	
	size_t new_size = 0;
	char* newNumb = __shift_left_big_num( numb, &size_num, &places, &new_size);


	for(size_t i = 0 ; i < new_size; i++)
		printf(" | %hhX | ", newNumb[i] );
	

	free(newNumb);	

	return 0;
}
