// Start here. All this can be run in systick!
// This will just keep going straight forever.

void get_sensor_feedback() {
	angle_travelled = encoders.left() - encoders.right();
}

float x_controller() {
	return BASE_PWM_X;
}

float w_controller() {
	w_error = goal_angle - angle_travelled;
	pwm_w = KpW * w_error + KdW * (w_error - w_error_old) * dt;

	w_error_old = w_error;

	return pwm_w;
}

void update_motor_pwm() {
	pwm_x = x_controller();
	pwm_w = w_controller();
	
	motors.set_right_pwm(pwm_x + pwm_w);
	motors.set_left_pwm(pwm_x - pwm_w);
}
