// 254.gap uses sgtty/ioctl to disable terminal input buffering. This pointless
// as far as benchmarking goes. Newer iOS SDKs do not provide sgtty.h anymore
// (it's not part of any standards anyway), so this file stubs out some sgtty
// stuff.
#ifndef SYS_IS_BSD
#error workaround assumes the SYS_IS_BSD code is used
#endif

struct tchars {
  int t_intrc;
  int t_quitc;
};
struct sgttyb {
  int sg_flags;
};

#ifndef TIOCGETP
#define TIOCGETP 0
#endif
#ifndef TIOCGETC
#define TIOCGETC 0
#endif
#ifndef TIOCSETC
#define TIOCSETC 0
#endif
#ifndef TIOCSETN
#define TIOCSETN 0
#endif
#ifndef CBREAK
#define CBREAK 0
#endif
#ifndef ECHO
#define ECHO 0
#endif
