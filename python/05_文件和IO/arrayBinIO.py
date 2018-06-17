import array

nums = array.array('i',[1,2,3,4])
filename = 'data.bin'
with open(filename,'wb') as f:
	f.write(nums)

a = array.array('i',[0,0,0,0,0,0,0,0])
with open(filename,'rb') as f:
	f.readinto(a)

print a
