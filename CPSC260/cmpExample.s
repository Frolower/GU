# ----------------------------------------------------------------------------------------
# Find the maxmum value among three. Runs on 64-bit Linux only.
# To assemble and run:
#
#     gcc -c Assignment7.s && ld Assignment7.o && ./a.out
#
# or
#
#     gcc -nostdlib Assignment7.s && ./a.out
# ----------------------------------------------------------------------------------------

        .global _start

        .text
_start:
        # write your program below
		movl $22, %ebx     # a = 22
		movl $13, %ecx		# b = 13
		cmpl %ecx, %ebx     # a>b ?
		jg _larger          
		movl $0, %eax    # if a is not larger than b
		jmp _Exit
_larger:movl $3, %eax    # if a is larger
_Exit: 		
		
		
		# write your program above

        # exit(0)
        mov     $60, %rax               # system call 60 is exit
        xor     %rdi, %rdi              # we want return code 0
        syscall                         # invoke operating system to exit


