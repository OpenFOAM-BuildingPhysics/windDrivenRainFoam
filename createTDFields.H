PtrList<volScalarField> Ctrain(phases.size());
  
forAll (phases, phase_no)
{
    word nameCt_i ("Ct" + name(phase_no+1));
    Ctrain.set
    (
    phase_no,
    new volScalarField
    (
        IOobject
        (
            nameCt_i,
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedScalar(nameCt_i,dimensionSet(0,0,0,0,0,0,0),0)
    )
    );
}

volScalarField k
(
    IOobject
    (
        "k",
        "0",//runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("k",dimensionSet(0,2,-2,0,0,0,0),0)
);
k = k*pow(scalingFactor,2);
k.correctBoundaryConditions();

volScalarField epsilon
(
    IOobject
    (
        "epsilon",
        "0",//runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("epsilon",dimensionSet(0,2,-3,0,0,0,0),0)
);
epsilon = epsilon*pow(scalingFactor,3);
epsilon.correctBoundaryConditions();

volScalarField nut
(
    IOobject
    (
        "nut",
        "0",//runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("nut",dimensionSet(0,2,-1,0,0,0,0),0)
);
nut = nut*scalingFactor;
nut.correctBoundaryConditions();

volScalarField nutrain
(
IOobject
(
    "nutrain",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
),
mesh,
dimensionedScalar("nutrain",dimensionSet(0,2,-1,0,0,0,0),0)
);

volScalarField tp
(
IOobject
(
    "tp",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
),
mesh,
dimensionedScalar("tp",dimensionSet(0,0,1,0,0,0,0),0)
);

volScalarField tfl
(
IOobject
(
    "tfl",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
),
mesh,
dimensionedScalar("tfl",dimensionSet(0,0,1,0,0,0,0),0)
);
