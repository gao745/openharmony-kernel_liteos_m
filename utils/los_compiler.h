/*
 * Copyright (c) 2013-2019, Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020, Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LOS_COMPILER_H
#define _LOS_COMPILER_H

/* for IAR Compiler */
#ifdef __ICCARM__
#include"iccarm_builtin.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/* for IAR Compiler */
#ifdef __ICCARM__

#ifndef ASM
#define ASM           __asm
#endif

#ifndef INLINE
#define INLINE        inline
#endif

#ifndef STATIC_INLINE
#define STATIC_INLINE static inline
#endif

#ifndef USED
#define USED          __root
#endif

#ifndef WEAK
#define WEAK          __weak
#endif

#ifndef CLZ
#define CLZ           __iar_builtin_CLZ
#endif

/* for ARM Compiler */
#elif defined(__CC_ARM)

#ifndef ASM
#define ASM           __asm
#endif

#ifndef INLINE
#define INLINE        __inline
#endif

#ifndef STATIC_INLINE
#define STATIC_INLINE static __inline
#endif

#ifndef USED
#define USED          __attribute__((used))
#endif

#ifndef WEAK
#define WEAK          __attribute__((weak))
#endif

#ifndef CLZ
#define CLZ           __clz
#endif

#pragma anon_unions

/* for GNU Compiler */
#elif defined(__GNUC__)

#ifndef ASM
#define ASM           __asm
#endif

#ifndef INLINE
#define INLINE        inline
#endif

#ifndef STATIC_INLINE
#define STATIC_INLINE static inline
#endif

#ifndef USED
#define USED          __attribute__((used))
#endif

#ifndef WEAK
#define WEAK          __attribute__((weak))
#endif

#ifndef CLZ
#define CLZ           __builtin_clz
#endif

#else
#error Unknown compiler.
#endif

#ifndef STATIC
#define STATIC       static
#endif

/**
 * @ingroup los_builddef
 * Define inline keyword
 */
#ifndef INLINE
#define INLINE                                              static inline
#endif

/**
 * @ingroup los_builddef
 * Little endian
 */
#define OS_LITTLE_ENDIAN                                    0x1234

/**
 * @ingroup los_builddef
 * Big endian
 */
#define OS_BIG_ENDIAN                                       0x4321

/**
 * @ingroup los_builddef
 * Byte order
 */
#ifndef OS_BYTE_ORDER
#define OS_BYTE_ORDER                                       OS_LITTLE_ENDIAN
#endif

/* Define OS code data sections */
/* The indicator function is inline */

/**
 * @ingroup los_builddef
 * Allow inline sections
 */
#ifndef LITE_OS_SEC_ALW_INLINE
#define LITE_OS_SEC_ALW_INLINE      //__attribute__((always_inline))
#endif

/**
 * @ingroup los_builddef
 * Vector table section
 */
#ifndef LITE_OS_SEC_VEC
#define LITE_OS_SEC_VEC          __attribute__ ((section(".vector")))
#endif

/**
 * @ingroup los_builddef
 * .Text section (Code section)
 */
#ifndef LITE_OS_SEC_TEXT
#define LITE_OS_SEC_TEXT            //__attribute__((section(".sram.text")))
#endif

/**
 * @ingroup los_builddef
 * .Text.ddr section
 */
#ifndef LITE_OS_SEC_TEXT_MINOR
#define LITE_OS_SEC_TEXT_MINOR      // __attribute__((section(".dyn.text")))
#endif

/**
 * @ingroup los_builddef
 * .Text.init section
 */
#ifndef LITE_OS_SEC_TEXT_INIT
#define LITE_OS_SEC_TEXT_INIT       //__attribute__((section(".dyn.text")))
#endif

/**
 * @ingroup los_builddef
 * .Data section
 */
#ifndef LITE_OS_SEC_DATA
#define LITE_OS_SEC_DATA  //__attribute__((section(".dyn.data")))
#endif

/**
 * @ingroup los_builddef
 * .Data.init section
 */
#ifndef LITE_OS_SEC_DATA_INIT
#define LITE_OS_SEC_DATA_INIT  //__attribute__((section(".dyn.data")))
#endif

/**
 * @ingroup los_builddef
 * Not initialized variable section
 */
#ifndef LITE_OS_SEC_BSS
#define LITE_OS_SEC_BSS  //__attribute__((section(".sym.bss")))
#endif

/**
 * @ingroup los_builddef
 * .bss.ddr section
 */
#ifndef LITE_OS_SEC_BSS_MINOR
#define LITE_OS_SEC_BSS_MINOR
#endif

/**
 * @ingroup los_builddef
 * .bss.init sections
 */
#ifndef LITE_OS_SEC_BSS_INIT
#define LITE_OS_SEC_BSS_INIT
#endif

