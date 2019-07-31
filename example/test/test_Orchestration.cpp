#include "gtest/gtest.h"
#include "arrowhead/OrchestratorInterface.h"
#include "arrowhead/ArrowheadDataExt.h"
#include "json-c/json.h"

class TestClas : arrowhead::OrchestratorInterface {
	public:	
	arrowhead::ArrowheadDataExt ahDE;
	//arrowhead::OrchestratorInterface orch;
	json_object* obj;
	
	void setup() {
		ahDE.load("test_example.json");
		getOrchetrationRequestForm(obj, ahDE);
	}
};

TEST(Orchestation, orch0) {
	std::string control = "{ \"requesterSystem\": { \"systemName\": \"the_name_of_these_system\", \"address\": \"local_address\", \"port\": 8460, \"authenticationInfo\": \"\" }, \"requestedService\": { \"serviceDefinition\": \"service_name\", \"interfaces\": [ \"JSON\" ], \"serviceMetadata\": { \"security\": \"token\" } }, \"orchestrationFlags\": { \"overrideStore\": true, \"matchmaking\": true, \"metadataSearch\": false, \"pingProviders\": false, \"onlyPreferred\": true, \"externalServiceRequest\": false }, \"preferredProviders\": [ { \"providerSystem\": { \"systemName\": \"name_of_target_system\", \"address\": \"target_system_address\", \"port\": 8462 } } ] }";

	TestClas testClass;
	testClass.setup();

	ASSERT_EQ(control, std::string(json_object_get_string(testClass.obj)));
}
