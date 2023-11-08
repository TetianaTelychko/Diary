cmake_minimum_required(VERSION 3.24)
project(Diary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/tatanatelicko/Qt/6.5.0/macos/lib/cmake/Qt6")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(Diary main.cpp
                       mainwindow.h mainwindow.cpp mainwindow.ui
                       category.h category.cpp
                       constants.h
                       datamodel.h datamodel.cpp
                       imagemanager.h imagemanager.cpp
                       mainwindowcontroller.h mainwindowcontroller.cpp
                       newcategorycontroller.h newcategorycontroller.cpp
                       newcategorywindow.h newcategorywindow.cpp
                       note.h note.cpp
                       notecontroller.h notecontroller.cpp
                       notewidget.h notewidget.cpp
                       notewindow.h notewindow.cpp
                       scrollablearea.h scrollablearea.cpp
                       resources.qrc
                )
target_link_libraries(Diary
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )

