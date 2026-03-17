cmake_minimum_required(VERSION 3.16)

project(OOP_lab_01_01_NEW LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOP_lab_01_01_NEW main.cpp
    Point.h
    Figure.h
    Circle.h Circle.cpp
    Rectangle.h Rectangle.cpp
    Triangle.h Triangle.cpp
    FigureType.h
    FigureParameters.h
    FigureFactory.h
    TriangleFactory.h
    CircleFactory.h
    RectangleFactory.h
    FactoryRegistry.h
    FigureCollection.h
    InputReader.h
    OutputPrinter.h
    AppController.h
    CircleFactory.cpp
    RectangleFactory.cpp
    TriangleFactory.cpp
    FactoryRegistry.cpp
    FigureCollection.cpp
    InputReader.cpp
    OutputPrinter.cpp
    AppController.cpp
    Point.cpp
    Figure.cpp)

include(GNUInstallDirs)
install(TARGETS OOP_lab_01_01_NEW
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
