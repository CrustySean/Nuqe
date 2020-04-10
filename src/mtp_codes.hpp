#pragma once

#include <cstdint>

namespace nq::mtp {

enum class TypeCode: std::uint16_t {
    UNDEF                                       = 0x0000,   // Undefined
    INT8                                        = 0x0001,   // Signed 8-bit integer
    UINT8                                       = 0x0002,   // Unsigned 8-bit integer
    INT16                                       = 0x0003,   // Signed 16-bit integer
    UINT16                                      = 0x0004,   // Unsigned 16-bit integer
    INT32                                       = 0x0005,   // Signed 32-bit integer
    UINT32                                      = 0x0006,   // Unsigned 32-bit integer
    INT64                                       = 0x0007,   // Signed 64-bit integer
    UINT64                                      = 0x0008,   // Unsigned 64-bit integer
    INT128                                      = 0x0009,   // Signed 128-bit integer
    UINT128                                     = 0x000a,   // Unsigned 128-bit integer
    AINT8                                       = 0x4001,   // Array of signed 8-bit integers
    AUINT8                                      = 0x4002,   // Array of unsigned 8-bit integers
    AINT16                                      = 0x4003,   // Array of signed 16-bit integers
    AUINT16                                     = 0x4004,   // Array of unsigned 16-bit integers
    AINT32                                      = 0x4005,   // Array of signed 32-bit integers
    AUINT32                                     = 0x4006,   // Array of unsigned 32-bit integers
    AINT64                                      = 0x4007,   // Array of signed 64-bit integers
    AUINT64                                     = 0x4008,   // Array of unsigned 64-bit integers
    AINT128                                     = 0x4009,   // Array of signed 128-bit integers
    AUINT128                                    = 0x400a,   // Array of unsigned 128-bit integers
    STR                                         = 0xffff,   // Variable-length Unicode string
};

using TransactionCode = std::uint16_t;

enum class OperationCode: TransactionCode {
    GetDeviceInfo                               = 0x1001,
    OpenSession                                 = 0x1002,
    CloseSession                                = 0x1003,
    GetStorageIDs                               = 0x1004,
    GetStorageInfo                              = 0x1005,
    GetNumObjects                               = 0x1006,
    GetObjectHandles                            = 0x1007,
    GetObjectInfo                               = 0x1008,
    GetObject                                   = 0x1009,
    GetThumb                                    = 0x100a,
    DeleteObject                                = 0x100b,
    SendObjectInfo                              = 0x100c,
    SendObject                                  = 0x100d,
    InitiateCapture                             = 0x100e,
    FormatStore                                 = 0x100f,
    ResetDevice                                 = 0x1010,
    SelfTest                                    = 0x1011,
    SetObjectProtection                         = 0x1012,
    PowerDown                                   = 0x1013,
    GetDevicePropDesc                           = 0x1014,
    GetDevicePropValue                          = 0x1015,
    SetDevicePropValue                          = 0x1016,
    ResetDevicePropValue                        = 0x1017,
    TerminateOpenCapture                        = 0x1018,
    MoveObject                                  = 0x1019,
    CopyObject                                  = 0x101a,
    GetPartialObject                            = 0x101b,
    InitiateOpenCapture                         = 0x101c,
    GetObjectPropsSupported                     = 0x9801,
    GetObjectPropDesc                           = 0x9802,
    GetObjectPropValue                          = 0x9803,
    SetObjectPropValue                          = 0x9804,
    GetObjectReferences                         = 0x9810,
    SetObjectReferences                         = 0x9811,
    Skip                                        = 0x9820,

