#pragma once

#include <zephyr/fs/fs.h>
#include <ff.h>

#include "../FileSystem.hpp"

class FatFileSystem : public FileSystem {
   public:
    FatFileSystem();

	void format() override;
    void mount(const std::string &mount_point) override;
	void unmount() override;

   private:
    FATFS fat_fs;
    struct fs_mount_t mp;
};