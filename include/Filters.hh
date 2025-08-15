#ifndef FILTERS_HH
#define FILTERS_HH

// ROOT headers
#include "TObject.h"
#include "TMath.h"

#include "PTDParticle.hh"
#include "SDParticle.hh"
#include "Constants.hh"
#include "Event.hh"
#include "CDBank.hh"

// Standard headers
#include "iostream"
#include <vector>
#include <string>
#include <cmath>

// #include <functional>

using namespace std;

class Filters: public TObject
{
    public: 
        //! constructor
		Filters();  
		Filters(std::vector<std::string>& _filtersToBeUsed);  

		//! desctructor
		~Filters();

        void reset(); 							   // resets the values of the Filters

        bool event_has_two_negative_particles       (Event& _event);
        bool event_has_two_charged_particles        (Event& _event);
        bool event_has_two_particles                (Event& _event);
        bool event_has_particles                    (Event& _event);
        bool event_has_two_tracks                   (Event& _event);  //this is equivalend to event_has_two_particles
        bool event_has_two_foil_vertices            (Event& _event);
        bool event_has_two_calo_hits                (Event& _event);
        bool event_has_one_calo_hit                 (Event& _event);
        bool event_has_two_associated_calo_hits     (Event& _event);
        bool event_has_two_distinct_associated_calo_hits     (Event& _event);
        bool event_has_associated_calo_hits         (Event& _event);

        bool event_has_n_escaped_particles          (Event& _event);
        void set_n_escaped_particles                (int _nEscapeParticles);

        bool event_has_sum_energy_above             (Event& _event, double _minEnergy);
        bool event_has_sum_energy_below             (Event& _event, double _maxEnergy); 
        void set_min_sum_energy                     (double _minSumEnergy);
        void set_max_sum_energy                     (double _maxSumEnergy);

        bool event_has_foil_vertex_distance_below   (Event& _event, double _maxFoilVertexDistance); 
        void set_max_foil_vertex_distance           (double _maxFoilVertexDistance);

        bool event_has_Pint_above                   (Event& _event, double _minPint); 
        void set_min_Pint                           (double _minPint);

        bool event_has_Pext_below                   (Event& _event, double _maxPext);
        void set_max_Pext                           (double _maxPext);

        double get_min_sum_energy                   ();
        double get_max_sum_energy                   ();

        bool event_passed_filters                   (Event& _event);


//new
//*********************************************************************************
	void set_source_cut_ellipse_Y(double _cut_ellipse_Y);
	void set_source_cut_ellipse_Z(double _cut_ellipse_Z);

	void set_calib_source_Y(const std::vector<std::vector<double>>& Y);
	void set_calib_source_Z(const std::vector<std::vector<double>>& Z);
	
//*******************************************************************************************************

bool event_has_vertex_close_to_calib_source(Event& _event);
void set_useEventHasVertexCloseToCalibSource(bool value);

//********************************************************************************************************
bool event_has_kink_tracks(Event& _event);

void set_useEventRejectIfKinkTracks(bool use) 
{ 
useEventRejectIfKinkTracks_ = use; 
}
//********************************************************************************************************

//new 
//********************************************************************************************************
bool event_has_number_of_kinks(Event& _event);


 void set_useEventHasNumberOfKinks(bool value) 
 { 
 useEventHasNumberOfKinks_ = value; 
 }
 void set_kink_multiplicity_pattern(const std::vector<int> & pattern) 
 { 
 kinkMultiplicityPattern_ = pattern; 
 }

//********************************************************************************************************




    private:
        // std::vector<FilterFunction> filters;

        bool useEventHasTwoNegativeParticles    = false; 
        bool useEventHasTwoChargedParticles     = false; 
        bool useEventHasTwoParticles            = false; 
        bool useEventHasParticles               = false; 
        bool useEventHasTwoTracks               = false; 
        bool useEventHasTwoFoilVertices         = false; 
        bool useEventHasTwoCaloHits             = false; 
        bool useEventHasOneCaloHit              = false; 
        bool useEventHasTwoAssociatedCaloHits   = false; 
        bool useEventHasTwoDistinctAssociatedCaloHits   = false; 
        bool useEventHasAssociatedCaloHits   = false; 

        bool useSDBDRC                          = false; 

        bool useEventHasSumEnergyAbove          = false; 
        double minSumEnergy;

        bool useEventHasSumEnergyBelow          = false; 
        double maxSumEnergy;

        bool useEventHasFoilVertexDistanceBelow = false; 
        double maxFoilVertexDistance;

        bool useEventHasPintAbove = false; 
        double minPint;

        bool useEventHasPextBelow = false; 
        double maxPext;

        bool useEventHasNEscapedParticles = false;
        int nEscapedParticles;

//new for filter "vertex close to calibration source" (1/4 filters)
//*********************************************************************************************************
//1 event has at least 1 track which has vertes close to the calobration source 
 bool useEventHasVertexCloseToCalibSource = false;
//****************************************************************


//new for filter "kinked tracks inspection" (2/4)                
//*********************************************************************************************************
//1 event has at least 1 kinked track to be declined 
bool useEventRejectIfKinkTracks_ = false;
//****************************************************************

//new for filter "number of kinked tracks" (additional)                
//*********************************************************************************************************
bool useEventHasNumberOfKinks_ = false;        
std::vector<int> kinkMultiplicityPattern_;    
//*********************************************************************************************************


//calib source parameters for the filter "vertex close to calibration source" (1/4 filters)
double source_cut_ellipse_Y_ = 25.0;
double source_cut_ellipse_Z_ = 30.0;

std::vector<std::vector<double>> calib_source_Y_;
std::vector<std::vector<double>> calib_source_Z_;


//coordinates of the source

static const int calib_source_rows_ = 7;
static const int calib_source_columns_ = 6;



        double get_beta(double _E);
        double get_tTOF(double _l, double _beta);
        double get_sigmaTot(double _tTOF, double _tExpSigma, double _E, double _ESigma);
        double get_chi2_int(double _tExp[2], double _l[2], double _beta[2], double _sigmaTot[2]);
        double get_chi2_ext(double _tExp[2], double _l[2], double _beta[2], double _sigmaTot[2]);       

	ClassDef(Filters,1);
};

#endif // FILTERS_HH
