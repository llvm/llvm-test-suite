; Test to make sure the invoke instruction and llvm.unwind intrinsic are 
; working...

implementation

declare void %llvm.unwind()
declare void %abort()

internal void %throw(bool %ShouldThrow) {
	br bool %ShouldThrow, label %Throw, label %NoThrow
Throw:
	call void %llvm.unwind()
	call void %abort()           ;;; dead
	ret void
NoThrow:
	ret void
}

int %main() {
	invoke void %throw(bool false) to label %Cont except label %Abort
Cont:
	invoke void %throw(bool true) to label %Abort except label %Exc
Abort:
	call void %abort()
	ret int 1
Exc:
	ret int 0
}
