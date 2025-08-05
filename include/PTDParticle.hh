#ifndef PTDPARTICLE_HH
#define PTDPARTICLE_HH

// ROOT headers
#include "TObject.h"
#include "TVector3.h"

// Standard headers
#include "iostream"

using namespace std;


class PTDParticle: public TObject
{
    public: 
        //! constructor
		PTDParticle();

		//! desctructor
		~PTDParticle();

		void    set_charge(int _charge);
		void    set_associated_calo_hits_number(int _associatedCaloHitsNo);
		void    set_energy(double _energy);
		void    set_energy_sigma_MeV(double _energySigma);
		void    set_track_length(double _trackLength);
		void    set_time(double _time);
		void    set_time_sigma(double _timeSigma);
		void    set_foil_vertex_position(double _X, double _Y, double _Z);
		void    set_calo_vertex_position(double _X, double _Y, double _Z);
		bool 	has_foil_vertex();
		bool 	has_calo_vertex();

        int     	get_charge();
        int 		get_associated_calo_hits_number();    					// get the number of calo hits per PTD entry (this may not be 1)
        double 		get_energy();
        double 		get_energy_MeV();
        double 		get_energy_sigma_MeV();
		double 		get_track_length();
		double 		get_time();
		double 		get_time_sigma();
		
		TVector3    get_foil_vertex_position();
		TVector3    get_calo_vertex_position();

	private:
		int     charge;
		int 	associatedCaloHitsNo = 0;
		double  energy = -1.0;
		double  energySigma = -1.0;
		double  trackLength = -1.0;
		double  time = -1.0;
		double  timeSigma = -1.0;

		bool hasFoilVertex = false;
		bool hasCaloVertex = false;

		TVector3 foilVertexPosition;
		TVector3 caloVertexPosition;
    
    
	ClassDef(PTDParticle,1);
};

#endif // PTDPARTICLE_HH