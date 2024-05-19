cmake_minimum_required(VERSION 3.5)

project(Kinematics_Arm VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES Kinematics_Arm_en_GB.ts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    arm_sys.cpp
    arm_sys.h
    ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Kinematics_Arm
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Kinematics_Arm SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Kinematics_Arm
            ${PROJECT_SOURCES}
        )
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# 查找 pigpio 库
find_path(PIGPIO_INCLUDE_DIR pigpio.h)
find_library(PIGPIO_LIBRARY NAMES pigpio pigpiod_if2)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Pigpio DEFAULT_MSG PIGPIO_LIBRARY PIGPIO_INCLUDE_DIR)

if(PIGPIO_FOUND)
    set(PIGPIO_LIBRARIES ${PIGPIO_LIBRARY})
    set(PIGPIO_INCLUDE_DIRS ${PIGPIO_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Could not find Pigpio library")
endif()

# 链接 pigpio 库
target_include_directories(Kinematics_Arm PRIVATE ${PIGPIO_INCLUDE_DIRS})
target_link_libraries(Kinematics_Arm PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${PIGPIO_LIBRARIES})

set_target_properties(Kinematics_Arm PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Kinematics_Arm)
endif()
