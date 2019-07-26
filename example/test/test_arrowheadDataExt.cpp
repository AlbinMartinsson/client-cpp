#include "gtest/gtest.h"
#include "arrowhead/ArrowheadDataExt.h"
#include <iostream>

TEST(json_core, testcase1){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("http://localhost:port/orchaORservis", config.ACCESS_URI);
	ASSERT_NE("random", config.ACCESS_URI);
	ASSERT_NE("", config.ACCESS_URI);
}

TEST(json_core_sai, test2){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(config.SECURE_ARROWHEAD_INTERFACE);
	ASSERT_TRUE(!config.SECURE_ARROWHEAD_INTERFACE);
}

TEST(json_core_spi, test3){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(config.SECURE_PROVIDER_INTERFACE);
	ASSERT_TRUE(!config.SECURE_PROVIDER_INTERFACE);
}

TEST(json_core_pub, test4){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("a/absolute/path", config.PUBLIC_KEY_PATH);
	ASSERT_NE("random", config.PUBLIC_KEY_PATH);
	ASSERT_NE("", config.PUBLIC_KEY_PATH);
}

TEST(json_core_privat, test5){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("a/absolute/path", config.PRIVATE_KEY_PATH);
	ASSERT_NE("random", config.PRIVATE_KEY_PATH);
	ASSERT_NE("", config.PRIVATE_KEY_PATH);
}

TEST(json_orchestration_flags_os, test7){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(!config.OVERRIDE_STORE);
	ASSERT_TRUE(config.OVERRIDE_STORE);
}

TEST(json_orchestration_flags_m, test8){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(!config.MATCHMAKING);
	ASSERT_TRUE(config.MATCHMAKING);
}

TEST(json_orchestration_flags_ms, test9){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(config.METADATA_SEARCH);
	ASSERT_TRUE(!config.METADATA_SEARCH);
}

TEST(json_orchestration_flags_pp, test10){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(config.PING_PROVIDERS);
	ASSERT_TRUE(!config.PING_PROVIDERS);
}

TEST(json_orchestration_flags_op, test11){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(!config.ONLY_PREFERRED);
	ASSERT_TRUE(config.ONLY_PREFERRED);
}

TEST(json_orchestration_flags_esr, test12){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_FALSE(config.EXTERNAL_SERVICE_REQUEST);
	ASSERT_TRUE(!config.EXTERNAL_SERVICE_REQUEST);
}

TEST(json_this_name, test13){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("the_name_of_these_system", config.THIS_SYSTEM_NAME);
	ASSERT_NE("random", config.THIS_SYSTEM_NAME);
	ASSERT_NE("", config.THIS_SYSTEM_NAME);
}

TEST(json_this_address, test14){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("local_address", config.THIS_ADDRESS);
	ASSERT_NE("random", config.THIS_ADDRESS);
	ASSERT_NE("", config.THIS_ADDRESS);
}

TEST(json_this_port, test16){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ(8460, config.THIS_PORT);
	ASSERT_NE(6540, config.THIS_PORT);
	ASSERT_NE(0, config.THIS_PORT);
}

TEST(json_target_name, test17){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("name_of_target_system", config.TARGET_SYSTEM_NAME);
	ASSERT_NE("random", config.TARGET_SYSTEM_NAME);
	ASSERT_NE("", config.TARGET_SYSTEM_NAME);
}

TEST(json_target_address, test18){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("target_system_address", config.TARGET_ADDRESS);
	ASSERT_NE("random", config.TARGET_ADDRESS);
	ASSERT_NE("", config.TARGET_ADDRESS);
}

TEST(json_target_port, test19){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ(8462, config.TARGET_PORT);
	ASSERT_NE(6821, config.TARGET_PORT);
	ASSERT_NE(0, config.TARGET_PORT);
}

TEST(json_sevice_name, test20){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("service_name", config.SERVICE_NAME);
	ASSERT_NE("random", config.SERVICE_NAME);
	ASSERT_NE("", config.SERVICE_NAME);
}

TEST(json_sevice_uri, test21){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("custom_uri_for_id_in_system", config.SERVICE_URI);
	ASSERT_NE("random", config.SERVICE_URI);
	ASSERT_NE("", config.SERVICE_URI);
}

TEST(json_sevice_interface, test22){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("JSON", config.INTERFACE);
	ASSERT_NE("random", config.INTERFACE);
	ASSERT_NE("", config.INTERFACE);
}

TEST(json_sevice_security, test23){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("token", config.SECURITY);
	ASSERT_NE("random", config.SECURITY);
	ASSERT_NE("", config.SECURITY);
}

TEST(json_sevice_unit, test24){
	arrowhead::ArrowheadDataExt config;
	std::string s = "test_example.json";
	config.load(s);
	ASSERT_EQ("what_is_sent", config.UNIT);
	ASSERT_NE("random", config.UNIT);
	ASSERT_NE("", config.UNIT);
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return 1;
}
