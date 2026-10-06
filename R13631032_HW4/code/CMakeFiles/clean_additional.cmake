# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\HW4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HW4_autogen.dir\\ParseCache.txt"
  "HW4_autogen"
  )
endif()
