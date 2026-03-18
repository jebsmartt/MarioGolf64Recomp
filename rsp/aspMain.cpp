#include "librecomp/rsp.hpp"
#include "librecomp/rsp_vu_impl.hpp"
RspExitReason aspMain(uint8_t* rdram, [[maybe_unused]] uint32_t ucode_addr) {
    uint32_t           r1 = 0,  r2 = 0,  r3 = 0,  r4 = 0,  r5 = 0,  r6 = 0,  r7 = 0;
    uint32_t  r8 = 0,  r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0;
    uint32_t r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0;
    uint32_t r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    uint32_t dma_mem_address = 0, dma_dram_address = 0, jump_target = 0;
    const char * debug_file = NULL; int debug_line = 0;
    RSP rsp{};
    r1 = 0xFC0;
    // j           L_1064
    // addi        $1, $zero, 0xFC0
    r1 = RSP_ADD32(0, 0XFC0);
    goto L_1064;
    // addi        $1, $zero, 0xFC0
    r1 = RSP_ADD32(0, 0XFC0);
L_1088:
    // lw          $2, 0x10($1)
    r2 = RSP_MEM_W_LOAD(0X10, r1);
    // addi        $3, $zero, 0xF7F
    r3 = RSP_ADD32(0, 0XF7F);
    // addi        $7, $zero, 0x1080
    r7 = RSP_ADD32(0, 0X1080);
    // mtc0        $7, SP_MEM_ADDR
    SET_DMA_MEM(r7);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
L_10A0:
    // mfc0        $4, SP_DMA_BUSY
    r4 = 0;
    // bne         $4, $zero, L_10A0
    if (r4 != 0) {
        // nop
    
        goto L_10A0;
    }
    // nop

    // jal         0x103C
    r31 = 0x10B4;
    // nop

    goto L_103C;
    // nop

L_10B4:
    // jr          $7
    jump_target = r7;
    debug_file = __FILE__; debug_line = __LINE__;
    // mtc0        $zero, SP_SEMAPHORE
    goto do_indirect_jump;
    // mtc0        $zero, SP_SEMAPHORE
L_10BC:
    // mfc0        $8, SP_STATUS
    r8 = 0;
    // andi        $8, $8, 0x80
    r8 = r8 & 0X80;
    // bne         $8, $zero, L_10D0
    if (r8 != 0) {
        // nop
    
        goto L_10D0;
    }
    // nop

    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // mtc0        $zero, SP_SEMAPHORE
    goto do_indirect_jump;
L_10D0:
    // mtc0        $zero, SP_SEMAPHORE
    // ori         $8, $zero, 0x5200
    r8 = 0 | 0X5200;
    // mtc0        $8, SP_STATUS
    // break       0
    return RspExitReason::Broke;
    // nop

    // lw          $2, 0x4($1)
    r2 = RSP_MEM_W_LOAD(0X4, r1);
    // andi        $2, $2, 0x2
    r2 = r2 & 0X2;
L_10EC:
    // beq         $2, $zero, L_110C
    if (r2 == 0) {
        // nop
    
        goto L_110C;
    }
    // nop

    // jal         0x103C
    r31 = 0x10FC;
    // nop

    goto L_103C;
    // nop

L_10FC:
    // mfc0        $2, DPC_STATUS
    r2 = 0;
    // andi        $2, $2, 0x100
    r2 = r2 & 0X100;
    // bgtz        $2, L_10BC
    if (RSP_SIGNED(r2) > 0) {
        // nop
    
        goto L_10BC;
    }
    // nop

L_110C:
    // lw          $2, 0x18($1)
    r2 = RSP_MEM_W_LOAD(0X18, r1);
    // lw          $3, 0x1C($1)
    r3 = RSP_MEM_W_LOAD(0X1C, r1);
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1118:
    // mfc0        $30, SP_DMA_FULL
    r30 = 0;
    // bne         $30, $zero, L_1118
    if (r30 != 0) {
        // nop
    
        goto L_1118;
    }
L_1120:
    // nop

    // mtc0        $zero, SP_MEM_ADDR
    SET_DMA_MEM(0);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
L_1130:
    // mfc0        $4, SP_DMA_BUSY
    r4 = 0;
    // bne         $4, $zero, L_1130
    if (r4 != 0) {
        // nop
    
        goto L_1130;
    }
    // nop

    // jal         0x103C
    r31 = 0x1144;
    // nop

    goto L_103C;
    // nop

L_1144:
    // j           L_1008
    // nop

    goto L_1008;
    // nop

L_114C:
    // nop

    // mfc0        $5, DPC_STATUS
    r5 = 0;
    // lw          $28, 0x30($1)
    r28 = RSP_MEM_W_LOAD(0X30, r1);
    // lw          $27, 0x34($1)
    r27 = RSP_MEM_W_LOAD(0X34, r1);
    // andi        $4, $5, 0x1
    r4 = r5 & 0X1;
    // beq         $4, $zero, L_117C
    if (r4 == 0) {
        // andi        $4, $5, 0x100
        r4 = r5 & 0X100;
        goto L_117C;
    }
    // andi        $4, $5, 0x100
    r4 = r5 & 0X100;
L_1168:
    // beq         $4, $zero, L_117C
    if (r4 == 0) {
        // mfc0        $4, DPC_STATUS
        r4 = 0;
        goto L_117C;
    }
    // mfc0        $4, DPC_STATUS
    r4 = 0;
L_1170:
    // andi        $4, $4, 0x100
    r4 = r4 & 0X100;
L_1174:
    // bgtz        $4, L_1170
    if (RSP_SIGNED(r4) > 0) {
        // mfc0        $4, DPC_STATUS
        r4 = 0;
        goto L_1170;
    }
    // mfc0        $4, DPC_STATUS
    r4 = 0;
L_117C:
    // addi        $24, $zero, 0xFA0
    r24 = RSP_ADD32(0, 0XFA0);
    // jal         0x1120
    r31 = 0x1188;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    goto L_1120;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
L_1188:
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
L_118C:
    // bne         $2, $zero, L_118C
    if (r2 != 0) {
        // mfc0        $2, SP_DMA_BUSY
        r2 = 0;
        goto L_118C;
    }
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
L_1194:
    // mtc0        $zero, SP_SEMAPHORE
L_1198:
    // lw          $26, 0x0($29)
    r26 = RSP_MEM_W_LOAD(0X0, r29);
    // lw          $25, 0x4($29)
    r25 = RSP_MEM_W_LOAD(0X4, r29);
    // addi        $28, $28, 0x8
    r28 = RSP_ADD32(r28, 0X8);
    // srl         $1, $26, 23
    r1 = S32(U32(r26) >> 23);
    // andi        $1, $1, 0xFE
    r1 = r1 & 0XFE;
    // lh          $1, 0x0($1)
    r1 = RSP_MEM_H_LOAD(0X0, r1);
    // jr          $1
    jump_target = r1;
    debug_file = __FILE__; debug_line = __LINE__;
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    goto do_indirect_jump;
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    // break       0
    return RspExitReason::Broke;
L_11BC:
    // bgtz        $30, L_1198
    if (RSP_SIGNED(r30) > 0) {
        // addi        $29, $29, 0x8
        r29 = RSP_ADD32(r29, 0X8);
        goto L_1198;
    }
    // addi        $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
    // blez        $27, L_11DC
    if (RSP_SIGNED(r27) <= 0) {
        // ori         $1, $zero, 0x4000
        r1 = 0 | 0X4000;
        goto L_11DC;
    }
    // ori         $1, $zero, 0x4000
    r1 = 0 | 0X4000;
    // jal         0x1120
    r31 = 0x11D4;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    goto L_1120;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
L_11D4:
    // j           L_10BC
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
    goto L_10BC;
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
L_11DC:
    // mtc0        $1, SP_STATUS
    // break       0
    return RspExitReason::Broke;
    // nop

L_11E8:
    // b           L_11E8
    // nop

    goto L_11E8;
L_11EC:
    // nop

    // addi        $5, $ra, 0x0
    r5 = RSP_ADD32(r31, 0X0);
    // addi        $3, $27, 0x0
    r3 = RSP_ADD32(r27, 0X0);
    // addi        $4, $3, -0x140
    r4 = RSP_ADD32(r3, -0X140);
    // blez        $4, L_1208
    if (RSP_SIGNED(r4) <= 0) {
        // addi        $1, $zero, 0x2B0
        r1 = RSP_ADD32(0, 0X2B0);
        goto L_1208;
    }
    // addi        $1, $zero, 0x2B0
    r1 = RSP_ADD32(0, 0X2B0);
    // addi        $3, $zero, 0x140
    r3 = RSP_ADD32(0, 0X140);
L_1208:
    // addi        $30, $3, 0x0
    r30 = RSP_ADD32(r3, 0X0);
    // jal         0x114C
    r31 = 0x1214;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_114C;
L_1210:
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1214:
    // jr          $5
    jump_target = r5;
    debug_file = __FILE__; debug_line = __LINE__;
    // addi        $29, $zero, 0x2B0
    r29 = RSP_ADD32(0, 0X2B0);
    goto do_indirect_jump;
    // addi        $29, $zero, 0x2B0
    r29 = RSP_ADD32(0, 0X2B0);
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1220:
    // bne         $4, $zero, L_1220
    if (r4 != 0) {
        // mfc0        $4, SP_SEMAPHORE
        r4 = 0;
        goto L_1220;
    }
L_1224:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_122C:
    // bne         $4, $zero, L_122C
    if (r4 != 0) {
        // mfc0        $4, SP_DMA_FULL
        r4 = 0;
        goto L_122C;
    }
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    goto do_indirect_jump;
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1248:
    // bne         $4, $zero, L_1248
    if (r4 != 0) {
        // mfc0        $4, SP_SEMAPHORE
        r4 = 0;
        goto L_1248;
    }
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_1254:
    // bne         $4, $zero, L_1254
    if (r4 != 0) {
        // mfc0        $4, SP_DMA_FULL
        r4 = 0;
        goto L_1254;
    }
L_1258:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_125C:
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
    goto do_indirect_jump;
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
    // andi        $2, $25, 0xFFFF
    r2 = r25 & 0XFFFF;
    // vxor        $v1, $v1, $v1
    rsp.VXOR<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[1]);
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
L_127C:
    // sdv         $v1[0], 0x0($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X0);
    // sdv         $v1[0], 0x8($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X1);
    // addi        $2, $2, -0x10
    r2 = RSP_ADD32(r2, -0X10);
    // bgtz        $2, L_127C
    if (RSP_SIGNED(r2) > 0) {
        // addi        $1, $1, 0x10
        r1 = RSP_ADD32(r1, 0X10);
        goto L_127C;
    }
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // sll         $3, $26, 8
    r3 = S32(r26) << 8;
    // srl         $3, $3, 20
    r3 = S32(U32(r3) >> 20);
    // beq         $3, $zero, L_11BC
    if (r3 == 0) {
        // addi        $30, $30, -0x8
        r30 = RSP_ADD32(r30, -0X8);
        goto L_11BC;
    }
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // andi        $1, $26, 0xFFF
    r1 = r26 & 0XFFF;
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    // jal         0x114C
    r31 = 0x12C4;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    goto L_114C;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
L_12C4:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_12C8:
    // bne         $1, $zero, L_12C8
    if (r1 != 0) {
        // mfc0        $1, SP_DMA_BUSY
        r1 = 0;
        goto L_12C8;
    }
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
    // sll         $3, $26, 8
    r3 = S32(r26) << 8;
    // srl         $3, $3, 20
    r3 = S32(U32(r3) >> 20);
    // beq         $3, $zero, L_11BC
    if (r3 == 0) {
        // addi        $30, $30, -0x8
        r30 = RSP_ADD32(r30, -0X8);
        goto L_11BC;
    }
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // andi        $1, $26, 0xFFF
    r1 = r26 & 0XFFF;
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    // jal         0x1174
    r31 = 0x1304;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    goto L_1174;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
L_1304:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_1308:
    // bne         $1, $zero, L_1308
    if (r1 != 0) {
        // mfc0        $1, SP_DMA_BUSY
        r1 = 0;
        goto L_1308;
    }
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
L_1320:
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // addi        $1, $zero, 0x3F0
    r1 = RSP_ADD32(0, 0X3F0);
    // andi        $3, $26, 0xFFFF
    r3 = r26 & 0XFFFF;
    // jal         0x114C
    r31 = 0x1334;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_114C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1334:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_1338:
    // bne         $1, $zero, L_1338
    if (r1 != 0) {
        // mfc0        $1, SP_DMA_BUSY
        r1 = 0;
        goto L_1338;
    }
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // srl         $3, $26, 16
    r3 = S32(U32(r26) >> 16);
    // andi        $1, $3, 0x4
    r1 = r3 & 0X4;
    // beq         $1, $zero, L_138C
    if (r1 == 0) {
        // andi        $1, $3, 0x2
        r1 = r3 & 0X2;
        goto L_138C;
    }
    // andi        $1, $3, 0x2
    r1 = r3 & 0X2;
    // beq         $1, $zero, L_1378
    if (r1 == 0) {
        // srl         $2, $25, 16
        r2 = S32(U32(r25) >> 16);
        goto L_1378;
    }
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // sh          $26, 0x50($24)
    RSP_MEM_H_STORE(0X50, r24, r26);
    // sh          $2, 0x4C($24)
    RSP_MEM_H_STORE(0X4C, r24, r2);
    // sh          $25, 0x4E($24)
    RSP_MEM_H_STORE(0X4E, r24, r25);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_1378:
    // sh          $26, 0x46($24)
    RSP_MEM_H_STORE(0X46, r24, r26);
    // sh          $2, 0x48($24)
    RSP_MEM_H_STORE(0X48, r24, r2);
    // sh          $25, 0x4A($24)
    RSP_MEM_H_STORE(0X4A, r24, r25);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_138C:
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // sh          $26, 0x40($24)
    RSP_MEM_H_STORE(0X40, r24, r26);
    // sh          $2, 0x42($24)
    RSP_MEM_H_STORE(0X42, r24, r2);
    // sh          $25, 0x44($24)
    RSP_MEM_H_STORE(0X44, r24, r25);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // addi        $1, $zero, 0x170
    r1 = RSP_ADD32(0, 0X170);
    // addi        $4, $zero, 0x4F0
    r4 = RSP_ADD32(0, 0X4F0);
    // addi        $2, $zero, 0x9D0
    r2 = RSP_ADD32(0, 0X9D0);
    // addi        $3, $zero, 0xB40
    r3 = RSP_ADD32(0, 0XB40);
L_13B4:
    // lqv         $v1[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[1], r2, 0X0);
    // lqv         $v2[0], 0x0($3)
    rsp.LQV<0>(rsp.vpu.r[2], r3, 0X0);
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
    // ssv         $v1[0], 0x0($4)
    rsp.SSV<0>(rsp.vpu.r[1], r4, 0X0);
    // ssv         $v2[0], 0x2($4)
    rsp.SSV<0>(rsp.vpu.r[2], r4, 0X1);
    // ssv         $v1[2], 0x4($4)
    rsp.SSV<2>(rsp.vpu.r[1], r4, 0X2);
    // ssv         $v2[2], 0x6($4)
    rsp.SSV<2>(rsp.vpu.r[2], r4, 0X3);
    // ssv         $v1[4], 0x8($4)
    rsp.SSV<4>(rsp.vpu.r[1], r4, 0X4);
    // ssv         $v2[4], 0xA($4)
    rsp.SSV<4>(rsp.vpu.r[2], r4, 0X5);
    // ssv         $v1[6], 0xC($4)
    rsp.SSV<6>(rsp.vpu.r[1], r4, 0X6);
    // ssv         $v2[6], 0xE($4)
    rsp.SSV<6>(rsp.vpu.r[2], r4, 0X7);
    // ssv         $v1[8], 0x10($4)
    rsp.SSV<8>(rsp.vpu.r[1], r4, 0X8);
    // ssv         $v2[8], 0x12($4)
    rsp.SSV<8>(rsp.vpu.r[2], r4, 0X9);
    // ssv         $v1[10], 0x14($4)
    rsp.SSV<10>(rsp.vpu.r[1], r4, 0XA);
    // ssv         $v2[10], 0x16($4)
    rsp.SSV<10>(rsp.vpu.r[2], r4, 0XB);
    // ssv         $v1[12], 0x18($4)
    rsp.SSV<12>(rsp.vpu.r[1], r4, 0XC);
    // ssv         $v2[12], 0x1A($4)
    rsp.SSV<12>(rsp.vpu.r[2], r4, 0XD);
    // ssv         $v1[14], 0x1C($4)
    rsp.SSV<14>(rsp.vpu.r[1], r4, 0XE);
    // ssv         $v2[14], 0x1E($4)
    rsp.SSV<14>(rsp.vpu.r[2], r4, 0XF);
    // bgtz        $1, L_13B4
    if (RSP_SIGNED(r1) > 0) {
        // addi        $4, $4, 0x20
        r4 = RSP_ADD32(r4, 0X20);
        goto L_13B4;
    }
    // addi        $4, $4, 0x20
    r4 = RSP_ADD32(r4, 0X20);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // andi        $1, $25, 0xFFFF
    r1 = r25 & 0XFFFF;
    // andi        $2, $26, 0xFFFF
    r2 = r26 & 0XFFFF;
    // addi        $2, $2, 0x4F0
    r2 = RSP_ADD32(r2, 0X4F0);
    // srl         $3, $25, 16
    r3 = S32(U32(r25) >> 16);
    // addi        $3, $3, 0x4F0
    r3 = RSP_ADD32(r3, 0X4F0);
L_142C:
    // ldv         $v1[0], 0x0($2)
    rsp.LDV<0>(rsp.vpu.r[1], r2, 0X0);
    // ldv         $v2[0], 0x8($2)
    rsp.LDV<0>(rsp.vpu.r[2], r2, 0X1);
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // sdv         $v1[0], 0x0($3)
    rsp.SDV<0>(rsp.vpu.r[1], r3, 0X0);
    // sdv         $v2[0], 0x8($3)
    rsp.SDV<0>(rsp.vpu.r[2], r3, 0X1);
    // bgtz        $1, L_142C
    if (RSP_SIGNED(r1) > 0) {
        // addi        $3, $3, 0x10
        r3 = RSP_ADD32(r3, 0X10);
        goto L_142C;
    }
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // sll         $1, $25, 8
    r1 = S32(r25) << 8;
    // srl         $1, $1, 8
    r1 = S32(U32(r1) >> 8);
    // addi        $1, $1, 0x0
    r1 = RSP_ADD32(r1, 0X0);
    // sw          $1, 0xE($zero)
    RSP_MEM_W_STORE(0XE, 0, r1);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // lqv         $v31[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X5);
    // srl         $23, $25, 12
    r23 = S32(U32(r25) >> 12);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // andi        $23, $23, 0xF
    r23 = r23 & 0XF;
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // addi        $23, $23, 0x4F0
    r23 = RSP_ADD32(r23, 0X4F0);
L_1484:
    // vxor        $v13, $v13, $v13
    rsp.VXOR<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[13]);
    // andi        $1, $25, 0xFFF
    r1 = r25 & 0XFFF;
    // vxor        $v14, $v14, $v14
    rsp.VXOR<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[14]);
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
    // vxor        $v15, $v15, $v15
    rsp.VXOR<0>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[15]);
    // srl         $21, $25, 16
    r21 = S32(U32(r25) >> 16);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // andi        $21, $21, 0xFFF
    r21 = r21 & 0XFFF;
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // sll         $20, $26, 8
    r20 = S32(r26) << 8;
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // srl         $20, $20, 8
    r20 = S32(U32(r20) >> 8);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    // srl         $13, $25, 28
    r13 = S32(U32(r25) >> 28);
    // andi        $2, $13, 0x1
    r2 = r13 & 0X1;
    // bgtz        $2, L_1530
    if (RSP_SIGNED(r2) > 0) {
        // addi        $22, $23, 0x1
        r22 = RSP_ADD32(r23, 0X1);
        goto L_1530;
    }
    // addi        $22, $23, 0x1
    r22 = RSP_ADD32(r23, 0X1);
    // andi        $2, $13, 0x2
    r2 = r13 & 0X2;
    // beq         $2, $zero, L_14DC
    if (r2 == 0) {
        // addi        $2, $20, 0x0
        r2 = RSP_ADD32(r20, 0X0);
        goto L_14DC;
    }
    // addi        $2, $20, 0x0
    r2 = RSP_ADD32(r20, 0X0);
    // lw          $2, 0xE($zero)
    r2 = RSP_MEM_W_LOAD(0XE, 0);
L_14DC:
    // mfc0        $13, SP_SEMAPHORE
    r13 = 0;
