#include "CDHit.hh"


ClassImp(CDHit);


CDHit::CDHit()
{
}

CDHit::~CDHit()
{
}

void    CDHit::set_energy(double _energy)
{
    energy = _energy;
}

double 	CDHit::get_energy()
{
    return energy;
}    

void    CDHit::set_om_gid(int _om_gid)
{
    om_gid = _om_gid;
}
int     CDHit::get_gid()
{
    return om_gid;
}					
