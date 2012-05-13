#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../header/hdr/Header.h"
#include "../../body/hdr/Body.h"
#include <stdint.h> 	// para 'uint8_t'

class Message {

	public:

		virtual ~Message();

//		uint8_t * getBytes();

		void showBytes();

	protected:

		Header* header;

		Body* body;
};

#endif // MESSAGE_H
