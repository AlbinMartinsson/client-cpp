#include "Provider.h"
#include "ErrorPrevention.h"

#ifdef __linux__
     #include "iniparser.h"
#elif _WIN32
     extern "C" {
     #include "iniparser.h"
     }
#endif

namespace arrowhead{
		
	Provider::Provider(){}
	Provider::~Provider(){}

	Provider::Provider(std::string file_path) {
		config.load(file_path);
		init();
	}

	Provider::Provider(std::string file_path, f_int_f callback) : Provider(file_path) {
		or_callback = true;
		this -> callback = callback; 
	}
	
	bool Provider::init() {
		// test sow there in not an error in set up for applicationServiceInterface
		if (!initApplicationServiceInterface(config)) {
			fprintf(stderr, "unable to init applictionServiceInterface");
			return false;
		}

		
		// register in the service register
		if(!registerSensor(config)) {
			fprintf(stderr, "cod not register sensor!\n");
			return false;
		}
	
		return true;
	}
	
	bool Provider::setMsgs(json_object *msgs) {
		if(!ErrorPrevention::correctService(msgs,config.SERVICE_NAME)) 
			return false;

		// if sensor is register is a new msgs set
		if (sensorIsRegistered) {
			this -> msgs = msgs;
			printf("New measurement received from: %s\n", 
						config.SERVICE_NAME.c_str());
			printf("megs updated.\n");
			return true;
		}
		return false;
	}


	// @override
	int Provider::callbackServerHttpGET(const char *URL, 
						std::string *data_stre) {

		if (!ErrorPrevention::correctURI(URL, config.SERVICE_URI))
				return 0;

		// if a user callback are used use it
		// return eminently after
		if (or_callback)
			return callback(URL, data_stre);
			
		// if no user define callback
		// return msgs
    	printf("\nHTTP GET request received\n");

  	 	printf("Received URL: %s\n", URL);
		
    	 *data_stre= json_object_get_string(msgs);
	     printf("Response:\n%s\n\n", data_stre->c_str());

		return 1;
	}

}