#ifndef LITE_OS_SEC_TEXT_DATA
#define LITE_OS_SEC_TEXT_DATA       //__attribute__((section(".dyn.data")))
#define LITE_OS_SEC_TEXT_BSS        //__attribute__((section(".dyn.bss")))
#define LITE_OS_SEC_TEXT_RODATA     //__attribute__((section(".dyn.rodata")))
#endif

#ifndef LITE_OS_SEC_SYMDATA
#define LITE_OS_SEC_SYMDATA         //__attribute__((section(".sym.data")))
#endif

#ifndef LITE_OS_SEC_SYMBSS
#define LITE_OS_SEC_SYMBSS          //__attribute__((section(".sym.bss")))
#endif


#ifndef LITE_OS_SEC_KEEP_DATA_DDR
#define LITE_OS_SEC_KEEP_DATA_DDR   //__attribute__((section(".keep.data.ddr")))
#endif

#ifndef LITE_OS_SEC_KEEP_TEXT_DDR
#define LITE_OS_SEC_KEEP_TEXT_DDR   //__attribute__((section(".keep.text.ddr")))
#endif

#ifndef LITE_OS_SEC_KEEP_DATA_SRAM
#define LITE_OS_SEC_KEEP_DATA_SRAM  //__attribute__((section(".keep.data.sram")))
#endif

#ifndef LITE_OS_SEC_KEEP_TEXT_SRAM
#define LITE_OS_SEC_KEEP_TEXT_SRAM  //__attribute__((section(".keep.text.sram")))
#endif

#ifndef LITE_OS_SEC_BSS_MINOR
#define LITE_OS_SEC_BSS_MINOR
#endif

/* type definitions */
typedef unsigned char          UINT8;
typedef unsigned short         UINT16;
typedef unsigned int           UINT32;
typedef signed char            INT8;
typedef signed short           INT16;
typedef signed int             INT32;
typedef float                  FLOAT;
typedef double                 DOUBLE;
typedef char                   CHAR;

typedef unsigned int           BOOL;
typedef unsigned long long     UINT64;
typedef signed long long       INT64;
typedef unsigned int           UINTPTR;
typedef signed int             INTPTR;

#define VOID          void

#ifndef FALSE
#define FALSE         ((BOOL)0)
#endif

#ifndef TRUE
#define TRUE          ((BOOL)1)
#endif

#ifndef NULL
#define NULL          ((VOID *)0)
#endif

#ifdef YES
#undef YES
#endif
#define YES           1

#ifdef NO
#undef NO
#endif
#define NO            0

#define OS_NULL_BYTE  ((UINT8)0xFF)
#define OS_NULL_SHORT ((UINT16)0xFFFF)
#define OS_NULL_INT   ((UINT32)0xFFFFFFFF)

#ifndef LOS_OK
#define LOS_OK        0U
#endif

#ifndef LOS_NOK
#define LOS_NOK       1U
#endif

#define OS_FAIL       1
#define OS_ERROR      (UINT32)(-1)
#define OS_INVALID    (UINT32)(-1)

#define asm           __asm
#ifdef typeof
#undef typeof
#endif
#define typeof        __typeof__

#define SIZE(a) (a)

#define LOS_ASSERT_COND(expression)

/**
 * @ingroup los_base
 * Align the beginning of the object with the base address addr,
 * with boundary bytes being the smallest unit of alignment.
 */
#ifndef ALIGN
#define ALIGN(addr, boundary)        LOS_Align(addr, boundary)
#endif
/**
 * @ingroup los_base
 * Align the tail of the object with the base address addr, with size bytes being the smallest unit of alignment.
 */
#define TRUNCATE(addr, size)         ((addr) & ~((size)-1))


/**
 * @ingroup los_base
 * @brief Align the value (addr) by some bytes (boundary) you specify.
 *
 * @par Description:
 * This API is used to align the value (addr) by some bytes (boundary) you specify.
 *
 * @attention
 * <ul>
 * <li>the value of boundary usually is 4,8,16,32.</li>
 * </ul>
 *
 * @param addr     [IN]  The variable what you want to align.
 * @param boundary [IN]  The align size what you want to align.
 *
 * @retval #UINT32 The variable what have been aligned.
 * @par Dependency:
 * <ul><li>los_base.h: the header file that contains the API declaration.</li></ul>
 * @see
 */
static inline UINT32 LOS_Align(UINT32 addr, UINT32 boundary)
{
    return (addr + (((addr + (boundary - 1)) > addr) ? (boundary - 1) : 0)) & ~(boundary - 1);
}

#define OS_GOTO_ERREND() \
        do {                 \
            goto LOS_ERREND; \
        } while (0)


#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _LOS_COMPILER_H */
