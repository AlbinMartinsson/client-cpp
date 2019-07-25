#include <iostream>
#include "arrowhead/Subscriber.h"

// callback when a published messages is received
// url is the "SERVICE_URL" that are sent
// prt contains the messages
static void callback(const char* url, const char* ptr){
	printf("messages received: \n%s\n", ptr);
}

int main(int argc, char* argv[]){
	// create a instance of an arrowhead subscriber
	arrowhead::Subscriber subscriber("subscriber.json", callback);
	// print configs for debugging
	subscriber.config.print();

	while(true){
		// what for messages
		// incoming messages will interrupt
		sleep(100);
	}

	return 1;
}
