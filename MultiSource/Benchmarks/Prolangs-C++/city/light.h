// light.h

#ifndef _light_h
#define _light_h
#include "ostream.h"

#define LIGHT_ID 0

class light
{
private:
    void init(int, int, int, int);

protected:
    int current_state;
    int time_in_state[4];
    int time_remaining_in_current_state;
    virtual int next_state() {return ((current_state + 1 ) % 4);};

public:
    int __;
    light() {init(4,2,5,2);};
    light(int t1, int t2, int t3, int t4) {init(t1,t2,t3,t4);};

    void tick();
    redNS()	{return ((current_state == 0) || (current_state == 1));};
    yellowNS()	{return (current_state == 3);};
    greenNS()	{return (current_state == 2);};
    redEW()	{return ((current_state == 2) || (current_state == 3));};
    yellowEW()	{return (current_state == 1);};
    greenEW()	{return (current_state == 0);};
    friend ostream& operator<< (ostream &, light);
};
typedef light light_type;
#endif
