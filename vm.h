//
// Created by sil on 2022/11/19.
//

#ifndef VM_LC3_VM_H
#define VM_LC3_VM_H
#include<stdint.h>

// registers
enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /** program counter */
    R_COND,
    R_COUNT
} ;

// opcodes
enum {
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

// trap code
enum
{
    TRAP_GETC = 0x20,  /* get character from keyboard, not echoed onto the terminal */
    TRAP_OUT = 0x21,   /* output a character */
    TRAP_PUTS = 0x22,  /* output a word string */
    TRAP_IN = 0x23,    /* get character from keyboard, echoed onto the terminal */
    TRAP_PUTSP = 0x24, /* output a byte string */
    TRAP_HALT = 0x25   /* halt the program */
};
// running
extern int running;

// memory
uint16_t mem_read(uint16_t address);
void mem_write(uint16_t address, uint16_t _value);
#ifndef MEMORY_MAX
#define MEMORY_MAX  (1 << 16)
#endif
extern uint16_t memory[MEMORY_MAX];
enum
{
    MR_KBSR = 0xFE00, /* keyboard status */
    MR_KBDR = 0xFE02  /* keyboard data */
};

// emulator
uint16_t sign_extend(uint16_t x, int bit_count);
void update_flags(uint16_t r);
void load_args(int argc,const char **argv);

void execute_add(uint16_t instr);
void execute_and(uint16_t instr);
void execute_not(uint16_t instr);
void execute_br(uint16_t instr);
void execute_jmp(uint16_t instr);
void execute_jsr(uint16_t instr);
void execute_ld(uint16_t instr);
void execute_ldi(uint16_t instr);
void execute_ldr(uint16_t instr);
void execute_lea(uint16_t instr);
void execute_st(uint16_t instr);
void execute_sti(uint16_t instr);
void execute_str(uint16_t instr);
void execute_trap(uint16_t instr);
#endif //VM_LC3_VM_H
