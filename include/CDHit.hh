#ifndef CDHIT_HH
#define CDHIT_HH

// ROOT headers
#include "TObject.h"

// Standard headers
#include "iostream"


using namespace std;


class CDHit: public TObject
{
    public: 
        //! constructor
		CDHit();

		//! desctructor
		~CDHit();

		void    set_energy(double _energy);
		void    set_om_gid(int _om_gid);

        double 	get_energy();    
		int 	get_gid();					

	private:
		double energy = 0.0;
		int     om_gid= 0;

    
	ClassDef(CDHit,1);
};

#endif // CDHIT_HH