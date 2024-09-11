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

 		
		
		
		# write your program above

_Exit:  # exit(0)
        mov     $60, %rax               # system call 60 is exit
        xor     %rdi, %rdi              # we want return code 0
        syscall                         # invoke operating system to exit


