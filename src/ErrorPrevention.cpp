#include "ErrorPrevention.h"
#include <iostream>

namespace arrowhead {

	ErrorPrevention::ErrorPrevention() {}
	ErrorPrevention::~ErrorPrevention() {}

	

	bool ErrorPrevention::correctService(json_object* obj, std::string SERVICE_NAME) {
		// check existent of ServiceName in obj
		json_object* jSN;
		if(!json_object_object_get_ex(obj, "ServiceName", &jSN)) {
			fprintf(stderr, "Error: no ServiceName field\n");
			return false;
		}

		// check sow it is the correct service name
		std::string sn = std::string(json_object_get_string(jSN));
		if(sn != SERVICE_NAME) {
			fprintf(stderr, 
					"Error: ServicName is not the expected!\n %s != %s\n"
					, sn.c_str(), SERVICE_NAME.c_str());
			return false;
		}
		return true;
	}

	bool ErrorPrevention::correctService(const char* str, std::string SERVICE_NAME) {
		return correctService(json_tokener_parse(str), SERVICE_NAME);
	}


	bool ErrorPrevention::correctURI(const char *URI, std::string expected) {
		if("/" + expected != std::string(URI)){
			fprintf(stderr, "Error: unexpected URI %s\n", URI);
			return false;
		}
		return true;
	}
}
