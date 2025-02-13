cmake_minimum_required(VERSION 3.22.1)
# build script scope).
project("mycppproject")

add_library(
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        mycppproject
        SHARED
        native-lib.cpp
        src/StudentManager.cpp   # Tambahkan StudentManager.cpp agar dikenali
)

target_include_directories(
        mycppproject PRIVATE includes
)

find_library(
        log-lib.log
        log
)

target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        log
        ${log-lib}
)