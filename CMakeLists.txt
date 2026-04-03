cmake_minimum_required(VERSION 3.16)

project(OOP_lab_01_01_NEW LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOP_lab_01_01_NEW main.cpp
    point.h
    figure.h
    circle.h circle.cpp
    rectangle.h rectangle.cpp
    triangle.h triangle.cpp

    figureParameters.h
    figureFactory.h
    triangleFactory.h
    circleFactory.h
    rectangleFactory.h
    factoryRegistry.h
    figureCollection.h
    inputReader.h
    outputPrinter.h
    appController.h
    circleFactory.cpp
    rectangleFactory.cpp
    triangleFactory.cpp
    factoryRegistry.cpp
    figureCollection.cpp
    inputReader.cpp
    outputPrinter.cpp
    appController.cpp
    point.cpp
    figure.cpp
    appInterface.h
    appInterface.cpp
)

include(GNUInstallDirs)
install(TARGETS OOP_lab_01_01_NEW
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
