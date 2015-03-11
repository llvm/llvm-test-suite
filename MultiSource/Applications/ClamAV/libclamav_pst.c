#include "clamav-config.h"
#include "clamav.h"
#include "others.h"
int
cli_pst(const char *dir, int desc)
{
        cli_warnmsg("PST files not yet supported\n");
        return CL_EFORMAT;
}
