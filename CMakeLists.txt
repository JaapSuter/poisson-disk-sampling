# Copyright (C) 2018 Tommy Hinks <tommy.hinks@gmail.com>
# This file is subject to the license terms in the LICENSE file
# found in the top-level directory of this distribution.

cmake_minimum_required(VERSION 3.1)
project(poisson_disk_sampling)

set(header_files
	${CMAKE_CURRENT_SOURCE_DIR}/include/thinks/poisson_disk_sampling/poisson_disk_sampling.h
)
add_library(thinks_poisson_disk_sampling INTERFACE)
target_sources(thinks_poisson_disk_sampling INTERFACE ${header_files})
target_include_directories(thinks_poisson_disk_sampling SYSTEM INTERFACE include/)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    enable_testing()
    add_subdirectory(test)
    add_subdirectory(examples)
endif()