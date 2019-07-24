#include "gtest/gtest.h"
#include "../include/Provider.h"
#include <iostream>

TEST(json_core, testcase1){
	arrowhead::Provider prov;
	std::string s = "test_example.json";
	//config.lood(s);
	//ASSERT_EQ("http://localhost:port/orchaORservis", config.ACCESS_URI);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return 1;
}
