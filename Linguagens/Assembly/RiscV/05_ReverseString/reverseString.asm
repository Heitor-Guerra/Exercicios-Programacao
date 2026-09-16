.data
# string_buffer: .space 100		# Alocação Estática
max_bytes: .word 100

.text
.global main
main:
#  la 	a0, string_buffer		# Alocação Estática
  jal	allocateMemory
  lw 	a1, max_bytes	
  li 	a7, 8
  ecall
  mv 	t0, a0				# Coloca o endereço alocado em t0
  mv	t1, t0
  
  
gotoEnd:
  lb	t2, 0(t1)			# Carrrega o byte 
  beqz 	t2, end		# Se chegou no /0
  addi	t1, t1, 1			# Avança t1
  j 	gotoEnd
  
  
end:
  addi 	t1, t1, -1        		# ponteiro direito = inicio + tamanho

  jal	allocateMemory
  mv 	t2, a0				# Coloca o endereço alocado em t2
  mv 	t3, t2

reverse:
  bgt 	t0, t1 final
  lb 	t4, 0(t1)
  sb 	t4, 0(t3) 
  addi 	t1, t1, -1
  addi	t3, t3, 1
  j 	reverse
  
  
final:
  sb	zero, 0(t3)
  mv 	a0, t2
  li 	a7, 4
  ecall


exit:
  li a7, 10
  ecall
  
allocateMemory:
  # Aloca 100 bytes de memória na heap
  lw	a0, max_bytes
  li 	a7, 9
  ecall
  ret