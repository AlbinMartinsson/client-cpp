#include <iostream>
#include "arrowhead/Subscriber.h"

static void callback(const char* url, const char* ptr){
	printf("messages reseved: \n%s\n", ptr);
}

int main(int argc, char* argv[]){
	arrowhead::Subscriber subscriber("subscriber.json", callback);
	subscriber.config.print();

	while(true){
		sleep(100);
	}

	return 1;
}
