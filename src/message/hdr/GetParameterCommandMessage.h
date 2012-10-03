#ifndef GETPARAMETERREQUESTMESSAGE_H_
#define GETPARAMETERREQUESTMESSAGE_H_

#include "Message.h"
#include "../../body/enum/ParameterEnum.h"

/**
 * Mensajes de tipo 'GetParameter'
 */
class GetParameterCommandMessage : public Message {

	public:

		GetParameterCommandMessage(ParameterEnum parameter);
};

#endif /* GETPARAMETERREQUESTMESSAGE_H_ */
