/**
 * @file tkl_isp.h
 * @brief isp
 * @version 1.0.0
 * @date 2021-11-08
 *
 * @copyright Copyright 2018-2021 Tuya Inc. All Rights Reserved.
 *
 */

#ifndef __TKL_ISP_H__
#define __TKL_ISP_H__

#include "tuya_cloud_types.h"
#include "tkl_media.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
    AUTO_MODE = 0,
    DAY_MODE,
    NIGHT_MODE, 
    COLOR_AUTO_MODE,                                  // color mode - auto
    COLOR_DAY_MODE,                                   // color mode - day
    COLOR_NIGHT_MODE,                                 // color mode - night
    MODE_MAX,
}TKL_ISP_DN_MODE_E;                                   // day and night mode

typedef enum
{
	FLICKER_TYPE_DISABLE = 0,                         // disable antiflicker
	FLICKER_TYPE_50HZ = 1,                            // 50Hz
	FLICKER_TYPE_60HZ = 2,                            // 60Hz
	FLICKER_TYPE_AUTO = 3,                            // auto mode
	FLICKER_TYPE_MAX,	   
}TKL_ISP_FLICKER_TYPE_E;                              // antiflicker mode

typedef enum 
{
    FIG_STYLE_DAY,
    FIG_STYLE_NIGHT, 
    FIG_STYLE_MAX,
}TKL_ISP_FIG_STYLE_MODE_E;

typedef struct
{
    UINT32_T brightness;                              // brightness
    UINT32_T saturation;                              // saturation
    UINT32_T contrast;                                // contrast
    UINT32_T sharpness;                               // sharpness
    UINT32_T gamma;                                   // gamma
}TKL_ISP_FIG_STYLE_CONFIG_T;                          // user style config 

typedef struct                                            
{                                                         
    UINT32_T awbMode;                                 // AWB mode, 0-auto, 1-manual, 2-extend style(warm/cool/natural)
    UINT32_T manualRGain;                             // manual - RGain
    UINT32_T manualGGain;                             // manual - GGain
    UINT32_T manualBGain;                             // manual - BGain
    UINT32_T awbExtendStyle;                          /* extend style，0-2700K，1-3500K，2-4100K，3-5000K，4-6500K */
}TKL_ISP_AWB_CONFIG_T;                                /* user AWB style config */

typedef struct                                            
{                                                         
    UINT32_T wdrMode;                                 // WDR mode, 0-disable, 1-auto, 2-manual 
    UINT32_T autoWdrStr;                              // auto WDR strength 
    UINT32_T manualWdrStr;                            // manual WDR strength
}TKL_ISP_WDR_CONFIG_T;                                // user WDR style config

typedef struct                                            
{                                                         
    UINT32_T denoiseMode;                             // denoise mode, 0-auto, 1-adjustable
    UINT32_T tempDenoiseStr;                          // time domain denoise strength
    UINT32_T specDenoiseStr;                          // space domain denoise strength
}TKL_ISP_DENOISE_CONFIG_T;                            // user denoise config

typedef struct                                            
{                                                         
    UINT32_T flipMode;                                // flip, 0-disable, 1-enable
    UINT32_T mirrorMode;                              // mirror, 0-disable, 1-enable
}TKL_ISP_MIRROR_FLIP_CONFIG_T;                        // user mirror and flip config

typedef struct                                            
{                                                         
    INT32_T cur_irmode;                               // current dn mode
    UINT32_T dayToNight;                              // day to night threshold
    UINT32_T nightToDay;                              // night to day threshold
    UINT32_T dnSwitchOffset;                          // day and night switch offset
    FLOAT_T offsetR[2];                               // offsetR，R[0] default 0.01
    FLOAT_T offsetG[2];                               // offsetG，G[0] default 0.01
    FLOAT_T offsetB[2];                               // offsetB，B[0] default 0.01
    FLOAT_T coffR[6];                                 // coefficient - R
    FLOAT_T coffG[6];                                 // coefficient - G
    FLOAT_T coffB[6];                                 // coefficient - B
}TKL_ISP_DN_SWITCH_CONFIG_T;                          // ADN config   

