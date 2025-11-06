#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "unicode_handling.h"


static res_uchar initialize_unicode() {
	
	return (res_uchar){SAFE_ENCODING,(unichar){0, 0}};
}

static res_uchar encode_unicode(uint32_t value) {

	if (value > 0x10FFFF) {
		response.err = INVALID_UNICODE_VALUE;
		memset(response.data.chr, 0, 5);
		response.data.byte = 0;
	}

	if(value <= 0x7F) {
			response.data.chr[0] = value;

		} else if(value <= 0x7FF) {

			uint8_t utf_char[3];
			response.data.chr[0] = 0xC0 | (value >> 6) ;
			response.data.chr[1] = 0x80 | (value & 0x3F);

		} else if(value <= 0xFFFF) {

			response.data.chr[0] = 0xE0 | (value >> 12) ;
			response.data.chr[1] = 0x80 | ((value >> 6) & 0x3F);
			response.data.chr[2] = 0x80 | (value & 0x3F);

		} else if(value <= 0x10FFFF) {

			response.data.chr[0] = 0xE0 | (value >> 18) ;
			response.data.chr[1] = 0x80 | ((value >> 12) & 0x3F);
			response.data.chr[2] = 0x80 | ((value >> 6) & 0x3F);
			response.data.chr[3] = 0x80 | (value & 0x3F);

		}

	return response;
}


res_uchar create_unicode(uint32_t hex) {
	
	res_uchar response;

	response = initialize_unicode();

	if (sizeof(hex) > 4) {
		response.err = INVALID_UNICODE_VALUE;
		memset(response.data.chr, 0, sizeof(response.data.chr));
		response.data.byte = 0;
		return response;
	}


	response = encode_unicode(hex);

	return response;
}


uint8_t print_unicode(res_uchar data) {
	printf("%s", data.data.chr);
	return data.data.byte;
}
