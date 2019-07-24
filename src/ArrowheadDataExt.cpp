#include "ArrowheadDataExt.h"
#include <fstream>

// Convert boolean ("x") to string "true"/"false"
// required to print booleans ass string
#define b2s(x) ((x)?"true":"false")

namespace arrowhead{
	
	ArrowheadDataExt::ArrowheadDataExt(){}
	ArrowheadDataExt::~ArrowheadDataExt(){}

	void ArrowheadDataExt::print(){
		printf("The set params\n");
		printf("Service settings\n");
		printf("SERVICE_DEFINITION: %s\n", SERVICE_DEFINITION.c_str());
		printf("INTERFACE: %s\n", INTERFACE.c_str());
		printf("SERVICE_URI: %s\n", SERVICE_URI.c_str());
		printf("UNIT : %s\n", UNIT.c_str());
		printf("SECURITY: %s\n", SECURITY.c_str());
	
		printf("Core conection\n");
		printf("ACCESS_URI: %s\n", ACCESS_URI.c_str());
		printf("ACCESS_URI_HTTPS: %s\n", ACCESS_URI_HTTPS.c_str());
	
		printf("Orchestrator settings\n");
		printf("OVERRIDE_STORE: %s\n", b2s(OVERRIDE_STORE));
		printf("MATCHMAKING: %s\n", b2s(MATCHMAKING));
		printf("METADATA_SEARCH: %s\n", b2s(METADATA_SEARCH));
		printf("PING_PROVIDERS: %s\n", b2s(PING_PROVIDERS));
		printf("ONLY_PREFERRED: %s\n", b2s(ONLY_PREFERRED));
		printf("EXTERNAL_SERVICE_REQUEST: %s\n",
						b2s(EXTERNAL_SERVICE_REQUEST));

		printf("This procomer\n");
		printf("THIS_SYSTEM_NAME: %s\n", THIS_SYSTEM_NAME.c_str());
		printf("THIS_ADDRESS: %s\n", THIS_ADDRESS.c_str());
		printf("THIS_ADDRESS6: %s\n", THIS_ADDRESS6.c_str());
		printf("THIS_PORT: %i\n", THIS_PORT);
		
		printf("Target provomer\n");
		printf("TARGET_SYSTEM_NAME: %s\n", TARGET_SYSTEM_NAME.c_str());
		printf("TARGET_ADDRESS: %s\n", TARGET_ADDRESS.c_str());
		printf("TARGET_PORT: %i\n", TARGET_PORT);
		
		printf("securety\n");
		printf("PUBLIC_KEY_PATH: %s\n", PUBLIC_KEY_PATH.c_str());
		printf("PRIVATE_KEY_PATH: %s\n", PRIVATE_KEY_PATH.c_str());
		printf("AUTHENTICATION_INFO: %s\n", AUTHENTICATION_INFO.c_str());
		printf("SECURE_ARROWHEAD_INTERFACE: %s\n", 
						b2s(SECURE_ARROWHEAD_INTERFACE));
		printf("SECURE_PROVIDER_INTERFACE: %s\n", 
						b2s(SECURE_PROVIDER_INTERFACE));
	}


	void ArrowheadDataExt::lood(std::string file_path){
		std::ifstream input_file;
		std::string line;
		input_file.open(file_path);

		if(!input_file.good()) {
			fprintf(stderr, "Error, cant open file %s\n", file_path.c_str());
			input_file.close();
			return;
		}

		std::string content;
		int number_of_open = 0;
		
		while (std::getline(input_file, line)) {
			if (line.size() < 1) continue;

			number_of_open += line.find("{") != std::string::npos;
			number_of_open -= line.find("}") != std::string::npos;

			content += line;

			if (number_of_open == 0) {
				set(content);
				content = "";
			}
		}
		input_file.close();
	}


	void ArrowheadDataExt::set(std::string settings) {
		json_object *obj = json_tokener_parse(settings.c_str());

		json_object *section;
		if(json_object_object_get_ex(obj, "core", &section)) {
			setCore(section);
		}

		if(json_object_object_get_ex(obj, "orchestration_flags", &section)) {
			setOrchestration(section);
		}

		if(json_object_object_get_ex(obj, "this_system", &section)) {
			setThis(section);
		}

		if(json_object_object_get_ex(obj, "target_system", &section)) {
			setTarget(section);
		}
		
		if(json_object_object_get_ex(obj, "service", &section)) {
			setService(section);
		}
	}

	void ArrowheadDataExt::setCore(json_object *core) {
		ACCESS_URI = getString("access_uri", core);
		SECURE_ARROWHEAD_INTERFACE = getBool("secure_arrowhead_interface", core);
		SECURE_ARROWHEAD_INTERFACE = getBool("secure_provider_interface", core);
		PUBLIC_KEY_PATH = getString("public_key_path", core);
		PRIVATE_KEY_PATH = getString("private_key_path", core);
		AUTHENTICATION_INFO = getString("authentication_info", core);
	}
	
	void ArrowheadDataExt::setOrchestration(json_object* orchestration) {
		OVERRIDE_STORE = getBool("override_store", orchestration);
		MATCHMAKING = getBool("matchmaking", orchestration);
		METADATA_SEARCH = getBool("metadata_search", orchestration);
		PING_PROVIDERS = getBool("ping_providers", orchestration);
		ONLY_PREFERRED = getBool("only_preferred", orchestration);
		EXTERNAL_SERVICE_REQUEST = getBool("external_service_request", orchestration);
	}
	
	void ArrowheadDataExt::setThis(json_object *this_system) {
		THIS_SYSTEM_NAME = getString("this_name", this_system);
		THIS_ADDRESS = getString("this_address", this_system);
		THIS_ADDRESS6 = getString("this_address6", this_system);
		THIS_PORT = getInt("this_port", this_system);
	}
	
	void ArrowheadDataExt::setTarget(json_object *target_system) {
		TARGET_SYSTEM_NAME = getString("target_name", target_system);
		TARGET_ADDRESS = getString("target_address", target_system);
		TARGET_PORT = getInt("target_port", target_system);
	}
	
	void ArrowheadDataExt::setService(json_object *service) {
		SERVICE_DEFINITION = getString("service_name", service);
		SERVICE_URI = getString("service_uri", service);
		INTERFACE = getString("interface", service);
		SECURITY = getString("security", service);
		UNIT = getString("unit", service);
	}

	std::string ArrowheadDataExt::getString(std::string name, json_object *src) {

		json_object *uri;
		json_object_object_get_ex(src, name.c_str(), &uri);
		return json_object_get_string(uri);
	}

	bool ArrowheadDataExt::getBool(std::string name, json_object *src) {
		json_object *uri;
		json_object_object_get_ex(src, name.c_str(), &uri);
		return json_object_get_boolean(uri);
	}

	int ArrowheadDataExt::getInt(std::string name, json_object *src) {
		json_object *uri;
		json_object_object_get_ex(src, name.c_str(), &uri);
		return json_object_get_int(uri);
	}
}
