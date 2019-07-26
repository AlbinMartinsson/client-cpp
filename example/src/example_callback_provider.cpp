#include "arrowhead/Provider.h"
#include "iostream"
#include <ctime>
#include <json-c/json.h>
#ifdef __linux__
     #include "arrowhead/iniparser.h"
#elif _WIN32
     extern "C" {
     #include "arrowhead/iniparser.h"
     }
#endif

int callback(const char *URL, std::string *return_data);

// construct an arrowhead instance of type provider
arrowhead::Provider provider("callback_provider.json", callback);
int i = 0;

// json msgs structure
// { 
// 	"ServiceName": "counter_example", 
// 	"Entity": [ { 
// 		"count": 4, 
// 		"Time_stamp": 1564040190 
// 		"Unit": "int" 
// 	} ], 
// }
json_object* msgs(int value, std::string id, std::string unit){
	
	json_object* obj = json_object_new_object();	
	json_object *arr_obj = json_object_new_array();
	json_object *arr_cont = json_object_new_object();

	json_object_object_add(arr_cont,"count", json_object_new_int(value));
	json_object_object_add(arr_cont,"Time_stamp", json_object_new_int(std::time(0)));
	json_object_object_add(arr_cont,"Unit", json_object_new_string(unit.c_str()));
	json_object_array_add(arr_obj, arr_cont);
	
	json_object_object_add(obj,"ServiceName", json_object_new_string(id.c_str()));
	json_object_object_add(obj,"Entity", arr_obj);

	return obj;
}

// these function is triggered when a request is received
int callback(const char *URL, std::string *return_data) {
    	printf("\nCallback trigged \n");
  	 	printf("Received URL: %s\n", URL);
	
		// it is these messages that will be returned to the consumer.
    	 *return_data = json_object_get_string(msgs(i++, 
								 provider.config.SERVICE_NAME, 
								 provider.config.UNIT));

	     printf("Response:\n%s\n\n", return_data->c_str());

	return 1;
}


int main(int argc, char* argv[]){
	// print settings for debugging
	provider.config.print();

	// wait for interrupts from get requests
	while(true) {
		sleep(500);
	}

	return 1;
}
