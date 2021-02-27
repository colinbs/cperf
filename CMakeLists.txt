project(CPERF C)

set(PROJECT_DESCRIPTION "Performance measurement utilities for C projects")

cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=gnu99")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -ggdb")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

include_directories(.)

set(CPERF_SRC cperf.c log.c)

# Create shared library
add_library(cperf SHARED ${CPERF_SRC})
target_link_libraries(cperf ${CPERF_LINK})

install(TARGETS cperf DESTINATION bin)

# Create static library
# add_library(bgpsecpg_static STATIC ${BGPSECPG_SRC})
# target_link_libraries(bgpsecpg_static ${BGPSECPG_LINK})

# Testing
#add_subdirectory(tests)
#enable_testing()
#add_test(test_bgpsec_structs tests/test_bgpsec_structs)
#add_test(test_generators tests/test_generators)
