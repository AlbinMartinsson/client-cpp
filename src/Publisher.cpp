#include "Publisher.h"
#include "ErrorPrevention.h"
#include <json-c/json.h>

namespace arrowhead{
 
	Publisher::Publisher(){}
	Publisher::~Publisher(){}
	Publisher::Publisher(std::string file_path) {
		config.load(file_path);
		init();
	}

	bool Publisher::init(){
		json_object *request_form;
		if(!getOrchetrationRequestForm(request_form, config)){
			fprintf(stderr, "Error: Request form is missing");
			return false;
		}
	
		printf("\nrequest form: %s\n", 
						json_object_get_string(request_form));
		printf("Sending Orchestration Request to: %s\n",
						config.SECURE_ARROWHEAD_INTERFACE ? 
							"Secure Arrowhead Interface" : 
							"Insecure Arrowhead Interface");

		// 200 implies success
		if(200 != sendOrchestrationRequest(
						json_object_get_string(request_form), &config)){
			fprintf(stderr, "can't connect to subscriber\n");
			return false;
		}
		return true;
	}

	void Publisher::publish(json_object *msgs){
		if(!ErrorPrevention::correctService(msgs, config.SERVICE_NAME))
			return;
		sendRequestToProvider(json_object_get_string(msgs), 
						this -> target_uri, "pub");
	}
}
