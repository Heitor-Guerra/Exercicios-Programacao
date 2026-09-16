.data
leap: .asciz "The year is leap"
nLeap: .asciz "The year is not leap"


.text
.global main
main:
  
  li 	a7, 5		# Le o ano
  ecall
  mv 	t0, a0		# Move o ano para t0
   
  li 	t1, 4
  rem 	t2, t0, t1	# O resto da divisao do ano por 4
  bnez 	t2, notLeap

  li 	t1, 100
  rem 	t2, t0, t1	# O resto da divisao do ano por 4
  bnez	t2, leapYear
      
  li 	t1, 400
  rem 	t2, t0, t1	# O resto da divisao do ano por 4
  beqz	t2, leapYear
   
notLeap:
  la 	a0, nLeap
  li 	a7, 4
  ecall
  j	exit
  
leapYear:
  la 	a0, leap
  li 	a7, 4
  ecall
   
exit:
  li 	a7, 10
  ecall