/*ISP数据格式*/
typedef struct
{
    FLOAT_T  coffR[6];                                // coefficient - R
    FLOAT_T  coffG[6];                                // coefficient - G
    FLOAT_T  coffB[6];                                // coefficient - B
    UINT16_T GlobalR;                                 // global R mean
    UINT16_T GlobalG;                                 // global G mean
    UINT16_T GlobalB;                                 // global B mean
    UINT16_T RGain;                                   // RGain
    UINT16_T BGain;                                   // BGain
    UINT16_T GrGain;                                  // GrGain
    UINT16_T GbGain;                                  // GbGain
    INT32_T ExpTime;                                  // sensor exposure time
    INT32_T AGain;                                    // sensor analog gain
    INT32_T DGain;                                    // sensor digital gain
    INT32_T ISPDGain;                                 // ISP gain
    INT32_T ISO;                                      // sensor total gain, again*dgain*ispdgain
    INT32_T OverExpFlag;                              // over exposure flag
    FLOAT_T RGBComponent;                             // sum of RGB
    FLOAT_T Illumination;                             // temporary illumination
    FLOAT_T Exposure;                                 // total exposure value
}TKL_ISP_DN_SWITCH_CALC_DATA_T;

typedef struct
{
	FLOAT_T R_Return;
	FLOAT_T G_Return;
	FLOAT_T B_Return;
}TKL_ISP_DN_RETURN_T;

typedef struct                                            
{                                                         
    UINT32_T smartirMode;                             // SMART-IR mode, 0-disable, 1-auto, 2-manual
    UINT32_T smartirHtoL[6];                          // high to low power threshold
    UINT32_T smartirLtoH[6];                          // low to high power threshold
    UINT32_T smartirPower[6];                         // power of every stages
    UINT32_T manualSmartirStr;                        // manual smartit strength
}TKL_ISP_SMARTIR_CONFIG_T;                            // SMART-IR config

typedef struct                                            
{                                                         
    UINT32_T shadingMode;                             // shading mode, 0-disable, 1-enable
    UINT32_T shadingR[255];                             
    UINT32_T shadingG[255];                               
    UINT32_T shadingB[255];                           
}TKL_ISP_SHADING_CONFIG_T;                            // shading config

typedef struct                                            
{                                                         
    UINT32_T defogMode;                               // defog mode, 0-disable, 1-enable
    UINT32_T autoDefogStr;                            // defog strength
}TKL_ISP_RESERVED_CONFIG_T;                           // defog config

typedef struct                                            
{                                                         
    UINT32_T ispLogEnable;                            // isp debug log, 0-disable, 1-enable
    UINT32_T ispLogLevel;                             // isp debug level
}TKL_ISP_DEBUG_CONFIG_T;                              // isp debug config

typedef struct
{
    INT32_T irmode;                                       // day and night mode
    TKL_ISP_FIG_STYLE_CONFIG_T isp_fig_style_day;         // user style config in day
    TKL_ISP_FIG_STYLE_CONFIG_T isp_fig_style_night;       // user style config in night
    TKL_ISP_AWB_CONFIG_T isp_awb_config;                  // user awb style config
    TKL_ISP_WDR_CONFIG_T isp_wdr_config;                  // user wdr style config 
    TKL_ISP_DENOISE_CONFIG_T isp_denoise_config;          // user denoise config
    TKL_ISP_MIRROR_FLIP_CONFIG_T isp_flip_config;         // user mirror and flip config
    TKL_ISP_DN_SWITCH_CONFIG_T isp_dn_switch_config;      // ADN config 
    TKL_ISP_SMARTIR_CONFIG_T isp_smartir_config;          // SMART-IR config  
    TKL_ISP_SHADING_CONFIG_T isp_shading_config;          // shading config
    TKL_ISP_RESERVED_CONFIG_T isp_reserved_config;        // reserved config
}TKL_ISP_PARAM_INFO_T;                                    // isp param  

typedef struct
{
    /*AWB*/
    INT32_T isAwbStable;
    UINT16_T colorTemp;
    UINT16_T RGain;
    UINT16_T BGain;
    /*AE*/
    INT32_T isAeStable;
    UINT32_T US;
    UINT32_T SensorGain;
    UINT32_T ISPGain;
    UINT32_T BV;
    UINT32_T SceneTarget;
    /*ADN*/
    UINT32_T dayToNight;
    UINT32_T nightToDay;
    UINT32_T Illumination;
}TKL_ISP_LOG_INFO_T;                                       // isp debug log info

