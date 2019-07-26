#include "Subscriber.h"
#include "ErrorPrevention.h"

namespace arrowhead{
	
	Subscriber::Subscriber(){}
	Subscriber::~Subscriber(){}
	
	Subscriber::Subscriber(std::string file_path, f_void_f callback){
		config.load(file_path);
		init(callback);
	}

	bool Subscriber::init(f_void_f callback) {
		// test sow there in not an error in set up for applicationServiceInterface
		if (!initApplicationServiceInterface(config)){
			fprintf(stderr, "unable to init applictionServiceInterface");
			return false;
		}

		// register in the service register
		if(!registerSensor(config)) {
			fprintf(stderr, "cod not register sensor!\n");
			return false;
		}
		Subscriber::callback = callback;
		return true;
	}

	/*
	--
	-- Called, when publisher POST msgs arrives -- HTTP POST
	-- @orverride
	*/
	int Subscriber::callbackServerHttpPOST(const char *url, 
					const char *payload) {
		
		if(!ErrorPrevention::correctURI(url, config.SERVICE_URI))
			return 0;

		callback(url, payload);	
		return 1;
	}
}
