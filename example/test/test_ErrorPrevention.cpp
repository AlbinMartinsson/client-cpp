#include "gtest/gtest.h"
#include "arrowhead/ErrorPrevention.h"
#include "json-c/json.h"

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

TEST(errorPrevention, error1){
	ASSERT_TRUE(arrowhead::ErrorPrevention::correctService(msgs(0,"correct", "x"), "correct"));
	ASSERT_FALSE(arrowhead::ErrorPrevention::correctService(msgs(0,"wrong", "x"), "else" ));
	json_object* emty = json_object_new_object();
	ASSERT_FALSE(arrowhead::ErrorPrevention::correctService(emty, "do not care"));
}

TEST(errorPrevention, errorr21){
	ASSERT_TRUE(arrowhead::ErrorPrevention::correctService(
				json_object_get_string(msgs(0,"correct", "x")), "correct"));

	ASSERT_FALSE(arrowhead::ErrorPrevention::correctService(
				json_object_get_string(msgs(0,"wrong", "x")), "else" ));

	json_object* emty = json_object_new_object();
	ASSERT_FALSE(arrowhead::ErrorPrevention::correctService(
				json_object_get_string(	emty), "do not care"));
}

TEST(ErrorPrevention, error3) {
	ASSERT_TRUE(arrowhead::ErrorPrevention::correctURI("/Correct", "Correct"));
	ASSERT_FALSE(arrowhead::ErrorPrevention::correctURI("/not", "Correct"));
}
