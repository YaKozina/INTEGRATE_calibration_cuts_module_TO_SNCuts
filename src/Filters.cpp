#include "Filters.hh"


ClassImp(Filters);

Filters::Filters() 
{
}

Filters::Filters(std::vector<std::string>& _filtersToBeUsed) 
{
    for( auto& filter : _filtersToBeUsed)
    {
        if (filter == "useEventHasTwoNegativeParticles")
        {
            useEventHasTwoNegativeParticles = true;
        }

        if (filter == "useEventHasTwoChargedParticles")
        {
            useEventHasTwoChargedParticles = true;
        }

        if (filter == "useEventHasTwoParticles")
        {
            useEventHasTwoParticles = true;
        }
        if (filter == "useEventHasParticles")
        {
            useEventHasParticles = true;
        }
        if (filter == "useEventHasTwoTracks")
        {
            useEventHasTwoTracks = true;
        }
        if (filter == "useEventHasTwoFoilVertices")
        {
            useEventHasTwoFoilVertices = true;
        }
        if (filter == "useEventHasTwoCaloHits")
        {
            useEventHasTwoCaloHits = true;
        }
        if (filter == "useEventHasOneCaloHit")
        {
            useEventHasOneCaloHit = true;
        }
        if (filter == "useEventHasTwoAssociatedCaloHits")
        {
            useEventHasTwoAssociatedCaloHits = true;
        }
        if (filter == "useEventHasTwoDistinctAssociatedCaloHits")
        {
            useEventHasTwoDistinctAssociatedCaloHits = true;
        }
        if (filter == "useEventHasAssociatedCaloHits")
        {
            useEventHasAssociatedCaloHits = true;
        }
        if (filter == "useSDBDRC")
        {
            useEventHasTwoNegativeParticles = true;
            useEventHasTwoTracks            = true;
            useEventHasTwoFoilVertices      = true;
            useEventHasTwoCaloHits          = true;
            useEventHasTwoDistinctAssociatedCaloHits= true;
            useEventHasSumEnergyAbove       = true;
            useEventHasSumEnergyBelow       = true;
        }
        if (filter == "useEventHasSumEnergyAbove")
        {
            useEventHasSumEnergyAbove = true;
        }
        if (filter == "useEventHasSumEnergyBelow")
        {
            useEventHasSumEnergyBelow = true;
        }
        if (filter == "useEventHasFoilVertexDistanceBelow")
        {
            useEventHasFoilVertexDistanceBelow = true;
        }
        if (filter == "useEventHasPintAbove")
        {
            useEventHasPintAbove = true;
        }
        if (filter == "useEventHasPextBelow")
        {
            useEventHasPextBelow = true;
        }
        if (filter == "useEventHasNEscapedParticles")
        {
            useEventHasNEscapedParticles = true;
        }
//*****************************************************************        
        if (filter == "isThereKinkTrack") 
        {
    	    useEventRejectIfKinkTracks_ = true;
	}
//****************************************************************    
	if (filter == "hasNumberofKinks") 
	{
    	    useEventHasNumberOfKinks_ = true;
	}
//****************************************************************
	if (filter == "useEventTrackHasOneAssocCaloHit")
	{
    	    useEventTrackHasOneAssocCaloHit_ = true;
	}
//****************************************************************
	if (filter == "useEventTrackHasCaloChargeAbove") 
	{
	    useEventTrackHasCaloChargeAbove_ = true;
	}

//****************************************************************
    }
}

Filters::~Filters()
{
    useEventHasTwoNegativeParticles    = false; 
    useEventHasTwoChargedParticles     = false; 
    useEventHasTwoParticles            = false; 
    useEventHasParticles               = false; 
    useEventHasTwoTracks               = false; 
    useEventHasTwoFoilVertices         = false; 
    useEventHasTwoCaloHits             = false; 
    useEventHasOneCaloHit              = false; 
    useEventHasTwoAssociatedCaloHits   = false; 
    useEventHasTwoDistinctAssociatedCaloHits   = false; 
    useEventHasAssociatedCaloHits      = false; 

    useEventHasSumEnergyAbove          = false; 
    minSumEnergy                       = -10000.0;

    useEventHasSumEnergyBelow          = false; 
    maxSumEnergy                       = 100000.0;

    useEventHasFoilVertexDistanceBelow = false; 
    maxFoilVertexDistance              = 100000.0;

    useEventHasPintAbove               = false;
    minPint                            = 1.0;

    useEventHasPextBelow               = false;
    maxPext                            = 0.0;

    useEventHasNEscapedParticles       = false;
    nEscapedParticles                  = -1.0;

}

