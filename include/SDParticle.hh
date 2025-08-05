#ifndef SDPARTICLE_HH
#define SDPARTICLE_HH

// ROOT headers
#include "TObject.h"
#include "TVector3.h"

// Standard headers
#include "iostream"

using namespace std;


class SDParticle: public TObject
{
    public: 
        //! constructor
		SDParticle();

		//! desctructor
		~SDParticle();

		void    set_charge(int _charge);
		void    set_trackID(int _trackID);
		void    set_energy(double _energy);
		void    set_foil_vertex_position(double _X, double _Y, double _Z);
		void 	set_has_escaped_foil(bool _escaped);

        int     	get_charge();
        int     	get_trackID();
        double 		get_energy();
        double 		get_energy_MeV();
		bool 	    has_foil_vertex();
		bool 		has_escaped_foil();
		
		TVector3    get_foil_vertex_position();

	private:
		int     charge;
		int 	trackID;
		double  energy = -1.0;

		bool hasFoilVertex = false;
		bool hasEscapedFoil = false;

		TVector3 foilVertexPosition;
    
    
	ClassDef(SDParticle,1);
};

#endif // SDPARTICLE_HH