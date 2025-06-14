cmake_minimum_required (VERSION 3.10)
project (libvdpau-va-gl)
add_definitions(-std=gnu99 -Wall -fvisibility=hidden -fPIC)

find_package(PkgConfig REQUIRED)
find_package(X11 REQUIRED)
pkg_check_modules(GLIB20     glib-2.0   REQUIRED)
pkg_check_modules(LIBVA      libva-x11  REQUIRED)
pkg_check_modules(LIBSWSCALE libswscale REQUIRED)
pkg_check_modules(GL         gl glu     REQUIRED)

set(DRIVER_NAME "vdpau_va_gl" CACHE STRING "driver name")
set(LIB_SUFFIX "" CACHE STRING "library path suffix (if needed)")
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/vdpau" CACHE PATH "library installation path")

include_directories (
	${X11_INCLUDE_DIRS}
	${VDPAU_INCLUDE_DIRS}
	${GLIB20_INCLUDE_DIRS}
	${LIBVA_INCLUDE_DIRS}
	${LIBSWSCALE_INCLUDE_DIRS}
	${GL_INCLUDE_DIRS}
	${GENERATED_INCLUDE_DIRS}
	${CMAKE_BINARY_DIR}
	src
)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
add_custom_target(build-tests)
add_dependencies(check build-tests)
add_subdirectory(glsl)
enable_testing()
add_subdirectory(tests)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory(src)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INSTALL_PREFIX /usr/local)
