# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(example_provider)


enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(PROJECT_LINK_LIBS libarrowhead_cpp.so)
link_directories(/usr/local/lib/)

set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(example_provider 
	src/example_provider.cpp
)

target_link_libraries(example_provider 
	${PROJECT_LINK_LIBS}
	json-c
)

add_executable(example_consumer 
	src/example_consumer.cpp
)

target_link_libraries(example_consumer 
	${PROJECT_LINK_LIBS}
	json-c
)

add_executable(example_publisher 
	src/example_publisher.cpp
)

target_link_libraries(example_publisher 
	${PROJECT_LINK_LIBS}
	json-c
)

add_executable(example_subscriber 
	src/example_subscriber.cpp
)

target_link_libraries(example_subscriber 
	${PROJECT_LINK_LIBS}
	json-c
)

add_executable(example_callback_provider 
	src/example_callback_provider.cpp
)

target_link_libraries(example_callback_provider 
	${PROJECT_LINK_LIBS}
	json-c
)

add_executable(example_callback_consumer 
	src/example_callback_consumer.cpp
)

target_link_libraries(example_callback_consumer 
	${PROJECT_LINK_LIBS}
	json-c
)

add_executable(uTest test/test_arrowheadDataExt.cpp)

target_link_libraries(uTest 
		${GTEST_LIBRARIES} 
		${PROJECT_LINK_LIBS}
		pthread)

add_test(testcase1 uTest)

# %EndTag(FULLTEXT)%