/**
* @brief vi load isp file
* 
* @param[in] irmode: DN mode, 0-AUTO_MODE, 1-DAY_MODE, 2-NIGHT_MODE
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_load_isp_file(TKL_ISP_DN_MODE_E irmode);

/**
* @brief vi isp get antiflicker
* 
* @param[in] chn: vi chn
* @param[out] *eAntiFlicker: antiflicker mode, 0-disable,1-50hz,2-60hz,3-auto
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_get_antiflicker(TKL_VI_CHN_E chn, TKL_ISP_FLICKER_TYPE_E *eAntiFlicker);

/**
* @brief vi isp set antiflicker
* 
* @param[in] chn: vi chn
* @param[in] eAntiFlicker: antiflicker mode, 0-disable,1-50hz,2-60hz,3-auto
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_set_antiflicker(TKL_VI_CHN_E chn, TKL_ISP_FLICKER_TYPE_E eAntiFlicker);

/**
* @brief vi isp set color to gray
* 
* @param[in] chn: vi chn
* @param[in] gray_flag: gray_flag, 0-color video mode, 1-gray video mode
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_set_color_to_gray(TKL_VI_CHN_E chn, int gray_flag);

/**
* @brief vi dnswitch get illumin
* 
* @param[in] chn: vi chn
* @param[in] irmode: DN mode, 0-AUTO_MODE, 1-DAY_MODE, 2-NIGHT_MODE
* @param[out] *illumin_result: Illumination result
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_dnswitch_get_illumin(TKL_VI_CHN_E chn, TKL_ISP_DN_MODE_E irmode, INT32_T *illumin_result);

/**
* @brief vi isp get sensor fps
* 
* @param[in] chn: vi chn
* @param[out] *sensor_fps: sensor fps (non codec fps),this fps can update sensor max exposure
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_get_sensor_fps(TKL_VI_CHN_E chn, INT32_T *sensor_fps);

/**
* @brief vi isp set sensor fps
* 
* @param[in] chn: vi chn
* @param[in] sensor_fps: sensor fps (non codec fps),this interface can update sensor max exposure
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_set_sensor_fps(TKL_VI_CHN_E chn, INT32_T sensor_fps);

/**
* @brief vi isp get param
* 
* @param[in] chn: vi chn
* @param[out] *pstISPParam: ISP param info
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_get_param(TKL_VI_CHN_E chn, TKL_ISP_LOG_INFO_T *pstISPParam);

/**
* @brief set figure style config
* 
* @param[in] chn: vi chn
* @param[in] mode: daynight mode
* @param[in] config: style config
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_set_fig_style_config(TKL_VI_CHN_E chn, TKL_ISP_FIG_STYLE_MODE_E mode, TKL_ISP_FIG_STYLE_CONFIG_T *config);

/**
* @brief get figure style config
* 
* @param[in] chn: vi chn
* @param[in] mode: daynight mode
* @param[out] config: style config
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_get_fig_style_config(TKL_VI_CHN_E chn, TKL_ISP_FIG_STYLE_MODE_E mode, TKL_ISP_FIG_STYLE_CONFIG_T *config);

/**
* @brief vi isp set WDR
* 
* @param[in] chn: vi chn
* @param[in] mode: WDR mode, 0-disable, 1-auto, 2-manual 
* @param[in] strength: WDR strength, [0, 100]
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
*/
OPERATE_RET tkl_vi_isp_set_wdr(TKL_VI_CHN_E chn, INT32_T mode, INT32_T strength);

/**
* @brief vi isp get WDR params
* 
* @param[in] chn: vi chn
* @param[out] *mode: WDR mode, 0-disable, 1-auto, 2-manual 
* @param[out] *strength: WDR strength
*
* @return OPRT_OK on success. Others on error, please refer to tkl_error_code.h
* */
OPERATE_RET tkl_vi_isp_get_wdr(TKL_VI_CHN_E chn, INT32_T *mode, INT32_T *strength);

#ifdef __cplusplus
} // extern "C"
#endif

#endif 
