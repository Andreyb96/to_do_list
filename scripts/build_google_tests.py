import platform
import os
import shutil
from distutils.dir_util import copy_tree

COMMON_LIBS_PATH = os.getcwd();
GOOGLE_TEST_PATH = COMMON_LIBS_PATH + '/googletest'
BUILD_PATH = GOOGLE_TEST_PATH + '/build'
SRC_LIB_DIR = COMMON_LIBS_PATH + '/googletest/build/lib/'
SRC_ICNLUDE_DIR = COMMON_LIBS_PATH + '/googletest/googletest/include'
TARGET_LIB_DIR = COMMON_LIBS_PATH + '/lib/GoogleTest'
TARGET_DEBUG_LIB_DIR = TARGET_LIB_DIR + '/Debug'
TARGET_RELEASE_LIB_DIR = TARGET_LIB_DIR + '/Release'
TARGET_ICNLUDE_DIR = COMMON_LIBS_PATH + '/include/GoogleTest'

if not os.path.exists(GOOGLE_TEST_PATH):
	os.system('git clone https://github.com/google/googletest.git -b release-1.10.0')
	os.chdir(GOOGLE_TEST_PATH)
	if not os.path.exists(BUILD_PATH):
		os.mkdir(BUILD_PATH)

	if platform.system() == 'Windows':
		os.system('cmake -B build -DCMAKE_GENERATOR_PLATFORM=x64 -Dgtest_force_shared_crt=ON -G "Visual Studio 15"')
		os.system('cmake --build build --config Release')
		os.system('cmake --build build --config Debug')

		if not os.path.exists(TARGET_DEBUG_LIB_DIR):
			copy_tree(SRC_LIB_DIR + "Debug", TARGET_DEBUG_LIB_DIR)
		if not os.path.exists(TARGET_RELEASE_LIB_DIR):
			copy_tree(SRC_LIB_DIR + "Release", TARGET_RELEASE_LIB_DIR)
	else:
		os.system('cmake -B build')
		os.chdir(BUILD_PATH)
		os.system('make')
		libDir = SRC_LIB_DIR

		if not os.path.exists(TARGET_LIB_DIR):
			copy_tree(libDir, TARGET_LIB_DIR)

	if not os.path.exists(TARGET_ICNLUDE_DIR):
		copy_tree(SRC_ICNLUDE_DIR, TARGET_ICNLUDE_DIR)