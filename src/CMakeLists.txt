include_directories(
    ${GENERATED_INCLUDE_DIRS}
)

link_directories (
	${X11_LIBRARY_DIRS}
	${GLIB20_LIBRARY_DIRS}
	${LIBVA_LIBRARY_DIRS}
	${LIBSWSCALE_LIBRARY_DIRS}
	${GL_LIBRARY_DIRS}
)

add_library (${DRIVER_NAME}_obj OBJECT
	api-bitmap-surface.c
	api-csc-matrix.c
	api-device.c
	api-output-surface.c
	api-presentation-queue.c
	api-video-decoder.c
	api-video-mixer.c
	api-video-surface.c
	entry.c
	trace.c
	reverse-constant.c
	handle-storage.c
	bitstream.c
	h264-parse.c
	globals.c
	watermark.c
	ctx-stack.c
)

add_dependencies(${DRIVER_NAME}_obj shader-bundle)

add_library(${DRIVER_NAME} SHARED $<TARGET_OBJECTS:${DRIVER_NAME}_obj>)
add_library(${DRIVER_NAME}_static STATIC $<TARGET_OBJECTS:${DRIVER_NAME}_obj>)

set(LINK_LIBRARIES
	-lX11
	${GLIB20_LIBRARIES}
	${LIBVA_LIBRARIES}
	${LIBSWSCALE_LIBRARIES}
	${GL_LIBRARIES}
	-lpthread
	-lrt
	shader-bundle
)

target_link_libraries(${DRIVER_NAME} ${LINK_LIBRARIES})
target_link_libraries(${DRIVER_NAME}_static ${LINK_LIBRARIES})

set_target_properties(${DRIVER_NAME}
	PROPERTIES
	VERSION 1
)

install(TARGETS ${DRIVER_NAME} DESTINATION ${LIB_INSTALL_DIR})

set(CMAKE_BUILD_TYPE Release)
