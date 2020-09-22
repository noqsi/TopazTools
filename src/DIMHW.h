#ifndef __DIMHW_H
#define __DIMHW_H

#include <stdint.h>

/****************** DECLARATIONS *********************/
#define DEF_MCA_INTFC_ALL				   0
#define DEF_MCA_INTFC_LIBUSB			   2
#define DEF_MCA_INTFC_ETHERNET			   3
#define DEF_MCA_INTFC_SIM				   999

#define DEF_MCA_PREFIX_USB			   "USB"
#define DEF_MCA_PREFIX_ETH			   "ETH"
#define DEF_MCA_PREFIX_SIM			   "SIM"

#define DEF_MCA_STRING_LENGTH            256

// Command definitions
#define DEF_MCA_COMMAND_GETPARAM           1
#define DEF_MCA_COMMAND_SETPARAM           2
#define DEF_MCA_COMMAND_STARTACQ           3
#define DEF_MCA_COMMAND_STOPACQ            4
#define DEF_MCA_COMMAND_GETACQSTATUS       5
#define DEF_MCA_COMMAND_CLEARMEM           6
#define DEF_MCA_COMMAND_CLEARTIME          7
#define DEF_MCA_COMMAND_CLEARALL           8
#define DEF_MCA_COMMAND_SETTESTMODE        9
#define DEF_MCA_COMMAND_ARMSCOPE          10
#define DEF_MCA_COMMAND_GETSCOPESTATUS    11
#define DEF_MCA_COMMAND_READSPECTRUM      12
#define DEF_MCA_COMMAND_READSCOPE         13
#define DEF_MCA_COMMAND_SAVESETTINGS      14
#define DEF_MCA_COMMAND_RESTOREDEFAULTS   15
#define DEF_MCA_COMMAND_READLISTEVENTS    16
#define DEF_MCA_COMMAND_SAVEDEFAULTS	  17

