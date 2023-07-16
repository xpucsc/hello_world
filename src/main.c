/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>




static uint32_t counter, prev;
static void counter_fn(struct k_timer *dummy) {
	counter++;
}
static void timer_fn(struct k_timer *dummy) {
	
	printk("%d,%d\n",counter, counter-prev);
	prev = counter;
}

K_TIMER_DEFINE(timer, timer_fn, NULL);
K_TIMER_DEFINE(timer1, counter_fn, NULL);

int main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
	k_timer_start(&timer, K_SECONDS(5), K_SECONDS(1));
	k_timer_start(&timer1, K_SECONDS(5), K_USEC(120));   // very good values: 240, 120, 60, (multiple of 60*i)
	return 0;
}
  
