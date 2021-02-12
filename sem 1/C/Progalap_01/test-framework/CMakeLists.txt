cmake_minimum_required(VERSION 3.16)

project(googletest-download NONE)

include(ExternalProject)

ExternalProject_Add(
        googletest
        SOURCE_DIR "E:/Projects/C/Progalap_01/test-framework/googletest-src"
        BINARY_DIR "E:/Projects/C/Progalap_01/test-framework/googletest-build"
        GIT_REPOSITORY
            https://github.com/google/googletest.git
        GIT_TAG
            release-1.8.1
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
)
