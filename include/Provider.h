#pragma once

#include "ArrowheadDataExt.h"
#include "ApplicationServiceInterface.h"
#include <json-c/json.h>

/*
 * These class is an access point to arrowhead framework.
 * Use these class when you desire a provider.
 *
 * Usages:
 * 1 create an instance of the class.
 * 2 set the params in ArrowheadDataExt.
 * 3 call init(...) to initialise the provider.
 * 4 call setMsgs(...) to set the msgs that will be returned,
 * when a consumer request it.
*/


namespace arrowhead{

	// for callback when request is received
	using f_int_f = int(*)(const char*, std::string*);

	class Provider : ApplicationServiceInterface {
	public:
		ArrowheadDataExt config;

		// different constructors for different behaviors
		Provider();
		Provider(std::string file_path);
		Provider(std::string file_path, f_int_f callback);
		~Provider();
	
		// initialize the system
		// config params need to be set prior to these
		bool init();
	
		// Set new msgs to be returned on a GET request
		bool setMsgs(json_object *msgs);
	
		// when a GET request is received
		// @override
		int callbackServerHttpGET(const char *id, 
						std::string *data_str);

	private:
		json_object *msgs;
		f_int_f callback;
		bool or_callback = false;
	};
}
