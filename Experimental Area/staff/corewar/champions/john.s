.name "john"
.comment "yes, i'm john"

loop:
	sti r1,%:live,%1
#	and r1,%1,r2
	live:	live %1
	fork %:loop
#	and r1,%0,r1
	ld %1, r2
	zjmp %:loop

#l2: 	sti r1,%:live,%1
#	and r1,%0,r1

#live: 	live %1
#	zjmp %:live
