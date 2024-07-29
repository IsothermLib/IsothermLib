

cmake_minimum_required(VERSION 3.10)

project (    IsothermLib
             VERSION 1.0.1
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -fassociative-math -freciprocal-math -fno-signed-zeros -fno-trapping-math")

set ( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set ( ISOTHERMLIB_MODULE_LIB_NAME IsothermLib)

file   (   GLOB_RECURSE ISOTHERMLIB_MODULE_CXX src/*        )
file   (   GLOB_RECURSE ISOTHERMLIB_MODULE_HDR include/*    )

include_directories(${CMAKE_SOURCE_DIR}/IsothermLib/include)

add_library (   ${ISOTHERMLIB_MODULE_LIB_NAME}
                SHARED
                ${ISOTHERMLIB_MODULE_CXX}
                ${ISOTHERMLIB_MODULE_HDR}
                )



