#include "CDBank.hh"


ClassImp(CDBank);


CDBank::CDBank()
{
}

CDBank::~CDBank()
{
}

void        CDBank::add_calohit(CDHit &_cdHit)
{
    cdHits.push_back(_cdHit);
}

CDHit 		CDBank::get_calo_hit(int _cdHitNo)
{
    return cdHits.at(_cdHitNo);
}  

int 		CDBank::get_number_of_calo_hits()
{
    return cdHits.size();
}    					