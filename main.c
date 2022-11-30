#include <stdio.h>
#include "vm.h"
#include "misc.h"
#include <stdint.h>

extern uint16_t reg[R_COUNT];

int running = 1;
int main(int argc, const char * argv[]) {
    setup();
    load_args(argc,argv);
    reg[R_COND] = FL_ZRO;

    /** pc */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    while(running){
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;
        switch (op) {
            case OP_ADD:
                execute_add(instr);
                break;
            case OP_AND:
                execute_and(instr);
                break;
            case OP_NOT:
                execute_not(instr);
                break;
            case OP_BR:
                execute_br(instr);
                break;
            case OP_JMP:
                execute_jmp(instr);
                break;
            case OP_JSR:
                execute_jsr(instr);
                break;
            case OP_LD:
                execute_ld(instr);
                break;
            case OP_LDI:
                execute_ldi(instr);
                break;
            case OP_LDR:
                execute_ldr(instr);
                break;
            case OP_LEA:
                execute_lea(instr);
                break;
            case OP_ST:
                execute_st(instr);
                break;
            case OP_STI:
                execute_sti(instr);
                break;
            case OP_STR:
                execute_str(instr);
                break;
            case OP_TRAP:
                execute_trap(instr);
                break;
            case OP_RES:
            case OP_RTI:
            default:
                // bad opcode
                break;
        }
    }
    lc3_shutdown();
    return 0;
}
