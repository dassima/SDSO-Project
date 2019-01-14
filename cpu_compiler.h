// not all defines are used
// some of them are as I found in other documents
// that is good to have
#ifndef _CPU_uc_H
#define _CPU_uc_H

#ifdef  FALSE
#undef  FALSE
#endif
#define FALSE   (0)

#ifdef  TRUE
#undef  TRUE
#endif
#define TRUE    (1)

#ifdef  NULL
#undef  NULL
#endif
#define NULL    (0)

#ifdef  ON
#undef  ON
#endif
#define ON      (1)

#ifdef  OFF
#undef  OFF
#endif
#define OFF     (0)

//data types
typedef unsigned char       uint8;  
typedef unsigned short int  uint16; 
typedef unsigned long int   uint32; 

typedef char                int8;  
typedef short int           int16; 
typedef int                 int32; 

typedef volatile int8       vint8; 
typedef volatile int16      vint16;
typedef volatile int32      vint32; 

typedef volatile uint8      vuint8; 
typedef volatile uint16     vuint16; 
typedef volatile uint32     vuint32;

#define ADDRESS         uint32
#define INSTRUCTION     uint16
#define ILLEGAL         0x4AFC
#define CPU_WORD_SIZE   16

// Status Register
#define uc_SR_T        (0x8000)
#define uc_SR_S        (0x2000)
#define uc_SR_M        (0x1000)
#define uc_SR_IPL      (0x0700)
#define uc_SR_IPL_0    (0x0000)
#define uc_SR_IPL_1    (0x0100)
#define uc_SR_IPL_2    (0x0200)
#define uc_SR_IPL_3    (0x0300)
#define uc_SR_IPL_4    (0x0400)
#define uc_SR_IPL_5    (0x0500)
#define uc_SR_IPL_6    (0x0600)
#define uc_SR_IPL_7    (0x0700)
#define uc_SR_X        (0x0010)
#define uc_SR_N        (0x0008)
#define uc_SR_Z        (0x0004)
#define uc_SR_V        (0x0002)
#define uc_SR_C        (0x0001)

//Cache Control Register
#define uc_CACR_CENB       (0x80000000)
#define uc_CACR_DEC        (0x80000000)
#define uc_CACR_DW         (0x40000000)
#define uc_CACR_DESB       (0x20000000)
#define uc_CACR_CPDI       (0x10000000)
#define uc_CACR_DDPI       (0x10000000)
#define uc_CACR_CPD        (0x10000000)
#define uc_CACR_CFRZ       (0x08000000)
#define uc_CACR_DHLCK      (0x08000000)
#define uc_CACR_DDCM_WT    (0x00000000)
#define uc_CACR_DDCM_CB    (0x02000000)
#define uc_CACR_DDCM_IP    (0x04000000)
#define uc_CACR_DDCM_II    (0x06000000)
#define uc_CACR_CINV       (0x01000000)
#define uc_CACR_DCINVA     (0x01000000)
#define uc_CACR_DIDI       (0x00800000)
#define uc_CACR_DDSP       (0x00800000)
#define uc_CACR_DISD       (0x00400000)
#define uc_CACR_INVI       (0x00200000)
#define uc_CACR_INVD       (0x00100000)
#define uc_CACR_BEC        (0x00080000)
#define uc_CACR_BCINVA     (0x00040000)
#define uc_CACR_IEC        (0x00008000)
#define uc_CACR_DNFB       (0x00002000)
#define uc_CACR_IDPI       (0x00001000)
#define uc_CACR_IHLCK      (0x00000800)
#define uc_CACR_CEIB       (0x00000400)
#define uc_CACR_IDCM       (0x00000400)
#define uc_CACR_DCM_WR     (0x00000000)
#define uc_CACR_DCM_CB     (0x00000100)
#define uc_CACR_DCM_IP     (0x00000200)
#define uc_CACR_DCM        (0x00000200)
#define uc_CACR_DCM_II     (0x00000300)
#define uc_CACR_DBWE       (0x00000100)
#define uc_CACR_ICINVA     (0x00000100)
#define uc_CACR_IDSP       (0x00000080)
#define uc_CACR_DWP        (0x00000020)
#define uc_CACR_EUSP       (0x00000020)
#define uc_CACR_EUST       (0x00000020)
#define uc_CACR_DF         (0x00000010)
#define uc_CACR_CLNF_00    (0x00000000)
#define uc_CACR_CLNF_01    (0x00000002)
#define uc_CACR_CLNF_10    (0x00000004)
#define uc_CACR_CLNF_11    (0x00000006)

//Access Control Register
#define uc_ACR_AB(a)       ((a)&0xFF000000)
#define uc_ACR_AM(a)       (((a)&0xFF000000) >> 8)
#define uc_ACR_AM_4G       (0x00FF0000)
#define uc_ACR_AM_2G       (0x007F0000)
#define uc_ACR_AM_1G       (0x003F0000)
#define uc_ACR_AM_1024M    (0x003F0000)
#define uc_ACR_AM_512M     (0x001F0000)
#define uc_ACR_AM_256M     (0x000F0000)
#define uc_ACR_AM_128M     (0x00070000)
#define uc_ACR_AM_64M      (0x00030000)
#define uc_ACR_AM_32M      (0x00010000)
#define uc_ACR_AM_16M      (0x00000000)
#define uc_ACR_EN          (0x00008000)
#define uc_ACR_SM_USER     (0x00000000)
#define uc_ACR_SM_SUPER    (0x00002000)
#define uc_ACR_SM_IGNORE   (0x00006000)
#define uc_ACR_ENIB        (0x00000080)
#define uc_ACR_CM          (0x00000040)
#define uc_ACR_DCM_WR      (0x00000000)
#define uc_ACR_DCM_CB      (0x00000020)
#define uc_ACR_DCM_IP      (0x00000040)
#define uc_ACR_DCM_II      (0x00000060)
#define uc_ACR_CM          (0x00000040)
#define uc_ACR_BWE         (0x00000020)
#define uc_ACR_WP          (0x00000004)

