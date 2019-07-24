#include "arrowhead/Provider.h"
#include "iostream"
#include <time.h>
#include <ctime>
#include <json-c/json.h>

json_object* msgs(int value, std::string id, std::string unit){
	
	json_object* obj = json_object_new_object();	
	json_object *arr_obj = json_object_new_array();
	json_object *arr_cont = json_object_new_object();

	json_object_object_add(arr_cont,"count", json_object_new_double(value));
	json_object_object_add(arr_cont,"Time_stamp", json_object_new_int(std::time(0)));
	json_object_array_add(arr_obj, arr_cont);
	json_object_object_add(obj,"Entity", arr_obj);
	json_object_object_add(obj,"BaseName", json_object_new_string(id.c_str()));
	json_object_object_add(obj,"Unit", json_object_new_string(unit.c_str()));

	return obj;
}


int main(int argc, char* argv[]){
	arrowhead::Provider provider("provider.json");
	provider.config.print();

	int i = 0;
	while(true) {
		provider.setMsgs(msgs(i++, provider.config.SERVICE_DEFINITION, 
								provider.config.UNIT));
		sleep(5);
	}

	return 1;
}
