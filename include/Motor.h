#ifndef Motor_h
#define Motor_h

class Motor {
    public:
        Motor(int pin1, int pin2);

        void stop();
        void moveForward();
        void moveBackward();

    private:
        int _pin1;
        int _pin2;
};

#endif