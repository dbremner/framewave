/*
Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
This software is subject to the Apache v2.0 License.

Portions based on work by llcc and visionany (Framewave\sdk\external\dec_cavlc.c). See line number 1207.
*/

#include "Constants.h"
#if (defined( SOL64   ) || defined( _SOL64   ) || defined( SOL32   ) || defined( _SOL32   ) )
#define extern
#define const
#pragma align 16(atanhi_ds, atanlo_ds, aT_ds, xmmDatad, atanhi_fs, atanlo_fs, aT_fs, xmmDataf)
#pragma align 16(Atan2d_constants_d, Atan2d_constants_i, Atan2f_constants_f, Atan2f_constants_i)
#pragma align 16(atanhi_d, atanlo_d, aT_d, atanhi_f, atanlo_f, aT_f, huge_f, one_f, huge_d)
#pragma align 16(one_d, pi_f, pi_o_4_f, pi3_o_4_f, pi_hi_f, pi_lo_f, pi_d, pi_o_4_d, pi3_o_4_d)
#pragma align 16(pi_hi_d, pi_lo_d, idct_weighting, fdct_weighting, dct_Scale, non_intra_quantizer_matrix)
#pragma align 16(dequant_coef, dequant_coef16, QP_SCALE_CR, quant_coef, ClampTbl, coeff4_0, coeff4_1)
#pragma align 16(coeff3_0, coeff2_0, coeff2_1, coeff2_2, coeff2_3, coeff2_4, coeff2_5, coeff2_6)
#pragma align 16(coeff1_0, coeff1_1, coeff1_2, coeff1_3, coeff1_4, coeff1_5, coeff1_6, coeff0_0)
#pragma align 16(coeff0_1, coeff0_2, coeff0_3, coeff0_4, coeff0_5, GetBitsMask32, alphaMasks, alphaMasks_A, c_b, c_b0)
#endif

