# readme.txt
# Created Time: 2016-02-26 17:02:51
# Last modified: 2016-02-26 17:42:07
#
cmake_minimum_required(VERSION 2.8)

project(dataming_core)

set(CMAKE_C_FLAGS "$ENV{CMAKE_C_FLAGS} -g -Wall")
set(CMAKE_CXX_FLAGS "$ENV{CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_subdirectory(src bin)

