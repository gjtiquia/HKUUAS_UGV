#ifndef Motor_h
#define Motor_h

class Motor {
    public:
        Motor(int pin1, int pin2, int speedPin);

        void stop();
        void moveForward(int speed);
        void moveBackward(int speed);

    private:
        int _pin1;
        int _pin2;
        int _speedPin;
};

#endif