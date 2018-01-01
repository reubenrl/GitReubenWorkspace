/* THIS SAMPLE CODE IS PROVIDED AS IS AND IS SUBJECT TO ALTERATIONS. FUJITSU */
/* MICROELECTRONICS ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR */
/* ELIGIBILITY FOR ANY PURPOSES                                              */
/*                 (C) Fujitsu Microelectronics Europe GmbH                  */
/* $Id: sbrk.c,v 1.1 2003/02/03 16:00:25 dfisch Exp $ */

#define HEAP_SIZE       1278			/* memory size */

static long     brk_siz = 0;
#if HEAP_SIZE
#pragma asm
          .SECTION HEAP, DATA
          .GLOBAL _heap
_heap:
          .RES.B 1278
#pragma endasm

extern char heap[];



//	static char     heap[HEAP_SIZE];
	#define         heap_size      HEAP_SIZE
#else
	extern char     * heap;
	extern long     heap_size;
#endif

extern char *sbrk(int size)
{
    if (brk_siz + size > heap_size || brk_siz + size < 0)
        return((char*)-1);			/* return error */
    brk_siz += size;				/* allocate memory */
    return( heap + brk_siz - size); /* return allocatable memory */
}

/*****************************************************************************/
/* EOF $Id: sbrk.c,v 1.1 2003/02/03 16:00:25 dfisch Exp $ */
