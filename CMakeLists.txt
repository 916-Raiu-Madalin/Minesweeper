cmake_minimum_required(VERSION 3.17)
project(e3_916_Raiu_Madalin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
include_directories(.)

add_executable(e3_916_Raiu_Madalin
        Domain.cpp
        Domain.h main.cpp Controller.cpp Controller.h Observer.cpp Observer.h Repository.cpp Repository.h Window.cpp Window.h TableModel.cpp TableModel.h)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")
find_package(Qt5Widgets REQUIRED)
target_link_libraries(e3_916_Raiu_Madalin Qt5::Widgets)