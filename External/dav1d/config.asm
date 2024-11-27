%ifdef ARCH_X86_64
%define ARCH_X86_32 0
%define STACK_ALIGNMENT 16
%else
%define ARCH_X86_32 1
%define ARCH_X86_64 0
%define STACK_ALIGNMENT 4
%endif
%define FORCE_VEX_ENCODING 0
%define PIC 1
%define private_prefix dav1d
