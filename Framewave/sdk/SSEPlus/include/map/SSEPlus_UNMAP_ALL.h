//
// Copyright (c) 2006-2009 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
//no header guard

#undef __MAP_SSE2__
#undef __MAP_SSE3__

//SSE
#undef ssp_add_ps      
#undef ssp_add_ss      
#undef ssp_and_ps      
#undef ssp_andnot_ps   
#undef ssp_cmpeq_ps    
#undef ssp_cmpeq_ss    
#undef ssp_cmpge_ps    
#undef ssp_cmpge_ss    
#undef ssp_cmpgt_ps    
#undef ssp_cmpgt_ss    
#undef ssp_cmple_ps    
#undef ssp_cmple_ss    
#undef ssp_cmplt_ps    
#undef ssp_cmplt_ss    
#undef ssp_cmpneq_ps   
#undef ssp_cmpneq_ss   
#undef ssp_cmpnge_ps   
#undef ssp_cmpnge_ss   
#undef ssp_cmpngt_ps   
#undef ssp_cmpngt_ss   
#undef ssp_cmpnle_ps   
#undef ssp_cmpnle_ss   
#undef ssp_cmpnlt_ps   
#undef ssp_cmpnlt_ss   
#undef ssp_cmpord_ps   
#undef ssp_cmpord_ss   
#undef ssp_cmpunord_ps 
#undef ssp_cmpunord_ss 
#undef ssp_comieq_ss   
#undef ssp_comige_ss   
#undef ssp_comigt_ss   
#undef ssp_comile_ss   
#undef ssp_comilt_ss   
#undef ssp_comineq_ss  
#undef ssp_cvt_pi2ps   
#undef ssp_cvt_ps2pi   
#undef ssp_cvt_si2ss   
#undef ssp_cvt_ss2si   
#undef ssp_cvtsi64_ss  
#undef ssp_cvtss_f32   
#undef ssp_cvtss_si64  
#undef ssp_cvtt_ps2pi  
#undef ssp_cvtt_ss2si  
#undef ssp_cvttss_si64 
#undef ssp_div_ps      
#undef ssp_div_ss      
#undef ssp_getcsr      
#undef ssp_load_ps     
#undef ssp_load_ps1    
#undef ssp_load_ss     
#undef ssp_loadh_pi    
#undef ssp_loadl_pi    
#undef ssp_loadr_ps    
#undef ssp_loadu_ps    
#undef ssp_max_ps      
#undef ssp_max_ss      
#undef ssp_min_ps      
#undef ssp_min_ss      
#undef ssp_move_ss     
#undef ssp_movehl_ps   
#undef ssp_movelh_ps   
#undef ssp_movemask_ps 
#undef ssp_mul_ps      
#undef ssp_mul_ss      
#undef ssp_or_ps       
#undef ssp_prefetch    
#undef ssp_rcp_ps      
#undef ssp_rcp_ss      
#undef ssp_rsqrt_ps    
#undef ssp_rsqrt_ss    
#undef ssp_set_ps      
#undef ssp_set_ps1     
#undef ssp_set_ss      
#undef ssp_setcsr      
#undef ssp_setr_ps     
#undef ssp_setzero_ps  
#undef ssp_sfence      
#undef ssp_shuffle_ps  
#undef ssp_sqrt_ps     
#undef ssp_sqrt_ss     
#undef ssp_store_ps    
#undef ssp_store_ps1   
#undef ssp_store_ss    
#undef ssp_storeh_pi   
#undef ssp_storel_pi   
#undef ssp_storer_ps   
#undef ssp_storeu_ps   
#undef ssp_stream_ps   
#undef ssp_sub_ps      
#undef ssp_sub_ss      
#undef ssp_ucomieq_ss  
#undef ssp_ucomige_ss  
#undef ssp_ucomigt_ss  
#undef ssp_ucomile_ss  
#undef ssp_ucomilt_ss  
#undef ssp_ucomineq_ss 
#undef ssp_unpackhi_ps 
#undef ssp_unpacklo_ps 
#undef ssp_xor_ps      

