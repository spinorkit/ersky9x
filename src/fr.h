/****************************************************************************
*  Copyright (c) 2013 by Michael Blandford. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*  1. Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*  2. Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*  3. Neither the name of the author nor the names of its contributors may
*     be used to endorse or promote products derived from this software
*     without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
*  THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
*  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
*  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
*  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
*  SUCH DAMAGE.
*
****************************************************************************
* Other Authors:
 * - Andre Bernet
 * - Bertrand Songis
 * - Bryan J. Rentoul (Gruvin)
 * - Cameron Weeks
 * - Erez Raviv
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini
 * - Thomas Husterer
*
****************************************************************************/

// Special characters:
// �  use \300
// �  use \301
// �  use \302
// �  use \303
// �  use \304

#define ISTR_ON             "ON "
#define ISTR_OFF            "OFF"

#define ISTR_ALTEQ	         "Alt=" 
#define ISTR_TXEQ		       "Tx="
#define ISTR_RXEQ		       "Rx="
#define ISTR_TRE012AG	     "TRE012AG"

// ISTR_YELORGRED indexed 3 char each
#define ISTR_YELORGRED	     "\003---JauOraRou"
#define ISTR_A_EQ		       "A ="
#define ISTR_SOUNDS	       "\006Warn1 ""Warn2 ""Cheap ""Ring  ""SciFi ""Robot ""Chirp ""Tada  ""Crickt""Siren ""AlmClk""Ratata""Tick  ""Haptc1""Haptc2""Haptc3"
#define ISTR_SWITCH_WARN	   "Switch Warning"
// ISTR_TIMER exactly 5 chars long
#define ISTR_TIMER          "Timer"

// ISTR_PPMCHANNELS indexed 4 char each
#define ISTR_PPMCHANNELS	   "CH"

#define ISTR_MAH_ALARM      "mAh Alarm"


// er9x.cpp
// ********
#define ISTR_LIMITS		     "LIMITS"
#define ISTR_EE_LOW_MEM     "EEPROM low mem"
#define ISTR_ALERT		       "ALERT"
#define ISTR_THR_NOT_IDLE   "Throttle not idle"
#define ISTR_RST_THROTTLE   "Reset throttle"
#define ISTR_PRESS_KEY_SKIP "Press any key to skip"
#define ISTR_ALARMS_DISABLE "Alarms Disabled"
#define ISTR_OLD_VER_EEPROM " Old Version EEPROM   CHECK SETTINGS/CALIB"
#define ISTR_RESET_SWITCHES "Please Reset Switches"
#define ISTR_LOADING        "LOADING"
#define ISTR_MESSAGE        "MESSAGE"
#define ISTR_PRESS_ANY_KEY  "press any Key"
#define ISTR_MSTACK_UFLOW   "mStack uflow"
#define ISTR_MSTACK_OFLOW   "mStack oflow"

#ifdef PCBSKY
#define ISTR_CHANS_GV	     "\004P1  P2  P3  HALFFULLCYC1CYC2CYC3PPM1PPM2PPM3PPM4PPM5PPM6PPM7PPM8CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8 CH9 CH10CH11CH12CH13CH14CH15CH16CH17CH18CH19CH20CH21CH22CH23CH24SWCHGV1 GV2 GV3 GV4 GV5 GV6 GV7 THISSC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#define ISTR_CHANS_RAW	   "\004P1  P2  P3  HALFFULLCYC1CYC2CYC3PPM1PPM2PPM3PPM4PPM5PPM6PPM7PPM8CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8 CH9 CH10CH11CH12CH13CH14CH15CH16CH17CH18CH19CH20CH21CH22CH23CH24SWCH"
#endif
#ifdef PCBX9D
#define ISTR_CHANS_GV	     "\004P1  P2  SL  SR  HALFFULLCYC1CYC2CYC3PPM1PPM2PPM3PPM4PPM5PPM6PPM7PPM8CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8 CH9 CH10CH11CH12CH13CH14CH15CH16CH17CH18CH19CH20CH21CH22CH23CH24SWCHGV1 GV2 GV3 GV4 GV5 GV6 GV7 THISSC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#define ISTR_CHANS_RAW	   "\004P1  P2  SL  SR  HALFFULLCYC1CYC2CYC3PPM1PPM2PPM3PPM4PPM5PPM6PPM7PPM8CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8 CH9 CH10CH11CH12CH13CH14CH15CH16CH17CH18CH19CH20CH21CH22CH23CH24SWCH"
#endif