L_14E0:
    // bne         $13, $zero, L_14E0
    if (r13 != 0) {
        // mfc0        $13, SP_SEMAPHORE
        r13 = 0;
        goto L_14E0;
    }
    // mfc0        $13, SP_SEMAPHORE
    r13 = 0;
    // mfc0        $13, SP_DMA_FULL
    r13 = 0;
L_14EC:
    // bne         $13, $zero, L_14EC
    if (r13 != 0) {
        // mfc0        $13, SP_DMA_FULL
        r13 = 0;
        goto L_14EC;
    }
    // mfc0        $13, SP_DMA_FULL
    r13 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // addi        $19, $zero, 0x20
    r19 = RSP_ADD32(0, 0X20);
    // addi        $18, $zero, 0x3F0
    r18 = RSP_ADD32(0, 0X3F0);
    // ldv         $v25[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[25], r19, 0X0);
    // ldv         $v24[8], 0x0($19)
    rsp.LDV<8>(rsp.vpu.r[24], r19, 0X0);
    // ldv         $v23[0], 0x8($19)
    rsp.LDV<0>(rsp.vpu.r[23], r19, 0X1);
    // ldv         $v23[8], 0x8($19)
    rsp.LDV<8>(rsp.vpu.r[23], r19, 0X1);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_151C:
    // bne         $5, $zero, L_151C
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_151C;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_1484
    // lqv         $v27[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, 0X1);
    goto L_1484;
    // lqv         $v27[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, 0X1);
L_1530:
    // addi        $19, $zero, 0x20
    r19 = RSP_ADD32(0, 0X20);
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // addi        $18, $zero, 0x3F0
    r18 = RSP_ADD32(0, 0X3F0);
    // ldv         $v25[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[25], r19, 0X0);
    // ldv         $v24[8], 0x0($19)
    rsp.LDV<8>(rsp.vpu.r[24], r19, 0X0);
    // ldv         $v23[0], 0x8($19)
    rsp.LDV<0>(rsp.vpu.r[23], r19, 0X1);
    // ldv         $v23[8], 0x8($19)
    rsp.LDV<8>(rsp.vpu.r[23], r19, 0X1);
    // sqv         $v27[0], 0x0($1)
    rsp.SQV<0>(rsp.vpu.r[27], r1, 0X0);
    // sqv         $v27[0], 0x10($1)
    rsp.SQV<0>(rsp.vpu.r[27], r1, 0X1);
    // beq         $21, $zero, L_1704
    if (r21 == 0) {
        // addi        $1, $1, 0x20
        r1 = RSP_ADD32(r1, 0X20);
        goto L_1704;
    }
    // addi        $1, $1, 0x20
    r1 = RSP_ADD32(r1, 0X20);
    // ldv         $v12[0], 0x0($22)
    rsp.LDV<0>(rsp.vpu.r[12], r22, 0X0);
    // lbu         $10, 0x0($23)
    r10 = RSP_MEM_BU(0X0, r23);
    // addi        $13, $zero, 0xC
    r13 = RSP_ADD32(0, 0XC);
    // addi        $12, $zero, 0x1
    r12 = RSP_ADD32(0, 0X1);
    // andi        $14, $10, 0xF
    r14 = r10 & 0XF;
    // sll         $14, $14, 5
    r14 = S32(r14) << 5;
    // vand        $v10, $v25, $v12[0]
    rsp.VAND<8>(rsp.vpu.r[10], rsp.vpu.r[25], rsp.vpu.r[12]);
    // add         $16, $14, $18
    r16 = RSP_ADD32(r14, r18);
    // vand        $v9, $v24, $v12[1]
    rsp.VAND<9>(rsp.vpu.r[9], rsp.vpu.r[24], rsp.vpu.r[12]);
    // srl         $17, $10, 4
    r17 = S32(U32(r10) >> 4);
    // vand        $v8, $v25, $v12[2]
    rsp.VAND<10>(rsp.vpu.r[8], rsp.vpu.r[25], rsp.vpu.r[12]);
    // sub         $17, $13, $17
    r17 = RSP_SUB32(r13, r17);
    // vand        $v7, $v24, $v12[3]
    rsp.VAND<11>(rsp.vpu.r[7], rsp.vpu.r[24], rsp.vpu.r[12]);
    // addi        $13, $17, -0x1
    r13 = RSP_ADD32(r17, -0X1);
    // sll         $12, $12, 15
    r12 = S32(r12) << 15;
    // srlv        $11, $12, $13
    r11 = S32(U32(r12) >> (r13 & 31));
    // mtc2        $11, $v22[0]
    rsp.MTC2<0>(r11, rsp.vpu.r[22]);
    // lqv         $v21[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[21], r16, 0X0);
    // lqv         $v20[0], 0x10($16)
    rsp.LQV<0>(rsp.vpu.r[20], r16, 0X1);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v19[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[19], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v18[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[18], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v17[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[17], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v16[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[16], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v15[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[15], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v14[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[14], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v13[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[13], r16, 0X2);
L_15E0:
    // addi        $22, $22, 0x9
    r22 = RSP_ADD32(r22, 0X9);
    // vmudn       $v30, $v10, $v23
    rsp.VMUDN<0>(rsp.vpu.r[30], rsp.vpu.r[10], rsp.vpu.r[23]);
    // addi        $23, $23, 0x9
    r23 = RSP_ADD32(r23, 0X9);
    // vmadn       $v30, $v9, $v23
    rsp.VMADN<0>(rsp.vpu.r[30], rsp.vpu.r[9], rsp.vpu.r[23]);
    // lbu         $10, 0x0($23)
    r10 = RSP_MEM_BU(0X0, r23);
    // vmudn       $v29, $v8, $v23
    rsp.VMUDN<0>(rsp.vpu.r[29], rsp.vpu.r[8], rsp.vpu.r[23]);
    // ldv         $v12[0], 0x0($22)
    rsp.LDV<0>(rsp.vpu.r[12], r22, 0X0);
    // vmadn       $v29, $v7, $v23
    rsp.VMADN<0>(rsp.vpu.r[29], rsp.vpu.r[7], rsp.vpu.r[23]);
    // addi        $13, $zero, 0xC
    r13 = RSP_ADD32(0, 0XC);
    // blez        $17, L_1614
    if (RSP_SIGNED(r17) <= 0) {
        // andi        $14, $10, 0xF
        r14 = r10 & 0XF;
        goto L_1614;
    }
    // andi        $14, $10, 0xF
    r14 = r10 & 0XF;
    // vmudm       $v30, $v30, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[22]);
    // vmudm       $v29, $v29, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[22]);
L_1614:
    // sll         $14, $14, 5
    r14 = S32(r14) << 5;
    // vmudh       $v11, $v21, $v27[6]
    rsp.VMUDH<14>(rsp.vpu.r[11], rsp.vpu.r[21], rsp.vpu.r[27]);
    // add         $16, $14, $18
    r16 = RSP_ADD32(r14, r18);
    // vmadh       $v11, $v20, $v27[7]
    rsp.VMADH<15>(rsp.vpu.r[11], rsp.vpu.r[20], rsp.vpu.r[27]);
    // vmadh       $v11, $v19, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[11], rsp.vpu.r[19], rsp.vpu.r[30]);
    // vmadh       $v11, $v18, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[11], rsp.vpu.r[18], rsp.vpu.r[30]);
    // srl         $17, $10, 4
    r17 = S32(U32(r10) >> 4);
    // vmadh       $v11, $v17, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[11], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadh       $v11, $v16, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[16], rsp.vpu.r[30]);
    // sub         $17, $13, $17
    r17 = RSP_SUB32(r13, r17);
    // vmadh       $v28, $v15, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[15], rsp.vpu.r[30]);
    // addi        $13, $17, -0x1
    r13 = RSP_ADD32(r17, -0X1);
    // vmadh       $v11, $v14, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[11], rsp.vpu.r[14], rsp.vpu.r[30]);
    // vmadh       $v11, $v13, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[11], rsp.vpu.r[13], rsp.vpu.r[30]);
    // vmadh       $v11, $v30, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[30], rsp.vpu.r[31]);
    // srlv        $11, $12, $13
    r11 = S32(U32(r12) >> (r13 & 31));
    // vsar        $v26, $v6, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[6]);
    // mtc2        $11, $v22[0]
    rsp.MTC2<0>(r11, rsp.vpu.r[22]);
    // vsar        $v28, $v6, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[6]);
    // vand        $v10, $v25, $v12[0]
    rsp.VAND<8>(rsp.vpu.r[10], rsp.vpu.r[25], rsp.vpu.r[12]);
    // vand        $v9, $v24, $v12[1]
    rsp.VAND<9>(rsp.vpu.r[9], rsp.vpu.r[24], rsp.vpu.r[12]);
    // vand        $v8, $v25, $v12[2]
    rsp.VAND<10>(rsp.vpu.r[8], rsp.vpu.r[25], rsp.vpu.r[12]);
    // vand        $v7, $v24, $v12[3]
    rsp.VAND<11>(rsp.vpu.r[7], rsp.vpu.r[24], rsp.vpu.r[12]);
    // vmudn       $v11, $v26, $v31[1]
    rsp.VMUDN<9>(rsp.vpu.r[11], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v28, $v28, $v31[1]
    rsp.VMADH<9>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[31]);
    // vmudh       $v11, $v19, $v29[0]
    rsp.VMUDH<8>(rsp.vpu.r[11], rsp.vpu.r[19], rsp.vpu.r[29]);
    // addi        $15, $16, -0x2
    r15 = RSP_ADD32(r16, -0X2);
    // vmadh       $v11, $v18, $v29[1]
    rsp.VMADH<9>(rsp.vpu.r[11], rsp.vpu.r[18], rsp.vpu.r[29]);
    // lrv         $v19[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[19], r15, 0X2);
    // vmadh       $v11, $v17, $v29[2]
    rsp.VMADH<10>(rsp.vpu.r[11], rsp.vpu.r[17], rsp.vpu.r[29]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v16, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[16], rsp.vpu.r[29]);
    // lrv         $v18[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[18], r15, 0X2);
    // vmadh       $v11, $v15, $v29[4]
    rsp.VMADH<12>(rsp.vpu.r[11], rsp.vpu.r[15], rsp.vpu.r[29]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v14, $v29[5]
    rsp.VMADH<13>(rsp.vpu.r[11], rsp.vpu.r[14], rsp.vpu.r[29]);
    // lrv         $v17[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[17], r15, 0X2);
    // vmadh       $v11, $v13, $v29[6]
    rsp.VMADH<14>(rsp.vpu.r[11], rsp.vpu.r[13], rsp.vpu.r[29]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v29, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[29], rsp.vpu.r[31]);
    // lrv         $v16[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[16], r15, 0X2);
    // vmadh       $v11, $v21, $v28[6]
    rsp.VMADH<14>(rsp.vpu.r[11], rsp.vpu.r[21], rsp.vpu.r[28]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v20, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[11], rsp.vpu.r[20], rsp.vpu.r[28]);
    // lrv         $v15[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[15], r15, 0X2);
    // vsar        $v26, $v6, $v27[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[6]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vsar        $v27, $v6, $v27[0]
    rsp.VSAR<8>(rsp.vpu.r[27], rsp.vpu.r[6]);
    // lrv         $v14[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[14], r15, 0X2);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // lrv         $v13[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[13], r15, 0X2);
    // lqv         $v21[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[21], r16, 0X0);
    // vmudn       $v11, $v26, $v31[1]
    rsp.VMUDN<9>(rsp.vpu.r[11], rsp.vpu.r[26], rsp.vpu.r[31]);
    // lqv         $v20[0], 0x10($16)
    rsp.LQV<0>(rsp.vpu.r[20], r16, 0X1);
    // vmadh       $v27, $v27, $v31[1]
    rsp.VMADH<9>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $21, $21, -0x20
    r21 = RSP_ADD32(r21, -0X20);
    // sqv         $v28[0], 0x0($1)
    rsp.SQV<0>(rsp.vpu.r[28], r1, 0X0);
    // addi        $1, $1, 0x20
    r1 = RSP_ADD32(r1, 0X20);
    // bgtz        $21, L_15E0
    if (RSP_SIGNED(r21) > 0) {
        // sqv         $v27[0], 0x7F0($1)
        rsp.SQV<0>(rsp.vpu.r[27], r1, -0X1);
        goto L_15E0;
    }
    // sqv         $v27[0], 0x7F0($1)
    rsp.SQV<0>(rsp.vpu.r[27], r1, -0X1);
L_1704:
    // addi        $1, $1, -0x20
    r1 = RSP_ADD32(r1, -0X20);
    // jal         0x1174
    r31 = 0x1710;
    // addi        $2, $20, 0x0
    r2 = RSP_ADD32(r20, 0X0);
    goto L_1174;
    // addi        $2, $20, 0x0
    r2 = RSP_ADD32(r20, 0X0);
L_1710:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1718:
    // bne         $5, $zero, L_1718
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1718;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
    // srl         $19, $25, 24
    r19 = S32(U32(r25) >> 24);
    // addi        $20, $zero, 0x3F0
    r20 = RSP_ADD32(0, 0X3F0);
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // beq         $19, $zero, L_1740
    if (r19 == 0) {
        // addi        $23, $zero, 0x4F0
        r23 = RSP_ADD32(0, 0X4F0);
        goto L_1740;
    }
    // addi        $23, $zero, 0x4F0
    r23 = RSP_ADD32(0, 0X4F0);
    // addi        $23, $zero, 0x660
    r23 = RSP_ADD32(0, 0X660);
L_1740:
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // mtc2        $26, $v18[10]
    rsp.MTC2<10>(r26, rsp.vpu.r[18]);
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // sll         $26, $26, 2
    r26 = S32(r26) << 2;
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // mtc2        $26, $v20[0]
    rsp.MTC2<0>(r26, rsp.vpu.r[20]);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // vxor        $v26, $v26, $v26
    rsp.VXOR<0>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[26]);
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
L_176C:
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    // addi        $19, $zero, 0x4
    r19 = RSP_ADD32(0, 0X4);
L_177C:
    // mtc2        $19, $v18[0]
    rsp.MTC2<0>(r19, rsp.vpu.r[18]);
    // addi        $22, $zero, 0x170
    r22 = RSP_ADD32(0, 0X170);
    // vmudm       $v20, $v28, $v20[0]
    rsp.VMUDM<8>(rsp.vpu.r[20], rsp.vpu.r[28], rsp.vpu.r[20]);
    // srl         $19, $26, 18
    r19 = S32(U32(r26) >> 18);
    // andi        $19, $19, 0x1
    r19 = r19 & 0X1;
    // bgtz        $19, L_1810
    if (RSP_SIGNED(r19) > 0) {
        // sqv         $v20[0], 0x10($20)
        rsp.SQV<0>(rsp.vpu.r[20], r20, 0X1);
        goto L_1810;
    }
    // sqv         $v20[0], 0x10($20)
    rsp.SQV<0>(rsp.vpu.r[20], r20, 0X1);
    // addi        $1, $24, 0x0
    r1 = RSP_ADD32(r24, 0X0);
    // mfc0        $19, SP_SEMAPHORE
    r19 = 0;
L_17A0:
    // bne         $19, $zero, L_17A0
    if (r19 != 0) {
        // mfc0        $19, SP_SEMAPHORE
        r19 = 0;
        goto L_17A0;
    }
    // mfc0        $19, SP_SEMAPHORE
    r19 = 0;
    // mfc0        $19, SP_DMA_FULL
    r19 = 0;
L_17AC:
    // bne         $19, $zero, L_17AC
    if (r19 != 0) {
        // mfc0        $19, SP_DMA_FULL
        r19 = 0;
        goto L_17AC;
    }
    // mfc0        $19, SP_DMA_FULL
    r19 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
L_17C4:
    // lrv         $v27[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[27], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v26[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[26], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v25[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[25], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v24[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[24], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v23[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[23], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v22[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[22], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
L_17F4:
    // lrv         $v21[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[21], r20, 0X2);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_17FC:
    // bne         $5, $zero, L_17FC
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_17FC;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_177C
    // ldv         $v30[8], 0x0($1)
    rsp.LDV<8>(rsp.vpu.r[30], r1, 0X0);
    goto L_177C;
    // ldv         $v30[8], 0x0($1)
    rsp.LDV<8>(rsp.vpu.r[30], r1, 0X0);
L_1810:
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // vxor        $v30, $v30, $v30
    rsp.VXOR<0>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[30]);
    // lrv         $v27[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[27], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v26[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[26], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v25[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[25], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v24[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[24], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v23[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[23], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v22[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[22], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v21[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[21], r20, 0X2);
    // lqv         $v31[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[31], r23, 0X0);
L_1850:
    // vmudh       $v20, $v28, $v30[7]
    rsp.VMUDH<15>(rsp.vpu.r[20], rsp.vpu.r[28], rsp.vpu.r[30]);
    // vmadh       $v20, $v27, $v31[0]
    rsp.VMADH<8>(rsp.vpu.r[20], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $22, $22, -0x10
    r22 = RSP_ADD32(r22, -0X10);
    // vmadh       $v20, $v26, $v31[1]
    rsp.VMADH<9>(rsp.vpu.r[20], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v20, $v25, $v31[2]
    rsp.VMADH<10>(rsp.vpu.r[20], rsp.vpu.r[25], rsp.vpu.r[31]);
    // sqv         $v30[0], 0x7F0($23)
    rsp.SQV<0>(rsp.vpu.r[30], r23, -0X1);
    // vmadh       $v20, $v24, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[20], rsp.vpu.r[24], rsp.vpu.r[31]);
    // vmadh       $v30, $v23, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[30], rsp.vpu.r[23], rsp.vpu.r[31]);
    // vmadh       $v20, $v22, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[20], rsp.vpu.r[22], rsp.vpu.r[31]);
    // vmadh       $v20, $v21, $v31[6]
    rsp.VMADH<14>(rsp.vpu.r[20], rsp.vpu.r[21], rsp.vpu.r[31]);
    // vmadh       $v20, $v31, $v18[5]
    rsp.VMADH<13>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[18]);
L_187C:
    // lqv         $v31[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[31], r23, 0X1);
    // vsar        $v29, $v19, $v30[1]
    rsp.VSAR<9>(rsp.vpu.r[29], rsp.vpu.r[19]);
    // vsar        $v30, $v19, $v30[0]
    rsp.VSAR<8>(rsp.vpu.r[30], rsp.vpu.r[19]);
    // vmudn       $v20, $v29, $v18[0]
    rsp.VMUDN<8>(rsp.vpu.r[20], rsp.vpu.r[29], rsp.vpu.r[18]);
    // vmadh       $v30, $v30, $v18[0]
    rsp.VMADH<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[18]);
    // bgtz        $22, L_1850
    if (RSP_SIGNED(r22) > 0) {
        // addi        $23, $23, 0x10
        r23 = RSP_ADD32(r23, 0X10);
        goto L_1850;
    }
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
    // addi        $1, $23, -0x8
    r1 = RSP_ADD32(r23, -0X8);
    // jal         0x1174
    r31 = 0x18A4;
    // sqv         $v30[0], 0x7F0($23)
    rsp.SQV<0>(rsp.vpu.r[30], r23, -0X1);
    goto L_1174;
    // sqv         $v30[0], 0x7F0($23)
    rsp.SQV<0>(rsp.vpu.r[30], r23, -0X1);
L_18A4:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_18AC:
    // bne         $5, $zero, L_18AC
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_18AC;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
    // sll         $2, $26, 8
    r2 = S32(r26) << 8;
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // addi        $3, $zero, 0xF
    r3 = RSP_ADD32(0, 0XF);
    // srl         $21, $25, 30
    r21 = S32(U32(r25) >> 30);
    // bgtz        $21, L_1930
    if (RSP_SIGNED(r21) > 0) {
        // addi        $1, $24, 0x0
        r1 = RSP_ADD32(r24, 0X0);
        goto L_1930;
    }
    // addi        $1, $24, 0x0
    r1 = RSP_ADD32(r24, 0X0);
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_18E0:
    // bne         $4, $zero, L_18E0
    if (r4 != 0) {
        // mfc0        $4, SP_SEMAPHORE
        r4 = 0;
        goto L_18E0;
    }
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_18EC:
    // bne         $4, $zero, L_18EC
    if (r4 != 0) {
        // mfc0        $4, SP_DMA_FULL
        r4 = 0;
        goto L_18EC;
    }
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // srl         $20, $25, 2
    r20 = S32(U32(r25) >> 2);
    // andi        $20, $20, 0xFFF
    r20 = r20 & 0XFFF;
    // addi        $20, $20, 0x4E8
    r20 = RSP_ADD32(r20, 0X4E8);
    // lqv         $v31[0], 0x40($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X4);
    // lqv         $v25[0], 0x30($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X3);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1918:
    // bne         $5, $zero, L_1918
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1918;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // ldv         $v19[0], 0x0($24)
    rsp.LDV<0>(rsp.vpu.r[19], r24, 0X0);
    // j           L_187C
    // lsv         $v24[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[24], r24, 0X4);
    goto L_187C;
    // lsv         $v24[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[24], r24, 0X4);
L_1930:
    // srl         $20, $25, 2
    r20 = S32(U32(r25) >> 2);
    // andi        $20, $20, 0xFFF
    r20 = r20 & 0XFFF;
L_1938:
    // addi        $20, $20, 0x4E8
    r20 = RSP_ADD32(r20, 0X4E8);
L_193C:
    // lqv         $v31[0], 0x40($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X4);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // lqv         $v25[0], 0x30($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X3);
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // mtc2        $20, $v21[4]
    rsp.MTC2<4>(r20, rsp.vpu.r[21]);
    // addi        $4, $zero, 0xB0
    r4 = RSP_ADD32(0, 0XB0);
    // mtc2        $4, $v21[6]
    rsp.MTC2<6>(r4, rsp.vpu.r[21]);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // srl         $4, $25, 14
    r4 = S32(U32(r25) >> 14);
    // mtc2        $4, $v21[8]
    rsp.MTC2<8>(r4, rsp.vpu.r[21]);
    // addi        $4, $zero, 0x40
    r4 = RSP_ADD32(0, 0X40);
    // mtc2        $4, $v21[10]
    rsp.MTC2<10>(r4, rsp.vpu.r[21]);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v30[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[30], 0, 0X5);
    // lqv         $v29[0], 0x60($zero)
    rsp.LQV<0>(rsp.vpu.r[29], 0, 0X6);
    // lqv         $v28[0], 0x70($zero)
    rsp.LQV<0>(rsp.vpu.r[28], 0, 0X7);
    // vmudm       $v24, $v31, $v24[7]
    rsp.VMUDM<15>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x80($zero)
    rsp.LQV<0>(rsp.vpu.r[27], 0, 0X8);
    // vmadm       $v23, $v25, $v21[4]
    rsp.VMADM<12>(rsp.vpu.r[23], rsp.vpu.r[25], rsp.vpu.r[21]);
    // lqv         $v26[0], 0x90($zero)
    rsp.LQV<0>(rsp.vpu.r[26], 0, 0X9);
    // vmadn       $v24, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[30]);
    // sdv         $v19[0], 0x0($20)
    rsp.SDV<0>(rsp.vpu.r[19], r20, 0X0);
    // lqv         $v25[0], 0x30($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X3);
    // vmudn       $v22, $v31, $v21[2]
    rsp.VMUDN<10>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[21]);
    // addi        $22, $zero, 0x170
    r22 = RSP_ADD32(0, 0X170);
    // vmadn       $v22, $v23, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[22], rsp.vpu.r[23], rsp.vpu.r[30]);
    // andi        $4, $25, 0x3
    r4 = r25 & 0X3;
    // vmudl       $v20, $v24, $v21[5]
    rsp.VMUDL<13>(rsp.vpu.r[20], rsp.vpu.r[24], rsp.vpu.r[21]);
    // beq         $4, $zero, L_19B8
    if (r4 == 0) {
        // addi        $23, $zero, 0x4F0
        r23 = RSP_ADD32(0, 0X4F0);
        goto L_19B8;
    }
    // addi        $23, $zero, 0x4F0
    r23 = RSP_ADD32(0, 0X4F0);
    // addi        $23, $zero, 0x660
    r23 = RSP_ADD32(0, 0X660);
L_19B8:
    // ssv         $v24[7], 0x8($24)
    rsp.SSV<7>(rsp.vpu.r[24], r24, 0X4);
    // vmudn       $v20, $v20, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[30]);
    // sqv         $v22[0], 0x7B0($zero)
    rsp.SQV<0>(rsp.vpu.r[22], 0, -0X5);
    // vmadn       $v20, $v31, $v21[3]
    rsp.VMADN<11>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[21]);
    // sqv         $v20[0], 0x7C0($zero)
    rsp.SQV<0>(rsp.vpu.r[20], 0, -0X4);
    // lh          $21, 0xFB0($zero)
    r21 = RSP_MEM_H_LOAD(0XFB0, 0);
    // lh          $13, 0xFC0($zero)
    r13 = RSP_MEM_H_LOAD(0XFC0, 0);
    // lh          $17, 0xFB8($zero)
    r17 = RSP_MEM_H_LOAD(0XFB8, 0);
    // lh          $9, 0xFC8($zero)
    r9 = RSP_MEM_H_LOAD(0XFC8, 0);
    // lh          $20, 0xFB2($zero)
    r20 = RSP_MEM_H_LOAD(0XFB2, 0);
    // lh          $12, 0xFC2($zero)
    r12 = RSP_MEM_H_LOAD(0XFC2, 0);
    // lh          $16, 0xFBA($zero)
    r16 = RSP_MEM_H_LOAD(0XFBA, 0);
    // lh          $8, 0xFCA($zero)
    r8 = RSP_MEM_H_LOAD(0XFCA, 0);
    // lh          $19, 0xFB4($zero)
    r19 = RSP_MEM_H_LOAD(0XFB4, 0);
    // lh          $11, 0xFC4($zero)
    r11 = RSP_MEM_H_LOAD(0XFC4, 0);
    // lh          $15, 0xFBC($zero)
    r15 = RSP_MEM_H_LOAD(0XFBC, 0);
    // lh          $7, 0xFCC($zero)
    r7 = RSP_MEM_H_LOAD(0XFCC, 0);
    // lh          $18, 0xFB6($zero)
    r18 = RSP_MEM_H_LOAD(0XFB6, 0);
    // lh          $10, 0xFC6($zero)
    r10 = RSP_MEM_H_LOAD(0XFC6, 0);
    // lh          $14, 0xFBE($zero)
    r14 = RSP_MEM_H_LOAD(0XFBE, 0);
    // lh          $6, 0xFCE($zero)
    r6 = RSP_MEM_H_LOAD(0XFCE, 0);
    // ldv         $v19[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[19], r21, 0X0);
    // vmudm       $v24, $v31, $v24[7]
    rsp.VMUDM<15>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[24]);
    // ldv         $v18[0], 0x0($13)
    rsp.LDV<0>(rsp.vpu.r[18], r13, 0X0);
    // vmadh       $v24, $v31, $v23[7]
    rsp.VMADH<15>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[23]);
    // ldv         $v19[8], 0x0($17)
    rsp.LDV<8>(rsp.vpu.r[19], r17, 0X0);
    // vmadm       $v23, $v25, $v21[4]
    rsp.VMADM<12>(rsp.vpu.r[23], rsp.vpu.r[25], rsp.vpu.r[21]);
    // ldv         $v18[8], 0x0($9)
    rsp.LDV<8>(rsp.vpu.r[18], r9, 0X0);
    // vmadn       $v24, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[30]);
    // ldv         $v17[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[17], r20, 0X0);
    // vmudn       $v22, $v31, $v21[2]
    rsp.VMUDN<10>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[21]);
    // ldv         $v16[0], 0x0($12)
    rsp.LDV<0>(rsp.vpu.r[16], r12, 0X0);
    // ldv         $v17[8], 0x0($16)
    rsp.LDV<8>(rsp.vpu.r[17], r16, 0X0);
    // vmadn       $v22, $v23, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[22], rsp.vpu.r[23], rsp.vpu.r[30]);
    // ldv         $v16[8], 0x0($8)
    rsp.LDV<8>(rsp.vpu.r[16], r8, 0X0);
    // vmudl       $v20, $v24, $v21[5]
    rsp.VMUDL<13>(rsp.vpu.r[20], rsp.vpu.r[24], rsp.vpu.r[21]);
    // ldv         $v15[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[15], r19, 0X0);
    // ldv         $v14[0], 0x0($11)
    rsp.LDV<0>(rsp.vpu.r[14], r11, 0X0);
    // ldv         $v15[8], 0x0($15)
    rsp.LDV<8>(rsp.vpu.r[15], r15, 0X0);
    // ldv         $v14[8], 0x0($7)
    rsp.LDV<8>(rsp.vpu.r[14], r7, 0X0);
    // vmudn       $v20, $v20, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[30]);
    // ldv         $v13[0], 0x0($18)
    rsp.LDV<0>(rsp.vpu.r[13], r18, 0X0);
    // vmadn       $v20, $v31, $v21[3]
    rsp.VMADN<11>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[21]);
    // ldv         $v12[0], 0x0($10)
    rsp.LDV<0>(rsp.vpu.r[12], r10, 0X0);
    // ldv         $v13[8], 0x0($14)
    rsp.LDV<8>(rsp.vpu.r[13], r14, 0X0);
    // vmulf       $v11, $v19, $v18
    rsp.VMULF<0>(rsp.vpu.r[11], rsp.vpu.r[19], rsp.vpu.r[18]);
    // ldv         $v12[8], 0x0($6)
    rsp.LDV<8>(rsp.vpu.r[12], r6, 0X0);
    // vmulf       $v10, $v17, $v16
    rsp.VMULF<0>(rsp.vpu.r[10], rsp.vpu.r[17], rsp.vpu.r[16]);
    // sqv         $v22[0], 0x7B0($zero)
    rsp.SQV<0>(rsp.vpu.r[22], 0, -0X5);
    // vmulf       $v9, $v15, $v14
    rsp.VMULF<0>(rsp.vpu.r[9], rsp.vpu.r[15], rsp.vpu.r[14]);
    // sqv         $v20[0], 0x7C0($zero)
    rsp.SQV<0>(rsp.vpu.r[20], 0, -0X4);
    // lh          $21, 0xFB0($zero)
    r21 = RSP_MEM_H_LOAD(0XFB0, 0);
    // lh          $13, 0xFC0($zero)
    r13 = RSP_MEM_H_LOAD(0XFC0, 0);
    // vmulf       $v8, $v13, $v12
    rsp.VMULF<0>(rsp.vpu.r[8], rsp.vpu.r[13], rsp.vpu.r[12]);
    // lh          $17, 0xFB8($zero)
    r17 = RSP_MEM_H_LOAD(0XFB8, 0);
    // vadd        $v11, $v11, $v11[1q]
    rsp.VADD<3>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[11]);
    // lh          $9, 0xFC8($zero)
    r9 = RSP_MEM_H_LOAD(0XFC8, 0);
    // vadd        $v10, $v10, $v10[1q]
    rsp.VADD<3>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[10]);
    // lh          $20, 0xFB2($zero)
    r20 = RSP_MEM_H_LOAD(0XFB2, 0);
    // vadd        $v9, $v9, $v9[1q]
    rsp.VADD<3>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[9]);
    // lh          $12, 0xFC2($zero)
    r12 = RSP_MEM_H_LOAD(0XFC2, 0);
    // vadd        $v8, $v8, $v8[1q]
    rsp.VADD<3>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $16, 0xFBA($zero)
    r16 = RSP_MEM_H_LOAD(0XFBA, 0);
    // vadd        $v11, $v11, $v11[2h]
    rsp.VADD<6>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[11]);
    // lh          $8, 0xFCA($zero)
    r8 = RSP_MEM_H_LOAD(0XFCA, 0);
    // vadd        $v10, $v10, $v10[2h]
    rsp.VADD<6>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[10]);
    // lh          $19, 0xFB4($zero)
    r19 = RSP_MEM_H_LOAD(0XFB4, 0);
    // vadd        $v9, $v9, $v9[2h]
    rsp.VADD<6>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[9]);
    // lh          $11, 0xFC4($zero)
    r11 = RSP_MEM_H_LOAD(0XFC4, 0);
    // vadd        $v8, $v8, $v8[2h]
    rsp.VADD<6>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $15, 0xFBC($zero)
    r15 = RSP_MEM_H_LOAD(0XFBC, 0);
    // vmudn       $v7, $v29, $v11[0h]
    rsp.VMUDN<4>(rsp.vpu.r[7], rsp.vpu.r[29], rsp.vpu.r[11]);
    // lh          $7, 0xFCC($zero)
    r7 = RSP_MEM_H_LOAD(0XFCC, 0);
    // vmadn       $v7, $v28, $v10[0h]
    rsp.VMADN<4>(rsp.vpu.r[7], rsp.vpu.r[28], rsp.vpu.r[10]);
    // lh          $18, 0xFB6($zero)
    r18 = RSP_MEM_H_LOAD(0XFB6, 0);
    // vmadn       $v7, $v27, $v9[0h]
    rsp.VMADN<4>(rsp.vpu.r[7], rsp.vpu.r[27], rsp.vpu.r[9]);
    // lh          $10, 0xFC6($zero)
    r10 = RSP_MEM_H_LOAD(0XFC6, 0);
    // vmadn       $v7, $v26, $v8[0h]
    rsp.VMADN<4>(rsp.vpu.r[7], rsp.vpu.r[26], rsp.vpu.r[8]);
    // lh          $14, 0xFBE($zero)
    r14 = RSP_MEM_H_LOAD(0XFBE, 0);
    // lh          $6, 0xFCE($zero)
    r6 = RSP_MEM_H_LOAD(0XFCE, 0);
    // addi        $22, $22, -0x10
    r22 = RSP_ADD32(r22, -0X10);
    // blez        $22, L_1B0C
    if (RSP_SIGNED(r22) <= 0) {
        // sqv         $v7[0], 0x0($23)
        rsp.SQV<0>(rsp.vpu.r[7], r23, 0X0);
        goto L_1B0C;
    }
    // sqv         $v7[0], 0x0($23)
    rsp.SQV<0>(rsp.vpu.r[7], r23, 0X0);
    // j           L_193C
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
    goto L_193C;
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
L_1B0C:
    // ldv         $v19[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[19], r21, 0X0);
    // ssv         $v24[0], 0x8($24)
    rsp.SSV<0>(rsp.vpu.r[24], r24, 0X4);
    // jal         0x1174
    r31 = 0x1B1C;
    // sdv         $v19[0], 0x0($24)
    rsp.SDV<0>(rsp.vpu.r[19], r24, 0X0);
    goto L_1174;
    // sdv         $v19[0], 0x0($24)
    rsp.SDV<0>(rsp.vpu.r[19], r24, 0X0);
