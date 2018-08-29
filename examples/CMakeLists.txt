# Copyright (C) 2018 Tommy Hinks <tommy.hinks@gmail.com>
# This file is subject to the license terms in the LICENSE file
# found in the top-level directory of this distribution.

set(examples
	json_example.cc
)

add_executable(thinks_poisson_disk_sampling_examples
	main.cc
	${examples})
target_include_directories(thinks_poisson_disk_sampling_examples SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(thinks_poisson_disk_sampling_examples PUBLIC thinks_poisson_disk_sampling)
set_target_properties(thinks_poisson_disk_sampling_examples PROPERTIES CXX_STANDARD 11)