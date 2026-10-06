# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\hw6_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hw6_autogen.dir\\ParseCache.txt"
  "hw6_autogen"
  )
endif()