//RAM Base Address Register
#define uc_RAMBAR_BA(a)    ((a)&0xFFFFC000)
#define uc_RAMBAR_PRI_00   (0x00000000)
#define uc_RAMBAR_PRI_01   (0x00004000)
#define uc_RAMBAR_PRI_10   (0x00008000)
#define uc_RAMBAR_PRI_11   (0x0000C000)
#define uc_RAMBAR_WP       (0x00000100)
#define uc_RAMBAR_CI       (0x00000020)
#define uc_RAMBAR_SC       (0x00000010)
#define uc_RAMBAR_SD       (0x00000008)
#define uc_RAMBAR_UC       (0x00000004)
#define uc_RAMBAR_UD       (0x00000002)
#define uc_RAMBAR_V        (0x00000001)

//Read macros for D0/D1 reset values
#define uc_D0_PF(x)        (((x)&0xFF000000)>>24)
#define uc_D0_VER(x)       (((x)&0x00F00000)>>20)
#define uc_D0_REV(x)       (((x)&0x000F0000)>>16)
#define uc_D0_MAC(x)       ((x)&0x00008000)
#define uc_D0_DIV(x)       ((x)&0x00004000)
#define uc_D0_EMAC(x)      ((x)&0x00002000)
#define uc_D0_FPU(x)       ((x)&0x00001000)
#define uc_D0_MMU(x)       ((x)&0x00000800)
#define uc_D0_ISA(x)       (((x)&0x000000F0)>>4)
#define uc_D0_DEBUG(x)     (((x)&0x0000000F)>>0)
#define uc_D1_CL(x)        (((x)&0xC0000000)>>30)
#define uc_D1_ICA(x)       (((x)&0x30000000)>>28)
#define uc_D1_ICSIZ(x)     (((x)&0x0F000000)>>24)
#define uc_D1_RAM0SIZ(x)   (((x)&0x00F00000)>>20)
#define uc_D1_ROM0SIZ(x)   (((x)&0x000F0000)>>16)
#define uc_D1_BUSW(x)      (((x)&0x0000C000)>>14)
#define uc_D1_DCA(x)       (((x)&0x00003000)>>12)
#define uc_D1_DCSIZ(x)     (((x)&0x00000F00)>>8)
#define uc_D1_RAM1SIZ(x)   (((x)&0x000000F0)>>4)
#define uc_D1_ROM1SIZ(x)   (((x)&0x0000000F)>>0)

//handles exception stack
//the stack self-aligns to a 4-byte boundary at an exception
//SP indicates how many bytes are used
#define uc_RD_SF_FORMAT(PTR)   \
    ((*((uint16 *)(PTR)) >> 12) & 0x00FF)

#define uc_RD_SF_VECTOR(PTR)   \
    ((*((uint16 *)(PTR)) >>  2) & 0x00FF)

#define uc_RD_SF_FS(PTR)       \
    ( ((*((uint16 *)(PTR)) & 0x0C00) >> 8) | (*((uint16 *)(PTR)) & 0x0003) )

#define uc_SF_SR(PTR)  *((uint16 *)(PTR)+1)
#define uc_SF_PC(PTR)  *((uint32 *)(PTR)+1)

// from cpu_compiler.s
int  asm_set_ipl (uint32);
void uc_exe_wdebug (void *);
void uc_wr_sr (uint32);
void uc_wr_cacr (uint32);
void uc_wr_asid (uint32);
void uc_wr_acr0 (uint32);
void uc_wr_acr1 (uint32);
void uc_wr_acr2 (uint32);
void uc_wr_acr3 (uint32);
void uc_wr_mmubar (uint32);
void uc_wr_other_a7 (uint32);
void uc_wr_other_sp (uint32);
void uc_wr_vbr (uint32);
void uc_wr_macsr (uint32);
void uc_wr_mask (uint32);
void uc_wr_acc0 (uint32);
void uc_wr_accext01 (uint32);
void uc_wr_accext23 (uint32);
void uc_wr_acc1 (uint32);
void uc_wr_acc2 (uint32);
void uc_wr_acc3 (uint32);
void uc_wr_pc (uint32);
void uc_wr_rombar0 (uint32);
void uc_wr_rombar1 (uint32);
void uc_wr_rambar0 (uint32);
void uc_wr_rambar1 (uint32);
void uc_wr_mpcr (uint32);
void uc_wr_secmbar (uint32);
void uc_wr_mbar1 (uint32);
void uc_wr_mbar (uint32);
void uc_wr_mbar0 (uint32);
void uc_move_line (ADDRESS, ADDRESS);


//from cpu_compiler.c
void uc_exception_handler (void *);
void uc_interpret_d0d1 (int, int);
void uc_irq_enable (void);
void uc_irq_disable (void);
ADDRESS uc_set_handler (int, ADDRESS);

void cpu_handle_interrupt (int);

#endif

