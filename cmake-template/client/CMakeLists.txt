project(client)

set(CLIENT_ROOT "" CACHE PATH "Client source directories.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_INSTALL_BINDIR})

add_executable(
    client
    main.cc Client.hh
)

target_link_libraries(
    client
    PRIVATE zmq ${CMAKE_THREAD_LIBS_INIT}
)
