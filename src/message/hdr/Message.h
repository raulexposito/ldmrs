#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../header/hdr/Header.h"
#include "../../body/hdr/Body.h"
#include <stdint.h> 	// para 'uint8_t'

class Message {

	public:

		Message(Header* header, Body* body);

		virtual ~Message();

		uint8_t * getBytes();

		void showBytes();

		int getAmountBytes();

	protected:

		Header* header;

		Body* body;

		uint8_t* bytes;

		int messageSize;

	private:

		void populateBytes();
};

#endif // MESSAGE_H
