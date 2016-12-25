cmake_minimum_required(VERSION 2.6)
project (libserver)
file(GLOB networking
  "${PROJECT_SOURCE_DIR}/networking/*.h",
  "${PROJECT_SOURCE_DIR}/networking/*.c"
)

file(GLOB multiplexers
  "${PROJECT_SOURCE_DIR}/multiplexers/*.h",
  "${PROJECT_SOURCE_DIR}/multiplexers/*.c"
)

#include_directories(${PROJECT_SOURCE_DIR}, ${PROJECT_SOURCE_DIR}/networking)
add_executable(main main.c ${networking})
