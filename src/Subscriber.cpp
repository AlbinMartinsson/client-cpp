#include "Subscriber.h"

namespace arrowhead{
	
	Subscriber::Subscriber(){}
	Subscriber::~Subscriber(){}
	Subscriber::Subscriber(std::string file_path, f_void_f callback){
		config.lood(file_path);
		init(config.SERVICE_DEFINITION, callback);
	}

	void Subscriber::init(std::string base_name, f_void_f callback) {
		// test sow there in not an error in set up for applicationServiceInterface
		if (!initApplicationServiceInterface(config)){
			fprintf(stderr, "unable to init applictionServiceInterface");
		}

		registerSensor(config, base_name);
		Subscriber::callback = callback;
		this -> base_name = base_name;
	
	}

	/*
	--
	-- Called, when publisher POST msgs arrives -- HTTP POST
	-- @orverride
	*/
	int Subscriber::callbackServerHttpPOST(const char *url, 
					const char *payload) {
		callback(url, payload);	
		return 1;
	}
}
