#pragma once

#include <unordered_map>

#include "mtp_codes.hpp"
#include "mtp_object.hpp"
#include "mtp_packet.hpp"

namespace nq::mtp::props {

namespace dev {

static inline String device_friendly_name    = u"Switch";
static inline String synchronization_partner = u"Nuqe";

} // namespace dev

namespace obj {

static inline std::unordered_map<ObjectFormatCode, std::vector<ObjectPropertyCode>> supported = {
    {
        ObjectFormatCode::Undefined, std::vector{
            ObjectPropertyCode::StorageID,
            ObjectPropertyCode::Object_Format,
            ObjectPropertyCode::Object_Size,
            ObjectPropertyCode::Object_File_Name,
            ObjectPropertyCode::Date_Created,
            ObjectPropertyCode::Date_Modified,
            ObjectPropertyCode::Parent_Object,
        }
    },
    {
        ObjectFormatCode::Association, std::vector{
            ObjectPropertyCode::StorageID,
            ObjectPropertyCode::Object_Format,
            ObjectPropertyCode::Object_File_Name,
            ObjectPropertyCode::Parent_Object,
        }
    },
};

} // namespace obj


template <typename T>
struct DevicePropDesc {
    DevicePropertyCode code          = DevicePropertyCode::Undefined;
    TypeCode           type          = TypeCode::UNDEF;
    std::uint8_t       get_set       = 0; // Get
    T                  default_value = {};
    T                  current_value = {};
    std::uint32_t      group_code    = 0;
    Forms              form_flag     = Forms::None;

    void push_to(DataPacket &packet) {
        packet.buffer.reserve(packet.buffer.size() + sizeof(DevicePropDesc<T>));
        packet.set_data(
            this->code,          this->type,        this->get_set,      this->default_value,
            this->current_value, this->group_code,  this->form_flag
        );
    }
};

template <typename T>
struct ObjectPropDesc {
    ObjectPropertyCode code          = ObjectPropertyCode::StorageID;
    TypeCode           type          = TypeCode::UNDEF;
    std::uint8_t       get_set       = 0; // Get
    T                  default_value = {};
    std::uint32_t      group_code    = 0;
    Forms              form_flag     = Forms::None;

    void push_to(DataPacket &packet) {
        packet.buffer.reserve(packet.buffer.size() + sizeof(ObjectPropDesc<T>));
        packet.set_data(
            this->code,          this->type,        this->get_set,      this->default_value,
            this->group_code,    this->form_flag
        );
    }
};

ResponseCode get_device_prop_desc(DataPacket &packet, DevicePropertyCode property);
ResponseCode get_device_prop_value(DataPacket &packet, DevicePropertyCode property);

ResponseCode get_object_props_supported(DataPacket &packet, ObjectFormatCode format);
ResponseCode get_object_prop_desc(DataPacket &packet, ObjectPropertyCode property, ObjectFormatCode format);

} // namespace nq::mtp::props
