//
// Copyright (c) 2019 The nanoFramework project contributors
// See LICENSE file in the project root for full license information.
//
#include "st_cmsis_defines.h"
#include "stdint.h"
#include "stdbool.h"
// #include "cmsis_gcc.h"
#include <nanoWeak.h>
#include <platform_target_capabilities.h>

#include <FreeRTOS.h>
#include <task.h>

void HAL_AssertEx()
{
    __asm volatile ("bkpt ");
    while(true) { /*nop*/ }
}

#if !defined(BUILD_RTM)

void HARD_Breakpoint() 
{
    __asm volatile ("bkpt ");
    while(true) { /*nop*/ }
};

#endif  // !defined(BUILD_RTM)

uint32_t HAL_GetTick(void)
{
  return xTaskGetTickCount();
}

// Provides information whether the configuration block storage requires erase command before sending the update command
// The 'weak' implementation for NXP targets is true
// If a target implements the store differently it has to provide a 'strong' implementation of this.
__nfweak bool Target_ConfigUpdateRequiresErase()
{
    return true;
};

bool Target_HasNanoBooter()
{ 
    return true; 
};

// declarations of platform capabilities
uint32_t GetPlatformCapabilities()
{ 
    return 0; 
};

// declarations of target capabilities
// If a target has something to declare it has to provide a 'strong' implementation of this.
__nfweak uint32_t GetTargetCapabilities()
{ 
    return 0; 
};