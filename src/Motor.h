#ifndef Motor_h
#define Motor_h

class Motor {
    public:
        Motor(int pin1, int pin2);

        void stop();
        void moveForward();
        void moveBackward();

    private:
        float _pin1;
        float _pin2;
};

#endif