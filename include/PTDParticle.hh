#ifndef PTDPARTICLE_HH
#define PTDPARTICLE_HH

// ROOT headers
#include "TObject.h"
#include "TVector3.h"

// Standard headers
#include "iostream"
#include <algorithm>

using namespace std;

class PTDParticle : public TObject
{
public:
    //! constructor
    PTDParticle();

    //! desctructor
    ~PTDParticle();

    void     set_charge(int _charge);
    void     set_associated_calo_hits_number(int _associatedCaloHitsNo);
    void     set_energy(double _energy);
    void     set_energy_sigma_MeV(double _energySigma);
    void     set_track_length(double _trackLength);
    void     set_time(double _time);
    void     set_time_sigma(double _timeSigma);
    void     set_foil_vertex_position(double _X, double _Y, double _Z);
    void     set_calo_vertex_position(double _X, double _Y, double _Z);

    // new
    // ---------------------------------------------------------------
    void     set_calib_vertex_position(double _X, double _Y, double _Z);
    void     set_calibration_source_vertex_position(double x, double y, double z);

    void     set_kink_info_from_trajectory(int trajectoryKinkCount);
    void     set_has_kink_in_trajectory(bool hasKink);

    void     set_has_main_or_x_calo_vertex(bool value);

    void     set_calo_charge_nVs(double q);
    // ---------------------------------------------------------------

    bool     has_foil_vertex();
    bool     has_calo_vertex();

    // new
    // ---------------------------------------------------------------
    bool     has_calib_vertex();
    bool     has_calibration_source_vertex() const;
    bool     has_kink_in_trajectory();

    bool     has_main_or_x_calo_vertex() const;
    // ---------------------------------------------------------------

    int      get_charge();
    int      get_associated_calo_hits_number();  // get the number of calo hits per PTD entry (this may not be 1)

    // ---------------------------------------------------------------
    int      get_kink_count_in_trajectory();
    // ---------------------------------------------------------------

    double   get_energy();
    double   get_energy_MeV();
    double   get_energy_sigma_MeV();
    double   get_track_length();
    double   get_time();
    double   get_time_sigma();

    // ---------------------------------------------------------------
    double   get_calo_charge_nVs();
    // ---------------------------------------------------------------

    TVector3 get_foil_vertex_position();
    TVector3 get_calo_vertex_position();

    // ---------------------------------------------------------------
    TVector3 get_calib_vertex_position();
    TVector3 get_calibration_source_vertex_position() const;
    // ---------------------------------------------------------------

    // new
    // ---------------------------------------------------------------
    // ---------------------------------------------------------------

private:
    int      charge;
    int      associatedCaloHitsNo = 0;

    // ---------------------------------------------------------------
    int      kinkCountInTrajectory = 0;
    // ---------------------------------------------------------------

    double   energy      = -1.0;
    double   energySigma = -1.0;
    double   trackLength = -1.0;
    double   time        = -1.0;
    double   timeSigma   = -1.0;

    double   caloCharge_nVs = -1.0;

    bool     hasFoilVertex = false;
    bool     hasCaloVertex = false;

    // ---------------------------------------------------------------
    bool     hasCalibVertex               = false;
    bool     hasCalibrationSourceVertex_  = false;
    bool     hasKinkInTrajectory          = false;

    bool     hasMainOrXCalVertex          = false;
    // ---------------------------------------------------------------

    TVector3 foilVertexPosition;
    TVector3 caloVertexPosition;

    // ---------------------------------------------------------------
    TVector3 calibVertexPosition;
    TVector3 calibrationSourceVertex_;
    // ---------------------------------------------------------------

    ClassDef(PTDParticle,1);
};

#endif // PTDPARTICLE_HH

