# Debug Notes
- Notes for understanding the bugs reported by the compiler.

## Stack overflow & Segmentation fault
- [Segmentation Fault](https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault?rq=1)
  - A kind of error caused by accessing memory that "does not belong to you". It's a helper machanism that keeps you from corrupting the memory and introducing hard-to-debug memory bugs. for instance,
	- Accessing variables that has already been freed.
	- Writing to a read-only portion of the memory.
```C++
//case 1:dereference a null pointer
int *p=NULL;
*p=1;//dereference

//case 2: write to a portion of memory marked as read-only
char *str="Foo";
*str = 'b';

//case3: dangling pointer points to a thing that doesn't exist any more
char *p = NULL;
{
	char c;
	p = &c;
}
```
- About `Stack Overflow & Segmentation Fault`. In short, stack overflow is the cause, segmention fault is the result.
  - Concepts
	- `segmentations` is meant to keep programs from memory in certain ways. For instance, one segment could be marked read-only and the code could be put here and another segment be marked read/write and that is where the data goes;
	- `Stack` refers to a piece of memory reserved for placing local variables and returned addresses of function calls.
  - Relation
	- When the stack is exhausted, the memory outside the reserved memory will be accessed while the app is not granted the right to access it, thus a `Segmentation Fault` is generated.

# branch prediction
- Where there is data-dependent branching structure(`if` statement), for better instructionn prepared in CPU, the compiler will try to predict which way you the program might choose therefore saving time for instructions loading.
  - if it predicts right, the program could run smoothly without needing to stop;however when it predicts the wrong one, it could take more time to setup the instructions;
  - If you want to avoid the time comsumption brought by branch prediction, try	
	- make the prediction easier for compiler;
	- replace the data-dependent branching with other code(hack code );















