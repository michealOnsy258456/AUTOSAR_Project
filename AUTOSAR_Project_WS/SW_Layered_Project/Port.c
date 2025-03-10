/*
 * Port_PBcfg.h
 *
 *  Created on: Mar 3, 2020
 *      Author: micheal_onsy
 */
#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
		|| (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
		|| (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED ;
STATIC Port_ConfigChannel *port_PortChannels = NULL_PTR;

/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr-Pointer to configuration set.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the Port Driver module.
 ************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr)
{
	uint8 *DDR_ptr;
	uint8 *port_ptr;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_PARAM_CONFIG);
	}
	else
	{
		port_PortChannels = ConfigPtr->Ports;
		for (int i = 0; i < PORT_CONFIGURED_CHANNLES; i++) {
			/*get port */
			switch (port_PortChannels[i].port) {
			case PORTA: DDR_ptr  = &DDRA_REG;
			port_ptr = &PORTA_REG;
			break;
			case PORTB: DDR_ptr  = &DDRB_REG;
			port_ptr = &PORTB_REG;
			break;
			case PORTC: DDR_ptr  = &DDRC_REG;
			port_ptr = &PORTC_REG;
			break;
			case PORTD: DDR_ptr  = &DDRD_REG;
			port_ptr = &PORTD_REG;
			break;
			}
			if(PORT_PIN_IN==port_PortChannels[i].direction)
			{
				CLEAR_BIT(*DDR_ptr,port_PortChannels[i].pin_num);
				if (Disable_Pullup == port_PortChannels[i].pin_in_mode)
				{
					CLEAR_BIT(*port_ptr, port_PortChannels[i].pin_num);
				}
				else if(Enable_Pullup== port_PortChannels[i].pin_in_mode)
				{
					SET_BIT(*port_ptr, port_PortChannels[i].pin_num);
				}
				else
				{
				}
			}
			else if(PORT_PIN_OUT==port_PortChannels[i].direction)
			{
				SET_BIT(*DDR_ptr,port_PortChannels[i].pin_num);
				if (initial_Low==port_PortChannels[i].initial_Value)
				{
					CLEAR_BIT(*port_ptr,port_PortChannels[i].pin_num);
				}
				else if (initial_High==port_PortChannels[i].initial_Value)
				{
					SET_BIT(*port_ptr,port_PortChannels[i].pin_num);
				}
				else
				{
				}
			}
			else
			{
			}

		}
		Port_Status = PORT_INITIALIZED;
	}
#endif
}

/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Pin -> Port Pin ID number
 * 			  Direction -> Port Pin Direction
 * Parameters (in): ConfigPtr-Pointer to configuration set.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin direction.
 ************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction)
{
	uint8 * DDR_Ptr = NULL_PTR;
	boolean error = FALSE;
	uint8 local_port;
	uint8 local_pin;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if(Pin >= PORT_PIN_NUM)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
	}
	else
	{
		/* No Action Required */
	}
#endif
	{
		if(Pin >= PORT_A_PIN_0 && Pin <= PORT_A_PIN_7 )
		{
			local_port=PORTA;
		}
		else if (Pin >=PORT_B_PIN_0 && Pin<=PORT_B_PIN_7)
		{
			local_port=PORTB;
		}
		else if (Pin >=PORT_C_PIN_0 && Pin<=PORT_C_PIN_7)
		{
			local_port=PORTC;
		}
		else if (Pin >=PORT_D_PIN_0 && Pin<=PORT_D_PIN_7)
		{
			local_port=PORTD;
		}
		else
		{
		}

		if (Pin >=PORT_A_PIN_0 && Pin<=PORT_A_PIN_7)
		{
			local_pin=Pin;
		}
		else
		{
			local_pin=Pin % MAX_PIN_IN_PORT;
		}
		switch (local_port) {
		case PORTA:DDR_Ptr = &DDRA_REG;
		break;
		case PORTB:DDR_Ptr = &DDRB_REG;
		break;
		case PORTC:DDR_Ptr = &DDRC_REG;
		break;
		case PORTD:DDR_Ptr = &DDRD_REG;
		break;
		}
		if (PORT_PIN_OUT == Direction)
		{
			SET_BIT(*DDR_Ptr, local_pin);
		}
		else if (PORT_PIN_IN == Direction)
		{
			CLEAR_BIT(*DDR_Ptr, local_pin);
		}
		else
		{

		}
	}
}
#endif
/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction. .
 ************************************************************************************/

void Port_RefreshPortDirection(void)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
	}
	else
	{
	}
#endif

}


/************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo -> Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Returns the version information of this module.
 ************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin -> Port Pin ID number
 * 				   Mode -> New Port Pin mode to be set on port pin.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode.
 ************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if(PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE );
		error = TRUE;
	}
	else
#endif
	{

	}
}
#endif
/***********************************************************************************/



