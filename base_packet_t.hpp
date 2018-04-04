//
// Created by zinjkov on 05.04.18.
//

#ifndef SERI_BASE_PACKET_T_HPP
#define SERI_BASE_PACKET_T_HPP

#include "serializable.hpp"
#include "meta.hpp"
#include "binary_stream.hpp"
#include "crc.hpp"

namespace rov_types {
    template <uint8_t packet_id_, uint8_t payload_size_, uint16_t packet_size_>
    class base_packet_t : public serializable {
    public:
		uint8_t serialize(uint8_t *output) override final  {
            binary_stream bs;
            Serial.println((int)meta.packet_id);   
            bs << meta.packet_id;
            // return 0;
            data_serialize(bs);
            bs << crc::calculateCRC(bs.data_ptr(), meta.payload_size);
			uint8_t size = 0;
            bs.data(output, &size);

			// Serial.print("seri ");
			// Serial.println((int)binary_stream::swap_endian<uint8_t>(output[0]));
			return size;
        }

        error_code deserialize(uint8_t *input, uint8_t size) {
            binary_stream bs(input, size);
			// Serial.print("bs size ");
			// Serial.println(bs.len());
            uint8_t packet_id;

            if (size < meta.packet_size){
                return size_less;
            }

            bs >> packet_id;

            // Serial.print("meta id ");
            // Serial.println((int)meta.packet_id);

            // Serial.print("packet id ");
            // Serial.println((int)input[0]);
            // Serial.print("packet id ");
            // Serial.println((int)binary_stream::swap_endian<uint8_t>(packet_id));

            if (packet_id != meta.packet_id) {
                return wrong_id;
            }

            data_deserialize(bs);

            int16_t current_crc = 0;
            bs >> current_crc;

            if (current_crc != crc::calculateCRC(input, meta.payload_size)) {
                return crc_mismatch;
            }

            if (size > meta.packet_size){
                return success_size_greater;
            }

            return success;
        }

    protected:
        meta_traits<packet_id_, payload_size_, packet_size_> meta;

        virtual void data_serialize(binary_stream &bs) = 0;
        virtual void data_deserialize(binary_stream &bs) = 0;
    };
}


#endif //SERI_BASE_PACKET_T_HPP
