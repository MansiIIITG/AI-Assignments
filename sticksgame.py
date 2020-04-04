from random import randint
from sticks_func import Node
from sticks_func import AlphaBeta
from sticks_func import Dec
from sticks_func import MinMax

maxsize = 1000000


if __name__ == '__main__':
	sticksTotal = int(input("\nPick no. of sticks : "))
	depth = 4
	currPlayer = 0

	choice = input('Enter your choice :\n\'a\' for Bot1 v/s Bot2\n\'b\' Bot v/s Human :\t')

	if choice == 'a':
		AI_num = int(input("Which bot do you want to play first ? (1 or 2) : "))
		currPlayer = 1 if AI_num == 1 else -1
		Player_AI, Opp_AI = randint(1,3), 0
		print('AI-{}\'s choice : {}'.format(AI_num, Player_AI))
		node2 = Node(depth,currPlayer,sticksTotal)
		sticksTotal -= Player_AI

		while sticksTotal > 0:
			currPlayer = 1

			if Dec(sticksTotal, currPlayer, False):
				currPlayer = -1
				node = Node(depth,currPlayer,sticksTotal)
				bestChoice = -100
				bestVal = -currPlayer*maxsize
				for i in range(len(node.children)):
					nChild = node.children[i]
					newVal = AlphaBeta(nChild, depth, maxsize, -maxsize, currPlayer)
					if abs(currPlayer*maxsize-newVal) <= abs(currPlayer*maxsize-bestVal):
						bestVal = newVal
						bestChoice = i
				bestChoice += 1
				if bestChoice > sticksTotal:
					bestChoice = sticksTotal
				print("AI-{}\'s choice : {}".format(4-AI_num, bestChoice))
				sticksTotal -= bestChoice
				Dec(sticksTotal, currPlayer, False)
			currPlayer *= -1
			AI_num = 4 - AI_num


	elif choice == 'b':
		while currPlayer != 1 and currPlayer != -1:
			currPlayer = input("Want to play first ? (y or n) : ")
			currPlayer = 1 if currPlayer == 'y' else -1
			node2 = Node(depth,currPlayer,sticksTotal)

			if currPlayer == 1:
				print("Pick either 1, 2 or 3 sticks")

			while sticksTotal > 0:
				if currPlayer == 1:
					print("{} sticks remain. Pick number\n".format(sticksTotal))
					choice = int(input("Human's choice : "))
					while choice > 3 or choice > sticksTotal:
						print("{} sticks remain. Pick correctly!!!\n".format(sticksTotal))
						choice = int(input("Human's choice : "))
					sticksTotal -= int(float(choice))

				else:
					currPlayer = 1

				if Dec(sticksTotal, currPlayer):
					currPlayer *= -1
					node = Node(depth,currPlayer,sticksTotal)
					bestChoice = -100
					bestVal = -currPlayer*maxsize
					for i in range(len(node.children)):
						nChild = node.children[i]
						newVal = AlphaBeta(nChild, depth, maxsize, -maxsize, currPlayer)
						if abs(currPlayer*maxsize-newVal) <= abs(currPlayer*maxsize-bestVal):
							bestVal = newVal
							bestChoice = i
					bestChoice += 1
					if bestChoice>sticksTotal:
						bestChoice = sticksTotal
					print("AI's choice : {}\n".format(bestChoice))
					sticksTotal -= bestChoice
					Dec(sticksTotal, currPlayer)
				currPlayer *= -1