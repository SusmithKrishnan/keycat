cmake_minimum_required (VERSION 3.0)
project (KeyCat)
set (CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS}  -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
file (GLOB source_files "${source_dir}/*.cpp")
add_executable (keycat ${source_files})
install(TARGETS keycat DESTINATION bin)

