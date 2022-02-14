cmake_minimum_required(VERSION 3.10)
project(csample)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GST gstreamer-1.0 REQUIRED)
include_directories(${GST_INCLUDE_DIRS})
link_directories(${GST_LIBRARY_DIRS})

message(INFO " ${GST_INCLUDE_DIRS}")
message(INFO " ${GST_LIBRARIES}" )
message(INFO " ${GST_LIBRARY_DIRS}" )
message(INFO " ${GST_CXX_FLAGS}" )

#add_executable(tuto2 tuto2.c)
#add_executable(tuto7 tuto7.c)
#add_executable(tuto8 tuto8.c)
#add_executable(tuto9 tuto9.c)
#add_executable(tuto12 tuto12.c)
#add_executable(tuto13 tuto13.c)
#add_executable(tuto15 tuto15.c)
#add_executable(test test.c)

#add_executable(gstmyfilter gstmyfilter.c gstmyfilter.h config.h)
add_executable(test test.c)
#target_link_libraries(tuto2 ${GST_LIBRARIES})
target_link_libraries(test ${GST_LIBRARIES})
#target_link_libraries(tuto15 ${GST_LIBRARIES})

#add_executable(csample main.c tuto1.c tuto2.c tuto3.c tuto4.c
#        tuto5.c tuto6.c tuto7.c tuto8.c tuto9.c tuto12.c tuto13.c tuto15.c)