//SSE2
#undef ssp_add_epi16        
#undef ssp_add_epi32        
#undef ssp_add_epi64        
#undef ssp_add_epi8         
#undef ssp_add_pd           
#undef ssp_add_sd           
#undef ssp_add_si64         
#undef ssp_adds_epi16       
#undef ssp_adds_epi8        
#undef ssp_adds_epu16       
#undef ssp_adds_epu8        
#undef ssp_and_pd           
#undef ssp_and_si128        
#undef ssp_andnot_pd        
#undef ssp_andnot_si128     
#undef ssp_avg_epu16        
#undef ssp_avg_epu8         
#undef ssp_castpd_ps        
#undef ssp_castpd_si128     
#undef ssp_castps_pd        
#undef ssp_castps_si128     
#undef ssp_castsi128_pd     
#undef ssp_castsi128_ps     
#undef ssp_clflush          
#undef ssp_cmpeq_epi16      
#undef ssp_cmpeq_epi32      
#undef ssp_cmpeq_epi8       
#undef ssp_cmpeq_pd         
#undef ssp_cmpeq_sd         
#undef ssp_cmpge_pd         
#undef ssp_cmpge_sd         
#undef ssp_cmpgt_epi16      
#undef ssp_cmpgt_epi32      
#undef ssp_cmpgt_epi8       
#undef ssp_cmpgt_pd         
#undef ssp_cmpgt_sd         
#undef ssp_cmple_pd         
#undef ssp_cmple_sd         
#undef ssp_cmplt_epi16      
#undef ssp_cmplt_epi32      
#undef ssp_cmplt_epi8       
#undef ssp_cmplt_pd         
#undef ssp_cmplt_sd         
#undef ssp_cmpneq_pd        
#undef ssp_cmpneq_sd        
#undef ssp_cmpnge_pd        
#undef ssp_cmpnge_sd        
#undef ssp_cmpngt_pd        
#undef ssp_cmpngt_sd        
#undef ssp_cmpnle_pd        
#undef ssp_cmpnle_sd        
#undef ssp_cmpnlt_pd        
#undef ssp_cmpnlt_sd        
#undef ssp_cmpord_pd        
#undef ssp_cmpord_sd        
#undef ssp_cmpunord_pd      
#undef ssp_cmpunord_sd      
#undef ssp_comieq_sd        
#undef ssp_comige_sd        
#undef ssp_comigt_sd        
#undef ssp_comile_sd        
#undef ssp_comilt_sd        
#undef ssp_comineq_sd       
#undef ssp_cvtepi32_pd      
#undef ssp_cvtepi32_ps      
#undef ssp_cvtpd_epi32      
#undef ssp_cvtpd_pi32       
#undef ssp_cvtpd_ps         
#undef ssp_cvtpi32_pd       
#undef ssp_cvtps_epi32      
#undef ssp_cvtps_pd         
#undef ssp_cvtsd_f64        
#undef ssp_cvtsd_si32       
#undef ssp_cvtsd_si64       
#undef ssp_cvtsd_ss         
#undef ssp_cvtsi128_si32    
#undef ssp_cvtsi128_si64    
#undef ssp_cvtsi32_sd       
#undef ssp_cvtsi32_si128    
#undef ssp_cvtsi64_sd       
#undef ssp_cvtsi64_si128    
#undef ssp_cvtss_sd         
#undef ssp_cvttpd_epi32     
#undef ssp_cvttpd_pi32      
#undef ssp_cvttps_epi32     
#undef ssp_cvttsd_si32      
#undef ssp_cvttsd_si64      
#undef ssp_div_pd           
#undef ssp_div_sd           
#undef ssp_extract_epi16    
#undef ssp_insert_epi16     
#undef ssp_lfence           
#undef ssp_load_pd          
#undef ssp_load_sd          
#undef ssp_load_si128       
#undef ssp_load1_pd         
#undef ssp_loadh_pd         
#undef ssp_loadl_epi64      
#undef ssp_loadl_pd         
#undef ssp_loadr_pd         
#undef ssp_loadu_pd         
#undef ssp_loadu_si128      
#undef ssp_madd_epi16       
#undef ssp_maskmoveu_si128  
#undef ssp_max_epi16        
#undef ssp_max_epu8         
#undef ssp_max_pd           
#undef ssp_max_sd           
#undef ssp_mfence           
#undef ssp_min_epi16        
#undef ssp_min_epu8         
#undef ssp_min_pd           
#undef ssp_min_sd           
#undef ssp_move_epi64       
#undef ssp_move_sd          
#undef ssp_movemask_epi8    
#undef ssp_movemask_pd      
#undef ssp_movepi64_pi64    
#undef ssp_movpi64_epi64    
#undef ssp_mul_epu32        
#undef ssp_mul_pd           
#undef ssp_mul_sd           
#undef ssp_mul_su32         
#undef ssp_mulhi_epi16      
#undef ssp_mulhi_epu16      
#undef ssp_mullo_epi16      
#undef ssp_or_pd           
#undef ssp_or_si128         
#undef ssp_packs_epi16      
#undef ssp_packs_epi32      
#undef ssp_packus_epi16     
#undef ssp_pause           
#undef ssp_sad_epu8         
#undef ssp_set_epi16        
#undef ssp_set_epi32        
#undef ssp_set_epi64        
#undef ssp_set_epi8         
#undef ssp_set_pd           
#undef ssp_set_sd           
#undef ssp_set1_epi16       
#undef ssp_set1_epi32       
#undef ssp_set1_epi64       
#undef ssp_set1_epi8        
#undef ssp_set1_pd          
#undef ssp_setl_epi64       
#undef ssp_setr_epi16       
#undef ssp_setr_epi32       
#undef ssp_setr_epi64       
#undef ssp_setr_epi8        
#undef ssp_setr_pd          
#undef ssp_setzero_pd       
#undef ssp_setzero_si128    
#undef ssp_shuffle_epi32    
#undef ssp_shuffle_pd       
#undef ssp_shufflehi_epi16  
#undef ssp_shufflelo_epi16  
#undef ssp_sll_epi16        
#undef ssp_sll_epi32        
#undef ssp_sll_epi64        
#undef ssp_slli_epi16       
#undef ssp_slli_epi32       
#undef ssp_slli_epi64       
#undef ssp_slli_si128       
#undef ssp_sqrt_pd          
#undef ssp_sqrt_sd          
#undef ssp_sra_epi16        
#undef ssp_sra_epi32        
#undef ssp_srai_epi16       
#undef ssp_srai_epi32       
#undef ssp_srl_epi16        
#undef ssp_srl_epi32        
#undef ssp_srl_epi64        
#undef ssp_srli_epi16       
#undef ssp_srli_epi32       
#undef ssp_srli_epi64       
#undef ssp_srli_si128       
#undef ssp_store_pd         
#undef ssp_store_sd         
#undef ssp_store_si128      
#undef ssp_store1_pd        
#undef ssp_storeh_pd        
#undef ssp_storel_epi64     
#undef ssp_storel_pd        
#undef ssp_storer_pd        
#undef ssp_storeu_pd        
#undef ssp_storeu_si128     
#undef ssp_stream_pd        
#undef ssp_stream_si128     
#undef ssp_stream_si32      
#undef ssp_sub_epi16        
#undef ssp_sub_epi32        
#undef ssp_sub_epi64        
#undef ssp_sub_epi8         
#undef ssp_sub_pd           
#undef ssp_sub_sd           
#undef ssp_sub_si64         
#undef ssp_subs_epi16       
#undef ssp_subs_epi8        
#undef ssp_subs_epu16       
#undef ssp_subs_epu8        
#undef ssp_ucomieq_sd       
#undef ssp_ucomige_sd       
#undef ssp_ucomigt_sd       
#undef ssp_ucomile_sd       
#undef ssp_ucomilt_sd       
#undef ssp_ucomineq_sd      
#undef ssp_unpackhi_epi16   
#undef ssp_unpackhi_epi32   
#undef ssp_unpackhi_epi64   
#undef ssp_unpackhi_epi8    
#undef ssp_unpackhi_pd      
#undef ssp_unpacklo_epi16   
#undef ssp_unpacklo_epi32   
#undef ssp_unpacklo_epi64   
#undef ssp_unpacklo_epi8    
#undef ssp_unpacklo_pd      
#undef ssp_xor_pd           
#undef ssp_xor_si128        
#undef ssp_cvttss_si32      
#undef ssp_cvttps_pi32      
#undef ssp_maskmove_si64    
#undef ssp_avg_pu8          
#undef ssp_set1_ps          
#undef ssp_load1_ps         
#undef ssp_store1_ps        

