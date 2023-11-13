# Project #-----------------------------------------------------------------------------------------
cmake_minimum_required ( VERSION 3.18 )

project ( tp4 CXX )

# C++ Standard #------------------------------------------------------------------------------------
set ( CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_STANDARD 17 )

# GNU C++ Options #---------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -g -Og ${CMAKE_CXX_FLAGS}" )
endif ()

# Sources #-----------------------------------------------------------------------------------------
set ( PROJECT_HEADERS
      src/carte.hpp
      src/complexe.hpp
      src/consommateur.hpp
      src/mouchard.hpp
      src/paquet.hpp
      src/ressource.hpp
      src/usine.hpp
      src/vecteur.hpp
    )

set ( PROJECT_SOURCES
      src/carte.cpp
      src/paquet.cpp
      src/ressource.cpp
      src/usine.cpp
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
add_executable ( ${CMAKE_PROJECT_NAME}_mouchard test/test_mouchard.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_mouchard PRIVATE common )

add_executable ( ${CMAKE_PROJECT_NAME}_vecteur test/test_vecteur.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_vecteur PRIVATE common )

add_executable ( ${CMAKE_PROJECT_NAME}_test test/${CMAKE_PROJECT_NAME}_test.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_test PRIVATE common test )
