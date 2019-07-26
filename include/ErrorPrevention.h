#include "json-c/json.h"
#include <iostream>

namespace arrowhead {

	class ErrorPrevention {
	private:
	public:
		ErrorPrevention();
		~ErrorPrevention();

		// check sow it is the intended service
		static bool correctService(json_object* obj, std::string SERVICE_NAME);
		static bool correctService(const char* str, std::string SERVICE_NAME);

		// check sow it it the correct URI to the service
		static bool correctURI(const char* URI, std::string expected);

	};
}