#define ISTR_CH	           "CH"
#define ISTR_TMR_MODE	     "\003OFFABSRUsRU%ELsEL%THsTH%ALsAL%P1 P1%P2 P2%P3 P3%"

// pers.cpp
// ********
#define ISTR_ME             "ME        "
#define ISTR_MODEL          "MODELE    "
#define ISTR_BAD_EEPROM     "Bad EEprom Data"
#define ISTR_EE_FORMAT      "EEPROM Formatting"
#define ISTR_GENWR_ERROR    "genwrite error"
#define ISTR_EE_OFLOW       "EEPROM overflow"

// templates.cpp
// ***********
#define ISTR_T_S_4CHAN      "4 Voies simple"
#define ISTR_T_TCUT         "T-Cut"
#define ISTR_T_STICK_TCUT   "Coupure Gaz"
#define ISTR_T_V_TAIL       "Empennage V"
#define ISTR_T_ELEVON       "Elevon\\Delta"
#define ISTR_T_HELI_SETUP   "Conf. Helico"
#define ISTR_T_GYRO         "Gyro Setup"
#define ISTR_T_SERVO_TEST   "Servo Test"

// menus.cpp
// ***********
#ifdef PCBSKY
#define ISTR_TELEM_ITEMS	   "\004----A1= A2= RSSITSSITim1Tim2Alt GaltGspdT1= T2= RPM FUELMah1Mah2CvltBattAmpsMah CtotFasVAccXAccYAccZVspdGvr1Gvr2Gvr3Gvr4Gvr5Gvr6Gvr7FwatRxV Hdg A3= A4= SC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#endif
#ifdef PCBX9D
#define ISTR_TELEM_ITEMS	   "\004----A1= A2= RSSISWR Tim1Tim2Alt GaltGspdT1= T2= RPM FUELMah1Mah2CvltBattAmpsMah CtotFasVAccXAccYAccZVspdGvr1Gvr2Gvr3Gvr4Gvr5Gvr6Gvr7FwatRxV Hdg A3= A4= SC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#endif
#define ISTR_TELEM_SHORT    "\004----TIM1TIM2BATTGvr1Gvr2Gvr3Gvr4Gvr5Gvr6Gvr7"
#define ISTR_GV             "GV"
#define ISTR_OFF_ON         "OFFON "
#define ISTR_HYPH_INV       "\003---INV"
#define ISTR_VERSION        "VERSION"
#define ISTR_TRAINER        "ECOLAGE"
#define ISTR_SLAVE          "\007Slave" 
#define ISTR_MENU_DONE      "[MENU] WHEN DONE"
#define ISTR_CURVES         "Courbes"
#define ISTR_CURVE          "Courbe"
#define ISTR_GLOBAL_VAR     "GLOBAL VAR"
#define ISTR_VALUE          "Value"
#define ISTR_PRESET         "PRESET"
#define ISTR_CV             "CV"
#define ISTR_LIMITS         "LIMITS"
#define ISTR_COPY_TRIM      "COPY TRIM [MENU]"
#define ISTR_TELEMETRY      "TELEMETRY"
#define ISTR_USR_PROTO      "UsrProto"
#ifdef REVX
#define ISTR_FRHUB_WSHHI    "\005FrHubWSHhiDSMx "
#else
#define ISTR_FRHUB_WSHHI    "\005FrHubWSHhi"
#endif
#define ISTR_MET_IMP        "\003MetImp"
#define ISTR_A_CHANNEL      "A  channel"
#define ISTR_ALRM           "alrm"
#define ISTR_TELEMETRY2     "TELEMETRY2"
#define ISTR_TX_RSSIALRM    "TxRSSIalrm"
#define ISTR_NUM_BLADES     "Num Blades"
#define ISTR_ALT_ALARM      "AltAlarm"
#define ISTR_OFF122400      "\003OFF122400"
#define ISTR_VOLT_THRES     "Volt Thres="
#define ISTR_GPS_ALTMAIN    "GpsAltMain"
#define ISTR_CUSTOM_DISP    "Custom Display"
#define ISTR_FAS_OFFSET     "FAS Offset"
#define ISTR_VARIO_SRC      "Vario: Source"
#define ISTR_VSPD_A2        "\004----vspdA2  SC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#define ISTR_2SWITCH        "\002Switch"
#define ISTR_2SENSITIVITY   "\002Sensitivity"
#define ISTR_GLOBAL_VARS    "GLOBAL VARS"
#ifdef PCBSKY
#define ISTR_GV_SOURCE      "\003---RtmEtmTtmAtmRENDIRPRFGAZAILP1 P2 P3 c1 c2 c3 c4 c5 c6 c7 c8 c9 c10c11c12c13c14c15c16c17c18c19c20c21c22c23c24SC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#endif
#ifdef PCBX9D
#define ISTR_GV_SOURCE      "\003---RtmEtmTtmAtmRENDIRPRFGAZAILP1 P2 SG SD c1 c2 c3 c4 c5 c6 c7 c8 c9 c10c11c12c13c14c15c16c17c18c19c20c21c22c23c24SC1 SC2 SC3 SC4 SC5 SC6 SC7 SC8 "
#endif
#define ISTR_TEMPLATES      "TEMPLATES"
#define ISTR_CHAN_ORDER     "Ordre voies RX"
#define ISTR_SP_RETA        " DPGA"
#define ISTR_CLEAR_MIXES    "CLEAR MIXES [MENU]"
#define ISTR_SAFETY_SW      "SECUR. SWITCHES"
#define ISTR_NUM_VOICE_SW   "Number Voice Sw"
#define ISTR_V_OPT1         "\007 8 Secs12 Secs16 Secs"
#define ISTR_VS             "VS"
#define ISTR_VOICE_OPT      "\006ON    OFF   BOTH  15Secs30Secs60SecsVaribl"
#define ISTR_CUST_SWITCH    "CUSTOM SWITCHES"
#define ISTR_S              "S"
#define ISTR_15_ON          "\015On"
#define ISTR_EDIT_MIX       "EDIT MIX "
#define ISTR_2SOURCE        "\002Source"
#define ISTR_2WEIGHT        "\002Weight"
#define ISTR_FMTRIMVAL      "FmTrimVal"
#define ISTR_OFFSET         "Offset"
#define ISTR_2FIX_OFFSET    "\002Fix Offset"
#define ISTR_FLMODETRIM     "\002FlModetrim"
#define ISTR_2TRIM          "\002Trim"
#define ISTR_15DIFF         "\015Diff"
#define ISTR_Curve          "Curve"
#define ISTR_2SWITCH        "\002Switch"
#define ISTR_2WARNING       "\002Warning"
#define ISTR_2MULTIPLEX     "\002Multpx"
#define ISTR_ADD_MULT_REP   "\010Ajoute  MultiplyRemplace"
#define ISTR_2DELAY_DOWN    "\002Retard bas"
#define ISTR_2DELAY_UP      "\002Retard haut"
#define ISTR_2SLOW_DOWN     "\002Ralenti bas"
#define ISTR_2SLOW_UP       "\002Ralenti haut"
#define ISTR_MAX_MIXERS     "Max mixers reach: 32"
#define ISTR_PRESS_EXIT_AB  "Press [EXIT] to abort"
#define ISTR_YES_NO         "\003YES\013NO"
#define ISTR_MENU_EXIT      "\003[MENU]\013[EXIT]"
#define ISTR_DELETE_MIX     "DELETE MIX?"
#define ISTR_MIX_POPUP      "EDIT\0INSERT\0COPY\0MOVE\0DELETE"
#define ISTR_MIXER          "MIXEUR"
// CHR_S S for Slow
#define ICHR_S              "S"
// CHR_D D for Delay
#define ICHR_D              "D"
// CHR_d d for differential
#define ICHR_d              "d"
#define ISTR_EXPO_DR        "EXPO/DR"
#define ISTR_4DR_MID        "\004DR Mid"
#define ISTR_4DR_LOW        "\004DR Low"
#define ISTR_4DR_HI         "\004DR Hi"
#define ISTR_2EXPO          "\002Expo"
#define ISTR_DR_SW1         "DrSw1"
#define ISTR_DR_SW2         "DrSw2"
#define ISTR_DUP_MODEL      "DUPLICATE MODELE"
#define ISTR_DELETE_MODEL   "DELETE MODEL"
#define ISTR_DUPLICATING    "Duplicating modele"
#define ISTR_SETUP          "SETUP"
#define ISTR_NAME           "Nom"
#define ISTR_VOICE_INDEX    "Voice Index\021MENU"
#define ISTR_TRIGGERA       "Trigger"
#define ISTR_TRIGGERB       "TriggerB"
//ISTR_COUNT_DOWN_UP indexed, 10 chars each
#define ISTR_COUNT_DOWN_UP  "\012Count DownCount Up  "
#define ISTR_T_TRIM         "Trim gaz"
#define ISTR_T_EXPO         "T-Expo"
#define ISTR_TRIM_INC       "Pas Trim"
// ISTR_TRIM_OPTIONS indexed 6 chars each
#define ISTR_TRIM_OPTIONS   "\006Exp   ExFineFine  MediumCoarse"
#define ISTR_TRIM_SWITCH    "Trim Sw"
#define ISTR_BEEP_CENTRE    "Beep Cnt"
#define ISTR_RETA123        "RETA123"
#define ISTR_PROTO          "Proto"
// ISTR_21_USEC after \021 max 4 chars
#define ISTR_21_USEC        "\021uSec"
#define ISTR_13_RXNUM       "\013RxNum"
// ISTR_23_US after \023 max 2 chars
#define ISTR_23_US          "\023uS"
// ISTR_PPMFRAME_MSEC before \015 max 9 chars, after max 4 chars
#define ISTR_PPMFRAME_MSEC  " Trame PPM\015mSec"
#define ISTR_SEND_RX_NUM    " Send Rx Number [MENU]"
#define ISTR_DSM_TYPE       " DSM Type"
#define ISTR_PPM_1ST_CHAN   " 1st Chan"
#define ISTR_SHIFT_SEL      " Shift Sel"
// ISTR_POS_NEG indexed 3 chars each
#define ISTR_POS_NEG        "\003POSNEG"
#define ISTR_E_LIMITS       "Limites et"
#define ISTR_Trainer        "Trainer"
#define ISTR_T2THTRIG       "T2ThTrig"
#define ISTR_AUTO_LIMITS    "Auto Limits"
// ISTR_1_RETA indexed 1 char each
#define ISTR_1_RETA         "\001RETA"
#define ISTR_FL_MODE        "FL MODE"
#define ISTR_SWITCH         "Switch"
#define ISTR_TRIMS          "Trims"
#define ISTR_MODES          "MODES"
#define ISTR_SP_FM0         " FM0"
#define ISTR_SP_FM          " FM"
#define ISTR_HELI_SETUP     "HELI SETUP"
#define ISTR_SWASH_TYPE     "Swash Type"
#define ISTR_COLLECTIVE     "Collective"
#define ISTR_SWASH_RING     "Swash Ring"
#define ISTR_ELE_DIRECTION  "Inv. longitud."
#define ISTR_AIL_DIRECTION  "Inv. lateral"
#define ISTR_COL_DIRECTION  "Inv. collectif"
#define ISTR_MODEL_POPUP    "SELECT\0COPIE\0MOVE\0SUPPRIMER\0BACKUP\0RESTORE"
#define ISTR_MODELSEL       "MODELESEL"
// ISTR_11_FREE after \011 max 4 chars
#define ISTR_11_FREE        "\011disp"
#define ISTR_CALIBRATION    "CALIBRATION"
// ISTR_MENU_TO_START after \003 max 15 chars
#define ISTR_MENU_TO_START  "\003[MENU] TO START"
// ISTR_SET_MIDPOINT after \005 max 11 chars
#define ISTR_SET_MIDPOINT   "\005SET MIDPOINT"
// ISTR_MOVE_STICKS after \003 max 15 chars
#define ISTR_MOVE_STICKS    "\003MOVE STICKS/POTS"
#define ISTR_ANA            "ANA"
#define ISTR_DIAG           "DIAG"
// ISTR_KEYNAMES indexed 5 chars each
#define ISTR_KEYNAMES       "\005 Menu Exit Down   UpRight Left"
#define ISTR_TRIM_M_P       "Trim- +"
// ISTR_OFF_PLUS_EQ indexed 3 chars each
#define ISTR_OFF_PLUS_EQ    "\003off += :="
// ISTR_CH1_4 indexed 3 chars each
#define ISTR_CH1_4          "\003ch1ch2ch3ch4"
#define ISTR_MULTIPLIER     "Multiplieur"
#define ISTR_CAL            "Cal"
#define ISTR_MODE_SRC_SW    "\003mode\012% src  sw"
#define ISTR_RADIO_SETUP    "RADIO SETUP"
#define ISTR_OWNER_NAME     "Owner Nom"
#define ISTR_BEEPER         "Beeper"
// ISTR_BEEP_MODES indexed 6 chars each
#define ISTR_BEEP_MODES     "\006Aucun ""NoKey ""xShort""Short ""Norm  ""Long  ""xLong "
#define ISTR_SOUND_MODE     "Sound Mode"
// ISTR_SPEAKER_OPTS indexed 10 chars each
#define ISTR_SPEAKER_OPTS   "\012Beeper    ""PiSpkr    ""BeeprVoice""PiSpkVoice""MegaSound "
#define ISTR_VOLUME         "Volume"
#define ISTR_SPEAKER_PITCH  " Speaker Pitch"
#define ISTR_HAPTICSTRENGTH " Vibreur Strength"
#define ISTR_CONTRAST       "Contraste"
#define ISTR_BATT_WARN      "Batterie warning" 
// ISTR_INACT_ALARM m for minutes after \023 - single char
#define ISTR_INACT_ALARM    "Inactivite alarm\023m"
#define ISTR_THR_REVERSE    "Inv. gaz"
#define ISTR_MINUTE_BEEP    "Minute beep"
#define ISTR_BEEP_COUNTDOWN "Beep countdown"
#define ISTR_FLASH_ON_BEEP  "Flash on beep"
#define ISTR_LIGHT_SWITCH   "Light switch"
#define ISTR_LIGHT_INVERT   "Backlight invert"
#define ISTR_LIGHT_AFTER    "Light off after"
#define ISTR_LIGHT_STICK    "Light on Stk Mv"
#define ISTR_SPLASH_SCREEN  "Splash screen"
#define ISTR_SPLASH_NAME    "Splash Name"
#define ISTR_THR_WARNING    "Throttle Warning"
#define ISTR_DEAFULT_SW     "Default Sw"
#define ISTR_MEM_WARN       "Memoire Warning"
#define ISTR_ALARM_WARN     "Alarm Warning"
#define ISTR_POTSCROLL      "PotScroll"
#define ISTR_STICKSCROLL    "StickScroll"
#define ISTR_BANDGAP        "BandGap"
#define ISTR_ENABLE_PPMSIM  "Enable PPMSIM"
#define ISTR_CROSSTRIM      "CrossTrim"
#define ISTR_INT_FRSKY_ALRM "Int. Frsky alarm"
#define ISTR_MODE           "Mode"

