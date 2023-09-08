cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(fs_module_samples_format LANGUAGES C)

target_sources(app PRIVATE
	src/main.cpp
)