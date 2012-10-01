#ifndef HEADERFACTORY_H
#define HEADERFACTORY_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../hdr/Header.h"

class HeaderFactory {

	public:

		static HeaderFactory* getInstance();

		Header * generateHeader (uint8_t * headerBytes);

	private:

		HeaderFactory(){};

		HeaderFactory(HeaderFactory const&){};

		void setBodySize(uint8_t * receivedHeader);

		static HeaderFactory* instance;
};

#endif // HEADERFACTORY_H