// SWITCHES_STR 3 chars each
#ifdef PCBSKY
#define ISWITCHES_STR "\003THRRUDELEID0ID1ID2AILGEATRNSW1SW2SW3SW4SW5SW6SW7SW8SW9SWASWBSWCSWDSWESWFSWGSWHSWISWJSWKSWLSWMSWNSWO"
#define IHW_SWITCHES_STR     "\002SASBSCSDSESFSGSH"
#define IHW_SWITCHARROW_STR  "\200-\201"
#endif
#ifdef PCBX9D
#define ISWITCHES_STR "\003SA\200SA-SA\201SB\200SB-SB\201SC\200SC-SC\201SD\200SD-SD\201SE\200SE-SE\201SF\200SF\201SG\200SG-SG\201SH\200SH\201SW1SW2SW3SW4SW5SW6SW7SW8SW9SWASWBSWCSWDSWESWFSWGSWHSWISWJSWKSWLSWMSWNSWO"
#define IHW_SWITCHES_STR "\002SASBSCSDSESFSGSH"
#define IHW_SWITCHARROW_STR "\200-\201"
#endif
#define ISWITCH_WARN_STR	   "Switch Warning"
// CURV_STR indexed 3 chars each
// c17-c24 added for timer mode A display
#define ICURV_STR           "\003---x>0x<0|x|f>0f<0|f|c1 c2 c3 c4 c5 c6 c7 c8 c9 c10c11c12c13c14c15c16c17c18c19c20c21c22c23c24"
// CSWITCH_STR indexed 7 chars each
#define ICSWITCH_STR        "\007----   v>ofs  v<ofs  |v|>ofs|v|<ofsAND    OR     XOR    ""v1==v2 ""v1!=v2 ""v1>v2  ""v1<v2  ""Latch  F-Flop TimeOffv\140=ofs"

