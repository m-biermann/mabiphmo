# 'Boost_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable (httpServerTests test1.cpp)
target_link_libraries (httpServerTests PRIVATE ${Boost_LIBRARIES} httpServer)
target_include_directories(httpServerTests PRIVATE ${Boost_INCLUDE_DIRS})