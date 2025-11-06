#ifndef UNICODE_HANDLING
#define UNICODE_HANDLING

#include <stdint.h>

#ifdef _WIN32
    #ifdef UNICODE_HANDLER_BUILDING_DLL
        // We are building the DLL - export symbols
        #define UNIC_API __declspec(dllexport)
    #else
        // We are using the DLL - import symbols
        #define UNIC_API __declspec(dllimport)
    #endif
#else
    // Linux/macOS - no special handling needed (or use visibility attributes)
    #define UNIC_API
#endif



typedef enum unicode_errors {
	SAFE_ENCODING,
	INVALID_UNICODE_VALUE,
	CORRUPTED_UNICODE_ENCODING,
} unichar_err;

typedef struct unicode_char {
	uint8_t chr[5];
	uint8_t byte;
} unichar;

typedef struct unicode_response {
	unichar_err err;
	unichar data;
} res_uchar;


UNIC_API res_uchar create_unicode(uint32_t hex);
UNIC_API uint8_t print_unicode(res_uchar data);


#endif //UNICODE_HANDLING