L_1B1C:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1B24:
    // bne         $5, $zero, L_1B24
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1B24;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1B2C:
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // lqv         $v31[0], 0x40($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X4);
    // lqv         $v10[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[10], 0, 0X5);
    // lqv         $v30[0], 0xA0($zero)
    rsp.LQV<0>(rsp.vpu.r[30], 0, 0XA);
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // srl         $14, $26, 16
    r14 = S32(U32(r26) >> 16);
    // andi        $15, $14, 0x1
    r15 = r14 & 0X1;
    // bgtz        $15, L_1B88
    if (RSP_SIGNED(r15) > 0) {
        // addi        $1, $24, 0x0
        r1 = RSP_ADD32(r24, 0X0);
        goto L_1B88;
    }
    // addi        $1, $24, 0x0
    r1 = RSP_ADD32(r24, 0X0);
L_1B60:
    // jal         0x114C
    r31 = 0x1B68;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    goto L_114C;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
L_1B68:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1B6C:
    // bne         $5, $zero, L_1B6C
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1B6C;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // lqv         $v20[0], 0x0($24)
    rsp.LQV<0>(rsp.vpu.r[20], r24, 0X0);
    // lqv         $v21[0], 0x10($24)
    rsp.LQV<0>(rsp.vpu.r[21], r24, 0X1);
    // lqv         $v18[0], 0x20($24)
    rsp.LQV<0>(rsp.vpu.r[18], r24, 0X2);
    // lqv         $v19[0], 0x30($24)
    rsp.LQV<0>(rsp.vpu.r[19], r24, 0X3);
L_1B88:
    // lqv         $v24[0], 0x40($24)
    rsp.LQV<0>(rsp.vpu.r[24], r24, 0X4);
    // addi        $16, $zero, 0x4F0
    r16 = RSP_ADD32(0, 0X4F0);
    // addi        $21, $zero, 0x9D0
    r21 = RSP_ADD32(0, 0X9D0);
    // addi        $20, $zero, 0xB40
    r20 = RSP_ADD32(0, 0XB40);
    // addi        $19, $zero, 0xCB0
    r19 = RSP_ADD32(0, 0XCB0);
    // addi        $18, $zero, 0xE20
    r18 = RSP_ADD32(0, 0XE20);
    // addi        $17, $zero, 0x170
    r17 = RSP_ADD32(0, 0X170);
    // mfc2        $22, $v24[8]
    rsp.MFC2<8>(r22, rsp.vpu.r[24]);
    // beq         $15, $zero, L_1C78
    if (r15 == 0) {
        // mfc2        $23, $v24[2]
        rsp.MFC2<2>(r23, rsp.vpu.r[24]);
        goto L_1C78;
    }
    // mfc2        $23, $v24[2]
    rsp.MFC2<2>(r23, rsp.vpu.r[24]);
L_1BB0:
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    // vxor        $v20, $v20, $v20
    rsp.VXOR<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[20]);
    // lsv         $v20[14], 0x50($24)
    rsp.LSV<14>(rsp.vpu.r[20], r24, 0X28);
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // lqv         $v17[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[17], r16, 0X0);
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // mtc2        $26, $v18[14]
    rsp.MTC2<14>(r26, rsp.vpu.r[18]);
    // vmudl       $v23, $v30, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
L_1BD0:
    // lqv         $v29[0], 0x0($21)
    rsp.LQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vmadn       $v23, $v30, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmadh       $v20, $v31, $v20[7]
    rsp.VMADH<15>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[20]);
    // lqv         $v28[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X0);
L_1BE4:
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
    // bgez        $23, L_1BF8
    if (RSP_SIGNED(r23) >= 0) {
        // vxor        $v19, $v19, $v19
        rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
        goto L_1BF8;
    }
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // j           L_1B2C
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    goto L_1B2C;
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1BF8:
    // vlt         $v20, $v20, $v24[0]
    rsp.VLT<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmudl       $v23, $v30, $v24[5]
    rsp.VMUDL<13>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // lqv         $v26[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[26], r18, 0X0);
    // vmadn       $v23, $v30, $v24[4]
    rsp.VMADN<12>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // addi        $17, $17, -0x10
    r17 = RSP_ADD32(r17, -0X10);
    // vmadh       $v18, $v31, $v18[7]
    rsp.VMADH<15>(rsp.vpu.r[18], rsp.vpu.r[31], rsp.vpu.r[18]);
    // addi        $16, $16, 0x10
    r16 = RSP_ADD32(r16, 0X10);
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // bgez        $22, L_1C2C
    if (RSP_SIGNED(r22) >= 0) {
        // vmulf       $v15, $v20, $v24[7]
        rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
        goto L_1C2C;
    }
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // j           L_1B60
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    goto L_1B60;
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1C2C:
    // vlt         $v18, $v18, $v24[3]
    rsp.VLT<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v29, $v29, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v27, $v27, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // sqv         $v29[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vmulf       $v28, $v28, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmulf       $v26, $v26, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[28], r20, 0X0);
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // sqv         $v26[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[26], r18, 0X0);
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
L_1C78:
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // lqv         $v29[0], 0x0($21)
    rsp.LQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vaddc       $v19, $v19, $v24[5]
    rsp.VADDC<13>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[24]);
    // lqv         $v17[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[17], r16, 0X0);
    // bgez        $23, L_1C9C
    if (RSP_SIGNED(r23) >= 0) {
        // vadd        $v18, $v18, $v24[4]
        rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
        goto L_1C9C;
    }
    // vadd        $v18, $v18, $v24[4]
    rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // j           L_1BD0
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    goto L_1BD0;
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C9C:
    // vlt         $v20, $v20, $v24[0]
    rsp.VLT<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // bgez        $22, L_1CB0
    if (RSP_SIGNED(r22) >= 0) {
        // lqv         $v27[0], 0x0($19)
        rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
        goto L_1CB0;
    }
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // j           L_1BE4
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    goto L_1BE4;
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1CB0:
    // vlt         $v18, $v18, $v24[3]
    rsp.VLT<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v20[0], 0x0($24)
    rsp.SQV<0>(rsp.vpu.r[20], r24, 0X0);
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v21[0], 0x10($24)
    rsp.SQV<0>(rsp.vpu.r[21], r24, 0X1);
    // vmulf       $v29, $v29, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // lqv         $v28[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X0);
    // vmulf       $v27, $v27, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // lqv         $v26[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[26], r18, 0X0);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // addi        $17, $17, -0x10
    r17 = RSP_ADD32(r17, -0X10);
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // addi        $16, $16, 0x10
    r16 = RSP_ADD32(r16, 0X10);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v29[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmulf       $v28, $v28, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v26, $v26, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[28], r20, 0X0);
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // blez        $17, L_1D2C
    if (RSP_SIGNED(r17) <= 0) {
        // sqv         $v26[0], 0x0($18)
        rsp.SQV<0>(rsp.vpu.r[26], r18, 0X0);
        goto L_1D2C;
    }
    // sqv         $v26[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[26], r18, 0X0);
    // j           L_1BB0
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
    goto L_1BB0;
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
L_1D2C:
    // sqv         $v18[0], 0x20($24)
    rsp.SQV<0>(rsp.vpu.r[18], r24, 0X2);
    // sqv         $v19[0], 0x30($24)
    rsp.SQV<0>(rsp.vpu.r[19], r24, 0X3);
    // jal         0x1174
    r31 = 0x1D3C;
    // sqv         $v24[0], 0x40($24)
    rsp.SQV<0>(rsp.vpu.r[24], r24, 0X4);
    goto L_1174;
    // sqv         $v24[0], 0x40($24)
    rsp.SQV<0>(rsp.vpu.r[24], r24, 0X4);
