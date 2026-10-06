cmake_minimum_required(VERSION 3.16)

project(hw6 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/msvc2022_64/lib/cmake/Qt6")

set(OpenCV_DIR "C:/Users/erica/opencv/build")
include_directories(${OpenCV_INCLUDE_DIRS} "C:/Users/erica/opencv/build/include")

include_directories(${OpenCV_INCLUDE_DIRS} "C:/Users/erica/opencv_contrib/modules")

find_package(OpenCV REQUIRED )
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)



qt_add_executable(hw6 MANUAL_FINALIZATION ${PROJECT_SOURCES})
qt_finalize_executable(hw6)

target_link_libraries(hw6 PRIVATE Qt6::Core Qt6::Widgets ${OpenCV_LIBS})
set_target_properties(hw6 PROPERTIES WIN32_EXECUTABLE TRUE)

include(GNUInstallDirs)
install(TARGETS hw6
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


