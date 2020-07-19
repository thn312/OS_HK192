#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

struct proc_info {
	pid_t pid;
	char name[16];
};
struct procinfos {
	long studentID;
	struct proc_info proc;
	struct proc_info parent_proc;
	struct proc_info oldest_child_proc;
};

SYSCALL_DEFINE2(get_proc_info, pid_t, pid, struct procinfos *, info) {
	info->studentID = 1811345;
	struct task_struct *process_item;
	struct task_struct *current_proc;
	struct task_struct *parent_proc;
	struct task_struct *child_proc;
	current_proc = NULL;
	parent_proc = NULL;
	child_proc = NULL;

	if (pid == -1) {
		pid = current->pid;
	}

	for_each_process(process_item) {
		if (process_item->pid == pid) {
			current_proc = process_item;
		}
	}

	if (current_proc != NULL) {
		parent_proc = current_proc->real_parent;

		struct list_head *list_proc;
		struct task_struct *tmp;
		u64 start_time_min = 0;
		bool check_st = 0;
		list_for_each(list_proc, &current_proc->children) {
			tmp = list_entry(list_proc, struct task_struct, sibling);
			if (check_st == 0) {
				check_st = 1;
				start_time_min = tmp->start_time;
				child_proc = tmp;	
			}
			if (tmp->start_time < start_time_min) {
				start_time_min = tmp->start_time;
				child_proc = tmp;
			}
		}
		
		info->proc.pid = current_proc->pid;
		strcpy(info->proc.name, current_proc->comm);
		if (child_proc == NULL) {
			info->parent_proc.pid = -1;
			info->parent_proc.name[0] = '\0';
		} else {
			info->parent_proc.pid = parent_proc->pid;
			strcpy(info->parent_proc.name, parent_proc->comm);
		}
		if (child_proc == NULL) {
			info->oldest_child_proc.pid = -1;
			info->oldest_child_proc.name[0] = '\0';
		} else {
			info->oldest_child_proc.pid = child_proc->pid;
			strcpy(info->oldest_child_proc.name, child_proc->comm);
		}
	} else {
		return EINVAL;
	}
	return 0;
}
