%Sp = linkonce global int 0		; <int*> [#uses=1]

implementation   ; Functions:

int %main() {
	store int 123, int* %Sp
	ret int 0
}
