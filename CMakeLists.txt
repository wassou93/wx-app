cmake_minimum_required(VERSION 3.10)
project(wxApp)

set(CMAKE_CXX_STANDARD 17)

# wxWidgets
set(wxWidgets_CONFIG_EXECUTABLE "" CACHE FILEPATH "Path to wx-config")

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Include headers
# include_directories(${CMAKE_SOURCE_DIR}/inc)

# Sources
set(SOURCES
    src/App.cpp
    src/MainFrame.cpp
)

add_executable(app ${SOURCES})

# more modern way to include directories
target_include_directories(app PRIVATE inc)

target_link_libraries(app ${wxWidgets_LIBRARIES})