#define ISWASH_TYPE_STR     "\006---   ""120   ""120X  ""140   ""90    "

#define ISTR_STICK_NAMES    "RUD ELE THR AIL "

#define ISTR_STAT           "STAT"
#define ISTR_STAT2          "STAT2"
// ISTR_TRIM_OPTS indexed 3 chars each
#define ISTR_TRIM_OPTS      "\003ExpExFFneMedCrs"
#define ISTR_TTM            "TTm"
#define ISTR_FUEL           "Fuel"
#define ISTR_12_RPM         "\012RPM"
#define ISTR_LAT_EQ         "Lat="
#define ISTR_LON_EQ         "Lon="
#define ISTR_ALT_MAX        "Alt=\011m   Max="
#define ISTR_SPD_KTS_MAX    "Spd=\011kts Max="
#define ISTR_11_MPH         "\011mph"

#define ISTR_SINK_TONES	   "Sink Tones"


// ersky9x strings
#define ISTR_ST_CARD_STAT   "SD CARD STAT"
#define ISTR_4_READY        "\004Ready"
#define ISTR_NOT            "NOT"
#define ISTR_BOOT_REASON    "BOOT REASON"
#define ISTR_6_WATCHDOG     "\006WATCHDOG"
#define ISTR_5_UNEXPECTED   "\005UNEXPECTED"
#define ISTR_6_SHUTDOWN     "\006SHUTDOWN"
#define ISTR_6_POWER_ON     "\006POWER ON"
// ISTR_MONTHS indexed 3 chars each
#define ISTR_MONTHS         "\003XxxJanFebMarAprMayJunJulAugSepOctNovDec"
#define ISTR_MENU_REFRESH   "[MENU] to refresh"
#define ISTR_DATE_TIME      "DATE-HEURE"
#define ISTR_SEC            "Sec."
#define ISTR_MIN_SET        "Min.\015Set"
#define ISTR_HOUR_MENU_LONG "Hour\012MENU LONG"
#define ISTR_DATE           "Date"
#define ISTR_MONTH          "Month"
#define ISTR_YEAR_TEMP      "Year\013Temp."
#define ISTR_YEAR           "Year"
#define ISTR_BATTERY        "BATTERY"
#define ISTR_Battery        "Battery"
#define ISTR_CURRENT_MAX    "Current\016Max"
#define ISTR_CPU_TEMP_MAX   "CPU temp.\014C Max\024C"
#define ISTR_MEMORY_STAT    "MEMORY STAT"
#define ISTR_GENERAL        "General"
#define ISTR_Model          "Modele"
#define ISTR_RADIO_SETUP2   "RADIO SETUP2"
#define ISTR_BRIGHTNESS     "Brightness"
#define ISTR_CAPACITY_ALARM "Capacity Alarm"
#define ISTR_BT_BAUDRATE    "Bt baudrate"
#define ISTR_ROTARY_DIVISOR "Rotary Divisor"
#define ISTR_STICK_LV_GAIN  "Stick LV Gain"
#define ISTR_STICK_LH_GAIN  "Stick LH Gain"
#define ISTR_STICK_RV_GAIN  "Stick RV Gain"
#define ISTR_STICK_RH_GAIN  "Stick RH Gain"
#define ISTR_NO_SINK_TONES  "No Sink Tones"
#define ISTR_BIND					  " Bind"
#define ISTR_RANGE					" Range Check"

