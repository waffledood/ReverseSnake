@
@ Author:
@ Date..:
@
.arm
@.section .iwram
.align   2
.global  FunctionName
.type    FunctionName, %function
.align

FunctionName:
    @ save registers on stack
    stmfd   sp!, {r?-r?}


    @ load registers from stack
    ldmfd   sp!, {r?-r?}
    bx      lr

.size	FunctionName, .-FunctionName

