# readme.txt
# Created Time: 2015-11-12 11:01:39
# Last modified: 2016-04-13 20:27:09
#
cmake_minimum_required(VERSION 2.8)

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/app
	${PROJECT_SOURCE_DIR}/src/core
	${PROJECT_SOURCE_DIR}/src/core/association
	${PROJECT_SOURCE_DIR}/src/core/clustering
	${PROJECT_SOURCE_DIR}/src/core/dimen_reduction
	${PROJECT_SOURCE_DIR}/src/core/db
	${PROJECT_SOURCE_DIR}/src/core/tools
	${PROJECT_SOURCE_DIR}/src/core/test
	${PROJECT_SOURCE_DIR}/src/libs
	${PROJECT_SOURCE_DIR}/src/libs/jsoncpp/src
)

aux_source_directory(. SRC_LIST)
aux_source_directory(./app/ SRC_LIST)
aux_source_directory(./core/ SRC_LIST)
aux_source_directory(./core/association/ SRC_LIST)
aux_source_directory(./core/clustering/ SRC_LIST)
aux_source_directory(./core/db/ SRC_LIST)
aux_source_directory(./core/dimen_reduction/ SRC_LIST)
aux_source_directory(./core/tools/ SRC_LIST)
aux_source_directory(./core/test/ SRC_LIST)

add_executable(dataming-core ${SRC_LIST})

set(libs_path ${PROJECT_SOURCE_DIR}/src/libs)

set(link_lib
    ${libs_path}/libsqlite3.a
    pthread
    dl
    ${libs_path}/libjsoncpp.a
)

target_link_libraries(dataming-core ${link_lib})
