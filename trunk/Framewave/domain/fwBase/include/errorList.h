/*
Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
This software is subject to the Apache v2.0 License.
*/

// NO INCLUDES 
// NO PREPROCESSOR MACROS

/*
	List of (errorID,errorText) pairs.
	This file will be included in a file wich defines the LIST_ITEM macro.
*/


// Used return values

LIST_ITEM( fwStsAnchorErr				,"The anchor is located out of the mask" )  
LIST_ITEM( fwStsChannelOrderErr		,"The given destination order is not valid (contains values other than 0,1,2)" )  
LIST_ITEM( fwStsCoeffErr				,"The coefficient values have errors" )  
LIST_ITEM( fwStsContextMatchErr		,"The specification struture does not match the function or is invalid" )  
LIST_ITEM( fwStsCpuMismatch			,"The specified CPU type cannot be assigned" )  
LIST_ITEM( fwStsDivisorErr				,"The divisor is zero" )  
LIST_ITEM( fwStsDomain					,"Argument out of function domain warning status code" )  
LIST_ITEM( fwStsDoubleSize				,"Image size (height and/or width) is not a multiple of two warning status code" )  
LIST_ITEM( fwStsEpsValErr				,"Eps is a negative value" )  
LIST_ITEM( fwStsInterpolationErr		,"The interpolation value is incorrect or unsupported for the specified function" )  
LIST_ITEM( fwStsLnNegArg				,"Negative input buffer element warning status code" )  
LIST_ITEM( fwStsLnZeroArg				,"Zero-valued input buffer element warning status code" )  
//LIST_ITEM( fwStsMaskErr				,"The mask size is invalid" )  
LIST_ITEM( fwStsMaskSizeErr			,"The mask has an invalid value" )  
LIST_ITEM( fwStsMemAllocErr			,"The function failed to allocate memory" )  
LIST_ITEM( fwStsMirrorFlipErr			,"The mirror flip value is invalid" )  
LIST_ITEM( fwStsNoErr					,"No error detected" )  
LIST_ITEM( fwStsNotEvenStepErr			,"One of the step values for a floating point images is not divisible by four" )  
LIST_ITEM( fwStsNullPtrErr				,"A pointer passed to the function is null" )  
//LIST_ITEM( fwStsNumChannelErr		,"The number of channels is incorrect" )  
LIST_ITEM( fwStsOverflow				,"Overflow in operation warning status code" )  
LIST_ITEM( fwStsQuadErr				,"The source or destination quadrangle degenerates into a triangle, line, or points; or the destination quadrangle has conflicted vertex coordinates" )  
LIST_ITEM( fwStsRectErr				,"The width or height of the source ROI has a value less than or equal to one" )  
LIST_ITEM( fwStsResizeFactorErr		,"The resize factor is less than or equal to zero" )  
LIST_ITEM( fwStsResizeNoOperationErr	,"A destination image dimension is less than one pixel" )  
LIST_ITEM( fwStsSingularity			,"Singularity in operation warning status code" )  
LIST_ITEM( fwStsSizeErr				,"The size is invalid (usually indicates negative or zero size)" )  
LIST_ITEM( fwStsStepErr				,"The step value for the buffer is invalid" )  
LIST_ITEM( fwStsThresholdErr			,"The less-than threshold is greater than the greater-than threshold" )  
LIST_ITEM( fwStsUnderflow				,"Underflow in operation warning status code" )  
LIST_ITEM( fwStsWrongIntersectQuad		,"The quadrangle does not intersect the source or destination image (no operation is performed)" )  
LIST_ITEM( fwStsWrongIntersectROI		,"The ROI does not intersect the source or destination image (no operation is performed)" )  
LIST_ITEM( fwStsZeroMaskValuesErr		,"All mask values are equal to zero" )  

//Image Processing Errors

