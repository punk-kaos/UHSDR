/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
 **                                                                                 **
 **                                        UHSDR                                    **
 **               a powerful firmware for STM32 based SDR transceivers              **
 **                                                                                 **
 **---------------------------------------------------------------------------------**
 **                                                                                 **
 **  File name:                                                                     **
 **  Description:                                                                   **
 **  Last Modified:                                                                 **
 **  Licence:		GNU GPLv3                                                      **
 ************************************************************************************/
/*
 * radio_management.h
 *
 *  Created on: 23.12.2016
 *      Author: danilo
 */

#ifndef DRIVERS_UI_RADIO_MANAGEMENT_H_
#define DRIVERS_UI_RADIO_MANAGEMENT_H_

#include "uhsdr_board.h"
// Frequency public structure
typedef struct DialFrequency
{
    // pot values
    //
    // user visible frequency AKA dial frequency
    // NOT the always LO frequency since we have an IQ TRX which
    // uses frequency translation in many cases.
    ulong   tune_old;           // current value
    ulong   tune_new;           // requested value

    // Current tuning step
    ulong   tuning_step;        // selected step by user
    ulong   selected_idx;       // id of step
    ulong   step_new;           // Eth driver req step

    ulong   update_skip;

    // TCXO routine factor/flag
    int     temp_factor;
    bool    temp_factor_changed;
    uchar   temp_enabled;
#define TCXO_MODE_MASK 0x0f
#define TCXO_UNIT_MASK 0xf0
#define TCXO_UNIT_C 0x00
#define TCXO_UNIT_F 0xf0


    // Virtual segments
    uint8_t dial_digits[9];
    // Second display
    uint8_t sdial_digits[9];

} DialFrequency;

// ------------------------------------------------
// Frequency public
extern DialFrequency               df;


inline uint8_t RadioManagement_TcxoGetMode()
{
    return (df.temp_enabled & TCXO_MODE_MASK);
}
inline void RadioManagement_TcxoSetMode(uint8_t mode)
{
    df.temp_enabled = (df.temp_enabled & ~TCXO_MODE_MASK) | (mode & TCXO_MODE_MASK) ;
}

inline bool RadioManagement_TcxoIsEnabled()
{
    return (RadioManagement_TcxoGetMode())!= TCXO_OFF;
}

inline void RadioManagement_TcxoSetUnit(uint8_t unit)
{
    df.temp_enabled = (df.temp_enabled & ~TCXO_UNIT_MASK) | (unit & TCXO_UNIT_MASK);
}

inline bool RadioManagement_TcxoIsFahrenheit()
{
    return (df.temp_enabled & TCXO_UNIT_MASK) == TCXO_UNIT_F;
}


typedef enum
{
    COUPLING_2200M = 0,
    COUPLING_630M,
    COUPLING_160M,
    COUPLING_80M,
    COUPLING_40M,
    COUPLING_20M,
    COUPLING_15M,
    COUPLING_6M,
    COUPLING_2M,
    COUPLING_70CM,
    COUPLING_23CM,
    COUPLING_MAX
} filter_band_t;

typedef struct BandInfo
{
    uint32_t tune;
    uint32_t size;
    const char* name;
} BandInfo;

extern const BandInfo bandInfo[MAX_BAND_NUM];
// FIXME: for technical reasons defined in ui_menu.c


// SWR and RF power meter public
typedef struct SWRMeter
{
    float fwd_calc;         // forward power readings in A/D units
    float rev_calc;         // reverse power readings in A/D units
    float fwd_pwr;          // forward power in watts current measurement
    float rev_pwr;          // reverse power in watts current measurement
    float fwd_pwr_avg;      // forward power in watts averaged
    float rev_pwr_avg;      // reverse power in watts averaged

    float fwd_dbm;          // forward power in dBm
    float rev_dbm;          // reverse power in dBm
    float vswr;             // vswr
    float vswr_dampened;        // dampened VSWR reading
    bool  pwr_meter_disp;       // TRUE if numerical FWD/REV power metering (in milliwatts) is to be displayed
    bool  pwr_meter_was_disp;   // TRUE if numerical FWD/REV power metering WAS displayed (used to clear it)
    uchar   p_curr;         // count used to update power meter
    uchar   sensor_null;        // used to null out the sensor offset voltage

    uint8_t coupling_calc[COUPLING_MAX];

    bool high_vswr_detected;

} SWRMeter;

// New modes need to be added so that configuration compatibility is retained
// it is also necessary to extend the cw_mode_map in radio_management.c to include new modes
enum {
    CW_OFFSET_USB_TX  =   0,        // CW in USB mode, display is TX frequency if received frequency was zero-beated
    CW_OFFSET_LSB_TX,               // CW in LSB mode, display is TX frequency if received frequency was zero-beated
    CW_OFFSET_AUTO_TX,              // Same as CW_OFFSET_USB_TX except LSB if frequency is < 10 MHz, USB if >= 10 MHz
    CW_OFFSET_USB_RX,               // CW in USB mode, display is RX frequency if received signal is matched to sidetone
    CW_OFFSET_LSB_RX,               // CW in LSB mode, display is RX frequency if received signal is matched to sidetone
    CW_OFFSET_AUTO_RX,              // Same as CW_OFFSET_USB_RX except LSB if frequency is < 10 MHz, USB if >= 10 MHz
    CW_OFFSET_USB_SHIFT,            // CW in USB mode, LO shifts, display is RX frequency if signal is matched to sidetone
    CW_OFFSET_LSB_SHIFT,            // CW in LSB mode, LO shifts, display is RX frequency if signal is matched to sidetone
    CW_OFFSET_AUTO_SHIFT,           // Same as "CW_OFFSET_USB_SHIFT" except LSB if frequency is <10 MHz, USB of >= 10 MHz
    CW_OFFSET_NUM                   // Number of Modes
};