// Parameter definitions
#define DEF_MCA_PARAM_DEV_NAME             0		// String
#define DEF_MCA_PARAM_SERIAL_NUMBER        1		// String
#define DEF_MCA_PARAM_FW_VERSION           2		// String
#define DEF_MCA_PARAM_FW_DATE              3		// String
#define DEF_MCA_PARAM_PROD_DATE            4		// String
#define DEF_MCA_PARAM_MCA_MODE             5		// Int32
#define DEF_MCA_PARAM_NUM_CHANNELS         6		// Int32
#define DEF_MCA_PARAM_PHA_LLD              7		// Int32
#define DEF_MCA_PARAM_PHA_ULD              8		// Int32
#define DEF_MCA_PARAM_ACQ_PRESET           9		// Int32 (0.1second) Float
#define DEF_MCA_PARAM_PRESET_TIME          9		// Int32 (0.1second) Float
#define DEF_MCA_PARAM_ACQ_MODE            10		// Int32
#define DEF_MCA_PARAM_INP_POLARITY        11		// Int32
#define DEF_MCA_PARAM_GAIN_DIGITAL        12		// Int32
#define DEF_MCA_PARAM_GAIN_COARSE         13		// Int32
#define DEF_MCA_PARAM_GAIN_FINE           14		// Int32
#define DEF_MCA_PARAM_RISE_TIME           15		// Int32
#define DEF_MCA_PARAM_FLAT_TOP            16		// Int32
#define DEF_MCA_PARAM_PZ_ADJ              17		// Int32
#define DEF_MCA_PARAM_DIGITAL_PZ_ADJ      17		// Int32
#define DEF_MCA_PARAM_THRESHOLD           18		// Int32
#define DEF_MCA_PARAM_BLR_ENABLE          19		// Int32
#define DEF_MCA_PARAM_PUR_ENABLE          20		// Int32
#define DEF_MCA_PARAM_HV_VALUE            21		// Int32
#define DEF_MCA_PARAM_HV_STATUS           22		// Int32
#define DEF_MCA_PARAM_SCOPE_TRIG_LVL      23		// Int32
#define DEF_MCA_PARAM_SCOPE_WAVEFORM      24		// Int32
#define DEF_MCA_PARAM_CALIBRATION         25		// Float[]
#define DEF_MCA_PARAM_MCS_CHANNELS        26		// Int32
#define DEF_MCA_PARAM_MCS_CURRENT_CHANNEL 27		// Int32
#define DEF_MCA_PARAM_PRESET_COUNTS       28		// Int32
#define DEF_MCA_PARAM_CURRENT_COUNTS      29		// Int32
#define DEF_MCA_PARAM_ACQ_MODE_EX         30		// Int32 (bits)
#define DEF_MCA_PARAM_PHA_PRESET_LLD      31		// Int32
#define DEF_MCA_PARAM_PHA_PRESET_ULD      32		// Int32
#define DEF_MCA_PARAM_EXT_COUNTS          33		// Int32
#define DEF_MCA_PARAM_EXT_IO_MODE         34		// Int32
#define DEF_MCA_PARAM_ICR_COUNTS          35		// Int32
#define DEF_MCA_PARAM_HW_PZ_ADJ           36		// Int32
#define DEF_MCA_PARAM_ANALOG_PZ_ADJ       36		// Int32
#define DEF_MCA_PARAM_TRP_COUNTS          37		// Int32
#define DEF_MCA_PARAM_OCR_COUNTS          38		// Int32
#define DEF_MCA_PARAM_PUR_GUARD           39		// Int32
#define DEF_MCA_PARAM_TRP_GUARD           40		// Int32
#define DEF_MCA_PARAM_LT_TRIM             41		// Int32
#define DEF_MCA_PARAM_ADC_SAMPLING_RATE   42		// Int32
#define DEF_MCA_PARAM_TIMING_INFO         43		// Int32[]
#define DEF_MCA_PARAM_HV_INFO             44		// Int32[]
#define DEF_MCA_PARAM_LIST_MODE           45		// Int32
#define DEF_MCA_PARAM_SCOPE_TRIG_SRC      46		// Int32
#define DEF_MCA_PARAM_DIFF_SEL            47        // Int32
#define DEF_MCA_PARAM_GPIO1_MODE          48		// Int32
#define DEF_MCA_PARAM_GPIO2_MODE          49		// Int32
#define DEF_MCA_PARAM_BLR_ALPHA           50        // Int32
#define DEF_MCA_PARAM_HV_INHIBIT_MODE     51        // Int32
#define DEF_MCA_PARAM_SCOPE_CLOCK_DIV     52        // Int32

#define DEF_MCA_PARAM_NETBIOS_NAME       100		// String
#define DEF_MCA_PARAM_DEFAULT_IP         101		// UInt32[]
#define DEF_MCA_PARAM_REMOTE_IP          102		// UInt32
#define DEF_MCA_PARAM_REMOTE_PORT        103		// UInt16

#define DEF_MCA_PARAM_USERID             250		// String
#define DEF_MCA_PARAM_GROUPID			 251		// String
#define DEF_MCA_PARAM_USERDATA			 252		// UInt8[]

#define DEF_MCA_PARAM_BOOTLOADER         254		// UInt32

// Info string indexes
#define DEF_MCA_INFO_DEVICE_PATH         0
#define DEF_MCA_INFO_DEVICE_NAME         1
#define DEF_MCA_INFO_DEVICE_TYPE         2
#define DEF_MCA_INFO_SERIAL_NUMBER       3
#define DEF_MCA_INFO_USER_NAME           4
#define DEF_MCA_INFO_GROUP_NAME          5

// Acquisition modes
#define DEF_MCA_ACQ_MODE_REAL_TIME       0x00
#define DEF_MCA_ACQ_MODE_LIVE_TIME       0x01
#define DEF_MCA_ACQ_MODE_TIME            0x02
#define DEF_MCA_ACQ_MODE_COUNTS          0x04
#define DEF_MCA_ACQ_MODE_EXT_CONTROL     0x08

// Acquisition status
#define DEF_MCA_ACQ_STATUS_STOPPED       0x00
#define DEF_MCA_ACQ_STATUS_ACQUIRING     0x01
#define DEF_MCA_ACQ_STATUS_WAITING       0x02
#define DEF_MCA_ACQ_STATUS_STANDBY       0x04

