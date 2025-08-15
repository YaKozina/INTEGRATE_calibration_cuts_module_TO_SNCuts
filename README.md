## BREAKING

**I Have changed the module to work with Falaise 5.x version. The affecting change from Falaise 4.x to 5.x was the change in architecture of how vertices are stored/read. This is now working.**

### REMEMBER TO USE BRIO FILES GENERATED WITH FALAISE 5.x

# INTRODUCTION

This is a repository which implements a simple data-cuts Falaise module for the SUperNEMO experiment.

The module's main goal is to input a `.brio` file and *cut* data through a series of filters (for now I'm only implementing simple double beta decay topology filters, this may change in the future depending on collaboration's needs). The goal is to provide a *pure* `.brio` file with **only** the desired events inside!

**The caveat** is that the module must be placed in the pipeline **after** reconstruction is finished, since it pulls data from the `CDbank` and the `PTDbank`. (If these two are not provided in the `.brio` file, the module will do nothin.) 

**INSTALLATION**
==========
(Updated 11.12.2023)

To install the module:
1. Clone this repository to your local drive (preferably on `sps/nemo/scratch/` to be able to run most updated Falaise)
2. Run the `install_test.sh` script, which prompts to provide the Falaise **include/** path. (Provide the absolute path to where Falaise is installed and where the `include` files are placed, i.e. `/sps/nemo/sw/Falaise/tests/install_244/include/`)
3. There is a small test provided at the end of the `install_test.sh` script. This assumes that there is a `CD.brio` file present in the base directory. To perform this test, provide a sample `CD.brio` file (There are config files in the `test/` folder, you can use these to generate a simple $2\nu\beta\beta$ simulation). If no `CD.brio` is provided, the test will fail, but the module should work regardless.

**MODULE ARCHITECTURE**
===========
The idea of this module is to provide a **repository of cuts**. There are a number of standard cuts/filters already implemented (with more to come) in the `Filters.hh` class. The `Filters` work in such a way that an `Event` is passed as an argument and a `bool` is returned, either event `passed` or `failed` given set of cuts. 
From the implemented filters, the user can simply *chose* whichever ones are relevant. I have tried to implement the idea of _"flicking a switch"_ to turn on a series of cuts. The event must pass all the cuts that are **turned on**, while ignoring those that are off. 
#### One example speaks for all, see the [example](https://github.com/Shoram444/SNCuts#example-usage) below. 

**EXAMPLE USAGE**
===========
> Let us have simulated (and reconstructed) 100 events of standard $2\nu\beta\beta$ process in the Failaise simulation pipeline. Now, let's say we want to filter out only the $\beta\beta$ topology cuts, we shall call these the Standard Double Beta Decay Reconstruction Cuts (SDBDRC). An event fulfilling SDBDRC must have:
> 1. 2 negative particles (equivalent to saying 2 tracks with curvature following the negative charge in a magnetic field)
> 2. 2 OM hits
> 3. 2 Associated OM Hits
> 4. Total energy within the range: 0 - 3500 keV
> 5. 2 vertices on source foil
> To use the **SNCuts** module, this is as simple as setting the following values in the `SNCutsPipeline.conf` file:
```bash
# - Module load section
[name="flreconstruct.plugins" type="flreconstruct::section"]
	plugins : string[1] = "SNCuts"
	SNCuts.directory : string = "@PROJECT_BINARY_DIR@/"

[name="pipeline" type="SNCuts"]
useEventHasTwoNegativeParticles : boolean = true
useEventHasTwoTracks : boolean = true
useEventHasTwoFoilVertices : boolean = true
useEventHasTwoCaloHits : boolean = true
useEventHasTwoAssociatedCaloHits : boolean = true
useEventHasSumEnergyAbove : boolean = true
minSumEnergy : real = 0.0
useEventHasSumEnergyBelow : boolean = true
maxSumEnergy : real = 3500.0
```
> or more simply, for convenience the `SDBDRC` batch of cuts can be turned on by:
```bash
# - Module load section
[name="flreconstruct.plugins" type="flreconstruct::section"]
	plugins : string[1] = "SNCuts"
	SNCuts.directory : string = "@PROJECT_BINARY_DIR@/"

[name="pipeline" type="SNCuts"]
useSDBDRC : boolean = true
minSumEnergy : real = 0.0
maxSumEnergy : real = 3500.0
```
> Note that the energy must be set explicitly.

#### Now all that is needed is to run the following command and receive a _**clean**_ `CDCut.brio` file:
```bash
flrecontruct -i CD.brio -p SNCutsPipeline.conf -o CDCut.brio
```


**CURRENTLY IMPLEMENTED FILTERS**
===========
### Basic bool cuts
- `bool event_has_two_negative_particles(Event& _event)`: returns true if there are exactly 2 particles in the `PTD` bank and **both** are negative. *Requires PTD bank
- `bool event_has_two_particles(Event& _event)`: returns true if there are exactly 2 particles in the `PTD` bank. *Requires PTD bank
- `bool event_has_particles(Event& _event)`: returns true if there is _at least_ one particle in `PTD` bank. *Requires PTD bank
- `bool event_has_two_tracks(Event& _event)`: returns true if there are exactly 2 particles in the `PTD` bank. *Requires PTD bank **equivalend to `event_has_two_particles(Event& _event)`         
- `bool event_has_two_foil_vertices(Event& _event)`: returns true if there are exactly 2 reconstructed vertices on the source foil in the `PTD` bank. *Requires PTD bank
- `bool event_has_two_calo_hits(Event& _event)`: returns true if there are exactly 2 calorimeter hits in the `CD` bank. *Requires CD bank
- `bool event_has_one_calo_hit(Event& _event)`: returns true if there is _at least_ 1 calorimeter hit in the `CD` bank. *Requires CD bank
- `bool event_has_two_associated_calo_hits(Event& _event)`: returns true if there are exactly 2 particles in the `PTD` bank and both have exactly 1 calorimeter hit. *Requires PTD bank
- `bool event_has_two_distinct_associated_calo_hits(Event& _event)`: returns true if there are exactly 2 particles in the `PTD` bank and both have exactly 1 calorimeter hit which is different from one another. *Requires PTD bank

### Energy cuts 
- `bool event_has_sum_energy_above(Event& _event, double _minEnergy)`: returns true if the sum of the event energy (from `PTD` bank) is above the limit given by `_minEnergy`. `_minEnergy` is set by `event.set_min_energy(double _minEnergy)`
- `bool event_has_sum_energy_below(Event& _event, double _maxEnergy)`: returns true if the sum of the event energy (from `PTD` bank) is below the limit given by `_maxEnergy`. `_maxEnergy` is set by `event.set_max_energy(double _maxEnergy)`

### Vertex distance cuts
- `bool event_has_foil_vertex_distance_below(Event& _event, double _maxFoilVertexDistance)`: returns true if two vertices are are less than defined distance: `_maxFoilVertexDistance`. Needs to be used in conjuction with `void set_max_foil_vertex_distance(double _maxFoilVertexDistance)`

### ToF Cuts
- `bool event_has_Pint_above(Event& _event, double _minPint)`: returns true if the internal probability is above: `_minPint`. Needs to be used in conjuction with `void set_min_Pint(double _minPint);`
- `bool event_has_Pext_below(Event& _event, double _maxPext)`: returns true if the external probability is below: `_maxPext`. Needs to be used in conjuction with `void set_max_Pext(double _maxPext);`

### (EXPERIMENTAL) SD cuts
- `bool event_has_n_escaped_particles(Event& _event)`: returns true if the event has exactly `n` primary particles that have escaped the source foil: `nEscapedParticles`. This filter can only be used on simulated data with the `all_details` flag turned on in the `variant.profile`. To specify the number of escaped particles, set `nEscapedParticles` in the config file. 

# Using filters:

#### To turn on any of the filters, the filter must be set to `true` in the `SNCutsPipeline.config` file. Each cut is turned on with the keyword `useFiltersName` (note the CamelCase font use). Check out the [example](https://github.com/Shoram444/SNCuts#example-usage) above. 

**ADDING FILTERS**
==========
TBD

