// Unicode encoding and decoding
// 1 byte characters 0xxxxxxx [7 bits available] [range 0x00 <==> 0x7F]
// 2 byte characters 110xxxxx 10xxxxxx [11 bits available] [range 0x80 <==> 0x7FF]
// 3 byte characters 1110xxxx 10xxxxxx 10xxxxxx [16 bits available] [range 0x800 <==> 0xFFFF]
// 4 byte characters 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx [21 bits available] [range 0x10000 <==> 0x10FFFF]
//
// 10000000 => 0x80
// 11000000 => 0xC0
// 11100000 => 0xE0
// 11110000 => 0xF0
//
// 00111111 => 0x3F



#include "unicode_handling.h"
#include <stdio.h>
#include <stdint.h>


int main() {
	
	// for(uint32_t it = 0x0; it <= 0x01AF; it++) {
	//
	// 	printf("%x => ", it);
	// 	print_unicode(create_unicode(it));
	// 	printf("\n");
	// }


	print_unicode(create_unicode(0x92E));

	printf("\n");
	return 0;
}
