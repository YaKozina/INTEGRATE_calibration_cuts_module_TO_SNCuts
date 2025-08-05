# Check cmake version meets our requirements
cmake_minimum_required(VERSION 3.9)

# Declare project, which will configure compiler for us
project(SNCuts)

#Finds ROOT and Falaise packages and defines cmake variables
find_package(Falaise REQUIRED)
find_package(ROOT    REQUIRED)

include_directories(include ${Bayeux_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp" "src/dicts/*.cpp")
add_library(SNCuts SHARED ${SOURCES} )

target_link_libraries(SNCuts PUBLIC Falaise::FalaiseModule ${ROOT_LIBRARIES})  

install(TARGETS SNCuts DESTINATION ${CMAKE_INSTALL_PLUGINDIR})

configure_file("SNCutsPipeline.conf.in" "SNCutsPipeline.conf" @ONLY)
