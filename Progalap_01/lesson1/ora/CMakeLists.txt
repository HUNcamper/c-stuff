cmake_minimum_required(VERSION 3.16)

project(global-lesson1-ora)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC
        src/ora.c)

# Files from `./test` directory
set(TEST
        test/test.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
add_executable(${PROJECT_NAME}-run ${SRC})

# Running tests
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
configure_test_target(${PROJECT_NAME}-test ${SRC} ${TEST})