#ifndef XRAYPHYSICS_C_INTERFACE_H
#define XRAYPHYSICS_C_INTERFACE_H

#include "xrayphysics_export.h"

extern "C" XRAYPHYSICS_EXPORT void about();

extern "C" XRAYPHYSICS_EXPORT float atomicMass(int Z);
extern "C" XRAYPHYSICS_EXPORT float massDensity(int Z);
extern "C" XRAYPHYSICS_EXPORT int elementSymbolToAtomicNumber(const char* chemForm);

extern "C" XRAYPHYSICS_EXPORT bool simulateSpectra(float kVp, float takeOffAngle, int Z, float* gammas, int N, float* output);
extern "C" XRAYPHYSICS_EXPORT bool changeTakeOffAngle(float kVp, float takeOffAngle_cur, float takeOffAngle_new, int Z, float* gammas, int N, float* s);

extern "C" XRAYPHYSICS_EXPORT float sigma(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaCompound(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float sigmae(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaeCompound(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float sigmaPE(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaCompoundPE(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float sigmaCS(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaCompoundCS(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float sigmaRS(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaCompoundRS(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float sigmaPP(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaCompoundPP(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float sigmaTP(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float sigmaCompoundTP(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float incoherentScatterDistribution(float Z, float gamma, float theta);
extern "C" XRAYPHYSICS_EXPORT float coherentScatterDistribution(float Z, float gamma, float theta);

extern "C" XRAYPHYSICS_EXPORT float incoherentScatterDistributionCompound(const char* chemForm, float gamma, float theta);
extern "C" XRAYPHYSICS_EXPORT float coherentScatterDistributionCompound(const char* chemForm, float gamma, float theta);

extern "C" XRAYPHYSICS_EXPORT float incoherentScatterDistribution_normalizationFactor(float Z, float gamma);
extern "C" XRAYPHYSICS_EXPORT float coherentScatterDistribution_normalizationFactor(float Z, float gamma);

extern "C" XRAYPHYSICS_EXPORT float incoherentScatterDistributionCompound_normalizationFactor(const char* chemForm, float gamma);
extern "C" XRAYPHYSICS_EXPORT float coherentScatterDistributionCompound_normalizationFactor(const char* chemForm, float gamma);

extern "C" XRAYPHYSICS_EXPORT float meanEnergy(float* spectralResponse, float* gammas, int N);
extern "C" XRAYPHYSICS_EXPORT bool normalizeSpectrum(float* spectralResponse, float* gammas, int N);

extern "C" XRAYPHYSICS_EXPORT float effectiveZ(const char* chemForm, float min_energy, float max_energy, float arealDensity);

extern "C" XRAYPHYSICS_EXPORT float effectiveAttenuation(float Ze, float density, float thickness, float* spectralResponse, float* gammas, int N);
extern "C" XRAYPHYSICS_EXPORT float effectiveEnergy(float Ze, float density, float thickness, float* spectralResponse, float* gammas, int N);

extern "C" XRAYPHYSICS_EXPORT float effectiveAttenuation_compound(const char* chemForm, float density, float thickness, float* spectralResponse, float* gammas, int N);
extern "C" XRAYPHYSICS_EXPORT float effectiveEnergy_compound(const char* chemForm, float density, float thickness, float* spectralResponse, float* gammas, int N);

extern "C" XRAYPHYSICS_EXPORT float transmission(float Z, float density, float thickness, float* spectralResponse, float* gammas, int N);
extern "C" XRAYPHYSICS_EXPORT float transmission_compound(const char* chemForm, float density, float thickness, float* spectralResponse, float* gammas, int N);

extern "C" XRAYPHYSICS_EXPORT bool setBHlookupTable(float Ze, float* spectralResponse, float* gammas, int N_gamma, float* LUT, float T_lac, int N_lac, float referenceEnergy);
extern "C" XRAYPHYSICS_EXPORT bool setBHlookupTable_compound(const char* chemForm, float* spectralResponse, float* gammas, int N_gamma, float* LUT, float T_lac, int N_lac, float referenceEnergy);

extern "C" XRAYPHYSICS_EXPORT bool setBHClookupTable(float Ze, float* spectralResponse, float* gammas, int N_gamma, float* LUT, float T_lac, int N_lac, float referenceEnergy);
extern "C" XRAYPHYSICS_EXPORT bool setBHClookupTable_compound(const char* chemForm, float* spectralResponse, float* gammas, int N_gamma, float* LUT, float T_lac, int N_lac, float referenceEnergy);

extern "C" XRAYPHYSICS_EXPORT bool generateDEDlookUpTables(float* spectralResponses, float* gammas, int N_gamma, float* referenceEnergies, float* basisFunctions, float* LUT, float T_lac, int N_lac);

extern "C" XRAYPHYSICS_EXPORT bool setTwoMaterialBHClookupTable(float* spectralResponse, float* gammas, int N_gamma, float referenceEnergy, float* sigmas, float* LUT, float T_lac, int N_lac);

#endif