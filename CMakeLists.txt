cmake_minimum_required(VERSION 3.10)
project(CommunicationBetweenThreads CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(communication_between_threads
    src/main.cpp
    src/Message.cpp
    src/Producer.cpp
    src/Consumer.cpp
)

target_include_directories(communication_between_threads PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
