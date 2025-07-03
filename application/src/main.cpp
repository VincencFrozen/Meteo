/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include "anemometer.hpp"
#include "windlogic.hpp"

#include <zephyr/kernel.h>

using Anemometer::AnemometerGpioWH1080;
using WindLogic::WindLogicUart;


int main(void)
{
	printf("Hello Worldd! %s\n", CONFIG_BOARD_TARGET);

	AnemometerGpioWH1080 anemo;
	WindLogicUart windLogic(anemo);

	while(1)
	{
		anemo.triggerFromGpio();
		windLogic.process();

		k_sleep(K_MSEC(1000));
	}

	return 0;
}