// GPIO functions
#define DEF_MCA_GPIO_NOP                     0         // No operation
#define DEF_MCA_GPIO_EXT_COUNTER_1_INPUT     1
#define DEF_MCA_GPIO_EXT_COUNTER_2_INPUT     2
#define DEF_MCA_GPIO_ROI_1_OUTPUT            3
#define DEF_MCA_GPIO_ROI_2_OUTPUT            4
#define DEF_MCA_GPIO_ICR_OUTPUT              5
#define DEF_MCA_GPIO_OCR_OUTPUT              6
#define DEF_MCA_GPIO_TRP_INPUT               7
#define DEF_MCA_GPIO_TRP_OUTPUT              8
#define DEF_MCA_GPIO_HV_INHIBIT_INPUT        9
#define DEF_MCA_GPIO_HV_STATUS_OUTPUT        10
#define DEF_MCA_GPIO_ACQ_START_INPUT         11
#define DEF_MCA_GPIO_ACQ_STOP_INPUT          12
#define DEF_MCA_GPIO_ACQ_START_STOP_INPUT    13
#define DEF_MCA_GPIO_ACQ_SUSPEND_INPUT       14
#define DEF_MCA_GPIO_ACQ_STANDBY_OUTPUT      15
#define DEF_MCA_GPIO_ACQ_STATUS_OUTPUT       16
#define DEF_MCA_GPIO_ACQ_START_STOP_OUTPUT   17
#define DEF_MCA_GPIO_ACQ_WAITING_OUTPUT      18
#define DEF_MCA_GPIO_MCS_CHANNEL_ADV_INPUT   19
#define DEF_MCA_GPIO_MCS_CHANNEL_ADV_OUTPUT  20
#define DEF_MCA_GPIO_MCS_READY_OUTPUT        21
#define DEF_MCA_GPIO_MCS_SWEEP_ADV_INPUT     22
#define DEF_MCA_GPIO_MCS_SWEEP_ADV_OUTPUT    23
#define DEF_MCA_GPIO_COINCIDENCE_INPUT       24
#define DEF_MCA_GPIO_ANTICOINCIDENCE_INPUT   25
#define DEF_MCA_GPIO_LT_GATE_OUTPUT          26
#define DEF_MCA_GPIO_TLIST_SYNC_INPUT        27
#define DEF_MCA_GPIO_TLIST_SYNC_OUTPUT       28
#define DEF_MCA_GPIO_PULSE_GEN_1_OUTPUT      29
#define DEF_MCA_GPIO_PULSE_GEN_2_OUTPUT      30
#define DEF_MCA_GPIO_EXT_USER_1_INPUT        31
#define DEF_MCA_GPIO_EXT_USER_2_INPUT        32
#define DEF_MCA_GPIO_USER_OUTPUT             33
#define DEF_MCA_GPIO_MCS_COUNTER_INPUT       34
#define DEF_MCA_GPIO_PHA_GROUP_SELECT_INPUT  35
#define DEF_MCA_GPIO_PHA_GROUP_SELECT_OUTPUT 36

#define DEF_MCA_GPIO_POLARITY_POSITIVE       0x0000
#define DEF_MCA_GPIO_POLARITY_NEGATIVE       0x8000

#define DEF_MCA_HV_INHIBIT_ENABLED           0x0001
#define DEF_MCA_HV_INHIBIT_POLARITY_POSITIVE 0x0000
#define DEF_MCA_HV_INHIBIT_POLARITY_NEGATIVE 0x8000

// Error codes
#define MCA_SUCCESS						 0
#define MCA_ERROR_NOT_CONNECTED			-1
#define MCA_ERROR_ALREADY_OPEN			-2
#define MCA_ERROR_INVALID_SOCKET		-3
#define MCA_ERROR_BIND_FAILED			-4
#define MCA_ERROR_INVALID_PARAMETER		-5
#define MCA_ERROR_INVALID_ARGUMENT		-6
#define MCA_ERROR_NOT_SUPPORTED			-7
#define MCA_ERROR_CONNECTION_FAILED		-8
#define MCA_ERROR_CONNECTION_CLOSED		-9
#define MCA_ERROR_INVALID_RESPONSE		-10
#define MCA_ERROR_SEND_FAILED			-11
#define MCA_ERROR_RECEIVE_FAILED		-12
#define MCA_ERROR_MCA_FAILED			-13
#define MCA_ERROR_INVALID_DEVICE		-14
#define MCA_ERROR_INVALID_HANDLE		-15
#define MCA_ERROR_OUT_OF_RANGE			-16

