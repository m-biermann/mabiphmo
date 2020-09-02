cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(httpServer src/main.cpp src/construction/AppBuilder.cpp src/construction/AppBuilder.h src/session/Session.cpp src/session/Session.h)

target_include_directories(httpServer PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}> PUBLIC ${Boost_INCLUDE_DIR})

target_link_libraries(httpServer PUBLIC ${PROJECT_NAME}::portServer)

add_library(${PROJECT_NAME}::httpServer ALIAS httpServer)

add_subdirectory(test)

include(GNUInstallDirs)
install(TARGETS httpServer
        EXPORT ${PROJECT_NAME}Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/mabiphmo TYPE INCLUDE)