// SSE3
#undef ssp_addsub_pd        
#undef ssp_addsub_ps        
#undef ssp_hadd_pd          
#undef ssp_hadd_ps          
#undef ssp_hsub_pd2         
#undef ssp_hsub_ps          
#undef ssp_lddqu_si128      
#undef ssp_loaddup_pd       
#undef ssp_movedup_pd       
#undef ssp_movehdup_ps      
#undef ssp_moveldup_ps      

// SSSE3
#undef ssp_abs_epi16        
#undef ssp_abs_epi32        
#undef ssp_abs_epi8         
#undef ssp_abs_pi16         
#undef ssp_abs_pi32         
#undef ssp_abs_pi8          
#undef ssp_alignr_epi8      
#undef ssp_alignr_pi8       
#undef ssp_hadd_epi16       
#undef ssp_hadd_epi32       
#undef ssp_hadd_pi16        
#undef ssp_hadd_pi32        
#undef ssp_hadds_epi16      
#undef ssp_hadds_pi16       
#undef ssp_hsub_epi16       
#undef ssp_hsub_epi32       
#undef ssp_hsub_pi16        
#undef ssp_hsub_pi32        
#undef ssp_hsubs_epi16      
#undef ssp_hsubs_pi16       
#undef ssp_maddubs_epi16    
#undef ssp_maddubs_pi16     
#undef ssp_mulhrs_epi16     
#undef ssp_mulhrs_pi16      
#undef ssp_shuffle_epi8     
#undef ssp_shuffle_pi8      
#undef ssp_sign_epi16       
#undef ssp_sign_epi32       
#undef ssp_sign_epi8        
#undef ssp_sign_pi16        
#undef ssp_sign_pi32        
#undef ssp_sign_pi8         