L_1D3C:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1D40:
    // bne         $5, $zero, L_1D40
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1D40;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // lqv         $v31[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X5);
    // andi        $22, $25, 0xFFFF
    r22 = r25 & 0XFFFF;
    // addi        $22, $22, 0x4F0
    r22 = RSP_ADD32(r22, 0X4F0);
    // lqv         $v28[0], 0x0($22)
    rsp.LQV<0>(rsp.vpu.r[28], r22, 0X0);
    // srl         $23, $25, 16
    r23 = S32(U32(r25) >> 16);
    // addi        $23, $23, 0x4F0
    r23 = RSP_ADD32(r23, 0X4F0);
    // lqv         $v29[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[29], r23, 0X0);
    // mtc2        $26, $v30[0]
    rsp.MTC2<0>(r26, rsp.vpu.r[30]);
    // addi        $21, $zero, 0x170
    r21 = RSP_ADD32(0, 0X170);
L_1D78:
    // vmulf       $v27, $v28, $v31[5]
    rsp.VMULF<13>(rsp.vpu.r[27], rsp.vpu.r[28], rsp.vpu.r[31]);
    // addi        $21, $21, -0x10
    r21 = RSP_ADD32(r21, -0X10);
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
    // addi        $22, $22, 0x10
    r22 = RSP_ADD32(r22, 0X10);
    // vmacf       $v27, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[27], rsp.vpu.r[29], rsp.vpu.r[30]);
    // lqv         $v28[0], 0x0($22)
    rsp.LQV<0>(rsp.vpu.r[28], r22, 0X0);
    // lqv         $v29[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[29], r23, 0X0);
    // bgtz        $21, L_1D78
    if (RSP_SIGNED(r21) > 0) {
        // sqv         $v27[0], 0x7F0($22)
        rsp.SQV<0>(rsp.vpu.r[27], r22, -0X1);
        goto L_1D78;
    }
    // sqv         $v27[0], 0x7F0($22)
    rsp.SQV<0>(rsp.vpu.r[27], r22, -0X1);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // nop

    // nop

    // nop

    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // lqv         $v31[0], 0x1B0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X1B);
    // lqv         $v30[0], 0x1C0($zero)
    rsp.LQV<0>(rsp.vpu.r[30], 0, 0X1C);
    // addi        $23, $zero, 0xBA8
    r23 = RSP_ADD32(0, 0XBA8);
    // vadd        $v1, $v0, $v0
    rsp.VADD<0>(rsp.vpu.r[1], rsp.vpu.r[0], rsp.vpu.r[0]);
    // addi        $22, $zero, 0xD00
    r22 = RSP_ADD32(0, 0XD00);
    // vsub        $v1, $v0, $v31[0]
    rsp.VSUB<8>(rsp.vpu.r[1], rsp.vpu.r[0], rsp.vpu.r[31]);
    // lw          $11, 0xF0($zero)
    r11 = RSP_MEM_W_LOAD(0XF0, 0);
    // lw          $12, 0xFC4($zero)
    r12 = RSP_MEM_W_LOAD(0XFC4, 0);
    // addi        $1, $zero, 0x2800
    r1 = RSP_ADD32(0, 0X2800);
    // beq         $11, $zero, L_1DF4
    if (r11 == 0) {
        // mtc0        $1, SP_STATUS
            goto L_1DF4;
    }
    // mtc0        $1, SP_STATUS
    // andi        $12, $12, 0x1
    r12 = r12 & 0X1;
    // beq         $12, $zero, L_1E60
    if (r12 == 0) {
        // sw          $zero, 0xFC4($zero)
        RSP_MEM_W_STORE(0XFC4, 0, 0);
        goto L_1E60;
    }
    // sw          $zero, 0xFC4($zero)
    RSP_MEM_W_STORE(0XFC4, 0, 0);
    // j           L_1168
    // lw          $26, 0xBF8($zero)
    r26 = RSP_MEM_W_LOAD(0XBF8, 0);
    goto L_1168;
    // lw          $26, 0xBF8($zero)
    r26 = RSP_MEM_W_LOAD(0XBF8, 0);
L_1DF4:
    // mfc0        $11, DPC_STATUS
    r11 = 0;
    // andi        $11, $11, 0x1
    r11 = r11 & 0X1;
    // bne         $11, $zero, L_1E2C
    if (r11 != 0) {
        // mfc0        $2, DPC_END
        r2 = 0;
        goto L_1E2C;
    }
    // mfc0        $2, DPC_END
    r2 = 0;
    // lw          $3, 0xFE8($zero)
    r3 = RSP_MEM_W_LOAD(0XFE8, 0);
    // sub         $11, $3, $2
    r11 = RSP_SUB32(r3, r2);
    // bgtz        $11, L_1E2C
    if (RSP_SIGNED(r11) > 0) {
        // mfc0        $1, DPC_CURRENT
        r1 = 0;
        goto L_1E2C;
    }
    // mfc0        $1, DPC_CURRENT
    r1 = 0;
    // lw          $4, 0xFEC($zero)
    r4 = RSP_MEM_W_LOAD(0XFEC, 0);
    // beq         $1, $zero, L_1E2C
    if (r1 == 0) {
        // sub         $11, $1, $4
        r11 = RSP_SUB32(r1, r4);
        goto L_1E2C;
    }
    // sub         $11, $1, $4
    r11 = RSP_SUB32(r1, r4);
    // bgez        $11, L_1E2C
    if (RSP_SIGNED(r11) >= 0) {
        // nop
    
        goto L_1E2C;
    }
    // nop

    // bne         $1, $2, L_1E4C
    if (r1 != r2) {
        // mfc0        $11, DPC_STATUS
        r11 = 0;
        goto L_1E4C;
    }
L_1E2C:
    // mfc0        $11, DPC_STATUS
    r11 = 0;
    // andi        $11, $11, 0x400
    r11 = r11 & 0X400;
    // bne         $11, $zero, L_1E2C
    if (r11 != 0) {
        // addi        $11, $zero, 0x1
        r11 = RSP_ADD32(0, 0X1);
        goto L_1E2C;
    }
    // addi        $11, $zero, 0x1
    r11 = RSP_ADD32(0, 0X1);
    // mtc0        $11, DPC_STATUS
    // lw          $2, 0xFEC($zero)
    r2 = RSP_MEM_W_LOAD(0XFEC, 0);
    // mtc0        $2, DPC_START
    // mtc0        $2, DPC_END
L_1E4C:
    // sw          $2, 0xF0($zero)
    RSP_MEM_W_STORE(0XF0, 0, r2);
    // lw          $11, 0xF4($zero)
    r11 = RSP_MEM_W_LOAD(0XF4, 0);
    // bne         $11, $zero, L_1E60
    if (r11 != 0) {
        // lw          $11, 0xFE0($zero)
        r11 = RSP_MEM_W_LOAD(0XFE0, 0);
        goto L_1E60;
    }
    // lw          $11, 0xFE0($zero)
    r11 = RSP_MEM_W_LOAD(0XFE0, 0);
    // sw          $11, 0xF4($zero)
    RSP_MEM_W_STORE(0XF4, 0, r11);
L_1E60:
    // lw          $1, 0xFD0($zero)
    r1 = RSP_MEM_W_LOAD(0XFD0, 0);
    // lw          $2, 0x2E0($zero)
    r2 = RSP_MEM_W_LOAD(0X2E0, 0);
    // lw          $3, 0x2E8($zero)
    r3 = RSP_MEM_W_LOAD(0X2E8, 0);
    // lw          $4, 0x410($zero)
    r4 = RSP_MEM_W_LOAD(0X410, 0);
    // lw          $5, 0x418($zero)
    r5 = RSP_MEM_W_LOAD(0X418, 0);
    // add         $2, $2, $1
    r2 = RSP_ADD32(r2, r1);
    // add         $3, $3, $1
    r3 = RSP_ADD32(r3, r1);
    // sw          $2, 0x2E0($zero)
    RSP_MEM_W_STORE(0X2E0, 0, r2);
    // sw          $3, 0x2E8($zero)
    RSP_MEM_W_STORE(0X2E8, 0, r3);
    // add         $4, $4, $1
    r4 = RSP_ADD32(r4, r1);
    // add         $5, $5, $1
    r5 = RSP_ADD32(r5, r1);
    // sw          $4, 0x410($zero)
    RSP_MEM_W_STORE(0X410, 0, r4);
    // sw          $5, 0x418($zero)
    RSP_MEM_W_STORE(0X418, 0, r5);
    // lw          $26, 0xFF0($zero)
    r26 = RSP_MEM_W_LOAD(0XFF0, 0);
    // addi        $11, $zero, 0x2E8
    r11 = RSP_ADD32(0, 0X2E8);
    // nop

    // jal         0x1FB4
    r31 = 0x1EA8;
    // ori         $12, $ra, 0x0
    r12 = r31 | 0X0;
    goto L_1FB4;
    // ori         $12, $ra, 0x0
    r12 = r31 | 0X0;
L_1EA8:
    // addi        $19, $zero, 0xA7
    r19 = RSP_ADD32(0, 0XA7);
    // ori         $24, $26, 0x0
    r24 = r26 | 0X0;
    // jal         0x1FD8
    r31 = 0x1EB8;
    // addiu       $20, $zero, 0x920
    r20 = RSP_ADD32(0, 0X920);
    goto L_1FD8;
    // addiu       $20, $zero, 0x920
    r20 = RSP_ADD32(0, 0X920);
L_1EB8:
    // addiu       $26, $26, 0xA8
    r26 = RSP_ADD32(r26, 0XA8);
    // addi        $27, $zero, -0xA8
    r27 = RSP_ADD32(0, -0XA8);
    // jal         0x1FC8
    r31 = 0x1EC8;
    // mfc0        $1, SP_STATUS
    r1 = 0;
    goto L_1FC8;
L_1EC4:
    // mfc0        $1, SP_STATUS
    r1 = 0;
L_1EC8:
    // lw          $25, 0x9C8($27)
    r25 = RSP_MEM_W_LOAD(0X9C8, r27);
    // beq         $27, $zero, L_1EA8
    if (r27 == 0) {
        // andi        $1, $1, 0x80
        r1 = r1 & 0X80;
        goto L_1EA8;
    }
    // andi        $1, $1, 0x80
    r1 = r1 & 0X80;
    // sra         $12, $25, 24
    r12 = S32(RSP_SIGNED(r25) >> 24);
    // sll         $11, $12, 1
    r11 = S32(r12) << 1;
    // lhu         $11, 0x36E($11)
    r11 = RSP_MEM_HU_LOAD(0X36E, r11);
    // bne         $1, $zero, L_0CDC
    if (r1 != 0) {
        // lw          $24, 0x9CC($27)
        r24 = RSP_MEM_W_LOAD(0X9CC, r27);
        goto L_0CDC;
    }
    // lw          $24, 0x9CC($27)
    r24 = RSP_MEM_W_LOAD(0X9CC, r27);
    // jr          $11
    jump_target = r11;
    debug_file = __FILE__; debug_line = __LINE__;
    // addiu       $27, $27, 0x8
    r27 = RSP_ADD32(r27, 0X8);
    goto do_indirect_jump;
    // addiu       $27, $27, 0x8
    r27 = RSP_ADD32(r27, 0X8);
    // jal         0x1224
    r31 = 0x1EF8;
    // lh          $20, 0x9C1($27)
    r20 = RSP_MEM_H_LOAD(0X9C1, r27);
    goto L_1224;
    // lh          $20, 0x9C1($27)
    r20 = RSP_MEM_H_LOAD(0X9C1, r27);
L_1EF8:
    // andi        $19, $25, 0xFF8
    r19 = r25 & 0XFF8;
    // sra         $20, $20, 2
    r20 = S32(RSP_SIGNED(r20) >> 2);
    // j           L_1FD8
    // addi        $ra, $zero, 0x1190
    r31 = RSP_ADD32(0, 0X1190);
    goto L_1FD8;
    // addi        $ra, $zero, 0x1190
    r31 = RSP_ADD32(0, 0X1190);
    // lw          $11, 0x1EC($zero)
    r11 = RSP_MEM_W_LOAD(0X1EC, 0);
    // and         $11, $11, $25
    r11 = r11 & r25;
    // or          $11, $11, $24
    r11 = r11 | r24;
    // j           L_1194
    // sw          $11, 0x1EC($zero)
    RSP_MEM_W_STORE(0X1EC, 0, r11);
    goto L_1194;
    // sw          $11, 0x1EC($zero)
    RSP_MEM_W_STORE(0X1EC, 0, r11);
    // lbu         $1, 0xDE($zero)
    r1 = RSP_MEM_BU(0XDE, 0);
    // beq         $1, $zero, L_0CDC
    if (r1 == 0) {
        // addi        $1, $1, -0x4
        r1 = RSP_ADD32(r1, -0X4);
        goto L_0CDC;
    }
    // addi        $1, $1, -0x4
    r1 = RSP_ADD32(r1, -0X4);
    // j           L_1020
    // lw          $26, 0x138($1)
    r26 = RSP_MEM_W_LOAD(0X138, r1);
    goto L_1020;
    // lw          $26, 0x138($1)
    r26 = RSP_MEM_W_LOAD(0X138, r1);
    // ldv         $v29[0], 0xD0($zero)
    rsp.LDV<0>(rsp.vpu.r[29], 0, 0X1A);
    // lw          $25, 0xD8($zero)
    r25 = RSP_MEM_W_LOAD(0XD8, 0);
    // addi        $23, $23, 0x8
    r23 = RSP_ADD32(r23, 0X8);
    // sdv         $v29[0], 0x3F8($23)
    rsp.SDV<0>(rsp.vpu.r[29], r23, -0X1);
    // sw          $24, 0x4($23)
    RSP_MEM_W_STORE(0X4, r23, r24);
    // sw          $25, 0x0($23)
    RSP_MEM_W_STORE(0X0, r23, r25);
    // j           L_1258
    // addi        $23, $23, 0x8
    r23 = RSP_ADD32(r23, 0X8);
    goto L_1258;
    // addi        $23, $23, 0x8
    r23 = RSP_ADD32(r23, 0X8);
    // addi        $ra, $zero, 0x1210
    r31 = RSP_ADD32(0, 0X1210);
    // srl         $11, $24, 22
    r11 = S32(U32(r24) >> 22);
    // andi        $11, $11, 0x3C
    r11 = r11 & 0X3C;
    // lw          $11, 0xF8($11)
    r11 = RSP_MEM_W_LOAD(0XF8, r11);
    // sll         $24, $24, 8
    r24 = S32(r24) << 8;
    // srl         $24, $24, 8
    r24 = S32(U32(r24) >> 8);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // add         $24, $24, $11
    r24 = RSP_ADD32(r24, r11);
    goto do_indirect_jump;
    // add         $24, $24, $11
    r24 = RSP_ADD32(r24, r11);
    // sw          $25, 0xC8($zero)
    RSP_MEM_W_STORE(0XC8, 0, r25);
    // j           L_1210
    // sw          $24, 0xCC($zero)
    RSP_MEM_W_STORE(0XCC, 0, r24);
    goto L_1210;
    // sw          $24, 0xCC($zero)
    RSP_MEM_W_STORE(0XCC, 0, r24);
    // sw          $25, 0xC0($zero)
    RSP_MEM_W_STORE(0XC0, 0, r25);
    // j           L_1210
    // sw          $24, 0xC4($zero)
    RSP_MEM_W_STORE(0XC4, 0, r24);
    goto L_1210;
    // sw          $24, 0xC4($zero)
    RSP_MEM_W_STORE(0XC4, 0, r24);
    // addi        $ra, $zero, 0x1194
    r31 = RSP_ADD32(0, 0X1194);
    // sub         $11, $23, $22
    r11 = RSP_SUB32(r23, r22);
    // blez        $11, L_0D04
    if (RSP_SIGNED(r11) <= 0) {
        // mfc0        $12, SP_DMA_BUSY
        r12 = 0;
        goto L_0D04;
    }
L_1F94:
    // mfc0        $12, SP_DMA_BUSY
    r12 = 0;
    // lw          $24, 0xF0($zero)
    r24 = RSP_MEM_W_LOAD(0XF0, 0);
    // addiu       $19, $11, 0x158
    r19 = RSP_ADD32(r11, 0X158);
    // bne         $12, $zero, L_1F94
    if (r12 != 0) {
        // lw          $12, 0xFEC($zero)
        r12 = RSP_MEM_W_LOAD(0XFEC, 0);
        goto L_1F94;
    }
    // lw          $12, 0xFEC($zero)
    r12 = RSP_MEM_W_LOAD(0XFEC, 0);
    // mtc0        $24, DPC_END
    // add         $11, $24, $19
    r11 = RSP_ADD32(r24, r19);
    // sub         $12, $12, $11
    r12 = RSP_SUB32(r12, r11);
L_1FB4:
    // bgez        $12, L_1FD8
    if (RSP_SIGNED(r12) >= 0) {
        // mfc0        $11, DPC_STATUS
        r11 = 0;
        goto L_1FD8;
    }
L_1FB8:
    // mfc0        $11, DPC_STATUS
    r11 = 0;
    // andi        $11, $11, 0x400
    r11 = r11 & 0X400;
    // bne         $11, $zero, L_1FB8
    if (r11 != 0) {
        // lw          $24, 0xFE8($zero)
        r24 = RSP_MEM_W_LOAD(0XFE8, 0);
        goto L_1FB8;
    }
    // lw          $24, 0xFE8($zero)
    r24 = RSP_MEM_W_LOAD(0XFE8, 0);
L_1FC8:
    // mfc0        $11, DPC_CURRENT
    r11 = 0;
    // beq         $11, $24, L_1FC8
    if (r11 == r24) {
        // nop
    
        goto L_1FC8;
    }
    // nop

    // mtc0        $24, DPC_START
L_1FD8:
    // mfc0        $11, DPC_CURRENT
    r11 = 0;
    // sub         $11, $11, $24
    r11 = RSP_SUB32(r11, r24);
    // blez        $11, L_1FEC
    if (RSP_SIGNED(r11) <= 0) {
        // sub         $11, $11, $19
        r11 = RSP_SUB32(r11, r19);
        goto L_1FEC;
    }
    // sub         $11, $11, $19
    r11 = RSP_SUB32(r11, r19);
    // blez        $11, L_1FD8
    if (RSP_SIGNED(r11) <= 0) {
        // add         $11, $24, $19
        r11 = RSP_ADD32(r24, r19);
        goto L_1FD8;
    }
