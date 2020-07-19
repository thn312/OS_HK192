#include "get_proc_info.h"
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

long get_proc_info(pid_t pid, struct procinfos * info) {
        long return_value;
        return_value = syscall(548, pid, info);
        return return_value;
}
