cmake_minimum_required(VERSION 3.20)

project(sudo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(/W4 /WX)

add_executable(${PROJECT_NAME}
    main.cpp
    )
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator'\" /SUBSYSTEM:WINDOWS")

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_BINARY_BIN})