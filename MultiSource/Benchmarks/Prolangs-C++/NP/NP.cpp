// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//  Written by Hemant Pande, Rutgers University.  December 1994.  May be
//  distributed freely, provided this comment is displayed at the top.
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
class True {
public:
 True() {}
 virtual True *and (True *arg)
 {
   return arg;
 }
} true;

class False : public True {
public:
  False() {}
  True *and (True *arg);
} false;

True *False::and (True *arg)
{
   return &false;
}

True *v1, *nv1, *v2, *nv2, *v3, *nv3;
True *c;

main () {
   if (0) {v1 = &true; nv1 = &false;} else {v1 = &false; nv1= &true;}
   if (0) {v2 = &true; nv2 = &false;} else {v2 = &false; nv2 = &true;}
   if (0) {v3 = &true; nv3 = &false;} else {v3 = &false; nv3 = &true;}
   if (0) c = nv2; else if (0) c = v1; else c = v2;
   if (0) c = c->and(nv3); else if (0) c = c->and(nv2); else c = c->and(v1);
   if (0) c = c->and(v2); else if (0) c = c->and(nv1); else c = c->and(v3);
}
