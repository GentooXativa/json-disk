cmake_minimum_required(VERSION 3.0.0)
project(json_disk LANGUAGES C VERSION 0.0.0)

add_executable(json_disk main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
