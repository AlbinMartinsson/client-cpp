#include "Provider.h"

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
		//////////////////////////////////
		// check sow it it a valid msgs //
		//////////////////////////////////
		if(msgs == NULL){
			fprintf(stderr, "Error: Could not parse SenML: %s\n", 
							json_object_get_string(msgs));
			return false;
		}

		 json_object *jBN;
		if(!json_object_object_get_ex(msgs, "ServiceName", &jBN)) {
			fprintf(stderr, "Error: received json does not contain ServiceName field!\n");
			return false;
		}

		std::string bn = std::string(json_object_get_string(jBN));

		if(bn != config.SERVICE_NAME) {
			fprintf(stderr, "baseNames don not match: %s != %s\n", 
							bn.c_str(), config.SERVICE_NAME.c_str());
			return false;
		}
		///////////////
		// check end //
		///////////////
		
		// if sensor is register is a new msgs set
		if (sensorIsRegistered) {
			this -> msgs = msgs;
			printf("New measurement received from: %s\n", 
						this -> config.SERVICE_NAME.c_str());
			printf("LastValue updated.\n");
			return true;
		}
		return false;
	}


	// @override
	int Provider::callbackServerHttpGET(const char *URL, 
						std::string *data_stre) {

		if (or_callback)
			return callback(URL, data_stre);
			
    	printf("\nHTTP GET request received\n");

  	 	printf("Received URL: %s\n", URL);
    	std::string tmp = "/" + this -> config.SERVICE_URI;
		// test sow the request has arived at the correct place 
		if (strcmp(tmp.c_str(), URL) != 0) {
			fprintf(stderr, "Error: Unknown URL: %s\n", URL);
			return 1;
		}
		
    	 *data_stre= json_object_get_string(msgs);
	     printf("Response:\n%s\n\n", data_stre->c_str());

		return 1;
	}

}
