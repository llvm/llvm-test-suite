; This testcase ensures the code emitter does something about the fact that
; we can have collisions with keywords


void %byte() {
  ret void
}
int %main() {
  call void %byte()
  ret int 0
}

