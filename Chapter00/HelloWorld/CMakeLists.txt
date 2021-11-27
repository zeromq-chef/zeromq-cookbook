
if( SHOW_DEBUG )
message( STATUS " ")
message( STATUS "----------------------------------------------------------------------")
message( STATUS " PROJECT      : ${PROJECT_FOLDER_NAME} - ${CMAKE_BUILD_TYPE}"          )
message( STATUS " Root    Dir. : ${CMAKE_SOURCE_DIR}"                                   )
message( STATUS " Current Dir. : ${CMAKE_CURRENT_SOURCE_DIR}"                           )
message( STATUS " Process file : ${CMAKE_CURRENT_LIST_FILE}"                            )
message( STATUS " Build   Dir. : ${CMAKE_CURRENT_BINARY_DIR}"                           )
message( STATUS "----------------------------------------------------------------------")
endif()

#//////////////////////////////////////  < BEGIN >  ///////////////////////////////////////


# Require a minimum version of cmake.
cmake_minimum_required( VERSION 3.20.0 )


#----------------------------------------
#       1. Project
#----------------------------------------
project( ${PROJECT_FOLDER_NAME} )


#----------------------------------------
#       2. Compiler
#----------------------------------------

# Include Directories
set ( INC_FOLDERS

    
)
include_directories( ${INC_FOLDERS} )

# Source Files
set ( SRC_FILES

    ./main.cpp
)

if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU)    # GNU C Compiler
    add_compile_options( -fPIC )                # PIC(Position Independent Code)    : http://www.jiniya.net/ng/2016/01/position-independent-code/
endif()

#----------------------------------------
#       3. Output
#----------------------------------------
add_executable( ${PROJECT_NAME}        ${SRC_FILES} )   # executable binary       (exe)


#//////////////////////////////////////  <  END  >  ///////////////////////////////////////