LIST_ITEM( fwStsNotSupportedModeErr	,"" )
LIST_ITEM( fwStsBlockStepErr			,"" )
LIST_ITEM( fwStsMBStepErr				,"" )
LIST_ITEM( fwStsNoiseRangeErr			,"" )
LIST_ITEM( fwStsLPCCalcErr				,"" )
LIST_ITEM( fwStsJPEG2KBadPassNumber	,"" )
LIST_ITEM( fwStsJPEG2KDamagedCodeBlock	,"" )
LIST_ITEM( fwStsH263CBPYCodeErr		,"" )
LIST_ITEM( fwStsH263MCBPCInterCodeErr	,"" )
LIST_ITEM( fwStsH263MCBPCIntraCodeErr	,"" )
LIST_ITEM( fwStsHistoNofLevelsErr		,"" )
LIST_ITEM( fwStsLUTNofLevelsErr		,"" )
LIST_ITEM( fwStsMP4BitOffsetErr		,"" )
LIST_ITEM( fwStsMP4QPErr				,"" )
LIST_ITEM( fwStsMP4BlockIdxErr			,"" )
LIST_ITEM( fwStsMP4BlockTypeErr		,"" )
LIST_ITEM( fwStsMP4MVCodeErr			,"" )
LIST_ITEM( fwStsMP4VLCCodeErr			,"" )
LIST_ITEM( fwStsMP4DCCodeErr			,"" )
LIST_ITEM( fwStsMP4FcodeErr			,"" )
LIST_ITEM( fwStsMP4AlignErr			,"" )
LIST_ITEM( fwStsMP4TempDiffErr			,"" )
LIST_ITEM( fwStsMP4BlockSizeErr		,"" )
LIST_ITEM( fwStsMP4ZeroBABErr			,"" )
LIST_ITEM( fwStsMP4PredDirErr			,"" )
LIST_ITEM( fwStsMP4BitsPerPixelErr		,"" )
LIST_ITEM( fwStsMP4VideoCompModeErr	,"" )
LIST_ITEM( fwStsMP4LinearModeErr		,"" )
LIST_ITEM( fwStsH263PredModeErr		,"" )
LIST_ITEM( fwStsH263BlockStepErr		,"" )
LIST_ITEM( fwStsH263MBStepErr			,"" )
LIST_ITEM( fwStsH263FrameWidthErr		,"" )
LIST_ITEM( fwStsH263FrameHeightErr		,"" )
LIST_ITEM( fwStsH263ExpandPelsErr		,"" )
LIST_ITEM( fwStsH263PlaneStepErr		,"" )
LIST_ITEM( fwStsH263QuantErr			,"" )
LIST_ITEM( fwStsH263MVCodeErr			,"" )
LIST_ITEM( fwStsH263VLCCodeErr			,"" )
LIST_ITEM( fwStsH263DCCodeErr			,"" )
LIST_ITEM( fwStsH263ZigzagLenErr		,"" )
LIST_ITEM( fwStsJPEGHuffTableErr		,"" )
LIST_ITEM( fwStsJPEGDCTRangeErr		,"" )
LIST_ITEM( fwStsJPEGOutOfBufErr		,"" )
LIST_ITEM( fwStsRangeErr				,"" )
LIST_ITEM( fwStsNoiseValErr			,"" )
LIST_ITEM( fwStsDitherLevelsErr		,"" )
LIST_ITEM( fwStsNumChannelsErr			,"" )
LIST_ITEM( fwStsDataTypeErr			,"" )
LIST_ITEM( fwStsCOIErr					,"" )
LIST_ITEM( fwStsOutOfRangeErr			,"" )
LIST_ITEM( fwStsAlphaTypeErr			,"" )
LIST_ITEM( fwStsGammaRangeErr			,"" )
LIST_ITEM( fwStsGrayCoefSumErr			,"" )
LIST_ITEM( fwStsChannelErr				,"" )
LIST_ITEM( fwStsJaehneErr				,"" )
LIST_ITEM( fwStsStrideErr				,"" )
LIST_ITEM( fwStsScaleRangeErr 			,"" )
LIST_ITEM( fwStsWtOffsetErr			,"" )
LIST_ITEM( fwStsShiftErr				,"" )
LIST_ITEM( fwStsSampleFactorErr 		,"" )
LIST_ITEM( fwStsDivByZeroErr			,"" )
LIST_ITEM( fwStsMoment00ZeroErr		,"" )
LIST_ITEM( fwStsThreshNegLevelErr 		,"" )
LIST_ITEM( fwStsNoOperation			,"" )
LIST_ITEM( fwStsMisalignedBuf			,"" )
LIST_ITEM( fwStsSqrtNegArg				,"" )
LIST_ITEM( fwStsInvZero				,"" )
LIST_ITEM( fwStsEvenMedianMaskSize		,"" )
LIST_ITEM( fwStsDivByZero				,"" )
LIST_ITEM( fwStsNanArg					,"" )
LIST_ITEM( fwStsJPEGMarker				,"" )
LIST_ITEM( fwStsResFloor				,"" )
LIST_ITEM( fwStsAffineQuadChanged		,"" )
									