//SSE4A
#undef       ssp_extract_si64_SSE2          
#undef       ssp_extracti_si64_SSE2         
#undef       ssp_insert_si64_SSE2           
#undef       ssp_inserti_si64_SSE2          
#undef       ssp_stream_sd_SSE2             
#undef       ssp_stream_ss_SSE2             

// SSE4.1
#undef ssp_blend_epi16            
#undef ssp_blend_pd               
#undef ssp_blend_ps               
#undef ssp_blendv_epi8            
#undef ssp_blendv_pd              
#undef ssp_blendv_ps              
#undef ssp_ceil_pd                
#undef ssp_ceil_ps                
#undef ssp_ceil_sd                
#undef ssp_ceil_ss                
#undef ssp_cmpeq_epi64            
#undef ssp_cvtepi16_epi32         
#undef ssp_cvtepi16_epi64         
#undef ssp_cvtepi32_epi64         
#undef ssp_cvtepi8_epi16          
#undef ssp_cvtepi8_epi32          
#undef ssp_cvtepi8_epi64          
#undef ssp_cvtepu16_epi32         
#undef ssp_cvtepu16_epi64         
#undef ssp_cvtepu32_epi64         
#undef ssp_cvtepu8_epi16          
#undef ssp_cvtepu8_epi32          
#undef ssp_cvtepu8_epi64          
#undef ssp_dp_pd                  
#undef ssp_dp_ps                  
#undef ssp_extract_epi32          
#undef ssp_extract_epi64          
#undef ssp_extract_epi8           
#undef ssp_extract_ps             
#undef ssp_floor_pd               
#undef ssp_floor_ps               
#undef ssp_floor_sd               
#undef ssp_floor_ss               
#undef ssp_insert_epi32           
#undef ssp_insert_epi64           
#undef ssp_insert_epi8            
#undef ssp_insert_ps              
#undef ssp_max_epi32              
#undef ssp_max_epi8               
#undef ssp_max_epu16              
#undef ssp_max_epu32              
#undef ssp_min_epi32              
#undef ssp_min_epi8               
#undef ssp_min_epu16              
#undef ssp_min_epu32              
#undef ssp_minpos_epu16           
#undef ssp_mpsadbw_epu8           
#undef ssp_mul_epi32              
#undef ssp_mullo_epi32            
#undef ssp_packus_epi32           
#undef ssp_round_pd               
#undef ssp_round_ps               
#undef ssp_round_sd               
#undef ssp_round_ss               
#undef ssp_stream_load_si128      
#undef ssp_testc_si128            
#undef ssp_testnzc_si128          
#undef ssp_testz_si128            
                                  
//SSE4.2                          
#undef ssp_cmpestra               
#undef ssp_cmpestrc               
#undef ssp_cmpestri               
#undef ssp_cmpestrm               
#undef ssp_cmpestro               
#undef ssp_cmpestrs               
#undef ssp_cmpestrz               
#undef ssp_cmpgt_epi64            
#undef ssp_cmpistra               
#undef ssp_cmpistrc               
#undef ssp_cmpistri               
#undef ssp_cmpistrm               
#undef ssp_cmpistro               
#undef ssp_cmpistrs               
#undef ssp_cmpistrz               
#undef ssp_crc32_u16              
#undef ssp_crc32_u32              
#undef ssp_crc32_u64              
#undef ssp_crc32_u8               
#undef ssp_popcnt_u32             
#undef ssp_popcnt_u64 

// Arithmetic
#undef ssp_arithmetic_hadd4_epi16 
#undef ssp_arithmetic_hadd4_dup_ps

// Logical
#undef ssp_logical_bitwise_select 
   
//convert
#undef ssp_convert_3c_3p_epi8
#undef ssp_convert_3p_3c_epi8

#undef ssp_convert_3c_3p_epi16
#undef ssp_convert_3p_3c_epi16

#undef ssp_convert_3c_3p_epi32
#undef ssp_convert_3p_3c_epi32

#undef ssp_convert_4c_4p_epi8
#undef ssp_convert_4p_4c_epi8

#undef ssp_convert_4c_4p_epi16
#undef ssp_convert_4p_4c_epi16

#undef ssp_convert_4c_4p_epi32
#undef ssp_convert_4p_4c_epi32

//no header guard
