cmake_minimum_required(VERSION 3.8)
project(IceShaver)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 -Wall")

aux_source_directory(. SOURCE_FILES)
include_directories(./ ./MIPSResolver ./SuffixTreeResolver ./JAVAResolver)
add_subdirectory(MIPSResolver)
add_subdirectory(SuffixTreeResolver)
add_subdirectory(JAVAResolver)

add_executable(IceShaver ${SOURCE_FILES})
target_link_libraries(IceShaver MIPSResolver SuffixTreeResolver JAVAResolver)