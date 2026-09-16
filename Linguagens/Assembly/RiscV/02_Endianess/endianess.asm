.data
big: .asciz "This computer is big endian!"
little: .asciz "This computer is little endian"
test_byte: .word 0x12345678

.global main
.text
main:
  la 	t0, test_byte		# Carrega a palavra de teste
  lb	t1, 0(t0)		# Pega o primeiro byte na memória
  li 	t2, 0x78		# 0x78 é o valor esperado para little Endian (menos significativo)
  beq 	t1, t2, little_endian	# Se t1 == 0x78, o byte é o menos significativo
  j 	big_endian
  
little_endian:
  la 	a0, little
  li 	a7, 4
  ecall
  j 	exit

big_endian:
  la 	a0, big
  li 	a7, 4
  ecall
  j 	exit

exit:
  li 	a7, 10
  ecall