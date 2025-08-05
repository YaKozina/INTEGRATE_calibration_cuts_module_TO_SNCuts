#ifndef SNCUTS_H
#define SNCUTS_H

// Interface from Falaise
#include "bayeux/dpp/base_module.h"
#include "bayeux/mctools/simulated_data.h"
#include "bayeux/geomtools/manager.h"
#include "bayeux/geomtools/geom_id.h"

#include "falaise/snemo/processing/module.h"
#include "falaise/snemo/datamodels/particle_track_data.h"
#include "falaise/snemo/datamodels/particle_track.h"
#include "falaise/snemo/datamodels/vertex_utils.h"
#include "falaise/snemo/datamodels/tracker_clustering_solution.h"
#include "falaise/snemo/datamodels/tracker_trajectory_data.h"
#include "falaise/snemo/datamodels/tracker_trajectory_solution.h"
#include "falaise/snemo/datamodels/calibrated_data.h"
#include "falaise/snemo/datamodels/geomid_utils.h"
// #include "falaise/snemo/datamodels/vertex_utils.h"



#include "Event.hh"
#include "PTDParticle.hh"
#include "SDParticle.hh"
#include "Filters.hh"
#include "CDBank.hh"
#include "CDHit.hh"
#include "Constants.hh"



class SNCuts : public dpp::base_module
{
public:
    ////////////////////////////////////////////////
    // The following PUBLIC methods MUST be defined!
    // Default constructor
    SNCuts();

    // Default destructor
    virtual ~SNCuts();

    //! Configure the module
    virtual void initialize(
        const datatools::properties &myConfig,
        datatools::service_manager &flServices,
        dpp::module_handle_dict_type &what);

    //! Reset the module
    virtual void reset();

    // Process event
    virtual dpp::base_module::process_status process(datatools::things &workItem);
    // Everything else is optional for your usecase
    ////////////////////////////////////////////////

    Event get_event_data(datatools::things &workItem);

private:
    int                         eventNo;
    Event                       event;
    Filters*                     eventFilter;
    std::vector<std::string>    _filtersToBeUsed;                 // This string is filled from the config file and determines which filters are to be enabled


    // configurable data members
    bool _useEventHasTwoNegativeParticles_      = false; 
    bool _useEventHasTwoChargedParticles_       = false; 
    bool _useEventHasOneParticle_               = false; 
    bool _useEventHasParticles_                 = false; 
    bool _useEventHasTwoParticles_              = false; 
    bool _useEventHasTwoTracks_                 = false; 
    bool _useEventHasTwoFoilVertices_           = false; 
    bool _useEventHasTwoCaloHits_               = false; 
    bool _useEventHasOneCaloHit_                = false; 
    bool _useEventHasTwoAssociatedCaloHits_     = false; 
    bool _useEventHasTwoDistinctAssociatedCaloHits_     = false; 
    bool _useEventHasAssociatedCaloHits_        = false; 

    bool _useEventHasSumEnergyAbove_            = false;
    double _minSumEnergy_                       = -10000.0;           // default value, this will be changed at construction of Filters
    bool _useEventHasSumEnergyBelow_            = false;
    double _maxSumEnergy_                       = 1000000.0;           // default value, this will be changed at construction of Filters

    /* 
    SDDBDRC includes: 
      * _useEventHasTwoNegativeParticles_
      * _useEventHasTwoTracks_       
      * _useEventHasTwoFoilVertices_     
      * _useEventHasTwoCaloHits_     
      * _useEventHasTwoDistinctAssociatedCaloHits_ 
      * _useEventHasSumEnergyAbove_: requires setting _minSumEnergy_     
      * _useEventHasSumEnergyBelow_: requires setting _maxSumEnergy_ 
    */
    bool _useSDBDRC_                            = false;        


    bool _useEventHasFoilVertexDistanceBelow_   = false;
    double _maxFoilVertexDistance_              = 10000.0;       // default value, this will be changed at construction of Filters

    bool _useEventHasPintAbove_                 = false;
    double _minPint_                            = 1.0;           // default value, this will be changed at construction of Filters

    bool _useEventHasPextBelow_                 = false;
    double _maxPext_                            = 1.0;           // default value, this will be changed at construction of Filters

    bool _useEventHasNEscapedParticles_         = false;
    double _nEscapedParticles_                  = 0.0;           // default value, this will be changed at construction of Filters


//new
//***************************************************************
    bool use_calibration_source_cut_ = false;
    bool _useEventHasVertexCloseToCalibSource_ = false;
//******
    double _source_cut_ellipse_Y_;
    double _source_cut_ellipse_Z_;

//************************************************************


    DPP_MODULE_REGISTRATION_INTERFACE(SNCuts);
};

#endif // SNCUTS_H
