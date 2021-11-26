project(test)

set(GTEST_ROOT "" CACHE PATH "Google test directories.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_INSTALL_BINDIR})

add_executable(
    test
    main.cc
    Test.hh
)

target_link_libraries(
    test
    PRIVATE zmq gtest ${CMAKE_THREAD_LIBS_INIT}
)