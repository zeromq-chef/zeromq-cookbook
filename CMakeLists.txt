

#//////////////////////////////////////  < BEGIN >  ///////////////////////////////////////


# Require a minimum version of cmake.
cmake_minimum_required( VERSION 3.20.0 )


#----------------------------------------
#       0. check setting
#----------------------------------------
if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set( SHOW_DEBUG ON )
    add_definitions( -DDEBUG )
endif()

if ( NOT CMAKE_BUILD_TYPE )
    message(FATAL_ERROR, "CMAKE_BUILD_TYPE is empty")
    break()
endif()


#----------------------------------------
#       1. Solution
#----------------------------------------
project( ZeroMQ )


#----------------------------------------
#       1.1 Setup property of compiler
#----------------------------------------

# GNU C Compiler
if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
    set (CMAKE_CXX_STANDARD 11)     # C++11 for Linux
endif()

# Microsoft Visual Studio
if(${CMAKE_CXX_COMPILER_ID} MATCHES MSVC)
    set (CMAKE_CXX_STANDARD 11)     # C++11 for Windows

    # setup runtime library for MSVC
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


#----------------------------------------
#       2. Debug information
#----------------------------------------
if( SHOW_DEBUG )
    message( STATUS " ")
    message( STATUS "------------------------------------------------------------------------")
    message( STATUS " SOLUTION : ZeroMQ - ${CMAKE_BUILD_TYPE}"     )
    message( STATUS " Path     : ${CMAKE_CURRENT_SOURCE_DIR}"       )
    message( STATUS "------------------------------------------------------------------------")
    message( STATUS "Compiler"                                      )
    message( STATUS " - ID      \t: ${CMAKE_CXX_COMPILER_ID}"       )
    message( STATUS " - Version \t: ${CMAKE_CXX_COMPILER_VERSION}"  )
    message( STATUS " - Path    \t: ${CMAKE_CXX_COMPILER}"          )
endif()


#----------------------------------------
#       3. Sub-Project
#----------------------------------------

# add Chapter 00
set( PROJECT_FOLDER_NAME Chapter00 )
add_subdirectory( ${PROJECT_FOLDER_NAME} )


#//////////////////////////////////////  <  END  >  ///////////////////////////////////////

