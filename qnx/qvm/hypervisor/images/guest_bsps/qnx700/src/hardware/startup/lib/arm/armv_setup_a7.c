/*
 * $QNXLicenseC:
 * Copyright 2018, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

#include "startup.h"

/*
 * Additional Cortex A7 MPCore specific CPU initialisation
 */

void
armv_setup_a7(struct cpuinfo_entry *cpu, unsigned cpunum, unsigned cpuid)
{

    if (lsp.syspage.p->num_cpu > 1) {
        unsigned   actlr;
        /*
         * Set SMP (bit 6) to enable coherency requests from other cpus
         */
        actlr = arm_actlr_get();
        actlr |= 1u << 6;
        arm_actlr_set(actlr);
    }
}


#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/mainline/hardware/startup/lib/arm/armv_setup_a7.c $ $Rev: 851750 $")
#endif