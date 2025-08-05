#include "Event.hh"


ClassImp(Event);


Event::Event()
{
}

Event::~Event()
{
    reset();
}

void Event::reset()
{
    eventTotalEnergy = -1.0; 
    ptdparticles.clear();
    sdparticles.clear();
}

void Event::set_event_number(int _eventNumber)
{
    eventNumber = _eventNumber;
}

int Event::get_event_number()
{
    return eventNumber;
}

void Event::add_particle(PTDParticle &_newPTDParticle)
{
    ptdparticles.push_back(_newPTDParticle);
}

void Event::add_sd_particle(SDParticle &_newSDParticle)
{
    sdparticles.push_back(_newSDParticle);
}


std::vector<PTDParticle> Event::get_particles()
{
    return ptdparticles;
}

std::vector<SDParticle> Event::get_sd_particles()
{
    return sdparticles;
}

void Event::add_cd_bank(CDBank &_cdBank)
{
    cdBank = _cdBank;
}		   

CDBank 	Event::get_cd_bank()
{
    return cdBank;
}     

void Event::set_event_total_energy(double _eventTotalEnergy)
{
    eventTotalEnergy = _eventTotalEnergy;
}

double Event::get_event_total_energy()
{
    return eventTotalEnergy;
}


void Event::print()
{
    cout << "Event Number: "        << eventNumber         << endl;
    cout << "Event Total Energy: "  << eventTotalEnergy    << endl;

    for (int i = 0; i < ptdparticles.size(); i++)
    {
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "Particle: "                                << i+1<< "/"<<  ptdparticles.size()                        << endl;
        cout << "Particle number of associated caloHits: "  << ptdparticles.at(i).get_associated_calo_hits_number()    << endl;
        
        cout << "Particle Charge: "                         << ptdparticles.at(i).get_charge()                         << endl;
        cout << "Particle Energy: "                         << ptdparticles.at(i).get_energy() << " keV"               << endl;
        cout << "Particle Energy: "
                << ptdparticles.at(i).get_energy_MeV()                     
                << " +- " <<  ptdparticles.at(i).get_energy_sigma_MeV()
                <<" MeV" << endl;
        cout << "Particle has foil vertex: "                << ptdparticles.at(i).has_foil_vertex()                    << endl;
        cout << "Foil Vertex Position: (" 
                <<          ptdparticles.at(i).get_foil_vertex_position().X()
                << ", " <<  ptdparticles.at(i).get_foil_vertex_position().Y()
                << ", " <<  ptdparticles.at(i).get_foil_vertex_position().Z() 
                << ")" << endl;

        cout << "Particle has calo vertex: "                << ptdparticles.at(i).has_foil_vertex()                    << endl;
        cout << "Calo Vertex Position: (" 
                <<          ptdparticles.at(i).get_calo_vertex_position().X()
                << ", " <<  ptdparticles.at(i).get_calo_vertex_position().Y()
                << ", " <<  ptdparticles.at(i).get_calo_vertex_position().Z() 
                << ")" << endl;
        cout << "Particle track length: "                   << ptdparticles.at(i).get_track_length() << " mm"          << endl;
        cout << "Particle hit time: "
                << ptdparticles.at(i).get_time() 
                << " +- " << ptdparticles.at(i).get_time_sigma()
                << " ns"  << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;
    }

    for (int i = 0; i < sdparticles.size(); i++)
    {
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "Particle: "                                << i+1<< "/"<<  sdparticles.size()                      << endl;
        cout << "Particle escaped foil: "                   << sdparticles.at(i).has_escaped_foil()                 << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;
    }
}