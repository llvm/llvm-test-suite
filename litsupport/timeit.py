import re


def getUserTime(filename):
    """Extract the user time form a .time file produced by timeit"""
    with open(filename) as fd:
        l = [l for l in fd.readlines()
             if l.startswith('user')]
    assert len(l) == 1

    m = re.match(r'user\s+([0-9.]+)', l[0])
    return float(m.group(1))
