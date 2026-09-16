.data
msg: .asciz "Hello World!"

.text
.global   main

main:
  la	t1, msg		# Carrega a mensagem para t1
  mv	a0, t1		# Move o endereço para o a0 (registrador de saída para o sistema)
  li	a7, 4		# Coloca o valor para printar no registrador do sistema
  ecall 		# Chama o sistema
  
  
exit:
  li 	a7, 10
  ecall
   