def quicksort(seq):
	if len(seq)<=1:
		return seq
	pivot = seq[0]
	lseq = [seq[i] for i in xrange(1,len(seq)) if seq[i]<pivot]
	rseq = [seq[i] for i in xrange(1,len(seq)) if seq[i]>=pivot]
	lseq = quicksort(lseq)
	rseq = quicksort(rseq)
	seq = lseq+[pivot]+rseq
	return seq

seq = [2,7,1,0,8,4,6]
print quicksort(seq)
