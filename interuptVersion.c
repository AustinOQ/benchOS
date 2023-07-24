void schedule(void)
{
    struct task_struct *prev, *next;

    if (in_interrupt())
        return;

    /* Check the 'interrupt' flag */
    if (global_interrupt_flag == 0)
        return;  

    /* Save the current task (or thread) */
    prev = current;

    /* Choose the next task (or thread) to run */
    next = pick_next_task();

    if (likely(prev != next)) {
        prev->state = TASK_INTERRUPTIBLE;
        set_current_state(TASK_RUNNING);
        switch_to(next);
        global_interrupt_flag = 0;
    }
}

void task_done(struct task_struct *task)
{
    /* ... cleanup after the task ... */
    global_interrupt_flag = 1;
}
