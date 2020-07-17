cmake_minimum_required(VERSION 3.16)
project(LabDiPro)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
set(SOURCE_FILES chat.cpp user.cpp messageNotifier.cpp unreadMessageNotification.cpp)
add_executable(LabDiPro main.cpp)
add_library (core ${SOURCE_FILES})
target_link_libraries (LabDiPro core)