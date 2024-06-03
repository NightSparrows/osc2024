
#include "syscall.h"
#include "proc/task.h"
#include "peripherals/irq.h"
#include "fs/fs.h"
#include "utils/printf.h"
#include "mm/mm.h"

void sys_ioctl(TRAP_FRAME* regs) {
    
    TASK* task = task_get_current_el1();

    int fd = (int)regs->regs[0];
    unsigned long request = (int)regs->regs[1];
    U64 args = &regs->regs[2];

    if (fd > MAX_FILE_DESCRIPTOR || fd < 0) {
        NS_DPRINT("[SYSCALL][CLOSE] illegal file descriptor id. fd: %d\n", fd);
        regs->regs[0] = -1;
        return;
    }
    FILE_DESCRIPTOR* descriptor = &task->file_table[fd];

    if (!descriptor->file) {
        NS_DPRINT("[SYSCALL][CLOSE] file descriptor not open yet. fd: %d\n", fd);
        regs->regs[0] = -1;
        return;
    }

    regs->regs[0] = descriptor->file->vnode->f_ops->ioctl(descriptor->file, request, args);

    return;
}
