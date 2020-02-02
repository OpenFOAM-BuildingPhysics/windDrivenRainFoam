///////////////////////////////////////////
List<scalar> DATABASE_DIAMETERS(34); 
List<scalar> DATABASE_Vt(34); 
DATABASE_DIAMETERS = {0, 0.3,  0.4,  0.5,  0.6,  0.7,  0.8,  0.9,  1.0,  1.2,  1.4, 1.6,  1.8,  2.0,  2.2,  2.4,  2.6,  2.8,  3.0,  3.2,  3.4, 3.6,  3.8,  4.0,  4.2,  4.4,  4.6,  4.8,  5.0,  5.2,  5.4, 5.6,  5.8,  6.0 };
DATABASE_Vt = {0, 1.17, 1.62, 2.06, 2.47, 2.87, 3.27, 3.67, 4.03, 4.64, 5.17, 5.65, 6.09, 6.49, 6.90, 7.27, 7.57, 7.82, 8.06, 8.26, 8.44, 8.60, 8.72, 8.83, 8.92, 8.98, 9.03, 9.07, 9.09, 9.12, 9.14, 9.16, 9.17, 9.18 };  

List<scalar> Vt(phases.size());
List<scalar> DIAMETERS(phases.size());

forAll (phases, i)
{
    DIAMETERS[i] = phases[i];
}

int Vt_index = 0;
forAll (phases, i)
{    
    for (label j = 0; j < 34; j++)
    {    
        if ( std::abs(DATABASE_DIAMETERS[j]-DIAMETERS[i]*1E3) < scalar(1E-4) )
        {            
            Vt[Vt_index] = DATABASE_Vt[j];
            Vt_index = Vt_index + 1;
        }
    }
}

List<List<scalar>> DFh(Rh.size());
forAll (Rh, i)
{    
    scalar Rh_ = Rh[i];
    List<scalar> DF(phases.size());
    scalar DFh_SUM = 0;
   
    if (Rh_ > 0)
    { 
        forAll (phases, j)
        {
            if (j==0)
            {
                DF[j] = best( (DIAMETERS[j]*1E3 + (DIAMETERS[j+1]*1E3-DIAMETERS[j]*1E3)/2.0) , Rh_) - 0.0;
            }
            else if (j == phases.size()-1)
            {
                DF[j] = 1 - best( (DIAMETERS[j]*1E3 - (DIAMETERS[j]*1E3-DIAMETERS[j-1]*1E3)/2.0) , Rh_);
            }
            else
            {
                DF[j] = best( (DIAMETERS[j]*1E3 + (DIAMETERS[j+1]*1E3-DIAMETERS[j]*1E3)/2.0) , Rh_) - best( (DIAMETERS[j]*1E3 - (DIAMETERS[j]*1E3-DIAMETERS[j-1]*1E3)/2.0) , Rh_);
            }
            DFh_SUM = DFh_SUM + (DF[j]*Vt[j]);
        }
        
        DFh[i] = (DF*Vt)/DFh_SUM;
    }
}
///////////////////////////////////////////
