# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\hw3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hw3_autogen.dir\\ParseCache.txt"
  "hw3_autogen"
  )
endif()
