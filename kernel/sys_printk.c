#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage void sys_printk(char *s){
    printk(KERN_INFO "%s",s);
}