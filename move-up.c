#pragma config(Sensor, dgtl8, sonar, sensorSONAR_inch)
#pragma config(Motor, port1, m1, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
bool moveUp = false;
float sv = 0;
task wait ();

task wait () {
    float oldValue = 0;
    int count = 0;
    float wait = 5;
    while (true) {
        if (sv < oldValue + 0.8 && sv > oldValue + 0.8) {
            if (count >= 5) {
                moveUp = true;
            } else {
                count++;
                sleep(wait / 5);
            }
        } else {
            moveUp = false;
            oldValue = sv;
            count = 0;
        }
    }
}

task main () {
    startTask(wait);
    while (true) {
        sv = SensorValue[dgtl8];
        float distance = 4;
        float gap = 6;
        float deadBand = 0.5;
        float motorSpeed = 80;
        float lowMotorSpeed = 5;
        if (moveUp) {
            startMotor(m1, lowMotorSpeed);
        } else {
            if (sv != -1 && sv < gap) {
                motorSpeed = sv / distance * 100;
                if (sv > distance + deadBand) {
                    startMotor(m1, motorSpeed);
                } else if (sv < distance - deadBand) {
                    startMotor(m1, -motorSpeed);
                } else {
                    stopMotor(m1);
                }
            }
        }
    }
}