/****************** PROTOTYPES *********************/
// MCA functions

#ifndef WIN32
#define __stdcall
#endif

#ifndef HANDLE
typedef void* HANDLE;
#endif

#ifdef __cplusplus
extern "C" {
#else
// C definition for bool
typedef int bool;
#define true 1
#define false 0
#endif

// Open/Close
int32_t __stdcall FindDevices(int32_t DeviceType);
int32_t __stdcall FindDevicesEx(int32_t DeviceType, uint32_t Timeout, uint32_t NewSearch);
int32_t __stdcall GetDeviceInfo(int32_t InterfaceNr, char *DevicePath, int32_t DevicePathSize, char *DeviceName, int32_t DeviceNameSize, char *Serial, int32_t SerialSize, int32_t *DeviceType);
int32_t __stdcall GetDeviceInfoEx(int32_t InterfaceNr, char *Info, uint32_t InfoSize, uint32_t InfoIndex);
int32_t __stdcall OpenDevice(char *DevicePath, int32_t DeviceType, HANDLE *DeviceHandle);
int32_t __stdcall OpenDeviceEx(char *DevicePath, int32_t DeviceType, HANDLE *DeviceHandle, uint32_t Timeout);
int32_t __stdcall CloseDevice(HANDLE DeviceHandle);

// Get parameter
int32_t __stdcall GetParam(HANDLE DeviceHandle, int32_t ParamId, void *ParamValue, int32_t ParamSize);
// Set parameter
int32_t __stdcall SetParam(HANDLE DeviceHandle, int32_t ParamId, void *ParamValue, int32_t ParamSize);
// Start acquisition
int32_t __stdcall StartAcquisition(HANDLE DeviceHandle);
// Stop acquisition
int32_t __stdcall StopAcquisition(HANDLE DeviceHandle);
// Get acquisition status
int32_t __stdcall GetAcquisitionStatus(HANDLE DeviceHandle, uint32_t *AcquisitionStatus);
// Clear memory
int32_t __stdcall ClearMemory(HANDLE DeviceHandle);
// Clear acq time
int32_t __stdcall ClearTime(HANDLE DeviceHandle);
// Clear everything
int32_t __stdcall ClearAll(HANDLE DeviceHandle);
// Internal testing
int32_t __stdcall SetTestMode(HANDLE DeviceHandle, int32_t OnOff, int32_t Rate);
// Arm the scope
int32_t __stdcall ArmScope(HANDLE DeviceHandle);
// Get scope status
int32_t __stdcall GetScopeStatus(HANDLE DeviceHandle, uint32_t *ScopeStatus);
// Get the spectrum
int32_t __stdcall ReadSpectrum(HANDLE DeviceHandle, uint32_t *Spectrum, uint32_t *NrOfChannels, float *ElapsedRT, float *ElapsedLT);
// Get the LIST/TLIST events
int32_t __stdcall ReadListEvents(HANDLE DeviceHandle, uint32_t *List, uint32_t MaxNrOfEvents, uint32_t *NrOfEvents, uint32_t *Overflow);
// Get scope values
int32_t __stdcall ReadScope(HANDLE DeviceHandle, int16_t *Waveform);
int32_t __stdcall ReadScopeEx(HANDLE DeviceHandle, int16_t *Ch1Waveform, int16_t *Ch2Waveform, uint16_t *DigitalBits);
// Save settings into device's EEPROM
int32_t __stdcall SaveSettings(HANDLE DeviceHandle);
// Restore factory defaults
int32_t __stdcall RestoreDefaults(HANDLE DeviceHandle);
// Direct access to device, to be used by specialized software (firmware updates and such)
int32_t __stdcall DirectIO(HANDLE DeviceHandle, uint8_t *Buffer, int32_t Length, int32_t Mode);

#ifdef __cplusplus
}
#endif


#endif  // __DIMHW_H
