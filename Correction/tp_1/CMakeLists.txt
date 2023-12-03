# Project #-----------------------------------------------------------------------------------------
cmake_minimum_required ( VERSION 3.18 )

project ( tp1 CXX )

# C++ Standard #------------------------------------------------------------------------------------
set ( CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_STANDARD 17 )

# GNU C++ Options #---------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic ${CMAKE_CXX_FLAGS}" )
endif ()

# Sources #-----------------------------------------------------------------------------------------
set ( PROJECT_HEADERS
      src/cartesien.hpp
      src/nuage.hpp
      src/point.hpp
      src/polaire.hpp
      src/vecteur.hpp
    )

set ( PROJECT_SOURCES
      src/cartesien.cpp
      src/nuage.cpp
      src/point.cpp
      src/polaire.cpp
      src/vecteur.cpp
    )

set ( TEST_HEADERS
      test/catch.hpp
    )

set ( TEST_SOURCES
      test/catch.cpp
    )

# Common Library #----------------------------------------------------------------------------------
add_library ( common OBJECT )

target_sources ( common
	               PRIVATE ${PROJECT_SOURCES}
	               PUBLIC ${PROJECT_HEADERS}
               )

target_include_directories( common PUBLIC src )

# Test Library #------------------------------------------------------------------------------------
add_library( test OBJECT )

target_sources ( test
	               PRIVATE ${TEST_SOURCES}
	               PUBLIC ${TEST_HEADERS}
               )

# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}_point src/main_point.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_point PRIVATE common )

add_executable ( ${CMAKE_PROJECT_NAME}_vecteur src/main_vecteur.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_vecteur PRIVATE common )

add_executable ( ${CMAKE_PROJECT_NAME}_test test/${CMAKE_PROJECT_NAME}_test.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_test PRIVATE common test )
