cmake_minimum_required(VERSION 3.0.0)
project(nixFileTest LANGUAGES C VERSION 0.0.0)

add_executable(freeSpaceJson main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
