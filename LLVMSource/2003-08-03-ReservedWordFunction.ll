; This testcase ensures the code emitter does something about the fact that
; we can have collisions with keywords

target endian = little
target pointersize = 32

void %byte() {
  ret void
}
int %main() {
  call void %byte()
  ret int 0
}

