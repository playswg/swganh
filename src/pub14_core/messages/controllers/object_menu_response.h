// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE

#ifndef SWGANH_MESSAGES_CONTROLLERS_OBJECT_MENU_RESPONSE_H_
#define SWGANH_MESSAGES_CONTROLLERS_OBJECT_MENU_RESPONSE_H_

#include <cstdint>
#include <string>
#include "anh/byte_buffer.h"

#include "pub14_core/messages/obj_controller_message.h"
#include "radial_options.h"

namespace swganh {
namespace messages {
namespace controllers {

    // Radial Response
    class ObjectMenuResponse : public ObjControllerMessage
    {
    public:
        explicit ObjectMenuResponse(uint32_t controller_type = 0x0000000B)
            : ObjControllerMessage(controller_type, message_type())            
        {}

        explicit ObjectMenuResponse(ObjControllerMessage controller_message)
            : ObjControllerMessage(std::move(controller_message))
        {
            OnControllerDeserialize(std::move(data));
        }

        static uint32_t message_type() { return 0x00000147; }
        
        uint64_t target_id;
        uint64_t owner_id;
        std::vector<RadialOptions> radial_options;
        uint8_t response_count;

        void OnControllerSerialize(anh::ByteBuffer& buffer) const
        {
            buffer.write(target_id);
            buffer.write(owner_id);

            uint32_t size = radial_options.size();
            if (size > 0)
            {
                int counter = 0;
                for(auto& radial : radial_options)
                {
                    buffer.write(counter++);
                    buffer.write(radial.parent_item);
                    buffer.write(static_cast<uint8_t>(radial.identifier));
                    buffer.write(radial.action);
                    buffer.write(radial.custom_description);
                }
            }
            else
            {
                buffer.write(0);
            }
            buffer.write(response_count);
        }

        void OnControllerDeserialize(anh::ByteBuffer buffer)
        {
            target_id = buffer.read<uint64_t>();
            owner_id = buffer.read<uint64_t>();
            
        }
    };

}}}  // namespace swganh::messages::controllers

#endif  // SWGANH_MESSAGES_CONTROLLERS_OBJECT_MENU_RESPONSE_H_