#define CW_OFFSET_MODE_DEFAULT  CW_OFFSET_USB_TX   // Default CW offset setting

typedef enum {
    CW_SB_USB = 0,
    CW_SB_LSB,
    CW_SB_AUTO
} cw_sb_t;

typedef enum {
    CW_OFFSET_TX = 0,
    CW_OFFSET_RX,
    CW_OFFSET_SHIFT
} cw_dial_t;

typedef enum
{
    DigitalMode_None = 0,
#ifdef USE_FREEDV
    DigitalMode_FreeDV,
#endif
    DigitalMode_RTTY,
    DigitalMode_BPSK,
    DigitalMode_Num_Modes
} digital_modes_t;

typedef struct
{
    const char* label;
    const uint32_t enabled;
} digital_mode_desc_t;

// The following descriptor table has to be in the order of the enum digital_modes_t in  radio_management.h
// This table is stored in flash (due to const) and cannot be written to
// for operational data per mode [r/w], use a different table with order of modes
extern const digital_mode_desc_t digimodes[DigitalMode_Num_Modes];


typedef struct
{
    cw_dial_t dial_mode;
    cw_sb_t sideband_mode;
} cw_mode_map_entry_t;

extern const cw_mode_map_entry_t cw_mode_map[];

// SWR/Power meter
extern SWRMeter                    swrm;

inline bool RadioManagement_IsTxDisabled()
{
    return (ts.tx_disable > 0);
}

inline bool RadioManagement_IsTxDisabledBy(uint8_t whom)
{
    return ((ts.tx_disable & (whom)) > 0);
}

uint32_t RadioManagement_GetRealFreqTranslationMode(uint32_t txrx_mode, uint32_t dmod_mode, uint32_t iq_freq_mode);
uint8_t RadioManagement_GetBand(ulong freq);
bool RadioManagement_FreqIsInBand(const BandInfo* bandinfo, const uint32_t freq);
bool RadioManagement_PowerLevelChange(uint8_t band, uint8_t power_level);
bool RadioManagement_Tune(bool tune);
bool RadioManagement_UpdatePowerAndVSWR();
void RadioManagement_SetHWFiltersForFrequency(ulong freq);
void RadioManagement_ChangeCodec(uint32_t codec, bool enableCodec);
bool RadioManagement_ChangeFrequency(bool force_update, uint32_t dial_freq,uint8_t txrx_mode);
void RadioManagement_HandlePttOnOff();
void RadioManagement_MuteTemporarilyRxAudio();

uint32_t RadioManagement_NextNormalDemodMode(uint32_t loc_mode);
uint32_t RadioManagement_NextAlternativeDemodMode(uint32_t loc_mode);

Oscillator_ResultCodes_t RadioManagement_ValidateFrequencyForTX(uint32_t dial_freq);
bool RadioManagement_IsApplicableDemodMode(uint32_t demod_mode);
void RadioManagement_SwitchTxRx(uint8_t txrx_mode, bool tune_mode);
void RadioManagement_SetBandPowerFactor(uchar band);
bool RadioManagement_LSBActive(uint16_t dmod_mode);
bool RadioManagement_USBActive(uint16_t dmod_mode);
void RadioManagement_SetBandPowerFactor(uchar band);
void RadioManagement_SetPaBias();
bool RadioManagement_CalculateCWSidebandMode(void);
void RadioManagement_SetDemodMode(uint8_t new_mode);
void RadioManagement_HandleRxIQSignalCodecGain();
const cw_mode_map_entry_t* RadioManagement_CWConfigValueToModeEntry(uint8_t cw_offset_mode);
uint8_t RadioManagement_CWModeEntryToConfigValue(const cw_mode_map_entry_t* mode_entry);
bool RadioManagement_UsesBothSidebands(uint16_t dmod_mode);
bool RadioManagement_IsPowerFactorReduce(uint32_t freq);
void RadioManagement_ToggleVfoAB();

bool RadioManagement_FmDevIs5khz();
void RadioManagement_FmDevSet5khz(bool is5khz);

uint32_t RadioManagement_GetTXDialFrequency();
uint32_t RadioManagement_GetRXDialFrequency();
int32_t  RadioManagement_GetCWDialOffset();

void RadioManagement_Request_TxOn();
void RadioManagement_Request_TxOff();

bool RadioManagement_SwitchTxRx_Possible();

inline void RadioManagement_ToggleVfoMem()
{
    ts.vfo_mem_flag = ! ts.vfo_mem_flag;
}

inline bool is_demod_rtty()
{
	return ts.dmod_mode == DEMOD_DIGI && ts.digital_mode == DigitalMode_RTTY;
}

inline bool is_demod_psk()
{
	return ts.dmod_mode == DEMOD_DIGI && ts.digital_mode == DigitalMode_BPSK;
}

inline void RadioManagement_TxRxSwitching_Disable()
{
    ts.txrx_switching_enabled = false;
}

inline void RadioManagement_TxRxSwitching_Enable()
{
    ts.txrx_switching_enabled = true;
}

inline bool RadioManagement_TxRxSwitching_IsEnabled()
{
    return ts.txrx_switching_enabled;
}

#endif /* DRIVERS_UI_RADIO_MANAGEMENT_H_ */
