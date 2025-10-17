# windDrivenRainFoam

An open-source solver for wind-driven rain based on OpenFOAM

<img src="https://raw.githubusercontent.com/wiki/OpenFOAM-BuildingPhysics/windDrivenRainFoam/img/winddrivenrainfoam.png" width="60%">

The solver is tested for the following OpenFOAM versions:

* OpenFOAM-org (OpenFOAM Foundation) v6, v7, v8, v9, v10, v11, v12, v13
* OpenFOAM-com (OpenCFD-ESI) v1806, v2006, v2106

### Usage

You can compile the solver for a specific OpenFOAM version by checking out the commit with corresponding tag. For example, for OpenFOAM v9:

    git clone https://github.com/OpenFOAM-BuildingPhysics/windDrivenRainFoam.git
    cd windDrivenRainFoam
    git checkout tags/of-org_v9.0
    wmake

See the list of tags for different versions [here](https://github.com/OpenFOAM-BuildingPhysics/windDrivenRainFoam/tags)

### Documentation

Read [windDrivenRainFoam wiki](https://github.com/OpenFOAM-BuildingPhysics/windDrivenRainFoam/wiki) for documentation.

### Tutorial cases

Tutorial case for the WDR exposure of an isolated cubic building can be found [here](https://github.com/OpenFOAM-BuildingPhysics/windDrivenRainFoam-tutorials).

### Validation

Please refer to the [dataset of field experiments](https://carmeliet.ethz.ch/research/downloads/wind-driven-rain.html) and the [relevant papers](https://carmeliet.ethz.ch/research/downloads/winddrivenrainfoam.html) for the validation study. 

More information at the Chair of Building Physics: https://carmeliet.ethz.ch
