/////////////////////////////////////////////////////////////////////////////
//
// spu - Top-level SPU emulation, for SPU and SPU2
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __PSX_SPU_H__
#define __PSX_SPU_H__

#include "emuconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t EMU_CALL spu_init(void);
/* version = 1 for PS1, 2 for PS2 */
uint32_t EMU_CALL spu_get_state_size(uint8_t version);
void   EMU_CALL spu_clear_state(void *state, uint8_t version);

void   EMU_CALL spu_set_buffer(void *state, int16_t *buf, uint32_t samples);
void   EMU_CALL spu_advance(void *state, uint32_t samples);
void   EMU_CALL spu_flush(void *state);

uint16_t EMU_CALL spu_lh(void *state, uint32_t a);
void   EMU_CALL spu_sh(void *state, uint32_t a, uint16_t d);

void   EMU_CALL spu_dma(void *state, uint32_t core, void *mem, uint32_t mem_ofs, uint32_t mem_mask, uint32_t bytes, int iswrite);

uint32_t EMU_CALL spu_cycles_until_interrupt(void *state, uint32_t samples);

void   EMU_CALL spu_interrupt_dma4(void *state);
void   EMU_CALL spu_interrupt_dma7(void *state);

/*
** Enable/disable main or reverb
*/
void EMU_CALL spu_enable_main(void *state, uint8_t enable);
void EMU_CALL spu_enable_reverb(void *state, uint8_t enable);

#ifdef __cplusplus
}
#endif

#endif
