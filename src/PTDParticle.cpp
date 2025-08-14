#include "PTDParticle.hh"
#include <algorithm>

ClassImp(PTDParticle);


PTDParticle::PTDParticle()
{
}

PTDParticle::~PTDParticle()
{
}

void        PTDParticle::set_charge(int _charge)
{
    charge = _charge;
}

void        PTDParticle::set_energy(double _energy)
{
    energy = _energy;
}

void        PTDParticle::set_energy_sigma_MeV(double _energySigma)
{
    energySigma = _energySigma;
}

int         PTDParticle::get_charge()
{
    return charge;
}
double      PTDParticle::get_energy()
{
    return energy;
}

double 		PTDParticle::get_energy_MeV()
{
    return energy / 1000; // originally energy is stored in keV in ::PTDParticle
}

double 		PTDParticle::get_energy_sigma_MeV()
{
    return energySigma; 
}

double 		PTDParticle::get_track_length()
{
    return trackLength;
}


void    PTDParticle::set_track_length(double _trackLength)
{
    trackLength = _trackLength;
}

double 		PTDParticle::get_time()
{
    return time;
}


void    PTDParticle::set_time(double _time)
{
    time = _time;
}

double 		PTDParticle::get_time_sigma()
{
    return timeSigma;
}


void    PTDParticle::set_time_sigma(double _timeSigma)
{
    timeSigma = _timeSigma;
}

void        PTDParticle::set_foil_vertex_position(double _X, double _Y, double _Z)
{
    hasFoilVertex = true;
    foilVertexPosition.SetXYZ(_X, _Y, _Z);
}


//new
//******************************************************************

void PTDParticle::set_calib_vertex_position(double _X, double _Y, double _Z)
{
	hasCalibVertex = true;
	calibVertexPosition.SetXYZ(_X, _Y, _Z);
}


void PTDParticle::set_calibration_source_vertex_position(double x,double y,double z)
{
  hasCalibrationSourceVertex_ = true;
  calibrationSourceVertex_.SetXYZ(x,y,z);
}


//******************************************************************
//end  


//new
//******************************************************************
void PTDParticle::set_kink_info_from_trajectory(int trajectoryKinkCount)
{
  kinkCountInTrajectory = trajectoryKinkCount;
  hasKinkInTrajectory   = (trajectoryKinkCount > 0);
}

void PTDParticle::set_has_kink_in_trajectory(bool hasKink)
{
  hasKinkInTrajectory   = hasKink;
  kinkCountInTrajectory = hasKink ? std::max(1, kinkCountInTrajectory) : 0; //???!!!
}
//******************************************************************
//end of 




void        PTDParticle::set_calo_vertex_position(double _X, double _Y, double _Z)
{
    hasCaloVertex = true;
    caloVertexPosition.SetXYZ(_X, _Y, _Z);
}

bool 	    PTDParticle::has_foil_vertex()
{
    return hasFoilVertex;
}

//new
//********************************************************************
bool PTDParticle::has_calib_vertex()
{
    return hasCalibVertex;
}

bool PTDParticle::has_calibration_source_vertex() const 
{ return hasCalibrationSourceVertex_; 

}

//********************************************************************
//end of


//new
//********************************************************************
bool PTDParticle::has_kink_in_trajectory()
{
  return hasKinkInTrajectory;
}
//********************************************************************
//end of

bool 	PTDParticle::has_calo_vertex()
{
    return hasCaloVertex;
}

void        PTDParticle::set_associated_calo_hits_number(int _associatedCaloHitsNo)
{
    associatedCaloHitsNo = _associatedCaloHitsNo;
}

int 		PTDParticle::get_associated_calo_hits_number()
{
    return associatedCaloHitsNo;
}

TVector3    PTDParticle::get_foil_vertex_position()
{
    return foilVertexPosition;
}

//new 
//********************************************************************
int PTDParticle::get_kink_count_in_trajectory()
{
  return kinkCountInTrajectory;
}
//********************************************************************
//end 

//
//*********************************************************
TVector3 PTDParticle::get_calib_vertex_position()
{
    return calibVertexPosition;
}


TVector3 PTDParticle::get_calibration_source_vertex_position() const 
{ return calibrationSourceVertex_; 
}
//*********************************************************
//

TVector3    PTDParticle::get_calo_vertex_position()
{
    return caloVertexPosition;
}
