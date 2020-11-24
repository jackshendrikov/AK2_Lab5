#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>

MODULE_AUTHOR("Jack Shendrikov <jackshen@ukr.net>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("2.0");

static uint count = 1;
module_param(count, uint, S_IRUGO);
MODULE_PARM_DESC(count, "Count to print 'Hello, world!'");

static int __init hello_init(void) {
	uint i = 0;

	if (count == 0) {
		pr_warning("The parameter is 0");
	} else if (count >= 5 && count <= 10) {
		pr_warning("The parameter is %d, between [5;10]", count);
	} else if (count > 10) {
		pr_err("The parameter is %d, (> 10)", count);
		return -EINVAL;
	} 

	for(i = 0; i < count; i++) {
		pr_info("Hello, world!\n");
	}
	return 0;

}

static void __exit hello_exit(void) {
	pr_emerg("Long live and prosper!\n");
}

module_init(hello_init);
module_exit(hello_exit);
