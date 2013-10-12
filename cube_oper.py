class ElementSet:
	all_layer = False
	layer_type = ''
	layer_num = 0

	def __init__(self, ** arg):
		if 'all' in arg:
			self.all_layer = True
		else:
			for i in arg.keys():
				self.layer_type = i
				self.layer_num = arg[i]
	def contains(self, x, y, z):
		if self.all_layer:
			return True
		if self.layer_type == 'x':
			return self.layer_num == ElementSet.sgn(x)
		elif self.layer_type == 'y':
			return self.layer_num == ElementSet.sgn(y)
		elif self.layer_type == 'z':
			return self.layer_num == ElementSet.sgn(z)

	@staticmethod
	def sgn(x):
		if x<0:
			return -1
		elif x>0:
			return 1
		else:
			return 0

Operations = {
	'f': ( ElementSet(z = 1), 'z', -1),
	'F': ( ElementSet(z = 1), 'z', 1),
	'b': ( ElementSet(z = -1), 'z', 1),
	'B': ( ElementSet(z = -1), 'z', -1),
	'q': ( ElementSet(z = 0), 'z', -1),
	'Q': ( ElementSet(z = 0), 'z', 1),
	
	'u': ( ElementSet(y = 1), 'y', -1),
	'U': ( ElementSet(y = 1), 'y', 1),
	'd': ( ElementSet(y = -1), 'y', 1),
	'D': ( ElementSet(y = -1), 'y', -1),
	'p': ( ElementSet(y = 0), 'y', -1),
	'P': ( ElementSet(y = 0), 'y', 1),
	
	'r': ( ElementSet(x = 1), 'x', -1),
	'R': ( ElementSet(x = 1), 'x', 1),
	'l': ( ElementSet(x = -1), 'x', 1),
	'L': ( ElementSet(x = -1), 'x', -1),
	'w': ( ElementSet(x = 0), 'x', -1),
	'W': ( ElementSet(x = 0), 'x', 1),

	'x': ( ElementSet(all = True), 'y', -1),
	'X': ( ElementSet(all = True), 'y', 1),
	'y': ( ElementSet(all = True), 'z', -1),
	'Y': ( ElementSet(all = True), 'z', 1),
	'z': ( ElementSet(all = True), 'x', -1),
	'Z': ( ElementSet(all = True), 'x', 1),
}
