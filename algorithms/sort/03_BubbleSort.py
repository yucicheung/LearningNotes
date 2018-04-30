#recursion way
def bubbleSort(seq):
	lenSeq=len(seq)
	if lenSeq==1:
		return seq
	else:
		def bubble(seq):
			cycleList = range(len(seq)-1)
			for index in cycleList:
				if seq[index]>seq[index+1]:
					tmp = seq[index]
					seq[index] = seq[index+1]
					seq[index+1] = tmp
			return seq
		seq = bubble(seq)
		return bubbleSort(seq[:-1])+[seq[-1]]

seq = [6,9,-2,56,87,11,-54,3,0,77]
print bubbleSort(seq)
