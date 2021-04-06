
typedef struct global_data gd_t;
typedef unsigned long phys_size_t;
typedef unsigned long phys_addr_t;
struct list_head {
	struct list_head *next, *prev;

};

/**
 * struct global_data - global data structure
 */
struct global_data {
	/**
	 * @bd: board information
	 */
	struct bd_info *bd;
	/**
	 * @flags: global data flags
	 *
	 * See &enum gd_flags
	 */
	unsigned long flags;
	/**
	 * @baudrate: baud rate of the serial interface
	 */
	unsigned int baudrate;
	/**
	 * @cpu_clk: CPU clock rate in Hz
	 */
	unsigned long cpu_clk;
	/**
	 * @bus_clk: platform clock rate in Hz
	 */
	unsigned long bus_clk;
	/**
	 * @pci_clk: PCI clock rate in Hz
	 */
	/* We cannot bracket this with CONFIG_PCI due to mpc5xxx */
	unsigned long pci_clk;
	/**
	 * @mem_clk: memory clock rate in Hz
	 */
	unsigned long mem_clk;
#if defined(CONFIG_LCD) || defined(CONFIG_VIDEO) || defined(CONFIG_DM_VIDEO)
	/**
	 * @fb_base: base address of frame buffer memory
	 */
	unsigned long fb_base;
#endif
#if defined(CONFIG_POST)
	/**
	 * @post_log_word: active POST tests
	 *
	 * @post_log_word is a bit mask defining which POST tests are recorded
	 * (see constants POST_*).
	 */
	unsigned long post_log_word;
	/**
	 * @post_log_res: POST results
	 *
	 * @post_log_res is a bit mask with the POST results. A bit with value 1
	 * indicates successful execution.
	 */
	unsigned long post_log_res;
	/**
	 * @post_init_f_time: time in ms when post_init_f() started
	 */
	unsigned long post_init_f_time;
#endif
#ifdef CONFIG_BOARD_TYPES
	/**
	 * @board_type: board type
	 *
	 * If a U-Boot configuration supports multiple board types, the actual
	 * board type may be stored in this field.
	 */
	unsigned long board_type;
#endif
	/**
	 * @have_console: console is available
	 *
	 * A value of 1 indicates that serial_init() was called and a console
	 * is available.
	 * A value of 0 indicates that console input and output drivers shall
	 * not be called.
	 */
	unsigned long have_console;
#if CONFIG_IS_ENABLED(PRE_CONSOLE_BUFFER)
	/**
	 * @precon_buf_idx: pre-console buffer index
	 *
	 * @precon_buf_idx indicates the current position of the buffer used to
	 * collect output before the console becomes available
	 */
	unsigned long precon_buf_idx;
#endif
	/**
	 * @env_addr: address of environment structure
	 *
	 * @env_addr contains the address of the structure holding the
	 * environment variables.
	 */
	unsigned long env_addr;
	/**
	 * @env_valid: environment is valid
	 *
	 * See &enum env_valid
	 */
	unsigned long env_valid;
	/**
	 * @env_has_init: bit mask indicating environment locations
	 *
	 * &enum env_location defines which bit relates to which location
	 */
	unsigned long env_has_init;
	/**
	 * @env_load_prio: priority of the loaded environment
	 */
	int env_load_prio;
	/**
	 * @ram_base: base address of RAM used by U-Boot
	 */
	unsigned long ram_base;
	/**
	 * @ram_top: top address of RAM used by U-Boot
	 */
	unsigned long ram_top;
	/**
	 * @relocaddr: start address of U-Boot in RAM
	 *
	 * After relocation this field indicates the address to which U-Boot
	 * has been relocated. It can be displayed using the bdinfo command.
	 * Its value is needed to display the source code when debugging with
	 * GDB using the 'add-symbol-file u-boot <relocaddr>' command.
	 */
	unsigned long relocaddr;
	/**
	 * @ram_size: RAM size in bytes
	 */
	phys_size_t ram_size;
	/**
	 * @mon_len: monitor length in bytes
	 */
	unsigned long mon_len;
	/**
	 * @irq_sp: IRQ stack pointer
	 */
	unsigned long irq_sp;
	/**
	 * @start_addr_sp: initial stack pointer address
	 */
	unsigned long start_addr_sp;
	/**
	 * @reloc_off: relocation offset
	 */
	unsigned long reloc_off;
	/**
	 * @new_gd: pointer to relocated global data
	 */
	struct global_data *new_gd;

#ifdef CONFIG_DM
	/**
	 * @dm_root: root instance for Driver Model
	 */
	struct udevice *dm_root;
	/**
	 * @dm_root_f: pre-relocation root instance
	 */
	struct udevice *dm_root_f;
	/**
	 * @uclass_root: head of core tree
	 */
	struct list_head uclass_root;
# if CONFIG_IS_ENABLED(OF_PLATDATA)
	/** @dm_driver_rt: Dynamic info about the driver */
	struct driver_rt *dm_driver_rt;
# endif
#endif
#ifdef CONFIG_TIMER
	/**
	 * @timer: timer instance for Driver Model
	 */
	struct udevice *timer;
#endif
	/**
	 * @fdt_blob: U-Boot's own device tree, NULL if none
	 */
	const void *fdt_blob;
	/**
	 * @new_fdt: relocated device tree
	 */
	void *new_fdt;
	/**
	 * @fdt_size: space reserved for relocated device space
	 */
	unsigned long fdt_size;
#if CONFIG_IS_ENABLED(OF_LIVE)
	/**
	 * @of_root: root node of the live tree
	 */
	struct device_node *of_root;
#endif

#if CONFIG_IS_ENABLED(MULTI_DTB_FIT)
	/**
	 * @multi_dtb_fit: pointer to uncompressed multi-dtb FIT image
	 */
	const void *multi_dtb_fit;
#endif
	/**
	 * @jt: jump table
	 *
	 * The jump table contains pointers to exported functions. A pointer to
	 * the jump table is passed to standalone applications.
	 */
	struct jt_funcs *jt;
	/**
	 * @env_buf: buffer for env_get() before reloc
	 */
	char env_buf[32];
#ifdef CONFIG_TRACE
	/**
	 * @trace_buff: trace buffer
	 *
	 * When tracing function in U-Boot this field points to the buffer
	 * recording the function calls.
	 */
	void *trace_buff;
#endif
#if defined(CONFIG_SYS_I2C)
	/**
	 * @cur_i2c_bus: currently used I2C bus
	 */
	int cur_i2c_bus;
#endif
	/**
	 * @timebase_h: high 32 bits of timer
	 */
	unsigned int timebase_h;
	/**
	 * @timebase_l: low 32 bits of timer
	 */
	unsigned int timebase_l;
#if CONFIG_VAL(SYS_MALLOC_F_LEN)
	/**
	 * @malloc_base: base address of early malloc()
	 */
	unsigned long malloc_base;
	/**
	 * @malloc_limit: limit address of early malloc()
	 */
	unsigned long malloc_limit;
	/**
	 * @malloc_ptr: current address of early malloc()
	 */
	unsigned long malloc_ptr;
#endif
#ifdef CONFIG_PCI
	/**
	 * @hose: PCI hose for early use
	 */
	struct pci_controller *hose;
	/**
	 * @pci_ram_top: top of region accessible to PCI
	 */
	phys_addr_t pci_ram_top;
#endif
#ifdef CONFIG_PCI_BOOTDELAY
	/**
	 * @pcidelay_done: delay time before scanning of PIC hose expired
	 *
	 * If CONFIG_PCI_BOOTDELAY=y, pci_hose_scan() waits for the number of
	 * milliseconds defined by environment variable pcidelay before
	 * scanning. Once this delay has expired the flag @pcidelay_done
	 * is set to 1.
	 */
	int pcidelay_done;
#endif
	/**
	 * @cur_serial_dev: current serial device
	 */
	struct udevice *cur_serial_dev;
};

