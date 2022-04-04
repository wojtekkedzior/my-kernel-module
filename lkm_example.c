#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include<linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert W. Oliver II");
MODULE_DESCRIPTION("A simple example Linux module");
MODULE_VERSION("0.01");


struct fox {
 unsigned long  tail_length;
 unsigned long  weight;
 char 	*name;
 struct list_head list;
 
};

static int __init lkm_example_init(void) {
 printk(KERN_INFO "Hello, World!\n");

 
 struct fox *red_fox;
 red_fox = kmalloc(sizeof(*red_fox), GFP_KERNEL);
 red_fox->tail_length = 40;
 red_fox->weight = 10;
 red_fox->name = "red fox";
 INIT_LIST_HEAD(&red_fox->list);
 
 static LIST_HEAD(fox_list);
 struct list_head *p;
 struct fox *f;
 
 list_add(&red_fox->list, &fox_list);
 
  list_for_each(p, &fox_list) {
    f = list_entry(p, struct fox, list);

    printk(KERN_INFO "%ld\n",f->tail_length);
    printk(KERN_INFO "%s\n", f->name);
}
 
 
 
 
 return 0;
}

static void __exit lkm_example_exit(void) {
 printk(KERN_INFO "Goodbye, World!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);


