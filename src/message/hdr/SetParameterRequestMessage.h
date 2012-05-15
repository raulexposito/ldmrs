#ifndef SETPARAMETERREQUESTMESSAGE_H
#define SETPARAMETERREQUESTMESSAGE_H

#include "Message.h"
#include "../../body/hdr/SetParameterRequestBody.h"

/**
 * Mensajes de tipo 'set parameter'
 */
class SetParameterRequestMessage : public Message {

	public:
		SetParameterRequestMessage(ParameterEnum parameter, uint32_t value);
};

#endif // SETPARAMETERREQUESTMESSAGE_H
