#!/usr/bin/python
import cube
import os
import sys
import random

if len(sys.argv)<2 :
	print "usage: %s 1-4"%sys.argv[0]
	sys.exit()

times = 0
error = 0
moves_all = ['u','l','r','d','f','b','w','p','q','x','y','z'];
moves_2 = ['u','x','FUFUFufuf','fufufUFUF'];
moves_3 = ['u','x','fruRUF','RuuruRur'];
moves_4 = ['u','x','rUrururURUrr'];
start_step = int(sys.argv[1])

def apply_move(steps):
	for i in steps:
		cube.rotate(i)

def random_move(start):
	if start <= 1:
		for i in xrange(0,100):
			step = random.choice(moves_all)
			apply_move(step)
	elif start <= 2:
		for i in xrange(0,20):
			step = random.choice(moves_2)
			apply_move(step)
	elif start <= 3:
		for i in xrange(0,10):
			step = random.choice(moves_3)
			apply_move(step)
	elif start <= 4:
		for i in xrange(0,5):
			step = random.choice(moves_4)
			apply_move(step)

def correct():
	for i in xrange(0, 6):
		clr = cube.getcolor(i, 0, 0)
		for j in xrange(0, 3):
			for k in xrange(0, 3):
				if cube.getcolor(i, j, k) != clr:
					return False
	return True


while True:
	cube.reset()

	random_move(start_step)

	cube.writestate()

	if start_step<=1:
		apply_move(cube.simplify(cube.step_all()))
	else:
		if start_step<=2:
			apply_move(cube.step2())
		if start_step<=3:
			apply_move(cube.step3())
		
		apply_move(cube.step4())

	if not correct():
		error += 1
		os.rename ("cube.save", ("cube.err%d"%error) )

	times += 1

	if times%1000 == 0:
		print "Progress: %d/%d" % (error, times)

	if error > 50:
		break
