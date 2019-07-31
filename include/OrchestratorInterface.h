#pragma once

#include "HttpHandler.h"
#include "HttpsHandler.h"
#include "ArrowheadDataExt.h"
#include <json-c/json.h>

namespace arrowhead{

// TODO split http and https parts
class OrchestratorInterface : HttpHandler, HttpsHandler {

private:

	std::string URI;
	
	// help functions to clean up code
	void jsonAddString(json_object* obj, std::string str, const char* name);
	void jsonAddInt(json_object* obj, int nr, const char* name);
	void jsonAddBool(json_object* obj, bool boolean, const char* name);

protected:
	std::string target_uri;

	std::string sConsumerID;

	OrchestratorInterface();
	~OrchestratorInterface();
	
	// GET or POST
	// to send/get msgs
	void sendRequestToProvider(std::string data, 
					std::string provider_uri, std::string method);
	
	// initialisation get a orchestration connection
	bool getOrchetrationRequestForm(json_object *&request_form,
									ArrowheadDataExt &config);
		
	int sendOrchestrationRequest(std::string rResult, ArrowheadDataExt *config);
	size_t callbackOrchestrationResponse(char *ptr, size_t size);

	// callback path for GET
	// @override
	size_t callbackGETHttp(char *ptr, size_t size);
	virtual size_t callbackRequest(const char *ptr, size_t size);

	
	size_t httpResponseCallback(char *ptr, size_t size);
	size_t httpsResponseCallback(char *ptr, size_t size);
};
}
