.data
score_out: 	.byte 0
score_outer: 	.byte 1
score_middle: 	.byte 5
score_inner: 	.byte 10

outer_rad: 	.float 10.0
middle_rad: 	.float 5.0
inner_rad: 	.float 1.0


.global main
.text
main:
  # Le o primeiro numero
  li 		a7, 6			# Leitura de float
  ecall					# Chamada para ler o x
  fmv.s 	ft0, fa0		# Move o float lido para f0
  
  # Le o segundo 
  ecall					# Chamada para ler o y
  fmv.s 	ft1, fa0		# Move o float para f1


calculate:
  fmul.s 	ft0, ft0, ft0		# Calcula o quadrado de x
  fmul.s 	ft1, ft1, ft1		# Calcula o quadrado de y  
  fadd.s 	ft2, ft0, ft1		# Calcula soma dos quadrados
  fsqrt.s 	ft2, ft2  		# Calcula a raíz quadrada da soma dos quadrados (distancia)
  
  
compare:
  li 		a7, 1			# Print de int
  
  flw		ft3, outer_rad, t1	# carrega o raio externo
  fgt.s 	t0, ft2, ft3		# Compara a distancia com o valor
  bnez 		t0, out			# Se for maior, errou o alvo
  
  flw		ft3, middle_rad, t1	# carrega o raio do meio
  fgt.s 	t0, ft2, ft3		# Compara a distancia com o valor
  bnez 		t0, outer_ring		# Se for maior, acertou no anel externo
  
  flw		ft3, inner_rad, t1	# carrega o raio interno
  fgt.s 	t0, ft2, ft3		# Compara a distancia com o valor
  bnez 		t0, middle_ring		# Se for maior, acertou o raio do meio
  
  # Se passou por tudo acertou o meio
  j inner_ring
  

out:
  lb 		t1, score_out 		# Carrega 0 na saida
  mv 		a0, t1
  j 		exit


outer_ring:
  lb 		t1, score_outer		# Carrega 0 na saida
  mv 		a0, t1
  j 		exit

middle_ring:
  lb 		t1, score_middle	# Carrega 0 na saida
  mv 		a0, t1
  j 		exit

inner_ring:
  lb 		t1, score_inner 	# Carrega 0 na saida
  mv 		a0, t1
  j 		exit

exit:
  ecall					# Chamada para printar
  li a7, 10
  ecall