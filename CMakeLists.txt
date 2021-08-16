cmake_minimum_required(VERSION 3.20)
project(wavestudio)

set(CMAKE_CXX_STANDARD 14)
if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    set(IMGUI_PATH /home/ben/Documents/repos/imgui)
    set(GL3W_PATH ${IMGUI_PATH}/examples/libs/gl3w)
    set(BACKENDS_PATH ${IMGUI_PATH}/backends)
    include_directories(/usr/include/SDL2/ ${GL3W_PATH} ${IMGUI_PATH} ${IMGUI_PATH}/backends)
    add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GL3W _REENTRANT)
endif ()

add_executable(wavestudio
        main.cpp
        ${GL3W_PATH}/GL/gl3w.c
        ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_PATH}/backends/imgui_impl_sdl.cpp
        ${IMGUI_PATH}/imgui.cpp
        ${IMGUI_PATH}/imgui_demo.cpp
        ${IMGUI_PATH}/imgui_draw.cpp
        ${IMGUI_PATH}/imgui_tables.cpp
        ${IMGUI_PATH}/imgui_widgets.cpp
        )
target_link_libraries(wavestudio SDL2 GL dl)

