/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */
                                                                        
// $Revision: 1.1.1.1 $
// $Date: 2000-09-15 08:23:19 $
// $Source: /usr/local/cvs/OpenSees/SRC/domain/pattern/UniformExcitation.h,v $
                                                                        
                                                                        
// File: ~/domain/load/UniformExcitation.h
//
// Written: fmk 11/98
// Revised:
//
// Purpose: This file contains the class definition for UniformExcitation.
// UniformExcitation is a concrete class. It sets the R for a single
// ground motion acting on a structure.

#ifndef UniformExcitation_h
#define UniformExcitation_h

#include <EarthquakePattern.h>

class UniformExcitation : public EarthquakePattern
{
  public:
    UniformExcitation(GroundMotion &theMotion, int dof, int tag);  
    ~UniformExcitation();

    // pure virtual functions
    void applyLoad(double time);
    void Print(ostream &s, int flag =0);

    int sendSelf(int commitTag, Channel &theChannel);
    int recvSelf(int commitTag, Channel &theChannel, 
		 FEM_ObjectBroker &theBroker);    

    LoadPattern *getCopy(void);
 protected:

 private:
    GroundMotion *theMotion; // the ground motion
    int theDof;      // the dof corrseponding to the ground motion
};

#endif