L_1FEC:
    // add         $11, $24, $19
    r11 = RSP_ADD32(r24, r19);
    // sw          $11, 0xF0($zero)
    RSP_MEM_W_STORE(0XF0, 0, r11);
    // addi        $19, $19, -0x1
    r19 = RSP_ADD32(r19, -0X1);
    // addi        $20, $22, -0x2158
    r20 = RSP_ADD32(r22, -0X2158);
    // xori        $22, $22, 0x208
    r22 = r22 ^ 0X208;
    // j           L_1FD8
    // addi        $23, $22, -0x158
    r23 = RSP_ADD32(r22, -0X158);
    goto L_1FD8;
    // addi        $23, $22, -0x158
    r23 = RSP_ADD32(r22, -0X158);
    // addi        $11, $zero, 0x410
    r11 = RSP_ADD32(0, 0X410);
    // j           L_1FB4
    // addi        $12, $zero, 0x12D8
    r12 = RSP_ADD32(0, 0X12D8);
    goto L_1FB4;
    // addi        $12, $zero, 0x12D8
    r12 = RSP_ADD32(0, 0X12D8);
    // ori         $30, $ra, 0x0
    r30 = r31 | 0X0;
    // addiu       $5, $zero, 0x14
    r5 = RSP_ADD32(0, 0X14);
    // addiu       $18, $zero, 0x6
    r18 = RSP_ADD32(0, 0X6);
    // addiu       $15, $zero, 0x9C8
    r15 = RSP_ADD32(0, 0X9C8);
    // sh          $1, 0x3CA($18)
    RSP_MEM_H_STORE(0X3CA, r18, r1);
    // sh          $2, 0x3CC($18)
    RSP_MEM_H_STORE(0X3CC, r18, r2);
    // sh          $3, 0x3CE($18)
    RSP_MEM_H_STORE(0X3CE, r18, r3);
    // sh          $zero, 0x3D0($18)
    RSP_MEM_H_STORE(0X3D0, r18, 0);
    // lw          $29, 0x3CC($zero)
    r29 = RSP_MEM_W_LOAD(0X3CC, 0);
    // lw          $9, 0x3F8($5)
    r9 = RSP_MEM_W_LOAD(0X3F8, r5);
    // lw          $16, 0x24($3)
    r16 = RSP_MEM_W_LOAD(0X24, r3);
    // and         $16, $16, $9
    r16 = r16 & r9;
    // addi        $17, $18, -0x6
    r17 = RSP_ADD32(r18, -0X6);
    // xori        $18, $18, 0x1C
    r18 = r18 ^ 0X1C;
    // addi        $21, $18, -0x6
    r21 = RSP_ADD32(r18, -0X6);
    // lhu         $2, 0x3D0($17)
    r2 = RSP_MEM_HU_LOAD(0X3D0, r17);
    // addi        $17, $17, 0x2
    r17 = RSP_ADD32(r17, 0X2);
    // beq         $2, $zero, L_01D8
    if (r2 == 0) {
        // lw          $11, 0x24($2)
        r11 = RSP_MEM_W_LOAD(0X24, r2);
        goto L_01D8;
    }
    // lw          $11, 0x24($2)
    r11 = RSP_MEM_W_LOAD(0X24, r2);
    // and         $11, $11, $9
    r11 = r11 & r9;
    // beq         $11, $16, L_01C4
    if (r11 == r16) {
        // ori         $16, $11, 0x0
        r16 = r11 | 0X0;
        goto L_01C4;
    }
    // ori         $16, $11, 0x0
    r16 = r11 | 0X0;
    // beq         $16, $zero, L_007C
    if (r16 == 0) {
        // ori         $19, $2, 0x0
        r19 = r2 | 0X0;
        goto L_007C;
    }
    // ori         $19, $2, 0x0
    r19 = r2 | 0X0;
    // ori         $19, $3, 0x0
    r19 = r3 | 0X0;
    // ori         $3, $2, 0x0
    r3 = r2 | 0X0;
    // sll         $11, $5, 1
    r11 = S32(r5) << 1;
    // ldv         $v2[0], 0x180($11)
    rsp.LDV<0>(rsp.vpu.r[2], r11, 0X30);
    // ldv         $v4[0], 0x8($19)
    rsp.LDV<0>(rsp.vpu.r[4], r19, 0X1);
    // ldv         $v5[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[5], r19, 0X0);
    // ldv         $v6[0], 0x8($3)
    rsp.LDV<0>(rsp.vpu.r[6], r3, 0X1);
    // ldv         $v7[0], 0x0($3)
    rsp.LDV<0>(rsp.vpu.r[7], r3, 0X0);
    // vmudh       $v3, $v2, $v31[0]
    rsp.VMUDH<8>(rsp.vpu.r[3], rsp.vpu.r[2], rsp.vpu.r[31]);
    // vmudn       $v8, $v4, $v2
    rsp.VMUDN<0>(rsp.vpu.r[8], rsp.vpu.r[4], rsp.vpu.r[2]);
    // vmadh       $v9, $v5, $v2
    rsp.VMADH<0>(rsp.vpu.r[9], rsp.vpu.r[5], rsp.vpu.r[2]);
    // vmadn       $v10, $v6, $v3
    rsp.VMADN<0>(rsp.vpu.r[10], rsp.vpu.r[6], rsp.vpu.r[3]);
    // vmadh       $v11, $v7, $v3
    rsp.VMADH<0>(rsp.vpu.r[11], rsp.vpu.r[7], rsp.vpu.r[3]);
    // vaddc       $v8, $v8, $v8[0q]
    rsp.VADDC<2>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lqv         $v25[0], 0x1D0($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X1D);
    // vadd        $v9, $v9, $v9[0q]
    rsp.VADD<2>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[9]);
    // vaddc       $v10, $v10, $v10[0q]
    rsp.VADDC<2>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[10]);
    // vadd        $v11, $v11, $v11[0q]
    rsp.VADD<2>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[11]);
    // vaddc       $v8, $v8, $v8[1h]
    rsp.VADDC<5>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // vadd        $v9, $v9, $v9[1h]
    rsp.VADD<5>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[9]);
    // vaddc       $v10, $v10, $v10[1h]
    rsp.VADDC<5>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[10]);
    // vadd        $v11, $v11, $v11[1h]
    rsp.VADD<5>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[11]);
    // vor         $v29, $v11, $v1[0]
    rsp.VOR<8>(rsp.vpu.r[29], rsp.vpu.r[11], rsp.vpu.r[1]);
    // vrcph       $v3[3], $v11[3]
    rsp.VRCPH<11>(rsp.vpu.r[3], 3, rsp.vpu.r[11]);
    // vrcpl       $v2[3], $v10[3]
    rsp.VRCPL<11>(rsp.vpu.r[2], 3, rsp.vpu.r[10]);
    // vrcph       $v3[3], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[3], 3, rsp.vpu.r[0]);
    // vabs        $v29, $v29, $v25[3]
    rsp.VABS<11>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[25]);
    // vmudn       $v2, $v2, $v29[3]
    rsp.VMUDN<11>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[29]);
    // vmadh       $v3, $v3, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[3], rsp.vpu.r[3], rsp.vpu.r[29]);
    // veq         $v3, $v3, $v0[0]
    rsp.VEQ<8>(rsp.vpu.r[3], rsp.vpu.r[3], rsp.vpu.r[0]);
    // vmrg        $v2, $v2, $v31[0]
    rsp.VMRG<8>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[31]);
    // vmudl       $v29, $v10, $v2[3]
    rsp.VMUDL<11>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[2]);
    // vmadm       $v11, $v11, $v2[3]
    rsp.VMADM<11>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[2]);
    // vmadn       $v10, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[10], rsp.vpu.r[0], rsp.vpu.r[0]);
    // vrcph       $v13[3], $v11[3]
    rsp.VRCPH<11>(rsp.vpu.r[13], 3, rsp.vpu.r[11]);
    // vrcpl       $v12[3], $v10[3]
    rsp.VRCPL<11>(rsp.vpu.r[12], 3, rsp.vpu.r[10]);
    // vrcph       $v13[3], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[13], 3, rsp.vpu.r[0]);
    // vmudl       $v29, $v12, $v10
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[12], rsp.vpu.r[10]);
    // vmadm       $v29, $v13, $v10
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[13], rsp.vpu.r[10]);
    // vmadn       $v10, $v12, $v11
    rsp.VMADN<0>(rsp.vpu.r[10], rsp.vpu.r[12], rsp.vpu.r[11]);
    // vmadh       $v11, $v13, $v11
    rsp.VMADH<0>(rsp.vpu.r[11], rsp.vpu.r[13], rsp.vpu.r[11]);
    // vmudh       $v29, $v1, $v31[1]
    rsp.VMUDH<9>(rsp.vpu.r[29], rsp.vpu.r[1], rsp.vpu.r[31]);
    // vmadn       $v10, $v10, $v31[4]
    rsp.VMADN<12>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[31]);
    // vmadh       $v11, $v11, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[31]);
    // vmudl       $v29, $v12, $v10
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[12], rsp.vpu.r[10]);
    // vmadm       $v29, $v13, $v10
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[13], rsp.vpu.r[10]);
    // vmadn       $v12, $v12, $v11
    rsp.VMADN<0>(rsp.vpu.r[12], rsp.vpu.r[12], rsp.vpu.r[11]);
    // vmadh       $v13, $v13, $v11
    rsp.VMADH<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[11]);
    // vmudl       $v29, $v8, $v12
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[8], rsp.vpu.r[12]);
    // luv         $v26[0], 0x10($3)
    rsp.LUV<0>(rsp.vpu.r[26], r3, 0X2);
    // vmadm       $v29, $v9, $v12
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[9], rsp.vpu.r[12]);
    // llv         $v26[8], 0x14($3)
    rsp.LLV<8>(rsp.vpu.r[26], r3, 0X5);
    // vmadn       $v10, $v8, $v13
    rsp.VMADN<0>(rsp.vpu.r[10], rsp.vpu.r[8], rsp.vpu.r[13]);
    // luv         $v25[0], 0x10($19)
    rsp.LUV<0>(rsp.vpu.r[25], r19, 0X2);
    // vmadh       $v11, $v9, $v13
    rsp.VMADH<0>(rsp.vpu.r[11], rsp.vpu.r[9], rsp.vpu.r[13]);
    // llv         $v25[8], 0x14($19)
    rsp.LLV<8>(rsp.vpu.r[25], r19, 0X5);
    // vmudl       $v29, $v10, $v2[3]
    rsp.VMUDL<11>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[2]);
    // vmadm       $v11, $v11, $v2[3]
    rsp.VMADM<11>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[2]);
    // vmadn       $v10, $v10, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[0]);
    // vlt         $v11, $v11, $v1[0]
    rsp.VLT<8>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[1]);
    // vmrg        $v10, $v10, $v31[0]
    rsp.VMRG<8>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[31]);
    // vsubc       $v29, $v10, $v1[0]
    rsp.VSUBC<8>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[1]);
    // vge         $v11, $v11, $v0[0]
    rsp.VGE<8>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[0]);
    // vmrg        $v10, $v10, $v1[0]
    rsp.VMRG<8>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[1]);
    // vmudn       $v2, $v10, $v31[0]
    rsp.VMUDN<8>(rsp.vpu.r[2], rsp.vpu.r[10], rsp.vpu.r[31]);
    // vmudl       $v29, $v6, $v10[3]
    rsp.VMUDL<11>(rsp.vpu.r[29], rsp.vpu.r[6], rsp.vpu.r[10]);
    // vmadm       $v29, $v7, $v10[3]
    rsp.VMADM<11>(rsp.vpu.r[29], rsp.vpu.r[7], rsp.vpu.r[10]);
    // vmadl       $v29, $v4, $v2[3]
    rsp.VMADL<11>(rsp.vpu.r[29], rsp.vpu.r[4], rsp.vpu.r[2]);
    // vmadm       $v24, $v5, $v2[3]
    rsp.VMADM<11>(rsp.vpu.r[24], rsp.vpu.r[5], rsp.vpu.r[2]);
    // vmadn       $v23, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[0], rsp.vpu.r[0]);
    // vmudm       $v29, $v26, $v10[3]
    rsp.VMUDM<11>(rsp.vpu.r[29], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmadm       $v22, $v25, $v2[3]
    rsp.VMADM<11>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[2]);
    // addi        $7, $zero, 0x0
    r7 = RSP_ADD32(0, 0X0);
    // addi        $1, $zero, 0x2
    r1 = RSP_ADD32(0, 0X2);
    // sh          $15, 0x3D0($21)
    RSP_MEM_H_STORE(0X3D0, r21, r15);
    // j           L_176C
    // addi        $ra, $zero, -0x6A18
    r31 = RSP_ADD32(0, -0X6A18);
    goto L_176C;
    // addi        $ra, $zero, -0x6A18
    r31 = RSP_ADD32(0, -0X6A18);
    // slv         $v25[0], 0x1C8($15)
    rsp.SLV<0>(rsp.vpu.r[25], r15, -0XE);
    // ssv         $v26[4], 0xCE($15)
    rsp.SSV<4>(rsp.vpu.r[26], r15, -0X19);
    // suv         $v22[0], 0x3C0($15)
    rsp.SUV<0>(rsp.vpu.r[22], r15, -0X8);
    // slv         $v22[8], 0x1C4($15)
    rsp.SLV<8>(rsp.vpu.r[22], r15, -0XF);
    // ssv         $v3[4], 0xCC($15)
    rsp.SSV<4>(rsp.vpu.r[3], r15, -0X1A);
    // addi        $15, $15, -0x28
    r15 = RSP_ADD32(r15, -0X28);
    // addi        $21, $21, 0x2
    r21 = RSP_ADD32(r21, 0X2);
    // bne         $16, $zero, L_0050
    if (r16 != 0) {
        // ori         $3, $2, 0x0
        r3 = r2 | 0X0;
        goto L_0050;
    }
    // ori         $3, $2, 0x0
    r3 = r2 | 0X0;
    // sh          $3, 0x3D0($21)
    RSP_MEM_H_STORE(0X3D0, r21, r3);
    // j           L_1320
    // addi        $21, $21, 0x2
    r21 = RSP_ADD32(r21, 0X2);
    goto L_1320;
    // addi        $21, $21, 0x2
    r21 = RSP_ADD32(r21, 0X2);
    // sub         $11, $21, $18
    r11 = RSP_SUB32(r21, r18);
    // bltz        $11, L_021C
    if (RSP_SIGNED(r11) < 0) {
        // sh          $zero, 0x3D0($21)
        RSP_MEM_H_STORE(0X3D0, r21, 0);
        goto L_021C;
    }
    // sh          $zero, 0x3D0($21)
    RSP_MEM_H_STORE(0X3D0, r21, 0);
    // lhu         $3, 0x3CE($21)
    r3 = RSP_MEM_HU_LOAD(0X3CE, r21);
    // bne         $5, $zero, L_0038
    if (r5 != 0) {
        // addi        $5, $5, -0x4
        r5 = RSP_ADD32(r5, -0X4);
        goto L_0038;
    }
    // addi        $5, $5, -0x4
    r5 = RSP_ADD32(r5, -0X4);
    // sw          $zero, 0x3CC($zero)
    RSP_MEM_W_STORE(0X3CC, 0, 0);
    // lhu         $1, 0x3CA($18)
    r1 = RSP_MEM_HU_LOAD(0X3CA, r18);
    // lhu         $2, 0x3CC($18)
    r2 = RSP_MEM_HU_LOAD(0X3CC, r18);
    // lhu         $3, 0x3CE($21)
    r3 = RSP_MEM_HU_LOAD(0X3CE, r21);
    // mtc2        $1, $v2[10]
    rsp.MTC2<10>(r1, rsp.vpu.r[2]);
    // vor         $v3, $v0, $v31[5]
    rsp.VOR<13>(rsp.vpu.r[3], rsp.vpu.r[0], rsp.vpu.r[31]);
    // mtc2        $2, $v4[12]
    rsp.MTC2<12>(r2, rsp.vpu.r[4]);
    // jal         0x17F4
    r31 = 0x2214;
    // mtc2        $3, $v2[14]
    rsp.MTC2<14>(r3, rsp.vpu.r[2]);
    goto L_17F4;
    // mtc2        $3, $v2[14]
    rsp.MTC2<14>(r3, rsp.vpu.r[2]);
L_2214:
    // bne         $21, $18, L_01F4
    if (r21 != r18) {
        // addi        $18, $18, 0x2
        r18 = RSP_ADD32(r18, 0X2);
        goto L_01F4;
    }
    // addi        $18, $18, 0x2
    r18 = RSP_ADD32(r18, 0X2);
    // jr          $30
    jump_target = r30;
    debug_file = __FILE__; debug_line = __LINE__;
    // sw          $29, 0x3CC($zero)
    RSP_MEM_W_STORE(0X3CC, 0, r29);
    goto do_indirect_jump;
    // sw          $29, 0x3CC($zero)
    RSP_MEM_W_STORE(0X3CC, 0, r29);
    // nop

    // lhu         $20, 0x380($25)
    r20 = RSP_MEM_HU_LOAD(0X380, r25);
    // jal         0x1224
    r31 = 0x2234;
    // lhu         $1, 0x9C1($27)
    r1 = RSP_MEM_HU_LOAD(0X9C1, r27);
    goto L_1224;
    // lhu         $1, 0x9C1($27)
    r1 = RSP_MEM_HU_LOAD(0X9C1, r27);
L_2234:
    // sub         $20, $20, $1
    r20 = RSP_SUB32(r20, r1);
    // jal         0x1FD8
    r31 = 0x2240;
    // addi        $19, $1, -0x1
    r19 = RSP_ADD32(r1, -0X1);
    goto L_1FD8;
    // addi        $19, $1, -0x1
    r19 = RSP_ADD32(r1, -0X1);
L_2240:
    // lhu         $5, 0x1EC($zero)
    r5 = RSP_MEM_HU_LOAD(0X1EC, 0);
    // srl         $1, $1, 3
    r1 = S32(U32(r1) >> 3);
    // sub         $15, $25, $1
    r15 = RSP_SUB32(r25, r1);
    // lhu         $15, 0x380($15)
    r15 = RSP_MEM_HU_LOAD(0X380, r15);
    // ori         $14, $20, 0x0
    r14 = r20 | 0X0;
    // lbu         $8, 0x1D9($zero)
    r8 = RSP_MEM_BU(0X1D9, 0);
    // andi        $6, $5, 0x2
    r6 = r5 & 0X2;
    // bne         $6, $zero, L_0008
    if (r6 != 0) {
        // andi        $7, $5, 0x1
        r7 = r5 & 0X1;
        goto L_0008;
    }
    // andi        $7, $5, 0x1
    r7 = r5 & 0X1;
    // bne         $8, $zero, L_0280
    if (r8 != 0) {
        // sll         $7, $7, 3
        r7 = S32(r7) << 3;
        goto L_0280;
    }
    // sll         $7, $7, 3
    r7 = S32(r7) << 3;
    // sb          $25, 0x1D9($zero)
    RSP_MEM_B(0X1D9, 0) = r25;
    // addi        $21, $zero, 0x40
    r21 = RSP_ADD32(0, 0X40);
    // addi        $20, $zero, 0x0
    r20 = RSP_ADD32(0, 0X0);
    // jal         0x1088
    r31 = 0x2280;
    // addi        $19, $zero, 0x80
    r19 = RSP_ADD32(0, 0X80);
    goto L_1088;
    // addi        $19, $zero, 0x80
    r19 = RSP_ADD32(0, 0X80);
L_2280:
    // lqv         $v8[0], 0x80($zero)
    rsp.LQV<0>(rsp.vpu.r[8], 0, 0X8);
    // lqv         $v10[0], 0x90($zero)
    rsp.LQV<0>(rsp.vpu.r[10], 0, 0X9);
    // lqv         $v12[0], 0xA0($zero)
    rsp.LQV<0>(rsp.vpu.r[12], 0, 0XA);
    // lqv         $v14[0], 0xB0($zero)
    rsp.LQV<0>(rsp.vpu.r[14], 0, 0XB);
    // vadd        $v9, $v8, $v0[0]
    rsp.VADD<8>(rsp.vpu.r[9], rsp.vpu.r[8], rsp.vpu.r[0]);
    // ldv         $v9[0], 0x88($zero)
    rsp.LDV<0>(rsp.vpu.r[9], 0, 0X11);
    // vadd        $v11, $v10, $v0[0]
    rsp.VADD<8>(rsp.vpu.r[11], rsp.vpu.r[10], rsp.vpu.r[0]);
    // ldv         $v11[0], 0x98($zero)
    rsp.LDV<0>(rsp.vpu.r[11], 0, 0X13);
    // vadd        $v13, $v12, $v0[0]
    rsp.VADD<8>(rsp.vpu.r[13], rsp.vpu.r[12], rsp.vpu.r[0]);
    // ldv         $v13[0], 0xA8($zero)
    rsp.LDV<0>(rsp.vpu.r[13], 0, 0X15);
    // vadd        $v15, $v14, $v0[0]
    rsp.VADD<8>(rsp.vpu.r[15], rsp.vpu.r[14], rsp.vpu.r[0]);
    // ldv         $v15[0], 0xB8($zero)
    rsp.LDV<0>(rsp.vpu.r[15], 0, 0X17);
    // ldv         $v8[8], 0x80($zero)
    rsp.LDV<8>(rsp.vpu.r[8], 0, 0X10);
    // ldv         $v10[8], 0x90($zero)
    rsp.LDV<8>(rsp.vpu.r[10], 0, 0X12);
    // jal         0x176C
    r31 = 0x22C0;
    // ldv         $v12[8], 0xA0($zero)
    rsp.LDV<8>(rsp.vpu.r[12], 0, 0X14);
    goto L_176C;
    // ldv         $v12[8], 0xA0($zero)
    rsp.LDV<8>(rsp.vpu.r[12], 0, 0X14);
L_22C0:
    // jal         0x1FC8
    r31 = 0x22C8;
    // ldv         $v14[8], 0xB0($zero)
    rsp.LDV<8>(rsp.vpu.r[14], 0, 0X16);
    goto L_1FC8;
    // ldv         $v14[8], 0xB0($zero)
    rsp.LDV<8>(rsp.vpu.r[14], 0, 0X16);
