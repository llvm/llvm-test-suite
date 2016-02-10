def wrapScript(context, runscript):
    profilefile = context.tmpBase + ".perf_data"
    profilescript = []
    for line in runscript:
        profilescript.append(
            ' '.join(
                ['perf record -e cycles,cache-misses,branch-misses -o',
                 profilefile, line]))
    return profilescript