#define ISTR_ALRMS_OFF			"Alarms Disabled"
#define ISTR_OLD_EEPROM			" Old Version EEPROM   CHECK SETTINGS/CALIB"
#define ISTR_TRIGA_OPTS			"OFFABSTHsTH%"
#define ISTR_CHK_MIX_SRC		"CHECK MIX SOURCES"

#define ISTR_BT_TELEMETRY		"BT Telemetry"
#define ISTR_FRSKY_COM_PORT "FrSky Com Port"
#define ISTR_INVERT_COM1		"Invert COM 1"
#define ISTR_LOG_SWITCH			"Log Switch"
#define ISTR_LOG_RATE				"Log Rate"
#define ISTR_6_BINDING			"\006BINDING"
#define ISTR_RANGE_RSSI			"RANGE CHECK RSSI:"
#define ISTR_FAILSAFE				"FAILSAFE"
#define ISTR_VOLUME_CTRL		"Volume Control"
#define ISTR_PROT_OPT				"\006PPM   PXX   DSM2  "
#define ISTR_TYPE						" Type"
#define ISTR_COUNTRY				" Country"
#define ISTR_SP_FAILSAFE		" Failsafe"
#define ISTR_PPM2_START			"PPM2 StartChan"
#define ISTR_FOLLOW					"Follow"
#define ISTR_PPM2_CHANNELS	"PPM2 Channels"
#define ISTR_FILTER_ADC			"Filter ADC"
#define ISTR_SCROLLING			"Scrolling"
#define ISTR_ALERT_YEL			"Alert [Yel]"
#define ISTR_ALERT_ORG			"Alert [Org]"
#define ISTR_ALERT_RED			"Alert [Red]"
#define ISTR_LANGUAGE				"Language"
