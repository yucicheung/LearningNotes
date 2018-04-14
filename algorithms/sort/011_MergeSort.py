# accomplish merge_sort using list
def merge_sort(seq):
	if len(seq)<=1:
		return seq

	def merge(lseq,rseq):
		merged = []
		while lseq and rseq:
			if lseq[0]<rseq[0]:
				merged.append(lseq[0])
				lseq.pop(0)
			else:
				merged.append(rseq[0])
				rseq.pop(0)
		if lseq:
			merged+=lseq
		else:
			merged+=rseq
		return merged

	mid = len(seq)/2
	lseq = seq[:mid]
	rseq = seq[mid:]
	lseq = merge_sort(lseq)
	rseq = merge_sort(rseq)
	return merge(lseq,rseq)

seq = [2,2,1,7,4,5,0,]
print merge_sort(seq)
