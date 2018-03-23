/*
 * (C) Copyright 2014 Alpha Data Parallel Systems Ltd.
 *
 * See zynq-common.h for Zynq common configs
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ADMXRC7Z1_H
#define __CONFIG_ADMXRC7Z1_H

#define CONFIG_SYS_SDRAM_SIZE		(512 * 1024 * 1024)

#define CONFIG_ZYNQ_SERIAL_UART1
#define CONFIG_ZYNQ_GEM0
#define CONFIG_ZYNQ_GEM_PHY_ADDR0	0

#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_SPI_MAX_HZ      30000000

#define CONFIG_ZYNQ_USB
#define CONFIG_ZYNQ_SDHCI0
#define CONFIG_ZYNQ_QSPI

#define CONFIG_ZYNQ_BOOT_FREEBSD
#define CONFIG_DEFAULT_DEVICE_TREE	admxrc7z1

#include <configs/zynq-common.h>


#undef CONFIG_SPL_FAT_LOAD_ARGS_NAME
#undef CONFIG_SPL_FAT_LOAD_KERNEL_NAME
#define CONFIG_SPL_FAT_LOAD_ARGS_NAME		"uImage-admxrc7z.dtb"
#define CONFIG_SPL_FAT_LOAD_KERNEL_NAME		"uImage-admxrc7z.bin"

#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS	\
        "baudrate=115200\0"	\
	"bitstream_image=system.bit.bin\0"	\
	"boot_image=BOOT.bin\0"	\
	"boot_size=0xF00000\0"	\
	"bootcmd=run $modeboot\0"	\
	"bootdelay=3\0"	\
	"bootenv=uEnv.txt\0"	\
	"devicetree_addr=0x2000000\0"	\
	"devicetree_image=admxrc7z.dtb\0"	\
	"devicetree_size=0x20000\0"	\
	"ethact=Gem.e000b000\0"	\
	"ethaddr=00:0a:35:00:01:22\0"	\
	"fdt_high=0x20000000\0"	\
	"importbootenv=echo Importing environment from SD ...;"	\
	"env import -t ${loadbootenv_addr} $filesize\0"	\
	"initrd_high=0x20000000\0"	\
	"ipaddr=10.10.70.102\0"	\
	"jtagboot=echo TFTPing Linux to RAM... && a"	\
		"tftpboot ${kernel_addr} ${kernel_image} && "	\
		"tftpboot ${devicetree_addr} ${devicetree_image} && "	\
		"tftpboot ${ramdisk_addr} ${ramdisk_image} && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}\0"	\
	"kernel_addr=0x2A00000\0"	\
	"kernel_size=0x500000\0"	\
	"kernel_image=admxrc7z.bin\0"	\
	"loadbit_addr=0x100000\0"	\
	"loadbootenv=fatload mmc 0 ${loadbootenv_addr} ${bootenv}\0"	\
	"loadbootenv_addr=${ramdisk_addr}\0"	\
	"mmc_loadbit_fat=echo Loading bitstream from SD/MMC/eMMC to RAM.. && "	\
		"mmcinfo && "	\
		"fatload mmc 0 ${loadbit_addr} ${bitstream_image} && "	\
		"fpga load 0 ${loadbit_addr} ${filesize}\0"	\
	"modeboot=qspiboot\0"	\
	"qspiboot=echo Copying Linux from QSPI flash to RAM... && "	\
		"sf probe 0 30000000 0 && sf read ${kernel_addr} 0x100000 ${kernel_size} && "	\
		"sf read ${devicetree_addr} 0x600000 ${devicetree_size} && "	\
		"echo Copying ramdisk... && "	\
		"sf read ${ramdisk_addr} 0x620000 ${ramdisk_size} && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}\0"	\
	"ramdisk_addr=0x3000000\0"	\
	"ramdisk_image=adlnx-image-admxrc7z.cpio.gz.u-boot\0"	\
	"ramdisk_size=0x1400000\0"	\
	"rsa_jtagboot=echo TFTPing Image to RAM... && "	\
		"tftpboot 0x100000 ${boot_image} && "	\
		"zynqrsa 0x100000 && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}\0"	\
	"rsa_qspiboot=echo Copying Image from QSPI flash to RAM... && "	\
		"sf probe 0 0 0 && "	\
		"sf read 0x100000 0x0 ${boot_size} && "	\
		"zynqrsa 0x100000 && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}\0"	\
	"rsa_sdboot=echo Copying Image from SD to RAM... && "	\
		"fatload mmc 0 0x100000 ${boot_image} && "	\
		"zynqrsa 0x100000 && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}\0"	\
	"sdboot=if mmcinfo; then run uenvboot; echo Copying Linux from SD to RAM... && "	\
		"fatload mmc 0 ${kernel_addr} ${kernel_image} && "	\
		"fatload mmc 0 ${devicetree_addr} ${devicetree_image} && "	\
		"fatload mmc 0 ${ramdisk_addr} ${ramdisk_image} && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}; fi\0"	\
	"serverip=10.10.70.101\0"	\
	"stderr=serial\0"	\
	"stdin=serial\0"	\
	"stdout=serial\0"	\
	"uenvboot=if run loadbootenv; then echo Loaded environment from ${bootenv}; run importbootenv; fi; if test -n $uenvcmd; then echo Running uenvcmd ...; run uenvcmd; fi\0"	\
	"usbboot=if usb start; then run uenvboot; echo Copying Linux from USB to RAM... && "	\
		"fatload usb 0 ${kernel_addr} ${kernel_image} && "	\
		"fatload usb 0 ${devicetree_addr} ${devicetree_image} && "	\
		"fatload usb 0 ${ramdisk_addr} ${ramdisk_image} && "	\
		"bootm ${kernel_addr} ${ramdisk_addr} ${devicetree_addr}; fi\0"


#endif /* __CONFIG_ADMXRC7Z1_H */
