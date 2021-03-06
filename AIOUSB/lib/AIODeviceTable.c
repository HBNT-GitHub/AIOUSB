#include "AIODeviceTable.h" 
#include <string.h>

#ifdef __cplusplus
namespace AIOUSB {
#endif

AIOUSBDevice deviceTable[ MAX_USB_DEVICES ];


static ProductIDName productIDNameTable[] = {
    { USB_DA12_8A_REV_A , "USB-DA12-8A-A"  },
    { USB_DA12_8A       , "USB-DA12-8A"    },
    { USB_DA12_8E       , "USB-DA12-8E"    },
    { USB_DIO_32        , "USB-DIO-32"     },
    { USB_DIO_32I       , "USB-DIO-32"     },
    { USB_DIO_48        , "USB-DIO-48"     },
    { USB_DIO_96        , "USB-DIO-96"     },
    { USB_DI16A_REV_A1  , "USB-DI16A-A1"   },
    { USB_DO16A_REV_A1  , "USB-DO16A-A1"   },
    { USB_DI16A_REV_A2  , "USB-DI16A-A2"   },
    { USB_DIO_16H       , "USB-DIO-16H"    },
    { USB_DI16A         , "USB-DI16A"      },
    { USB_DO16A         , "USB-DO16A"      },
    { USB_DIO_16A       , "USB-DIO-16A"    },
    { USB_IIRO_16       , "USB-IIRO-16"    },
    { USB_II_16         , "USB-II-16"      },
    { USB_RO_16         , "USB-RO-16"      },
    { USB_IIRO_8        , "USB-IIRO-8"     },
    { USB_II_8          , "USB-II-8"       },
    { USB_IIRO_4        , "USB-IIRO-4"     },
    { USB_IDIO_16       , "USB-IDIO-16"    },
    { USB_II_16_OLD     , "USB-II-16-OLD"  },
    { USB_IDO_16        , "USB-IDO-16"     },
    { USB_IDIO_8        , "USB-IDIO-8"     },
    { USB_II_8_OLD      , "USB-II-8-OLD"   },
    { USB_IDIO_4        , "USB-IDIO-4"     },
    { USB_CTR_15        , "USB-CTR-15"     },
    { USB_IIRO4_2SM     , "USB-IIRO4-2SM"  },
    { USB_IIRO4_COM     , "USB-IIRO4-COM"  },
    { USB_DIO16RO8      , "USB-DIO16RO8"   },
    { PICO_DIO16RO8     , "PICO-DIO16RO8"  },
    { USB_AI16_16A      , "USB-AI16-16A"   },
    { USB_AI16_16E      , "USB-AI16-16E"   },
    { USB_AI12_16A      , "USB-AI12-16A"   },
    { USB_AI12_16       , "USB-AI12-16"    },
    { USB_AI12_16E      , "USB-AI12-16E"   },
    { USB_AI16_64MA     , "USB-AI16-64MA"  },
    { USB_AI16_64ME     , "USB-AI16-64ME"  },
    { USB_AI12_64MA     , "USB-AI12-64MA"  },
    { USB_AI12_64M      , "USB-AI12-64M"   },
    { USB_AI12_64ME     , "USB-AI12-64ME"  },
    { USB_AI16_32A      , "USB-AI16-32A"   },
    { USB_AI16_32E      , "USB-AI16-32E"   },
    { USB_AI12_32A      , "USB-AI12-32A"   },
    { USB_AI12_32       , "USB-AI12-32"    },
    { USB_AI12_32E      , "USB-AI12-32E"   },
    { USB_AI16_64A      , "USB-AI16-64A"   },
    { USB_AI16_64E      , "USB-AI16-64E"   },
    { USB_AI12_64A      , "USB-AI12-64A"   },
    { USB_AI12_64       , "USB-AI12-64"    },
    { USB_AI12_64E      , "USB-AI12-64E"   },
    { USB_AI16_96A      , "USB-AI16-96A"   },
    { USB_AI16_96E      , "USB-AI16-96E"   },
    { USB_AI12_96A      , "USB-AI12-96A"   },
    { USB_AI12_96       , "USB-AI12-96"    },
    { USB_AI12_96E      , "USB-AI12-96E"   },
    { USB_AI16_128A     , "USB-AI16-128A"  },
    { USB_AI16_128E     , "USB-AI16-128E"  },
    { USB_AI12_128A     , "USB-AI12-128A"  },
    { USB_AI12_128      , "USB-AI12-128"   },
    { USB_AI12_128E     , "USB-AI12-128E"  },
    { USB_AO_ARB1       , "USB_AO_ARB1"    },
    { USB_AO16_16A      , "USB-AO16-16A"   },
    { USB_AO16_16       , "USB-AO16-16"    },
    { USB_AO16_12A      , "USB-AO16-12A"   },
    { USB_AO16_12       , "USB-AO16-12"    },
    { USB_AO16_8A       , "USB-AO16-8A"    },
    { USB_AO16_8        , "USB-AO16-8"     },
    { USB_AO16_4A       , "USB-AO16-4A"    },
    { USB_AO16_4        , "USB-AO16-4"     },
    { USB_AO12_16A      , "USB-AO12-16A"   },
    { USB_AO12_16       , "USB-AO12-16"    },
    { USB_AO12_12A      , "USB-AO12-12A"   },
    { USB_AO12_12       , "USB-AO12-12"    },
    { USB_AO12_8A       , "USB-AO12-8A"    },
    { USB_AO12_8        , "USB-AO12-8"     },
    { USB_AO12_4A       , "USB-AO12-4A"    },
    { USB_AO12_4        , "USB-AO12-4"     },
    { USB_AIO16_16A     , "USB-AIO16-16A"  },
    { USB_AIO16_16E     , "USB-AIO16-16E"  },
    { USB_AIO12_16A     , "USB-AIO12-16A"  },
    { USB_AIO12_16      , "USB-AIO12-16"   },
    { USB_AIO12_16E     , "USB-AIO12-16E"  },
    { USB_AIO16_64MA    , "USB-AIO16-64MA" },
    { USB_AIO16_64ME    , "USB-AIO16-64ME" },
    { USB_AIO12_64MA    , "USB-AIO12-64MA" },
    { USB_AIO12_64M     , "USB-AIO12-64M"  },
    { USB_AIO12_64ME    , "USB-AIO12-64ME" },
    { USB_AIO16_32A     , "USB-AIO16-32A"  },
    { USB_AIO16_32E     , "USB-AIO16-32E"  },
    { USB_AIO12_32A     , "USB-AIO12-32A"  },
    { USB_AIO12_32      , "USB-AIO12-32"   },
    { USB_AIO12_32E     , "USB-AIO12-32E"  },
    { USB_AIO16_64A     , "USB-AIO16-64A"  },
    { USB_AIO16_64E     , "USB-AIO16-64E"  },
    { USB_AIO12_64A     , "USB-AIO12-64A"  },
    { USB_AIO12_64      , "USB-AIO12-64"   },
    { USB_AIO12_64E     , "USB-AIO12-64E"  },
    { USB_AIO16_96A     , "USB-AIO16-96A"  },
    { USB_AIO16_96E     , "USB-AIO16-96E"  },
    { USB_AIO12_96A     , "USB-AIO12-96A"  },
    { USB_AIO12_96      , "USB-AIO12-96"   },
    { USB_AIO12_96E     , "USB-AIO12-96E"  },
    { USB_AIO16_128A    , "USB-AIO16-128A" },
    { USB_AIO16_128E    , "USB-AIO16-128E" },
    { USB_AIO12_128A    , "USB-AIO12-128A" },
    { USB_AIO12_128     , "USB-AIO12-128"  },
    { USB_AIO12_128E    , "USB-AIO12-128E" }
};
#ifdef __cplusplus
const int NUM_PROD_NAMES = sizeof(productIDNameTable) / sizeof(productIDNameTable[ 0 ]);
#else
#define NUM_PROD_NAMES (sizeof(productIDNameTable) / sizeof(productIDNameTable[ 0 ]))
#endif


unsigned long AIOUSB_INIT_PATTERN = 0x9b6773adul;  /* random pattern */
unsigned long aiousbInit = 0;                    /* == AIOUSB_INIT_PATTERN if AIOUSB module is initialized */


/*----------------------------------------------------------------------------*/
AIOUSBDevice *_get_device( unsigned long index , AIORESULT *result )
{
    AIOUSBDevice *dev;
    if ( index > MAX_USB_DEVICES ) { 
        *result = AIOUSB_ERROR_INVALID_INDEX;
        return NULL;
    }
    dev = (AIOUSBDevice*)&deviceTable[index];
    if ( !dev ) {
        if ( result )
            *result = AIOUSB_ERROR_INVALID_DATA;
        return NULL;
    } else if ( result ) 
        *result = AIOUSB_SUCCESS;
    return dev;
}

AIOUSBDevice *_verified_device( AIOUSBDevice *dev, AIORESULT *result )
{
    if ( dev && dev->valid == AIOUSB_TRUE ) {
        return dev;
    } else { 
        *result = AIOUSB_ERROR_INVALID_DEVICE_SETTING;
        return NULL;
    }   
}

AIOUSBDevice *_get_device_no_error( unsigned long index )
{
    return (AIOUSBDevice *)&deviceTable[ index ];
}


AIOUSB_BOOL AIOUSB_SetInit()
{
    aiousbInit = AIOUSB_INIT_PATTERN;
    return AIOUSB_SUCCESS;
}

/*----------------------------------------------------------------------------*/
void AIODeviceTableInit(void)
{
    int index;
    AIORESULT result;
    for(index = 0; index < MAX_USB_DEVICES; index++) {
        AIOUSBDevice *device = _get_device( index , &result );
        /* libusb handles */
        if ( index == 0 ) {
            if ( device->usb_device ) {
                DeleteUSBDevice( device->usb_device );
                device->usb_device = NULL;
            }
        } else {
            device->usb_device = NULL;
        }

        /* run-time settings */
        device->discardFirstSample = AIOUSB_FALSE;
        device->commTimeout = 5000;
        device->miscClockHz = 1;

        /* device-specific properties */
        device->ProductID = 0;
        device->DIOBytes
            = device->Counters
            = device->Tristates
            = device->ConfigBytes
            = device->ImmDACs
            = device->DACsUsed
            = device->ADCChannels
            = device->ADCMUXChannels
            = device->ADCChannelsPerGroup
            = device->WDGBytes
            = device->ImmADCs
            = device->FlashSectors
            = 0;
        device->RootClock
            = device->StreamingBlockSize
            = 0;
        device->bGateSelectable
            = device->bGetName
            = device->bDACStream
            = device->bADCStream
            = device->bDIOStream
            = device->bDIOSPI
            = device->bClearFIFO
            = device->bDACBoardRange
            = device->bDACChannelCal
            = AIOUSB_FALSE;

        /* device state */
        device->bDACOpen
            = device->bDACClosing
            = device->bDACAborting
            = device->bDACStarted
            = device->bDIOOpen
            = device->bDIORead
            = AIOUSB_FALSE;
        device->DACData = NULL;
        device->PendingDACData = NULL;
        device->LastDIOData = NULL;
        device->cachedName = NULL;
        device->cachedSerialNumber = 0;
        device->cachedConfigBlock.size = 0;       // .size == 0 == uninitialized

        /* worker thread state */
        device->workerBusy = AIOUSB_FALSE;
        device->workerStatus = 0;
        device->workerResult = AIOUSB_SUCCESS;
        device->valid = AIOUSB_FALSE;
        device->testing = AIOUSB_FALSE;
    }
    AIOUSB_SetInit();
}

/*----------------------------------------------------------------------------*/
AIOUSB_BOOL AIOUSB_IsInit()
{
    return ( aiousbInit == AIOUSB_INIT_PATTERN );
}

/*----------------------------------------------------------------------------*/
unsigned long AIOUSB_InitTest(void) {
    AIODeviceTableInit();
    aiousbInit = AIOUSB_INIT_PATTERN;
    return AIOUSB_SUCCESS;
}

/*----------------------------------------------------------------------------*/
AIOUSB_BOOL AIOUSB_Cleanup()
{
    aiousbInit = ~ AIOUSB_INIT_PATTERN;
    memset( &deviceTable[0], 0, MAX_USB_DEVICES * AIOUSBDeviceSize() );
    return AIOUSB_SUCCESS;
}

/*----------------------------------------------------------------------------*/
static int CompareProductIDs(const void *p1, const void *p2)
{
    assert(p1 != 0 &&
           (*( ProductIDName** )p1) != 0 &&
           p2 != 0 &&
           (*( ProductIDName** )p2) != 0);
    const unsigned int productID1 = (*( ProductIDName** )p1)->id,
                       productID2 = (*( ProductIDName** )p2)->id;
    if(productID1 < productID2)
        return -1;
    else if(productID1 > productID2)
        return 1;
    else
        return 0;
}

/*----------------------------------------------------------------------------*/
static int CompareProductNames(const void *p1, const void *p2) 
{
    assert(p1 != 0 &&
           (*( ProductIDName** )p1) != 0 &&
           p2 != 0 &&
           (*( ProductIDName** )p2) != 0);
    return strcmp((*( ProductIDName** )p1)->name, (*( ProductIDName** )p2)->name);
}

/*----------------------------------------------------------------------------*/
unsigned long QueryDeviceInfo( unsigned long DeviceIndex,
                               unsigned long *pPID,
                               unsigned long *pNameSize,
                               char *pName,
                               unsigned long *pDIOBytes,
                               unsigned long *pCounters
                               ) 
{
    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice *deviceDesc = AIODeviceTableGetDeviceAtIndex( DeviceIndex, &result );
    if ( result != AIOUSB_SUCCESS ){

        return result;
    }

    if(pPID != NULL)
        *pPID = deviceDesc->ProductID;

    if(pDIOBytes != NULL)
        *pDIOBytes = deviceDesc->DIOBytes;

    if(pCounters != NULL)
        *pCounters = deviceDesc->Counters;

    if(
        pNameSize != NULL &&
        pName != NULL
        ) {
        char *deviceName = GetSafeDeviceName(DeviceIndex);
          if(deviceName != 0) {
            /*
             * got a device name, so return it; pName[] is a character array, not a
             * null-terminated string, so don't append null terminator
             */
                int length = strlen(deviceName);
                if(length > ( int )*pNameSize)
                    length = ( int )*pNameSize;
                else
                    *pNameSize = length;
                memcpy(pName, deviceName, length);          // not null-terminated
            }
      }

    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief this function returns the name of a product ID; generally,
 * it's best to use this only as a last resort, since most
 * devices return their name when asked in QueryDeviceInfo()
 */
PRIVATE char *ProductIDToName(unsigned int productID) 
{

    char *tmpstr = strdup("UNKNOWN");
    char *name = tmpstr;


    /**
     * productIDIndex[] represents an index into
     * productIDNameTable[], sorted by product ID;
     * specifically, it contains pointers into
     * productIDNameTable[]; to get the actual product ID,
     * the pointer in productIDIndex[] must be
     * dereferenced; using a separate index table instead
     * of sorting productIDNameTable[] directly permits us
     * to create multiple indexes, in particular, a second
     * index sorted by product name
     */
        
    /* index of product IDs in productIDNameTable[] */
    static ProductIDName  *productIDIndex[ NUM_PROD_NAMES ];
    /* random pattern */
    unsigned long INIT_PATTERN = 0xe697f8acul;

    /* == INIT_PATTERN if index has been created */
    static unsigned long productIDIndexCreated = 0;
    if(productIDIndexCreated != INIT_PATTERN) {
        /* build index of product IDs */
        int index;
        for(index = 0; index < NUM_PROD_NAMES; index++)
            productIDIndex[ index ] = &productIDNameTable[ index ];

        qsort(productIDIndex, NUM_PROD_NAMES, sizeof(ProductIDName *), CompareProductIDs);
        productIDIndexCreated = INIT_PATTERN;
    }

    ProductIDName key;
    key.id = productID;
    ProductIDName * pKey = &key;
    ProductIDName **product = (  ProductIDName** )bsearch(&pKey, 
                                                          productIDIndex, 
                                                          NUM_PROD_NAMES, 
                                                          sizeof(ProductIDName *), 
                                                          CompareProductIDs
                                                          );
    if(product != 0)
        name = (*product)->name;

    return name;
}

/*----------------------------------------------------------------------------*/
/**
 * @details This function is the complement of ProductIDToName() and
 * returns the product ID for a given name; this function should be
 * used with care; it will work reliably if passed a name obtained
 * from ProductIDToName(); however, if passed a name obtained from the
 * device itself it may not work; the reason is that devices contain
 * their own name strings, which are most likely identical to the
 * names defined in this module, but not guaranteed to be so; that's
 * not as big a problem as it sounds, however, because if one has the
 * means to obtain the name from the device, then they also have
 * access to the device's product ID, so calling this function is
 * unnecessary; this function is mainly for performing simple
 * conversions between product names and IDs, primarily to support
 * user interfaces
 *
 * @param name
 *
 * @return
 */
PRIVATE unsigned int ProductNameToID(const char *name) 
{
    assert(name != 0);

    unsigned int productID = 0;

    /*
     * productNameIndex[] represents an index into
     * productIDNameTable[], sorted by product name (see notes for
     * ProductIDToName())
     */

    static ProductIDName const *productNameIndex[ NUM_PROD_NAMES ];
    /** index of product names in productIDNameTable[] */

    const unsigned long INIT_PATTERN = 0x7e6b2017ul;
    /** random pattern */

    static unsigned long productNameIndexCreated = 0;
    /** == INIT_PATTERN if index has been created */

    if(productNameIndexCreated != INIT_PATTERN) {
        /* build index of product names */
        int index;
        for(index = 0; index < NUM_PROD_NAMES; index++)
            productNameIndex[ index ] = &productIDNameTable[ index ];
        qsort(productNameIndex, NUM_PROD_NAMES, sizeof(ProductIDName *), CompareProductNames);
        productNameIndexCreated = INIT_PATTERN;
    }

    ProductIDName key;                                   // key.id not used
    strncpy(key.name, name, PROD_NAME_SIZE);
    key.name[ PROD_NAME_SIZE ] = 0;                     // in case strncpy() doesn't copy null
    const ProductIDName *const pKey = &key;
    const ProductIDName **product
        = ( const ProductIDName** )bsearch(&pKey, productNameIndex, NUM_PROD_NAMES, sizeof(ProductIDName *), CompareProductNames);
    if(product != 0)
        productID = (*product)->id;

    return productID;
}

/*----------------------------------------------------------------------------*/
AIORET_TYPE GetDevices(void) 
{
    unsigned long deviceMask = 0;

    if ( AIOUSB_IsInit() ) {
      /**
       * @note
       * we clear the device table to erase references to devices
       * which may have been unplugged; any device indexes to devices
       * that have not been unplugged, which the user may be using,
       * _should_ still be valid
       */
        /* AIODeviceTableClearDevices(); */
        int index;
        for(index = 0; index < MAX_USB_DEVICES; index++) {
            if ( deviceTable[index].usb_device != NULL && deviceTable[index].valid == AIOUSB_TRUE )
                deviceMask =  (deviceMask << 1) | 1;
        }
    } else {
        return -AIOUSB_ERROR_NOT_INIT;
    }


    return (AIORET_TYPE)deviceMask;
}

/*----------------------------------------------------------------------------*/
USBDevice *AIODeviceTableGetUSBDeviceAtIndex( unsigned long DeviceIndex, AIORESULT *result )
{
    AIOUSBDevice *dev = AIODeviceTableGetDeviceAtIndex( DeviceIndex , result );
    if ( !dev && *result == AIOUSB_SUCCESS )  {
        *result = -AIOUSB_ERROR_DEVICE_NOT_FOUND;
        return NULL;
    } else if ( *result != AIOUSB_SUCCESS ) { 
        return NULL;
    } else {
        USBDevice *usb = AIOUSBDeviceGetUSBHandle( dev );
        if ( !usb ) {
            *result = -AIOUSB_ERROR_INVALID_USBDEVICE;
            return NULL;
        } else {
            *result = AIOUSB_SUCCESS;
            return usb;
        }
    }
}

/*----------------------------------------------------------------------------*/
static unsigned long GetDeviceName(unsigned long DeviceIndex, char **name) 
{

    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice *deviceDesc = _get_device( DeviceIndex, &result );
    int MAX_NAME_SIZE = 100, srcLength,srcIndex, dstIndex, bytesTransferred;
    char *deviceName;
    unsigned char *descData;
    USBDevice *usb;
    const int CYPRESS_GET_DESC = 0x06;
    const int DESC_PARAMS = 0x0302;           /**03 = descriptor type: string; 02 = index */
    const int MAX_DESC_SIZE = 256;           // bytes, not characters

    if ( result != AIOUSB_SUCCESS ) 
        return AIOUSB_ERROR_DEVICE_NOT_FOUND;

    if (deviceDesc->cachedName != 0) {
        *name = deviceDesc->cachedName; /* name is cached, return it*/
        goto out_GetDeviceName;
    }

    /* name is not yet cached, so request it from the device  */

    deviceName = ( char* )malloc(MAX_NAME_SIZE + 2);

    if ( !deviceName ) {
        result = AIOUSB_ERROR_NOT_ENOUGH_MEMORY;
        goto out_GetDeviceName;
    }

    usb = AIOUSBDeviceGetUSBHandle( deviceDesc );
    if (!usb ) {
        result = AIOUSB_ERROR_USBDEVICE_NOT_FOUND;
        goto free_deviceName_GetDeviceName;
    }
    /*
     * descriptor strings returned by the device are
     * Unicode, not ASCII, and occupy two bytes per
     * character, so we need to handle our maximum
     * lengths accordingly
     */

    descData = ( unsigned char* )malloc(MAX_DESC_SIZE);
    if ( !descData ) {
        result = AIOUSB_ERROR_NOT_ENOUGH_MEMORY;
        goto free_deviceName_GetDeviceName;
    }

    bytesTransferred = usb->usb_control_transfer(usb,
                                                 USB_READ_FROM_DEVICE,
                                                 CYPRESS_GET_DESC,
                                                 DESC_PARAMS,
                                                 0,
                                                 descData,
                                                 MAX_DESC_SIZE,
                                                 deviceDesc->commTimeout
                                                 );
    if (bytesTransferred == MAX_DESC_SIZE) {
        /**
         * @verbatim
         * extract device name from descriptor and copy to cached name buffer
         *
         * descData[ 0 ] = 1 (descriptor length) + 1 (descriptor type) + 2 (Unicode) * string_length
         * descData[ 1 ] = \x03 (descriptor type: string)
         * descData[ 2 ] = low byte of first character of Unicode string
         * descData[ 3 ] = \0 (high byte)
         * descData[ 4 ] = low byte of second character of string
         * descData[ 5 ] = \0 (high byte)
         * ...
         * descData[ string_length * 2 ] = low byte of last character of string
         * descData[ string_length * 2 + 1 ] = \0 (high byte)
         * @endverbatim
         */

        srcLength = ( int )((descData[ 0 ] - 2) / 2);               // characters, not bytes

        /* srcIndex=2 =='slow byte first char */ 
        for(srcIndex = 2 , dstIndex = 0; dstIndex < srcLength && dstIndex < MAX_NAME_SIZE; srcIndex += 2 , dstIndex++ ) {
            deviceName[ dstIndex ] = descData[ srcIndex ];
        }
        deviceName[ dstIndex ] = 0; /* null-terminate */

        *name = deviceDesc->cachedName = strdup(deviceName);

    } else {
        result = LIBUSB_RESULT_TO_AIOUSB_RESULT(bytesTransferred);
    }
    free(descData);
 free_deviceName_GetDeviceName:
    free(deviceName);
 out_GetDeviceName:

    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief GetSafeDeviceName() returns a null-terminated device name;
 * if GetSafeDeviceName() is unable to obtain a legitimate device name
 * it returns something like "UNKNOWN" or 0
 */
char *GetSafeDeviceName(unsigned long DeviceIndex) 
{
    char *deviceName = 0;

    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice *deviceDesc = AIODeviceTableGetDeviceAtIndex( DeviceIndex, &result );
    if ( result != AIOUSB_SUCCESS )
        return deviceName;


    if(deviceDesc->bGetName) {
        /*
         * device supports getting its product name, so use it instead of the
         * name from the local product name table
         */

        unsigned long res = GetDeviceName(DeviceIndex, &deviceName);
        if(res != AIOUSB_SUCCESS) {
            /*
             * failed to get name from device, so fall back to local table after all
             */

            deviceName = ProductIDToName(deviceDesc->ProductID);

        } else {
            /*
             * device doesn't support getting its product name, so use local
             * product name table
             */
            deviceName = ProductIDToName(deviceDesc->ProductID);

        }
    }

    return deviceName;
}

/*----------------------------------------------------------------------------*/ 
AIORESULT _Initialize_Device_Desc(unsigned long DeviceIndex) 
{
    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice * device = _get_device( DeviceIndex , &result );
    if ( result != AIOUSB_SUCCESS )
        return result;

    device->DIOBytes = 0;
    device->DIOConfigBits = 0;
    device->Counters = 0;
    device->RootClock = 0;
    device->Tristates = 0;
    device->bGetName = AIOUSB_FALSE;
    device->ConfigBytes = 0;
    device->bGateSelectable = AIOUSB_FALSE;
    device->bDACBoardRange = AIOUSB_FALSE;
    device->bDACChannelCal = AIOUSB_FALSE;
    device->ImmDACs = 0;
    device->ImmADCs = 0;
    device->ADCChannels = 0;
    device->ADCMUXChannels = 0;
    device->bDACStream = AIOUSB_FALSE;
    device->bADCStream = AIOUSB_FALSE;
    device->RangeShift = 0;
    device->bDIOStream = AIOUSB_FALSE;
    device->StreamingBlockSize = 31 * 1024;
    device->bDIODebounce = AIOUSB_FALSE;
    device->bDIOSPI = AIOUSB_FALSE;
    device->bClearFIFO = AIOUSB_FALSE;
    device->FlashSectors = 0;
    device->WDGBytes = 0;
    device->bSetCustomClocks = AIOUSB_FALSE;
    return result;
}

/*----------------------------------------------------------------------------*/ 
AIORESULT  _Card_Specific_Settings(unsigned long DeviceIndex) 
{
    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice *device = _get_device( DeviceIndex , &result );

    if( result != AIOUSB_SUCCESS ) 
        return result;

    switch(device->ProductID) {
      case 0x8001:
          device->DIOBytes = 4;
          device->Counters = 3;
          device->RootClock = 3000000;
          device->bGetName = AIOUSB_TRUE;
          device->bSetCustomClocks = AIOUSB_TRUE;
          device->bDIODebounce = AIOUSB_TRUE;
          break;

      case 0x8004:
          device->DIOBytes = 4;
          device->DIOConfigBits = 32;
          device->bGetName = AIOUSB_TRUE;
          device->bSetCustomClocks = AIOUSB_TRUE;
          break;

      case 0x8002:
          device->DIOBytes = 6;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8003:
          device->DIOBytes = 12;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8008:
      case 0x8009:
      case 0x800A:
          device->DIOBytes = 1;
          device->bGetName = AIOUSB_TRUE;
          device->bDIOStream = AIOUSB_TRUE;
          device->bDIOSPI = AIOUSB_TRUE;
          device->bClearFIFO = AIOUSB_TRUE;
          break;

      case 0x800C:
      case 0x800D:
      case 0x800E:
      case 0x800F:
          device->DIOBytes = 4;
          device->Tristates = 2;
          device->bGetName = AIOUSB_TRUE;
          device->bDIOStream = AIOUSB_TRUE;
          device->bDIOSPI = AIOUSB_TRUE;
          device->bClearFIFO = AIOUSB_TRUE;
          break;

          //USB-IIRO-16 family
      case 0x8010:
      case 0x8011:
      case 0x8012:
      case 0x8014:
      case 0x8015:
      case 0x8016:
        //USB-IDIO-16 family
      case 0x8018:
      case 0x801a:
      case 0x801c:
      case 0x801e:
      case 0x8019:
      case 0x801d:
      case 0x801f:
          device->DIOBytes = 4;
          device->bGetName = AIOUSB_TRUE;
          device->WDGBytes = 2;
          break;

      case 0x4001:
      case 0x4002:
          device->bGetName = AIOUSB_FALSE;
          device->bDACStream = AIOUSB_TRUE;
          device->ImmDACs = 8;
          device->DACsUsed = 5;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x4003:
          device->bGetName = AIOUSB_FALSE;
          device->ImmDACs = 8;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8020:
          device->Counters = 5;
          device->bGateSelectable = AIOUSB_TRUE;
          device->RootClock = 10000000;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8030:
      case 0x8031:
          device->DIOBytes = 2;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8032:
          device->DIOBytes = 3;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8033:
          device->DIOBytes = 3;
          device->bGetName = AIOUSB_TRUE;
          break;

      case 0x8036:
          device->DIOBytes = 2;
          device->bGetName = AIOUSB_TRUE;
          device->ImmADCs = 2;
          break;

      case 0x8037:
          device->DIOBytes = 2;
          device->bGetName = AIOUSB_TRUE;
          device->ImmADCs = 2;
          break;

      case 0x8040:
      case 0x8041:
      case 0x8042:
      case 0x8043:
      case 0x8044:
      case 0x8140:
      case 0x8141:
      case 0x8142:
      case 0x8143:
      case 0x8144:
          device->DIOBytes = 2;
          device->Counters = 1;
          device->RootClock = 10000000;
          device->bGetName = AIOUSB_TRUE;
          device->bADCStream = AIOUSB_TRUE;
          device->ADCChannels = 16;
          device->ADCMUXChannels = 16;
          device->ConfigBytes = 20;
          device->RangeShift = 0;
          device->bClearFIFO = AIOUSB_TRUE;
          if((device->ProductID & 0x0100) != 0) {
                device->bDACBoardRange = AIOUSB_TRUE;
                device->ImmDACs = 2;
            }
          break;

      case 0x8045:
      case 0x8046:
      case 0x8047:
      case 0x8048:
      case 0x8049:
      case 0x8145:
      case 0x8146:
      case 0x8147:
      case 0x8148:
      case 0x8149:
          device->DIOBytes = 2;
          device->Counters = 1;
          device->RootClock = 10000000;
          device->bGetName = AIOUSB_TRUE;
          device->bADCStream = AIOUSB_TRUE;
          device->ADCChannels = 16;
          device->ADCMUXChannels = 64;
          device->ConfigBytes = 21;
          device->RangeShift = 2;
          device->bClearFIFO = AIOUSB_TRUE;
          if((device->ProductID & 0x0100) != 0) {
                device->bDACBoardRange = AIOUSB_TRUE;
                device->ImmDACs = 2;
            }
          break;

      case 0x804a:
      case 0x804b:
      case 0x804c:
      case 0x804d:
      case 0x804e:
      case 0x804f:
      case 0x8050:
      case 0x8051:
      case 0x8052:
      case 0x8053:
      case 0x8054:
      case 0x8055:
      case 0x8056:
      case 0x8057:
      case 0x8058:
      case 0x8059:
      case 0x805a:
      case 0x805b:
      case 0x805c:
      case 0x805d:
      case 0x805e:
      case 0x805f:
      case 0x814a:
      case 0x814b:
      case 0x814c:
      case 0x814d:
      case 0x814e:
      case 0x814f:
      case 0x8150:
      case 0x8151:
      case 0x8152:
      case 0x8153:
      case 0x8154:
      case 0x8155:
      case 0x8156:
      case 0x8157:
      case 0x8158:
      case 0x8159:
      case 0x815a:
      case 0x815b:
      case 0x815c:
      case 0x815d:
      case 0x815e:
      case 0x815f:
          device->DIOBytes = 2;
          device->Counters = 1;
          device->RootClock = 10000000;
          device->bGetName = AIOUSB_TRUE;
          device->bADCStream = AIOUSB_TRUE;
          device->ADCChannels = 16;
          device->ADCMUXChannels = 32 * ((((device->ProductID - 0x804A) & (~0x0100)) / 5) + 1);
          device->ConfigBytes = 21;
          device->RangeShift = 3;
          device->bClearFIFO = AIOUSB_TRUE;
          if((device->ProductID & 0x0100) != 0) {
                device->bDACBoardRange = AIOUSB_TRUE;
                device->ImmDACs = 2;
            }
          break;

      case 0x8060:
      case 0x8070:
      case 0x8071:
      case 0x8072:
      case 0x8073:
      case 0x8074:
      case 0x8075:
      case 0x8076:
      case 0x8077:
      case 0x8078:
      case 0x8079:
      case 0x807a:
      case 0x807b:
      case 0x807c:
      case 0x807d:
      case 0x807e:
      case 0x807f:
          device->DIOBytes = 2;
          device->bGetName = AIOUSB_TRUE;
          device->FlashSectors = 32;
          device->bDACBoardRange = AIOUSB_TRUE;
          device->bDACChannelCal = AIOUSB_TRUE;
          //device->bClearFIFO = AIOUSB_TRUE;
          //Add a new-style DAC streaming
          switch(device->ProductID & 0x06) {
            case 0x00:
                device->ImmDACs = 16;
                break;

            case 0x02:
                device->ImmDACs = 12;
                break;

            case 0x04:
                device->ImmDACs = 8;
                break;

            case 0x06:
                device->ImmDACs = 4;
                break;
            }
          if((device->ProductID & 1) == 0)
              device->ImmADCs = 2;
          break;

      default:
          device->bADCStream = AIOUSB_TRUE;
          device->bDIOStream = AIOUSB_TRUE;
          device->bDIOSPI = AIOUSB_TRUE;
          result = AIOUSB_SUCCESS;
          break;
      }
    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @param DeviceIndex
 * @return
 */
AIORESULT AIOUSB_EnsureOpen(unsigned long DeviceIndex)
{
    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice *device = AIODeviceTableGetDeviceAtIndex( DeviceIndex, &result );
    if ( result != AIOUSB_SUCCESS )
        return result;

    if ( !device->usb_device  ) {
        if ( device->bDeviceWasHere) 
            result = AIOUSB_ERROR_DEVICE_NOT_CONNECTED;
        else 
            result = AIOUSB_ERROR_USBDEVICE_NOT_FOUND;
        goto RETURN_AIOUSB_EnsureOpen;
    }  
   
    if (device->bOpen) {
        result = AIOUSB_ERROR_OPEN_FAILED;
        goto RETURN_AIOUSB_EnsureOpen;
    }
    if (result == AIOUSB_SUCCESS) {
          _Initialize_Device_Desc(DeviceIndex);
          result |= _Card_Specific_Settings(DeviceIndex);
          if(result != AIOUSB_SUCCESS)
              goto RETURN_AIOUSB_EnsureOpen;
          if(device->DIOConfigBits == 0)
              device->DIOConfigBits = device->DIOBytes;
      }
RETURN_AIOUSB_EnsureOpen:
    return result;
}

/*----------------------------------------------------------------------------*/ 
AIOUSBDevice *AIODeviceTableGetDeviceAtIndex( unsigned long DeviceIndex , AIORESULT *result ) 
{
    AIOUSBDevice *retval = NULL;

    if ( !AIOUSB_IsInit() ) {
        *result = AIOUSB_ERROR_NOT_INIT;
        return NULL;
    }
    if (DeviceIndex == diFirst) { /* find first device on bus */
        *result = AIOUSB_ERROR_FILE_NOT_FOUND;
        int index;
        for(index = 0; index < MAX_USB_DEVICES; index++) {
            if ( (retval = _verified_device(_get_device(index , result ), result )) && *result == AIOUSB_SUCCESS ) {
                DeviceIndex = index;
                break;
            }
        }
    } else if(DeviceIndex == diOnly) {
        /*
         * find first device on bus, ensuring that it's the only device
         */
        *result = AIOUSB_ERROR_FILE_NOT_FOUND;
        int index;
        for(index = 0; index < MAX_USB_DEVICES; index++) {
            if ( (retval = _verified_device(_get_device(index, result ), result )) ) {
                /* found a device */
                if ( *result != AIOUSB_SUCCESS) {
                    /*
                     * this is the first device found; save this index, but
                     * keep checking to see that this is the only device
                     */
                    DeviceIndex = index;
                    *result = AIOUSB_SUCCESS;
                } else {
                    /*
                     * there are multiple devices on the bus
                     */
                    *result = AIOUSB_ERROR_DUP_NAME;
                    retval = NULL;
                    break;
                }
            }
        }
    } else {
        /*
         * simply verify that the supplied index is valid
         */
        retval = _verified_device( _get_device( DeviceIndex , result ), result );
    }

    return retval;
}

/*----------------------------------------------------------------------------*/
void _setup_device_parameters( AIOUSBDevice *device , unsigned long productID ) 
{
    device->ProductID = productID;
    device->StreamingBlockSize = 31ul * 1024ul;
    device->bGetName = AIOUSB_TRUE;             // most boards support this feature
    if(productID == USB_DIO_32) {
        device->DIOBytes = 4;
        device->Counters = 3;
        device->RootClock = 3000000;
    } else if(productID == USB_DIO_48) {
        device->DIOBytes = 6;
    } else if(productID == USB_DIO_96) {
        device->DIOBytes = 12;
    } else if( productID >= USB_DI16A_REV_A1 && productID <= USB_DI16A_REV_A2 ) {
        device->DIOBytes = 1;
        device->bDIOStream = AIOUSB_TRUE;
        device->bDIOSPI = AIOUSB_TRUE;
        device->bClearFIFO = AIOUSB_TRUE;
    } else if(
              productID >= USB_DIO_16H &&
              productID <= USB_DIO_16A
              ) {
        device->DIOBytes = 4;
        device->Tristates = 2;
        device->bDIOStream = AIOUSB_TRUE;
        device->bDIOSPI = AIOUSB_TRUE;
        device->bClearFIFO = AIOUSB_TRUE;
    } else if(
              productID == USB_IIRO_16 ||
              productID == USB_II_16 ||
              productID == USB_RO_16 ||
              productID == USB_IIRO_8 ||
              productID == USB_II_8 ||
              productID == USB_IIRO_4
              ) {
        device->DIOBytes = 4;
        device->WDGBytes = 2;
    } else if(
              productID == USB_IDIO_16 ||
              productID == USB_II_16_OLD ||
              productID == USB_IDO_16 ||
              productID == USB_IDIO_8 ||
              productID == USB_II_8_OLD ||
              productID == USB_IDIO_4
              ) {
        device->DIOBytes = 4;
        device->WDGBytes = 2;
    } else if(
              productID >= USB_DA12_8A_REV_A &&
              productID <= USB_DA12_8A
              ) {
        device->bDACStream = AIOUSB_TRUE;
        device->ImmDACs = 8;
        device->DACsUsed = 5;
        device->bGetName = AIOUSB_FALSE;
        device->RootClock = 12000000;
    } else if(productID == USB_DA12_8E) {
        device->ImmDACs = 8;
        device->bGetName = AIOUSB_FALSE;
    } else if(productID == USB_CTR_15) {
        device->Counters = 5;
        device->bGateSelectable = AIOUSB_TRUE;
        device->RootClock = 10000000;
    } else if(
              productID == USB_IIRO4_2SM ||
              productID == USB_IIRO4_COM
              ) {
        device->DIOBytes = 2;
    } else if(productID == USB_DIO16RO8) {
        device->DIOBytes = 3;
    } else if(productID == PICO_DIO16RO8) {
        device->DIOBytes = 3;
    } else if(
              (productID >= USB_AI16_16A && productID <= USB_AI12_16E) ||
              (productID >= USB_AIO16_16A && productID <= USB_AIO12_16E)
              ) {
        device->DIOBytes = 2;
        device->Counters = 1;
        device->RootClock = 10000000;
        device->bADCStream = AIOUSB_TRUE;
        device->ImmADCs = 1;
        device->ADCChannels
            = device->ADCMUXChannels = 16;
        device->ADCChannelsPerGroup = 1;
        device->ConfigBytes = AD_CONFIG_REGISTERS;
        device->bClearFIFO = AIOUSB_TRUE;
        if(productID & 0x0100) {
            device->ImmDACs = 2;
            device->bDACBoardRange = AIOUSB_TRUE;
        }
    } else if(
              (productID >= USB_AI16_64MA && productID <= USB_AI12_64ME) ||
              (productID >= USB_AIO16_64MA && productID <= USB_AIO12_64ME)
              ) {
        device->DIOBytes = 2;
        device->Counters = 1;
        device->RootClock = 10000000;
        device->bADCStream = AIOUSB_TRUE;
        device->ImmADCs = 1;
        device->ADCChannels = 16;
        device->ADCMUXChannels = 64;
        device->ADCChannelsPerGroup = 4;
        device->ConfigBytes = AD_MUX_CONFIG_REGISTERS;
        device->bClearFIFO = AIOUSB_TRUE;
        if(productID & 0x0100) {
            device->ImmDACs = 2;
            device->bDACBoardRange = AIOUSB_TRUE;
        }
    } else if(
              (productID >= USB_AI16_32A && productID <= USB_AI12_128E) ||
              (productID >= USB_AIO16_32A && productID <= USB_AIO12_128E)
              ) {
        device->DIOBytes = 2;
        device->Counters = 1;
        device->RootClock = 10000000;
        device->bADCStream = AIOUSB_TRUE;
        device->ImmADCs = 1;
        device->ADCChannels = 16;

        /*
         * there are four groups of five
         * products each in this family;
         * each group of five products has
         * 32 more MUX channels than the
         * preceding group; so we calculate
         * the number of MUX channels by
         * doing some arithmetic on the
         * product ID
         */

        int I = (productID - USB_AI16_32A) & ~0x0100;
        I /= 5;               /* products per group */
        device->ADCMUXChannels = 32 * (I + 1);
        device->ADCChannelsPerGroup = 8;
        device->ConfigBytes = AD_MUX_CONFIG_REGISTERS;
        device->bClearFIFO = AIOUSB_TRUE;
        if(productID & 0x0100) {
            device->ImmDACs = 2;
            device->bDACBoardRange = AIOUSB_TRUE;
        }
    } else if ( productID == USB_AO_ARB1 ) { 
      device->DIOBytes      = 4;
      device->Tristates     = 1;
      device->bGetName      = AIOUSB_TRUE;
      device->bDIOStream    = AIOUSB_TRUE;
      device->bClearFIFO    = AIOUSB_TRUE;
      device->bDACDIOClock  = AIOUSB_TRUE;
    } else if(
              productID >= USB_AO16_16A &&
              productID <= USB_AO12_4
              ) {
        device->DIOBytes = 2;
        device->FlashSectors = 32;
        device->bDACBoardRange = AIOUSB_TRUE;
        device->bDACChannelCal = AIOUSB_TRUE;

        /*
         * we use a few bits within the
         * product ID to determine the
         * number of DACs and whether or not
         * the product has ADCs
         */
        switch(productID & 0x0006) {
        case 0x0000:
            device->ImmDACs = 16;
            break;

        case 0x0002:
            device->ImmDACs = 12;
            break;

        case 0x0004:
            device->ImmDACs = 8;
            break;

        case 0x0006:
            device->ImmDACs = 4;
            break;
        }
        if((productID & 0x0001) == 0)
            device->ImmADCs = 2;
    }

    /* allocate I/O image buffers */
    if(device->DIOBytes > 0) {
        /* calloc() zeros memory */
        device->LastDIOData = ( unsigned char* )calloc(device->DIOBytes, sizeof(unsigned char));
        // assert(device->LastDIOData != 0);
    }

    /* Clear up the CachedConfigBlock */
    ADCConfigBlockInitializeFromAIOUSBDevice( &device->cachedConfigBlock , device );
    device->cachedConfigBlock.size                              = device->ConfigBytes;
    device->cachedConfigBlock.testing                           = device->testing;
    device->cachedConfigBlock.mux_settings.ADCMUXChannels       = device->ADCMUXChannels;
    device->cachedConfigBlock.mux_settings.ADCChannelsPerGroup  = device->ADCChannelsPerGroup;
    device->cachedConfigBlock.mux_settings.defined              = AIOUSB_TRUE;

    device->valid = AIOUSB_TRUE;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief A mock function that can set up the DeviceTable with any type of devices
 **/
AIORESULT AIODeviceTableAddDeviceToDeviceTable( int *numAccesDevices, unsigned long productID ) 
{
    return AIODeviceTableAddDeviceToDeviceTableWithUSBDevice( numAccesDevices, productID, NULL );
}

/*----------------------------------------------------------------------------*/
AIORESULT AIODeviceTableAddDeviceToDeviceTableWithUSBDevice( int *numAccesDevices, unsigned long productID , USBDevice *usb_dev ) 
{
    AIORESULT result = AIOUSB_SUCCESS;
    AIOUSBDevice *device  = _get_device( *numAccesDevices , &result );

    device->usb_device    = usb_dev;
    device->ProductID     = productID;
    device->isInit        = AIOUSB_TRUE;
    _setup_device_parameters( device , productID );
    ADCConfigBlockSetDevice( AIOUSBDeviceGetADCConfigBlock( device ), device );

    *numAccesDevices += 1;
    return result;
}

/*----------------------------------------------------------------------------*/
AIORESULT AIODeviceTableSetDeviceID( int index, AIOUSBDevice *dev )
{
    AIORESULT result = AIOUSB_SUCCESS;
    return result;
}

/*----------------------------------------------------------------------------*/
AIORESULT AIOUSB_GetAllDevices() 
{
    AIORESULT deviceMask = 0;
    
    if(AIOUSB_IsInit()) {
        int index;
        for (index = 0; index < MAX_USB_DEVICES; index++) {
            AIORESULT res = AIOUSB_SUCCESS;
            AIODeviceTableGetDeviceAtIndex( index , &res );
            if ( res == AIOUSB_SUCCESS ) { 
                int MAX_NAME_SIZE = 100;
                char name[ MAX_NAME_SIZE + 1 ];
                unsigned long productID;
                unsigned long nameSize = MAX_NAME_SIZE;
                unsigned long numDIOBytes;
                unsigned long numCounters;

                unsigned long result = QueryDeviceInfo(index, &productID, &nameSize, name, &numDIOBytes, &numCounters);
                if(result == AIOUSB_SUCCESS) {
                    name[ nameSize ] = '\0';
                    deviceMask = (deviceMask << 1) | 1;
                }
            }
        }
    }

    return deviceMask;
}

/*----------------------------------------------------------------------------*/
AIORET_TYPE AIODeviceTablePopulateTableTest(unsigned long *products, int length ) 
{
    int numAccesDevices = 0;
    AIORESULT result;
    AIOUSB_InitTest();
    for( int i = 0; i < length ; i ++  ) {
        result = AIODeviceTableAddDeviceToDeviceTable( &numAccesDevices, products[i] );
        if ( result != AIOUSB_SUCCESS ) {
            deviceTable[numAccesDevices-1].usb_device = (USBDevice *)0x42; 
        }
    }
    return AIOUSB_SUCCESS;
}

/*----------------------------------------------------------------------------*/
void CloseAllDevices(void) 
{
    if(!AIOUSB_IsInit())
        return;
    int index;
    AIORESULT result = AIOUSB_SUCCESS;
    for(index = 0; index < MAX_USB_DEVICES; index++) {
        result = AIOUSB_SUCCESS;
        AIOUSBDevice *device = AIODeviceTableGetDeviceAtIndex( index, &result );
        if ( result == AIOUSB_SUCCESS )  {
            USBDevice *usb = AIOUSBDeviceGetUSBHandle( device );
            if ( usb ) 
                USBDeviceClose( usb );
        
            if(device->LastDIOData != NULL) {
                free(device->LastDIOData);
                device->LastDIOData = NULL;
            }
        
            if(device->cachedName != NULL) {
                free(device->cachedName);
                device->cachedName = NULL;
            }
        }
    }
}

/*----------------------------------------------------------------------------*/
unsigned long AIODeviceTableClearDevices(void) 
{
    CloseAllDevices();
    AIODeviceTableInit();
    return AIOUSB_SUCCESS;
}

/*----------------------------------------------------------------------------*/


#define DEVICE_POPULATOR_INTERFACE(T)                                   \
    AIORET_TYPE (*get_device_ids)( T *self );                           \
    unsigned long *products;                                            \
    int size;
    
typedef struct device_populator {
    DEVICE_POPULATOR_INTERFACE(struct device_populator );
    libusb_device *usb_device;
    libusb_device **deviceList;
    int numDevices;
    int numAccesDevices;
} AIODevicePopulator;

/*----------------------------------------------------------------------------*/

AIORESULT NewPopulateTable( AIODevicePopulator *dp ) 
{
    AIORESULT result = AIOUSB_SUCCESS;

    if ( ! dp )
        return AIOUSB_ERROR_INVALID_PARAMETER;

    dp->get_device_ids( dp  );
    for ( int i = 0; i < MIN( dp->size, MAX_USB_DEVICES ) ; ) {
        AIODeviceTableAddDeviceToDeviceTableWithUSBDevice( &i , dp->products[i] , NULL );
    }

    AIOUSB_SetInit();
    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief populate device table with ACCES devices found on USB bus
 * @todo Rely on Global Header files for the functionality of devices / cards
 * as opposed to hard coding
 * @note
 * populate device table so users can use diFirst and diOnly immediately; be
 * sure to call PopulateDeviceTable() after 'aiousbInit = AIOUSB_INIT_PATTERN;'
 */
AIORET_TYPE AIODeviceTablePopulateTable(void) 
{

    int libusbResult = libusb_init( NULL );
    if (libusbResult != LIBUSB_SUCCESS)
        return -libusbResult;
    int numAccesDevices = 0;
    AIORET_TYPE result;
    USBDevice *usbdevices = NULL;
    int size = 0;

    result = FindUSBDevices( &usbdevices, &size );

    if ( result < AIOUSB_SUCCESS ) 
        return result;

    for ( int i = 0; i < size ; i ++ ) {
        AIOUSBDevice *device = (AIOUSBDevice *)&deviceTable[ numAccesDevices++ ];

        unsigned productID = USBDeviceGetIdProduct( &usbdevices[i] );
        _setup_device_parameters( device, productID );
        /* device->usb_device = usbdevices[i]; */
        device->usb_device = CopyUSBDevice( &usbdevices[i] );
    }
    
    AIOUSB_SetInit();
    return AIOUSB_SUCCESS;
}

/* device->usb_device = CopyUSBDevice( &usbdevices[i] ); */
/* InitializeUSBDevice( device->usb_device ); /\* Sets up the internals for actually working *\/ */
/* DeleteUSBDevices( usbdevices ); */


/*----------------------------------------------------------------------------*/
/**
 * @brief AIOUSB_Init() and AIOUSB_Exit() are not thread-safe and
 * should not be called while other threads might be accessing global
 * variables. Hence you should just run AIOUSB_Init() once at the beginning
 * and then the AIOUSB_Exit() once at the end after every thread acquiring
 * data has been stopped.
 */
unsigned long AIOUSB_Init(void) 
{
    AIORESULT result = AIOUSB_SUCCESS;
    AIORET_TYPE retval = AIOUSB_SUCCESS;

    if(!AIOUSB_IsInit()) {
          AIODeviceTableInit();
#if defined(AIOUSB_ENABLE_MUTEX)
          pthread_mutexattr_t mutexAttr;
          if(pthread_mutexattr_init(&mutexAttr) == 0) {
                if(pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE) == 0) {
                    if(pthread_mutex_init(&aiousbMutex, &mutexAttr) == 0) {
                        /**
                         * @note
                         * populate device table so users can use diFirst and diOnly immediately; be
                         * sure to call PopulateDeviceTable() after 'aiousbInit = AIOUSB_INIT_PATTERN;'
                         */
                          if ( AIODeviceTablePopulateTable() != AIOUSB_SUCCESS ) {
                              pthread_mutex_destroy(&aiousbMutex);
                              result = LIBUSB_RESULT_TO_AIOUSB_RESULT(libusbResult);
                          } else {
                              AIOUSB_SetInit();
                          }

                        } else
                          result = AIOUSB_ERROR_INVALID_MUTEX;
                  } else
                    result = AIOUSB_ERROR_INVALID_MUTEX;
                pthread_mutexattr_destroy(&mutexAttr);
            } else
              result = AIOUSB_ERROR_INVALID_MUTEX;
#else
          retval  = AIODeviceTablePopulateTable();
          if ( retval >= AIOUSB_SUCCESS ) {
              AIOUSB_SetInit();
          }

#endif

    }
    return result;
}

/*----------------------------------------------------------------------------*/
void AIOUSB_Exit()
{
    if(AIOUSB_IsInit()) {
          CloseAllDevices();
          libusb_exit(NULL);
#if defined(AIOUSB_ENABLE_MUTEX)
          pthread_mutex_destroy(&aiousbMutex);
#endif
          aiousbInit = 0;
      }
}

/*----------------------------------------------------------------------------*/
unsigned long AIOUSB_Reset( unsigned long DeviceIndex )
{
    AIORESULT result = AIOUSB_SUCCESS;


    AIOUSBDevice *deviceDesc = AIODeviceTableGetDeviceAtIndex( DeviceIndex, &result );
    if ( result != AIOUSB_SUCCESS )
        return result;

    USBDevice *usb = AIOUSBDeviceGetUSBHandle( deviceDesc );

    if(usb != NULL) {

        int libusbResult = usb->usb_reset_device(usb);
        if (libusbResult != LIBUSB_SUCCESS )
            result = LIBUSB_RESULT_TO_AIOUSB_RESULT(libusbResult);
        usleep(250000);
    } else {
        result = AIOUSB_ERROR_DEVICE_NOT_CONNECTED;

    }

    return result;
}


#ifdef __cplusplus
}
#endif


#ifdef SELF_TEST
#include "gtest/gtest.h"
#include "tap.h"
#include <stdlib.h>

using namespace AIOUSB;

TEST(AIOUSB_Core,MockObjects) {
    int numDevices = 0;
    AIODeviceTableInit();    
    AIODeviceTableAddDeviceToDeviceTable( &numDevices, USB_AIO16_16A );
    EXPECT_EQ( numDevices, 1 );

    AIODeviceTableAddDeviceToDeviceTable( &numDevices, USB_DIO_32 );
    EXPECT_EQ( numDevices, 2 );

    EXPECT_EQ( ((AIOUSBDevice *)&deviceTable[0])->ProductID, USB_AIO16_16A  );
    EXPECT_EQ( ((AIOUSBDevice *)&deviceTable[1])->ProductID, USB_DIO_32  );

    EXPECT_TRUE( AIOUSBDeviceGetADCConfigBlock( (AIOUSBDevice *)&deviceTable[0] ) );
    
    EXPECT_EQ( (AIOUSBDevice *)&deviceTable[0], ADCConfigBlockGetAIOUSBDevice( AIOUSBDeviceGetADCConfigBlock( (AIOUSBDevice *)&deviceTable[0] ), NULL ));

}

TEST(AIODeviceTable, AddingDeviceSetsInit )
{
    int numDevices = 0;
    AIODeviceTableAddDeviceToDeviceTable( &numDevices , USB_AIO16_16A );
    EXPECT_EQ( AIOUSB_IsInit(), AIOUSB_TRUE );

}


/* #define DEVICE_POPULATOR_INTERFACE(T)                                         \ */
/*     AIORET_TYPE (*get_device_ids)( T *self , int **product_ids, int *size );  \ */
    
typedef struct test_populator 
{
    DEVICE_POPULATOR_INTERFACE(struct device_populator );
} TestPopulator;

AIORET_TYPE test_get_device_ids( AIODevicePopulator *self ) 
{
    char *tmp,*orig;
    if ( (tmp = getenv("AIODEVICETABLE_PRODUCT_IDS" )) ) { 
        self->size = 0;
        tmp = strdup( tmp );
        orig = tmp;
        char delim[] = ",";
        char *pos = NULL;
        char *savepos;
        for ( char *token = strtok_r( tmp, delim, &pos );  token ; token = strtok_r(NULL, delim , &pos) ) {
            if (token == NULL)
                break;
            if( strlen(token) > 3 && strncmp(token,"USB",3 ) == 0 ) {
                unsigned int tmpproduct = ProductNameToID( token );
                if( tmpproduct ) { 
                    /* printf("Using %d\n", tmpproduct ); */
                    self->size ++;
                    self->products = (unsigned long *)realloc( self->products, (self->size)*sizeof(unsigned long)) ;
                    self->products[self->size-1] = tmpproduct;
                }
            }
        }
        /* printf("After is 0x%x",(int)(long)(int*)&orig[0] ); */
        free(orig);

    } else {
        self->products = (unsigned long *)malloc( (self->size)*sizeof(unsigned long ) );
        self->size = 2;
        self->products[0] = USB_AIO16_16A;
        self->products[1] = USB_DIO_32;
    }
}

class DeviceTableSetup : public ::testing::Test 
{
 protected:
    virtual void SetUp() {
        numDevices = 0;
        tp = (TestPopulator *)calloc(sizeof(TestPopulator),1);
        tp->get_device_ids = test_get_device_ids;
        char *tmp = getenv("AIODEVICETABLE_PRODUCT_IDS" );
        if ( !tmp) {
            setenv("AIODEVICETABLE_PRODUCT_IDS","USB-AIO16-16A,USB-DIO-32" , 1 );
        }

        NewPopulateTable((AIODevicePopulator *)tp );
    }
  
    virtual void TearDown() { 
        free(tp);
        AIOUSB_Cleanup();
    }
    int numDevices;
    TestPopulator *tp;
};

TEST_F(DeviceTableSetup, InitAndDummyPopulateTest )
{
    AIOUSB_BOOL tmp;
    
    /* EXPECT_NE( NewPopulateTable(NULL), AIOUSB_SUCCESS ); */
    tmp = AIOUSB_IsInit();

    EXPECT_EQ( tmp, true );
    EXPECT_GE( tp->size, 1 ) << ::testing::PrintToString( tp->size );

    for ( int i = 0; i <  MIN(tp->size, MAX_USB_DEVICES ) ; i ++ ) {
        EXPECT_EQ( tp->products[i],  ((AIOUSBDevice *)&deviceTable[i])->ProductID  );
    }
}

TEST(AIODeviceTable, InitAddsConfigToDevicePointer )
{
    int numAccesDevices = 0;
    AIOUSB_BOOL tmp;
    AIORESULT result;

    result = AIODeviceTableAddDeviceToDeviceTableWithUSBDevice( &numAccesDevices, USB_AI16_16E, NULL );
    EXPECT_EQ( result, AIOUSB_SUCCESS );
    AIOUSBDevice *dev = AIODeviceTableGetDeviceAtIndex( numAccesDevices - 1 , &result );
    EXPECT_EQ( result, AIOUSB_SUCCESS );
    EXPECT_TRUE(dev);
}


TEST(AIODeviceTable, SetsUpDefaults )
{
    int numAccesDevices = 0;
    AIOUSB_BOOL tmp;
    AIORESULT retval;

    retval = AIODeviceTableAddDeviceToDeviceTableWithUSBDevice( &numAccesDevices, USB_AI16_16E, NULL );
    EXPECT_EQ( retval, AIOUSB_SUCCESS );
    AIODeviceTableAddDeviceToDeviceTableWithUSBDevice( &numAccesDevices, USB_DIO_32, NULL );
    EXPECT_EQ( retval, AIOUSB_SUCCESS );

    EXPECT_EQ( ((AIOUSBDevice *)&deviceTable[1])->DIOBytes, 4  );
}


int 
main(int argc, char *argv[] )
{

  testing::InitGoogleTest(&argc, argv);
  testing::TestEventListeners & listeners = testing::UnitTest::GetInstance()->listeners();
#ifdef GTEST_TAP_PRINT_TO_STDOUT
  delete listeners.Release(listeners.default_result_printer());
#endif

  listeners.Append( new tap::TapListener() );
  return RUN_ALL_TESTS();  

}


#endif






