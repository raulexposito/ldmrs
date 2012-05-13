#include "hdr/GetStatusRequestBody.h"

#define CODE_PREFFIX 0x01
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

/**
 * TODO: en la pagina 10 hablan del mensaje de vuelta, hay que implementarlo
 */

GetStatusRequestBody::GetStatusRequestBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}
