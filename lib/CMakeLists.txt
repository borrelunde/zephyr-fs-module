add_subdirectory(fat)

zephyr_library()
zephyr_library_sources(
	FileSystemException.cpp
	FileSystemFormatException.cpp
	FileSystemMountException.cpp
	FileSystemUnmountException.cpp
	IOException.cpp
)