// Signal Processing Errors:		
LIST_ITEM( fwStsCpuNotSupportedErr		,"" )
LIST_ITEM( fwStsMP3FrameHeaderErr		,"" )
LIST_ITEM( fwStsMP3SideInfoErr			,"" )
LIST_ITEM( fwStsAacPrgNumErr			,"" )
LIST_ITEM( fwStsAacSectCbErr			,"" )
LIST_ITEM( fwStsAacSfValErr			,"" )
LIST_ITEM( fwStsAacCoefValErr			,"" )
LIST_ITEM( fwStsAacMaxSfbErr			,"" )
LIST_ITEM( fwStsAacPredSfbErr			,"" )
LIST_ITEM( fwStsAacPlsDataErr			,"" )
LIST_ITEM( fwStsAacGainCtrErr			,"" )
LIST_ITEM( fwStsAacSectErr				,"" )
LIST_ITEM( fwStsAacTnsNumFiltErr		,"" )
LIST_ITEM( fwStsAacTnsLenErr			,"" )
LIST_ITEM( fwStsAacTnsOrderErr			,"" )
LIST_ITEM( fwStsAacTnsCoefResErr		,"" )
LIST_ITEM( fwStsAacTnsCoefErr			,"" )
LIST_ITEM( fwStsAacTnsDirectErr		,"" )
LIST_ITEM( fwStsAacTnsProfileErr		,"" )
LIST_ITEM( fwStsAacErr					,"" )
LIST_ITEM( fwStsAacBitOffsetErr		,"" )
LIST_ITEM( fwStsAacAdtsSyncWordErr		,"" )
LIST_ITEM( fwStsAacSmplRateIdxErr		,"" )
LIST_ITEM( fwStsAacWinLenErr			,"" )
LIST_ITEM( fwStsAacWinGrpErr			,"" )
LIST_ITEM( fwStsAacWinSeqErr			,"" )
LIST_ITEM( fwStsAacComWinErr			,"" )
LIST_ITEM( fwStsAacStereoMaskErr		,"" )
LIST_ITEM( fwStsAacChanErr				,"" )
LIST_ITEM( fwStsAacMonoStereoErr		,"" )
LIST_ITEM( fwStsAacStereoLayerErr		,"" )
LIST_ITEM( fwStsAacMonoLayerErr		,"" )
LIST_ITEM( fwStsAacScalableErr			,"" )
LIST_ITEM( fwStsAacObjTypeErr			,"" )
LIST_ITEM( fwStsAacWinShapeErr			,"" )
LIST_ITEM( fwStsAacPcmModeErr			,"" )
LIST_ITEM( fwStsVLCUsrTblHeaderErr		,"" )
LIST_ITEM( fwStsVLCUsrTblUnsupportedFmtErr	,"" )
LIST_ITEM( fwStsVLCUsrTblEscAlgTypeErr		,"" )
LIST_ITEM( fwStsVLCUsrTblEscCodeLengthErr	,"" )
LIST_ITEM( fwStsVLCUsrTblCodeLengthErr		,"" )
LIST_ITEM( fwStsVLCInternalTblErr			,"" )
LIST_ITEM( fwStsVLCInputDataErr		,"" )
LIST_ITEM( fwStsVLCAACEscCodeLengthErr	,"" )
LIST_ITEM( fwStsIncorrectLSPErr		,"" )
LIST_ITEM( fwStsNoRootFoundErr			,"" )
LIST_ITEM( fwStsLengthErr				,"" )
LIST_ITEM( fwStsFBankFreqErr			,"" )
LIST_ITEM( fwStsFBankFlagErr			,"" )
LIST_ITEM( fwStsFBankErr				,"" )
LIST_ITEM( fwStsNegOccErr				,"" )
LIST_ITEM( fwStsCdbkFlagErr			,"" )
LIST_ITEM( fwStsSVDCnvgErr				,"" )
LIST_ITEM( fwStsToneMagnErr			,"" )
LIST_ITEM( fwStsToneFreqErr			,"" )
LIST_ITEM( fwStsTonePhaseErr			,"" )
LIST_ITEM( fwStsTrnglMagnErr			,"" )
LIST_ITEM( fwStsTrnglFreqErr			,"" )
LIST_ITEM( fwStsTrnglPhaseErr			,"" )
LIST_ITEM( fwStsTrnglAsymErr			,"" )
LIST_ITEM( fwStsHugeWinErr				,"" )
//LIST_ITEM( fwStsJaehneErr			,"" )
//LIST_ITEM( fwStsStepErr				,"" )
LIST_ITEM( fwStsDlyLineIndexErr		,"" )
//LIST_ITEM( fwStsStrideErr			,"" )
//LIST_ITEM( fwStsEpsValErr			,"" )
//LIST_ITEM( fwStsScaleRangeErr		,"" )
//LIST_ITEM( fwStsThresholdErr			,"" )
//LIST_ITEM( fwStsWtOffsetErr			,"" )
//LIST_ITEM( fwStsAnchorErr			,"" )
//LIST_ITEM( fwStsMaskSizeErr			,"" )
//LIST_ITEM( fwStsShiftErr				,"" )
//LIST_ITEM( fwStsSampleFactorErr		,"" )
LIST_ITEM( fwStsSamplePhaseErr			,"" )
LIST_ITEM( fwStsFIRMRFactorErr			,"" )
LIST_ITEM( fwStsFIRMRPhaseErr			,"" )
LIST_ITEM( fwStsRelFreqErr				,"" )
LIST_ITEM( fwStsFIRLenErr				,"" )
LIST_ITEM( fwStsIIROrderErr			,"" )
//LIST_ITEM( fwStsResizeFactorErr		,"" )
//LIST_ITEM( fwStsDivByZeroErr			,"" )
//LIST_ITEM( fwStsInterpolationErr		,"" )
//LIST_ITEM( fwStsMirrorFlipErr		,"" )
//LIST_ITEM( fwStsMoment00ZeroErr		,"" )
//LIST_ITEM( fwStsThreshNegLevelErr 	,"" )
//LIST_ITEM( fwStsContextMatchErr		,"" )
//LIST_ITEM( fwStsMemAllocErr			,"" )
//LIST_ITEM( fwStsNullPtrErr			,"" )
//LIST_ITEM( fwStsSizeErr				,"" )
LIST_ITEM( fwStsBadArgErr				,"" )
LIST_ITEM( fwStsErr					,"" )
//LIST_ITEM( fwStsNoErr				,"" )
//LIST_ITEM( fwStsNoOperation			,"" )
//LIST_ITEM( fwStsMisalignedBuf		,"" )
//LIST_ITEM( fwStsEvenMedianMaskSize	,"" )
//LIST_ITEM( fwStsDivByZero			,"" )
//LIST_ITEM( fwStsLnZeroArg			,"" )
//LIST_ITEM( fwStsLnNegArg				,"" )
//LIST_ITEM( fwStsNanArg				,"" )
//LIST_ITEM( fwStsResFloor				,"" )
LIST_ITEM( fwStsZeroOcc				,"" )
LIST_ITEM( fwStsNoFwFunctionFound		,"" )
LIST_ITEM( fwStsDllNotFoundBestUsed	,"" )
LIST_ITEM( fwStsNoOperationInDll		,"" )
LIST_ITEM( fwStsOvermuchStrings		,"" )
LIST_ITEM( fwStsOverlongString			,"" )	
