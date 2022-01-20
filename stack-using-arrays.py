class stack:
	def __init__():
		self.l = []
		self.pointer = -1
	def __init__(default_value):
		self.l = []
		self.l.append(default_value)
		self.pointer = 0
	def is_empty(self):
		if self.l == -1:
			return true
		return false
	def pop(self):
		if not self.is_empty():
			ret = self.l[self.pointer]
			self.pointer = self.pointer - 1
			return ret
		else:
			return None
	def push(self, val):
		try:
			self.l.append(val)
			self.pointer += 1
			return true
		except:
			return false
