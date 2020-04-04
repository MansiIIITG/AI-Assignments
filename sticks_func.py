maxsize = 1000000

class Node(object):
	def __init__(self,depth,playNum,sticksRem,val=0):
		self.depth=depth
		self.playNum=playNum
		self.sticksRem=sticksRem
		self.val=val
		self.children=[]
		self.makeChildren()


	def makeChildren(self):
		if self.depth>=0:
			for i in range(1,3):
				v=self.sticksRem-i
				self.children.append(Node(self.depth-1,-self.playNum,v,self.realValue(v)))

	def realValue(self,value):
		if(value==0):
			return maxsize*-self.playNum #return maxsize*self.playNum
		elif(value<0): 
			return maxsize*-self.playNum
		return 0

def MinMax(node,depth,playNum):
	if(depth==0) or (abs(node.val)==maxsize):
		return node.val

		bestVal=maxsize*-playNum

	for i in range(len(node.children)):
		child=node.children[i]
		newVal=MinMax(child,depth-1,-playNum)
		if(abs(maxsize*playNum-newVal)<abs(maxsize*playNum-bestVal)):
			bestVal=newVal
	return bestVal

def AlphaBeta(node, depth, alpha, beta, playNum):
	if(depth==0) or (abs(node.val)==maxsize):
		return node.val

	bestVal=maxsize*-playNum
	if (playNum == 1):
		for i in range(len(node.children)):
			child=node.children[i]
			alpha = max(alpha, AlphaBeta(child, depth - 1, alpha, beta, 1))
			if beta <= alpha:
				break
		return alpha
		
	else:
		for i in range(len(node.children)):
			child=node.children[i]
			beta = min(beta, AlphaBeta(child, depth - 1, alpha, beta, -1))
			if beta <= alpha:
				break
		return beta
		
def Dec(sticks,playNum,isHumanPlaying=True):
	if isHumanPlaying:
		if sticks <= 0:
			print("*"*33)
			if playNum > 0:
				if sticks == 0:
					print("\tBot Won")
				else:
					print("\tHuman Won!!!")
			else:
				if sticks == 0:
					print("\tHuman Won!!!")
				else:
					print("\tBot Won!!!")
			print("*"*33)
			return 0
		return 1
	else:
		if sticks <= 0:
			print("*"*33)
			if playNum > 0:
				if sticks == 0:
					print("\tBot1 Won!!!")
				else:
					print("\tBot2 Won!!!")
			else:
				if sticks == 0:
					print("\tBot2 Won!!!")
				else:
					print("\tBot1 Won!!!")
			print("*"*33)
			return 0
		return 1
