cmake_minimum_required(VERSION 3.10)
project(wxApp)

set(CMAKE_CXX_STANDARD 17)

# Allow selecting wx-config manually
set(wxWidgets_CONFIG_EXECUTABLE "" CACHE FILEPATH "Path to wx-config")

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(app src/main.cpp)
target_link_libraries(app ${wxWidgets_LIBRARIES})