L_22C8:
    // ldv         $v20[0], 0x0($14)
    rsp.LDV<0>(rsp.vpu.r[20], r14, 0X0);
    // vmov        $v16[5], $v21[1]
    rsp.VMOV<9>(rsp.vpu.r[16], 5, rsp.vpu.r[21]);
    // ldv         $v20[8], 0x10($14)
    rsp.LDV<8>(rsp.vpu.r[20], r14, 0X2);
    // vmudn       $v29, $v15, $v1[0]
    rsp.VMUDN<8>(rsp.vpu.r[29], rsp.vpu.r[15], rsp.vpu.r[1]);
    // lw          $11, 0x1C($14)
    r11 = RSP_MEM_W_LOAD(0X1C, r14);
    // vmadh       $v29, $v11, $v1[0]
    rsp.VMADH<8>(rsp.vpu.r[29], rsp.vpu.r[11], rsp.vpu.r[1]);
    // llv         $v22[12], 0x8($14)
    rsp.LLV<12>(rsp.vpu.r[22], r14, 0X2);
    // vmadn       $v29, $v12, $v20[0h]
    rsp.VMADN<4>(rsp.vpu.r[29], rsp.vpu.r[12], rsp.vpu.r[20]);
    // ori         $9, $6, 0x0
    r9 = r6 | 0X0;
    // vmadh       $v29, $v8, $v20[0h]
    rsp.VMADH<4>(rsp.vpu.r[29], rsp.vpu.r[8], rsp.vpu.r[20]);
    // lpv         $v2[0], 0xB0($9)
    rsp.LPV<0>(rsp.vpu.r[2], r9, 0X16);
    // vmadn       $v29, $v13, $v20[1h]
    rsp.VMADN<5>(rsp.vpu.r[29], rsp.vpu.r[13], rsp.vpu.r[20]);
    // sw          $11, 0x8($14)
    RSP_MEM_W_STORE(0X8, r14, r11);
    // vmadh       $v29, $v9, $v20[1h]
    rsp.VMADH<5>(rsp.vpu.r[29], rsp.vpu.r[9], rsp.vpu.r[20]);
    // lpv         $v7[0], 0x8($14)
    rsp.LPV<0>(rsp.vpu.r[7], r14, 0X1);
    // vmadn       $v23, $v14, $v20[2h]
    rsp.VMADN<6>(rsp.vpu.r[23], rsp.vpu.r[14], rsp.vpu.r[20]);
    // bne         $6, $zero, L_0108
    if (r6 != 0) {
        // vmadh       $v24, $v10, $v20[2h]
        rsp.VMADH<6>(rsp.vpu.r[24], rsp.vpu.r[10], rsp.vpu.r[20]);
        goto L_0108;
    }
    // vmadh       $v24, $v10, $v20[2h]
    rsp.VMADH<6>(rsp.vpu.r[24], rsp.vpu.r[10], rsp.vpu.r[20]);
    // vge         $v27, $v25, $v31[3]
    rsp.VGE<11>(rsp.vpu.r[27], rsp.vpu.r[25], rsp.vpu.r[31]);
    // llv         $v22[4], 0x18($14)
    rsp.LLV<4>(rsp.vpu.r[22], r14, 0X6);
    // vge         $v3, $v25, $v0[0]
    rsp.VGE<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[0]);
    // addi        $1, $1, -0x4
    r1 = RSP_ADD32(r1, -0X4);
    // vmudl       $v29, $v23, $v18[4]
    rsp.VMUDL<12>(rsp.vpu.r[29], rsp.vpu.r[23], rsp.vpu.r[18]);
    // sub         $11, $8, $7
    r11 = RSP_SUB32(r8, r7);
    // vmadm       $v2, $v24, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[2], rsp.vpu.r[24], rsp.vpu.r[18]);
    // sbv         $v27[15], 0x73($11)
    rsp.SBV<15>(rsp.vpu.r[27], r11, -0XD);
    // vmadn       $v21, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[0], rsp.vpu.r[0]);
    // sbv         $v27[7], 0x4B($11)
    rsp.SBV<7>(rsp.vpu.r[27], r11, -0X35);
    // vmov        $v26[1], $v3[2]
    rsp.VMOV<10>(rsp.vpu.r[26], 1, rsp.vpu.r[3]);
    // ssv         $v3[12], 0xF4($8)
    rsp.SSV<12>(rsp.vpu.r[3], r8, -0X6);
    // vmudn       $v7, $v23, $v18[5]
    rsp.VMUDN<13>(rsp.vpu.r[7], rsp.vpu.r[23], rsp.vpu.r[18]);
    // slv         $v25[8], 0x1F0($8)
    rsp.SLV<8>(rsp.vpu.r[25], r8, -0X4);
    // vmadh       $v6, $v24, $v18[5]
    rsp.VMADH<13>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[18]);
    // sdv         $v25[0], 0x3C8($8)
    rsp.SDV<0>(rsp.vpu.r[25], r8, -0X7);
    // vrcph       $v29[0], $v2[3]
    rsp.VRCPH<11>(rsp.vpu.r[29], 0, rsp.vpu.r[2]);
    // ssv         $v26[12], 0xF6($8)
    rsp.SSV<12>(rsp.vpu.r[26], r8, -0X5);
    // vrcpl       $v5[3], $v21[3]
    rsp.VRCPL<11>(rsp.vpu.r[5], 3, rsp.vpu.r[21]);
    // slv         $v26[2], 0x1CC($8)
    rsp.SLV<2>(rsp.vpu.r[26], r8, -0XD);
    // vrcph       $v4[3], $v2[7]
    rsp.VRCPH<15>(rsp.vpu.r[4], 3, rsp.vpu.r[2]);
    // ldv         $v3[0], 0x8($14)
    rsp.LDV<0>(rsp.vpu.r[3], r14, 0X1);
    // vrcpl       $v5[7], $v21[7]
    rsp.VRCPL<15>(rsp.vpu.r[5], 7, rsp.vpu.r[21]);
    // sra         $11, $1, 31
    r11 = S32(RSP_SIGNED(r1) >> 31);
    // vrcph       $v4[7], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[4], 7, rsp.vpu.r[0]);
    // andi        $11, $11, 0x28
    r11 = r11 & 0X28;
    // vch         $v29, $v24, $v24[3h]
    rsp.VCH<7>(rsp.vpu.r[29], rsp.vpu.r[24], rsp.vpu.r[24]);
    // addi        $15, $15, 0x50
    r15 = RSP_ADD32(r15, 0X50);
    // vcl         $v29, $v23, $v23[3h]
    rsp.VCL<7>(rsp.vpu.r[29], rsp.vpu.r[23], rsp.vpu.r[23]);
    // sub         $8, $15, $11
    r8 = RSP_SUB32(r15, r11);
    // vmudl       $v29, $v21, $v5
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[21], rsp.vpu.r[5]);
    // cfc2        $t2, $1
    r10 = 0;
    // vmadm       $v29, $v2, $v5
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[2], rsp.vpu.r[5]);
    // sdv         $v23[8], 0x3E0($8)
    rsp.SDV<8>(rsp.vpu.r[23], r8, -0X4);
    // vmadn       $v21, $v21, $v4
    rsp.VMADN<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[4]);
    // ldv         $v20[0], 0x20($14)
    rsp.LDV<0>(rsp.vpu.r[20], r14, 0X4);
    // vmadh       $v2, $v2, $v4
    rsp.VMADH<0>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[4]);
    // sdv         $v23[0], 0x3B8($15)
    rsp.SDV<0>(rsp.vpu.r[23], r15, -0X9);
    // vge         $v29, $v24, $v0[0]
    rsp.VGE<8>(rsp.vpu.r[29], rsp.vpu.r[24], rsp.vpu.r[0]);
    // lsv         $v23[14], 0xE4($8)
    rsp.LSV<14>(rsp.vpu.r[23], r8, -0XE);
    // vmudh       $v29, $v1, $v31[1]
    rsp.VMUDH<9>(rsp.vpu.r[29], rsp.vpu.r[1], rsp.vpu.r[31]);
    // sdv         $v24[8], 0x3D8($8)
    rsp.SDV<8>(rsp.vpu.r[24], r8, -0X5);
    // vmadn       $v26, $v21, $v31[4]
    rsp.VMADN<12>(rsp.vpu.r[26], rsp.vpu.r[21], rsp.vpu.r[31]);
    // lsv         $v23[6], 0xBC($15)
    rsp.LSV<6>(rsp.vpu.r[23], r15, -0X22);
    // vmadh       $v25, $v2, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[25], rsp.vpu.r[2], rsp.vpu.r[31]);
    // sdv         $v24[0], 0x3B0($15)
    rsp.SDV<0>(rsp.vpu.r[24], r15, -0XA);
    // vmrg        $v2, $v0, $v31[7]
    rsp.VMRG<15>(rsp.vpu.r[2], rsp.vpu.r[0], rsp.vpu.r[31]);
    // ldv         $v20[8], 0x30($14)
    rsp.LDV<8>(rsp.vpu.r[20], r14, 0X6);
    // vch         $v29, $v24, $v6[3h]
    rsp.VCH<7>(rsp.vpu.r[29], rsp.vpu.r[24], rsp.vpu.r[6]);
    // slv         $v3[0], 0x1E8($8)
    rsp.SLV<0>(rsp.vpu.r[3], r8, -0X6);
    // vmudl       $v29, $v26, $v5
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[26], rsp.vpu.r[5]);
    // lsv         $v24[14], 0xDC($8)
    rsp.LSV<14>(rsp.vpu.r[24], r8, -0X12);
    // vmadm       $v29, $v25, $v5
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[25], rsp.vpu.r[5]);
    // slv         $v3[4], 0x1C0($15)
    rsp.SLV<4>(rsp.vpu.r[3], r15, -0X10);
    // vmadn       $v5, $v26, $v4
    rsp.VMADN<0>(rsp.vpu.r[5], rsp.vpu.r[26], rsp.vpu.r[4]);
    // lsv         $v24[6], 0xB4($15)
    rsp.LSV<6>(rsp.vpu.r[24], r15, -0X26);
    // vmadh       $v4, $v25, $v4
    rsp.VMADH<0>(rsp.vpu.r[4], rsp.vpu.r[25], rsp.vpu.r[4]);
    // sh          $10, -0x2($8)
    RSP_MEM_H_STORE(-0X2, r8, r10);
    // vmadh       $v2, $v2, $v31[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[31]);
    // sll         $11, $10, 4
    r11 = S32(r10) << 4;
    // vcl         $v29, $v23, $v7[3h]
    rsp.VCL<7>(rsp.vpu.r[29], rsp.vpu.r[23], rsp.vpu.r[7]);
    // cfc2        $t2, $1
    r10 = 0;
    // vmudl       $v29, $v23, $v5[3h]
    rsp.VMUDL<7>(rsp.vpu.r[29], rsp.vpu.r[23], rsp.vpu.r[5]);
    // ssv         $v5[14], 0xFA($8)
    rsp.SSV<14>(rsp.vpu.r[5], r8, -0X3);
    // vmadm       $v29, $v24, $v5[3h]
    rsp.VMADM<7>(rsp.vpu.r[29], rsp.vpu.r[24], rsp.vpu.r[5]);
    // addi        $14, $14, 0x20
    r14 = RSP_ADD32(r14, 0X20);
    // vmadn       $v26, $v23, $v2[3h]
    rsp.VMADN<7>(rsp.vpu.r[26], rsp.vpu.r[23], rsp.vpu.r[2]);
    // sh          $10, -0x4($8)
    RSP_MEM_H_STORE(-0X4, r8, r10);
    // vmadh       $v25, $v24, $v2[3h]
    rsp.VMADH<7>(rsp.vpu.r[25], rsp.vpu.r[24], rsp.vpu.r[2]);
    // sll         $10, $10, 4
    r10 = S32(r10) << 4;
    // vmudm       $v3, $v22, $v18
    rsp.VMUDM<0>(rsp.vpu.r[3], rsp.vpu.r[22], rsp.vpu.r[18]);
    // sh          $11, -0x2A($15)
    RSP_MEM_H_STORE(-0X2A, r15, r11);
    // sh          $10, -0x2C($15)
    RSP_MEM_H_STORE(-0X2C, r15, r10);
    // vmudl       $v29, $v26, $v18[4]
    rsp.VMUDL<12>(rsp.vpu.r[29], rsp.vpu.r[26], rsp.vpu.r[18]);
    // ssv         $v5[6], 0xD2($15)
    rsp.SSV<6>(rsp.vpu.r[5], r15, -0X17);
    // vmadm       $v25, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[18]);
    // ssv         $v4[14], 0xF8($8)
    rsp.SSV<14>(rsp.vpu.r[4], r8, -0X4);
    // vmadn       $v26, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[26], rsp.vpu.r[0], rsp.vpu.r[0]);
    // ssv         $v4[6], 0xD0($15)
    rsp.SSV<6>(rsp.vpu.r[4], r15, -0X18);
    // slv         $v3[4], 0x1EC($8)
    rsp.SLV<4>(rsp.vpu.r[3], r8, -0X5);
    // vmudh       $v29, $v17, $v1[0]
    rsp.VMUDH<8>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[1]);
    // slv         $v3[12], 0x1C4($15)
    rsp.SLV<12>(rsp.vpu.r[3], r15, -0XF);
    // vmadh       $v29, $v19, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[29], rsp.vpu.r[19], rsp.vpu.r[31]);
    // vmadn       $v26, $v26, $v16
    rsp.VMADN<0>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[16]);
    // bgtz        $1, L_02D4
    if (RSP_SIGNED(r1) > 0) {
        // vmadh       $v25, $v25, $v16
        rsp.VMADH<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[16]);
        goto L_02D4;
    }
    // vmadh       $v25, $v25, $v16
    rsp.VMADH<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[16]);
    // bltz        $ra, L_01A8
    if (RSP_SIGNED(r31) < 0) {
        // vge         $v3, $v25, $v0[0]
        rsp.VGE<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[0]);
        goto L_01A8;
    }
    // vge         $v3, $v25, $v0[0]
    rsp.VGE<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[0]);
    // slv         $v25[8], 0x1F0($8)
    rsp.SLV<8>(rsp.vpu.r[25], r8, -0X4);
    // vge         $v27, $v25, $v31[3]
    rsp.VGE<11>(rsp.vpu.r[27], rsp.vpu.r[25], rsp.vpu.r[31]);
    // slv         $v25[0], 0x1C8($15)
    rsp.SLV<0>(rsp.vpu.r[25], r15, -0XE);
    // ssv         $v26[12], 0xF6($8)
    rsp.SSV<12>(rsp.vpu.r[26], r8, -0X5);
    // ssv         $v26[4], 0xCE($15)
    rsp.SSV<4>(rsp.vpu.r[26], r15, -0X19);
    // ssv         $v3[12], 0xF4($8)
    rsp.SSV<12>(rsp.vpu.r[3], r8, -0X6);
    // beq         $7, $zero, L_1EC4
    if (r7 == 0) {
        // ssv         $v3[4], 0xCC($15)
        rsp.SSV<4>(rsp.vpu.r[3], r15, -0X1A);
        goto L_1EC4;
    }
    // ssv         $v3[4], 0xCC($15)
    rsp.SSV<4>(rsp.vpu.r[3], r15, -0X1A);
    // sbv         $v27[15], 0x6B($8)
    rsp.SBV<15>(rsp.vpu.r[27], r8, -0X15);
    // j           L_1194
    // sbv         $v27[7], 0x43($15)
    rsp.SBV<7>(rsp.vpu.r[27], r15, -0X3D);
    goto L_1194;
    // sbv         $v27[7], 0x43($15)
    rsp.SBV<7>(rsp.vpu.r[27], r15, -0X3D);
    // addi        $13, $zero, 0x180
    r13 = RSP_ADD32(0, 0X180);
    // ldv         $v16[0], 0xE0($zero)
    rsp.LDV<0>(rsp.vpu.r[16], 0, 0X1C);
    // ldv         $v16[8], 0xE0($zero)
    rsp.LDV<8>(rsp.vpu.r[16], 0, 0X1C);
    // llv         $v29[0], 0x60($13)
    rsp.LLV<0>(rsp.vpu.r[29], r13, 0X18);
    // ldv         $v17[0], 0xE8($zero)
    rsp.LDV<0>(rsp.vpu.r[17], 0, 0X1D);
    // ldv         $v17[8], 0xE8($zero)
    rsp.LDV<8>(rsp.vpu.r[17], 0, 0X1D);
    // vlt         $v19, $v31, $v31[3]
    rsp.VLT<11>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[31]);
    // vsub        $v21, $v0, $v16
    rsp.VSUB<0>(rsp.vpu.r[21], rsp.vpu.r[0], rsp.vpu.r[16]);
    // llv         $v18[4], 0x68($13)
    rsp.LLV<4>(rsp.vpu.r[18], r13, 0X1A);
    // vmrg        $v16, $v16, $v29[0]
    rsp.VMRG<8>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[29]);
    // llv         $v18[12], 0x68($13)
    rsp.LLV<12>(rsp.vpu.r[18], r13, 0X1A);
    // vmrg        $v19, $v0, $v1[0]
    rsp.VMRG<8>(rsp.vpu.r[19], rsp.vpu.r[0], rsp.vpu.r[1]);
    // llv         $v18[8], 0xDC($zero)
    rsp.LLV<8>(rsp.vpu.r[18], 0, 0X37);
    // vmrg        $v17, $v17, $v29[1]
    rsp.VMRG<9>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[29]);
    // lsv         $v18[10], 0x6($13)
    rsp.LSV<10>(rsp.vpu.r[18], r13, 0X3);
    // vmov        $v16[1], $v21[1]
    rsp.VMOV<9>(rsp.vpu.r[16], 1, rsp.vpu.r[21]);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // addi        $8, $23, 0x50
    r8 = RSP_ADD32(r23, 0X50);
    goto do_indirect_jump;
    // addi        $8, $23, 0x50
    r8 = RSP_ADD32(r23, 0X50);
    // jal         0x17C4
    r31 = 0x24EC;
    // sw          $24, 0x4($23)
    RSP_MEM_W_STORE(0X4, r23, r24);
    goto L_17C4;
    // sw          $24, 0x4($23)
    RSP_MEM_W_STORE(0X4, r23, r24);
