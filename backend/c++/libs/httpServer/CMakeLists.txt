cmake_minimum_required(VERSION 3.16)
project(httpServer)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

include_directories(include)

add_library(httpServer include/mabiphmo/httpServer/construction/IAppBuilder.h src/main.cpp include/mabiphmo/httpServer/main.h src/construction/AppBuilder.cpp src/construction/AppBuilder.h include/mabiphmo/httpServer/handler/IHandler.h include/mabiphmo/httpServer/handler/IContextHandler.h include/mabiphmo/httpServer/handler/IHandlerContext.h include/mabiphmo/httpServer/handler/IRequestContext.h src/acceptor/AcceptorBase.cpp src/acceptor/AcceptorBase.h src/acceptor/ClearTextAcceptor.cpp src/acceptor/ClearTextAcceptor.h src/acceptor/SslAcceptor.cpp src/acceptor/SslAcceptor.h include/mabiphmo/httpServer/handler/Sender.h include/mabiphmo/httpServer/handler/HandlerResult.h src/session/Session.cpp src/session/Session.h)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(httpServer ${BOOST_LIB_DIR})

find_library(iocServer REQUIRED)
target_link_libraries(httpServer ${iocServer_LIB_DIR})

add_subdirectory(test)