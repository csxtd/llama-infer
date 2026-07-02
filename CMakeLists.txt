cmake_minimum_required(VERSION 3.16)

project(llama_infer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    source/*.cpp
)

add_executable(llama_infer
    ${SOURCES}
)

target_include_directories(llama_infer PRIVATE
    ${PROJECT_SOURCE_DIR}/include


)