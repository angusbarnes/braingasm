#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define MEMSIZE 30000
size_t __program_counter = 0;

#define INCREMENT_PC() __program_counter++

void safe_increment(uint8_t* byte) {
	if (*byte == 255) { 
		*byte = 0;
		return;
	}

	*byte++;
}


int main() {
	
	uint8_t* memory = calloc(MEMSIZE, sizeof(uint8_t));	
	if(memory != NULL) {
		printf("Created stack frame at address: %p\n with size: %d\n", memory, MEMSIZE);
	} else {
		printf("Failed to initialise memory for VM\n");
	}

	INCREMENT_PC();

	printf("PC: %d\n", __program_counter);

	free(memory);
	return 0;
}
