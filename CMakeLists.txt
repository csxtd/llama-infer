cmake_minimum_required(VERSION 3.16)

project(llama_infer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE LLAMA_INFER_SOURCES CONFIGURE_DEPENDS
    source/*.cpp
)

add_library(llama_infer_lib
    ${LLAMA_INFER_SOURCES}
)

target_include_directories(llama_infer_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    test/*.cpp
)

add_executable(llama_infer_tests
    ${TEST_SOURCES}
)

target_link_libraries(llama_infer_tests PRIVATE
    llama_infer_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(llama_infer_tests)
