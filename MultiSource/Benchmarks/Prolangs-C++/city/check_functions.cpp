// check-functions.cc

#include "direction.h"
#include "roadlet.h"
#include "vehicle.h"
#include "stream.h"


// roadlet r is the the 'd' of v->location()


roadlet * return_null(roadlet * r, vehicle *v, direction)
{
    return(NULL);
}


roadlet * is_empty(roadlet *r, vehicle *v, direction d)
{
    if (!r->occupied())
	return(r);
    else
	return(NULL);
}


//check both left and right.  This makes sense for roads of two or fewer lanes.
roadlet * lane_switch_ok(roadlet *r, vehicle *v, direction d)
{
    direction dir = v->direction();
    //cout << "dir = " << dir << "\n";
    cout << "lane switch for " << *v << " at " << *r <<'\n';

    if (r->occupied())
	return(NULL);

    /*if ((r->neighbor(dir.right()) != NULL) && 
	(r->neighbor(dir.right())->occupied()))
	return(NULL);

    if ((r->neighbor(dir.left()) != NULL) && 
	(r->neighbor(dir.left())->occupied()))
	return(NULL);
don;t check right or left */

    if ((r->neighbor(dir.back()) != NULL) && 
	(r->neighbor(dir.back())->occupied()))
	return(NULL);

cout << "lane switch said true \n";
    return(r);
}


//f from notes
roadlet * strait (roadlet *r, vehicle *v, direction d)
{
    if (!r->occupied() && (v->direction() == d))
	return(r);
    else
	return(NULL);


}


// h from notes
roadlet * strait_or_left (roadlet *r, vehicle *v, direction d)
{
    if (!r->occupied() && 
          ((v->direction() == d) || (v->direction().left() == d)))
	return(r);
    else
	return(NULL);
}


//g from notes
roadlet * strait_or_right (roadlet *r, vehicle *v, direction d)
{
    if (!r->occupied() && 
          ((v->direction() == d) || (v->direction().right() == d)))
	return(r);
    else
	return(NULL);
}

roadlet * green_light(intersection_roadlet* r, vehicle* v, direction d)
{
    if ((d == N) || (d == S))
    {
	if (!r->occupied() && (r->light()->greenNS()))
	    return(r);
        else
	    return(NULL);
    }
    else
    {
	if (!r->occupied() && (r->light()->greenEW()))
	    return(r);
        else
	    return(NULL);
    }
}

roadlet * green_OR_plan_rightONred(intersection_roadlet* r, vehicle* v, direction d)
{
    int right_on_red ;
    int green_light;

    cout << "green or right on red\n";

    //if (r->light()->yellow() )
	// stop car;

    if ((d == N) || (d == S))
    {
        right_on_red = (r->light()->redNS()) ; // && no on coming traffic 
	green_light = r->light()->greenNS();
    }
    else
    {
        right_on_red = (r->light()->redEW()) ; // && no on coming traffic 
	green_light = r->light()->greenEW();
    }
       

    if (right_on_red)      //verify that there is a road to the right
    {
        if (r->neighbor(d.right()) == NULL)
	{
	    right_on_red = FALSE;
	}
	else
        {
           v->plan = d.right().as_int();
           cout << "plan for " << *v << " is " << direction(v->plan) << "\n";
        }
    }

    if (green_light) cout << "green!\n";
    if (right_on_red) cout << "right on red\n";
    if (!r->occupied() && (right_on_red || green_light))
    {
	return(r);
    }
    else
	return(NULL);
}
