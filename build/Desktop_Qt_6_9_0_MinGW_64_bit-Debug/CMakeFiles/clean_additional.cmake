# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MediaViewer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MediaViewer_autogen.dir\\ParseCache.txt"
  "MediaViewer_autogen"
  )
endif()
