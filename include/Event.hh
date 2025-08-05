#ifndef EVENT_HH
#define EVENT_HH

// ROOT headers
#include "TObject.h"

#include "PTDParticle.hh"
#include "SDParticle.hh"
#include "Constants.hh"
#include "CDBank.hh"
#include "Constants.hh"


// Standard headers
#include "iostream"


using namespace std;

class Event: public TObject
{
    public: 
        //! constructor
		Event();

		//! desctructor
		~Event();

		void set_event_number(int _eventNumber);
		void set_event_total_energy(double _eventTotalEnergy);
		void set_event_foil_vertex_distance(double _eventFoilVertexDistance);

		void add_particle(PTDParticle &_newPTDParticle); // add a PTDparticle into the event
		void add_sd_particle(SDParticle &_newSDParticle); // add an SDparticle into the event
		void add_cd_bank(CDBank &_cdBank);		   // add CD bank into the event

		void reset(); 							   // resets the values of the Event
		void print();	

		std::vector<PTDParticle> get_particles();     
		std::vector<SDParticle> get_sd_particles();     
		CDBank 	get_cd_bank();     

		int 	get_event_number(); 
		double 	get_event_total_energy();


	private:
		int 	eventNumber;
		double 	eventTotalEnergy; 

		std::vector<PTDParticle> ptdparticles; 			// Info from PTD bank
		std::vector<SDParticle> sdparticles; 			// Info from SD bank
		CDBank cdBank;
    
    
	ClassDef(Event,1);
};

#endif // EVENT_HH