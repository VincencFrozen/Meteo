# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

target_include_directories(app PRIVATE . PRIVATE src/)

# TODO: List into variable and add separate CmakeLists into src folder
target_sources(app PRIVATE src/main.cpp)
target_sources(app PRIVATE src/anemometer.cpp)
target_sources(app PRIVATE src/windlogic.cpp)
