cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(hello-cppzmq CXX)

# Use clang
set(CMAKE_C_COMPILER /bin/clang CACHE PATH "./")
set(CMAKE_CXX_COMPILER /bin/clang++ CACHE PATH "./")

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++2a")
set(CMAKE_CXX_FLGAS_DEBUG "-g")
set(CMAKE_CXX_FLGAS_RELEASE "-O3")

find_package(PkgConfig)
pkg_check_modules(PC_LIBZMQ QUIET libzmq)
set(ZeroMQ_VERSION ${PC_LIBZMQ_VERSION})

find_path(ZeroMQ_INCLUDE_DIR zmq.h
        PATHS ${ZeroMQ_DIR}/include
        ${PC_LIBZMQ_INCLUDE_DIRS})
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${ZeroMQ_DIR}/lib
        ${PC_LIBZMQ_LIBDIR}
        ${PC_LIBZMQ_LIBRARY_DIRS})

if(ZeroMQ_LIBRARY)
    set(ZeroMQ_FOUND ON)
endif()

set ( ZeroMQ_LIBRARIES ${ZeroMQ_LIBRARY} )
set ( ZeroMQ_INCLUDE_DIRS ${ZeroMQ_INCLUDE_DIR} )

if(NOT TARGET libzmq)
    add_library(libzmq UNKNOWN IMPORTED)
    set_target_properties(libzmq PROPERTIES
            IMPORTED_LOCATION ${ZeroMQ_LIBRARIES}
            INTERFACE_INCLUDE_DIRECTORIES ${ZeroMQ_INCLUDE_DIRS})
endif()

include ( FindPackageHandleStandardArgs )
# handle the QUIETLY and REQUIRED arguments and set ZMQ_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args ( ZeroMQ DEFAULT_MSG ZeroMQ_LIBRARIES ZeroMQ_INCLUDE_DIRS )

set(CPPZMQ_HEADERS
    zmq.hpp
    zmq_addon.hpp
)

find_package(Threads)

ADD_SUBDIRECTORY(server)
ADD_SUBDIRECTORY(client)
ADD_SUBDIRECTORY(test)
