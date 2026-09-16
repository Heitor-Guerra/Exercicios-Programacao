.data


.text
.global main
main:
  jal 	readInt
  mv 	t1, t0
  li 	t2, 2
  
  beqz 	t0, baseCase
  j 	factorial

factorial:
  ble 	t0, t2, print 
  mul 	t1, t1, t2
  addi 	t2, t2, 1
  j 	factorial 

baseCase:
  li t1, 1

print:
  mv 	a0, t1
  li	a7, 1
  ecall

exit:
  li 	a7, 10
  ecall

readInt:
  li 	a7, 5
  ecall
  mv 	t0, a0
  ret