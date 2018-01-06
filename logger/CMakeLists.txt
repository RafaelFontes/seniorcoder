cmake_minimum_required(VERSION 3.10)

project(sclogger VERSION 0.0.1 LANGUAGES CXX)

add_library(sclogger SHARED src/sclogger.cpp)

target_compile_definitions(sclogger PRIVATE
  PROPERTIES
  PROJECT_VERSION="${PROJECT_VERSION}"
  PROJECT_NAME=${CMAKE_PROJECT_NAME})

target_include_directories(sclogger PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE src)

target_compile_features(sclogger
  PRIVATE cxx_std_17)

install(
  TARGETS sclogger
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

enable_testing()
find_package(Threads)
find_package(PkgConfig)
find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  ${GMOCK_INCLUDE_DIRS}
)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(testscl
  test/sclogger.test.cpp)

target_link_libraries(testscl sclogger ${CMAKE_THREAD_LIBS_INIT} ${GTEST_BOTH_LIBRARIES})

add_test(AllTestsInfoSCL testscl)

