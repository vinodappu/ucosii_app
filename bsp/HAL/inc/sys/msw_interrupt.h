#ifndef __M_SW_INTERRUPT_H__
#define __M_SW_INTERRUPT_H__

#include "alt_types.h"
#include "sys/alt_irq.h"
#include "intel_niosv_m.h"

static volatile alt_u32 *const alt_niosv_msip = (alt_u32 *)ABBOTTS_LAKE_MSIP_ADDR;
extern alt_niosv_sw_isr_t alt_niosv_software_interrupt_handler;

static ALT_INLINE void ALT_ALWAYS_INLINE alt_niosv_enable_msw_interrupt() {
    ABBOTTS_LAKE_SET_CSR(ABBOTTS_LAKE_MIE_CSR, 0x1 << ABBOTTS_LAKE_SOFTWARE_IRQ);
}

static ALT_INLINE void ALT_ALWAYS_INLINE alt_niosv_disable_msw_interrupt() {
    ABBOTTS_LAKE_CLR_CSR(ABBOTTS_LAKE_MIE_CSR, 0x1 << ABBOTTS_LAKE_SOFTWARE_IRQ);
}

static ALT_INLINE int ALT_ALWAYS_INLINE alt_niosv_is_msw_interrupt_enabled() {
    alt_u32 mie_val;
    ABBOTTS_LAKE_READ_CSR(ABBOTTS_LAKE_MIE_CSR, mie_val);   
    return mie_val & (0x1 << ABBOTTS_LAKE_SOFTWARE_IRQ);
}

static ALT_INLINE void ALT_ALWAYS_INLINE alt_niosv_trigger_msw_interrupt() {
    *alt_niosv_msip = 0x1;
}

static ALT_INLINE void ALT_ALWAYS_INLINE alt_niosv_clear_msw_interrupt() {
    *alt_niosv_msip = 0x0;
}

static ALT_INLINE void ALT_ALWAYS_INLINE alt_niosv_register_msw_interrupt_handler(alt_niosv_sw_isr_t handle) {
    alt_niosv_software_interrupt_handler = handle;
}

#endif /* __M_SW_INTERRUPT_H__ */
