#ifndef SETPARAMETERREQUESTMESSAGE_H
#define SETPARAMETERREQUESTMESSAGE_H

#include "Message.h"
#include "../../body/hdr/SetParameterCommandBody.h"

/**
 * Mensajes de tipo 'set parameter'
 */
class SetParameterCommandMessage : public Message {

	public:

		SetParameterCommandMessage(ParameterEnum parameter, uint32_t value);
};

#endif // SETPARAMETERREQUESTMESSAGE_H
