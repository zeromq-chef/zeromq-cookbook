project(server)

set(CLIENT_ROOT "" CACHE PATH "Client source directories.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_INSTALL_BINDIR})

add_executable(
    server
    main.cc
    Server.hh
)

target_link_libraries(
    server
    PRIVATE zmq ${CMAKE_THREAD_LIBS_INIT}
)
