/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2023 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// ROOT headers
#include "TClonesArray.h"
#include "TMath.h"
#include "TRandom.h"

// Fair headers
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"

// R3B headers
#include "R3BCalifaMapped2SuperCal.h"

// ---- Default constructor -------------------------------------------
R3BCalifaMapped2SuperCal::R3BCalifaMapped2SuperCal()
    : R3BCalifaMapped2SuperCal("R3BCalifaMapped2SuperCal", 1)
{
}

// ---- Standard Constructor ------------------------------------------
R3BCalifaMapped2SuperCal::R3BCalifaMapped2SuperCal(const TString& name, Int_t iVerbose)
    : FairTask(name, iVerbose)
    , fOnline(kFALSE)
{
}

// ---- Destructor ----------------------------------------------------
R3BCalifaMapped2SuperCal::~R3BCalifaMapped2SuperCal()
{
    LOG(debug) << "Destructor of R3BCalifaMapped2SuperCal";
    if (fDataInput)
        delete fDataInput;
}

// ----  Initialisation  ----------------------------------------------
void R3BCalifaMapped2SuperCal::SetParContainers()
{
    LOG(debug) << "SetParContainers of R3BCalifaMapped2SuperCal";
    // Load all necessary parameter containers from the runtime data base
}

// ---- Init ----------------------------------------------------------
InitStatus R3BCalifaMapped2SuperCal::Init()
{
    LOG(info) << "R3BCalifaMapped2SuperCal::Init()";

    // Get a handle from the IO manager
    FairRootManager* ioman = FairRootManager::Instance();
    if (!ioman)
    {
        return kFATAL;
    }

    // Get a pointer to the previous already existing data level
    /*
    fDataInput = (TClonesArray*) ioman->GetObject("InputDataLevelName");
    if ( ! fDataInput ) {
    return kERROR;
    }
  */

    // Create the TClonesArray for the output data and register it
    /*
    fDataOutput = new TClonesArray("OutputDataLevelName", 10);
    ioman->Register("OutputDataLevelName","OutputDataLevelName",fDataOutput,fOnline);
  */

    // Do whatever else is needed at the initilization stage
    // Create histograms to be filled
    // initialize variables

    return kSUCCESS;
}

// ---- ReInit  -------------------------------------------------------
InitStatus R3BCalifaMapped2SuperCal::ReInit()
{
    LOG(debug) << "ReInit of R3BCalifaMapped2SuperCal";
    SetParContainers();
    return kSUCCESS;
}

// ---- Exec ----------------------------------------------------------
void R3BCalifaMapped2SuperCal::Exec(Option_t* opt) { LOG(debug) << "Exec of R3BCalifaMapped2SuperCal"; }

// ---- Finish --------------------------------------------------------
void R3BCalifaMapped2SuperCal::Finish() { LOG(debug) << "Finish of R3BCalifaMapped2SuperCal"; }

// ---- Reset ---------------------------------------------------------
void R3BCalifaMapped2SuperCal::Reset()
{
    LOG(debug) << "Reset Data Structures";
    if (fDataOutput)
        fDataOutput->Clear();
}

ClassImp(R3BCalifaMapped2SuperCal);
