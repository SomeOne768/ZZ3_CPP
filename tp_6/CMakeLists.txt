# Project #-----------------------------------------------------------------------------------------
cmake_minimum_required ( VERSION 3.18 )

project ( tp6 CXX )

# C++ Standard #------------------------------------------------------------------------------------
set ( CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_STANDARD 17 )

# Threads #-----------------------------------------------------------------------------------------
set ( CMAKE_THREAD_PREFER_PTHREAD TRUE )
set ( THREADS_PREFER_PTHREAD_FLAG TRUE )
find_package ( Threads REQUIRED )

# GNU C++ Options #---------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -pthread -fsanitize=thread ${CMAKE_CXX_FLAGS}" )
endif ()

# Sources #-----------------------------------------------------------------------------------------
set ( PROJECT_HEADERS
      src/nombre.hpp
      #src/boucle.hpp
    )

set ( PROJECT_SOURCES
    )

# Common Library #----------------------------------------------------------------------------------
add_library ( common OBJECT )

target_sources ( common
	               PRIVATE ${PROJECT_SOURCES}
	               PUBLIC ${PROJECT_HEADERS}
               )

target_include_directories( common PUBLIC src )


# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}_sequentiel src/sequentiel.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_sequentiel PRIVATE common Threads::Threads )

add_executable ( ${CMAKE_PROJECT_NAME}_parallele src/parallele.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_parallele PRIVATE common Threads::Threads )

add_executable ( ${CMAKE_PROJECT_NAME}_parallele2 src/parallele2.cpp )

target_link_libraries ( ${CMAKE_PROJECT_NAME}_parallele2 PRIVATE common Threads::Threads )
