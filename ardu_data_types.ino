/*
 Name:		ardu_data_types.ino
 Created:	13.04.2018 16:18:35
 Author:	zinjk
*/

// the setup function runs once when you press reset or power the board
#include "rov_data_types.hpp"
using namespace rov_types;

void gen(rov_hardware_control &rc1) {
	for (int i = 0; i < 4; i++) {
		rc1.horizontal_power[i] = rand();
	}
	for (int i = 0; i < 4; i++) {
		rc1.vertical_power[i] = rand();
	}
	for (int i = 0; i < 2; i++) {
		rc1.camera_rotate[i] = rand();
	}

	rc1.acoustic = rand();

	rc1.magnet = rand();

	rc1.manipulator_open_close = rand();

	rc1.manipulator_rotate = rand();
}
String validate(rov_hardware_control &rc1, rov_hardware_control &rc2) {
	for (int i = 0; i < 4; i++) {
		if (rc1.horizontal_power[i] != rc2.horizontal_power[i])
			return "horizontal_power[i] is valid";
	}
	for (int i = 0; i < 4; i++) {
		if (rc1.vertical_power[i] != rc2.vertical_power[i])
			return "vertical_power[i] is valid";
	}
	for (int i = 0; i < 2; i++) {
		if (rc1.camera_rotate[i] != rc2.camera_rotate[i])
			return "camera_rotate[i] is valid";
	}
	if (rc1.acoustic != rc2.acoustic)
		return "acoustic is valid";
	
	if (rc1.magnet != rc2.magnet)
		return "magnet is valid";

	if (rc1.manipulator_open_close != rc2.manipulator_open_close)
		return "manipulator_open_close is valid";

	if (rc1.manipulator_rotate != rc2.manipulator_rotate)
		return "manipulator_rotate is valid";
	return "passed";
}
void hardware_test() {
	rov_hardware_control rc;
	gen(rc);
	uint8_t buffer[255];
	uint8_t size = rc.serialize(buffer);
	rov_hardware_control rc2;
	auto err = rc2.deserialize(buffer, size);
	Serial.print("ROV HARDWARE CONTROL: ");
	Serial.print(serializable::error_to_string(err));
	Serial.print(" ");
	Serial.println(validate(rc, rc2).c_str());
}
void gen(rov_hardware_telimetry &rc1) {
	rc1.depth = rand();
	for (int i = 0; i < 2; i++) {
		rc1.camera_rotate[i] = rand();
	}

	rc1.mega_communication = rand();

	rc1.mini_communication = rand();

	rc1.esp_communication = rand();

	rc1.esp_state = rand();

	rc1.manipulator_rotated = rand();

	rc1.manipulator_opened_closed = rand();

	rc1.magnet = rand();

	rc1.acoustic = rand();
}
String validate(rov_hardware_telimetry &rc1, rov_hardware_telimetry &rc2) {
	if (rc1.depth != rc2.depth)
		return "depth is invalid";
	
	
	if (rc1.mega_communication != rc2.mega_communication)
		return "mega_communication is invalid";
	
	
	if (rc1.mini_communication != rc2.mini_communication)
		return "mini_communication is valid";
	
	if (rc1.acoustic != rc2.acoustic)
		return "acoustic is valid";

	if (rc1.magnet != rc2.magnet)
		return "magnet is valid";

	if (rc1.manipulator_opened_closed != rc2.manipulator_opened_closed)
		return "manipulator_open_close is valid";

	if (rc1.manipulator_rotated != rc2.manipulator_rotated)
		return "manipulator_rotate is valid";

	if (rc1.camera_rotate[0] != rc2.camera_rotate[0])
		return "camera_rotate is valid";

	if (rc1.camera_rotate[1] != rc2.camera_rotate[1])
		return "camera_rotate is valid";
	return "passed";
}
void teli_test() {
	rov_hardware_telimetry rc;
	gen(rc);
	uint8_t buffer[255];
	uint8_t size = rc.serialize(buffer);
	rov_hardware_telimetry rc2;
	auto err = rc2.deserialize(buffer, size);
	Serial.print("ROV HARDWARE TELIMETRY: ");
	Serial.print(serializable::error_to_string(err));
	Serial.print(" ");
	Serial.println(validate(rc, rc2).c_str());
}

void gen(rov_mini_control &rc1) {
	rc1.acoustics = rand();
	for (int i = 0; i < 9; i++) {
		rc1.pins[i] = rand();
		rc1.value[i] = rand();
	}

	rc1.acoustics = rand();

	rc1.manipulator = rand();

}
String validate(rov_mini_control &rc1, rov_mini_control &rc2) {
	if (rc1.acoustics != rc2.acoustics)
		return "acoustics is invalid";


	if (rc1.manipulator != rc2.manipulator)
		return "manipulator is invalid";

	for (int i = 0; i < 9; i++) {
		if (rc1.pins[i] != rc2.pins[i])
			return "pins[i] is valid";

		if (rc1.value[i] != rc2.value[i])
			return "value[i] is valid";
	}
	
	return "passed";
}
void rov_mini_control_test() {
	rov_mini_control rc;
	gen(rc);
	uint8_t buffer[255];
	uint8_t size = rc.serialize(buffer);
	rov_mini_control rc2;
	auto err = rc2.deserialize(buffer, size);
	Serial.print("ROV HARDWARE MINI_CONTROL: ");
	Serial.print(serializable::error_to_string(err));
	Serial.print(" ");
	Serial.println(validate(rc, rc2).c_str());
}

void gen(rov_mini_telimetry &rc1) {
	rc1.acoustics = rand();
	for (int i = 0; i < 9; i++) {
		rc1.pins[i] = rand();
		rc1.value[i] = rand();
	}

	rc1.acoustics = rand();

	rc1.manipulator_feedback = rand();

}
String validate(rov_mini_telimetry &rc1, rov_mini_telimetry &rc2) {
	if (rc1.acoustics != rc2.acoustics)
		return "acoustics is invalid";


	if (rc1.manipulator_feedback != rc2.manipulator_feedback)
		return "manipulator is invalid";

	for (int i = 0; i < 9; i++) {
		if (rc1.pins[i] != rc2.pins[i])
			return "pins[i] is valid";

		if (rc1.value[i] != rc2.value[i])
			return "value[i] is valid";
	}

	return "passed";
}
void rov_mini_telimetry_test() {
	rov_mini_telimetry rc;
	gen(rc);
	uint8_t buffer[255];
	uint8_t size = rc.serialize(buffer);
	rov_mini_telimetry rc2;
	auto err = rc2.deserialize(buffer, size);
	Serial.print("ROV HARDWARE MINI_TELI: ");
	Serial.print(serializable::error_to_string(err));
	Serial.print(" ");
	Serial.println(validate(rc, rc2).c_str());
}


void setup() {
	Serial.begin(115200);
	hardware_test();
	teli_test();
	rov_mini_control_test();
	rov_mini_telimetry_test();
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
