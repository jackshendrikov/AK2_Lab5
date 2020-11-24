#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>

MODULE_AUTHOR("Jack Shendrikov <jackshen@ukr.net>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count, uint, 0);
MODULE_PARM_DESC(count, "Count to print 'Hello world!'");

static int __init hello_init(void)
{
	uint i = 0;

	printk(KERN_INFO "Сount: %d\n", count);

	if (count == 0 || (count >= 5 && count <= 10)) {
		printk(KERN_WARNING "WARNING\nThe parameter is between [5;10] or 0");
	} else if (count > 10) {
		printk(KERN_ERR "ERROR\nThe parameter is greater than 10");
		return -EINVAL;
	} 

	for(i = 0; i < count; i++) {
		printk(KERN_INFO "Hello world!\n");
	}
	return 0;

}

static void __exit hello_exit(void)
{
	printk(KERN_EMERG "Long live and prosper!\n");
}

module_init(hello_init);
module_exit(hello_exit);
