# Only include header files and add source files if the module is enabled.
if (CONFIG_FS_MODULE)

	# Include internal header files.
	zephyr_include_directories(include)

	# Add internal source files.
	add_subdirectory(lib)

endif()