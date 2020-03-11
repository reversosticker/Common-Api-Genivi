project(fradal)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen
    /home/mihup/fradal/capicxx-core-runtime/include
    /home/mihup/fradal/capicxx-dbus-runtime/include
    /home/mihup/fradal/dbus-1.10.10
)
link_directories(
    /home/mihup/fradal/capicxx-core-runtime/build
    /home/mihup/fradal/capicxx-dbus-runtime/build
    /home/mihup/fradal/dbus-1.10.10/dbus/.libs
)
add_executable(HelloWorldClient
	src/HelloWorldClient.cpp
	src-gen/v1/commonapi/HelloWorldDBusProxy.cpp
	src-gen/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-DBus dbus-1)
add_executable(HelloWorldService
	src/HelloWorldService.cpp
	src/HelloWorldStubImpl.cpp
	src-gen/v1/commonapi/HelloWorldDBusStubAdapter.cpp
	src-gen/v1/commonapi/HelloWorldStubDefault
	src-gen/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-DBus dbus-1)
