; The sparc back-end is generating set-unsigned (setuw) for -2, when it
; should be using setsw.  

implementation

int %main(int %argc, sbyte * * %argv) {
	%T1 = cast int 2 to uint
	%tmp = add uint %T1, 4294967294  ; == -2
	%cond = seteq uint %tmp, 0
	br bool %cond, label %Ok, label %Fail
Ok:
	ret int 0
Fail:
	ret int 1
}
