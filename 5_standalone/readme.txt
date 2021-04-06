是 用 做 standalone 实验用的

编译器
可选
gcc version 4.3.2 (Sourcery G++ Lite 2008q3-72)
不可选
gcc version 7.4.1 20181213 [linaro-7.4-2019.02 revision 56ec6f6b99cc167ff0c2f8e1a2eed33b1edc85d4] (Linaro GCC 7.4-2019.02)


仅适用于


ok6410a u-boot-2021-01 ok6410a_mini_net_defconfig

$ cat configs/ok6410a_mini_net_defconfig 
# target
CONFIG_ARM=y
CONFIG_ARCH_S3C64XX=y
CONFIG_TARGET_OK6410A=y

# driver
CONFIG_NR_DRAM_BANKS=1
CONFIG_CLK=y
CONFIG_MMC=y
CONFIG_MMC_SDHCI=y
CONFIG_MMC_SDHCI_S3C64XX=y
CONFIG_NET_RANDOM_ETHADDR=y

# mem
CONFIG_SYS_MALLOC_F_LEN=0x100000
CONFIG_SYS_TEXT_BASE=0x5FB00000
CONFIG_SPL_TEXT_BASE=0x0C000000

#env
CONFIG_ENV_IS_IN_MMC=y
CONFIG_ENV_OFFSET=0x80000
CONFIG_ENV_SIZE=0x4000

# cmdline
CONFIG_CMD_FAT=y
CONFIG_DEFAULT_DEVICE_TREE="s3c64xx-ok6410a"

# spl
CONFIG_SPL=y
CONFIG_SPL_LDSCRIPT="board/$(BOARDDIR)/u-boot-spl.lds"
CONFIG_SPL_SERIAL_SUPPORT=y
CONFIG_SPL_LIBGENERIC_SUPPORT=y


#net utils
CONFIG_CMD_PING=y
CONFIG_CMD_TFTP=y



若需要适配其他 config,请替换
	u-boot/autoconf.h <= output/include/generated/autoconf.h // 该文件为生成文件

若需要适配其他版本u-boot,请替换,并做少量修改
	u-boot/autoconf.h 		<= output/include/generated/autoconf.h
	u-boot/_exports.h 		<= include/_exports.h
	u-boot/global_data.h 	<= arch/arm/include/asm/global_data.h
	u-boot/kconfig.h  		<= include/linux/kconfig.h
	u-boot/u-boot.h 		<= 自己写的

-Ttext 0x51000000
因为要加载到 0x51000000 , 怕会出现地址相关码
tftp 51000000 standalone.bin
go 51000000

