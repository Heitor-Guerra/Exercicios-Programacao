.data
space1: .space 100
space2: .space 100

.text
.global main
main:
  la 	a0, space1
  jal 	readString
  mv 	t0, a0
  
  la 	a0, space2
  jal 	readString
  mv 	t1, a0

  mv 	t4, zero

traverse:
  lb 	t2, 0(t0)
  lb 	t3, 0(t1)
  beqz 	t2, end
  beqz 	t3, end
  
  sub 	t2, t2, t3
  snez 	t2, t2
  add 	t4, t4, t2
  
  addi 	t0, t0, 1
  addi 	t1, t1, 1
  
  j traverse
  
end:
  mv 	a0, t4
  li 	a7, 1
  ecall
  
exit:
  li a7, 10
  ecall  

readString:
  li	a1, 100
  li	a7, 8
  ecall
  ret