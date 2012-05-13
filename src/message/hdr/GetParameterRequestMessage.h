#ifndef GETPARAMETERREQUESTMESSAGE_H_
#define GETPARAMETERREQUESTMESSAGE_H_

#include "Message.h"
#include "../../body/enum/ParameterEnum.h"

/**
 * Mensajes de tipo 'GetParameter'
 */
class GetParameterRequestMessage : public Message {

	public:
		GetParameterRequestMessage(ParameterEnum parameter);
};

#endif /* GETPARAMETERREQUESTMESSAGE_H_ */