// Constants used by IntraPredict
extern SYS_FORCEALIGN_16 const Fw16s c_b[16] = {-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
extern SYS_FORCEALIGN_16 const Fw16s c_b0[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// Constants used by Sharpen Filters
extern SYS_FORCEALIGN_16 const unsigned int alphaMasks_16[4][4] = {
                    { 0x0000FFFF, 0x00000000, 0x0000FFFF, 0x00000000 },
                    { 0x00000000, 0xFFFF0000, 0x00000000, 0xFFFF0000 },
                    { 0x00000000, 0x0000FFFF, 0x00000000, 0x0000FFFF },
                    { 0xFFFF0000, 0x00000000, 0xFFFF0000, 0x00000000 },
                };
                
extern SYS_FORCEALIGN_16 const unsigned int alphaMasks_32[4][4] = {
                    { 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000 },
                    { 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF },
                    { 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000 },
                    { 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000 }
                };                

namespace Const
{
    extern const U32    FW_ALIGN  = 32;
    extern const double FW_PI     = 3.14159265358979323846;
    extern const double FW_2PI    = 2 * FW_PI;

    // Debug
    extern const U32 ImageDisplayOnPass   =  0;         // 0 -> disable.
    extern const U32 ImageDisplayOnFail   =  30 * 1000; // 0 -> disable.
           
    extern const double BayerDither44[4][4] = {{0, 8, 2, 10}, {12, 4, 14, 6}, {3, 11, 1, 9}, {15, 7, 13, 5}};
           
    extern const U32 NAN_32Fi      = 0x7FC00000;
    extern const U32 INF_32Fi      = 0x7F800000 ;
    extern const U32 INF_NEG_32Fi  = 0xFF800000 ;
    extern const U32 IND_32Fi      = 0xFFC00000 ;
           
    extern const U32 NAN_64Fi[2]     = {0x0,0x7FF80000};
    extern const U32 INF_64Fi[2]     = {0x0,0x7FF00000};
    extern const U32 INF_NEG_64Fi[2] = {0x0,0xFFF00000};
    extern const U32 IND_64Fi[2]     = {0x0,0xFFF80000};
           
           
    extern const double NAN_64F      = * ( double* ) &NAN_64Fi;
    extern const double INF_64F      = * ( double* ) &INF_64Fi;
    extern const double INF_NEG_64F  = * ( double* ) &INF_NEG_64Fi;
    extern const double IND_64F      = * ( double* ) &IND_64Fi;
           
    extern const float NAN_32F       = * ( float*  ) &NAN_32Fi;
    extern const float INF_32F       = * ( float*  ) &INF_32Fi;
    extern const float INF_NEG_32F   = * ( float*  ) &INF_NEG_32Fi;
    extern const float IND_32F       = * ( float*  ) &IND_32Fi;
};


// --- Color Model Conversion Constants ---
extern const unsigned short int CONST_RGB2YUVsubR = 0, CONST_RGB2YUVsubG = 0, CONST_RGB2YUVsubB = 0;
extern const double CONST_RGB2YUV_YR    =    0.299, CONST_RGB2YUV_YG = 0.587, CONST_RGB2YUV_YB = 0.114;
extern const double CONST_RGB2YUV_UR    =    0.147, CONST_RGB2YUV_UG = 0.289, CONST_RGB2YUV_UB = 0.436;
extern const double CONST_RGB2YUV_VR    =    0.615, CONST_RGB2YUV_VG = 0.515, CONST_RGB2YUV_VB = 0.100;
extern const unsigned short int CONST_RGB2YUVaddY = 0, CONST_RGB2YUVaddU = 128, CONST_RGB2YUVaddV = 128;

extern const unsigned short int CONST_YUV2RGBsubY = 0, CONST_YUV2RGBsubU = 128, CONST_YUV2RGBsubV = 128;
extern const double CONST_YUV2RGB_RY    =    1.000, CONST_YUV2RGB_RU = 0.000, CONST_YUV2RGB_RV = 1.140;
extern const double CONST_YUV2RGB_GY    =    1.000, CONST_YUV2RGB_GU = 0.394, CONST_YUV2RGB_GV = 0.581;
extern const double CONST_YUV2RGB_BY    =    1.000, CONST_YUV2RGB_BU = 2.032, CONST_YUV2RGB_BV = 0.000;
extern const unsigned short int CONST_YUV2RGBaddR = 0, CONST_YUV2RGBaddG = 0, CONST_YUV2RGBaddB = 0;

extern const unsigned short int CONST_RGB2YCbCrsubR = 0, CONST_RGB2YCbCrsubG = 0, CONST_RGB2YCbCrsubB  = 0;
extern const double CONST_RGB2YCbCr_YR  =    0.257, CONST_RGB2YCbCr_YG   = 0.504, CONST_RGB2YCbCr_YB  = 0.098;
extern const double CONST_RGB2YCbCr_CbR =    0.148, CONST_RGB2YCbCr_CbG  = 0.291, CONST_RGB2YCbCr_CbB = 0.439;
extern const double CONST_RGB2YCbCr_CrR =    0.439, CONST_RGB2YCbCr_CrG  = 0.368, CONST_RGB2YCbCr_CrB = 0.071;
extern const double CONST_RGB2YCbCraddY =   16,     CONST_RGB2YCbCraddCb = 128,   CONST_RGB2YCbCraddCr = 128;

extern const unsigned short int CONST_YCbCr2RGBsubY = 16, CONST_YCbCr2RGBsubCb = 128, CONST_YCbCr2RGBsubCr = 128;
extern const double CONST_YCbCr2RGB_RY  =    1.164, CONST_YCbCr2RGB_RCb  = 0.000, CONST_YCbCr2RGB_RCr = 1.596;
extern const double CONST_YCbCr2RGB_GY  =    1.164, CONST_YCbCr2RGB_GCb  = 0.392, CONST_YCbCr2RGB_GCr = 0.813;
extern const double CONST_YCbCr2RGB_BY  =    1.164, CONST_YCbCr2RGB_BCb  = 2.017, CONST_YCbCr2RGB_BCr = 0.000;
extern const unsigned short int CONST_YCbCr2RGBaddR = 0, CONST_YCbCr2RGBaddG = 0, CONST_YCbCr2RGBaddB = 0;

extern const unsigned short int CONST_RGB2XYZsubR = 0, CONST_RGB2XYZsubG = 0, CONST_RGB2XYZsubB = 0;
extern const double CONST_RGB2XYZ_XR    =    0.4124530, CONST_RGB2XYZ_XG = 0.357580,  CONST_RGB2XYZ_XB = 0.1804230;
extern const double CONST_RGB2XYZ_YR    =    0.2126710, CONST_RGB2XYZ_YG = 0.715160,  CONST_RGB2XYZ_YB = 0.0721690;
extern const double CONST_RGB2XYZ_ZR    =    0.0193340, CONST_RGB2XYZ_ZG = 0.1191930, CONST_RGB2XYZ_ZB = 0.9502270;
extern const unsigned short int CONST_RGB2XYZaddX = 0, CONST_RGB2XYZaddY = 0, CONST_RGB2XYZaddZ = 0;
extern const int CONST_RGB2XYZOffsetX = -1623, CONST_RGB2XYZOffsetY = 0, CONST_RGB2XYZOffsetZ = 2908; // For 16s formats-Offset

extern const unsigned short int CONST_XYZ2RGBsubX = 0, CONST_XYZ2RGBsubY = 0, CONST_XYZ2RGBsubZ = 0;
extern const double CONST_XYZ2RGB_RX    =    3.240479, CONST_XYZ2RGB_RY = 1.537150, CONST_XYZ2RGB_RZ = 0.498535;
extern const double CONST_XYZ2RGB_GX    =    0.969256, CONST_XYZ2RGB_GY = 1.875991, CONST_XYZ2RGB_GZ = 0.041556;
extern const double CONST_XYZ2RGB_BX    =    0.055648, CONST_XYZ2RGB_BY = 0.204043, CONST_XYZ2RGB_BZ = 1.057311;
extern const unsigned short int CONST_XYZ2RGBaddR = 0, CONST_XYZ2RGBaddG = 0, CONST_XYZ2RGBaddB = 0;
extern const int CONST_XYZ2RGBOffsetR = 6711, CONST_XYZ2RGBOffsetG = -1694, CONST_XYZ2RGBOffsetB = -2985; // For 16s formats

extern const double CONST_LUV_Lmin = 0.0,    CONST_LUV_Lmax = 100.0;
extern const double CONST_LUV_Umin = -134.0, CONST_LUV_Umax = 220.0;
extern const double CONST_LUV_Vmin = -140.0, CONST_LUV_Vmax = 116.0;//122.0;
extern const double CONST_LUV_Un = 0.197833036997, CONST_LUV_Vn = 0.468330474353;

extern const double CONST_BGR2Lab_ftConst = 0.008856, CONST_BGR2Lab_ftCoeff = 7.787;
extern const double CONST_BGR2Lab_k = 903.3;
extern const double CONST_Lab_Xn = 0.950455, CONST_Lab_Yn = 1.000000, CONST_Lab_Zn = 1.088754;

extern const double CONST_RGB2YCC_YR     =    0.299, CONST_RGB2YCC_YG = 0.587, CONST_RGB2YCC_YB = 0.114;
extern const double CONST_RGB2YCC_C1R    =    0.299, CONST_RGB2YCC_C1G = 0.587, CONST_RGB2YCC_C1B = 0.886;
extern const double CONST_RGB2YCC_C2R    =    0.701, CONST_RGB2YCC_C2G = 0.587, CONST_RGB2YCC_C2B = 0.114;
extern const double CONST_RGB2YCC_YConst = 1.000 / 1.402, CONST_RGB2YCC_C1Const = 111.4 / 255.0, 
                    CONST_RGB2YCC_C2Const = 135.64 / 255.0;
extern const double CONST_YCC_C1Off = 156.0 / 255.0, CONST_YCC_C2Off = 137.0 / 255.0;

extern const double CONST_YCC2RGB_Y     =    1.3584;
extern const double CONST_YCC2RGB_C1    =    2.2179, CONST_YCC2RGB_GC1 = 0.194;
extern const double CONST_YCC2RGB_C2    =    1.8215, CONST_YCC2RGB_GC2 = 0.509;


#define SHIFT_VAL 16                    // 2^4
#define SET_16U(           val       ) (Fw16u)val
#define SET_16U_SHIFT_15L( val       ) (Fw16u)(32768*val)
#define SET_16U_SHIFT_13L( val       ) (Fw16u)(8192*val)
#define SET_16U_MUL_VAL(   val, mult ) (Fw16u)(val*mult)

extern const CMCDat CMCConstants[CF_MAXConv] = 
{
    {CF_RGBToYUV,        {SET_16U( CONST_RGB2YUVsubR ), SET_16U( CONST_RGB2YUVsubG ), SET_16U( CONST_RGB2YUVsubB )},
    {{ SET_16U_SHIFT_15L( CONST_RGB2YUV_YR ), SET_16U_SHIFT_15L( CONST_RGB2YUV_YG ), SET_16U_SHIFT_15L( CONST_RGB2YUV_YB )}, 
    {  SET_16U_SHIFT_15L( CONST_RGB2YUV_UR ), SET_16U_SHIFT_15L( CONST_RGB2YUV_UG ), SET_16U_SHIFT_15L( CONST_RGB2YUV_UB )},
    {  SET_16U_SHIFT_15L( CONST_RGB2YUV_VR ), SET_16U_SHIFT_15L( CONST_RGB2YUV_VG ), SET_16U_SHIFT_15L( CONST_RGB2YUV_VB )}},
    {SET_16U_MUL_VAL( CONST_RGB2YUVaddY, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_RGB2YUVaddU, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_RGB2YUVaddV, SHIFT_VAL )}
    },
    {CF_YUVToRGB,        {SET_16U( CONST_YUV2RGBsubY ), SET_16U( CONST_YUV2RGBsubU ), SET_16U( CONST_YUV2RGBsubV )},
    {{ SET_16U_SHIFT_13L( CONST_YUV2RGB_RY ), SET_16U_SHIFT_13L( CONST_YUV2RGB_RU ), SET_16U_SHIFT_13L( CONST_YUV2RGB_RV )}, 
    {  SET_16U_SHIFT_13L( CONST_YUV2RGB_GY ), SET_16U_SHIFT_13L( CONST_YUV2RGB_GU ), SET_16U_SHIFT_13L( CONST_YUV2RGB_GV )},
    {  SET_16U_SHIFT_13L( CONST_YUV2RGB_BY ), SET_16U_SHIFT_13L( CONST_YUV2RGB_BU ), SET_16U_SHIFT_13L( CONST_YUV2RGB_BV )}},
    {SET_16U_MUL_VAL( CONST_YUV2RGBaddR, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_YUV2RGBaddG, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_YUV2RGBaddB, SHIFT_VAL ) }
    },
    {CF_RGBToYCbCr,    {SET_16U( CONST_RGB2YCbCrsubR ), SET_16U( CONST_RGB2YCbCrsubG ), SET_16U( CONST_RGB2YCbCrsubB )},
    {{ SET_16U_SHIFT_15L( CONST_RGB2YCbCr_YR  ), SET_16U_SHIFT_15L( CONST_RGB2YCbCr_YG  ), SET_16U_SHIFT_15L( CONST_RGB2YCbCr_YB  )}, 
    {  SET_16U_SHIFT_15L( CONST_RGB2YCbCr_CbR ), SET_16U_SHIFT_15L( CONST_RGB2YCbCr_CbG ), SET_16U_SHIFT_15L( CONST_RGB2YCbCr_CbB )},
    {  SET_16U_SHIFT_15L( CONST_RGB2YCbCr_CrR ), SET_16U_SHIFT_15L( CONST_RGB2YCbCr_CrG ), SET_16U_SHIFT_15L( CONST_RGB2YCbCr_CrB )}},
    {SET_16U_MUL_VAL( CONST_RGB2YCbCraddY, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_RGB2YCbCraddCb, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_RGB2YCbCraddCr, SHIFT_VAL )}
    },
    {CF_YCbCrToRGB,    {SET_16U( CONST_YCbCr2RGBsubY ), SET_16U( CONST_YCbCr2RGBsubCb ), SET_16U( CONST_YCbCr2RGBsubCr )},
    {{ SET_16U_SHIFT_13L( CONST_YCbCr2RGB_RY ), SET_16U_SHIFT_13L( CONST_YCbCr2RGB_RCb ), SET_16U_SHIFT_13L( CONST_YCbCr2RGB_RCr )}, 
    {  SET_16U_SHIFT_13L( CONST_YCbCr2RGB_GY ), SET_16U_SHIFT_13L( CONST_YCbCr2RGB_GCb ), SET_16U_SHIFT_13L( CONST_YCbCr2RGB_GCr )},
    {  SET_16U_SHIFT_13L( CONST_YCbCr2RGB_BY ), SET_16U_SHIFT_13L( CONST_YCbCr2RGB_BCb ), SET_16U_SHIFT_13L( CONST_YCbCr2RGB_BCr )}},
    {SET_16U_MUL_VAL( CONST_YCbCr2RGBaddR, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_YCbCr2RGBaddG, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_YCbCr2RGBaddB, SHIFT_VAL )}
    },
    {CF_RGBToXYZ,        {SET_16U( CONST_RGB2XYZsubR ), SET_16U( CONST_RGB2XYZsubG ), SET_16U( CONST_RGB2XYZsubB )},
    {{ SET_16U_SHIFT_15L( CONST_RGB2XYZ_XR ), SET_16U_SHIFT_15L( CONST_RGB2XYZ_XG ), SET_16U_SHIFT_15L( CONST_RGB2XYZ_XB )}, 
    {  SET_16U_SHIFT_15L( CONST_RGB2XYZ_YR ), SET_16U_SHIFT_15L( CONST_RGB2XYZ_YG ), SET_16U_SHIFT_15L( CONST_RGB2XYZ_YB )},
    {  SET_16U_SHIFT_15L( CONST_RGB2XYZ_ZR ), SET_16U_SHIFT_15L( CONST_RGB2XYZ_ZG ), SET_16U_SHIFT_15L( CONST_RGB2XYZ_ZB )}},
    {SET_16U_MUL_VAL(CONST_RGB2XYZaddX, SHIFT_VAL ), 
     SET_16U_MUL_VAL(CONST_RGB2XYZaddY, SHIFT_VAL ), 
     SET_16U_MUL_VAL(CONST_RGB2XYZaddZ, SHIFT_VAL ) }
    },
    {CF_XYZToRGB,        {SET_16U( CONST_XYZ2RGBsubX ), SET_16U( CONST_XYZ2RGBsubY ), SET_16U( CONST_XYZ2RGBsubZ )},
    {{ SET_16U_SHIFT_13L( CONST_XYZ2RGB_RX ), SET_16U_SHIFT_13L( CONST_XYZ2RGB_RY ), SET_16U_SHIFT_13L( CONST_XYZ2RGB_RZ )}, 
    {  SET_16U_SHIFT_13L( CONST_XYZ2RGB_GX ), SET_16U_SHIFT_13L( CONST_XYZ2RGB_GY ), SET_16U_SHIFT_13L( CONST_XYZ2RGB_GZ )},
    {  SET_16U_SHIFT_13L( CONST_XYZ2RGB_BX ), SET_16U_SHIFT_13L( CONST_XYZ2RGB_BY ), SET_16U_SHIFT_13L( CONST_XYZ2RGB_BZ )}},
    {SET_16U_MUL_VAL( CONST_XYZ2RGBaddR, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_XYZ2RGBaddG, SHIFT_VAL ), 
     SET_16U_MUL_VAL( CONST_XYZ2RGBaddB, SHIFT_VAL )}
    },
    {CF_RGBToLUV,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_LUVToRGB,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_BGRToLab,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_LabToBGR,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_RGBToYCC,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_YCCToRGB,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_RGBToHLS,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_HLSToRGB,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_BGRToHLS,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_RGBToHSV,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
    {CF_HSVToRGB,      {0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
};

// Exp Constants
namespace EXP_TABLES {

    SYS_FORCEALIGN_16 extern const Fw8u exp_8u_tbl[15][9] = 
    {
        {128, 255, 255, 255, 255, 255, 255, 255, 255},        // Factor -7
        { 64, 174, 255, 255, 255, 255, 255, 255, 255},        // Factor -6
        { 32,  87, 236, 255, 255, 255, 255, 255, 255},        // Factor -5
        { 16,  43, 118, 255, 255, 255, 255, 255, 255},        // Factor -4
        {  8,  22,  59, 161, 255, 255, 255, 255, 255},        // Factor -3
        {  4,  11,  30,  80, 218, 255, 255, 255, 255},        // Factor -2
        {  2,   5,  15,  40, 109, 255, 255, 255, 255},        // Factor -1
        {  1,   3,   7,  20,  55, 148, 255, 255, 255},        // Factor 0
        {  1,   1,   4,  10,  27,  74, 202, 255, 255},        // Factor 1
        {  0,   1,   2,   5,  14,  37, 101, 255, 255},        // Factor 2
        {  0,   1,   3,   7,  19,  50, 137, 255, 255},        // Factor 3
        {  0,   1,   3,   9,  25,  69, 186, 255, 255},        // Factor 4
        {  0,   1,   2,   5,  13,  34,  93, 253, 255},        // Factor 5
        {  0,   1,   2,   6,  17,  47, 127, 255, 255},        // Factor 6
        {  0,   1,   3,   9,  23,  63, 172, 255, 255}         // Factor 7
    };

    SYS_FORCEALIGN_16 extern const Fw16s exp_16s_tbl[21][14] = 
    { 
        { 0, 1, 3, 7, 19, 51, 139, 377, 1024, 2784, 7566,  20568, 32767,  32767 },  //scale = -10
        { 0, 1, 3, 9, 25, 69, 188, 512, 1392, 3783, 10284, 27954, 32767,  32767 },  //scale = -9
        { 0, 1, 2, 5, 13, 35,  94, 256,  696, 1892, 5142,  13977, 32767,  32767 },  //scale = -8
        { 0, 1, 2, 6, 17, 47, 128, 348,  946, 2571, 6989,  18997, 32767,  32767 },  //scale = -7
        { 0, 1, 3, 9, 24, 64, 174, 473, 1285, 3494, 9498,  25819, 32767,  32767 },  //scale = -6
        { 0, 1, 2, 4, 12, 32,  87, 236,  643, 1747, 4749,  12910, 32767,  32767 },  //scale = -5
        { 0, 1, 2, 6, 16, 43, 118, 321,  874, 2375, 6455,  17546, 32767,  32767 },  //scale = -4
        { 0, 1, 3, 8, 22, 59, 161, 437, 1187, 3227, 8773,  23848, 32767,  32767 },  //scale = -3
        { 0, 1, 1, 4, 11, 30,  80, 218,  594, 1614, 4387,  11924, 32412,  32767 },  //scale = -2
        { 0, 1, 2, 5, 15, 40, 109, 297,  807, 2193, 5962,  16206, 32767,  32767 },  //scale = -1
        { 0, 1, 3, 7, 20, 55, 148, 403, 1097, 2981, 8103,  22026, 32767,  32767 },  //scale = 0
        { 0, 1, 1, 4, 10, 27,  74, 202,  548, 1490, 4052,  11013, 29937,  32767 },  //scale = 1
        { 0, 1, 2, 5, 14, 37, 101, 274,  745, 2026, 5507,  14969, 32767,  32767 },  //scale = 2
        { 0, 1, 3, 7, 19, 50, 137, 373, 1013, 2753, 7484,  20344, 32767,  32767 },  //scale = 3
        { 0, 1, 3, 9, 25, 69, 186, 506, 1377, 3742, 10172, 27651, 32767,  32767 },  //scale = 4
        { 0, 1, 2, 5, 13, 34,  93, 253,  688, 1871, 5086,  13825, 32767,  32767 },  //scale = 5
        { 0, 1, 2, 6, 17, 47, 127, 344,  936, 2543, 6913,  18791, 32767,  32767 },  //scale = 6
        { 0, 1, 3, 9, 23, 63, 172, 468, 1272, 3456, 9395,  25539, 32767,  32767 },  //scale = 7
        { 0, 1, 2, 4, 12, 32,  86, 234,  636, 1728, 4698,  12770, 32767,  32767 },  //scale = 8
        { 0, 1, 2, 6, 16, 43, 117, 318,  864, 2349, 6385,  17356, 32767,  32767 },  //scale = 9
        { 0, 1, 3, 8, 22, 58, 159, 432, 1174, 3192, 8678,  23589, 32767,  32767 },  //scale = 10
    };
    
    
    SYS_FORCEALIGN_16 extern const float exp_32s_tbl[32] = 
    {
        1.0000001F    ,    // 0
        2.71828182846F,    7.38905609893F,    20.0855369232F,    54.5981500331F,    // 1 to 4
        148.413159103F,    403.428793493F,    1096.63315843F,    2980.95798704F,    // 5 to 8
        8103.08392758F,    22026.4657948F,    59874.1417152F,    162754.791419F,    // 9 - 12
        442413.392009F,    1202604.28416F,    3269017.37247F,    8886110.52051F,    // 13 - 16
        24154952.7536F,    65659969.1373F,    178482300.963F,     485165195.41F,    // 17 - 20
        1318815734.48F,    3584912846.13F,    9744803446.25F,    26489122129.8F,    // 21 - 24
    };
    
    SYS_FORCEALIGN_16 extern const Fw64s exp_64s_tbl[64] =
    {
        1                   , 2                   , 7                    , 20                   ,    //0-3
        54                  , 148                 , 403                  , 1096                 ,    //4-7
        2980LL              , 8103LL              , 22026LL              , 59874LL              ,    //8-11
        162755LL            , 442413LL            , 1202604LL            , 3269017LL            ,    //12-15
        8886111LL           , 24154953LL          , 65659969LL           , 178482301LL          ,    //16-19
        485165195LL         , 1318815734LL        , 3584912846LL         , 9744803446LL         ,    //20-23
        26489122130LL       , 72004899337LL       , 195729609429LL       , 532048240602LL       ,    //24-27
        1446257064291LL     , 3931334297144LL     , 10686474581524LL     , 29048849665247LL     ,    //28-31
        78962960182681LL    , 214643579785916LL   , 583461742527455LL    , 1586013452313431LL   ,    //32-35
        4311231547115195LL  , 11719142372802611LL/*2*/, 31855931757113756LL, 86593400423993747LL,    //36-39
        235385266837019985LL, 639843493530054949LL, 1739274941520501047LL, 4727839468229346561LL,    //40-43
        0x7fffffffffffffffLL, 0x7fffffffffffffffLL, 0x7fffffffffffffffLL , 0x7fffffffffffffffLL ,    //44-47
        0x7fffffffffffffffLL, 0x7fffffffffffffffLL, 0x7fffffffffffffffLL , 0x7fffffffffffffffLL ,    //48-
        0x7fffffffffffffffLL, 0x7fffffffffffffffLL, 0x7fffffffffffffffLL , 0x7fffffffffffffffLL ,    //52-
        0x7fffffffffffffffLL, 0x7fffffffffffffffLL, 0x7fffffffffffffffLL , 0x7fffffffffffffffLL ,    //56-
        0x7fffffffffffffffLL, 0x7fffffffffffffffLL, 0x7fffffffffffffffLL , 0x7fffffffffffffffLL ,    //60-63
    };

    SYS_FORCEALIGN_16 extern const double exp_64s_flt_tbl[64] = 
    {
        0.049787068367, 0.135335283237, 0.367879441171, 1.0,                //-3 to 0
        2.71828182846 , 7.38905609893 , 20.0855369232 , 54.5981500331,      // 1 to 4
        148.413159103 , 403.428793493 , 1096.63315843 , 2980.95798704,      // 5 to 8
        8103.08392758 , 22026.4657948 , 59874.1417152 , 162754.791419,      // 9 - 12
                                 442413.392009,               1202604.284164776777749,
                       3269017.372472110639301,               8886110.520507872636763,
                      24154952.753575298214775,              65659969.137330511138786,
                     178482300.963187260844910,             485165195.409790277969106,
                    1318815734.483214697209998,            3584912846.131591561681159,
                    9744803446.248902600034632,           26489122129.843472294139162,
                   72004899337.385872524161351,          195729609428.838764269776397,
                  532048240601.798616683747304,         1446257064291.475173677047422,
                 3931334297144.042074388620580,        10686474581524.462146990468650,
                29048849665247.425231085682111,        78962960182680.695160978022635,
               214643579785916.064624297761531,       583461742527454.881402902734610,
              1586013452313430.728129644625774,      4311231547115195.227113422292856,
             11719142372802611.308772939791190,     31855931757113756.220328671701298,
             86593400423993746.953606932719264,    235385266837019985.407899910749034,
            639843493530054949.222663403515570,   1739274941520501047.394681303611235,
           4727839468229346561.474457562744280,  12851600114359308275.809299632143099,
          34934271057485095348.034797233406099,  94961194206024488745.133649117118323,
         258131288619006739623.285800215273380, 701673591209763173865.471599886117405,
        1907346572495099690525.099840953848447,                                    -1,    //e(49), 
        -1, -1 , -1, -1, -1, -1, -1, -1, -1, -1
    };


  SYS_FORCEALIGN_16 extern const double two_to_jby32_lead_64f[32] = {
        1, // 3ff00000 00000000
        1.0218971486541050808,    // 0x3FF059B0D3158540 ,
        1.0442737824274104241,    // 0x3FF0B5586CF98900 ,
        1.0671404006768199224,    // 0x3FF11301D0125B40 ,
        1.090507732665244589 ,    // 0x3FF172B83C7D5140 ,
        1.1143867425958831063,    // 0x3FF1D4873168B980 ,
        1.1387886347566791301,    // 0x3FF2387A6E756200 ,
        1.163724858777570148 ,    // 0x3FF29E9DF51FDEC0 ,
        1.189207115002716364 ,    // 0x3FF306FE0A31B700 ,
        1.2152473599804665128,    // 0x3FF371A7373AA9C0 ,
        1.2418578120734764525,    // 0x3FF3DEA64C123400 ,
        1.2690509571917232279,    // 0x3FF44E0860618900 ,
        1.2968395546510009808,    // 0x3FF4BFDAD5362A00 ,
        1.3252366431597408791,    // 0x3FF5342B569D4F80 ,
        1.3542555469368835475,    // 0x3FF5AB07DD485400 ,
        1.3839098819638309124,    // 0x3FF6247EB03A5580 ,
        1.4142135623730922589,    // 0x3FF6A09E667F3BC0 ,
        1.445180806977035104 ,    // 0x3FF71F75E8EC5F40 ,
        1.4768261459394977919,    // 0x3FF7A11473EB0180 ,
        1.5091644275934186226,    // 0x3FF82589994CCE00 ,
        1.5422108254079347489,    // 0x3FF8ACE5422AA0C0 ,
        1.5759808451078782809,    // 0x3FF93737B0CDC5C0 ,
        1.6104903319492507308,    // 0x3FF9C49182A3F080 ,
        1.6457554781539585065,    // 0x3FFA5503B23E2540 ,
        1.6817928305074190121,    // 0x3FFAE89F995AD380 ,
        1.7186192981224763798,    // 0x3FFB7F76F2FB5E40 ,
        1.7562521603732932363,    // 0x3FFC199BDD855280 ,
        1.7947090750030980644,    // 0x3FFCB720DCEF9040 ,
        1.8340080864093408763,    // 0x3FFD5818DCFBA480 ,
        1.8741676341102930792,    // 0x3FFDFC97337B9B40 ,
        1.9152065613971416269,    // 0x3FFEA4AFA2A490C0 ,
        1.9571441241754001794,    // 0x3FFF50765B6E4540 ,
    };
    SYS_FORCEALIGN_16 extern const double two_to_jby32_trail_64f[32] = {
        0, // 00000000 00000000
        1.1597411706391361837e-14,    // 0x3D0A1D73E2A475B4
        3.4161879709308491346e-15,    // 0x3CEEC5317256E308
        3.6957597440571163423e-15,    // 0x3CF0A4EBBF1AED93
        1.3070163869778723193e-14,    // 0x3D0D6E6FBE462876
        9.4299761914197699096e-15,    // 0x3D053C02DC0144C8
        1.2523626002562007491e-14,    // 0x3D0C3360FD6D8E0B
        7.3657640108952735779e-15,    // 0x3D009612E8AFAD12
        4.7027568557403141035e-15,    // 0x3CF52DE8D5A46306
        2.3653643472485295323e-15,    // 0x3CE54E28AA05E8A9
        7.5960968433694342619e-15,    // 0x3D011ADA0911F09F
        9.9946751537577509698e-15,    // 0x3D068189B7A04EF8
        8.6851220948711086338e-15,    // 0x3D038EA1CBD7F621
        4.1550189774967398395e-16,    // 0x3CBDF0A83C49D86A
        9.1808382857243129714e-15,    // 0x3D04AC64980A8C8F
        1.0425179080372087638e-15,    // 0x3CD2C7C3E81BF4B7
        2.7899069308908777473e-15,    // 0x3CE921165F626CDD
        1.1516081874751687512e-14,    // 0x3D09EE91B8797785
        1.5194722889062912911e-15,    // 0x3CDB5F54408FDB37
        4.1172019608001656455e-15,    // 0x3CF28ACF88AFAB35
        6.074702681072821835e-15,    // 0x3CFB5BA7C55A192D
        8.205513465754879596e-15,    // 0x3D027A280E1F92A0
        3.5774208713702990206e-15,    // 0x3CF01C7C46B071F3
        6.3380367436891598263e-15,    // 0x3CFC8B424491CAF8
        1.0073997321832223817e-14,    // 0x3D06AF439A68BB99
        1.5357984302925880313e-15,    // 0x3CDBAA9EC206AD4F
        6.2468503448553655751e-15,    // 0x3CFC2220CB12A092
        9.1220562603541958323e-15,    // 0x3D048A81E5E8F4A5
        1.5871433067176753855e-15,    // 0x3CDC976816BAD9B8
        6.8221551185459294701e-15,    // 0x3CFEB968CAC39ED3
        5.666960267488854618e-15,    // 0x3CF9858F73A18F5E
        8.9607677910366677676e-17,    // 0x3C99D3E12DD8A18B
    };
}



// Trignometric

SYS_FORCEALIGN_16 extern const double atanhi_ds[] = 
{
  4.63647609000806093515e-01, // atan(0.5)hi 0x3FDDAC67, 0x0561BB4F
  4.63647609000806093515e-01, // atan(0.5)hi 0x3FDDAC67, 0x0561BB4F
  7.85398163397448278999e-01, // atan(1.0)hi 0x3FE921FB, 0x54442D18
  7.85398163397448278999e-01, // atan(1.0)hi 0x3FE921FB, 0x54442D18
  9.82793723247329054082e-01, // atan(1.5)hi 0x3FEF730B, 0xD281F69B
  9.82793723247329054082e-01, // atan(1.5)hi 0x3FEF730B, 0xD281F69B
  1.57079632679489655800e+00, // atan(inf)hi 0x3FF921FB, 0x54442D18
  1.57079632679489655800e+00, // atan(inf)hi 0x3FF921FB, 0x54442D18
};

SYS_FORCEALIGN_16 extern const double atanlo_ds[] = 
{
  2.26987774529616870924e-17, // atan(0.5)lo 0x3C7A2B7F, 0x222F65E2
  2.26987774529616870924e-17, // atan(0.5)lo 0x3C7A2B7F, 0x222F65E2
  3.06161699786838301793e-17, // atan(1.0)lo 0x3C81A626, 0x33145C07
  3.06161699786838301793e-17, // atan(1.0)lo 0x3C81A626, 0x33145C07
  1.39033110312309984516e-17, // atan(1.5)lo 0x3C700788, 0x7AF0CBBD
  1.39033110312309984516e-17, // atan(1.5)lo 0x3C700788, 0x7AF0CBBD
  6.12323399573676603587e-17, // atan(inf)lo 0x3C91A626, 0x33145C07
  6.12323399573676603587e-17, // atan(inf)lo 0x3C91A626, 0x33145C07
};

SYS_FORCEALIGN_16 extern const double aT_ds[] = 
 {
  3.33333333333329318027e-01, // 0x3FD55555, 0x5555550D
  3.33333333333329318027e-01, // 0x3FD55555, 0x5555550D
 -1.99999999998764832476e-01, // 0xBFC99999, 0x9998EBC4
 -1.99999999998764832476e-01, // 0xBFC99999, 0x9998EBC4
  1.42857142725034663711e-01, // 0x3FC24924, 0x920083FF
  1.42857142725034663711e-01, // 0x3FC24924, 0x920083FF
 -1.11111104054623557880e-01, // 0xBFBC71C6, 0xFE231671
 -1.11111104054623557880e-01, // 0xBFBC71C6, 0xFE231671
  9.09088713343650656196e-02, // 0x3FB745CD, 0xC54C206E
  9.09088713343650656196e-02, // 0x3FB745CD, 0xC54C206E
 -7.69187620504482999495e-02, // 0xBFB3B0F2, 0xAF749A6D
 -7.69187620504482999495e-02, // 0xBFB3B0F2, 0xAF749A6D
  6.66107313738753120669e-02, // 0x3FB10D66, 0xA0D03D51
  6.66107313738753120669e-02, // 0x3FB10D66, 0xA0D03D51
 -5.83357013379057348645e-02, // 0xBFADDE2D, 0x52DEFD9A
 -5.83357013379057348645e-02, // 0xBFADDE2D, 0x52DEFD9A
  4.97687799461593236017e-02, // 0x3FA97B4B, 0x24760DEB
  4.97687799461593236017e-02, // 0x3FA97B4B, 0x24760DEB
 -3.65315727442169155270e-02, // 0xBFA2B444, 0x2C6A6C2F
 -3.65315727442169155270e-02, // 0xBFA2B444, 0x2C6A6C2F
  1.62858201153657823623e-02, // 0x3F90AD3A, 0xE322DA11
  1.62858201153657823623e-02, // 0x3F90AD3A, 0xE322DA11
};


SYS_FORCEALIGN_16 extern const int xmmDatad[] = 
{
0x00000000, 0x3fdc0000, 0x00000000,0x3fdc0000,
0x00000000, 0x44100000, 0x00000000,0x44100000,
0x00000000, 0x7fffffff, 0x00000000,0x7fffffff
};



SYS_FORCEALIGN_16 extern const float atanhi_fs[] = 
{
  4.6364760399e-01F, // atan(0.5)hi 0x3eed6338 
  4.6364760399e-01F, // atan(0.5)hi 0x3eed6338 
  4.6364760399e-01F, // atan(0.5)hi 0x3eed6338 
  4.6364760399e-01F, // atan(0.5)hi 0x3eed6338 
  7.8539812565e-01F, // atan(1.0)hi 0x3f490fda 
  7.8539812565e-01F, // atan(1.0)hi 0x3f490fda 
  7.8539812565e-01F, // atan(1.0)hi 0x3f490fda 
  7.8539812565e-01F, // atan(1.0)hi 0x3f490fda 
  9.8279368877e-01F, // atan(1.5)hi 0x3f7b985e 
  9.8279368877e-01F, // atan(1.5)hi 0x3f7b985e 
  9.8279368877e-01F, // atan(1.5)hi 0x3f7b985e 
  9.8279368877e-01F, // atan(1.5)hi 0x3f7b985e 
  1.5707962513e+00F, // atan(inf)hi 0x3fc90fda 
  1.5707962513e+00F, // atan(inf)hi 0x3fc90fda 
  1.5707962513e+00F, // atan(inf)hi 0x3fc90fda 
  1.5707962513e+00F, // atan(inf)hi 0x3fc90fda 
};

SYS_FORCEALIGN_16 extern const float atanlo_fs[] = 
{
  5.0121582440e-09F, // atan(0.5)lo 0x31ac3769
  5.0121582440e-09F, // atan(0.5)lo 0x31ac3769
  5.0121582440e-09F, // atan(0.5)lo 0x31ac3769
  5.0121582440e-09F, // atan(0.5)lo 0x31ac3769
  3.7748947079e-08F, // atan(1.0)lo 0x33222168
  3.7748947079e-08F, // atan(1.0)lo 0x33222168
  3.7748947079e-08F, // atan(1.0)lo 0x33222168
  3.7748947079e-08F, // atan(1.0)lo 0x33222168
  3.4473217170e-08F, // atan(1.5)lo 0x33140fb4
  3.4473217170e-08F, // atan(1.5)lo 0x33140fb4
  3.4473217170e-08F, // atan(1.5)lo 0x33140fb4
  3.4473217170e-08F, // atan(1.5)lo 0x33140fb4
  7.5497894159e-08F, // atan(inf)lo 0x33a22168
  7.5497894159e-08F, // atan(inf)lo 0x33a22168
  7.5497894159e-08F, // atan(inf)lo 0x33a22168
  7.5497894159e-08F, // atan(inf)lo 0x33a22168
};

SYS_FORCEALIGN_16 extern const float aT_fs[] = 
{
  3.3333334327e-01F, // 0x3eaaaaaa
  3.3333334327e-01F, // 0x3eaaaaaa
  3.3333334327e-01F, // 0x3eaaaaaa
  3.3333334327e-01F, // 0x3eaaaaaa
 -2.0000000298e-01F, // 0xbe4ccccd
 -2.0000000298e-01F, // 0xbe4ccccd
 -2.0000000298e-01F, // 0xbe4ccccd
 -2.0000000298e-01F, // 0xbe4ccccd
  1.4285714924e-01F, // 0x3e124925
  1.4285714924e-01F, // 0x3e124925
  1.4285714924e-01F, // 0x3e124925
  1.4285714924e-01F, // 0x3e124925
 -1.1111110449e-01F, // 0xbde38e38
 -1.1111110449e-01F, // 0xbde38e38
 -1.1111110449e-01F, // 0xbde38e38
 -1.1111110449e-01F, // 0xbde38e38
  9.0908870101e-02F, // 0x3dba2e6e
  9.0908870101e-02F, // 0x3dba2e6e
  9.0908870101e-02F, // 0x3dba2e6e
  9.0908870101e-02F, // 0x3dba2e6e
 -7.6918758452e-02F, // 0xbd9d8795
 -7.6918758452e-02F, // 0xbd9d8795
 -7.6918758452e-02F, // 0xbd9d8795
 -7.6918758452e-02F, // 0xbd9d8795
  6.6610731184e-02F, // 0x3d886b35
  6.6610731184e-02F, // 0x3d886b35
  6.6610731184e-02F, // 0x3d886b35
  6.6610731184e-02F, // 0x3d886b35
 -5.8335702866e-02F, // 0xbd6ef16b
 -5.8335702866e-02F, // 0xbd6ef16b
 -5.8335702866e-02F, // 0xbd6ef16b
 -5.8335702866e-02F, // 0xbd6ef16b
  4.9768779427e-02F, // 0x3d4bda59
  4.9768779427e-02F, // 0x3d4bda59
  4.9768779427e-02F, // 0x3d4bda59
  4.9768779427e-02F, // 0x3d4bda59
 -3.6531571299e-02F, // 0xbd15a221
 -3.6531571299e-02F, // 0xbd15a221
 -3.6531571299e-02F, // 0xbd15a221
 -3.6531571299e-02F, // 0xbd15a221
  1.6285819933e-02F, // 0x3c8569d7
  1.6285819933e-02F, // 0x3c8569d7
  1.6285819933e-02F, // 0x3c8569d7
  1.6285819933e-02F, // 0x3c8569d7
 };



SYS_FORCEALIGN_16 extern const int xmmDataf[] = 
{
0x3ee00000, 0x3ee00000, 0x3ee00000,0x3ee00000,
0x50800000, 0x50800000, 0x50800000,0x50800000,
0x7fffffff, 0x7fffffff, 0x7fffffff,0x7fffffff
};

SYS_FORCEALIGN_16 extern const double Atan2d_constants_d[] = 
{
3.1415926535897932384626433832795 , 3.1415926535897932384626433832795 ,
0.78539816339744830961566084581988, 0.78539816339744830961566084581988,
2.3561944901923449288469825374596 , 2.3561944901923449288469825374596 ,
3.1415926535897932384626433832795 , 3.1415926535897932384626433832795 ,
1.3846264338327950288419716939931e-16,1.3846264338327950288419716939931e-16,
0.0,0.0
};
SYS_FORCEALIGN_16 extern const int Atan2d_constants_i[] = 
{
0x7ff00000,0x7ff00000,0x7ff00000,0x7ff00000,
-60,-60,-60,-60
};



SYS_FORCEALIGN_16 extern const float Atan2f_constants_f[] = 
{
3.1415926535897932384626433832795F ,3.1415926535897932384626433832795F ,3.1415926535897932384626433832795F ,3.1415926535897932384626433832795F ,
0.78539816339744830961566084581988F,0.78539816339744830961566084581988F,0.78539816339744830961566084581988F,0.78539816339744830961566084581988F,
2.3561944901923449288469825374596F ,2.3561944901923449288469825374596F ,2.3561944901923449288469825374596F ,2.3561944901923449288469825374596F ,
3.1415926535897932384626433832795F ,3.1415926535897932384626433832795F ,3.1415926535897932384626433832795F ,3.1415926535897932384626433832795F ,
1.3846264338327950288419716939931e-16F,1.3846264338327950288419716939931e-16F,1.3846264338327950288419716939931e-16F,1.3846264338327950288419716939931e-16F,
0.0,0.0,0.0,0.0
};
SYS_FORCEALIGN_16 extern const int Atan2f_constants_i[] = 
{
0x00800000, 0x00800000, 0x00800000, 0x00800000,
0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
-60,-60,-60,-60
};



// used by scalbn
extern const double
two54   =  1.80143985094819840000e+16,  /* 0x43500000, 0x00000000 */
twom54  =  5.55111512312578270212e-17,  /* 0x3C900000, 0x00000000 */
huge   = 1.0e+300,
tiny   = 1.0e-300;

// used by kernel_remainder pi_o_2
extern const int 
init_jk[] = {2,3,4,6}; /* initial value for jk */

extern const double 
PIo2[] = {
1.57079625129699707031e+00,				/* 0x3FF921FB, 0x40000000 */
7.54978941586159635335e-08,				/* 0x3E74442D, 0x00000000 */
5.39030252995776476554e-15,				/* 0x3CF84698, 0x80000000 */
3.28200341580791294123e-22,				/* 0x3B78CC51, 0x60000000 */
1.27065575308067607349e-29,				/* 0x39F01B83, 0x80000000 */
1.22933308981111328932e-36,				/* 0x387A2520, 0x40000000 */
2.73370053816464559624e-44,				/* 0x36E38222, 0x80000000 */
2.16741683877804819444e-51,				/* 0x3569F31D, 0x00000000 */
};

extern const double 
zero   = 0.0,
one    = 1.0,
two24   =  1.67772160000000000000e+07,  /* 0x41700000, 0x00000000 */
twon24  =  5.96046447753906250000e-08;  /* 0x3E700000, 0x00000000 */

// used by ieee754_remainder_pi_o_2
/*
 * Table of constants for 2/pi, 396 Hex digits (476 decimal) of 2/pi */
extern const int 
two_over_pi[] = {
0xA2F983, 0x6E4E44, 0x1529FC, 0x2757D1, 0xF534DD, 0xC0DB62,0x95993C, 0x439041, 0xFE5163, 0xABDEBB, 0xC561B7, 0x246E3A,0x424DD2, 0xE00649, 0x2EEA09, 0xD1921C, 0xFE1DEB, 0x1CB129,0xA73EE8, 0x8235F5, 0x2EBB44, 0x84E99C, 0x7026B4, 0x5F7E41,0x3991D6, 0x398353, 0x39F49C, 0x845F8B, 0xBDF928, 0x3B1FF8,0x97FFDE, 0x05980F, 0xEF2F11, 0x8B5A0A, 0x6D1F6D, 0x367ECF,0x27CB09, 0xB74F46, 0x3F669E, 0x5FEA2D, 0x7527BA, 0xC7EBE5,0xF17B3D, 0x0739F7, 0x8A5292, 0xEA6BFB, 0x5FB11F, 0x8D5D08,0x560330, 0x46FC7B, 0x6BABF0, 0xCFBC20, 0x9AF436, 0x1DA9E3,0x91615E, 0xE61B08, 0x659985, 0x5F14A0, 0x68408D, 0xFFD880,0x4D7327, 0x310606, 0x1556CA, 0x73A8C9, 0x60E27B, 0xC08C6B
};

extern const int 
npio2_hw[] = {
0x3FF921FB, 0x400921FB, 0x4012D97C, 0x401921FB, 0x401F6A7A, 0x4022D97C,
0x4025FDBB, 0x402921FB, 0x402C463A, 0x402F6A7A, 0x4031475C, 0x4032D97C,
0x40346B9C, 0x4035FDBB, 0x40378FDB, 0x403921FB, 0x403AB41B, 0x403C463A,
0x403DD85A, 0x403F6A7A, 0x40407E4C, 0x4041475C, 0x4042106C, 0x4042D97C,
0x4043A28C, 0x40446B9C, 0x404534AC, 0x4045FDBB, 0x4046C6CB, 0x40478FDB,
0x404858EB, 0x404921FB,
};

/*
 * invpio2:  53 bits of 2/pi
 * pio2_1:   first  33 bit of pi/2
 * pio2_1t:  pi/2 - pio2_1
 * pio2_2:   second 33 bit of pi/2
 * pio2_2t:  pi/2 - (pio2_1+pio2_2)
 * pio2_3:   third  33 bit of pi/2
 * pio2_3t:  pi/2 - (pio2_1+pio2_2+pio2_3)
 */

extern const double
//zero =  0.00000000000000000000e+00,   /* 0x00000000, 0x00000000 */
half =  5.00000000000000000000e-01,     /* 0x3FE00000, 0x00000000 */
//two24 =  1.67772160000000000000e+07,  /* 0x41700000, 0x00000000 */
invpio2 =  6.36619772367581382433e-01,  /* 0x3FE45F30, 0x6DC9C883 */
pio2_1  =  1.57079632673412561417e+00,  /* 0x3FF921FB, 0x54400000 */
pio2_1t =  6.07710050650619224932e-11,  /* 0x3DD0B461, 0x1A626331 */
pio2_2  =  6.07710050630396597660e-11,  /* 0x3DD0B461, 0x1A600000 */
pio2_2t =  2.02226624879595063154e-21,  /* 0x3BA3198A, 0x2E037073 */
pio2_3  =  2.02226624871116645580e-21,  /* 0x3BA3198A, 0x2E000000 */
pio2_3t =  8.47842766036889956997e-32;  /* 0x397B839A, 0x252049C1 */

// used by cos
extern const double
//one =  1.00000000000000000000e+00,    /* 0x3FF00000, 0x00000000 */
C1_d  = 4.16666666666666019037e-02,		/* 0x3FA55555, 0x5555554C */
C2_d  =-1.38888888888741095749e-03,		/* 0xBF56C16C, 0x16C15177 */
C3_d  = 2.48015872894767294178e-05,		/* 0x3EFA01A0, 0x19CB1590 */
C4_d  =-2.75573143513906633035e-07,		/* 0xBE927E4F, 0x809C52AD */
C5_d  = 2.08757232129817482790e-09,		/* 0x3E21EE9E, 0xBDB4B1C4 */
C6_d  =-1.13596475577881948265e-11;		/* 0xBDA8FAE9, 0xBE8838D4 */

// used by sin
extern const double
//half =  5.00000000000000000000e-01,   /* 0x3FE00000, 0x00000000 */
S1  =-1.66666666666666324348e-01,		/* 0xBFC55555, 0x55555549 */
S2  = 8.33333333332248946124e-03,		/* 0x3F811111, 0x1110F8A6 */
S3  =-1.98412698298579493134e-04,		/* 0xBF2A01A0, 0x19C161D5 */
S4  = 2.75573137070700676789e-06,		/* 0x3EC71DE3, 0x57B1FE7D */
S5  =-2.50507602534068634195e-08,		/* 0xBE5AE5E6, 0x8A2B9CEB */
S6  = 1.58969099521155010221e-10;		/* 0x3DE5D93A, 0x5ACFD57C */

// used by tan
extern const double 
xxx[] = {
3.33333333333334091986e-01,				/* 3FD55555, 55555563 */   
1.33333333333201242699e-01,				/* 3FC11111, 1110FE7A */
5.39682539762260521377e-02,				/* 3FABA1BA, 1BB341FE */
2.18694882948595424599e-02,				/* 3F9664F4, 8406D637 */
8.86323982359930005737e-03,				/* 3F8226E3, E96E8493 */
3.59207910759131235356e-03,				/* 3F6D6D22, C9560328 */
1.45620945432529025516e-03,				/* 3F57DBC8, FEE08315 */
5.88041240820264096874e-04,				/* 3F4344D8, F2F26501 */
2.46463134818469906812e-04,				/* 3F3026F7, 1A8D1068 */
7.81794442939557092300e-05,				/* 3F147E88, A03792A6 */
7.14072491382608190305e-05,				/* 3F12B80F, 32F0A7E9 */
-1.85586374855275456654e-05,			/* BEF375CB, DB605373 */
 2.59073051863633712884e-05,			/* 3EFB2A70, 74BF7AD4 */
1.00000000000000000000e+00,             /* 3FF00000, 00000000 */ /* one */   
7.85398163397448278999e-01,             /* 3FE921FB, 54442D18 */	/* pio4 */  
3.06161699786838301793e-17              /* 3C81A626, 33145C07 */	/* pio4lo */
};
#define one    xxx[13]
#define pio4   xxx[14]
#define pio4lo xxx[15]
#define T      xxx

// used by acos
extern const double
//one_d=  1.00000000000000000000e+00,   /* 0x3FF00000, 0x00000000 */
//pi_d =  3.14159265358979311600e+00,	/* 0x400921FB, 0x54442D18 */
pio2_hi_d =  1.57079632679489655800e+00,/* 0x3FF921FB, 0x54442D18 */
pio2_lo_d =  6.12323399573676603587e-17,/* 0x3C91A626, 0x33145C07 */
pS0_d =  1.66666666666666657415e-01,	/* 0x3FC55555, 0x55555555 */
pS1_d = -3.25565818622400915405e-01,	/* 0xBFD4D612, 0x03EB6F7D */
pS2_d =  2.01212532134862925881e-01,	/* 0x3FC9C155, 0x0E884455 */
pS3_d = -4.00555345006794114027e-02,	/* 0xBFA48228, 0xB5688F3B */
pS4_d =  7.91534994289814532176e-04,	/* 0x3F49EFE0, 0x7501B288 */
pS5_d =  3.47933107596021167570e-05,	/* 0x3F023DE1, 0x0DFDF709 */
qS1_d = -2.40339491173441421878e+00,	/* 0xC0033A27, 0x1C8A2D4B */
qS2_d =  2.02094576023350569471e+00,	/* 0x40002AE5, 0x9C598AC8 */
qS3_d = -6.88283971605453293030e-01,	/* 0xBFE6066C, 0x1B8D0159 */
qS4_d =  7.70381505559019352791e-02;	/* 0x3FB3B8C5, 0xB12E9282 */

extern const float
//one_f =  1.0000000000e+00F,			/* 0x3F800000 */
//pi_f =  3.1415925026e+00F,			/* 0x40490fda */
pio2_hi_f =  1.5707962513e+00F,			/* 0x3fc90fda */
pio2_lo_f =  7.5497894159e-08F,			/* 0x33a22168 */
pS0_f =  1.6666667163e-01F,				/* 0x3e2aaaab */
pS1_f = -3.2556581497e-01F,				/* 0xbea6b090 */
pS2_f =  2.0121252537e-01F,				/* 0x3e4e0aa8 */
pS3_f = -4.0055535734e-02F,				/* 0xbd241146 */
pS4_f =  7.9153501429e-04F,				/* 0x3a4f7f04 */
pS5_f =  3.4793309169e-05F,				/* 0x3811ef08 */
qS1_f = -2.4033949375e+00F,				/* 0xc019d139 */
qS2_f =  2.0209457874e+00F,				/* 0x4001572d */
qS3_f = -6.8828397989e-01F,				/* 0xbf303361 */
qS4_f =  7.7038154006e-02F;				/* 0x3d9dc62e */

// used by asin
extern const double
//huge_d =  1.000e+300,
pio4_hi_d =  7.85398163397448278999e-01;/* 0x3FE921FB, 0x54442D18 */

extern const float
//huge_f =  1.000e+30F,
pio4_hi_f =  7.8539812565e-01F;			/* 0x3f490fda */

// used by atan
SYS_FORCEALIGN_16 extern const double 
atanhi_d[] = {
0.46364760900080611621425623146121F,	/* atan(0.5)hi 0x3eed6338 */
0.78539816339744830961566084581988F,	/* atan(1.0)hi 0x3f490fda */
0.98279372324732906798571061101467F,	/* atan(1.5)hi 0x3f7b985e */
1.5707963267948966192313216916398F		/* atan(inf)hi 0x3fc90fda */
};

SYS_FORCEALIGN_16 extern const double 
atanlo_d[] = {
5.0121586562142562314612144020192e-9F,	/* atan(0.5)lo 0x31ac3769 */
-2.1855695000384339154180124278986e-8F,	/* atan(1.0)lo 0x33222168 */
-2.5131424592014289388985333985481e-8F,	/* atan(1.5)lo 0x33140fb4 */
-0.000000043711389980768678308361F		/* atan(inf)lo 0x33a22168 */
};
SYS_FORCEALIGN_16 extern const double 
aT_d[] = {
0.33333333333333333333333333333333F,	// 1/3
-2.0e-01F,								// 1/5
0.14285714285714285714285714285714F,	// 1/7	
-0.11111111111111111111111111111111F,	// 1/9
0.090909090909090909090909090909091F,	// ..
-0.076923076923076923076923076923077F,
0.066666666666666666666666666666667F,
-0.058823529411764705882352941176471F,
0.052631578947368421052631578947368F,
-0.047619047619047619047619047619048F,
0.043478260869565217391304347826087F
};

SYS_FORCEALIGN_16 extern const float 
atanhi_f[] = {
0.46364760900080611621425623146121F,	/* atan(0.5)hi 0x3eed6338 */
0.78539816339744830961566084581988F,	/* atan(1.0)hi 0x3f490fda */
0.98279372324732906798571061101467F,	/* atan(1.5)hi 0x3f7b985e */
1.5707963267948966192313216916398F		/* atan(inf)hi 0x3fc90fda */
};

SYS_FORCEALIGN_16 extern const float
atanlo_f[] = {
9.0008061162142562314612144020192e-9F,	/* atan(0.5)lo 0x31ac3769 */
-2.6602551690384339154180124278986e-8F,	/* atan(1.0)lo 0x33222168 */
-2.6752670932014289388985333985481e-8F,	/* atan(1.5)lo 0x33140fb4 */
-0.000000073205103380768678308361F		/* atan(inf)lo 0x33a22168 */
};
SYS_FORCEALIGN_16 extern const float
aT_f[] = {
0.33333333333333333333333333333333F,	// 1/3
-2.0e-01F,								// 1/5
0.14285714285714285714285714285714F,	// 1/7	
-0.11111111111111111111111111111111F,	// 1/9
0.090909090909090909090909090909091F,	// ..
-0.076923076923076923076923076923077F,
0.066666666666666666666666666666667F,
-0.058823529411764705882352941176471F,
0.052631578947368421052631578947368F,
-0.047619047619047619047619047619048F,
0.043478260869565217391304347826087F
};


// used by atan2
SYS_FORCEALIGN_16 extern const float  
huge_f = 1.0e30F,one_f = 1.0F;

SYS_FORCEALIGN_16 extern const double
huge_d = 1.0e300,one_d = 1.0;

SYS_FORCEALIGN_16 extern const float
pi_f      = 3.1415926535897932384626433832795F,
pi_o_4_f  = 0.78539816339744830961566084581988F,
pi3_o_4_f = 2.3561944901923449288469825374596F,
pi_hi_f   = 3.1415926535897932384626433832795F,
pi_lo_f   = 1.3846264338327950288419716939931e-16F;

SYS_FORCEALIGN_16 extern const double
pi_d      = 3.1415926535897932384626433832795,
pi_o_4_d  = 0.78539816339744830961566084581988,	
pi3_o_4_d = 2.3561944901923449288469825374596,							
pi_hi_d   = 3.1415926535897932384626433832795, 
pi_lo_d   = 1.3846264338327950288419716939931e-16;

// used by expm1
extern const double
//one_d           = 1.0,
//huge_d          = 1.0e+300,
tiny_d            = 1.0e-300,
o_threshold_d     = 7.09782712893383973096e+02,/* 0x40862E42, 0xFEFA39EF */
ln2_hi_d          = 6.93147180369123816490e-01,/* 0x3fe62e42, 0xfee00000 */
ln2_lo_d          = 1.90821492927058770002e-10,/* 0x3dea39ef, 0x35793c76 */
invln2_d          = 1.44269504088896338700e+00,/* 0x3ff71547, 0x652b82fe */

/* scaled coefficients related to expm1 */
Q1_d  =  -3.33333333333331316428e-02,			/* BFA11111 111110F4 */
Q2_d  =   1.58730158725481460165e-03,			/* 3F5A01A0 19FE5585 */
Q3_d  =  -7.93650757867487942473e-05,			/* BF14CE19 9EAADBB7 */
Q4_d  =   4.00821782732936239552e-06,			/* 3ED0CFCA 86E65239 */
Q5_d  =  -2.01099218183624371326e-07;			/* BE8AFDB7 6E09C32D */

//used by ieee754_exp
extern const double
halF_d[2] = {0.5,-0.5,},
twom1000_d= 9.33263618503218878990e-302,		/* 2**-1000=0x01700000,0*/
u_threshold_d= -7.45133219101941108420e+02,		/* 0xc0874910, 0xD52D3051 */
ln2HI_d[2]   ={ 6.93147180369123816490e-01,		/* 0x3fe62e42, 0xfee00000 */
             -6.93147180369123816490e-01,},		/* 0xbfe62e42, 0xfee00000 */
ln2LO_d[2]   ={ 1.90821492927058770002e-10,		/* 0x3dea39ef, 0x35793c76 */
             -1.90821492927058770002e-10,},		/* 0xbdea39ef, 0x35793c76 */
P1_d   =  1.66666666666666019037e-01,			/* 0x3FC55555, 0x5555553E */
P2_d   = -2.77777777770155933842e-03,			/* 0xBF66C16C, 0x16BEBD93 */
P3_d   =  6.61375632143793436117e-05,			/* 0x3F11566A, 0xAF25DE2C */
P4_d   = -1.65339022054652515390e-06,			/* 0xBEBBBD41, 0xC5D26BF1 */
P5_d   =  4.13813679705723846039e-08;			/* 0x3E663769, 0x72BEA4D0 */

// used by cosh
extern const double half_d=0.5;
extern const float half_f=0.5F;

// used by sinh
extern const double shuge_d = 1.0e307;
extern const float shuge_f = 1.0e37F;

// used by tanh
extern const double two_d = 2.0;
extern const float two_f=2.0;

// used by acosh
extern const float
//one_f           = 1.0F,
//huge_f          = 1.0e+30F,
tiny_f            = 1.0e-30F,
ln2_hi_f          = 6.9313812256e-01F,			/* 0x3f317180 */
ln2_lo_f          = 9.0580006145e-06F;			/* 0x3717f7d1 */
extern const double
ln2_d     = 6.93147180559945286227e-01;			/* 0x3FE62E42, 0xFEFA39EF */
extern const float
ln2_f     = 6.9314718246e-01F;					/* 0x3f317218 */

// used by log1p
extern const double
two54_d   =  1.80143985094819840000e+16,		/* 43500000 00000000 */
Lp1_d = 6.666666666666735130e-01,				/* 3FE55555 55555593 */
Lp2_d = 3.999999999940941908e-01,				/* 3FD99999 9997FA04 */
Lp3_d = 2.857142874366239149e-01,				/* 3FD24924 94229359 */
Lp4_d = 2.222219843214978396e-01,				/* 3FCC71C5 1D8E78AF */
Lp5_d = 1.818357216161805012e-01,				/* 3FC74664 96CB03DE */
Lp6_d = 1.531383769920937332e-01,				/* 3FC39A09 D078C69F */
Lp7_d = 1.479819860511658591e-01;				/* 3FC2F112 DF3E5244 */

extern const double zero_d = 0.0;

// used by iee754_log
extern const double
Lg1_d = 6.666666666666735130e-01,				/* 3FE55555 55555593 */
Lg2_d = 3.999999999940941908e-01,				/* 3FD99999 9997FA04 */
Lg3_d = 2.857142874366239149e-01,				/* 3FD24924 94229359 */
Lg4_d = 2.222219843214978396e-01,				/* 3FCC71C5 1D8E78AF */
Lg5_d = 1.818357216161805012e-01,				/* 3FC74664 96CB03DE */
Lg6_d = 1.531383769920937332e-01,				/* 3FC39A09 D078C69F */
Lg7_d = 1.479819860511658591e-01;				/* 3FC2F112 DF3E5244 */

// used by log1pf
extern const float
two25_f = 3.355443200e+07F,						/* 0x4c000000 */
Lp1_f = 6.6666668653e-01F,						/* 3F2AAAAB */
Lp2_f = 4.0000000596e-01F,						/* 3ECCCCCD */
Lp3_f = 2.8571429849e-01F,						/* 3E924925 */
Lp4_f = 2.2222198546e-01F,						/* 3E638E29 */
Lp5_f = 1.8183572590e-01F,						/* 3E3A3325 */
Lp6_f = 1.5313838422e-01F,						/* 3E1CD04F */
Lp7_f = 1.4798198640e-01F;						/* 3E178897 */

extern const float zero_f = 0.0;

// used by ieee754_logpf
extern const float
Lg1_f =      0.66666662693F,					/* 0xaaaaaa.0p-24 */
Lg2_f =      0.40000972152F,					/* 0xccce13.0p-25 */
Lg3_f =      0.28498786688F,					/* 0x91e9ee.0p-25 */
Lg4_f =      0.24279078841F;					/* 0xf89e26.0p-26 */

extern const Fw8u zigZagFwdOrder[80] =
{
	0,   1,  8, 16,  9,  2,  3, 10, 
	17, 24, 32, 25, 18, 11,  4,  5,
	12, 19, 26, 33, 40, 48, 41, 34, 
	27, 20, 13,  6,  7, 14, 21, 28,
	35, 42, 49, 56, 57, 50, 43, 36, 
	29, 22, 15, 23, 30, 37, 44, 51,
	58, 59, 52, 45, 38, 31, 39, 46, 
	53, 60, 61, 54, 47, 55, 62, 63,
	63, 63, 63, 63, 63, 63, 63, 63,
	63, 63, 63, 63, 63, 63, 63, 63
};

extern const Fw8u zigZagInvOrder[64] =
{
	 0,  1,  5,  6, 14, 15, 27, 28,
	 2,  4,  7, 13, 16, 26, 29, 42,
	 3,  8, 12, 17, 25, 30, 41, 43,
	 9, 11, 18, 24, 31, 40, 44, 53,
	10, 19, 23, 32, 39, 45, 52, 54,
	20, 22, 33, 38, 46, 51, 55, 60,
	21, 34, 37, 47, 50, 56, 59, 61,
	35, 36, 48, 49, 57, 58, 62, 63
};

extern SYS_FORCEALIGN_16 const Fw16s idct_weighting[] = {
	16384,	21407,	16384,	8867, 16384,	-8867,  16384, -21407,	//	w05 w04 w01 w00	w13 w12 w09 w08
	16384,	8867,	-16384,	-21407,	-16384,	21407,  16384,  -8867,	//	w07 w06 w03 w02	w15 w14 w11 w10
	22725,	19266,  19266,  -4520, 	12873,	-22725,	4520,	-12873,	//	w21 w20 w17 w16 w29 w28 w25 w24
	12873,	4520,	-22725, -12873, 4520,	19266,  19266,	-22725, //	w23 w22 w19 w18 w31 w30 w27 w26

	22725,  29692,  22725,  12299, 22725,	-12299, 22725,	-29692,
	22725,  12299,	-22725, -29692,	-22725,	29692,  22725,	-12299,
	31521,  26722,  26722,  -6270, 17855,	-31521, 6270,	-17855,
	17855,  6270,	-31521, -17855,	6270,	26722,  26722,	-31521,

	21407,  27969,  21407,  11585,  21407,	-11585, 21407,	-27969,
	21407,  11585,	-21407, -27969,	-21407, 27969,  21407,	-11585,
	29692,  25172,  25172,  -5906,  16819,	-29692, 5906,	-16819,
	16819,  5906,	-29692, -16819,	5906,	25172,  25172,	-29692,

	19266,  25172,  19266,  10426, 19266,	-10426, 19266,	-25172,	
	19266,  10426,	-19266, -25172,	-19266, 25172,  19266,	-10426,	
	26722,  22654,  22654,  -5315,  15137,	-26722, 5315,	-15137,	
	15137,  5315,	-26722, -15137, 5315,	22654,  22654,	-26722,

	13036,  13036,  13036,  13036,  13036,  13036,  13036,  13036, 
	27146,  27146,  27146,  27146,  27146,  27146,  27146,  27146,
	-21746, -21746, -21746, -21746, -21746, -21746, -21746, -21746, // tg * (2<<16) + 0.5
	-19195, -19195, -19195, -19195,-19195, -19195, -19195, -19195   //cos * (2<<16) + 0.5
}; 

extern SYS_FORCEALIGN_16 const Fw16s fdct_weighting[]=
{
	16384,  16384,  22725,  19266,  21407,   8867,  19266,  -4520,   // 04
	16384,  16384,  12873,   4520,	-8867, -21407, -22725, -12873,   
	16384, -16384,  12873, -22725,	 8867, -21407,   4520, -12873,   
	-16384,  16384,   4520,  19266,	21407,  -8867,  19266, -22725,   

	22725,  22725,  31521,  26722,  29692,  12299,  26722,  -6270,   // 17
	22725,  22725,  17855,   6270,  -12299, -29692, -31521, -17855,   
	22725, -22725,  17855, -31521,  12299, -29692,   6270, -17855,   
	-22725,  22725,   6270,  26722, 29692, -12299,  26722, -31521,   

	21407,  21407,  29692,  25172,  27969,  11585,  25172,  -5906,   // 26
	21407,  21407,  16819,   5906,  -11585, -27969, -29692, -16819,   
	21407, -21407,  16819, -29692,  11585, -27969,   5906, -16819,   
	-21407,  21407,   5906,  25172, 27969, -11585,  25172, -29692,   

	19266,  19266,  26722,  22654,  25172,  10426,  22654,  -5315,   //35
	19266,  19266,  15137,   5315,  -10426, -25172, -26722, -15137,   
	19266, -19266,  15137, -26722,  10426, -25172,   5315, -15137,   
	-19266,  19266,   5315,  22654, 25172, -10426,  22654, -26722,   

	13036,  13036,  13036,  13036,  13036,  13036,  13036,  13036, 
	27146,  27146,  27146,  27146,  27146,  27146,  27146,  27146,
	-21746, -21746, -21746, -21746, -21746, -21746, -21746, -21746, // tg * (2<<16) + 0.5
	23170,  23170,  23170,  23170,  23170,  23170,  23170,  23170   //cos * (2<<15) + 0.5
}; 

extern const float dct_Scale[64]=
{
	(float)1.000000, (float)0.720960, (float)0.765367, (float)0.850430, 
	(float)1.000000, (float)1.272759, (float)1.847759, (float)3.624510,
	(float)0.720960, (float)0.519783, (float)0.551799, (float)0.613126, 
	(float)0.720960, (float)0.917608, (float)1.332160, (float)2.613126,
	(float)0.765367, (float)0.551799, (float)0.585786, (float)0.650891, 
	(float)0.765367, (float)0.974127, (float)1.414214, (float)2.774080,
	(float)0.850430, (float)0.613126, (float)0.650891, (float)0.723231, 
	(float)0.850430, (float)1.082392, (float)1.571390, (float)3.082392,
	(float)1.000000, (float)0.720960, (float)0.765367, (float)0.850430,
	(float)1.000000, (float)1.272759, (float)1.847759, (float)3.624510,
	(float)1.272759, (float)0.917608, (float)0.974127, (float)1.082392,
	(float)1.272759, (float)1.619914, (float)2.351751, (float)4.613126,
	(float)1.847759, (float)1.332160, (float)1.414214, (float)1.571390,
	(float)1.847759, (float)2.351751, (float)3.414214, (float)6.697221,
	(float)3.624510, (float)2.613126, (float)2.774080, (float)3.082392,
	(float)3.624510, (float)4.613126, (float)6.697221, (float)13.137072
};

// Constants Used in Video

// used by ReconstructBlock
extern const unsigned int NUM_ROWS = 8;
extern const unsigned int NUM_COLS = 8;
extern const unsigned int NUM_ELEMS = NUM_ROWS * NUM_COLS;
extern const unsigned int DC_ELEM_INDEX = 0;

// used by AANIDCT
extern const float idct_coefficients[8][8] = {
    { 0.35355338F,      0.35355338F,      0.35355338F,      0.35355338F,      0.35355338F,      0.35355338F,      0.35355338F,      0.35355338F },
    {0.49039263F,      0.41573480F,      0.27778512F,     0.097545162F,    -0.097545162F,     -0.27778512F,     -0.41573480F,     -0.49039263F },
    {0.46193975F,     0.19134171F,     -0.19134171F,     -0.46193975F,     -0.46193975F,     -0.19134171F,      0.19134171F,      0.46193975F },
    {0.41573480F,    -0.097545162F,     -0.49039263F,     -0.27778512F,      0.27778512F,      0.49039263F,     0.097545162F,     -0.41573480F },
    {0.35355338F,     -0.35355338F,     -0.35355338F,      0.35355338F,      0.35355338F,     -0.35355338F,     -0.35355338F,      0.35355338F },
    {0.27778512F,     -0.49039263F,     0.097545162F,      0.41573480F,     -0.41573480F,    -0.097545162F,      0.49039263F,     -0.27778512F },
    {0.19134171F,     -0.46193975F,      0.46193975F,     -0.19134171F,     -0.19134171F,      0.46193975F,     -0.46193975F,      0.19134171F },
    {0.097545162F,     -0.27778512F,      0.41573480F,     -0.49039263F,      0.49039263F,     -0.41573480F,      0.27778512F,    -0.097545162F}
 };

// used by ReconstructDCTBlock
extern SYS_FORCEALIGN_16 const Fw16s non_intra_quantizer_matrix[128] = {
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16,
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16, 
16, 16, 16, 16, 16, 16, 16, 16
};

// used by H.264 Transform
//! Dequantization coefficients
extern SYS_FORCEALIGN_16 const int dequant_coef[6][4][4] = {
  {{10, 13, 10, 13},{ 13, 16, 13, 16},{10, 13, 10, 13},{ 13, 16, 13, 16}},
  {{11, 14, 11, 14},{ 14, 18, 14, 18},{11, 14, 11, 14},{ 14, 18, 14, 18}},
  {{13, 16, 13, 16},{ 16, 20, 16, 20},{13, 16, 13, 16},{ 16, 20, 16, 20}},
  {{14, 18, 14, 18},{ 18, 23, 18, 23},{14, 18, 14, 18},{ 18, 23, 18, 23}},
  {{16, 20, 16, 20},{ 20, 25, 20, 25},{16, 20, 16, 20},{ 20, 25, 20, 25}},
  {{18, 23, 18, 23},{ 23, 29, 23, 29},{18, 23, 18, 23},{ 23, 29, 23, 29}}
};

extern SYS_FORCEALIGN_16 const Fw16s dequant_coef16[6*4*4] = {
    10, 13, 10, 13, 13, 16, 13, 16, 10, 13, 10, 13, 13, 16, 13, 16,
    11, 14, 11, 14, 14, 18, 14, 18, 11, 14, 11, 14, 14, 18, 14, 18,
    13, 16, 13, 16, 16, 20, 16, 20, 13, 16, 13, 16, 16, 20, 16, 20,
    14, 18, 14, 18, 18, 23, 18, 23, 14, 18, 14, 18, 18, 23, 18, 23,
    16, 20, 16, 20, 20, 25, 20, 25, 16, 20, 16, 20, 20, 25, 20, 25,
    18, 23, 18, 23, 23, 29, 23, 29, 18, 23, 18, 23, 23, 29, 23, 29
};

extern SYS_FORCEALIGN_16 const Fw8u QP_SCALE_CR[52] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,
   12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
   28,29,29,30,31,32,32,33,34,34,35,35,36,36,37,37,
   37,38,38,38,39,39,39,39
};

extern const int quant_coef[6][4][4] = {
  {{13107, 8066,13107, 8066},{ 8066, 5243, 8066, 5243},{13107, 8066,13107, 8066},{ 8066, 5243, 8066, 5243}},
  {{11916, 7490,11916, 7490},{ 7490, 4660, 7490, 4660},{11916, 7490,11916, 7490},{ 7490, 4660, 7490, 4660}},
  {{10082, 6554,10082, 6554},{ 6554, 4194, 6554, 4194},{10082, 6554,10082, 6554},{ 6554, 4194, 6554, 4194}},
  {{ 9362, 5825, 9362, 5825},{ 5825, 3647, 5825, 3647},{ 9362, 5825, 9362, 5825},{ 5825, 3647, 5825, 3647}},
  {{ 8192, 5243, 8192, 5243},{ 5243, 3355, 5243, 3355},{ 8192, 5243, 8192, 5243},{ 5243, 3355, 5243, 3355}},
  {{ 7282, 4559, 7282, 4559},{ 4559, 2893, 4559, 2893},{ 7282, 4559, 7282, 4559},{ 4559, 2893, 4559, 2893}}
};

extern const int A[4][4] = {
  { 16, 20, 16, 20},
  { 20, 25, 20, 25},
  { 16, 20, 16, 20},
  { 20, 25, 20, 25}
};

extern const int QuantCoef[6][16] = {
  {13107, 8066,13107, 8066, 8066, 5243, 8066, 5243,13107, 8066,13107, 8066, 8066, 5243, 8066, 5243},
  {11916, 7490,11916, 7490, 7490, 4660, 7490, 4660,11916, 7490,11916, 7490, 7490, 4660, 7490, 4660},
  {10082, 6554,10082, 6554, 6554, 4194, 6554, 4194,10082, 6554,10082, 6554, 6554, 4194, 6554, 4194},
  { 9362, 5825, 9362, 5825, 5825, 3647, 5825, 3647, 9362, 5825, 9362, 5825, 5825, 3647, 5825, 3647},
  { 8192, 5243, 8192, 5243, 5243, 3355, 5243, 3355, 8192, 5243, 8192, 5243, 5243, 3355, 5243, 3355},
  { 7282, 4559, 7282, 4559, 4559, 2893, 4559, 2893, 7282, 4559, 7282, 4559, 4559, 2893, 4559, 2893}
};

extern const int MATR[16] = {
   16, 20, 16, 20,
   20, 25, 20, 25,
   16, 20, 16, 20,
   20, 25, 20, 25
};

//the same arrays that QuantIndex and InvQuantTable in ownH264Tables.h
extern const Fw32s QuantIndex1[16] = {0,2,0,2,2,1,2,1,0,2,0,2,2,1,2,1};

extern const Fw32s InvQuantTable1[52][3] = {
{10,16,13},{11,18,14},{13,20,16},{14,23,18},
{16,25,20},{18,29,23},{20,32,26},{22,36,28},
{26,40,32},{28,46,36},{32,50,40},{36,58,46},
{40,64,52},{44,72,56},{52,80,64},{56,92,72},
{64,100,80},{72,116,92},{80,128,104},{88,144,112},
{104,160,128},{112,184,144},{128,200,160},{144,232,184},
{160,256,208},{176,288,224},{208,320,256},{224,368,288},
{256,400,320},{288,464,368},{320,512,416},{352,576,448},
{416,640,512},{448,736,576},{512,800,640},{576,928,736},
{640,1024,832},{704,1152,896},{832,1280,1024},{896,1472,1152},
{1024,1600,1280},{1152,1856,1472},{1280,2048,1664},{1408,2304,1792},
{1664,2560,2048},{1792,2944,2304},{2048,3200,2560},{2304,3712,2944},
{2560,4096,3328},{2816,4608,3584},{3328,5120,4096},{3584,5888,4608}
};

// used by H.264-MBrecon
//extern "C" const static Fw8u  ClampTbl[CLIP_RANGE];	/////////// Init
extern SYS_FORCEALIGN_16  const Fw8u ClampTbl[768] =
{
     0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00
    ,0x00 ,0x01 ,0x02 ,0x03 ,0x04 ,0x05 ,0x06 ,0x07
    ,0x08 ,0x09 ,0x0a ,0x0b ,0x0c ,0x0d ,0x0e ,0x0f
    ,0x10 ,0x11 ,0x12 ,0x13 ,0x14 ,0x15 ,0x16 ,0x17
    ,0x18 ,0x19 ,0x1a ,0x1b ,0x1c ,0x1d ,0x1e ,0x1f
    ,0x20 ,0x21 ,0x22 ,0x23 ,0x24 ,0x25 ,0x26 ,0x27
    ,0x28 ,0x29 ,0x2a ,0x2b ,0x2c ,0x2d ,0x2e ,0x2f
    ,0x30 ,0x31 ,0x32 ,0x33 ,0x34 ,0x35 ,0x36 ,0x37
    ,0x38 ,0x39 ,0x3a ,0x3b ,0x3c ,0x3d ,0x3e ,0x3f
    ,0x40 ,0x41 ,0x42 ,0x43 ,0x44 ,0x45 ,0x46 ,0x47
    ,0x48 ,0x49 ,0x4a ,0x4b ,0x4c ,0x4d ,0x4e ,0x4f
    ,0x50 ,0x51 ,0x52 ,0x53 ,0x54 ,0x55 ,0x56 ,0x57
    ,0x58 ,0x59 ,0x5a ,0x5b ,0x5c ,0x5d ,0x5e ,0x5f
    ,0x60 ,0x61 ,0x62 ,0x63 ,0x64 ,0x65 ,0x66 ,0x67
    ,0x68 ,0x69 ,0x6a ,0x6b ,0x6c ,0x6d ,0x6e ,0x6f
    ,0x70 ,0x71 ,0x72 ,0x73 ,0x74 ,0x75 ,0x76 ,0x77
    ,0x78 ,0x79 ,0x7a ,0x7b ,0x7c ,0x7d ,0x7e ,0x7f
    ,0x80 ,0x81 ,0x82 ,0x83 ,0x84 ,0x85 ,0x86 ,0x87
    ,0x88 ,0x89 ,0x8a ,0x8b ,0x8c ,0x8d ,0x8e ,0x8f
    ,0x90 ,0x91 ,0x92 ,0x93 ,0x94 ,0x95 ,0x96 ,0x97
    ,0x98 ,0x99 ,0x9a ,0x9b ,0x9c ,0x9d ,0x9e ,0x9f
    ,0xa0 ,0xa1 ,0xa2 ,0xa3 ,0xa4 ,0xa5 ,0xa6 ,0xa7
    ,0xa8 ,0xa9 ,0xaa ,0xab ,0xac ,0xad ,0xae ,0xaf
    ,0xb0 ,0xb1 ,0xb2 ,0xb3 ,0xb4 ,0xb5 ,0xb6 ,0xb7
    ,0xb8 ,0xb9 ,0xba ,0xbb ,0xbc ,0xbd ,0xbe ,0xbf
    ,0xc0 ,0xc1 ,0xc2 ,0xc3 ,0xc4 ,0xc5 ,0xc6 ,0xc7
    ,0xc8 ,0xc9 ,0xca ,0xcb ,0xcc ,0xcd ,0xce ,0xcf
    ,0xd0 ,0xd1 ,0xd2 ,0xd3 ,0xd4 ,0xd5 ,0xd6 ,0xd7
    ,0xd8 ,0xd9 ,0xda ,0xdb ,0xdc ,0xdd ,0xde ,0xdf
    ,0xe0 ,0xe1 ,0xe2 ,0xe3 ,0xe4 ,0xe5 ,0xe6 ,0xe7
    ,0xe8 ,0xe9 ,0xea ,0xeb ,0xec ,0xed ,0xee ,0xef
    ,0xf0 ,0xf1 ,0xf2 ,0xf3 ,0xf4 ,0xf5 ,0xf6 ,0xf7
    ,0xf8 ,0xf9 ,0xfa ,0xfb ,0xfc ,0xfd ,0xfe ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
    ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff ,0xff
};

// Remaining constants based on work by llcc and visionany (Framewave\sdk\external\dec_cavlc.c).
// 
// used in H.264-CAVLC
// three entry
#define VLC(a, b, c) {a, b, c}
#define VLC2(a, b, c) VLC(a, b, c), VLC(a, b, c)
#define VLC4(a, b, c) VLC2(a, b, c), VLC2(a, b, c)

/* ++ cavlc tables ++ */
extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff4_0[] = 
{
    VLC(6, 0, 2),   /* 0001 00 */
    VLC(6, 3, 3),   /* 0001 01 */
    VLC(6, 1, 2),   /* 0001 10 */
    VLC(6, 0, 1),   /* 0001 11 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff4_1[] = 
{
    VLC2(7, 3, 4),   /* 0000 000(0) */
    VLC(8, 2, 4),   /* 0000 0010 */
    VLC(8, 1, 4),   /* 0000 0011 */
    VLC2(7, 2, 3),   /* 0000 010(0) */
    VLC2(7, 1, 3),   /* 0000 011(0) */
    VLC4(6, 0, 4),   /* 0000 10(00) */
    VLC4(6, 0, 3),   /* 0000 11(00) */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff3_0[] =
{
    VLC(6, 0, 1),    /* 0000 00 */ 
    VLC(6, 1, 1),    /* 0000 01 */ 
    VLC((Fw8u)-1, (Fw8u)-1, (Fw8u)-1), /* 0000 10 */ 
    VLC(6, 0, 0),    /* 0000 11 */
    VLC(6, 0, 2),    /* 0001 00 */
    VLC(6, 1, 2),    /* 0001 01 */
    VLC(6, 2, 2),    /* 0001 10 */
    VLC((Fw8u)-1, (Fw8u)-1, (Fw8u)-1), /* 0001 11 */
    VLC(6, 0, 3),    /* 0010 00 */
    VLC(6, 1, 3),    /* 0010 01 */
    VLC(6, 2, 3),    /* 0010 10 */
    VLC(6, 3, 3),    /* 0010 11 */
    VLC(6, 0, 4),    /* 0011 00 */
    VLC(6, 1, 4),    /* 0011 01 */
    VLC(6, 2, 4),    /* 0011 10 */
    VLC(6, 3, 4),    /* 0011 11 */
    VLC(6, 0, 5),    /* 0100 00 */
    VLC(6, 1, 5),    /* 0100 01 */
    VLC(6, 2, 5),    /* 0100 10 */
    VLC(6, 3, 5),    /* 0100 11 */
    VLC(6, 0, 6),    /* 0101 00 */
    VLC(6, 1, 6),    /* 0101 01 */
    VLC(6, 2, 6),    /* 0101 10 */
    VLC(6, 3, 6),    /* 0101 11 */
    VLC(6, 0, 7),    /* 0110 00 */
    VLC(6, 1, 7),    /* 0110 01 */
    VLC(6, 2, 7),    /* 0110 10 */
    VLC(6, 3, 7),    /* 0110 11 */
    VLC(6, 0, 8),
    VLC(6, 1, 8),
    VLC(6, 2, 8),
    VLC(6, 3, 8),
    VLC(6, 0, 9),
    VLC(6, 1, 9),
    VLC(6, 2, 9),
    VLC(6, 3, 9),
    VLC(6, 0, 10),
    VLC(6, 1, 10),
    VLC(6, 2, 10),
    VLC(6, 3, 10),
    VLC(6, 0, 11),
    VLC(6, 1, 11),
    VLC(6, 2, 11),
    VLC(6, 3, 11),
    VLC(6, 0, 12),
    VLC(6, 1, 12),
    VLC(6, 2, 12),
    VLC(6, 3, 12),
    VLC(6, 0, 13),
    VLC(6, 1, 13),
    VLC(6, 2, 13),
    VLC(6, 3, 13),
    VLC(6, 0, 14),
    VLC(6, 1, 14),
    VLC(6, 2, 14),
    VLC(6, 3, 14),
    VLC(6, 0, 15),
    VLC(6, 1, 15),
    VLC(6, 2, 15),
    VLC(6, 3, 15),
    VLC(6, 0, 16),
    VLC(6, 1, 16),
    VLC(6, 2, 16),
    VLC(6, 3, 16)
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_0[] = 
{
    VLC(4, 3, 7),   /* 1000 */
    VLC(4, 3, 6),   /* 1001 */
    VLC(4, 3, 5),   /* 1010 */
    VLC(4, 3, 4),   /* 1011 */
    VLC(4, 3, 3),   /* 1100 */
    VLC(4, 2, 2),   /* 1101 */
    VLC(4, 1, 1),   /* 1110 */
    VLC(4, 0, 0),   /* 1111 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_1[] = 
{
    VLC(5, 1, 5),   /* 0100 0 */
    VLC(5, 2, 5),
    VLC(5, 1, 4),
    VLC(5, 2, 4),
    VLC(5, 1, 3),
    VLC(5, 3, 8),
    VLC(5, 2, 3),
    VLC(5, 1, 2),
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_2[] = 
{
    VLC(6, 0, 3),   /* 0010 00 */
    VLC(6, 2, 7),
    VLC(6, 1, 7),
    VLC(6, 0, 2),
    VLC(6, 3, 9),
    VLC(6, 2, 6),
    VLC(6, 1, 6),
    VLC(6, 0, 1),
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_3[] = 
{
    VLC(7, 0, 7),   /* 0001 000 */
    VLC(7, 0, 6),
    VLC(7, 2, 9),
    VLC(7, 0, 5),
    VLC(7, 3, 10),
    VLC(7, 2, 8),
    VLC(7, 1, 8),
    VLC(7, 0, 4),
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_4[] = 
{
    VLC(8, 3, 12),   /* 0000 1000 */
    VLC(8, 2, 11),
    VLC(8, 1, 10),
    VLC(8, 0, 9),
    VLC(8, 3, 11),
    VLC(8, 2, 10),
    VLC(8, 1, 9),
    VLC(8, 0, 8),
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_5[] = 
{
    VLC(9, 0, 12),   /* 0000 0100 0 */
    VLC(9, 2, 13),
    VLC(9, 1, 12),
    VLC(9, 0, 11),
    VLC(9, 3, 13),
    VLC(9, 2, 12),
    VLC(9, 1, 11),
    VLC(9, 0, 10),
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff2_6[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1, (Fw8u)-1),   /* 0000 0000 00 */
    VLC(10, 0, 16),    /* 0000 0000 01 */
    VLC(10, 3, 16),    /* 0000 0000 10 */
    VLC(10, 2, 16),    /* 0000 0000 11 */
    VLC(10, 1, 16),    /* 0000 0001 00 */
    VLC(10, 0, 15),    /* 0000 0001 01 */
    VLC(10, 3, 15),    /* 0000 0001 10 */
    VLC(10, 2, 15),    /* 0000 0001 11 */
    VLC(10, 1, 15),    /* 0000 0010 00 */
    VLC(10, 0, 14),
    VLC(10, 3, 14),
    VLC(10, 2, 14),
    VLC(10, 1, 14),
    VLC(10, 0, 13),
    VLC2(9, 1, 13),    /* 0000 0011 1(0) */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_0[] = 
{
    VLC(4, 3, 4),  /* 0100 */
    VLC(4, 3, 3),  /* 0101 */
    VLC2(3, 2, 2), /* 011(0) */
    VLC4(2, 1, 1), /* 10 */
    VLC4(2, 0, 0), /* 11 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_1[] = 
{
    VLC(6, 3, 7),   /* 0001 00 */
    VLC(6, 2, 4),   /* 0001 01 */
    VLC(6, 1, 4),   /* 0001 10 */
    VLC(6, 0, 2),   /* 0001 11 */
    VLC(6, 3, 6),   /* 0010 00 */
    VLC(6, 2, 3),   /* 0010 01 */
    VLC(6, 1, 3),   /* 0010 10 */
    VLC(6, 0, 1),   /* 0010 11*/
    VLC2(5, 3, 5),   /* 0011 0(0)*/
    VLC2(5, 1, 2),   /* 0011 1(0)*/
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_2[] = 
{
    VLC(9, 3, 9),   /* 0000 0010 0 */
    VLC(9, 2, 7),   /* 0000 0010 1 */
    VLC(9, 1, 7),   /* 0000 0011 0 */
    VLC(9, 0, 6),   /* 0000 0011 1 */

    VLC2(8, 0, 5),   /* 0000 0100 */
    VLC2(8, 2, 6),   /* 0000 0101 */
    VLC2(8, 1, 6),   /* 0000 0110 */
    VLC2(8, 0, 4),   /* 0000 0111 */

    VLC4(7, 3, 8),    /* 0000 100 */
    VLC4(7, 2, 5),    /* 0000 101 */
    VLC4(7, 1, 5),    /* 0000 110 */
    VLC4(7, 0, 3),    /* 0000 111 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_3[] = 
{
    VLC(11, 3, 11),   /* 0000 0001 000 */
    VLC(11, 2, 9),    /* 0000 0001 001 */
    VLC(11, 1, 9),    /* 0000 0001 010 */
    VLC(11, 0, 8),    /* 0000 0001 011 */
    VLC(11, 3, 10),   /* 0000 0001 100 */
    VLC(11, 2, 8),    /* 0000 0001 101 */
    VLC(11, 1, 8),    /* 0000 0001 110 */
    VLC(11, 0, 7),    /* 0000 0001 111 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_4[] = 
{
    VLC(12, 0, 11),   /* 0000 0000 1000 */
    VLC(12, 2, 11),   /* 0000 0000 1001 */
    VLC(12, 1, 11),   /* 0000 0000 1010 */
    VLC(12, 0, 10),   /* 0000 0000 1011 */
    VLC(12, 3, 12),   /* 0000 0000 1100 */
    VLC(12, 2, 10),   /* 0000 0000 1101 */
    VLC(12, 1, 10),   /* 0000 0000 1110 */
    VLC(12, 0, 9),    /* 0000 0000 1111 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_5[] = 
{
    VLC(13, 3, 14),   /* 0000 0000 0100 0 */
    VLC(13, 2, 13),   /* 0000 0000 0100 1 */
    VLC(13, 1, 13),   /* 0000 0000 0101 0 */
    VLC(13, 0, 13),   /* 0000 0000 0101 1 */
    VLC(13, 3, 13),   /* 0000 0000 0110 0 */
    VLC(13, 2, 12),   /* 0000 0000 0110 1 */
    VLC(13, 1, 12),   /* 0000 0000 0111 0 */
    VLC(13, 0, 12),   /* 0000 0000 0111 1 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff1_6[] = 
{
    VLC2((Fw8u)-1, (Fw8u)-1, (Fw8u)-1),  /* 0000 0000 0000 00 */
    VLC2(13, 3, 15),   /* 0000 0000 0000 1(0) */
    VLC(14, 3, 16),   /* 0000 0000 0001 00 */
    VLC(14, 2, 16),   /* 0000 0000 0001 01 */
    VLC(14, 1, 16),   /* 0000 0000 0001 10 */
    VLC(14, 0, 16),   /* 0000 0000 0001 11 */

    VLC(14, 1, 15),   /* 0000 0000 0010 00 */
    VLC(14, 0, 15),   /* 0000 0000 0010 01 */
    VLC(14, 2, 15),   /* 0000 0000 0010 10 */
    VLC(14, 1, 14),   /* 0000 0000 0010 11 */
    VLC2(13, 2, 14),   /* 0000 0000 0011 0(0) */
    VLC2(13, 0, 14),   /* 0000 0000 0011 1(0) */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff0_0[] = 
{
    VLC2((Fw8u)-1, (Fw8u)-1, (Fw8u)-1), /* 0000 0000 0000 000(0) */
    VLC2(15, 1, 13),  /* 0000 0000 0000 001(0) */
    VLC(16, 0, 16),   /* 0000 0000 0000 0100 */
    VLC(16, 2, 16),   
    VLC(16, 1, 16),
    VLC(16, 0, 15),
    VLC(16, 3, 16),
    VLC(16, 2, 15),
    VLC(16, 1, 15),
    VLC(16, 0, 14),
    VLC(16, 3, 15),
    VLC(16, 2, 14),
    VLC(16, 1, 14),
    VLC(16, 0, 13),   /* 0000 0000 0000 1111 */
    VLC2(15, 3, 14),  /* 0000 0000 0001 000(0) */
    VLC2(15, 2, 13),
    VLC2(15, 1, 12),
    VLC2(15, 0, 12),
    VLC2(15, 3, 13),
    VLC2(15, 2, 12),
    VLC2(15, 1, 11),
    VLC2(15, 0, 11),  /* 0000 0000 0001 111(0) */
    VLC4(14, 3, 12),  /* 0000 0000 0010 00(00) */
    VLC4(14, 2, 11),
    VLC4(14, 1, 10),
    VLC4(14, 0, 10),
    VLC4(14, 3, 11),
    VLC4(14, 2, 10),
    VLC4(14, 1, 9),
    VLC4(14, 0, 9),  /* 0000 0000 0011 11(00) */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff0_1[] = 
{
    VLC(13, 0, 8),   /* 0000 0000 0100 0 */
    VLC(13, 2, 9),
    VLC(13, 1, 8),
    VLC(13, 0, 7),
    VLC(13, 3, 10),
    VLC(13, 2, 8),
    VLC(13, 1, 7),
    VLC(13, 0, 6),  /* 0000 0000 0111 1 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff0_2[] = 
{
    VLC(11, 3, 9),   /* 0000 0000 100 */
    VLC(11, 2, 7),
    VLC(11, 1, 6),
    VLC(11, 0, 5),   /* 0000 0000 111 */
    VLC2(10, 3, 8),  /* 0000 0001 00(0) */
    VLC2(10, 2, 6),
    VLC2(10, 1, 5),
    VLC2(10, 0, 4),  /* 0000 0001 11(0) */
    VLC4(9, 3, 7),  /* 0000 0010 0(0) */
    VLC4(9, 2, 5),
    VLC4(9, 1, 4),
    VLC4(9, 0, 3),  /* 0000 0011 1(0) */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff0_3[] = 
{
    VLC(8, 3, 6),   /* 0000 0100 */
    VLC(8, 2, 4),
    VLC(8, 1, 3),
    VLC(8, 0, 2),
    VLC2(7, 3, 5),  /* 0000 100 */
    VLC2(7, 2, 3),
    VLC4(6, 3, 4),  /* 0000 11 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff0_4[] = 
{
    VLC(6, 1, 2),    /* 0001 00 */
    VLC(6, 0, 1),    /* 0001 01 */
    VLC2(5, 3, 3)    /* 0001 1 */
};

extern SYS_FORCEALIGN_16 const vlc_coeff_token_t coeff0_5[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1, (Fw8u)-1),   /* 000 */
    VLC(3, 2, 2),      /* 001 */
    VLC2(2, 1, 1),     /* 01 */
    VLC4(1, 0, 0)      /* 1 */
};

extern SYS_FORCEALIGN_16 const Fw32u GetBitsMask32[32] =
{
    0x00000000, 0x00000001, 0x00000003, 0x00000007,
    0x0000000f, 0x0000001f, 0x0000003f, 0x0000007f,
    0x000000ff, 0x000001ff, 0x000003ff, 0x000007ff,
    0x00000fff, 0x00001fff, 0x00003fff, 0x00007fff,
    0x0000ffff, 0x0001ffff, 0x0003ffff, 0x0007ffff,
    0x000fffff, 0x001fffff, 0x003fffff, 0x007fffff,
    0x00ffffff,	0x01ffffff, 0x03ffffff, 0x07ffffff,
    0x0fffffff,	0x1fffffff, 0x3fffffff, 0x7fffffff,
};

// two entry
#undef VLC
#undef VLC2
#undef VLC4
#define VLC(a, b) {a, b}
#define VLC2(a, b) VLC(a, b), VLC(a, b)
#define VLC4(a, b) VLC2(a, b), VLC2(a, b)
#define VLC8(a, b) VLC4(a, b), VLC4(a, b)

extern const zero_count_t total_zero_table1_0[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1),
    VLC(15, 9), /* 0000 0000 1 */
    VLC(14, 9),
    VLC(13, 9), /* 0000 0001 1 */
    VLC2(12, 8),/* 0000 0010 */
    VLC2(11, 8),/* 0000 0011 */
    VLC4(10, 7),/* 0000 010 */
    VLC4(9, 7), /* 0000 011 */
    VLC8(8, 6), /* 0000 10 */
    VLC8(7, 6), /* 0000 11 */
};

extern const zero_count_t total_zero_table1_1[] = 
{
    VLC2((Fw8u)-1, (Fw8u)-1),
    VLC(6, 5), /* 0001 0 */
    VLC(5, 5), /* 0001 1 */
    VLC2(4, 4),/* 0010 */
    VLC2(3, 4),/* 0011 */
    VLC4(2, 3),/* 010 */
    VLC4(1, 3),/* 011 */
    VLC8(0, 1), /*1 */
    VLC8(0, 1), /*1 */
};

extern const zero_count_t total_zero_table2_0[] = 
{
    VLC(14, 6), /* 0000 00 */
    VLC(13, 6),
    VLC(12, 6),
    VLC(11, 6),
    VLC2(10, 5),/* 0001 0 */
    VLC2(9, 5),
};

extern const zero_count_t total_zero_table2_1[] = 
{
    VLC2((Fw8u)-1, (Fw8u)-1),
    VLC(8, 4), /* 0010 */
    VLC(7, 4), /* 0011 */
    VLC(6, 4),
    VLC(5, 4),
    VLC2(4, 3),/* 011 */
    VLC2(3, 3),/* 100 */
    VLC2(2, 3), /*101 */
    VLC2(1, 3), /*110 */
    VLC2(0, 3), /*111 */
};

extern const zero_count_t total_zero_table3_0[] = 
{
    VLC(13, 6), /* 0000 00 */
    VLC(11, 6),
    VLC2(12, 5),/* 0000 1 */
    VLC2(10, 5),/* 0001 0 */
    VLC2(9, 5), /* 0001 1 */
};

extern const zero_count_t total_zero_table3_1[] = 
{
    VLC2((Fw8u)-1, (Fw8u)-1),
    VLC(8, 4), /* 0010 */
    VLC(5, 4), /* 0011 */
    VLC(4, 4),
    VLC(0, 4),
    VLC2(7, 3),/* 011 */
    VLC2(6, 3),/* 100 */
    VLC2(3, 3), /*101 */
    VLC2(2, 3), /*110 */
    VLC2(1, 3), /*111 */
};

extern const zero_count_t total_zero_table6_0[] = 
{
    VLC(10, 6), /* 0000 00 */
    VLC(0, 6),
    VLC2(1, 5),/* 0000 1 */
    VLC4(8, 4),/* 0000 1 */
};

extern const zero_count_t total_zero_table6_1[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1),
    VLC(9, 3), /* 001 */
    VLC(7, 3), /* 010 */
    VLC(6, 3),
    VLC(5, 3),
    VLC(4, 3),
    VLC(3, 3),
    VLC(2, 3)
};

extern const zero_count_t total_zero_table7_0[] = 
{
    VLC(9, 6), /* 0000 00 */
    VLC(0, 6),
    VLC2(1, 5),/* 0000 1 */
    VLC4(7, 4),/* 0001 */
};

extern const zero_count_t total_zero_table7_1[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1),
    VLC(8, 3), /* 001 */
    VLC(6, 3), /* 010 */
    VLC(4, 3),
    VLC(3, 3),
    VLC(2, 3),
    VLC2(5, 2)
};

extern const zero_count_t total_zero_table8_0[] = 
{
    VLC(8, 6), /* 0000 00 */
    VLC(0, 6),
    VLC2(2, 5),/* 0000 1 */
    VLC4(1, 4),/* 0001 */
};

extern const zero_count_t total_zero_table8_1[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1),
    VLC(7, 3), /* 001 */
    VLC(6, 3), /* 010 */
    VLC(3, 3),
    VLC2(5, 2),
    VLC2(4, 2)
};

extern const zero_count_t total_zero_table9_0[] = 
{
    VLC(1, 6), /* 0000 00 */
    VLC(0, 6),
    VLC2(7, 5),/* 0000 1 */
    VLC4(2, 4),/* 0001 */
};

extern const zero_count_t total_zero_table9_1[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1),
    VLC(5, 3), /* 001 */
    VLC2(6, 2), /* 01 */
    VLC2(4, 2),
    VLC2(3, 2),
};

extern const zero_count_t total_zero_table4_0[] = 
{
    VLC(12, 5), /* 0000 0 */
    VLC(11, 5),
    VLC(10, 5), /* 0000 1 */
    VLC(0, 5),  /* 0001 1 */
    VLC2(9, 4), /* 0010 */
    VLC2(7, 4),
    VLC2(3, 4),
    VLC2(2, 4), /* 0101 */
    VLC4(8, 3), /* 011 */
};

extern const zero_count_t total_zero_table4_1[] = 
{
    VLC(6, 3),   /* 100 */
    VLC(5, 3),   /* 101 */
    VLC(4, 3),   /* 110 */
    VLC(1, 3)    /* 111 */
};

extern const zero_count_t total_zero_table5_0[] = 
{
    VLC(11, 5),  /* 0000 0 */
    VLC(9, 5),
    VLC2(10, 4), /* 0000 1 */
    VLC2(8, 4),  /* 0010 */
    VLC2(2, 4),
    VLC2(1, 4),
    VLC2(0, 4),
    VLC4(7, 3)
};

extern const zero_count_t total_zero_table5_1[] = 
{
    VLC(6, 3), /* 100 */
    VLC(5, 3),
    VLC(4, 3),
    VLC(3, 3)
};

extern const zero_count_t total_zero_table10_0[] = 
{
    VLC(1, 5), /* 0000 0 */
    VLC(0, 5),
    VLC2(6, 4), /* 0000 1 */
};

extern const zero_count_t total_zero_table10_1[] = 
{
    VLC((Fw8u)-1, (Fw8u)-1),
    VLC(2, 3), /* 001 */
    VLC2(5, 2), /* 01 */
    VLC2(4, 2),
    VLC2(3, 2),
};

extern const zero_count_t total_zero_table11_0[] = 
{
    VLC(0, 4), /* 0000 */
    VLC(1, 4),
    VLC2(2, 3), /* 010 */
    VLC2(3, 3),
    VLC2(5, 3),
    VLC8(4, 1)
};

extern const zero_count_t total_zero_table12_0[] = 
{
    VLC(0, 4), /* 0000 */
    VLC(1, 4),
    VLC2(4, 3), /* 010 */
    VLC4(2, 2),
    VLC8(3, 1)
};

extern const zero_count_t total_zero_table13_0[] = 
{
    VLC(0, 3), /* 000 */
    VLC(1, 3),
    VLC2(3, 2), /* 01 */
    VLC4(2, 1),
};

extern const zero_count_t total_zero_table14_0[] = 
{
    VLC(0, 2), 
    VLC(1, 2),
    VLC2(2, 1),
};

extern const zero_count_t total_zero_table_chroma[3][8] = 
{
    {
        VLC(3, 3), 
        VLC(2, 3),
        VLC2(1, 2),
        VLC4(0, 1)
    },
    {
        VLC2(2, 2),
        VLC2(1, 2),
        VLC4(0, 1)
    },
    {
        VLC4(1, 1),
        VLC4(0, 1)
    }
};

extern const zero_count_t run_before_table_0[7][8] = 
{
    {
        VLC4(1, 1),
        VLC4(0, 1)
    },
    {
        VLC2(2, 2),
        VLC2(1, 2),
        VLC4(0, 1)
    },
    {
        VLC2(3, 2),
        VLC2(2, 2),
        VLC2(1, 2),
        VLC2(0, 2)
    },
    {
        VLC(4, 3),
        VLC(3, 3),
        VLC2(2, 2),
        VLC2(1, 2),
        VLC2(0, 2)
    },
    {
        VLC(5, 3),
        VLC(4, 3),
        VLC(3, 3),
        VLC(2, 3),
        VLC2(1, 2),
        VLC2(0, 2),
    },
    {
        VLC(1, 3),
        VLC(2, 3),
        VLC(4, 3),
        VLC(3, 3),
        VLC(6, 3),
        VLC(5, 3),
        VLC2(0, 2)
    },
    {
        VLC((Fw8u)-1, (Fw8u)-1),
        VLC(6, 3),
        VLC(5, 3),
        VLC(4, 3),
        VLC(3, 3),
        VLC(2, 3),
        VLC(1, 3),
        VLC(0, 3)
    }
};

extern const Fw8u prefix_table0[] = 
{
    (Fw8u)-1,
    (Fw8u)3,
    (Fw8u)2, (Fw8u)2,
    (Fw8u)1, (Fw8u)1, (Fw8u)1, (Fw8u)1,
    (Fw8u)0, (Fw8u)0, (Fw8u)0, (Fw8u)0, (Fw8u)0, (Fw8u)0, (Fw8u)0, (Fw8u)0
};

extern const Fw8u prefix_table1[] = 
{
    (Fw8u)-1,
    (Fw8u)7,
    (Fw8u)6, (Fw8u)6,
    (Fw8u)5, (Fw8u)5, (Fw8u)5, (Fw8u)5,
    (Fw8u)4, (Fw8u)4, (Fw8u)4, (Fw8u)4, (Fw8u)4, (Fw8u)4, (Fw8u)4, (Fw8u)4
};

extern const Fw8u prefix_table2[] =
{
    (Fw8u)-1,
    (Fw8u)11,
    (Fw8u)10, (Fw8u)10,
    (Fw8u)9, (Fw8u)9, (Fw8u)9, (Fw8u)9,
    (Fw8u)8, (Fw8u)8, (Fw8u)8, (Fw8u)8, (Fw8u)8, (Fw8u)8, (Fw8u)8, (Fw8u)8
};

extern const Fw8u prefix_table3[] = 
{
    (Fw8u)-1,
    (Fw8u)15,
    (Fw8u)14, (Fw8u)14,
    (Fw8u)13, (Fw8u)13, (Fw8u)13, (Fw8u)13,
    (Fw8u)12, (Fw8u)12, (Fw8u)12, (Fw8u)12, (Fw8u)12, (Fw8u)12, (Fw8u)12, (Fw8u)12
};

extern const Fw8u run_before_table_1[] =
{
    (Fw8u)-1,
    (Fw8u)10,
    (Fw8u)9, (Fw8u)9,
    (Fw8u)8, (Fw8u)8, (Fw8u)8, (Fw8u)8,
    (Fw8u)7, (Fw8u)7, (Fw8u)7, (Fw8u)7, (Fw8u)7, (Fw8u)7, (Fw8u)7,(Fw8u) 7
};

extern const Fw8u run_before_table_2[] =
{
    (Fw8u)-1,
    (Fw8u)14,
    (Fw8u)13, (Fw8u)13,
    (Fw8u)12, (Fw8u)12, (Fw8u)12, (Fw8u)12,
    (Fw8u)11, (Fw8u)11, (Fw8u)11, (Fw8u)11, (Fw8u)11, (Fw8u)11, (Fw8u)11, (Fw8u)11
};

#if defined( FW_SOL )
#undef extern
#undef const
#endif

