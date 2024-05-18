# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Kinematics_Arm_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Kinematics_Arm_autogen.dir/ParseCache.txt"
  "Kinematics_Arm_autogen"
  )
endif()