    // Enhanced operations
    GetObjectPropList                           = 0x9805,
    SetObjectPropList                           = 0x9806,
    GetInterdependentPropDesc                   = 0x9807,
    SendObjectPropList                          = 0x9808,
};

enum class ResponseCode: TransactionCode {
    Undefined                                   = 0x2000,
    OK                                          = 0x2001,
    General_Error                               = 0x2002,
    Session_Not_Open                            = 0x2003,
    Invalid_TransactionID                       = 0x2004,
    Operation_Not_Supported                     = 0x2005,
    Parameter_Not_Supported                     = 0x2006,
    Incomplete_Transfer                         = 0x2007,
    Invalid_StorageID                           = 0x2008,
    Invalid_ObjectHandle                        = 0x2009,
    DeviceProp_Not_Supported                    = 0x200a,
    Invalid_ObjectFormatCode                    = 0x200b,
    Store_Full                                  = 0x200c,
    Object_WriteProtected                       = 0x200d,
    Store_Read_Only                             = 0x200e,
    Access_Denied                               = 0x200f,
    No_Thumbnail_Present                        = 0x2010,
    SelfTest_Failed                             = 0x2011,
    Partial_Deletion                            = 0x2012,
    Store_Not_Available                         = 0x2013,
    Specification_By_Format_Unsupported         = 0x2014,
    No_Valid_ObjectInfo                         = 0x2015,
    Invalid_Code_Format                         = 0x2016,
    Unknown_Vendor_Code                         = 0x2017,
    Capture_Already_Terminated                  = 0x2018,
    Device_Busy                                 = 0x2019,
    Invalid_ParentObject                        = 0x201a,
    Invalid_DeviceProp_Format                   = 0x201b,
    Invalid_DeviceProp_Value                    = 0x201c,
    Invalid_Parameter                           = 0x201d,
    Session_Already_Open                        = 0x201e,
    Transaction_Cancelled                       = 0x201f,
    Specification_of_Destination_Unsupported    = 0x2020,
    Invalid_ObjectPropCode                      = 0xa801,
    Invalid_ObjectProp_Format                   = 0xa802,
    Invalid_ObjectProp_Value                    = 0xa803,
    Invalid_ObjectReference                     = 0xa804,
    Group_Not_Supported                         = 0xa805,
    Invalid_Dataset                             = 0xa806,
    Specification_By_Group_Unsupported          = 0xa807,
    Specification_By_Depth_Unsupported          = 0xa808,
    Object_Too_Large                            = 0xa809,
    ObjectProp_Not_Supported                    = 0xa80a,
};

enum class EventCode: TransactionCode {
    Undefined                                   = 0x4000,
    CancelTransaction                           = 0x4001,
    ObjectAdded                                 = 0x4002,
    ObjectRemoved                               = 0x4003,
    StoreAdded                                  = 0x4004,
    StoreRemoved                                = 0x4005,
    DevicePropChanged                           = 0x4006,
    ObjectInfoChanged                           = 0x4007,
    DeviceInfoChanged                           = 0x4008,
    RequestObjectTransfer                       = 0x4009,
    StoreFull                                   = 0x400a,
    DeviceReset                                 = 0x400b,
    StorageInfoChanged                          = 0x400c,
    CaptureComplete                             = 0x400d,
    UnreportedStatus                            = 0x400e,
    ObjectPropChanged                           = 0xc801,
    ObjectPropDescChanged                       = 0xc802,
    ObjectReferencesChanged                     = 0xc803,
};

enum class ObjectFormatCode: std::uint16_t {
    Undefined                                   = 0x3000,   // Undefined object
    Association                                 = 0x3001,   // Association (for example, a folder)
    Script                                      = 0x3002,   // Device model-specific script
    Executable                                  = 0x3003,   // Device model-specific binary executable
    Text                                        = 0x3004,   // Text file
    HTML                                        = 0x3005,   // Hypertext Markup Language file (text)
    DPOF                                        = 0x3006,   // Digital Print Order Format file (text)
    AIFF                                        = 0x3007,   // Audio clip
    WAV                                         = 0x3008,   // Audio clip
    MP3                                         = 0x3009,   // MPEG-1 Layer III audio (ISO/IEC 13818-3)
    AVI                                         = 0x300a,   // Video clip
    MPEG                                        = 0x300b,   // Video clip
    ASF                                         = 0x300c,   // Microsoft Advanced Streaming Format (video)
    Undefined_Image                             = 0x3800,   // Undefined image object
    EXIF_JPEG                                   = 0x3801,   // Exchangeable File Format, JEIDA standard
    TIFF_EP                                     = 0x3802,   // Tag Image File Format for Electronic Photography
    FlashPix                                    = 0x3803,   // Structured Storage Image Format
    BMP                                         = 0x3804,   // Microsoft Windows Bitmap file
    CIFF                                        = 0x3805,   // Canon Camera Image File Format
    Undefined_2                                 = 0x3806,   // Reserved
    GIF                                         = 0x3807,   // Graphics Interchange Format
    JFIF                                        = 0x3808,   // JPEG File Interchange Format
    CD                                          = 0x3809,   // PhotoCD Image Pac
    PICT                                        = 0x380a,   // Quickdraw Image Format
    PNG                                         = 0x380b,   // Portable Network Graphics
    Undefined_3                                 = 0x380c,   // Reserved
    TIFF                                        = 0x380d,   // Tag Image File Format
    TIFF_IT                                     = 0x380e,   // Tag Image File Format for Information Technology (graphic arts)
    JP2                                         = 0x380f,   // JPEG2000 Baseline File Format
    JPX                                         = 0x3810,   // JPEG2000 Extended File Format
    Undefined_Firmware                          = 0xb802,
    Windows_Image_Format                        = 0xb881,
    WBMP                                        = 0xb803,   // Wireless Application Protocol Bitmap Format (.wbmp)
    JPEG_XR                                     = 0xb804,   // JPEG XR, also known as HD Photo (.hdp, jxr, .wpd)
    Undefined_Audio                             = 0xb900,   // Undefined audio object
    WMA                                         = 0xb901,
    OGG                                         = 0xb902,
    AAC                                         = 0xb903,
    Audible                                     = 0xb904,
    FLAC                                        = 0xb906,
    QCELP                                       = 0xb907,
    AMR                                         = 0xb908,
    Undefined_Video                             = 0xb980,
    WMV                                         = 0xb981,   // Windows Media Video
    MP4_Container                               = 0xb982,   // ISO 14496-1
    MP2                                         = 0xb983,   // MPEG-1 Layer II audio (ISO/IEC 13818-3)
    _3GP_Container                              = 0xb984,   // 3GPP file format
    _3G2                                        = 0xb985,   // 3GPP2 format (.3g2)
    AVCHD                                       = 0xb986,   // MPEG-4 AVC video and Dolby Digital audio within an MPEG-2 Transport Stream as constrained by the AVCHD format specification
    ATSC_TS                                     = 0xb987,   // MPEG-2 video and AC-3 audio within an ATSC-compliant MPEG-2 Transport Stream
    DVB_TS                                      = 0xb988,   // MPEG-2 video and MPEG-1 Layer II or AC-3 audio within a DVB- compliant MPEG-2 Transport Stream
    Undefined_Collection                        = 0xba00,
    Abstract_Multimedia_Album                   = 0xba01,
    Abstract_Image_Album                        = 0xba02,
    Abstract_Audio_Album                        = 0xba03,
    Abstract_Video_Album                        = 0xba04,
    Abstract_Audio_And_Video_Playlist           = 0xba05,
    Abstract_Contact_Group                      = 0xba06,
    Abstract_Message_Folder                     = 0xba07,
    Abstract_Chaptered_Production               = 0xba08,
    Abstract_Audio_Playlist                     = 0xba09,
    Abstract_Video_Playlist                     = 0xba0a,
    Abstract_Mediacast                          = 0xba0b,   // For use with mediacasts; references multimedia enclosures of RSS feeds or episodic content
    WPL_Playlist                                = 0xba10,
    M3U_Playlist                                = 0xba11,
    MPL_Playlist                                = 0xba12,
    ASX_Playlist                                = 0xba13,
    PLS_Playlist                                = 0xba14,
    Undefined_Document                          = 0xba80,
    Abstract_Document                           = 0xba81,
    XML_Document                                = 0xba82,
    Microsoft_Word_Document                     = 0xba83,
    MHT_Compiled_HTML_Document                  = 0xba84,
    Microsoft_Excel_spreadsheet                 = 0xba85,
    Microsoft_Powerpoint_Presentation           = 0xba86,
    Undefined_Message                           = 0xbb00,
    Abstract_Message                            = 0xbb01,
    Undefined_Bookmark                          = 0xbb10,
    Abstract_Bookmark                           = 0xbb11,
    Undefined_Appointment                       = 0xbb20,
    Abstract_Appointment                        = 0xbb21,
    vCalendar_1_0                               = 0xbb22,
    Undefined_Task                              = 0xbb40,
    Abstract_Task                               = 0xbb41,
    iCalendar                                   = 0xbb42,
    Undefined_Note                              = 0xbb60,
    Abstract_Note                               = 0xbb61,
    Undefined_Contact                           = 0xbb80,
    Abstract_Contact                            = 0xbb81,
    vCard_2                                     = 0xbb82,
    vCard_3                                     = 0xbb83,
};

enum class ObjectPropertyCode: std::uint16_t {
    StorageID                                   = 0xdc01,
    Object_Format                               = 0xdc02,
    Protection_Status                           = 0xdc03,
    Object_Size                                 = 0xdc04,
    Association_Type                            = 0xdc05,
    Association_Desc                            = 0xdc06,
    Object_File_Name                            = 0xdc07,
    Date_Created                                = 0xdc08,
    Date_Modified                               = 0xdc09,
    Keywords                                    = 0xdc0a,
    Parent_Object                               = 0xdc0b,
    Allowed_Folder_Contents                     = 0xdc0c,
    Hidden                                      = 0xdc0d,
    System_Object                               = 0xdc0e,
    Persistent_Unique_Object_Identifier         = 0xdc41,
    SyncID                                      = 0xdc42,
    Property_Bag                                = 0xdc43,
    Name                                        = 0xdc44,
    Created_By                                  = 0xdc45,
    Artist                                      = 0xdc46,
    Date_Authored                               = 0xdc47,
    Description                                 = 0xdc48,
    URL_Reference                               = 0xdc49,
    Language_Locale                             = 0xdc4a,
    Copyright_Information                       = 0xdc4b,
    Source                                      = 0xdc4c,
    Origin_Location                             = 0xdc4d,
    Date_Added                                  = 0xdc4e,
    Non_Consumable                              = 0xdc4f,
    Corrupt_Unplayable                          = 0xdc50,
    ProducerSerialNumber                        = 0xdc51,
    Representative_Sample_Format                = 0xdc81,
    Representative_Sample_Size                  = 0xdc82,
    Representative_Sample_Height                = 0xdc83,
    Representative_Sample_Width                 = 0xdc84,
    Representative_Sample_Duration              = 0xdc85,
    Representative_Sample_Data                  = 0xdc86,
    Width                                       = 0xdc87,
    Height                                      = 0xdc88,
    Duration                                    = 0xdc89,
    Rating                                      = 0xdc8a,
    Track                                       = 0xdc8b,
    Genre                                       = 0xdc8c,
    Credits                                     = 0xdc8d,
    Lyrics                                      = 0xdc8e,
    Subscription_Content_ID                     = 0xdc8f,
    Produced_By                                 = 0xdc90,
    Use_Count                                   = 0xdc91,
    Skip_Count                                  = 0xdc92,
    Last_Accessed                               = 0xdc93,
    Parental_Rating                             = 0xdc94,
    Meta_Genre                                  = 0xdc95,
    Composer                                    = 0xdc96,
    Effective_Rating                            = 0xdc97,
    Subtitle                                    = 0xdc98,
    Original_Release_Date                       = 0xdc99,
    Album_Name                                  = 0xdc9a,
    Album_Artist                                = 0xdc9b,
    Mood                                        = 0xdc9c,
    DRM_Status                                  = 0xdc9d,
    Sub_Description                             = 0xdc9e,
    Is_Cropped                                  = 0xdcd1,
    Is_Colour_Corrected                         = 0xdcd2,
    Image_Bit_Depth                             = 0xdcd3,
    Fnumber                                     = 0xdcd4,
    Exposure_Time                               = 0xdcd5,
    Exposure_Index                              = 0xdcd6,
    Total_BitRate                               = 0xde91,
    Bitrate_Type                                = 0xde92,
    Sample_Rate                                 = 0xde93,
    Number_Of_Channels                          = 0xde94,
    Audio_BitDepth                              = 0xde95,
    Scan_Type                                   = 0xde97,
    Audio_WAVE_Codec                            = 0xde99,
    Audio_BitRate                               = 0xde9a,
    Video_FourCC_Codec                          = 0xde9b,
    Video_BitRate                               = 0xde9c,
    Frames_Per_Thousand_Seconds                 = 0xde9d,
    KeyFrame_Distance                           = 0xde9e,
    Buffer_Size                                 = 0xde9f,
    Encoding_Quality                            = 0xdea0,
    Encoding_Profile                            = 0xdea1,
    Display_Name                                = 0xdce0,
    Body_Text                                   = 0xdce1,
    Subject                                     = 0xdce2,
    Priority                                    = 0xdce3,
    Given_Name                                  = 0xdd00,
    Middle_Names                                = 0xdd01,
    Family_Name                                 = 0xdd02,
    Prefix                                      = 0xdd03,
    Suffix                                      = 0xdd04,
    Phonetic_Given_Name                         = 0xdd05,
    Phonetic_Family_Name                        = 0xdd06,
    Email_Primary                               = 0xdd07,
    Email_Personal_1                            = 0xdd08,
    Email_Personal_2                            = 0xdd09,
    Email_Business_1                            = 0xdd0a,
    Email_Business_2                            = 0xdd0b,
    Email_Others                                = 0xdd0c,
    Phone_Number_Primary                        = 0xdd0d,
    Phone_Number_Personal                       = 0xdd0e,
    Phone_Number_Personal_2                     = 0xdd0f,
    Phone_Number_Business                       = 0xdd10,
    Phone_Number_Business_2                     = 0xdd11,
    Phone_Number_Mobile                         = 0xdd12,
    Phone_Number_Mobile_2                       = 0xdd13,
    Fax_Number_Primary                          = 0xdd14,
    Fax_Number_Personal                         = 0xdd15,
    Fax_Number_Business                         = 0xdd16,
    Pager_Number                                = 0xdd17,
    Phone_Number_Others                         = 0xdd18,
    Primary_Web_Address                         = 0xdd19,
    Personal_Web_Address                        = 0xdd1a,
    Business_Web_Address                        = 0xdd1b,
    Instant_Messenger_Address                   = 0xdd1c,
    Instant_Messenger_Address_2                 = 0xdd1d,
    Instant_Messenger_Address_3                 = 0xdd1e,
    Postal_Address_Personal_Full                = 0xdd1f,
    Postal_Address_Personal_Line_1              = 0xdd20,
    Postal_Address_Personal_Line_2              = 0xdd21,
    Postal_Address_Personal_City                = 0xdd22,
    Postal_Address_Personal_Region              = 0xdd23,
    Postal_Address_Personal_Postal_Code         = 0xdd24,
    Postal_Address_Personal_Country             = 0xdd25,
    Postal_Address_Business_Full                = 0xdd26,
    Postal_Address_Business_Line_1              = 0xdd27,
    Postal_Address_Business_Line_2              = 0xdd28,
    Postal_Address_Business_City                = 0xdd29,
    Postal_Address_Business_Region              = 0xdd2a,
    Postal_Address_Business_Postal_Code         = 0xdd2b,
    Postal_Address_Business_Country             = 0xdd2c,
    Postal_Address_Other_Full                   = 0xdd2d,
    Postal_Address_Other_Line_1                 = 0xdd2e,
    Postal_Address_Other_Line_2                 = 0xdd2f,
    Postal_Address_Other_City                   = 0xdd30,
    Postal_Address_Other_Region                 = 0xdd31,
    Postal_Address_Other_Postal_Code            = 0xdd32,
    Postal_Address_Other_Country                = 0xdd33,
    Organization_Name                           = 0xdd34,
    Phonetic_Organization_Name                  = 0xdd35,
    Role                                        = 0xdd36,
    Birthdate                                   = 0xdd37,
    Message_To                                  = 0xdd40,
    Message_CC                                  = 0xdd41,
    Message_BCC                                 = 0xdd42,
    Message_Read                                = 0xdd43,
    Message_Received_Time                       = 0xdd44,
    Message_Sender                              = 0xdd45,
    Activity_Begin_Time                         = 0xdd50,
    Activity_End_Time                           = 0xdd51,
    Activity_Location                           = 0xdd52,
    Activity_Required_Attendees                 = 0xdd54,
    Activity_Optional_Attendees                 = 0xdd55,
    Activity_Resources                          = 0xdd56,
    Activity_Accepted                           = 0xdd57,
    Activity_Tentative                          = 0xdd58,
    Activity_Declined                           = 0xdd59,
    Activity_Reminder_Time                      = 0xdd5a,
    Activity_Owner                              = 0xdd5b,
    Activity_Status                             = 0xdd5c,
    Owner                                       = 0xdd5d,
    Editor                                      = 0xdd5e,
    Webmaster                                   = 0xdd5f,
    URL_Source                                  = 0xdd60,
    URL_Destination                             = 0xdd61,
    Time_Bookmark                               = 0xdd62,
    Object_Bookmark                             = 0xdd63,
    Byte_Bookmark                               = 0xdd64,
    Last_Build_Date                             = 0xdd70,
    Time_to_Live                                = 0xdd71,
    Media_GUID                                  = 0xdd72,
};

enum class DevicePropertyCode: std::uint16_t {
    Undefined                                   = 0x5000,
    Battery_Level                               = 0x5001,
    Functional_Mode                             = 0x5002,
    Image_Size                                  = 0x5003,
    Compression_Setting                         = 0x5004,
    White_Balance                               = 0x5005,
    RGB_Gain                                    = 0x5006,
    F_Number                                    = 0x5007,
    Focal_Length                                = 0x5008,
    Focus_Distance                              = 0x5009,
    Focus_Mode                                  = 0x500a,
    Exposure_Metering_Mode                      = 0x500b,
    Flash_Mode                                  = 0x500c,
    Exposure_Time                               = 0x500d,
    Exposure_Program_Mode                       = 0x500e,
    Exposure_Index                              = 0x500f,
    Exposure_Bias_Compensation                  = 0x5010,
    DateTime                                    = 0x5011,
    Capture_Delay                               = 0x5012,
    Still_Capture_Mode                          = 0x5013,
    Contrast                                    = 0x5014,
    Sharpness                                   = 0x5015,
    Digital_Zoom                                = 0x5016,
    Effect_Mode                                 = 0x5017,
    Burst_Number                                = 0x5018,
    Burst_Interval                              = 0x5019,
    Timelapse_Number                            = 0x501a,
    Timelapse_Interval                          = 0x501b,
    Focus_Metering_Mode                         = 0x501c,
    Upload_URL                                  = 0x501d,
    Artist                                      = 0x501e,
    Copyright_Info                              = 0x501f,
    Synchronization_Partner                     = 0xd401,
    Device_Friendly_Name                        = 0xd402,
    Volume                                      = 0xd403,
    SupportedFormatsOrdered                     = 0xd404,
    DeviceIcon                                  = 0xd405,
    Playback_Rate                               = 0xd410,
    Playback_Object                             = 0xd411,
    Playback_Container_Index                    = 0xd412,
    Session_Initiator_Version_Info              = 0xd406,
    Perceived_Device_Type                       = 0xd407,
};

enum class StorageType: std::uint16_t {
    Undefined                                   = 0,
    FixedRom                                    = 1,
    RemovableRom                                = 2,
    FixedRam                                    = 3,
    RemovableRam                                = 4,
};

enum class FilesystemType: std::uint16_t {
    Undefined                                   = 0,
    GenericFlat                                 = 1,
    GenericHierachical                          = 2,
    DCF                                         = 3,
};

enum class AccessCapability: std::uint16_t {
    ReadWrite                                   = 0,
    ReadOnlyNoDeletion                          = 1,
    ReadOnlyDeletion                            = 2,
};

enum class Protection: std::uint16_t {
    None                                        = 0,
    ReadOnly                                    = 1,
    ReadOnlyData                                = 0x8002,
    NonTransferableData                         = 0x8003,
};

enum class AssociationType: std::uint16_t {
    Undefined                                   = 0,
    GenericFolder                               = 1,
    Album                                       = 2,
    TimeSequence                                = 3,
    HorizontalPanoramic                         = 4,
    VerticalPanoramic                           = 5,
    _2dPanoramic                                = 6,
    AncillaryData                               = 7,
};

using AssociationDesc = std::uint32_t;

enum class Forms: std::uint8_t {
    None                                        = 0,
    Range                                       = 1,
    Enumeration                                 = 2,
    DateTime                                    = 3,
    Array                                       = 4,
    Regex                                       = 5,
    ByteArray                                   = 6,
    LongString                                  = 0xff,
};

} // namespace nq::mtp
