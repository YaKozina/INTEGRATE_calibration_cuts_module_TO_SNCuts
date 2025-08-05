#include "PTDParticle.hh"

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

void        PTDParticle::set_calo_vertex_position(double _X, double _Y, double _Z)
{
    hasCaloVertex = true;
    caloVertexPosition.SetXYZ(_X, _Y, _Z);
}

bool 	    PTDParticle::has_foil_vertex()
{
    return hasFoilVertex;
}
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

TVector3    PTDParticle::get_calo_vertex_position()
{
    return caloVertexPosition;
}
