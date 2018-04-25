# -*- coding: utf-8 -*-
# achieve with deque
from collections import deque

def merge_sort(seq):
	if len(seq)<=1:
		return seq
	def merge(lseq,rseq):
		merged, lseq, rseq = deque(),deque(lseq),deque(rseq)
		while lseq and rseq:
			merged.append(lseq.popleft() if lseq[0] <= rseq[0] else rseq.popleft())
		merged.extend(lseq if lseq else rseq)
		return list(merged)

	mid = len(seq)/2
	lseq = seq[:mid]
	rseq = seq[mid:]
	lseq = merge_sort(lseq)
	rseq = merge_sort(rseq)
	seq = merge(lseq,rseq)
	return seq


seq = [9,5,6,2,3,0,8]
print merge_sort(seq)