L_24EC:
    // addi        $ra, $zero, 0x1194
    r31 = RSP_ADD32(0, 0X1194);
    // sw          $25, 0x4($23)
    RSP_MEM_W_STORE(0X4, r23, r25);
    // lpv         $v2[0], 0x0($23)
    rsp.LPV<0>(rsp.vpu.r[2], r23, 0X0);
    // lbu         $1, 0x5($23)
    r1 = RSP_MEM_BU(0X5, r23);
    // lbu         $2, 0x6($23)
    r2 = RSP_MEM_BU(0X6, r23);
    // lbu         $3, 0x7($23)
    r3 = RSP_MEM_BU(0X7, r23);
    // vor         $v3, $v0, $v31[5]
    rsp.VOR<13>(rsp.vpu.r[3], rsp.vpu.r[0], rsp.vpu.r[31]);
    // lhu         $1, 0x380($1)
    r1 = RSP_MEM_HU_LOAD(0X380, r1);
    // vmudn       $v4, $v1, $v31[6]
    rsp.VMUDN<14>(rsp.vpu.r[4], rsp.vpu.r[1], rsp.vpu.r[31]);
    // lhu         $2, 0x380($2)
    r2 = RSP_MEM_HU_LOAD(0X380, r2);
    // vmadl       $v2, $v2, $v30[1]
    rsp.VMADL<9>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[30]);
    // lhu         $3, 0x380($3)
    r3 = RSP_MEM_HU_LOAD(0X380, r3);
    // vmadn       $v4, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[4], rsp.vpu.r[0], rsp.vpu.r[0]);
    // ori         $4, $1, 0x0
    r4 = r1 | 0X0;
    // vnxor       $v5, $v0, $v31[7]
    rsp.VNXOR<15>(rsp.vpu.r[5], rsp.vpu.r[0], rsp.vpu.r[31]);
    // llv         $v6[0], 0x18($1)
    rsp.LLV<0>(rsp.vpu.r[6], r1, 0X6);
    // vnxor       $v7, $v0, $v31[7]
    rsp.VNXOR<15>(rsp.vpu.r[7], rsp.vpu.r[0], rsp.vpu.r[31]);
    // llv         $v4[0], 0x18($2)
    rsp.LLV<0>(rsp.vpu.r[4], r2, 0X6);
    // vmov        $v6[6], $v2[5]
    rsp.VMOV<13>(rsp.vpu.r[6], 6, rsp.vpu.r[2]);
    // llv         $v8[0], 0x18($3)
    rsp.LLV<0>(rsp.vpu.r[8], r3, 0X6);
    // vnxor       $v9, $v0, $v31[7]
    rsp.VNXOR<15>(rsp.vpu.r[9], rsp.vpu.r[0], rsp.vpu.r[31]);
    // lw          $5, 0x24($1)
    r5 = RSP_MEM_W_LOAD(0X24, r1);
    // vmov        $v8[6], $v2[7]
    rsp.VMOV<15>(rsp.vpu.r[8], 6, rsp.vpu.r[2]);
    // lw          $6, 0x24($2)
    r6 = RSP_MEM_W_LOAD(0X24, r2);
    // vadd        $v2, $v0, $v6[1]
    rsp.VADD<9>(rsp.vpu.r[2], rsp.vpu.r[0], rsp.vpu.r[6]);
    // lw          $7, 0x24($3)
    r7 = RSP_MEM_W_LOAD(0X24, r3);
    // vsub        $v10, $v6, $v4
    rsp.VSUB<0>(rsp.vpu.r[10], rsp.vpu.r[6], rsp.vpu.r[4]);
    // andi        $11, $5, 0x7070
    r11 = r5 & 0X7070;
    // vsub        $v11, $v4, $v6
    rsp.VSUB<0>(rsp.vpu.r[11], rsp.vpu.r[4], rsp.vpu.r[6]);
    // and         $11, $6, $11
    r11 = r6 & r11;
    // vsub        $v12, $v6, $v8
    rsp.VSUB<0>(rsp.vpu.r[12], rsp.vpu.r[6], rsp.vpu.r[8]);
    // and         $11, $7, $11
    r11 = r7 & r11;
    // vlt         $v13, $v2, $v4[1]
    rsp.VLT<9>(rsp.vpu.r[13], rsp.vpu.r[2], rsp.vpu.r[4]);
    // vmrg        $v14, $v6, $v4
    rsp.VMRG<0>(rsp.vpu.r[14], rsp.vpu.r[6], rsp.vpu.r[4]);
    // bne         $11, $zero, L_0D04
    if (r11 != 0) {
        // lbu         $11, 0x1EE($zero)
        r11 = RSP_MEM_BU(0X1EE, 0);
        goto L_0D04;
    }
    // lbu         $11, 0x1EE($zero)
    r11 = RSP_MEM_BU(0X1EE, 0);
    // vmudh       $v29, $v10, $v12[1]
    rsp.VMUDH<9>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[12]);
    // lw          $12, 0x3CC($zero)
    r12 = RSP_MEM_W_LOAD(0X3CC, 0);
    // vmadh       $v29, $v12, $v11[1]
    rsp.VMADH<9>(rsp.vpu.r[29], rsp.vpu.r[12], rsp.vpu.r[11]);
    // or          $5, $5, $6
    r5 = r5 | r6;
    // vge         $v2, $v2, $v4[1]
    rsp.VGE<9>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[4]);
    // or          $5, $5, $7
    r5 = r5 | r7;
    // vmrg        $v10, $v6, $v4
    rsp.VMRG<0>(rsp.vpu.r[10], rsp.vpu.r[6], rsp.vpu.r[4]);
    // lw          $11, 0x3C2($11)
    r11 = RSP_MEM_W_LOAD(0X3C2, r11);
    // vge         $v6, $v13, $v8[1]
    rsp.VGE<9>(rsp.vpu.r[6], rsp.vpu.r[13], rsp.vpu.r[8]);
    // mfc2        $6, $v29[0]
    rsp.MFC2<0>(r6, rsp.vpu.r[29]);
    // vmrg        $v4, $v14, $v8
    rsp.VMRG<0>(rsp.vpu.r[4], rsp.vpu.r[14], rsp.vpu.r[8]);
    // and         $5, $5, $12
    r5 = r5 & r12;
    // vmrg        $v14, $v8, $v14
    rsp.VMRG<0>(rsp.vpu.r[14], rsp.vpu.r[8], rsp.vpu.r[14]);
    // bne         $5, $zero, L_0014
    if (r5 != 0) {
        // add         $11, $6, $11
        r11 = RSP_ADD32(r6, r11);
        goto L_0014;
    }
    // add         $11, $6, $11
    r11 = RSP_ADD32(r6, r11);
    // vlt         $v6, $v6, $v2
    rsp.VLT<0>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[2]);
    // bgez        $11, L_0D04
    if (RSP_SIGNED(r11) >= 0) {
        // vmrg        $v2, $v4, $v10
        rsp.VMRG<0>(rsp.vpu.r[2], rsp.vpu.r[4], rsp.vpu.r[10]);
        goto L_0D04;
    }
    // vmrg        $v2, $v4, $v10
    rsp.VMRG<0>(rsp.vpu.r[2], rsp.vpu.r[4], rsp.vpu.r[10]);
    // vmrg        $v10, $v10, $v4
    rsp.VMRG<0>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[4]);
    // mfc2        $1, $v14[12]
    rsp.MFC2<12>(r1, rsp.vpu.r[14]);
    // vmudn       $v4, $v14, $v31[5]
    rsp.VMUDN<13>(rsp.vpu.r[4], rsp.vpu.r[14], rsp.vpu.r[31]);
    // beq         $6, $zero, L_0D04
    if (r6 == 0) {
        // vsub        $v6, $v2, $v14
        rsp.VSUB<0>(rsp.vpu.r[6], rsp.vpu.r[2], rsp.vpu.r[14]);
        goto L_0D04;
    }
    // vsub        $v6, $v2, $v14
    rsp.VSUB<0>(rsp.vpu.r[6], rsp.vpu.r[2], rsp.vpu.r[14]);
    // mfc2        $2, $v2[12]
    rsp.MFC2<12>(r2, rsp.vpu.r[2]);
    // vsub        $v8, $v10, $v14
    rsp.VSUB<0>(rsp.vpu.r[8], rsp.vpu.r[10], rsp.vpu.r[14]);
    // mfc2        $3, $v10[12]
    rsp.MFC2<12>(r3, rsp.vpu.r[10]);
    // vsub        $v11, $v14, $v2
    rsp.VSUB<0>(rsp.vpu.r[11], rsp.vpu.r[14], rsp.vpu.r[2]);
    // lw          $6, 0x1EC($zero)
    r6 = RSP_MEM_W_LOAD(0X1EC, 0);
    // vsub        $v12, $v14, $v10
    rsp.VSUB<0>(rsp.vpu.r[12], rsp.vpu.r[14], rsp.vpu.r[10]);
    // llv         $v13[0], 0x20($1)
    rsp.LLV<0>(rsp.vpu.r[13], r1, 0X8);
    // vsub        $v15, $v10, $v2
    rsp.VSUB<0>(rsp.vpu.r[15], rsp.vpu.r[10], rsp.vpu.r[2]);
    // llv         $v13[8], 0x20($2)
    rsp.LLV<8>(rsp.vpu.r[13], r2, 0X8);
    // vmudh       $v16, $v6, $v8[0]
    rsp.VMUDH<8>(rsp.vpu.r[16], rsp.vpu.r[6], rsp.vpu.r[8]);
    // llv         $v13[12], 0x20($3)
    rsp.LLV<12>(rsp.vpu.r[13], r3, 0X8);
    // vmadh       $v16, $v8, $v11[0]
    rsp.VMADH<8>(rsp.vpu.r[16], rsp.vpu.r[8], rsp.vpu.r[11]);
    // sll         $11, $6, 10
    r11 = S32(r6) << 10;
    // vsar        $v17, $v17, $v17[0]
    rsp.VSAR<8>(rsp.vpu.r[17], rsp.vpu.r[17]);
    // bgez        $11, L_063C
    if (RSP_SIGNED(r11) >= 0) {
        // vsar        $v16, $v16, $v16[1]
        rsp.VSAR<9>(rsp.vpu.r[16], rsp.vpu.r[16]);
        goto L_063C;
    }
    // vsar        $v16, $v16, $v16[1]
    rsp.VSAR<9>(rsp.vpu.r[16], rsp.vpu.r[16]);
    // lpv         $v18[0], 0x10($1)
    rsp.LPV<0>(rsp.vpu.r[18], r1, 0X2);
    // vmov        $v15[2], $v6[0]
    rsp.VMOV<8>(rsp.vpu.r[15], 2, rsp.vpu.r[6]);
    // lpv         $v19[0], 0x10($2)
    rsp.LPV<0>(rsp.vpu.r[19], r2, 0X2);
    // vrcp        $v20[0], $v15[1]
    rsp.VRCP<9>(rsp.vpu.r[20], 0, rsp.vpu.r[15]);
    // lpv         $v21[0], 0x10($3)
    rsp.LPV<0>(rsp.vpu.r[21], r3, 0X2);
    // vrcph       $v22[0], $v17[1]
    rsp.VRCPH<9>(rsp.vpu.r[22], 0, rsp.vpu.r[17]);
    // vrcpl       $v23[1], $v16[1]
    rsp.VRCPL<9>(rsp.vpu.r[23], 1, rsp.vpu.r[16]);
    // j           L_1938
    // vrcph       $v24[1], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[24], 1, rsp.vpu.r[0]);
    goto L_1938;
    // vrcph       $v24[1], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[24], 1, rsp.vpu.r[0]);
    // lpv         $v18[0], 0x10($4)
    rsp.LPV<0>(rsp.vpu.r[18], r4, 0X2);
    // vrcp        $v20[0], $v15[1]
    rsp.VRCP<9>(rsp.vpu.r[20], 0, rsp.vpu.r[15]);
    // lbv         $v18[6], 0x13($1)
    rsp.LBV<6>(rsp.vpu.r[18], r1, 0X13);
    // vrcph       $v22[0], $v17[1]
    rsp.VRCPH<9>(rsp.vpu.r[22], 0, rsp.vpu.r[17]);
    // lpv         $v19[0], 0x10($4)
    rsp.LPV<0>(rsp.vpu.r[19], r4, 0X2);
    // vrcpl       $v23[1], $v16[1]
    rsp.VRCPL<9>(rsp.vpu.r[23], 1, rsp.vpu.r[16]);
    // lbv         $v19[6], 0x13($2)
    rsp.LBV<6>(rsp.vpu.r[19], r2, 0X13);
    // vrcph       $v24[1], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[24], 1, rsp.vpu.r[0]);
    // lpv         $v21[0], 0x10($4)
    rsp.LPV<0>(rsp.vpu.r[21], r4, 0X2);
    // vmov        $v15[2], $v6[0]
    rsp.VMOV<8>(rsp.vpu.r[15], 2, rsp.vpu.r[6]);
    // lbv         $v21[6], 0x13($3)
    rsp.LBV<6>(rsp.vpu.r[21], r3, 0X13);
    // vrcp        $v20[2], $v6[1]
    rsp.VRCP<9>(rsp.vpu.r[20], 2, rsp.vpu.r[6]);
    // vrcph       $v22[2], $v6[1]
    rsp.VRCPH<9>(rsp.vpu.r[22], 2, rsp.vpu.r[6]);
    // lw          $5, 0x20($1)
    r5 = RSP_MEM_W_LOAD(0X20, r1);
    // vrcp        $v20[3], $v8[1]
    rsp.VRCP<9>(rsp.vpu.r[20], 3, rsp.vpu.r[8]);
    // lw          $7, 0x20($2)
    r7 = RSP_MEM_W_LOAD(0X20, r2);
    // vrcph       $v22[3], $v8[1]
    rsp.VRCPH<9>(rsp.vpu.r[22], 3, rsp.vpu.r[8]);
    // lw          $8, 0x20($3)
    r8 = RSP_MEM_W_LOAD(0X20, r3);
    // vmudl       $v18, $v18, $v30[3]
    rsp.VMUDL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[30]);
    // lbu         $9, 0x1E7($zero)
    r9 = RSP_MEM_BU(0X1E7, 0);
    // vmudl       $v19, $v19, $v30[3]
    rsp.VMUDL<11>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[30]);
    // sub         $11, $5, $7
    r11 = RSP_SUB32(r5, r7);
    // vmudl       $v21, $v21, $v30[3]
    rsp.VMUDL<11>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[30]);
    // sra         $12, $11, 31
    r12 = S32(RSP_SIGNED(r11) >> 31);
    // vmov        $v15[3], $v8[0]
    rsp.VMOV<8>(rsp.vpu.r[15], 3, rsp.vpu.r[8]);
    // and         $11, $11, $12
    r11 = r11 & r12;
    // vmudl       $v29, $v20, $v30[7]
    rsp.VMUDL<15>(rsp.vpu.r[29], rsp.vpu.r[20], rsp.vpu.r[30]);
    // sub         $5, $5, $11
    r5 = RSP_SUB32(r5, r11);
    // vmadm       $v22, $v22, $v30[7]
    rsp.VMADM<15>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[30]);
    // sub         $11, $5, $8
    r11 = RSP_SUB32(r5, r8);
    // vmadn       $v20, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[20], rsp.vpu.r[0], rsp.vpu.r[0]);
    // sra         $12, $11, 31
    r12 = S32(RSP_SIGNED(r11) >> 31);
    // vmudm       $v25, $v15, $v30[2]
    rsp.VMUDM<10>(rsp.vpu.r[25], rsp.vpu.r[15], rsp.vpu.r[30]);
    // and         $11, $11, $12
    r11 = r11 & r12;
    // vmadn       $v15, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[15], rsp.vpu.r[0], rsp.vpu.r[0]);
    // sub         $5, $5, $11
    r5 = RSP_SUB32(r5, r11);
    // vsubc       $v4, $v0, $v4
    rsp.VSUBC<0>(rsp.vpu.r[4], rsp.vpu.r[0], rsp.vpu.r[4]);
    // sw          $5, 0x10($23)
    RSP_MEM_W_STORE(0X10, r23, r5);
    // vsub        $v26, $v0, $v0
    rsp.VSUB<0>(rsp.vpu.r[26], rsp.vpu.r[0], rsp.vpu.r[0]);
    // llv         $v27[0], 0x10($23)
    rsp.LLV<0>(rsp.vpu.r[27], r23, 0X4);
    // vmudm       $v29, $v25, $v20
    rsp.VMUDM<0>(rsp.vpu.r[29], rsp.vpu.r[25], rsp.vpu.r[20]);
    // mfc2        $5, $v17[1]
    rsp.MFC2<1>(r5, rsp.vpu.r[17]);
    // vmadl       $v29, $v15, $v20
    rsp.VMADL<0>(rsp.vpu.r[29], rsp.vpu.r[15], rsp.vpu.r[20]);
    // lbu         $7, 0x1E6($zero)
    r7 = RSP_MEM_BU(0X1E6, 0);
    // vmadn       $v20, $v15, $v22
    rsp.VMADN<0>(rsp.vpu.r[20], rsp.vpu.r[15], rsp.vpu.r[22]);
    // lsv         $v19[14], 0x1C($2)
    rsp.LSV<14>(rsp.vpu.r[19], r2, 0XE);
    // vmadh       $v15, $v25, $v22
    rsp.VMADH<0>(rsp.vpu.r[15], rsp.vpu.r[25], rsp.vpu.r[22]);
    // lsv         $v21[14], 0x1C($3)
    rsp.LSV<14>(rsp.vpu.r[21], r3, 0XE);
    // vmudl       $v29, $v23, $v16
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[23], rsp.vpu.r[16]);
    // lsv         $v7[14], 0x1E($2)
    rsp.LSV<14>(rsp.vpu.r[7], r2, 0XF);
    // vmadm       $v29, $v24, $v16
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[24], rsp.vpu.r[16]);
    // lsv         $v9[14], 0x1E($3)
    rsp.LSV<14>(rsp.vpu.r[9], r3, 0XF);
    // vmadn       $v16, $v23, $v17
    rsp.VMADN<0>(rsp.vpu.r[16], rsp.vpu.r[23], rsp.vpu.r[17]);
    // ori         $11, $6, 0xC8
    r11 = r6 | 0XC8;
    // vmadh       $v17, $v24, $v17
    rsp.VMADH<0>(rsp.vpu.r[17], rsp.vpu.r[24], rsp.vpu.r[17]);
    // or          $11, $11, $9
    r11 = r11 | r9;
    // vand        $v22, $v20, $v30[5]
    rsp.VAND<13>(rsp.vpu.r[22], rsp.vpu.r[20], rsp.vpu.r[30]);
    // vcr         $v15, $v15, $v30[3]
    rsp.VCR<11>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[30]);
    // sb          $11, 0x0($23)
    RSP_MEM_B(0X0, r23) = r11;
    // vmudh       $v29, $v1, $v30[6]
    rsp.VMUDH<14>(rsp.vpu.r[29], rsp.vpu.r[1], rsp.vpu.r[30]);
    // ssv         $v10[2], 0x2($23)
    rsp.SSV<2>(rsp.vpu.r[10], r23, 0X1);
    // vmadn       $v16, $v16, $v30[4]
    rsp.VMADN<12>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[30]);
    // ssv         $v2[2], 0x4($23)
    rsp.SSV<2>(rsp.vpu.r[2], r23, 0X2);
    // vmadh       $v17, $v17, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // ssv         $v14[2], 0x6($23)
    rsp.SSV<2>(rsp.vpu.r[14], r23, 0X3);
    // vmudn       $v29, $v3, $v14[0]
    rsp.VMUDN<8>(rsp.vpu.r[29], rsp.vpu.r[3], rsp.vpu.r[14]);
    // andi        $12, $5, 0x80
    r12 = r5 & 0X80;
    // vmadl       $v29, $v22, $v4[1]
    rsp.VMADL<9>(rsp.vpu.r[29], rsp.vpu.r[22], rsp.vpu.r[4]);
    // or          $12, $12, $7
    r12 = r12 | r7;
    // vmadm       $v29, $v15, $v4[1]
    rsp.VMADM<9>(rsp.vpu.r[29], rsp.vpu.r[15], rsp.vpu.r[4]);
    // sb          $12, 0x1($23)
    RSP_MEM_B(0X1, r23) = r12;
    // vmadn       $v2, $v22, $v26[1]
    rsp.VMADN<9>(rsp.vpu.r[2], rsp.vpu.r[22], rsp.vpu.r[26]);
    // beq         $9, $zero, L_07D4
    if (r9 == 0) {
        // vmadh       $v3, $v15, $v26[1]
        rsp.VMADH<9>(rsp.vpu.r[3], rsp.vpu.r[15], rsp.vpu.r[26]);
        goto L_07D4;
    }
    // vmadh       $v3, $v15, $v26[1]
    rsp.VMADH<9>(rsp.vpu.r[3], rsp.vpu.r[15], rsp.vpu.r[26]);
    // vrcph       $v29[0], $v27[0]
    rsp.VRCPH<8>(rsp.vpu.r[29], 0, rsp.vpu.r[27]);
    // vrcpl       $v10[0], $v27[1]
    rsp.VRCPL<9>(rsp.vpu.r[10], 0, rsp.vpu.r[27]);
    // vadd        $v14, $v0, $v13[1q]
    rsp.VADD<3>(rsp.vpu.r[14], rsp.vpu.r[0], rsp.vpu.r[13]);
    // vrcph       $v27[0], $v0[0]
    rsp.VRCPH<8>(rsp.vpu.r[27], 0, rsp.vpu.r[0]);
    // vor         $v22, $v0, $v31[7]
    rsp.VOR<15>(rsp.vpu.r[22], rsp.vpu.r[0], rsp.vpu.r[31]);
    // vmudm       $v29, $v13, $v10[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[13], rsp.vpu.r[10]);
    // vmadl       $v29, $v14, $v10[0]
    rsp.VMADL<8>(rsp.vpu.r[29], rsp.vpu.r[14], rsp.vpu.r[10]);
    // llv         $v22[0], 0x14($1)
    rsp.LLV<0>(rsp.vpu.r[22], r1, 0X5);
    // vmadn       $v14, $v14, $v27[0]
    rsp.VMADN<8>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[27]);
    // llv         $v22[8], 0x14($2)
    rsp.LLV<8>(rsp.vpu.r[22], r2, 0X5);
    // vmadh       $v13, $v13, $v27[0]
    rsp.VMADH<8>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[27]);
    // vor         $v10, $v0, $v31[7]
    rsp.VOR<15>(rsp.vpu.r[10], rsp.vpu.r[0], rsp.vpu.r[31]);
    // vge         $v29, $v30, $v30[7]
    rsp.VGE<15>(rsp.vpu.r[29], rsp.vpu.r[30], rsp.vpu.r[30]);
    // llv         $v10[8], 0x14($3)
    rsp.LLV<8>(rsp.vpu.r[10], r3, 0X5);
    // vmudm       $v29, $v22, $v14[0h]
    rsp.VMUDM<4>(rsp.vpu.r[29], rsp.vpu.r[22], rsp.vpu.r[14]);
    // vmadh       $v22, $v22, $v13[0h]
    rsp.VMADH<4>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[13]);
    // vmadn       $v25, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[25], rsp.vpu.r[0], rsp.vpu.r[0]);
    // vmudm       $v29, $v10, $v14[6]
    rsp.VMUDM<14>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[14]);
    // vmadh       $v10, $v10, $v13[6]
    rsp.VMADH<14>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[13]);
    // vmadn       $v13, $v0, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[13], rsp.vpu.r[0], rsp.vpu.r[0]);
    // sdv         $v22[0], 0x20($23)
    rsp.SDV<0>(rsp.vpu.r[22], r23, 0X4);
    // vmrg        $v19, $v19, $v22
    rsp.VMRG<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[22]);
    // sdv         $v25[0], 0x28($23)
    rsp.SDV<0>(rsp.vpu.r[25], r23, 0X5);
    // vmrg        $v7, $v7, $v25
    rsp.VMRG<0>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[25]);
    // ldv         $v18[8], 0x20($23)
    rsp.LDV<8>(rsp.vpu.r[18], r23, 0X4);
    // vmrg        $v21, $v21, $v10
    rsp.VMRG<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[10]);
    // ldv         $v5[8], 0x28($23)
    rsp.LDV<8>(rsp.vpu.r[5], r23, 0X5);
    // vmrg        $v9, $v9, $v13
    rsp.VMRG<0>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[13]);
    // vmudl       $v29, $v16, $v23
    rsp.VMUDL<0>(rsp.vpu.r[29], rsp.vpu.r[16], rsp.vpu.r[23]);
    // lsv         $v5[14], 0x1E($1)
    rsp.LSV<14>(rsp.vpu.r[5], r1, 0XF);
    // vmadm       $v29, $v17, $v23
    rsp.VMADM<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[23]);
    // lsv         $v18[14], 0x1C($1)
    rsp.LSV<14>(rsp.vpu.r[18], r1, 0XE);
    // vmadn       $v23, $v16, $v24
    rsp.VMADN<0>(rsp.vpu.r[23], rsp.vpu.r[16], rsp.vpu.r[24]);
    // lh          $1, 0x18($2)
    r1 = RSP_MEM_H_LOAD(0X18, r2);
    // vmadh       $v24, $v17, $v24
    rsp.VMADH<0>(rsp.vpu.r[24], rsp.vpu.r[17], rsp.vpu.r[24]);
    // addiu       $2, $23, 0x20
    r2 = RSP_ADD32(r23, 0X20);
    // vsubc       $v10, $v9, $v5
    rsp.VSUBC<0>(rsp.vpu.r[10], rsp.vpu.r[9], rsp.vpu.r[5]);
    // andi        $3, $6, 0x4
    r3 = r6 & 0X4;
    // vsub        $v9, $v21, $v18
    rsp.VSUB<0>(rsp.vpu.r[9], rsp.vpu.r[21], rsp.vpu.r[18]);
    // sll         $1, $1, 14
    r1 = S32(r1) << 14;
    // vsubc       $v13, $v7, $v5
    rsp.VSUBC<0>(rsp.vpu.r[13], rsp.vpu.r[7], rsp.vpu.r[5]);
    // sw          $1, 0x8($23)
    RSP_MEM_W_STORE(0X8, r23, r1);
    // vsub        $v7, $v19, $v18
    rsp.VSUB<0>(rsp.vpu.r[7], rsp.vpu.r[19], rsp.vpu.r[18]);
    // ssv         $v3[6], 0x10($23)
    rsp.SSV<6>(rsp.vpu.r[3], r23, 0X8);
    // vmudn       $v29, $v10, $v6[1]
    rsp.VMUDN<9>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[6]);
    // ssv         $v2[6], 0x12($23)
    rsp.SSV<6>(rsp.vpu.r[2], r23, 0X9);
    // vmadh       $v29, $v9, $v6[1]
    rsp.VMADH<9>(rsp.vpu.r[29], rsp.vpu.r[9], rsp.vpu.r[6]);
    // ssv         $v3[4], 0x18($23)
    rsp.SSV<4>(rsp.vpu.r[3], r23, 0XC);
    // vmadn       $v29, $v13, $v12[1]
    rsp.VMADN<9>(rsp.vpu.r[29], rsp.vpu.r[13], rsp.vpu.r[12]);
    // ssv         $v2[4], 0x1A($23)
    rsp.SSV<4>(rsp.vpu.r[2], r23, 0XD);
    // vmadh       $v29, $v7, $v12[1]
    rsp.VMADH<9>(rsp.vpu.r[29], rsp.vpu.r[7], rsp.vpu.r[12]);
    // ssv         $v15[0], 0xC($23)
    rsp.SSV<0>(rsp.vpu.r[15], r23, 0X6);
    // vsar        $v2, $v2, $v2[1]
    rsp.VSAR<9>(rsp.vpu.r[2], rsp.vpu.r[2]);
    // ssv         $v20[0], 0xE($23)
    rsp.SSV<0>(rsp.vpu.r[20], r23, 0X7);
    // vsar        $v3, $v3, $v3[0]
    rsp.VSAR<8>(rsp.vpu.r[3], rsp.vpu.r[3]);
    // ssv         $v15[6], 0x14($23)
    rsp.SSV<6>(rsp.vpu.r[15], r23, 0XA);
    // vmudn       $v29, $v13, $v8[0]
    rsp.VMUDN<8>(rsp.vpu.r[29], rsp.vpu.r[13], rsp.vpu.r[8]);
    // ssv         $v20[6], 0x16($23)
    rsp.SSV<6>(rsp.vpu.r[20], r23, 0XB);
    // vmadh       $v29, $v7, $v8[0]
    rsp.VMADH<8>(rsp.vpu.r[29], rsp.vpu.r[7], rsp.vpu.r[8]);
    // ssv         $v15[4], 0x1C($23)
    rsp.SSV<4>(rsp.vpu.r[15], r23, 0XE);
    // vmadn       $v29, $v10, $v11[0]
    rsp.VMADN<8>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[11]);
    // ssv         $v20[4], 0x1E($23)
    rsp.SSV<4>(rsp.vpu.r[20], r23, 0XF);
    // vmadh       $v29, $v9, $v11[0]
    rsp.VMADH<8>(rsp.vpu.r[29], rsp.vpu.r[9], rsp.vpu.r[11]);
    // sll         $11, $3, 4
    r11 = S32(r3) << 4;
    // vsar        $v6, $v6, $v6[1]
    rsp.VSAR<9>(rsp.vpu.r[6], rsp.vpu.r[6]);
    // add         $1, $2, $11
    r1 = RSP_ADD32(r2, r11);
    // vsar        $v7, $v7, $v7[0]
    rsp.VSAR<8>(rsp.vpu.r[7], rsp.vpu.r[7]);
    // sll         $11, $9, 5
    r11 = S32(r9) << 5;
    // vmudl       $v29, $v2, $v23[1]
    rsp.VMUDL<9>(rsp.vpu.r[29], rsp.vpu.r[2], rsp.vpu.r[23]);
    // add         $23, $1, $11
    r23 = RSP_ADD32(r1, r11);
    // vmadm       $v29, $v3, $v23[1]
    rsp.VMADM<9>(rsp.vpu.r[29], rsp.vpu.r[3], rsp.vpu.r[23]);
    // andi        $6, $6, 0x1
    r6 = r6 & 0X1;
    // vmadn       $v2, $v2, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[24]);
    // sll         $11, $6, 4
    r11 = S32(r6) << 4;
    // vmadh       $v3, $v3, $v24[1]
    rsp.VMADH<9>(rsp.vpu.r[3], rsp.vpu.r[3], rsp.vpu.r[24]);
    // add         $23, $23, $11
    r23 = RSP_ADD32(r23, r11);
    // vmudl       $v29, $v6, $v23[1]
    rsp.VMUDL<9>(rsp.vpu.r[29], rsp.vpu.r[6], rsp.vpu.r[23]);
    // vmadm       $v29, $v7, $v23[1]
    rsp.VMADM<9>(rsp.vpu.r[29], rsp.vpu.r[7], rsp.vpu.r[23]);
    // vmadn       $v6, $v6, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[24]);
    // sdv         $v2[0], 0x18($2)
    rsp.SDV<0>(rsp.vpu.r[2], r2, 0X3);
    // vmadh       $v7, $v7, $v24[1]
    rsp.VMADH<9>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[24]);
    // sdv         $v3[0], 0x8($2)
    rsp.SDV<0>(rsp.vpu.r[3], r2, 0X1);
    // vmadl       $v29, $v2, $v20[3]
    rsp.VMADL<11>(rsp.vpu.r[29], rsp.vpu.r[2], rsp.vpu.r[20]);
    // sdv         $v2[8], 0x18($1)
    rsp.SDV<8>(rsp.vpu.r[2], r1, 0X3);
    // vmadm       $v29, $v3, $v20[3]
    rsp.VMADM<11>(rsp.vpu.r[29], rsp.vpu.r[3], rsp.vpu.r[20]);
    // sdv         $v3[8], 0x8($1)
    rsp.SDV<8>(rsp.vpu.r[3], r1, 0X1);
    // vmadn       $v8, $v2, $v15[3]
    rsp.VMADN<11>(rsp.vpu.r[8], rsp.vpu.r[2], rsp.vpu.r[15]);
    // sdv         $v6[0], 0x38($2)
    rsp.SDV<0>(rsp.vpu.r[6], r2, 0X7);
    // vmadh       $v9, $v3, $v15[3]
    rsp.VMADH<11>(rsp.vpu.r[9], rsp.vpu.r[3], rsp.vpu.r[15]);
    // sdv         $v7[0], 0x28($2)
    rsp.SDV<0>(rsp.vpu.r[7], r2, 0X5);
    // vmudn       $v29, $v5, $v1[0]
    rsp.VMUDN<8>(rsp.vpu.r[29], rsp.vpu.r[5], rsp.vpu.r[1]);
    // sdv         $v6[8], 0x38($1)
    rsp.SDV<8>(rsp.vpu.r[6], r1, 0X7);
    // vmadh       $v29, $v18, $v1[0]
    rsp.VMADH<8>(rsp.vpu.r[29], rsp.vpu.r[18], rsp.vpu.r[1]);
    // sdv         $v7[8], 0x28($1)
    rsp.SDV<8>(rsp.vpu.r[7], r1, 0X5);
    // vmadl       $v29, $v8, $v4[1]
    rsp.VMADL<9>(rsp.vpu.r[29], rsp.vpu.r[8], rsp.vpu.r[4]);
    // sdv         $v8[0], 0x30($2)
    rsp.SDV<0>(rsp.vpu.r[8], r2, 0X6);
    // vmadm       $v29, $v9, $v4[1]
    rsp.VMADM<9>(rsp.vpu.r[29], rsp.vpu.r[9], rsp.vpu.r[4]);
    // sdv         $v9[0], 0x20($2)
    rsp.SDV<0>(rsp.vpu.r[9], r2, 0X4);
    // vmadn       $v5, $v8, $v26[1]
    rsp.VMADN<9>(rsp.vpu.r[5], rsp.vpu.r[8], rsp.vpu.r[26]);
    // sdv         $v8[8], 0x30($1)
    rsp.SDV<8>(rsp.vpu.r[8], r1, 0X6);
    // vmadh       $v18, $v9, $v26[1]
    rsp.VMADH<9>(rsp.vpu.r[18], rsp.vpu.r[9], rsp.vpu.r[26]);
    // sdv         $v9[8], 0x20($1)
    rsp.SDV<8>(rsp.vpu.r[9], r1, 0X4);
    // vmudn       $v10, $v8, $v4[1]
    rsp.VMUDN<9>(rsp.vpu.r[10], rsp.vpu.r[8], rsp.vpu.r[4]);
    // beq         $6, $zero, L_095C
    if (r6 == 0) {
        // vmudn       $v8, $v8, $v30[7]
        rsp.VMUDN<15>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[30]);
        goto L_095C;
    }
    // vmudn       $v8, $v8, $v30[7]
    rsp.VMUDN<15>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[30]);
    // vmadh       $v9, $v9, $v30[7]
    rsp.VMADH<15>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[30]);
    // sdv         $v5[0], 0x10($2)
    rsp.SDV<0>(rsp.vpu.r[5], r2, 0X2);
    // vmudn       $v2, $v2, $v30[7]
    rsp.VMUDN<15>(rsp.vpu.r[2], rsp.vpu.r[2], rsp.vpu.r[30]);
    // sdv         $v18[0], 0x0($2)
    rsp.SDV<0>(rsp.vpu.r[18], r2, 0X0);
    // vmadh       $v3, $v3, $v30[7]
    rsp.VMADH<15>(rsp.vpu.r[3], rsp.vpu.r[3], rsp.vpu.r[30]);
    // sdv         $v5[8], 0x10($1)
    rsp.SDV<8>(rsp.vpu.r[5], r1, 0X2);
    // vmudn       $v6, $v6, $v30[7]
    rsp.VMUDN<15>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[30]);
    // sdv         $v18[8], 0x0($1)
    rsp.SDV<8>(rsp.vpu.r[18], r1, 0X0);
    // vmadh       $v7, $v7, $v30[7]
    rsp.VMADH<15>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[30]);
    // ssv         $v8[14], 0xFA($23)
    rsp.SSV<14>(rsp.vpu.r[8], r23, -0X3);
    // vmudl       $v29, $v10, $v30[7]
    rsp.VMUDL<15>(rsp.vpu.r[29], rsp.vpu.r[10], rsp.vpu.r[30]);
    // ssv         $v9[14], 0xF8($23)
    rsp.SSV<14>(rsp.vpu.r[9], r23, -0X4);
    // vmadn       $v5, $v5, $v30[7]
    rsp.VMADN<15>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[30]);
    // ssv         $v2[14], 0xF6($23)
    rsp.SSV<14>(rsp.vpu.r[2], r23, -0X5);
    // vmadh       $v18, $v18, $v30[7]
    rsp.VMADH<15>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[30]);
    // ssv         $v3[14], 0xF4($23)
    rsp.SSV<14>(rsp.vpu.r[3], r23, -0X6);
    // ssv         $v6[14], 0xFE($23)
    rsp.SSV<14>(rsp.vpu.r[6], r23, -0X1);
    // ssv         $v7[14], 0xFC($23)
    rsp.SSV<14>(rsp.vpu.r[7], r23, -0X2);
    // ssv         $v5[14], 0xF2($23)
    rsp.SSV<14>(rsp.vpu.r[5], r23, -0X7);
    // j           L_125C
    // ssv         $v18[14], 0xF0($23)
    rsp.SSV<14>(rsp.vpu.r[18], r23, -0X8);
    goto L_125C;
    // ssv         $v18[14], 0xF0($23)
    rsp.SSV<14>(rsp.vpu.r[18], r23, -0X8);
    // sdv         $v5[0], 0x10($2)
    rsp.SDV<0>(rsp.vpu.r[5], r2, 0X2);
    // sdv         $v18[0], 0x0($2)
    rsp.SDV<0>(rsp.vpu.r[18], r2, 0X0);
    // sdv         $v5[8], 0x10($1)
    rsp.SDV<8>(rsp.vpu.r[5], r1, 0X2);
    // j           L_125C
    // sdv         $v18[8], 0x0($1)
    rsp.SDV<8>(rsp.vpu.r[18], r1, 0X0);
    goto L_125C;
    // sdv         $v18[8], 0x0($1)
    rsp.SDV<8>(rsp.vpu.r[18], r1, 0X0);
    // lhu         $25, 0x380($25)
    r25 = RSP_MEM_HU_LOAD(0X380, r25);
    // lhu         $24, 0x380($24)
    r24 = RSP_MEM_HU_LOAD(0X380, r24);
    // addiu       $1, $zero, 0x7070
    r1 = RSP_ADD32(0, 0X7070);
    // lw          $11, 0x24($25)
    r11 = RSP_MEM_W_LOAD(0X24, r25);
    // and         $1, $1, $11
    r1 = r1 & r11;
    // beq         $1, $zero, L_1EC4
    if (r1 == 0) {
        // lw          $11, 0x4C($25)
        r11 = RSP_MEM_W_LOAD(0X4C, r25);
        goto L_1EC4;
    }
    // lw          $11, 0x4C($25)
    r11 = RSP_MEM_W_LOAD(0X4C, r25);
    // bne         $25, $24, L_0980
    if (r25 != r24) {
        // addiu       $25, $25, 0x28
        r25 = RSP_ADD32(r25, 0X28);
        goto L_0980;
    }
    // addiu       $25, $25, 0x28
    r25 = RSP_ADD32(r25, 0X28);
    // j           L_11EC
    // lhu         $25, 0x380($25)
    r25 = RSP_MEM_HU_LOAD(0X380, r25);
    goto L_11EC;
    // lhu         $25, 0x380($25)
    r25 = RSP_MEM_HU_LOAD(0X380, r25);
    // lw          $25, 0x1C($25)
    r25 = RSP_MEM_W_LOAD(0X1C, r25);
    // sub         $2, $25, $24
    r2 = RSP_SUB32(r25, r24);
    // bgez        $2, L_1EC4
    if (RSP_SIGNED(r2) >= 0) {
        // lw          $24, 0xD8($zero)
        r24 = RSP_MEM_W_LOAD(0XD8, 0);
        goto L_1EC4;
    }
    // lw          $24, 0xD8($zero)
    r24 = RSP_MEM_W_LOAD(0XD8, 0);
    // j           L_1008
    // lbu         $1, 0x9C1($27)
    r1 = RSP_MEM_BU(0X9C1, r27);
    goto L_1008;
    // lbu         $1, 0x9C1($27)
    r1 = RSP_MEM_BU(0X9C1, r27);
    // j           L_1040
    // lhu         $25, 0x380($25)
    r25 = RSP_MEM_HU_LOAD(0X380, r25);
    goto L_1040;
    // lhu         $25, 0x380($25)
    r25 = RSP_MEM_HU_LOAD(0X380, r25);
    return RspExitReason::ImemOverrun;
