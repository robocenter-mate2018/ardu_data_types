//
// Created by zinjkov on 30.03.18.
//

#include "rov_data_types.hpp"



void rov_types::rov_telimetry::data_serialize(rov_types::binary_stream &bs) {
    bs << roll;
    bs << pitch;
    bs << yaw;
    bs << depth;

    bs << mega_communication;
    bs << mini_communication;
    bs << esp_communication;
    bs << esp_state;
    bs << manipulator_rotated;
    bs << manipulator_opened_closed;
    for (auto &c : camera_rotate) {
        bs << c;
    }
    bs << magnet;
    bs << acoustic;

}

void rov_types::rov_telimetry::data_deserialize(rov_types::binary_stream &bs) {
    bs >> roll;
    bs >> pitch;
    bs >> yaw;
    bs >> depth;

    bs >> mega_communication;
    bs >> mini_communication;
    bs >> esp_communication;
    bs >> esp_state;
    bs >> manipulator_rotated;
    bs >> manipulator_opened_closed;
    for (auto &c : camera_rotate) {
        bs >> c;
    }
    bs >> magnet;
    bs >> acoustic;
}


void rov_types::rov_control::data_serialize(rov_types::binary_stream &bs) {
    bs << axis_x;
    bs << axis_y;
    bs << axis_z;
    bs << axis_w;
    bs << manipulator_rotate;
    bs << manipulator_open_close;
    for(const auto & b : camera_rotate) {
        bs << b;
    }
    bs << magnet;
    bs << acoustic;
    for(const auto & b : twisting_motors) {
        bs << b;
    }
}

void rov_types::rov_control::data_deserialize(rov_types::binary_stream &bs) {
    bs >> axis_x;
    bs >> axis_y;
    bs >> axis_z;
    bs >> axis_w;
    bs >> manipulator_rotate;
    bs >> manipulator_open_close;
    for(auto & b : camera_rotate) {
        bs >> b;
    }
    bs >> magnet;
    bs >> acoustic;
    for(auto & b : twisting_motors) {
        bs >> b;
    }
}

void rov_types::rov_hardware_control::data_serialize(rov_types::binary_stream &bs) {
    for(auto & p : horizontal_power) {
        bs << p;
    }
    for(auto & p : vertical_power) {
        bs << p;
    }
    bs << manipulator_rotate;
    bs << manipulator_open_close;
    for(auto & b : camera_rotate) {
        bs << b;
    }
    bs << magnet;
    bs << acoustic;
    for(const auto & b : twisting_motors) {
        bs << b;
    }
}

void rov_types::rov_hardware_control::data_deserialize(rov_types::binary_stream &bs) {
    for(auto & p : horizontal_power) {
        bs >> p;
    }
    for(auto & p : vertical_power) {
        bs >> p;
    }

    bs >> manipulator_rotate;
    bs >> manipulator_open_close;
    for(auto & b : camera_rotate) {
        bs >> b;
    }
    bs >> magnet;
    bs >> acoustic;
    for(auto & b : twisting_motors) {
        bs >> b;
    }
}


void rov_types::rov_hardware_telimetry::data_serialize(rov_types::binary_stream &bs) {
    bs << depth;
    bs << mega_communication;
    bs << mini_communication;
    bs << esp_communication;
    bs << esp_state;
    bs << manipulator_rotated;
    bs << manipulator_opened_closed;
    for(auto & b : camera_rotate) {
        bs << b;
    }
    bs << magnet;
    bs << acoustic;
	for (auto & b : twisting_motors) {
		bs << b;
	}
}

void rov_types::rov_hardware_telimetry::data_deserialize(rov_types::binary_stream &bs) {
    bs >> depth;
    bs >> mega_communication;
    bs >> mini_communication;
    bs >> esp_communication;
    bs >> esp_state;
    bs >> manipulator_rotated;
    bs >> manipulator_opened_closed;
    for(auto & b : camera_rotate) {
        bs >> b;
    }
    bs >> magnet;
    bs >> acoustic;
	for (auto & b : twisting_motors) {
		bs >> b;
	}
}

void rov_types::rov_mini_telimetry::data_serialize(rov_types::binary_stream &bs) {
    for(auto & b : twisting_motors_feedback) {
        bs << b;
    }
	bs << magnet;
    bs << acoustics;
    bs << mini_communicator_feedback;
	bs << manipulator_feedback;
}

void rov_types::rov_mini_telimetry::data_deserialize(rov_types::binary_stream &bs) {
    for(auto & b : twisting_motors_feedback) {
        bs >> b;
    }
	bs >> magnet;
    bs >> acoustics;
    bs >> mini_communicator_feedback;
	bs >> manipulator_feedback;
}

void rov_types::rov_mini_control::data_serialize(rov_types::binary_stream &bs) {
    for(auto & b : twisting_motors) {
        bs << b;
    }
	bs << magnet;
    bs << acoustics;
	bs << manipulator;
}

void rov_types::rov_mini_control::data_deserialize(rov_types::binary_stream &bs) {
    for(auto & b : twisting_motors) {
        bs >> b;
    }
	bs >> magnet;
    bs >> acoustics;
	bs >> manipulator;
}