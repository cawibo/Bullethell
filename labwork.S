  # labwork.S
  # Written 2015 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1 2015-2016.
  # The macros PUSH and POP are in the public domain.

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm

  # You can add your own code here
  #

  .global time2string, delay
  .data
  .align 2
  .text

hexasc:
  andi $a0, $a0, 0xf
  blt $a0,10,numeric  # om $a0 = {0-9} goto numeric
  nop
  blt $a0,16,alpha  # om $a0 = {10-15} goto alpha
  nop

numeric:
  addi $a0,$a0,0x30 # 0x30 är diffen mellan ental och dess ascii
  move $v0,$a0    # flytta argument till returvärde
  jr $ra        # 'returnera hexasc'
  nop

alpha:
  addi $a0,$a0,0x37 # 0x37 är diffen mellan 10-15 och dess ascii
  move $v0,$a0    # flytta argument till returvärde
  jr $ra        # 'returnera hexasc
  nop

  #
  #

delay:
  bgtz $a0, delay_loop
  nop
  jr $ra
  nop

delay_loop:
  addiu $a0,$a0, -1
  li $t1, 30000 # <-- här är värdet, hyfsat enkelt att ändra

inner_delay_loop:
  addiu $t1,$t1, -1
  bgtz $t1, inner_delay_loop
  nop
  
  bgtz $a0, delay_loop
  nop
  jr $ra
  nop

  #
  #

time2string:
  PUSH $ra
  move $t0,$a0  # destination finns nu i t0

    # surprise
  andi $a0, $a1, 0x000000ff
  beq $a0, $t1, surprise
  nop

    # null
  li $t1,0x00
  sb $t1,5($t0)

    # ental sekunder
  andi $a0,$a1,0x0000000f
  jal hexasc
  nop
  sb $v0,4($t0)

    # tiotal sekunder
  andi $a0,$a1,0x000000f0
  srl $a0,$a0,4
  jal hexasc
  nop
  sb $v0,3($t0)

    # kolon :
  li $t1,0x3a
  sb $t1,2($t0)

    # ental minuter
  andi $a0,$a1,0x00000f00
  srl $a0,$a0,8
  jal hexasc
  nop
  sb $v0,1($t0)

    # tiotal minuter
  andi $a0,$a1,0x0000f000
  srl $a0,$a0,12
  jal hexasc
  nop
  sb $v0,0($t0)

  POP $ra
  jr $ra
  nop

surprise:
  li $t1, 0x00
  sb $t1,4($t0)

  li $t1, 0x47
  sb $t1,3($t0)
  
  li $t1, 0x4E
  sb $t1,2($t0)
  
  li $t1, 0x49
  sb $t1,1($t0) 
  
  li $t1, 0x44
  sb $t1,0($t0)
  
  POP $ra
  jr $ra
  nop


