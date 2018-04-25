def selectionsort(seq):
	if len(seq)<=1:
		return seq
	sorted_seq	= []
	min_index = 0
	seq_min = seq[0]
	for i in xrange(1,len(seq)):
		if seq[i]<seq_min:
			seq_min = seq[i]
			min_index = i

	sorted_seq.append(seq_min)
	seq.pop(min_index)
	return sorted_seq+selectionsort(seq)

seq = [2,3,34,5,6,1,1,0]
print selectionsort(seq)
