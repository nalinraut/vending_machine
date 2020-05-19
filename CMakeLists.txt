project(VendingMachine)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

set(sources src/main.cpp 
            src/vending_machine.cpp 
            src/vending_machine_implementation.cpp
            src/item.cpp
            src/cash.cpp
            src/exception.cpp
)



if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 
add_executable(VendingMachine ${sources})
