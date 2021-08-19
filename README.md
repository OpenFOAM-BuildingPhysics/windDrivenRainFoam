# windDrivenRainFoam

An open-source solver for wind-driven rain based on OpenFOAM

<img src="https://carmeliet.ethz.ch/research/downloads/winddrivenrainfoam/_jcr_content/par/fullwidthimage_0/image.imageformat.fullwidth.1739434017.png"  width="60%">

The solver is tested for the following OpenFOAM versions:

* OpenFOAM-org (OpenFOAM Foundation) v6, v7, v8, v9 
* OpenFOAM-com (OpenCFD-ESI) v1806

### Usage

You can compile the solver for the specific OpenFOAM version by checking out commit with corresponding tag. For example, for OpenFOAM v9:

	git clone https://gitlab.ethz.ch/openfoam-cbp/solvers/winddrivenrainfoam.git
	cd winddrivenrainfoam
	git checkout tags/of-org_v9.0
	wmake

### Documentation

Read [windDrivenRainFoam wiki](https://gitlab.ethz.ch/openfoam-cbp/solvers/winddrivenrainfoam/-/wikis/home) for documentation.

### Validation

Please refer to the [dataset of field experiments](https://carmeliet.ethz.ch/research/downloads/wind-driven-rain.html) and the [relevant papers](https://carmeliet.ethz.ch/research/downloads/winddrivenrainfoam.html) for the validation study. 

More information at the Chair of Building Physics: https://carmeliet.ethz.ch
