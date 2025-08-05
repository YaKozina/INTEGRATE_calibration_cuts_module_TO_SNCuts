#include "SDParticle.hh"

ClassImp(SDParticle);


SDParticle::SDParticle()
{
    hasFoilVertex = false;
    hasEscapedFoil = false;
}

SDParticle::~SDParticle()
{
}

void        SDParticle::set_charge(int _charge)
{
    charge = _charge;
}

void        SDParticle::set_energy(double _energy)
{
    energy = _energy;
}

int         SDParticle::get_charge()
{
    return charge;
}
double      SDParticle::get_energy()
{
    return energy;
}

double 		SDParticle::get_energy_MeV()
{
    return energy / 1000; // originally energy is stored in keV in ::SDParticle
}


void        SDParticle::set_foil_vertex_position(double _X, double _Y, double _Z)
{
    foilVertexPosition.SetXYZ(_X, _Y, _Z);
}


bool 	    SDParticle::has_foil_vertex()
{
    return hasFoilVertex;
}


TVector3    SDParticle::get_foil_vertex_position()
{
    return foilVertexPosition;
}

void 	SDParticle::set_has_escaped_foil(bool _escaped)
{
    hasEscapedFoil = _escaped;
}

bool    SDParticle::has_escaped_foil()
{
    return hasEscapedFoil;
}

void    SDParticle::set_trackID(int _trackID)
{
    trackID = _trackID;
}

int     SDParticle::get_trackID()
{
    return trackID;
}