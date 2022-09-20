
cmake_minimum_required (VERSION 3.6)

set(m_SOURCES_DIR "${PROJECT_SOURCE_DIR}/Source/")

project(Solution)

set(SOURCES
	Source/Main.cpp
    Source/Matrix.hpp
	Source/Vector3.hpp
    
)

add_executable (
    main ${SOURCES}
    
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)