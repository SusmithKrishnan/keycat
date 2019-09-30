cmake_minimum_required (VERSION 3.0)
project (KeyboardCat)
set (CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS}  -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
file (GLOB source_files "${source_dir}/*.cpp")
add_executable (kcat ${source_files})
install(TARGETS kcat DESTINATION bin)

