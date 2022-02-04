
string(REPLACE "/" "_" PROJECT_FULL_NAME ${PROJECT_FOLDER_NAME})

if( SHOW_DEBUG )
message( STATUS " ")
message( STATUS "----------------------------------------------------------------------")
message( STATUS " PROJECT      : ${PROJECT_FULL_NAME} - ${CMAKE_BUILD_TYPE}"            )
message( STATUS " Root    Dir. : ${CMAKE_SOURCE_DIR}"                                   )
message( STATUS " Root    Dir. : ${PROJECT_FULL_NAME}"                                  )
message( STATUS " Current Dir. : ${CMAKE_CURRENT_SOURCE_DIR}"                           )
message( STATUS " Process file : ${CMAKE_CURRENT_LIST_FILE}"                            )
message( STATUS " Build   Dir. : ${CMAKE_CURRENT_BINARY_DIR}"                           )
message( STATUS " - libzmq     : ${LIB_ZMQ}"                                            )
message( STATUS "----------------------------------------------------------------------")
endif()

#//////////////////////////////////////  < BEGIN >  ///////////////////////////////////////


#----------------------------------------
#       1. Project
#----------------------------------------
project( ${PROJECT_FULL_NAME} )


#----------------------------------------
#       2. Target
#----------------------------------------
# Source Files
set ( SRC_FILES
    ./taskventilator.cpp
)

#----------------------------------------
#       2.1 Option
#----------------------------------------

if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU)    # GNU C Compiler
    add_compile_options( -fPIC )                # PIC(Position Independent Code)    : http://www.jiniya.net/ng/2016/01/position-independent-code/
endif()


#----------------------------------------
#       3. Output
#----------------------------------------
 add_executable( ${PROJECT_NAME}        ${SRC_FILES} )   # executable binary       (exe)


#----------------------------------------
#       3.1 link library
#----------------------------------------
target_link_libraries( ${PROJECT_NAME}
PRIVATE
    ${LIB_ZMQ}
)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_link_libraries( ${PROJECT_NAME}
    PRIVATE
        Ws2_32.lib
        Iphlpapi.lib
    )
endif()


#//////////////////////////////////////  <  END  >  ///////////////////////////////////////

