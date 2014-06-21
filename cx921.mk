all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- rk3188_cx921_defconfig
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4
	rm -rf ./modules && mkdir -p ./modules
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules -j4 
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=./modules modules_install -j4
