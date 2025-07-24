cmake_minimum_required(VERSION 3.16)
project(QGobang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)

qt_standard_project_setup()

# 添加子模块目录
add_subdirectory(QGobangClient)
add_subdirectory(QGobangServer)
add_subdirectory(QGobangTool)
