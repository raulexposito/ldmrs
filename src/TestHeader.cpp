#include "Header.h"
#include <iostream.h>

void testShowBytesHeaders() {
	Header *scanDataHeader = new ScanDataHeader(42);
	Header *errorAndWarningHeader = new ErrorAndWarningHeader(42);
	Header *commandHeader = new CommandHeader(42);
	Header *commandReplyHeader = new CommandReplyHeader(42);

	scanDataHeader->showBytes();
	cout << endl;
	errorAndWarningHeader->showBytes();
	cout << endl;
	commandHeader->showBytes();
	cout << endl;
	commandReplyHeader->showBytes();

	delete scanDataHeader;
	delete errorAndWarningHeader;
	delete commandHeader;
	delete commandReplyHeader;
}


int main () {
	
	testShowBytesHeaders();
	return 0;
}
