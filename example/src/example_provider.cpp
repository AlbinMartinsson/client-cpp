#include "arrowhead/Provider.h"
#include "iostream"
#include <time.h>
#include <ctime>
#include <json-c/json.h>

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


int main(int argc, char* argv[]){
	// construct an arrowhead instance of type provider
	arrowhead::Provider provider("provider.json");
	// print settings for debugging
	provider.config.print();

	int i = 0;
	while(true) {
		// update messages that will be returned 
		// when request from consumer arrive
		provider.setMsgs(msgs(i++, provider.config.SERVICE_NAME, 
								provider.config.UNIT));
		sleep(5);
	}

	return 1;
}
