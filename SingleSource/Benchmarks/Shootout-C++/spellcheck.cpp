// -*- mode: c++ -*-
// $Id$
// http://www.bagley.org/~doug/shootout/
// STL spell checker from Bill Lear

#include <iostream>
#include <utility>
#include <fstream>
#include <hash_map.h>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef std::pair<const char*, const char*> span;

namespace std {
    template <> struct hash<span>;
    template <> struct equal_to<span>;
}

template<> struct hash<span> {
    inline size_t operator()(const span& s) const {
        size_t h = 0;
        const char* end = s.second;
        for (const char* begin = s.first; begin != end; ++begin) {
            h = 5 * h + *begin;
        }
        return h;
    }
};

template<> struct equal_to<span> {
    inline bool operator()(const span& s1, const span& s2) const {
        return (s1.second - s1.first) == (s2.second - s2.first) &&
            std::equal(s1.first, s1.second, s2.first);
    }
};

class spell_checker {
public:
    spell_checker() {
        std::ifstream in("Usr.Dict.Words");
        char line[32];
        while (in.getline(line, 32)) {
            const char* begin = line;
            const char* end = line + in.gcount() - 1;
            if (dict.end() == dict.find(span(begin, end))) {
                const size_t len = end - begin;
                char* word = new char[len];
                copy(begin, end, word);
                ++dict[span(word, word + len)];
            }
         }
    }

    void process(std::istream& in) {
        char line[32];
        while (in.getline(line, 32)) {
            if (dict.end() == dict.find(span(line, line + in.gcount() - 1))) {
                cout << line << '\n';
            }
        }
    }

private:
    std::hash_map<span, int> dict;
};

int main() {
    spell_checker spell;
    char buff[4096];
    cin.rdbuf()->pubsetbuf(buff, 4096); // enable buffering
    spell.process(cin);
}
