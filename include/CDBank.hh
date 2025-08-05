#ifndef CDBANK_HH
#define CDBANK_HH

// ROOT headers
#include "TObject.h"

// Standard headers
#include "iostream"

#include "CDHit.hh"


using namespace std;


class CDBank: public TObject
{
    public: 
        //! constructor
		CDBank();

		//! desctructor
		~CDBank();

		void    add_calohit(CDHit &_cdHit);

        CDHit 		get_calo_hit(int _cdHitNo);    					// get the number of calo hits per PTD entry (this may not be 1)
        int 		get_number_of_calo_hits();    					// get the number of calo hits per PTD entry (this may not be 1)

	private:
		int 	caloHitsNo = 0;

		std::vector<CDHit> cdHits; 
    
	ClassDef(CDBank,1);
};

#endif // CDBANK_HH