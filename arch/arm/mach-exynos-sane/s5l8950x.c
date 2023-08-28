#include <asm-offsets.h>
#include <config.h>
#include <linux/linkage.h>
#include <common.h>

// TODO: move board early init to board
int board_early_init_f(void)
{
    printf("board_early_init_f\n");
    return 0;
}

/* TODO: Implement AIC, we don't have a separate timer block */
int timer_init(void)
{
    return 0;
}

unsigned long timer_read_counter(void)
{
    return 0;
}