do_indirect_jump:
    switch ((jump_target | 0x1000) & 0X1FFF) { 
        case 0x02D4: goto L_02D4;
        case 0x2234: goto L_2234;
        case 0x24EC: goto L_24EC;
        case 0x1B1C: goto L_1B1C;
        case 0x1214: goto L_1214;
        case 0x1334: goto L_1334;
        case 0x12C4: goto L_12C4;
        case 0x11D4: goto L_11D4;
        case 0x1EF8: goto L_1EF8;
        case 0x1710: goto L_1710;
        case 0x1188: goto L_1188;
        case 0x22C0: goto L_22C0;
        case 0x1304: goto L_1304;
        case 0x1D3C: goto L_1D3C;
        case 0x0280: goto L_0280;
        case 0x1EA8: goto L_1EA8;
        case 0x01A8: goto L_01A8;
        case 0x1EB8: goto L_1EB8;
        case 0x1EC8: goto L_1EC8;
        case 0x2214: goto L_2214;
        case 0x2240: goto L_2240;
        case 0x10FC: goto L_10FC;
        case 0x2280: goto L_2280;
        case 0x1B68: goto L_1B68;
        case 0x18A4: goto L_18A4;
        case 0x1144: goto L_1144;
        case 0x22C8: goto L_22C8;
        case 0x0014: goto L_0014;
        case 0x10B4: goto L_10B4;
        case 0x0108: goto L_0108;
    }
    printf("Unhandled jump target 0x%04X in microcode aspMain, coming from [%s:%d]\n", jump_target, debug_file, debug_line);
    printf("Register dump: r0  = %08X r1  = %08X r2  = %08X r3  = %08X r4  = %08X r5  = %08X r6  = %08X r7  = %08X\n"
           "               r8  = %08X r9  = %08X r10 = %08X r11 = %08X r12 = %08X r13 = %08X r14 = %08X r15 = %08X\n"
           "               r16 = %08X r17 = %08X r18 = %08X r19 = %08X r20 = %08X r21 = %08X r22 = %08X r23 = %08X\n"
           "               r24 = %08X r25 = %08X r26 = %08X r27 = %08X r28 = %08X r29 = %08X r30 = %08X r31 = %08X\n",
           0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16,
           r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31);
    return RspExitReason::UnhandledJumpTarget;
    L_0008:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0014:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0038:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0050:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_007C:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0108:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_01A8:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_01C4:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_01D8:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_01F4:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_021C:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0280:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_02D4:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_063C:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_07D4:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_095C:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0980:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0CDC:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_0D04:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_1008:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_1020:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_103C:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_1040:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
    L_1064:
        return RspExitReason::UnhandledJumpTarget; // rspboot address
}