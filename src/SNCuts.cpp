// Interface from Falaise
//*************************************************************
// Falaise
#include <falaise/snemo/services/service_handle.h>
#include <falaise/snemo/datamodels/particle_track_data.h>
#include <falaise/snemo/datamodels/precalibrated_data.h>
#include <falaise/snemo/datamodels/tracker_trajectory_data.h>
#include <falaise/snemo/datamodels/geomid_utils.h>
#include <falaise/snemo/datamodels/vertex_utils.h>

// Bayeux
#include <geomtools/geometry_service.h>
#include <datatools/clhep_units.h>

#include <falaise/snemo/services/geometry.h>

//***********************************************************

#include "SNCuts.hh"
#include "Event.hh"
#include "PTDParticle.hh"
#include "SDParticle.hh"
#include "Filters.hh"

DPP_MODULE_REGISTRATION_IMPLEMENT(SNCuts, "SNCuts")

SNCuts::SNCuts() : dpp::base_module()
{
    eventNo = 0;
    // std::cout << "constructed!" << std::endl;
}

SNCuts::~SNCuts()
{
    if (this->is_initialized())
    {
        this->reset();
    }
}

void SNCuts::initialize(
    const datatools::properties &myConfig,
    datatools::service_manager &flServices,
    dpp::module_handle_dict_type & /*moduleDict*/
)
{
    this->_set_initialized(true);
//*******************************************************************************************    
    geo_manager_ = snemo::service_handle<snemo::geometry_svc>{flServices};
    

calib_source_Y_.resize(calib_source_rows_, std::vector<double>(calib_source_columns_));
calib_source_Z_.resize(calib_source_rows_, std::vector<double>(calib_source_columns_));

if (myConfig.has_key("source_pos_path")) {
  source_pos_path_ = myConfig.fetch_string("source_pos_path");
} else {
  source_pos_path_ = "";
}

if (source_pos_path_.empty()) {

    std::cout << "[SNCuts]Falaise geometry service" << std::endl;

  const geomtools::id_mgr & mgr = geo_manager_->get_id_mgr();
  const geomtools::mapping & mapping = geo_manager_->get_mapping();

  for (int i = 0; i < calib_source_rows_; ++i) {
    for (int j = 0; j < calib_source_columns_; ++j) {
      geomtools::geom_id spot_id;
      mgr.make_id("source_calibration_spot", spot_id);
      mgr.set(spot_id, "module", 0);
      mgr.set(spot_id, "track", j);
      mgr.set(spot_id, "position", i);
      const geomtools::geom_info & info = mapping.get_geom_info(spot_id);
      const geomtools::placement & place = info.get_world_placement();
      const geomtools::vector_3d & pos = place.get_translation();
      calib_source_Y_[i][j] = pos.getY();
      calib_source_Z_[i][j] = pos.getZ();
    }
  }
} else {
  std::ifstream source_positions_file(source_pos_path_);
  if (source_positions_file.fail()) {
    throw std::logic_error(source_pos_path_ + " does not exist!");
  }

    std::cout << "[SNCuts] txt file data " << source_pos_path_ << std::endl;


  int i = 0;
  std::string line;

  while (getline(source_positions_file, line)) {
    calib_source_Y_[i / calib_source_columns_][i % calib_source_columns_] = std::stod(line.substr(0, line.find(";")));
    calib_source_Z_[i / calib_source_columns_][i % calib_source_columns_] = std::stod(line.substr(line.find(";") + 1));
    i++;
  }

  source_positions_file.close();
}

//********************************************************************************************    
    
    
    // std::cout << " -----------------------------" << std::endl;
    // std::cout << " Using the following filters: " << std::endl;
    try // myConfig.fetch(configKeyword, classVariable) looks for the config keyword
    {   // in the pipeline.conf file and sets the corresponding value of the classVariable
        myConfig.fetch("useEventHasTwoNegativeParticles", this->_useEventHasTwoNegativeParticles_);
        if (_useEventHasTwoNegativeParticles_) // if in the config file, the useCut is flagged true,
        {                                      // it will be added to the list of all filters to be used
            // std::cout << "EventHasTwoNegativeParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoNegativeParticles");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try 
    {   
        myConfig.fetch("useEventHasTwoChargedParticles", this->_useEventHasTwoChargedParticles_);
        if (_useEventHasTwoChargedParticles_) // if in the config file, the useCut is flagged true,
        {                                      // it will be added to the list of all filters to be used
            // std::cout << "EventHasTwoChargedParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoChargedParticles");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasTwoParticles", this->_useEventHasTwoParticles_);
        if (_useEventHasTwoParticles_)
        {
            // std::cout << "EventHasTwoParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoParticles");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasParticles", this->_useEventHasParticles_);
        if (_useEventHasParticles_)
        {
            // std::cout << "EventHasParticles" << std::endl;
            _filtersToBeUsed.push_back("useEventHasParticles");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasTwoTracks", this->_useEventHasTwoTracks_);
        if (_useEventHasTwoTracks_)
        {
            // std::cout << "EventHasTwoTracks" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoTracks");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasTwoFoilVertices", this->_useEventHasTwoFoilVertices_);
        if (_useEventHasTwoFoilVertices_)
        {
            // std::cout << "EventHasTwoFoilVertices" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoFoilVertices");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasTwoCaloHits", this->_useEventHasTwoCaloHits_);
        if (_useEventHasTwoCaloHits_)
        {
            // std::cout << "EventHasTwoCaloHits" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoCaloHits");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasOneCaloHit", this->_useEventHasOneCaloHit_);
        if (_useEventHasOneCaloHit_)
        {
            // std::cout << "EventHasOneCaloHit" << std::endl;
            _filtersToBeUsed.push_back("useEventHasOneCaloHit");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasTwoAssociatedCaloHits", this->_useEventHasTwoAssociatedCaloHits_);
        if (_useEventHasTwoAssociatedCaloHits_)
        {
            // std::cout << "EventHasTwoAssociatedCaloHits" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoAssociatedCaloHits");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasTwoDistinctAssociatedCaloHits", this->_useEventHasTwoDistinctAssociatedCaloHits_);
        if (_useEventHasTwoDistinctAssociatedCaloHits_)
        {
            // std::cout << "EventHasTwoDistinctAssociatedCaloHits" << std::endl;
            _filtersToBeUsed.push_back("useEventHasTwoDistinctAssociatedCaloHits");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasAssociatedCaloHits", this->_useEventHasAssociatedCaloHits_);
        if (_useEventHasAssociatedCaloHits_)
        {
            // std::cout << "EventHasAssociatedCaloHits" << std::endl;
            _filtersToBeUsed.push_back("useEventHasAssociatedCaloHits");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useSDBDRC", this->_useSDBDRC_);
        if (_useSDBDRC_)
        {
            // std::cout << "SDBDRC" << std::endl;
            _filtersToBeUsed.push_back("useSDBDRC");
        }
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasSumEnergyAbove", this->_useEventHasSumEnergyAbove_);
        if (_useEventHasSumEnergyAbove_)
        {
            _filtersToBeUsed.push_back("useEventHasSumEnergyAbove");
        }
        myConfig.fetch("minSumEnergy", this->_minSumEnergy_);
        // std::cout << "EventHasSumEnergyAbove " << _minSumEnergy_ << " keV" << std::endl;
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasSumEnergyBelow", this->_useEventHasSumEnergyBelow_);
        if (_useEventHasSumEnergyBelow_)
        {
            _filtersToBeUsed.push_back("useEventHasSumEnergyBelow");
        }
        myConfig.fetch("maxSumEnergy", this->_maxSumEnergy_);
        // std::cout << "EventHasSumEnergyBelow " << _maxSumEnergy_ << " keV" << std::endl;
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasFoilVertexDistanceBelow", this->_useEventHasFoilVertexDistanceBelow_);
        if (_useEventHasFoilVertexDistanceBelow_)
        {
            _filtersToBeUsed.push_back("useEventHasFoilVertexDistanceBelow");
        }
        myConfig.fetch("maxFoilVertexDistance", this->_maxFoilVertexDistance_);
        // std::cout << "EventHasFoilVertexDistanceBelow " << _maxFoilVertexDistance_ << " mm" << std::endl;
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasPintAbove", this->_useEventHasPintAbove_);
        if (_useEventHasPintAbove_)
        {
            _filtersToBeUsed.push_back("useEventHasPintAbove");
        }
        myConfig.fetch("minPint", this->_minPint_);
        // std::cout << "EventHasPintAbove " << _minPint_ << std::endl;
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasPextBelow", this->_useEventHasPextBelow_);
        if (_useEventHasPextBelow_)
        {
            _filtersToBeUsed.push_back("useEventHasPextBelow");
        }
        myConfig.fetch("maxPext", this->_maxPext_);
        // std::cout << "EventHasPextBelow " << _maxPext_ << std::endl;
    }
    catch (std::logic_error &e)
    {
    }

    try
    {
        myConfig.fetch("useEventHasNEscapedParticles", this->_useEventHasNEscapedParticles_); //_useEventHasNEscapedParticles_ is from SNCUTS.hh
        if (_useEventHasNEscapedParticles_)
        {
            _filtersToBeUsed.push_back("useEventHasNEscapedParticles"); //useEventHasNEscapedParticles is from FILTERS.hh & described in FILTERS.cpp 
        }
        myConfig.fetch("nEscapedParticles", this->_nEscapedParticles_);  //nEscapedParticles is from FILTERS.hh    _nEscapedParticles_ is from SNCUTS.hh
        // std::cout << "EventHasNEscapedParticles " << _nEscapedParticles_ << std::endl;
    }
    catch (std::logic_error &e)
    {
    }



// new filter 

//*******************************************************************

//iterate through all particles and find those coming from a calibration source (a) and hitting an OM (b)
//finding the vertex close to the calib source (a)

try
{
    myConfig.fetch("useEventHasVertexCloseToCalibSource", this->_useEventHasVertexCloseToCalibSource_);
    if (_useEventHasVertexCloseToCalibSource_)
    {
        _filtersToBeUsed.push_back("useEventHasVertexCloseToCalibSource");
    }

    myConfig.fetch("source_cut_ellipse_Y", this->_source_cut_ellipse_Y_);
    myConfig.fetch("source_cut_ellipse_Z", this->_source_cut_ellipse_Z_);
    //std::cout << "Using vertex calibration cut: ellipse Y = " << _source_cut_ellipse_Y_ << ", Z = " << _source_cut_ellipse_Z_ << std::endl;
}
catch (std::logic_error &e)
{
}

}

dpp::base_module::process_status SNCuts::process(datatools::things &workItem)
{
    eventFilter = new Filters(_filtersToBeUsed);  // construct Filters instance which holds the filters

//new 
//******************************************************
eventFilter->set_source_cut_ellipse_Y(_source_cut_ellipse_Y_);
eventFilter->set_source_cut_ellipse_Z(_source_cut_ellipse_Z_);

eventFilter->set_useEventHasVertexCloseToCalibSource(_useEventHasVertexCloseToCalibSource_);
eventFilter->set_calib_source_Y(calib_source_Y_);
eventFilter->set_calib_source_Z(calib_source_Z_);


//******************************************************

    eventFilter->set_min_sum_energy(_minSumEnergy_);                    // if not set in config file, value of -10000 is used.
    eventFilter->set_max_sum_energy(_maxSumEnergy_);                    // if not set in config file, value of 1000000 is used.
    eventFilter->set_max_foil_vertex_distance(_maxFoilVertexDistance_); // if not set in config file, value of 1000000 is used.
    eventFilter->set_min_Pint(_minPint_);                               // if not set in config file, value of 0 is used.
    eventFilter->set_max_Pext(_maxPext_);                               // if not set in config file, value of 0 is used.
    eventFilter->set_n_escaped_particles(_nEscapedParticles_);          // if not set in config file, value of 0 is used.

    //// Main method that fills event data from CD, PTD, etc.
    event = get_event_data(workItem);
    // event.print();

    //// If event passes all configured filters it is kept in the brio file, it is removed otherwise
    if (eventFilter->event_passed_filters(event))
    {
    
                             
         std::cout << "Event: " << eventNo << " ++PASSED++! " << std::endl;
         
         //check coordinates of the passed vertexes
         
         
         std::vector<PTDParticle> particles = event.get_particles();
        
        for (size_t i = 0; i < particles.size(); ++i)
{
    PTDParticle &p = particles[i];
    std::cout << "  Particle " << i << ":\n";

    if (p.has_foil_vertex())
    {
        TVector3 foilPos = p.get_foil_vertex_position();
        std::cout << "    Foil Vertex (X, Y, Z): "
                  << foilPos.X() << ", "
                  << foilPos.Y() << ", "
                  << foilPos.Z() << "\n";
    }

    if (p.has_calo_vertex())
    {
        TVector3 caloPos = p.get_calo_vertex_position();
        std::cout << "    Calo Vertex (X, Y, Z): "
                  << caloPos.X() << ", "
                  << caloPos.Y() << ", "
                  << caloPos.Z() << "\n";
    }
    
    if (p.has_calib_vertex()) {
    auto c = p.get_calib_vertex_position();
    std::cout << "    Calib Source Vertex (X, Y, Z): "
              << c.X() << ", " << c.Y() << ", " << c.Z() << "\n";
}
}

//*************************************************************************************************


        eventNo++;
        return falaise::processing::status::PROCESS_SUCCESS;
    }
    else if (!eventFilter->event_passed_filters(event))
    {
         std::cout << "Event: " << eventNo << " Failed! "  <<std::endl;
        eventNo++;
        return dpp::base_module::PROCESS_STOP;
    }
    else
    {
    // std::cout << "Event: " << eventNo << " Neither passed nor failed, wtf?! " << std::endl;
        eventNo++;
        return dpp::base_module::PROCESS_STOP;
    }
}

void SNCuts::reset()
{
    this->_set_initialized(false);
}

Event SNCuts::get_event_data(datatools::things &workItem)
{
    event.reset();
    event.set_event_number(eventNo);
    

    double totEne = 0.0;

    if (workItem.has("PTD"))
    {
        using namespace snemo::datamodel;

        snemo::datamodel::particle_track_data PTDbank = workItem.get<particle_track_data>("PTD");
        snemo::datamodel::ParticleHdlCollection PTDparticles = PTDbank.particles();

        for (auto &iParticle : PTDparticles)
        {
            PTDParticle *ptdparticle = new PTDParticle(); // explicitly creates instance of Particle class from this Cuts module, as there is a name clash with Bayeux

            const snemo::datamodel::particle_track &track = iParticle.get();
            if (particle_has_negative_charge(track))
            {
                ptdparticle->set_charge(-1);
            }
            else if (particle_has_neutral_charge(track))
            {
                ptdparticle->set_charge(0);
            }
            else if (particle_has_positive_charge(track))
            {
                ptdparticle->set_charge(1);
            }
            else if (particle_has_undefined_charge(track))
            {
                ptdparticle->set_charge(1000);
            }
            else
            {
                ptdparticle->set_charge(1001); // something fishy
            }

            if (track.has_vertices()) // check vertices
            {
                const std::vector<datatools::handle<snemo::datamodel::vertex>> &particle_vertices = track.get_vertices();

                for (
                    datatools::handle<vertex> iVertex : particle_vertices)
                {
                    snemo::datamodel::vertex vtx = iVertex.get(); // get the vertex

                    if (vtx.is_on_source_foil())
                    {
                        ptdparticle->set_foil_vertex_position(
                            vtx.get_spot().get_position().x(),
                            vtx.get_spot().get_position().y(),
                            vtx.get_spot().get_position().z());
                    }

                    else if (
                        vtx.is_on_main_calorimeter() ||
                        vtx.is_on_x_calorimeter() ||
                        vtx.is_on_gamma_veto())
                    {
                        ptdparticle->set_calo_vertex_position(
                            vtx.get_spot().get_position().x(),
                            vtx.get_spot().get_position().y(),
                            vtx.get_spot().get_position().z());
                    }
                    
                    //************************************************************************                
                else if (vtx.is_on_reference_source_plane()) {
            double ver_y = vtx.get_spot().get_position().y();
            double ver_z = vtx.get_spot().get_position().z();
            bool is_close = false;

            for (int i = 0; i < calib_source_rows_; ++i) {
                for (int j = 0; j < calib_source_columns_; ++j) {
                    double dy = ver_y - calib_source_Y_[i][j];
                    double dz = ver_z - calib_source_Z_[i][j];
                    double dist = (dy * dy) / (_source_cut_ellipse_Y_ * _source_cut_ellipse_Y_) + (dz * dz) / (_source_cut_ellipse_Z_ * _source_cut_ellipse_Z_);
                    if (dist < 1.0) {
                        is_close = true;
                        break;
                    }
                }
                if (is_close) break;
            }

            if (is_close) {
                ptdparticle->set_calib_vertex_position(
                    vtx.get_spot().get_position().x(),
                    vtx.get_spot().get_position().y(),
                    vtx.get_spot().get_position().z());
            }
        }
//************************************************************************   
                    
                    
   }            
}


            if (track.has_associated_calorimeter_hits())
            {

                int assCaloHitNo = 0;

                const std::vector<datatools::handle<snemo::datamodel::calibrated_calorimeter_hit>> &assCaloHits = track.get_associated_calorimeter_hits();
                for (
                    datatools::handle<snemo::datamodel::calibrated_calorimeter_hit> iCaloHit : track.get_associated_calorimeter_hits())
                {
                    snemo::datamodel::calibrated_calorimeter_hit cch = iCaloHit.get();

                    ptdparticle->set_energy(cch.get_energy() / CLHEP::keV);                 // energy in keV
                    ptdparticle->set_energy_sigma_MeV(cch.get_sigma_energy() / CLHEP::MeV); // energy sigma in MeV
                    ptdparticle->set_time(cch.get_time() / CLHEP::ns);                      // calohit time in ns
                    ptdparticle->set_time_sigma(cch.get_sigma_time() / CLHEP::ns);          // calohit time sigma in ns

                    // cout << "edep_bcu: " << cch.get_auxiliaries().fetch_real("edep_bcu") << endl;

                    totEne += cch.get_energy() / CLHEP::keV;
                    assCaloHitNo++;
                }

                ptdparticle->set_associated_calo_hits_number(assCaloHitNo);
            }

            if (track.has_trajectory())
            {
                const snemo::datamodel::tracker_trajectory &trajectory = track.get_trajectory();

                ptdparticle->set_track_length(trajectory.get_pattern().get_shape().get_length());

                if (TMath::Abs(trajectory.get_pattern().get_first().x()) <= trajectory.get_pattern().get_last().x())
                {
                    double mul = (trajectory.get_pattern().get_first_direction().x() * trajectory.get_pattern().get_first().x() > 0) ? 1.0 : -1.0;
                    geomtools::vector_3d direction = trajectory.get_pattern().get_first_direction() * mul;
                }
                else
                {
                    double mul = (trajectory.get_pattern().get_last_direction().x() * trajectory.get_pattern().get_last().x() > 0) ? 1.0 : -1.0;
                    geomtools::vector_3d direction = trajectory.get_pattern().get_last_direction() * mul;
                }
            }

            event.add_particle(*ptdparticle);
            delete ptdparticle;
        }
        event.set_event_total_energy(totEne);
    }
    else
    {
        // std::cout << "No PTD Bank!!!\n";
        event.set_event_total_energy(-1);
    }

    if (workItem.has("SD"))
    {
        using namespace snemo::datamodel;

        // Get the SD data
        mctools::simulated_data SD = workItem.get<mctools::simulated_data>("SD");
        // Save data about primary event into primev
        genbb::primary_event primary_event = SD.get_primary_event();
        // Get the list with particle data into prcoll
        list<genbb::primary_particle> primary_particle = primary_event.get_particles();

        std::vector<int> processedTrackIDs; 
        int currentTrackID;
        bool trackWasProcessed = false;
        for (auto &iPrimaryParticle : primary_particle)
        {
            SDParticle *sdparticle = new SDParticle();

            sdparticle->set_charge(iPrimaryParticle.get_charge());
            sdparticle->set_energy(iPrimaryParticle.get_kinetic_energy());


            bool hasEscapedFoil = false;

            if (SD.has_step_hits("__visu.tracks")) 
            {
                for (UInt_t ihit = 0; ihit < SD.get_number_of_step_hits("__visu.tracks"); ihit++) 
                {
                    auto stepHit = SD.get_step_hit("__visu.tracks", ihit); // Cache step hit
                    currentTrackID = stepHit.get_track_id();

                    // Check if this track ID has already been processed
                    if (std::find(processedTrackIDs.begin(), processedTrackIDs.end(), currentTrackID) == processedTrackIDs.end()) 
                    {
                        sdparticle->set_trackID(currentTrackID);
                        // Process new track ID
                        if (    
                                stepHit.get_parent_track_id() == 0    && // we only care about the initial particles
                                stepHit.has_material_name()   == true && 
                                stepHit.get_material_name()   == "tracking_gas"
                            ) 
                        {
                            hasEscapedFoil = true;
                            processedTrackIDs.push_back(currentTrackID); // Mark as processed
                            break; // Exit loop for this track ID
                        }
                    } 
                }
            }
            sdparticle->set_has_escaped_foil(hasEscapedFoil);
            event.add_sd_particle(*sdparticle);
            delete sdparticle;
        }
    }
    else
    {
        // std::cout << "No SD Bank!!!\n";
    }


    if (workItem.has("CD"))
    {
        using namespace snemo::datamodel;

        snemo::datamodel::calibrated_data falaiseCDbank = workItem.get<calibrated_data>("CD");

        CDBank *SNCCDBank = new CDBank(); // SNCuts CD bank

        const std::vector<datatools::handle<snemo::datamodel::calibrated_calorimeter_hit>> &caloHits = falaiseCDbank.calorimeter_hits();

        for (
            const datatools::handle<snemo::datamodel::calibrated_calorimeter_hit> &calohit : caloHits)
        {
            CDHit *cdhit = new CDHit();
            int om_id = om_num(calohit.get().get_geom_id());
            cdhit->set_energy(calohit.get().get_energy() / CLHEP::keV);
            cdhit->set_om_gid(om_id); 
            SNCCDBank->add_calohit(*cdhit);

            delete cdhit;
        }

        event.add_cd_bank(*SNCCDBank);

        delete SNCCDBank;
    }
    else
    {
        // std::cout << "No CD Bank!!!\n";
    }

    return event;
}

