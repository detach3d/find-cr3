#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <asm/io.h>

MODULE_LICENSE("Dual BSD/GPL");
static int write_cr3(int pid)
{
    struct task_struct *task;
    struct mm_struct *mm;
    void *cr3_virt;

    task = pid_task(find_vpid(pid), PIDTYPE_PID);

    if (task == NULL)
        return -1;

    mm = task->mm;

    cr3_virt = (void *) mm->pgd;
    unsigned long cr3_phys = virt_to_phys(cr3_virt);

    printk(KERN_INFO "CR3 value = \"0x%llx\", pid = %i\n", (unsigned long long)cr3_phys, current->pid);

    return cr3_phys;
}

static int init_driver(void){
    printk(KERN_ALERT "Hello. Let's find CR3 value");
    write_cr3(current->pid);
    return 0;
}

static void exit_driver(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(init_driver);
module_exit(exit_driver);
