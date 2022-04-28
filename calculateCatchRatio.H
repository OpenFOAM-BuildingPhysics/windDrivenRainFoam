Info<< nl << "Calculating specific catch ratio fields\n" << endl;
forAll (phases, phase_no)
{
    surfaceScalarField normalvel
    (
        mag( (mesh.Sf()/mesh.magSf()) & fvc::interpolate(Urain[phase_no]) )
    );
    surfaceScalarField surfaceScr
    (
        (normalvel * fvc::interpolate(alpharain[phase_no])) / (1.0 * Vt[phase_no]) //Here 1.0 is the alpha values at inlets 
    );
    const surfaceScalarField::Boundary& patchSurfaceScr = surfaceScr.boundaryField();

    word namescr_i ("scr" + name(phase_no+1));
    scr.set
    (
    phase_no,
    new volScalarField
    (
        IOobject
        (
            namescr_i,
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedScalar(namescr_i, dimless, 0.0)
    )
    );        
    volScalarField::Boundary& scrtempBf = scr[phase_no].boundaryFieldRef();
    
    forAll(scrtempBf,patchi)
    {
        scrtempBf[patchi] = patchSurfaceScr[patchi];
    }    

    scr[phase_no].write();
}

Info << "Calculating catch ratio field\n" << endl;
forAll (Rh, i)
{
    word gcrname ("gcr" + name(Rh[i]));
    volScalarField gcrtemp
    (
        IOobject
        (
            gcrname,
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedScalar("gcr", dimless, 0.0)
    );

    forAll (phases, phase_no)
    {
        gcrtemp += scr[phase_no]*DFh[i][phase_no];
    }
    gcrtemp.write();
}
