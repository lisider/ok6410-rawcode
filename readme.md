```c

本工程适用于 OK6410-A 的裸机工程,并烧写到 sd卡上,从sd卡启动
烧写的bin文件由于s3c6410的iRAM限制,大小不能超过8KB

```


- 开发板
```c
OK6410-A

```

- 启动方式
```c
SD卡启动

```

- 编译器
```c
$ arm-linux-gcc --version
arm-none-linux-gnueabi-gcc (Sourcery G++ Lite 2008q3-72) 4.3.2
Copyright (C) 2008 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

- sd卡
```c
/dev/sdb

```

- project
```c
裸机工程
	裸机工程生成的 .bin 文件不能超过8KB(BL1最大大小为8KB)
```