void Filters::reset()
{
     
}


bool Filters::event_has_two_negative_particles(Event& _event)
{
    if (_event.get_particles().size() != 2)
    {
        return false;
    }

    for (auto& particle : _event.get_particles())
    {
        if( particle.get_charge() != -1)
        {
            return false;
        }
    }
    return true;
}

bool Filters::event_has_two_charged_particles(Event& _event)
{
    if (_event.get_particles().size() != 2)
    {
        return false;
    }

    for (auto& particle : _event.get_particles())
    {
        if( particle.get_charge() == 0)
        {
            return false;
        }
    }
    return true;
}

bool Filters::event_has_particles(Event& _event)
{
    if ( _event.get_particles().size() > 0 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_particles(Event& _event)
{
    if (_event.get_particles().size() == 2)
    {
        return true;
    }

    return false;
}

bool Filters::event_has_sum_energy_above(Event& _event, double _minSumEnergy)
{
    if( _event.get_event_total_energy() >  _minSumEnergy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Filters::event_has_sum_energy_below(Event& _event, double _maxSumEnergy)
{
    if( _event.get_event_total_energy() <  _maxSumEnergy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Filters::event_has_two_tracks(Event& _event)
{
    return event_has_two_particles(_event);
}

bool Filters::event_has_two_foil_vertices(Event& _event)
{
    int numberFoilVertices = 0;
    for (auto& particle : _event.get_particles())
    {
        if( particle.has_foil_vertex() )
        {
            numberFoilVertices++;
        }
    }
    if ( numberFoilVertices == 2 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_calo_hits(Event& _event)
{
    if( _event.get_cd_bank().get_number_of_calo_hits() == 2 )
    {
        return true;
    }
    return false; 
}

bool Filters::event_has_one_calo_hit(Event& _event)
{
    if( _event.get_cd_bank().get_number_of_calo_hits() == 1 )
    {
        return true;
    }
    return false;
}

bool Filters::event_has_two_associated_calo_hits(Event& _event)
{
    if ( event_has_two_particles(_event) )
    {
        for (auto& particle : _event.get_particles())
        {
            if ( particle.get_associated_calo_hits_number() != 1 )  // if there are multiple calohits associated with single PTD entry: fail
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Filters::event_has_two_distinct_associated_calo_hits(Event& _event)
{
    if ( event_has_two_particles(_event) )
    {
        for (auto& particle : _event.get_particles())
        {
            if ( particle.get_associated_calo_hits_number() != 1 )  // if there are multiple calohits associated with single PTD entry: fail
            {
                return false;
            }
        }
        if( _event.get_cd_bank().get_number_of_calo_hits() == 2 )
        {
            if (_event.get_cd_bank().get_calo_hit(0).get_gid() == _event.get_cd_bank().get_calo_hit(1).get_gid())
            {
                return false;
            }
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool Filters::event_has_associated_calo_hits(Event& _event)
{
    if ( event_has_particles(_event) )
    {
        for (auto& particle : _event.get_particles())
        {
            if ( particle.get_associated_calo_hits_number() != 1 )  // if there are multiple calohits associated with single PTD entry: fail
            {
                return false;
            }
        }
        if( _event.get_cd_bank().get_number_of_calo_hits() > 0 )
        {
            return true;
        }
        return (_event.get_cd_bank().get_number_of_calo_hits() > 0);
    }
    else
    {
        return false;
    }
}


void Filters::set_min_sum_energy(double _minSumEnergy)
{
    minSumEnergy = _minSumEnergy;
}

void Filters::set_max_sum_energy(double _maxSumEnergy)
{
    maxSumEnergy = _maxSumEnergy;
}

double Filters::get_min_sum_energy()
{
    return minSumEnergy;
}
double Filters::get_max_sum_energy()
{
    return maxSumEnergy;
}

void Filters::set_max_foil_vertex_distance(double _maxFoilVertexDistance)
{
    maxFoilVertexDistance = _maxFoilVertexDistance;
}

//new
//*******************************************************************************************

void Filters::set_useEventHasVertexCloseToCalibSource(bool _useEventHasVertexCloseToCalibSource)
{
    useEventHasVertexCloseToCalibSource = _useEventHasVertexCloseToCalibSource;
}

void Filters::set_source_cut_ellipse_Y(double _cut_ellipse_Y) {
    source_cut_ellipse_Y_ = _cut_ellipse_Y;
}

void Filters::set_source_cut_ellipse_Z(double _cut_ellipse_Z) {
    source_cut_ellipse_Z_ = _cut_ellipse_Z;
}
//*******************************************************************************************

void Filters::set_useEventTrackHasOneAssocCaloHit(bool value)
{
    useEventTrackHasOneAssocCaloHit_ = value;
}

//*******************************************************************************************
void Filters::set_useEventTrackHasCaloChargeAbove(bool value) 
{ 
useEventTrackHasCaloChargeAbove_ = value; 
}

void Filters::set_calo_charge_min_nVs(double v)
{ 
caloChargeMin_nVs_ = v; 
}


//*******************************************************************************************
bool Filters::event_has_foil_vertex_distance_below(Event& _event, double _maxFoilVertexDistance) // is it better if vertex distance is calculated here, or is part of Event?
{
    double foilVertexDistance = 1000000.0;
    if( event_has_two_foil_vertices(_event) && event_has_two_tracks(_event))  // Calculate foil vertex distance only if there are 2 foil vertices!
    {
        double dy = _event.get_particles().at(0).get_foil_vertex_position().Y() - _event.get_particles().at(1).get_foil_vertex_position().Y(); 
        double dz = _event.get_particles().at(0).get_foil_vertex_position().Z() - _event.get_particles().at(1).get_foil_vertex_position().Z();

        foilVertexDistance =  sqrt(  // I'm omitting X-component since this doesn't really make sense to use
                pow( dy , 2) + 
                pow( dz , 2) 
            );
    }

    if( foilVertexDistance < _maxFoilVertexDistance )
    {
        return true;
    }

    return false;
}


//new 
//********************************************************************************************************
bool Filters::event_has_vertex_close_to_calib_source(Event& _event)
{
    for (auto& particle : _event.get_particles())
    {
        if (!particle.has_calib_vertex()) continue;

        double ver_y = particle.get_calib_vertex_position().Y();
        double ver_z = particle.get_calib_vertex_position().Z();

        for (int i = 0; i < calib_source_rows_; ++i)
        {
            for (int j = 0; j < calib_source_columns_; ++j)
            {
                double dy = ver_y - calib_source_Y_[i][j];
                double dz = ver_z - calib_source_Z_[i][j];

                double dist = (dy * dy) / (source_cut_ellipse_Y_ * source_cut_ellipse_Y_) +
                              (dz * dz) / (source_cut_ellipse_Z_ * source_cut_ellipse_Z_);

                if (dist < 1.0) return true;
            }
        }
    }
    return false;
}


//******************************************************************************************************

bool Filters::event_has_kink_tracks(Event& _event)
{
    for (auto& particle : _event.get_particles()) 
    {
        if (particle.has_kink_in_trajectory())
        {
         return true;
         }
    }
    return false;
}
//******************************************************************************************************
bool Filters::event_has_number_of_kinks(Event& _event)
{
  if (kinkMultiplicityPattern_.empty())
  { 
  return false;
  }

  std::vector<int> counts(kinkMultiplicityPattern_.size(), 0);
  int extraHigher = 0;

    for (auto& particle : _event.get_particles()) {

    if (particle.get_track_length() < 0) continue;

    int kinkCount = particle.get_kink_count_in_trajectory();
    if (kinkCount < 0) kinkCount = 0; 

    if (kinkCount < static_cast<int>(counts.size())) {
      counts[kinkCount]++;
    } else {

      extraHigher++;
    }
  }

  for (size_t i = 0; i < counts.size(); ++i) 
  {
    if (counts[i] != kinkMultiplicityPattern_[i]) 
    {
    return false;
    }
  }
  if (extraHigher > 0) 
  {
  return false;
  }
  return true;
}

//******************************************************************************************************

bool Filters::event_track_has_one_assoc_calo_hit(Event& _event)
{
    for (auto& particle : _event.get_particles()) 
    {
        if (particle.get_associated_calo_hits_number() == 1 && particle.has_main_or_x_calo_vertex())
        {
            return true; 
        }
    }
    return false;
}
//******************************************************************************************************

bool Filters::event_track_has_calo_charge_above(Event& _event)
{
    for (auto& particle : _event.get_particles()) 
      {
    if (particle.get_associated_calo_hits_number() == 1 && particle.has_main_or_x_calo_vertex())
    {
      if (particle.get_calo_charge_nVs() >= caloChargeMin_nVs_) return true;
    }
  }
  return false;
}

//******************************************************************************************************
bool Filters::event_has_Pint_above    (Event& _event, double _minPint)
{
    if ( _event.get_particles().size() != 2.0 )
    {
        return false;
    }
    
        double E[2];           // storage for particle energies [MeV]
    double ESigma[2];      // storage for particle energy sigmas [MeV]    
    double l[2];           // storage for particle track lengths [mm]
    double tExp[2];        // storage for particles calo hit times (experimental) [ns]
    double tExpSigma[2];   // storage for particles calo hit time sigmas [ns]

    double beta[2]; // get_beta()
    double tTOF[2]; // get_tTOF()
    double sigmaTot[2]; // get_sigmaTot()

    int i = 0;
    for ( auto& particle : _event.get_particles() )
    {
        E[i]            = particle.get_energy_MeV();
        ESigma[i]       = particle.get_energy_sigma_MeV();
        l[i]            = particle.get_track_length();
        tExp[i]         = particle.get_time();
        tExpSigma[i]    = particle.get_time_sigma();

        beta[i]         = get_beta(E[i]);             // sqrt(_E * (_E + 2 * m_e)) / (_E + m_e)
        tTOF[i]         = get_tTOF(l[i], beta[i]);    // _l / (_beta * Constants::LIGHT_SPEED)
        sigmaTot[i]     = get_sigmaTot(tTOF[i], tExpSigma[i], E[i], ESigma[i]);

        i++;
    }

    double chi2 = get_chi2_int(tExp, l, beta, sigmaTot) ; // ( (tExp2 - l2/(beta2 * c )) - (tExp1 - l1/(beta1 * c )) )^2 / ( sigmaTot1 + sigmaTot2 )
    double Pint = TMath::Prob(chi2, 1); // returns 1 - P(a,x)

    if ( Pint >  _minPint)
    {
        return true;
    }
    return false;
 
}

void Filters::set_min_Pint(double _minPint)
{
    minPint = _minPint;
}

bool Filters::event_has_Pext_below    (Event& _event, double _maxPext)
{
    if ( _event.get_particles().size() != 2.0 )
    {
        return false;
    }


    double E[2];           // storage for particle energies [MeV]
    double ESigma[2];      // storage for particle energy sigmas [MeV]    
    double l[2];           // storage for particle track lengths [mm]
    double tExp[2];        // storage for particles calo hit times (experimental) [ns]
    double tExpSigma[2];   // storage for particles calo hit time sigmas [ns]

    double beta[2]; // get_beta()
    double tTOF[2]; // get_tTOF()
    double sigmaTot[2]; // get_sigmaTot()

    int i = 0;
    for ( auto& particle : _event.get_particles() )
    {
        E[i]            = particle.get_energy_MeV();
        ESigma[i]       = particle.get_energy_sigma_MeV();
        l[i]            = particle.get_track_length();
        tExp[i]         = particle.get_time();
        tExpSigma[i]    = particle.get_time_sigma();

        beta[i]         = get_beta(E[i]);             // sqrt(_E * (_E + 2 * m_e)) / (_E + m_e)
        tTOF[i]         = get_tTOF(l[i], beta[i]);    // _l / (_beta * Constants::LIGHT_SPEED)
        sigmaTot[i]     = get_sigmaTot(tTOF[i], tExpSigma[i], E[i], ESigma[i]);

        i++;
    }

    double chi2 = get_chi2_ext(tExp, l, beta, sigmaTot) ; // ( (tExp2 - l2/(beta2 * c )) - (tExp1 - l1/(beta1 * c )) )^2 / ( sigmaTot1 + sigmaTot2 )
    double Pext = TMath::Prob(chi2, 1); // returns 1 - P(a,x)

    if ( Pext <  _maxPext)
    {
        return true;
    }
    
    return false;
} 

void Filters::set_max_Pext(double _maxPext)
{
    maxPext = _maxPext;
}

bool Filters::event_has_n_escaped_particles(Event& _event)
{
    int eventNEscaped = 0;
    for(int i = 0; i < _event.get_sd_particles().size(); i++ )
    {
        if(_event.get_sd_particles().at(i).has_escaped_foil() == true)
        {
            eventNEscaped++; 
        }
    }
    if( eventNEscaped == nEscapedParticles)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Filters::set_n_escaped_particles(int _nEscapedParticles)
{
    nEscapedParticles = _nEscapedParticles;
}


//***************************************************************************

void Filters::set_calib_source_Y(const std::vector<std::vector<double>>& Y) {
    calib_source_Y_ = Y;
}

void Filters::set_calib_source_Z(const std::vector<std::vector<double>>& Z) {
    calib_source_Z_ = Z;
}

//***************************************************************************





bool Filters::event_passed_filters(Event& _event) {
    if ( useEventHasTwoNegativeParticles && !event_has_two_negative_particles(_event) )         // event doesn't pass filter if filter should be used AND is not fulilled!
    {
        return false;
    }
    if ( useEventHasTwoChargedParticles && !event_has_two_charged_particles(_event) )         // event doesn't pass filter if filter should be used AND is not fulilled!
    {
        return false;
    }
    if ( useEventHasTwoParticles && !event_has_two_particles(_event) )
    {
        return false;
    }
    if ( useEventHasParticles && !event_has_particles(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoTracks && !event_has_two_tracks(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoFoilVertices && !event_has_two_foil_vertices(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoCaloHits && !event_has_two_calo_hits(_event) ) 
    {
        return false;
    }
    if ( useEventHasOneCaloHit && !event_has_one_calo_hit(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoAssociatedCaloHits && !event_has_two_associated_calo_hits(_event) ) 
    {
        return false;
    }
    if ( useEventHasTwoDistinctAssociatedCaloHits && !event_has_two_distinct_associated_calo_hits(_event) ) 
    {
        return false;
    }
    if ( useEventHasAssociatedCaloHits && !event_has_associated_calo_hits(_event) ) 
    {
        return false;
    }
    if ( useEventHasSumEnergyAbove && !event_has_sum_energy_above(_event, minSumEnergy) )       
    {
        return false;
    }
    if ( useEventHasSumEnergyBelow && !event_has_sum_energy_below(_event, maxSumEnergy) )       
    {
        return false;
    }
    if ( useEventHasFoilVertexDistanceBelow && !event_has_foil_vertex_distance_below(_event, maxFoilVertexDistance) )       
    {
        return false;
    }
    if ( useEventHasPintAbove && !event_has_Pint_above(_event, minPint) )       
    {
        return false;
    }
    if ( useEventHasPextBelow && !event_has_Pext_below(_event, maxPext) )       
    {
        return false;
    }
    if ( useEventHasNEscapedParticles && !event_has_n_escaped_particles(_event) )
    {
        return false;
    }
    
    
//new     
//*********************************************************    
    if (useEventHasVertexCloseToCalibSource && !event_has_vertex_close_to_calib_source(_event)) 
    {
    return false;
    }    
//*********************************************************

//new     
//*********************************************************    
    if (useEventRejectIfKinkTracks_ && event_has_kink_tracks(_event)) 
    {
    return false; 
    }
//*********************************************************

//new     
//*********************************************************    
    if (useEventHasNumberOfKinks_) 
    {
         if (!event_has_number_of_kinks(_event)) 
         {
         return false;
         }
    }
//*********************************************************
    if (useEventTrackHasOneAssocCaloHit_ && !event_track_has_one_assoc_calo_hit(_event))
    {
    return false;
    }
//*********************************************************
    if (useEventTrackHasCaloChargeAbove_ && !event_track_has_calo_charge_above(_event))   
    {
    return false;
    }
//*********************************************************    
    return true;
}

double Filters::get_beta(double _E)
{
    return TMath::Sqrt(_E * (_E + 2 * Constants::ELECTRON_MASS_MEV)) / (_E + Constants::ELECTRON_MASS_MEV);
}

double Filters::get_tTOF(double _l, double _beta)
{
    return _l/(_beta * Constants::LIGHT_SPEED);
}

double Filters::get_sigmaTot(double _tTOF, double _tExpSigma, double _E, double _ESigma)
{
    double m            = Constants::ELECTRON_MASS_MEV;

    double tExpSigma2   = _tExpSigma * _tExpSigma;

    double dfdb         = pow(_tTOF * _tTOF * m * m, 2) / 
                          pow(_E * (_E + m) * (_E + 2 * m), 2);  // this factor equals to (d(tTOF)/d(beta))^2 from propagating uncertainties of tTOF

    double ESigma2      = _ESigma * _ESigma;

    return tExpSigma2 + dfdb * ESigma2;
}

double Filters::get_chi2_int(double _tExp[2], double _l[2], double _beta[2], double _sigmaTot[2]) 
{
    double c            = Constants::LIGHT_SPEED;
    double numerator    = pow((_tExp[1] - _l[1] / (_beta[1] * c)) - (_tExp[0] - _l[0] / (_beta[0] * c)), 2);
    double denominator  = _sigmaTot[0] + _sigmaTot[1];

    return numerator / denominator;
}

double Filters::get_chi2_ext(double _tExp[2], double _l[2], double _beta[2], double _sigmaTot[2]) 
{
    double c            = Constants::LIGHT_SPEED;
    double numerator    = pow(TMath::Abs(_tExp[1] - _tExp[0])  - (_l[1] / (_beta[1] * c)  + _l[0] / (_beta[0] * c)), 2);
    double denominator  = _sigmaTot[0] + _sigmaTot[1];

    return numerator / denominator;
}
