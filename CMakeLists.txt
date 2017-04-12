cmake_minimum_required(VERSION 2.8)
project(phw-bot)

file(GLOB SRCS
        "src/*.cpp"
        "src/*.hpp"
)

SET(EXECUTABLE_OUTPUT_PATH bin)
SET(OpenCV_DIR build/opencv)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} build/opencv/)
find_package( OpenCV REQUIRED )
add_executable(phw-bot ${SRCS})
target_link_libraries(phw-bot ${OpenCV_LIBS})