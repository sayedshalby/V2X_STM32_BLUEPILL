#ifndef FMI_PRIVATE_H_
#define FMI_PRIVATE_H_

#define FMI_BASE_ADDRESS (0x40022000)

typedef struct {
	uint32 ACR;
	uint32 KEYR;
	uint32 OPTKEYR;
	uint32 SR;
	uint32 CR;
    uint32 AR;
    uint32 Reserved;
    uint32 OBR;
    uint32 WRPR;
}tstrFMI_registers;

#define FMI_REG ((volatile tstrFMI_registers*)FMI_BASE_ADDRESS)

#define SR_BSY  0
#define SR_EOP  5

#define CR_LOCK  7
#define CR_STRT  6
#define CR_PSIZE 8
#define CR_PER   1
#define CR_PG    0

#define FMI_FPECKEY1 (0x45670123)
#define FMI_FPECKEY2 (0xCDEF89AB)

#define FMI_OPTKEY1 (0x08192A3B)
#define FMI_OPTKEY2 (0x4C5D6E7F)

#endif
