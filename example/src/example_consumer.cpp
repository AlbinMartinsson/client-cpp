#include <iostream>
#include "arrowhead/Consumer.h"

static void callback(const char* url, const char* prt){
	printf("callback reseved: \n%s\n", prt);
}


int main(int argc, char* argv) {
	arrowhead::Consumer consumer("consumer.json", callback);
	consumer.config.print();

	while(true) {
		consumer.request();
		sleep(5);
	}

	return 1;
}
